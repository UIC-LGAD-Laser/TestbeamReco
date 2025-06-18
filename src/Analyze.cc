#define Analyze_cxx
#include "TestbeamReco/interface/Analyze.h"
#include "TestbeamReco/interface/Utility.h"
#include "TestbeamReco/interface/NTupleReader.h"

#include <TH1D.h>
#include <TH2D.h>
#include <TEfficiency.h>
#include <TFile.h>
#include <iostream>
#include <fstream>

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
    double timeDiffLow = -1.0;//40.0;//
    double timeDiffHigh = 1.0;//50.0;//
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
            utility::makeHisto(my_histos,"baselineRMSSlewRateRatio"+r+s,"", 100,0.0,100.0);
            utility::makeHisto(my_histos,"baselineRMS"+r+s,"", 200,-10.0,10.0);
            utility::makeHisto(my_histos,"slewRateChargeRatio"+r+s,"", 300,0.0,30.0);
            utility::makeHisto(my_histos,"slewrate"+r+s,"", 300,0.0,400.0);
            utility::makeHisto(my_histos,"risetime"+r+s,"", 500,0.0,1500.0);
            utility::makeHisto(my_3d_histos,"baselineRMS_vs_xy_channel"+r+s,"; X [mm]; Y [mm]",std::round((xmax-xmin)/xBinSize),xmin,xmax, (ymax-ymin)/yBinSize,ymin,ymax, 100,0,50 );
            utility::makeHisto(my_3d_histos,"slewRate_vs_xy_channel"+r+s,"; X [mm]; Y [mm]",std::round((xmax-xmin)/xBinSize),xmin,xmax, (ymax-ymin)/yBinSize,ymin,ymax,300,0.0,500.0);
            utility::makeHisto(my_3d_histos,"signalOverNoise_vs_xy_channel"+r+s,"; X [mm]; Y [mm]",std::round((xmax-xmin)/xBinSize),xmin,xmax, (ymax-ymin)/yBinSize,ymin,ymax,200,0.0,200.0);
            utility::makeHisto(my_3d_histos,"risetime_vs_xy_channel"+r+s,"; X [mm]; Y [mm]",std::round((xmax-xmin)/xBinSize),xmin,xmax, (ymax-ymin)/yBinSize,ymin,ymax, 500,0.0,1500.0);
            utility::makeHisto(my_2d_histos,"amplitude_vs_risetime"+r+s, "; amp [mV]; risetime [ps]", 400,0.0,400.0, 500,0.0,1500.0);
            utility::makeHisto(my_3d_histos,"amplitude_vs_xy_channel"+r+s,"; X [mm]; Y [mm]",std::round((xmax-xmin)/xBinSize),xmin,xmax, (ymax-ymin)/yBinSize,ymin,ymax, 250,0,500 );
            utility::makeHisto(my_2d_histos,"Amp1OverAmp1and2_vs_deltaXmax_channel"+r+s, "; X_{track} - X_{Max Strip} [mm]; Amp_{Max} / Amp_{Max} + Amp_{2}", (5*pitch)/0.02,-2.5*pitch,2.5*pitch, 100,0.0,1.0);
        }
        rowIndex++;
    }

    // Global 1D Histograms
    utility::makeHisto(my_histos,"wave0", "; Time [ns]; Voltage [mV]", 500,0.0,25.0);
    utility::makeHisto(my_histos,"wave1", "; Time [ns]; Voltage [mV]", 500,0.0,25.0);
    utility::makeHisto(my_histos,"wave2", "; Time [ns]; Voltage [mV]", 500,0.0,25.0);
    utility::makeHisto(my_histos,"wave3", "; Time [ns]; Voltage [mV]", 500,0.0,25.0);

    utility::makeHisto(my_1d_prof,"waveProf0", "; Time [ns]; Voltage [mV]", 500,0.0,25.0);
    utility::makeHisto(my_1d_prof,"waveProf1", "; Time [ns]; Voltage [mV]", 500,0.0,25.0);
    utility::makeHisto(my_1d_prof,"waveProf2", "; Time [ns]; Voltage [mV]", 500,0.0,25.0);
    utility::makeHisto(my_1d_prof,"waveProf3", "; Time [ns]; Voltage [mV]", 500,0.0,25.0);
    
    for(unsigned int k = 0; k < regionsOfIntrest.size(); k++)
    {
        utility::makeHisto(my_1d_prof,"waveProf0"+regionsOfIntrest[k].getName(), "; Time [ns]; Voltage [mV]", 500,0.0,25.0);
        utility::makeHisto(my_1d_prof,"waveProf1"+regionsOfIntrest[k].getName(), "; Time [ns]; Voltage [mV]", 500,0.0,25.0);
        utility::makeHisto(my_1d_prof,"waveProf2"+regionsOfIntrest[k].getName(), "; Time [ns]; Voltage [mV]", 500,0.0,25.0);
        utility::makeHisto(my_1d_prof,"waveProf3"+regionsOfIntrest[k].getName(), "; Time [ns]; Voltage [mV]", 500,0.0,25.0);
    }

    utility::makeHisto(my_histos,"weighted2_timeDiff_tracker", "", timeDiffNbin,timeDiffLow,timeDiffHigh);
    utility::makeHisto(my_histos,"weighted2_timeDiff_tracker_noMetal", "", timeDiffNbin,timeDiffLow,timeDiffHigh);
    utility::makeHisto(my_histos,"weighted_jitter_hist", "", 200, 0, 200);

    // Global 2D Histograms
    utility::makeHisto(my_2d_histos,"Amp1OverAmp1and2_vs_deltaXmax", "",           (5*pitch)/0.01,-2.5*pitch,2.5*pitch, 100,0.0,1.0);
    utility::makeHisto(my_2d_histos,"BaselineRMS12_vs_x", "; X [mm]; Noise Sum 12", std::round((xmax-xmin)/xBinSize),xmin,xmax, 40,0.0,10);
    utility::makeHisto(my_2d_histos,"Amp12_vs_x", "; X [mm]; Sum Amp12", std::round((xmax-xmin)/xBinSize),xmin,xmax, 250,0.0,500);
    utility::makeHisto(my_2d_histos,"Amp1_vs_x", "; X [mm]; Amp1", std::round((xmax-xmin)/xBinSize),xmin,xmax, 250,0.0,500);
    utility::makeHisto(my_2d_histos,"Amp2_vs_x", "; X [mm]; Amp2", std::round((xmax-xmin)/xBinSize),xmin,xmax, 250,0.0,500);

    // DS - Add 2 histograms to calculate efficiencies and fraction of twoGoodHits to oneGoodHit for input to simulation
    utility::makeHisto(my_2d_histos,"efficiency_vs_x_OneGoodHit", "; X [mm]; Counts", std::round((xmax-xmin)/xBinSize),xmin,xmax, 100, 0, 5000);
    utility::makeHisto(my_2d_histos,"efficiency_vs_x_TwoGoodHit", "; X [mm]; Counts", std::round((xmax-xmin)/xBinSize),xmin,xmax, 100, 0, 5000);
    utility::makeHisto(my_2d_histos,"efficiency_vs_xy_denominator_coarseBins", "; X [mm]; Y [mm]", std::round((xmax-xmin)/xBinSize),xmin,xmax, std::round((ymax-ymin)/yBinSize),ymin,ymax);
    utility::makeHisto(my_2d_histos,"efficiency_vs_xy_numerator_coarseBins", "; X [mm]; Y [mm]", std::round((xmax-xmin)/xBinSize),xmin,xmax, std::round((ymax-ymin)/yBinSize),ymin,ymax);
    utility::makeHisto(my_2d_histos,"efficiency_vs_xy_oneStrip_numerator_coarseBins", "; X [mm]; Y [mm]", std::round((xmax-xmin)/xBinSize),xmin,xmax, std::round((ymax-ymin)/yBinSize),ymin,ymax);
    utility::makeHisto(my_2d_histos,"efficiency_vs_xy_twoStrip_numerator_coarseBins", "; X [mm]; Y [mm]", std::round((xmax-xmin)/xBinSize),xmin,xmax, std::round((ymax-ymin)/yBinSize),ymin,ymax);

    utility::makeHisto(my_2d_histos,"dXdFrac_vs_Xtrack", "; X_{track} [mm]; dX/dFraction [mm]", std::round((xmax-xmin)/xBinSize),xmin,xmax, 500,-19.0,1.0);
    utility::makeHisto(my_2d_histos,"deltaX_vs_Xtrack_twoStrips", "; X_{track} [mm]; #X_{reco} - X_{track} [mm]", std::round((xmax-xmin)/xBinSize),xmin,xmax, 200,-0.5,0.5);
    utility::makeHisto(my_2d_histos,"amplitude_vs_risetime","; amp [mV]; risetime [ps]",500, 0, 500, 500, 0, 1500);
    utility::makeHisto(my_2d_histos,"amplitude_vs_risetime_onMetal","; amp [mV]; risetime [ps]",500, 0, 500, 500, 0, 1500);
    utility::makeHisto(my_2d_histos,"amplitude_vs_dT","; amp [mV]; dT [ps]",40,20,100, timeDiffNbin,timeDiffLow,timeDiffHigh);
    // utility::makeHisto(my_2d_histos,"amplitude_vs_dT","; amp [mV]; dT [ps]",150,0,300, timeDiffNbin,timeDiffLow,timeDiffHigh);//, 25,0,500);
    
    // Global 3D Histograms
    utility::makeHisto(my_3d_histos,"amplitude_vs_xy","; X [mm]; Y [mm]",std::round((xmax-xmin)/xBinSize),xmin,xmax, (ymax-ymin)/yBinSize,ymin,ymax, 250, 0, 500);
    utility::makeHisto(my_3d_histos,"baselineRMS_vs_xy","; X [mm]; Y [mm]",std::round((xmax-xmin)/xBinSize),xmin,xmax, (ymax-ymin)/yBinSize,ymin,ymax, 150,0.0,50.0);
    utility::makeHisto(my_3d_histos,"risetime_vs_xy","; X [mm]; Y [mm]",std::round((xmax-xmin)/xBinSize),xmin,xmax, (ymax-ymin)/yBinSize,ymin,ymax, 500,0.0,1500.0);
    utility::makeHisto(my_3d_histos,"slewRate_vs_xy","; X [mm]; Y [mm]",std::round((xmax-xmin)/xBinSize),xmin,xmax, (ymax-ymin)/yBinSize,ymin,ymax,300,0.0,500.0);
    utility::makeHisto(my_3d_histos,"signalOverNoise_vs_xy","; X [mm]; Y [mm]",std::round((xmax-xmin)/xBinSize),xmin,xmax, (ymax-ymin)/yBinSize,ymin,ymax,200,0.0,200.0);
    utility::makeHisto(my_3d_histos,"charge_vs_xy","; X [mm]; Y [mm]",std::round((xmax-xmin)/xBinSize),xmin,xmax, (ymax-ymin)/yBinSize,ymin,ymax,300,0.0,150.0);
    utility::makeHisto(my_3d_histos,"ampChargeRatio_vs_xy","; X [mm]; Y [mm]",std::round((xmax-xmin)/xBinSize),xmin,xmax, (ymax-ymin)/yBinSize,ymin,ymax,300,0.0,15.0);
    utility::makeHisto(my_3d_histos,"timeDiff_vs_xy", "; X [mm]; Y [mm]", std::round((xmax-xmin)/xBinSize),xmin,xmax, (ymax-ymin)/yBinSize,ymin,ymax, timeDiffNbin,timeDiffLow,timeDiffHigh);
    utility::makeHisto(my_3d_histos,"timeDiffTracker_vs_xy", "; X [mm]; Y [mm]", std::round((xmax-xmin)/xBinSize),xmin,xmax, (ymax-ymin)/yBinSize,ymin,ymax, timeDiffNbin,timeDiffLow,timeDiffHigh);
    utility::makeHisto(my_3d_histos,"weighted2_timeDiff_tracker_vs_xy", "; X [mm]; Y [mm]", std::round((xmax-xmin)/xBinSize),xmin,xmax, (ymax-ymin)/yBinSize,ymin,ymax, timeDiffNbin,timeDiffLow,timeDiffHigh);
    //DS - new variables to plot t1 and t2 vs X and compare with simulation results.
    utility::makeHisto(my_3d_histos,"t1_res_vs_xy", "; X [mm]; Y [mm]", std::round((xmax-xmin)/xBinSize),xmin,xmax, (ymax-ymin)/yBinSize,ymin,ymax, timeDiffNbin,timeDiffLow,timeDiffHigh);
    utility::makeHisto(my_3d_histos,"t2_res_vs_xy", "; X [mm]; Y [mm]", std::round((xmax-xmin)/xBinSize),xmin,xmax, (ymax-ymin)/yBinSize,ymin,ymax, timeDiffNbin,timeDiffLow,timeDiffHigh);
    utility::makeHisto(my_3d_histos,"jitter1_res_vs_xy", "; X [mm]; Y [mm]", std::round((xmax-xmin)/xBinSize),xmin,xmax, (ymax-ymin)/yBinSize,ymin,ymax, 200.0, 0.0, 200.0);
    utility::makeHisto(my_3d_histos,"jitter2_res_vs_xy", "; X [mm]; Y [mm]", std::round((xmax-xmin)/xBinSize),xmin,xmax, (ymax-ymin)/yBinSize,ymin,ymax, 200.0, 0.0, 200.0);
    utility::makeHisto(my_3d_histos,"weighted2_time_tracker_vs_xy", "; X [mm]; Y [mm]", std::round((xmax-xmin)/xBinSize),xmin,xmax, (ymax-ymin)/yBinSize,ymin,ymax, 2000,11.0,11.6);
    utility::makeHisto(my_3d_histos,"photektime_vs_xy", "; X [mm]; Y [mm]", std::round((xmax-xmin)/xBinSize),xmin,xmax, (ymax-ymin)/yBinSize,ymin,ymax, 2000,11.0,11.6);
    utility::makeHisto(my_3d_histos,"weighted2_timeDiff_tracker_vs_xy_noMetal", "; X [mm]; Y [mm]", std::round((xmax-xmin)/xBinSize),xmin,xmax, (ymax-ymin)/yBinSize,ymin,ymax, timeDiffNbin,timeDiffLow,timeDiffHigh);
    utility::makeHisto(my_3d_histos,"weighted_jitter_vs_xy", "; X [mm]; Y [mm]", std::round((xmax-xmin)/xBinSize),xmin,xmax, (ymax-ymin)/yBinSize,ymin,ymax, 200.0, 0.0, 200.0);
    // utility::makeHisto(my_3d_histos,"timeDiff_vs_xy", "; X [mm]; Y [mm]", std::round((xmax-xmin)/xBinSize),xmin,xmax, timeDiffYnbin,ymin,ymax, timeDiffNbin,timeDiffLow,timeDiffHigh);
    // utility::makeHisto(my_3d_histos,"timeDiffTracker_vs_xy", "; X [mm]; Y [mm]", std::round((xmax-xmin)/xBinSize),xmin,xmax, timeDiffYnbin,ymin,ymax, timeDiffNbin,timeDiffLow,timeDiffHigh);
    // utility::makeHisto(my_3d_histos,"weighted2_timeDiff_tracker_vs_xy", "; X [mm]; Y [mm]", std::round((xmax-xmin)/xBinSize),xmin,xmax, timeDiffYnbin,ymin,ymax, timeDiffNbin,timeDiffLow,timeDiffHigh);

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
    
    const auto& xBinSize = tr.getVar<double>("xBinSize");
    
    if(firstFile) InitHistos(tr, geometry);

    int max_save = 10;
    int counter[2] = {0, 0};

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

        const auto& corrTime = tr.getVec<double>("corrTime");
        const auto& timeLGAD = tr.getVec<std::vector<double>>("timeLGAD");
        const auto& timeLGADTracker = tr.getVec<std::vector<double>>("timeLGADTracker");
        
        const auto& x = tr.getVar<double>("x");
        const auto& x_reco = tr.getVar<double>("x_reco");
        const auto& y = tr.getVar<double>("y");
        const auto& TrgTime = tr.getVar<double>("TrgTime");
        const auto& dXdFrac = tr.getVar<double>("dXdFrac");
        const auto& risetimeLGAD = tr.getVec<std::vector<double>>("risetimeLGAD");
        const auto& chargeLGAD = tr.getVec<std::vector<double>>("chargeLGAD");
        const auto& slewrateLGAD = tr.getVec<std::vector<double>>("slewrateLGAD");
        const auto& ampChargeRatioLGAD = tr.getVec<std::vector<double>>("ampChargeRatioLGAD");
        const auto& photekIndex = tr.getVar<int>("photekIndex"); // for CFD based trigger time calculation
        const auto& baselineRMSSlewRateRatioLGAD = tr.getVec<std::vector<double>>("baselineRMSSlewRateRatioLGAD");
        const auto& baselineRMS = tr.getVec<std::vector<float>>("baselineRMS");
        const auto& slewRateChargeRatioLGAD = tr.getVec<std::vector<double>>("slewRateChargeRatioLGAD");

        const auto& weighted_time = tr.getVar<double>("weighted_time");
        const auto& weighted_time_tracker = tr.getVar<double>("weighted_time_tracker");
        const auto& weighted2_time = tr.getVar<double>("weighted2_time");
        const auto& weighted2_time_tracker = tr.getVar<double>("weighted2_time_tracker");
        const auto& t1_res = tr.getVar<double>("t1_res");
        const auto& t2_res = tr.getVar<double>("t2_res");

        const auto& hitSensor = tr.getVar<bool>("hitSensor");
        const auto& stripCenterXPositionLGAD = tr.getVec<std::vector<double>>("stripCenterXPositionLGAD");
        const auto& maxAmpLGAD = tr.getVar<double>("maxAmpLGAD");
        const auto& maxAmpIndex = tr.getVar<int>("maxAmpIndex");
        const auto& amp1Indexes = tr.getVar<std::pair<int,int>>("amp1Indexes");
        const auto& amp2Indexes = tr.getVar<std::pair<int,int>>("amp2Indexes");
        const auto& Noise12 = tr.getVar<double>("Noise12");
        const auto& Amp12 = tr.getVar<double>("Amp12");
        double maxAmp = ampLGAD[amp1Indexes.first][amp1Indexes.second];
        double maxAmpTime = timeLGAD[amp1Indexes.first][amp1Indexes.second];
        double maxAmpTimeTracker = timeLGADTracker[amp1Indexes.first][amp1Indexes.second];
        double amp1 = ampLGAD[amp1Indexes.first][amp1Indexes.second];
        double amp2 = ampLGAD[amp2Indexes.first][amp2Indexes.second];
        double jitter1 = baselineRMSSlewRateRatioLGAD[amp1Indexes.first][amp1Indexes.second];
        double jitter2 = baselineRMSSlewRateRatioLGAD[amp2Indexes.first][amp2Indexes.second];
        double weighted_jitter = 0.0;

        const auto& deltaXmax = tr.getVar<double>("deltaXmax");
        const auto& Amp1OverAmp1and2 = tr.getVar<double>("Amp1OverAmp1and2");
        const auto& goodNeighbour = tr.getVar<bool>("goodNeighbour");

        //Define selection bools
        bool pass =  hitSensor; // equivalent to pass_loose
        bool goodOverNoiseAmp = maxAmpLGAD > noiseAmpThreshold;
        bool goodMaxLGADAmp = maxAmpLGAD > signalAmpThreshold;
        bool midgap = ((x>0.225) && (x<0.275))||((x<-0.225) && (x>-0.275));

        bool oneGoodHit = ampLGAD[amp1Indexes.first][amp1Indexes.second] > noiseAmpThreshold;
        bool twoGoodHits = ampLGAD[amp1Indexes.first][amp1Indexes.second] > noiseAmpThreshold && ampLGAD[amp2Indexes.first][amp2Indexes.second] > noiseAmpThreshold;
        bool twoStripsReco = goodNeighbour && (Amp1OverAmp1and2 < positionRecoMaxPoint);
        //bool twoStripsReco = (Amp1OverAmp1and2 < positionRecoMaxPoint);   
        bool hitOnMetal = false;
        bool LaserhitOnMetal = false;

        // double photekTime = TrgTime; // old method to set trigger time
        double photekTime = corrTime[photekIndex];
        // std::cout<<"CFDTime = "<<photekTime<<std::endl;


        if(twoGoodHits){weighted_jitter = std::sqrt((amp1*amp1*amp1*amp1*jitter1*jitter1 + amp2*amp2*amp2*amp2*jitter2*jitter2)/(((amp1*amp1) + (amp2*amp2))*((amp1*amp1) + (amp2*amp2))));}//std::sqrt((amp1*amp1*jitter1*jitter1 + amp2*amp2*jitter2*jitter2)/(amp1*amp1+amp2*amp2));}
        else if(!twoGoodHits){weighted_jitter = jitter1;}

        //******************************************************************
        //Make cuts and fill histograms here
    	//******************************************************************        
        //Loop over each channel in each sensor
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
                if (((stripCenterXPositionLGAD[rowIndex][i]-stripWidth/2.)<x) && (x<(stripCenterXPositionLGAD[rowIndex][i]+stripWidth/2.)))
                {
                    hitOnMetal = true;
                }
                if (((stripCenterXPositionLGAD[rowIndex][i]-stripWidth/2.-xBinSize)<x) && (x<(stripCenterXPositionLGAD[rowIndex][i]+stripWidth/2.+xBinSize)))
                {
                    LaserhitOnMetal = true;
                }
                const auto& slewrate = slewrateLGAD[rowIndex][i];
                const auto& slewRateChargeRatio = slewRateChargeRatioLGAD[rowIndex][i];
                const auto& baselineRMSSlewRateRatio = baselineRMSSlewRateRatioLGAD[rowIndex][i];
                const auto& noise = baselineRMS[rowIndex][i];
                const auto& risetime = risetimeLGAD[rowIndex][i];
                double time = timeLGAD[rowIndex][i];
                double timeTracker = timeLGADTracker[rowIndex][i];
                bool isMaxChannel = amp1Indexes.first == rowIndex && amp1Indexes.second == int(i);

                utility::fillHisto(pass && goodHit,                         my_histos, "timeDiff_channel"+r+s, time-photekTime);
                utility::fillHisto(pass && goodHit,                         my_histos, "timeDiffTracker_channel"+r+s, timeTracker-photekTime);
                utility::fillHisto(pass && goodHit,                         my_histos, "weighted2_timeDiff_channel"+r+s, weighted2_time-photekTime);
                utility::fillHisto(pass && goodHit,                         my_histos, "weighted2_timeDiff_tracker_channel"+r+s, weighted2_time_tracker-photekTime);
                utility::fillHisto(pass && goodHit,                         my_2d_histos, "amplitude_vs_risetime"+r+s,ampChannel, risetime);
                utility::fillHisto(pass && goodHit,                         my_3d_histos, "amplitude_vs_xy_channel"+r+s, x,y,ampChannel);
                utility::fillHisto(pass && goodHit && isMaxChannel && goodNeighbour,         my_2d_histos, "Amp1OverAmp1and2_vs_deltaXmax_channel"+r+s, deltaXmax, Amp1OverAmp1and2);
                utility::fillHisto(pass && goodHit,                         my_3d_histos, "baselineRMS_vs_xy_channel"+r+s, x,y,noise);
                utility::fillHisto(pass && goodHit,                         my_3d_histos, "slewRate_vs_xy_channel"+r+s, x,y,slewrate);
                utility::fillHisto(pass && goodHit,                         my_3d_histos, "signalOverNoise_vs_xy_channel"+r+s, x,y,ampChannel/noise);
                utility::fillHisto(pass && goodHit,                         my_3d_histos, "risetime_vs_xy_channel"+r+s, x,y,risetime);
                utility::fillHisto(pass && goodHit&& isMaxChannel,          my_histos, "baselineRMSSlewRateRatio"+r+s, baselineRMSSlewRateRatio);
                // utility::fillHisto(pass,  my_histos, "baselineRMS"+r+s, noise);
                utility::fillHisto(pass && goodHit && isMaxChannel,    my_histos, "baselineRMS"+r+s, noise);
                utility::fillHisto(pass && goodHit && isMaxChannel,    my_histos, "slewRateChargeRatio"+r+s, slewRateChargeRatio); 
                utility::fillHisto(pass && goodHit && isMaxChannel,    my_histos, "slewrate"+r+s, slewrate);
                utility::fillHisto(pass && goodHit && isMaxChannel,    my_histos, "risetime"+r+s, risetime);
            }
            rowIndex++;
        }
 
        utility::fillHisto(pass && goodMaxLGADAmp,                  my_histos, "weighted2_timeDiff_tracker", weighted2_time_tracker-photekTime);
        utility::fillHisto(pass && goodMaxLGADAmp && LaserhitOnMetal, my_histos, "weighted2_timeDiff_tracker_noMetal", weighted2_time_tracker-photekTime);
        utility::fillHisto(pass && goodMaxLGADAmp,                  my_histos, "weighted_jitter_hist", weighted_jitter);
    
        utility::fillHisto(pass && goodMaxLGADAmp && twoGoodHits,   my_2d_histos, "Amp1OverAmp1and2_vs_deltaXmax", fabs(deltaXmax),Amp1OverAmp1and2);
        utility::fillHisto(pass && goodMaxLGADAmp && twoStripsReco, my_2d_histos, "deltaX_vs_Xtrack_twoStrips", x,x_reco-x);
        utility::fillHisto(pass && goodMaxLGADAmp && twoStripsReco, my_2d_histos, "BaselineRMS12_vs_x", x, Noise12);
        utility::fillHisto(pass && goodMaxLGADAmp && twoStripsReco, my_2d_histos, "Amp12_vs_x", x, Amp12);
        utility::fillHisto(pass && goodMaxLGADAmp && twoStripsReco, my_2d_histos, "Amp1_vs_x", x, maxAmp);
        utility::fillHisto(pass && goodMaxLGADAmp && twoStripsReco, my_2d_histos, "Amp2_vs_x", x, amp2);

        utility::fillHisto(pass && oneGoodHit,                      my_2d_histos, "efficiency_vs_x_OneGoodHit", x, 1);
        utility::fillHisto(pass && twoGoodHits,                     my_2d_histos, "efficiency_vs_x_TwoGoodHit", x, 1);
        utility::fillHisto(pass,                                                     my_2d_histos, "efficiency_vs_xy_denominator_coarseBins", x,y);
        utility::fillHisto(pass && goodOverNoiseAmp,                                 my_2d_histos, "efficiency_vs_xy_numerator_coarseBins", x,y);
        utility::fillHisto(pass && goodOverNoiseAmp && oneGoodHit && !twoGoodHits,   my_2d_histos, "efficiency_vs_xy_oneStrip_numerator_coarseBins", x,y);
        utility::fillHisto(pass && goodOverNoiseAmp && twoGoodHits,                  my_2d_histos, "efficiency_vs_xy_twoStrip_numerator_coarseBins", x,y);
        
        utility::fillHisto(pass && goodMaxLGADAmp && twoStripsReco, my_2d_histos, "dXdFrac_vs_Xtrack", x,dXdFrac);
        utility::fillHisto(pass && goodMaxLGADAmp,                  my_2d_histos, "amplitude_vs_risetime", maxAmp, risetimeLGAD[amp1Indexes.first][amp1Indexes.second]);
        utility::fillHisto(pass && goodMaxLGADAmp && hitOnMetal,    my_2d_histos, "amplitude_vs_risetime_onMetal", maxAmp, risetimeLGAD[amp1Indexes.first][amp1Indexes.second]);
        utility::fillHisto(pass && goodMaxLGADAmp && midgap,        my_2d_histos, "amplitude_vs_dT", maxAmp, weighted2_time_tracker-photekTime);
        
        utility::fillHisto(pass && goodMaxLGADAmp,                  my_3d_histos, "amplitude_vs_xy", x,y,maxAmp);
        utility::fillHisto(pass && goodMaxLGADAmp,                  my_3d_histos, "baselineRMS_vs_xy", x,y,baselineRMS[amp1Indexes.first][amp1Indexes.second]);
        utility::fillHisto(pass && goodMaxLGADAmp,                  my_3d_histos, "risetime_vs_xy", x,y,risetimeLGAD[amp1Indexes.first][amp1Indexes.second]);
        utility::fillHisto(pass && goodMaxLGADAmp,                  my_3d_histos, "slewRate_vs_xy", x,y,slewrateLGAD[amp1Indexes.first][amp1Indexes.second]);
        utility::fillHisto(pass && goodMaxLGADAmp,                  my_3d_histos, "signalOverNoise_vs_xy", x,y,maxAmp/baselineRMS[amp1Indexes.first][amp1Indexes.second]);
        utility::fillHisto(pass && goodMaxLGADAmp,                  my_3d_histos, "charge_vs_xy", x,y,chargeLGAD[amp1Indexes.first][amp1Indexes.second]);
        utility::fillHisto(pass && goodMaxLGADAmp,                  my_3d_histos, "ampChargeRatio_vs_xy", x,y,ampChargeRatioLGAD[amp1Indexes.first][amp1Indexes.second]);
        utility::fillHisto(pass && goodMaxLGADAmp, my_3d_histos, "timeDiff_vs_xy", x,y,maxAmpTime-photekTime);
        utility::fillHisto(pass && goodMaxLGADAmp, my_3d_histos, "timeDiffTracker_vs_xy", x,y,maxAmpTimeTracker-photekTime);
        utility::fillHisto(pass && goodMaxLGADAmp, my_3d_histos, "weighted2_timeDiff_tracker_vs_xy", x,y,weighted2_time_tracker-photekTime);
        utility::fillHisto(pass && goodMaxLGADAmp, my_3d_histos, "t1_res_vs_xy", x,y,t1_res-photekTime);
        utility::fillHisto(pass && goodMaxLGADAmp, my_3d_histos, "t2_res_vs_xy", x,y,t2_res-photekTime);
        
        utility::fillHisto(pass && goodMaxLGADAmp, my_3d_histos, "weighted2_time_tracker_vs_xy", x,y,weighted2_time_tracker);
        utility::fillHisto(pass && goodMaxLGADAmp, my_3d_histos, "photektime_vs_xy", x,y, photekTime);
        utility::fillHisto(pass && goodMaxLGADAmp && LaserhitOnMetal, my_3d_histos, "weighted2_timeDiff_tracker_vs_xy_noMetal", x,y,weighted2_time_tracker-photekTime);
        utility::fillHisto(pass && goodMaxLGADAmp,   my_3d_histos, "weighted_jitter_vs_xy", x,y, weighted_jitter);
        utility::fillHisto(pass && goodMaxLGADAmp,   my_3d_histos, "jitter1_res_vs_xy", x,y, jitter1);
        utility::fillHisto(pass && goodMaxLGADAmp && twoGoodHits,  my_3d_histos, "jitter2_res_vs_xy", x,y, jitter2);
        
        


        // Fill wave form histos once
        bool maxAmpInCenter = maxAmpIndex == 3;// || maxAmpIndex == 3;
        if(goodMaxLGADAmp)
        {
            const auto& channel = tr.getVecVec<float>("channel");
            const auto& time = tr.getVecVec<float>("time");
            const auto& timeCalibrationCorrection = tr.getVar<std::map<int, double>>("timeCalibrationCorrection");
            for(unsigned int k = 0; k < regionsOfIntrest.size(); k++)
            {
                if(regionsOfIntrest[k].passROI(x,y))
                {
                    // Introduced to provide waveforms to UCSC team for new HPK production 2024
                    // if(counter[k] < max_save)
                    // {
                    //     // Open a CSV file for writing
                    //     // std::ofstream outputFile("waveform_"+regionsOfIntrest[k].getName()+"("+std::to_string(x)+","+std::to_string(y)+")_"+std::to_string(counter[k])+".csv");
                    //     std::ofstream outputFile("waveform_"+regionsOfIntrest[k].getName()+"_"+std::to_string(counter[k])+".csv");
                    //     // Write the header to the CSV file
                    //     outputFile << "Time[ns],Channel1[V],Channel2[V],Channel3[V]" << std::endl;
                    //     for(unsigned int j = 0; j < time[0].size(); j++)
                    //     {
                    //         // auto t = timeCalibrationCorrection.at(i) + 80.0;
                    //         outputFile<<1e9*time[0][j]<<","<<channel[0][j]<<","<<channel[1][j]<<","<<channel[2][j]<<std::endl;
                    //     }
                    //     // Close the CSV file and ROOT file
                    //     outputFile.close();
                    //     std::cout << "Data saved." << std::endl;
                    //     counter[k]++;
                    // }
                    for(unsigned int i = 0; i < channel.size(); i++)
                    {
                        auto t = timeCalibrationCorrection.at(i) + 80.0;
                        // if(i==3) continue;
                        std::string index = std::to_string(i);
                        for(unsigned int j = 0; j < time[0].size(); j++)
                        {
                            // my_histos["wave"+index]->Fill(1e9*time[0][j], channel[i][j]);
                            // my_1d_prof["waveProf"+index+regionsOfIntrest[k].getName()]->Fill(1e9*time[0][j], channel[i][j]);
                            my_histos["wave"+index]->Fill(1e9*time[0][j] - photekTime - t, channel[i][j]);
                            my_1d_prof["waveProf"+index+regionsOfIntrest[k].getName()]->Fill(1e9*time[0][j] - photekTime - t, channel[i][j]);
                        }
                    }


                }
            }
        }
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

