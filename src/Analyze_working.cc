#define Analyze_cxx
#include "TestbeamReco/interface/Analyze.h"
#include "TestbeamReco/interface/Utility.h"
#include "TestbeamReco/interface/NTupleReader.h"

#include <TH1D.h>
#include <TH2D.h>
#include <TEfficiency.h>
#include <TFile.h>
#include <iostream>

Analyze::Analyze()
{
}

//Define all your histograms here. 
void Analyze::InitHistos(NTupleReader& tr, const std::vector<std::vector<int>>& geometry)
{
    TH1::SetDefaultSumw2();
    TH2::SetDefaultSumw2();

    //This event counter histogram is necessary so that we know that all the condor jobs ran successfully. If not, when you use the hadder script, you will see a discrepancy in red as the files are being hadded.
    my_histos.emplace( "EventCounter", std::make_shared<TH1D>( "EventCounter", "EventCounter", 2, -1.1, 1.1 ) ) ;

    //Define 1D histograms
    const auto& pitch = tr.getVar<double>("pitch");
    const auto& xBinSize = tr.getVar<double>("xBinSize");
    const auto& yBinSize = tr.getVar<double>("yBinSize");
    const auto& xmin = tr.getVar<double>("xmin");
    const auto& xmax = tr.getVar<double>("xmax");
    const auto& ymin = tr.getVar<double>("ymin");
    const auto& ymax = tr.getVar<double>("ymax");
    const auto& regionsOfIntrest = tr.getVar<std::vector<utility::ROI>>("regionsOfIntrest");
    int xbins = 175;
    int ybins = 175;
    double xBinSizePad = 0.5;
    double yBinSizePad = 0.5;

    int timeDiffNbin = 200; // 200
    double timeDiffLow = -1.0;
    double timeDiffHigh = 1.0;
    int timeDiffYnbin = 50;

    int    bvNbin = 500;
    double bvLow  = 0.0;
    double bvHigh = 500.0;

    int rowIndex = 0;
    for(const auto& row : geometry)
    {
        if(row.size()<2) continue;
        for(unsigned int i = 0; i < row.size(); i++)
        {
            const auto& r = std::to_string(rowIndex);
            const auto& s = std::to_string(i);

            utility::makeHisto(my_histos,"timeDiff_channel"+r+s, "", timeDiffNbin,timeDiffLow,timeDiffHigh);
            utility::makeHisto(my_histos,"timeDiffTracker_channel"+r+s, "", timeDiffNbin,timeDiffLow,timeDiffHigh);
            utility::makeHisto(my_histos,"weighted2_timeDiff_channel"+r+s, "", timeDiffNbin,timeDiffLow,timeDiffHigh);
            utility::makeHisto(my_histos,"weighted2_timeDiff_tracker_channel"+r+s, "", timeDiffNbin,timeDiffLow,timeDiffHigh);
	    utility::makeHisto(my_histos,"baselineRMS"+r+s,"", 200,-10.0,10.0);
	    utility::makeHisto(my_histos,"risetime"+r+s,"", 150,0.0,1500.0);
            utility::makeHisto(my_histos,"charge"+r+s,"", 300,0.0,150.0);
            utility::makeHisto(my_histos,"ampChargeRatio"+r+s,"", 300,0.0,15.0);
            utility::makeHisto(my_histos,"slewrate"+r+s,"", 300,0.0,400.0);
            utility::makeHisto(my_histos,"slewRateChargeRatio"+r+s,"", 300,0.0,30.0);
            utility::makeHisto(my_3d_histos,"amplitude_vs_xy_channel"+r+s,"; X [mm]; Y [mm]",(xmax-xmin)/xBinSize,xmin,xmax, (ymax-ymin)/yBinSize,ymin,ymax, 250,0,500 );
            utility::makeHisto(my_2d_histos,"Amp1OverAmp1and2_vs_deltaXmax_channel"+r+s, "; X_{track} - X_{Max Strip} [mm]; Amp_{Max} / Amp_{Max} + Amp_{2}", (5*pitch)/0.02,-2.5*pitch,2.5*pitch, 100,0.0,1.0);

        }
        rowIndex++;
    }
            utility::makeHisto(my_3d_histos,"amplitude_vs_xy","; X [mm]; Y [mm]",(xmax-xmin)/xBinSize,xmin,xmax, (ymax-ymin)/yBinSize,ymin,ymax, 250,0,500 );
            utility::makeHisto(my_3d_histos,"timeDiff_vs_xy", "; X [mm]; Y [mm]", (xmax-xmin)/xBinSize,xmin,xmax, timeDiffYnbin,ymin,ymax, timeDiffNbin,timeDiffLow,timeDiffHigh);
            utility::makeHisto(my_3d_histos,"timeDiffTracker_vs_xy", "; X [mm]; Y [mm]", (xmax-xmin)/xBinSize,xmin,xmax, timeDiffYnbin,ymin,ymax, timeDiffNbin,timeDiffLow,timeDiffHigh);
            utility::makeHisto(my_3d_histos,"weighted2_timeDiff_tracker_vs_xy", "; X [mm]; Y [mm]", (xmax-xmin)/xBinSize,xmin,xmax, timeDiffYnbin,ymin,ymax, timeDiffNbin,timeDiffLow,timeDiffHigh);

            utility::makeHisto(my_2d_histos,"Amp1OverAmp1and2_vs_deltaXmax", "",           (5*pitch)/0.01,-2.5*pitch,2.5*pitch, 100,0.0,1.0);
            utility::makeHisto(my_2d_histos,"BaselineRMS12_vs_x", "; X [mm]; Noise Sum 12", (xmax-xmin)/xBinSize,xmin,xmax, 40,0.0,10);
            utility::makeHisto(my_2d_histos,"Amp12_vs_x", "; X [mm]; Sum Amp12", (xmax-xmin)/xBinSize,xmin,xmax, 250,0.0,500);
            utility::makeHisto(my_2d_histos,"Amp1_vs_x", "; X [mm]; Amp1", (xmax-xmin)/xBinSize,xmin,xmax, 250,0.0,500);
            utility::makeHisto(my_2d_histos,"Amp2_vs_x", "; X [mm]; Amp2", (xmax-xmin)/xBinSize,xmin,xmax, 250,0.0,500);
            utility::makeHisto(my_2d_histos,"dXdFrac_vs_Xtrack", "; X_{track} [mm]; dX/dFraction [mm]", (xmax-xmin)/xBinSize,xmin,xmax, 500,-19.0,1.0);
            utility::makeHisto(my_2d_histos,"deltaX_vs_Xtrack_twoStrips", "; X_{track} [mm]; #X_{reco} - X_{track} [mm]", (xmax-xmin)/xBinSize,xmin,xmax, 200,-0.5,0.5);


    std::cout<<"Finished defining histos"<<std::endl;
}

//Put everything you want to do per event here.
void Analyze::Loop(NTupleReader& tr, int maxevents)
{
    const auto& indexToGeometryMap = tr.getVar<std::map<int, std::vector<int>>>("indexToGeometryMap");
    const auto& geometry = tr.getVar<std::vector<std::vector<int>>>("geometry");
    const auto& numLGADchannels = tr.getVar<int>("numLGADchannels");
    const auto& noiseAmpThreshold = tr.getVar<double>("noiseAmpThreshold");
    const auto& signalAmpThreshold = tr.getVar<double>("signalAmpThreshold");
    const auto& sensorEdges = tr.getVar<std::vector<std::vector<double>>>("sensorEdges");
    const auto& stripWidth = tr.getVar<double>("stripWidth");
    const auto& lowGoodStripIndex = tr.getVar<int>("lowGoodStripIndex");
    const auto& highGoodStripIndex = tr.getVar<int>("highGoodStripIndex");
    const auto& firstFile = tr.getVar<bool>("firstFile");
    const auto& regionsOfIntrest = tr.getVar<std::vector<utility::ROI>>("regionsOfIntrest");
    const auto& voltage = tr.getVar<int>("voltage");
    const auto& positionRecoMaxPoint = tr.getVar<double>("positionRecoMaxPoint");


    if(firstFile) InitHistos(tr, geometry);

    while( tr.getNextEvent() )
    {
        //This is added to count the number of events- do not change the next two lines.
        const auto& eventCounter = tr.getVar<int>("eventCounter");
        my_histos["EventCounter"]->Fill( eventCounter );

        //Print Event Number 
        if( maxevents != -1 && tr.getEvtNum() >= maxevents ) break;
        if( tr.getEvtNum() % 100000 == 0 ) printf( " Event %i\n", tr.getEvtNum() );

        const auto& corrAmp = tr.getVec<double>("corrAmp");
        const auto& ampLGAD = tr.getVec<std::vector<double>>("ampLGAD");

	const auto& baselineRMS = tr.getVec<std::vector<float>>("baselineRMS");
        const auto& risetimeLGAD = tr.getVec<std::vector<double>>("risetimeLGAD");
        const auto& chargeLGAD = tr.getVec<std::vector<double>>("chargeLGAD");
        const auto& ampChargeRatioLGAD = tr.getVec<std::vector<double>>("ampChargeRatioLGAD");
        const auto& slewrateLGAD = tr.getVec<std::vector<double>>("slewrateLGAD");
        const auto& slewRateChargeRatioLGAD = tr.getVec<std::vector<double>>("slewRateChargeRatioLGAD");


        const auto& corrTime = tr.getVec<double>("corrTime");
        const auto& timeLGAD = tr.getVec<std::vector<double>>("timeLGAD");
        const auto& timeLGADTracker = tr.getVec<std::vector<double>>("timeLGADTracker");
        
        const auto& x = tr.getVar<double>("x");
        const auto& x_reco = tr.getVar<double>("x_reco");
        const auto& y = tr.getVar<double>("y");
        const auto& TrgTime = tr.getVar<double>("TrgTime");
        const auto& dXdFrac = tr.getVar<double>("dXdFrac");


        const auto& weighted_time = tr.getVar<double>("weighted_time");
        const auto& weighted_time_tracker = tr.getVar<double>("weighted_time_tracker");
        const auto& weighted2_time = tr.getVar<double>("weighted2_time");
        const auto& weighted2_time_tracker = tr.getVar<double>("weighted2_time_tracker");

        const auto& hitSensor = tr.getVar<bool>("hitSensor");
        const auto& maxAmpLGAD = tr.getVar<double>("maxAmpLGAD");
        const auto& maxAmpIndex = tr.getVar<int>("maxAmpIndex");
        const auto& amp1Indexes = tr.getVar<std::pair<int,int>>("amp1Indexes");
        const auto& amp2Indexes = tr.getVar<std::pair<int,int>>("amp2Indexes");
        const auto& Noise12 = tr.getVar<double>("Noise12");
        const auto& Amp12 = tr.getVar<double>("Amp12");


        const auto& deltaXmax = tr.getVar<double>("deltaXmax");
        const auto& Amp1OverAmp1and2 = tr.getVar<double>("Amp1OverAmp1and2");
        const auto& goodNeighbour = tr.getVar<bool>("goodNeighbour");
        
        //Define selection bools
        bool pass =  hitSensor; // equivalent to pass_loose
        bool goodOverNoiseAmp = maxAmpLGAD > noiseAmpThreshold;
        bool goodMaxLGADAmp = maxAmpLGAD > signalAmpThreshold;
        double photekTime = TrgTime;
        double maxAmp = ampLGAD[amp1Indexes.first][amp1Indexes.second];
        double maxAmpTime = timeLGAD[amp1Indexes.first][amp1Indexes.second];
        double maxAmpTimeTracker = timeLGADTracker[amp1Indexes.first][amp1Indexes.second];
        double amp2 = ampLGAD[amp2Indexes.first][amp2Indexes.second];

        bool twoGoodHits = ampLGAD[amp1Indexes.first][amp1Indexes.second] > noiseAmpThreshold && ampLGAD[amp2Indexes.first][amp2Indexes.second] > noiseAmpThreshold;
        bool twoStripsReco = goodNeighbour && (Amp1OverAmp1and2 < positionRecoMaxPoint);
        
        //******************************************************************
        //Make cuts and fill histograms here
    	//******************************************************************        
        //Loop over each channel in each sensor
        bool goodHitGlobal2and5 = false;
        int rowIndex = 0;
        for(const auto& row : ampLGAD)
        {
            for(unsigned int i = 0; i < row.size(); i++)
            {
                const auto& r = std::to_string(rowIndex);
                const auto& s = std::to_string(i);
                const auto& ampChannel = ampLGAD[rowIndex][i];
                bool goodNoiseAmp = ampChannel>noiseAmpThreshold;
                bool goodSignalAmp = ampChannel>signalAmpThreshold;
                bool goodHit = goodNoiseAmp && goodMaxLGADAmp;
                double time = timeLGAD[rowIndex][i];
                double timeTracker = timeLGADTracker[rowIndex][i];
                bool isMaxChannel = amp1Indexes.first == rowIndex && amp1Indexes.second == int(i);

                const auto& noise = baselineRMS[rowIndex][i]; 
                const auto& risetime = risetimeLGAD[rowIndex][i];
                const auto& charge = chargeLGAD[rowIndex][i];
                const auto& ampChargeRatio = ampChargeRatioLGAD[rowIndex][i];
                const auto& slewrate = slewrateLGAD[rowIndex][i];
                const auto& slewRateChargeRatio = slewRateChargeRatioLGAD[rowIndex][i];

		utility::fillHisto(pass && goodHit,                         my_histos, "timeDiff_channel"+r+s, time-photekTime);
                utility::fillHisto(pass && goodHit,                         my_histos, "timeDiffTracker_channel"+r+s, timeTracker-photekTime);
                utility::fillHisto(pass && goodHit,                         my_histos, "weighted2_timeDiff_channel"+r+s, weighted2_time-photekTime);
                utility::fillHisto(pass && goodHit,                         my_histos, "weighted2_timeDiff_tracker_channel"+r+s, weighted2_time_tracker-photekTime);
		utility::fillHisto(pass && goodHit && isMaxChannel,                         my_histos, "baselineRMS"+r+s, noise);
                utility::fillHisto(pass && goodHit && isMaxChannel,                         my_histos, "risetime"+r+s, risetime);
                utility::fillHisto(pass && goodHit && isMaxChannel,                         my_histos, "charge"+r+s, charge);
                utility::fillHisto(pass && goodHit && isMaxChannel,                         my_histos, "ampChargeRatio"+r+s, ampChargeRatio);
                utility::fillHisto(pass && goodHit && isMaxChannel,                         my_histos, "slewRateChargeRatio"+r+s, slewRateChargeRatio); 
                utility::fillHisto(pass && goodHit && isMaxChannel,                         my_histos, "slewrate"+r+s, slewrate);
                utility::fillHisto(pass && goodHit,                         my_3d_histos, "amplitude_vs_xy_channel"+r+s, x,y,ampChannel);
                utility::fillHisto(pass && goodHit && isMaxChannel && goodNeighbour,         my_2d_histos, "Amp1OverAmp1and2_vs_deltaXmax_channel"+r+s, deltaXmax, Amp1OverAmp1and2);

            }
            rowIndex++;
        }
      
                 utility::fillHisto(pass && goodMaxLGADAmp,                  my_3d_histos, "amplitude_vs_xy", x,y,maxAmp);
                 utility::fillHisto(pass && goodMaxLGADAmp && twoStripsReco, my_3d_histos, "timeDiff_vs_xy", x,y,maxAmpTime-photekTime);
                 utility::fillHisto(pass && goodMaxLGADAmp && twoStripsReco, my_3d_histos, "timeDiffTracker_vs_xy", x,y,maxAmpTimeTracker-photekTime);
                 utility::fillHisto(pass && goodMaxLGADAmp && twoStripsReco, my_3d_histos, "weighted2_timeDiff_tracker_vs_xy", x,y,weighted2_time_tracker-photekTime);
                 utility::fillHisto(pass && goodMaxLGADAmp && twoGoodHits,   my_2d_histos, "Amp1OverAmp1and2_vs_deltaXmax", fabs(deltaXmax),Amp1OverAmp1and2);
                 utility::fillHisto(pass && goodMaxLGADAmp && twoStripsReco, my_2d_histos, "deltaX_vs_Xtrack_twoStrips", x,x_reco-x);
                 utility::fillHisto(pass && goodMaxLGADAmp && twoStripsReco, my_2d_histos, "BaselineRMS12_vs_x", x, Noise12);
                 utility::fillHisto(pass && goodMaxLGADAmp && twoStripsReco, my_2d_histos, "Amp12_vs_x", x, Amp12);
                 utility::fillHisto(pass && goodMaxLGADAmp && twoStripsReco, my_2d_histos, "Amp1_vs_x", x, maxAmp);
                 utility::fillHisto(pass && goodMaxLGADAmp && twoStripsReco, my_2d_histos, "Amp2_vs_x", x, amp2);
                 utility::fillHisto(pass && goodMaxLGADAmp && twoStripsReco, my_2d_histos, "dXdFrac_vs_Xtrack", x,dXdFrac);



    } //event loop
}

void Analyze::WriteHistos(TFile* outfile)
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

