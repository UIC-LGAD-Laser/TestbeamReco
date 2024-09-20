#define InitialAnalyzer_cxx
#include "TestbeamReco/interface/InitialAnalyzer.h"
#include "TestbeamReco/interface/Utility.h"
#include "TestbeamReco/interface/NTupleReader.h"

#include <TH1D.h>
#include <TH2D.h>
#include <TEfficiency.h>
#include <TFile.h>
#include <iostream>
#include <fstream>

InitialAnalyzer::InitialAnalyzer()
{
}

//Define all your histograms here. 
//void InitialAnalyzer::InitHistos(NTupleReader& tr, const std::vector<std::vector<int>>& geometry)
void InitialAnalyzer::InitHistos(NTupleReader& tr, const std::vector<std::vector<int>>& geometry)
{
    TH1::SetDefaultSumw2();
    TH2::SetDefaultSumw2();

    //This event counter histogram is necessary so that we know that all the condor jobs ran successfully. If not, when you use the hadder script, you will see a discrepancy in red as the files are being hadded.
    my_histos.emplace( "EventCounter", std::make_shared<TH1D>( "EventCounter", "EventCounter", 2, -1.1, 1.1 ) ) ;

    // const auto& pitch = tr.getVar<double>("pitch");
    const auto& xBinSize = tr.getVar<double>("xBinSize");
    const auto& yBinSize = tr.getVar<double>("yBinSize");

    const auto& xBinSize_delay_corr = tr.getVar<double>("xBinSize_delay_corr");
    const auto& yBinSize_delay_corr = tr.getVar<double>("yBinSize_delay_corr");

    const auto& xmin = tr.getVar<double>("xmin");
    const auto& xmax = tr.getVar<double>("xmax");
    const auto& ymin = tr.getVar<double>("ymin");
    const auto& ymax = tr.getVar<double>("ymax");




    int timeDiffNbin = 800; // 200
    double timeDiffLow = -1.0;
    double timeDiffHigh = 1.0;

    int rowIndex = 0;
    for(const auto& row : geometry)
    {
        if(row.size()<2) continue;
        for(unsigned int i = 0; i < row.size(); i++)
        {
            const auto& r = std::to_string(rowIndex);
            const auto& s = std::to_string(i);
            utility::makeHisto(my_3d_histos,"amplitude_vs_xy_channel"+r+s,"; X [mm]; Y [mm]",(xmax-xmin)/xBinSize,xmin,xmax, (ymax-ymin)/yBinSize,ymin,ymax, 500,0,500 );
            utility::makeHisto(my_3d_histos,"timeDiff_fine_vs_xy_channel"+r+s, "; X [mm]; Y [mm]",(xmax-xmin)/xBinSize,xmin,xmax, (ymax-ymin)/yBinSize,ymin,ymax, timeDiffNbin,timeDiffLow,timeDiffHigh);
        }
        rowIndex++;
    }

    //Time corrections need to match dimension of LP2_X branches, NOT the LGAD coordinates.
    const auto& amp = tr.getVec<float>("amp");
    uint n_scope_channels = amp.size();
    std::cout<<"I found "<<n_scope_channels<<" channels."<<std::endl;
    for(uint i=0;i<n_scope_channels;i++)
    {
        utility::makeHisto(my_3d_histos,Form("timeDiff_coarse_vs_xy_channel0%i",i), "; X [mm]; Y [mm]",(xmax-xmin)/xBinSize_delay_corr,xmin,xmax, (ymax-ymin)/yBinSize_delay_corr,ymin,ymax, timeDiffNbin,timeDiffLow,timeDiffHigh);
    }

    utility::makeHisto(my_2d_prof,"y_vs_Amp1OverAmp1and2_deltaT_prof", "; Amp_{Max} / Amp_{Max} + Amp_{2}; t_{Max} - t_{2} [ns]; Y [mm]", 100,0.0,1.0, 1000,-1,1);

    std::cout<<"Finished making histos"<<std::endl;
}

//Put everything you want to do per event here.
void InitialAnalyzer::Loop(NTupleReader& tr, int maxevents)
{
    //const auto& indexToGeometryMap = tr.getVar<std::map<int, std::vector<int>>>("indexToGeometryMap");
    const auto& geometry = tr.getVar<std::vector<std::vector<int>>>("geometry");
    const auto& signalAmpThreshold = tr.getVar<double>("signalAmpThreshold");
    const auto& noiseAmpThreshold = tr.getVar<double>("noiseAmpThreshold");
    //const auto& lowGoodStripIndex = tr.getVar<int>("lowGoodStripIndex");
    //const auto& highGoodStripIndex = tr.getVar<int>("highGoodStripIndex");

    const auto& firstFile = tr.getVar<bool>("firstFile");
    if(firstFile)
    {
        InitHistos(tr, geometry);
    }
    
    while( tr.getNextEvent() )
    {
        //This is added to count the number of events- do not change the next two lines.
        const auto& eventCounter = tr.getVar<int>("eventCounter");
        my_histos["EventCounter"]->Fill( eventCounter );

        //Print Event Number 
        if( maxevents != -1 && tr.getEvtNum() >= maxevents ) break;
        if( tr.getEvtNum() % 100000 == 0 ) printf( " Event %i\n", tr.getEvtNum() );
                       
        //Can add some fun code here....try not to calculate too much in this file: use modules to do the heavy caclulations
        const auto& amp = tr.getVec<float>("amp");
        uint n_scope_channels = amp.size();
        const auto& ampLGAD = tr.getVec<std::vector<double>>("ampLGAD");
        const auto& rawAmpLGAD = tr.getVec<std::vector<float>>("rawAmpLGAD");
        const auto& corrTime = tr.getVec<double>("corrTime");
        const auto& timeLGADTracker = tr.getVec<std::vector<double>>("timeLGADTracker");
        const auto& hitSensor = tr.getVar<bool>("hitSensor");
        const auto& maxAmpLGAD = tr.getVar<double>("maxAmpLGAD");
        const auto& amp1Indexes = tr.getVar<std::pair<int,int>>("amp1Indexes");
        const auto& Amp1OverAmp1and2 = tr.getVar<double>("Amp1OverAmp1and2");
        const auto& goodNeighbour = tr.getVar<bool>("goodNeighbour");
        const auto& parityLGAD = tr.getVec<std::vector<int>>("parityLGAD");
        const auto& deltaT = tr.getVar<double>("deltaT");
        const auto& twoGoodChannel = tr.getVar<bool>("twoGoodChannel"); // Timing requirement
        const auto& photekIndex = tr.getVar<int>("photekIndex"); // for cfd-based trigger time calculation

        //Define selection bools
        bool pass = hitSensor;
        bool goodMaxLGADAmp = maxAmpLGAD > signalAmpThreshold;

        const auto& x = tr.getVar<double>("x");
        const auto& y = tr.getVar<double>("y");
        const auto& TrgTime = tr.getVar<double>("TrgTime"); 
        int parityMax = parityLGAD[amp1Indexes.first][amp1Indexes.second];

        // double photekTime = TrgTime; // old method to set trigger time
        double photekTime = corrTime[photekIndex]; // trigger time using CFD



        //******************************************************************
        //Make cuts and fill histograms here
    	//******************************************************************        
        //Loop over each channel in each sensor
        int rowIndex=0;
        for(const auto& row : ampLGAD)
        {
            for(unsigned int i = 0; i < row.size(); i++)
            {
                const auto& r = std::to_string(rowIndex);
                const auto& s = std::to_string(i);
                const auto& rawAmpChannel = rawAmpLGAD[rowIndex][i];
                bool goodNoiseAmp = rawAmpChannel>noiseAmpThreshold;
                double timeTracker = timeLGADTracker[rowIndex][i];
                
                utility::fillHisto(pass && goodNoiseAmp,                                my_3d_histos, "amplitude_vs_xy_channel"+r+s, x,y,rawAmpChannel);
                utility::fillHisto(pass && goodNoiseAmp,                                my_3d_histos, "timeDiff_fine_vs_xy_channel"+r+s, x,y,timeTracker-photekTime);

            }
            rowIndex++;
        }
        for(uint i=0;i<n_scope_channels;i++)
        {
            const auto& rawAmpChannel = amp[i];
 
            //std::cout<< corrTime[i]  <<std::endl;
            //std::cout<< TrgTime  <<std::endl;
            
            bool goodNoiseAmp = rawAmpChannel>noiseAmpThreshold;
            utility::fillHisto(pass && goodNoiseAmp,                                    my_3d_histos, Form("timeDiff_coarse_vs_xy_channel0%i",i), x,y,corrTime[i]-photekTime);
        }

        utility::fillHisto(pass && goodMaxLGADAmp && goodNeighbour && twoGoodChannel,   my_2d_prof, "y_vs_Amp1OverAmp1and2_deltaT_prof", Amp1OverAmp1and2, deltaT, parityMax*y);

    } //event loop
}

void InitialAnalyzer::WriteHistos(TFile* outfile)
{
    outfile->cd();
    for(const auto& p : my_histos)       p.second->Write();
    for(const auto& p : my_2d_histos)    p.second->Write();
    for(const auto& p : my_3d_histos)    p.second->Write();
    for(const auto& p : my_2d_prof)      p.second->Write();
    for(const auto& p : my_1d_prof)      p.second->Write();
    for(const auto& p : my_efficiencies) p.second->Write();
    std::cout<<"Made it to the end of writing histos"<<std::endl;
}

