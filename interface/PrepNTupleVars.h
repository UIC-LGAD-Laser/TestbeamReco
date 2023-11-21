#ifndef PREPNTUPLEVARS_H
#define PREPNTUPLEVARS_H

#include <numeric>
#include "TestbeamReco/interface/Utility.h"
#include <TRandom3.h>
#include <chrono>

class PrepNTupleVars
{
private:
    std::vector<std::shared_ptr<TProfile2D>> v_timeDiff_coarse_vs_xy_channel;
    float xTr;
	float yTr;
    float TrigTimeFit;
	bool doAmpSmearing_;
    mutable int seed;

    double getSmear(double mean, double sigma) const
    {
        seed+=1;
        double smear = 1.0;
        if(doAmpSmearing_)
        {
            auto rNG = TRandom3(seed);
            smear = rNG.Gaus(mean, sigma);
            smear = (smear < 0.0) ? -1.0*smear : smear;
        }
        return smear;
    }

    void applyAmplitudeCorrection(NTupleReader& tr) const
    {     
        const auto& ampCorrectionFactors = tr.getVar<std::map<int,double>>("amplitudeCorrectionFactor");
        auto& corrAmp = tr.createDerivedVec<double>("corrAmp");
        const auto& amp = tr.getVec<float>("amp");
        
        int counter = 0;
        for(auto thisAmp : amp) 
        {
            corrAmp.emplace_back(getSmear(1.0, 0.2)*thisAmp*ampCorrectionFactors.at(counter));
            counter++;
        }
    }


	void getXYOnSensor(double& xFinal, double& yFinal, double& TrigTime)
		    {

				double xI=xTr, yI=yTr, trigT = TrigTimeFit;
				xFinal = xI;
				yFinal = yI;
				TrigTime = trigT*(1e9);

			}

    void prepNTupleVars(NTupleReader& tr)
    {
        // Create the eventCounter variable to keep track of processed events
        int w = 1;
        tr.registerDerivedVar<int>("eventCounter",w);        
        xTr = tr.getVar<float>("xTr");
		yTr = tr.getVar<float>("yTr");
		TrigTimeFit = tr.getVar<float>("TrigTimeFit");

        auto& x = tr.createDerivedVar<double>("x");
	    auto& y = tr.createDerivedVar<double>("y");
	    auto& TrgTime = tr.createDerivedVar<double>("TrgTime");
		getXYOnSensor(x, y, TrgTime);

		// Correct amp and map raw amplitude
        applyAmplitudeCorrection(tr);
        const auto& amp = tr.getVec<float>("amp");
        const auto& rawAmpLGAD = utility::remapToLGADgeometry(tr, amp, "rawAmpLGAD");
        double totRawAmpLGAD = 0.0;
        for(auto row : rawAmpLGAD){totRawAmpLGAD += std::accumulate(row.begin(), row.end(), 0.0);}
        tr.registerDerivedVar("totRawAmpLGAD", totRawAmpLGAD);

        // Cut to get hits that only go through active sensor
        const auto& sensorEdges = tr.getVar<std::vector<std::vector<double>>>("sensorEdges");
        const auto& sensorEdgesExtra = tr.getVar<std::vector<std::vector<double>>>("sensorEdgesExtra");
        bool hitSensor = sensorEdges[0][0] < x && x < sensorEdges[1][0] &&  sensorEdges[0][1] < y && y < sensorEdges[1][1];
        bool hitSensorExtra = sensorEdgesExtra[0][0] < x && x < sensorEdgesExtra[1][0] &&  sensorEdgesExtra[0][1] < y && y < sensorEdgesExtra[1][1];
        tr.registerDerivedVar("hitSensor", hitSensor);
        tr.registerDerivedVar("hitSensorExtra", hitSensorExtra);

        const auto& sensorEdgesTight = tr.getVar<std::vector<std::vector<double>>>("sensorEdgesTight");

        bool hitSensorTightY = sensorEdgesTight[0][1] < y && y < sensorEdgesTight[1][1];
        tr.registerDerivedVar("hitSensorTightY", hitSensorTightY);
        bool hitSensorTight = sensorEdgesTight[0][0] < x && x < sensorEdgesTight[1][0] &&  hitSensorTightY;
        tr.registerDerivedVar("hitSensorTight", hitSensorTight);


        // Correct the time variable
        const auto& CFD_threshold = tr.getVar<int>("CFD_threshold");
        const auto& LP2 = tr.getVec<float>(Form("LP2_%i",CFD_threshold));
        //const auto& LP2 = tr.getVec<float>("t_peak");
		const auto& LP2_30mV = tr.getVec<float>("LP2_30mV");
        const auto& timeCalibrationCorrection = tr.getVar<std::map<int,double>>("timeCalibrationCorrection");
        auto& corrTime = tr.createDerivedVec<double>("corrTime");
        auto& corrTime_30mV = tr.createDerivedVec<double>("corrTime_30mV");
        auto& corrTimeTracker = tr.createDerivedVec<double>("corrTimeTracker");
    
        const auto& CFD_list = tr.getVar<std::vector<std::string>>("CFD_list");
        std::vector<std::vector<float>> v_LP2_allCFD;
        std::vector<std::vector<double>*> v_corrTime_allCFD;
        for(auto cfd : CFD_list)
        {
            v_LP2_allCFD.emplace_back(tr.getVec<float>("LP2_"+cfd));
            v_corrTime_allCFD.emplace_back(&tr.createDerivedVec<double>("corrTime"+cfd+"Tracker"));
        }

        uint counter = 0;
        for(auto thisTime : LP2)
        {
            auto corr = (thisTime == 0.0) ? 0.0 : timeCalibrationCorrection.at(counter);
            auto tracker_corr = utility::getTrackerTimeCorr<TProfile2D>(x, y, thisTime, counter, v_timeDiff_coarse_vs_xy_channel);

            corrTime.emplace_back(1e9*(thisTime) + corr);
            corrTimeTracker.emplace_back(1e9*(thisTime) - tracker_corr + corr);

            int icfd =0;
            for(auto cfd : CFD_list)
            {
                v_corrTime_allCFD[icfd]->emplace_back(1e9*(v_LP2_allCFD[icfd][counter]) - tracker_corr + corr);
                icfd++;
            }

            counter++;
        }

        counter = 0;
        for(auto thisTime : LP2_30mV)
        {
            auto corr = (thisTime == 0.0) ? 0.0 : timeCalibrationCorrection.at(counter);
            corrTime_30mV.emplace_back(1e9*(thisTime) + corr);
            counter++;
        }

        utility::remapToLGADgeometry(tr, corrTime, "timeLGAD");
        utility::remapToLGADgeometry(tr, corrTime_30mV, "timeLGAD_30mV");
        utility::remapToLGADgeometry(tr, corrTimeTracker, "timeLGADTracker");
        int icfd =0;
        for(auto* corrTimeEachCFD: v_corrTime_allCFD )
        {
            utility::remapToLGADgeometry(tr, *corrTimeEachCFD, "time"+CFD_list[icfd]+"LGADTracker");
            icfd++;
        }

        // Baseline RMS
        const auto& baselineRMS = tr.getVec<float>("baseline_RMS");
        utility::remapToLGADgeometry(tr, baselineRMS, "baselineRMS");

        // Redefine Risetime
        const auto& corrAmp = tr.getVec<double>("corrAmp");
        const auto& risetime = tr.getVec<float>("risetime");
        auto& corrRisetime = tr.createDerivedVec<double>("corrRisetime",risetime.size());
        //auto& SlewRate = tr.createDerivedVec<float>("SlewRate",risetime.size());
        for(unsigned int i = 0; i < risetime.size(); i++)
        {
            corrRisetime[i] = 1e12*abs(0.8*corrAmp[i] / risetime[i]);
            //SlewRate[i] = 1e-9*abs(risetime[i]);
        }
        utility::remapToLGADgeometry(tr, corrRisetime, "risetimeLGAD");
        
        const auto& slewrate = tr.getVec<float>("risetime");
        auto& corrSlewrate = tr.createDerivedVec<double>("corrSlewrate", slewrate.size());
        auto& baselineRMSSlewRateRatio = tr.createDerivedVec<double>("baselineRMSSlewRateRatio",slewrate.size());  
		for(unsigned int i = 0; i < slewrate.size(); i++)
        {
             corrSlewrate[i] = 1e-9*abs(slewrate[i]);
			 baselineRMSSlewRateRatio[i] = 1000*(baselineRMS[i]/corrSlewrate[i]);
        }
        utility::remapToLGADgeometry(tr, corrSlewrate, "slewrateLGAD");
		utility::remapToLGADgeometry(tr, baselineRMSSlewRateRatio, "baselineRMSSlewRateRatioLGAD");
        //utility::remapToLGADgeometry(tr, SlewRate, "slewrateLGAD");
        //Charge, amp/charge ratio
        const auto& integral = tr.getVec<float>("integral");
        auto& charge = tr.createDerivedVec<double>("charge",integral.size());
        auto& AmpChargeRatio = tr.createDerivedVec<double>("AmpChargeRatio",integral.size());
        auto& SlewRateChargeRatio = tr.createDerivedVec<double>("SlewRateChargeRatio",integral.size());
		for(unsigned int i = 0; i < integral.size(); i++)
        {
            charge[i] = -1000*integral[i]*1e9*50/(1.4*4700); //FNAL / UCSC Q ratio is 1.4, using 4700 for both.
            AmpChargeRatio[i] = corrAmp[i]/charge[i];
            SlewRateChargeRatio[i] = corrSlewrate[i]/charge[i];
        }
        utility::remapToLGADgeometry(tr, charge, "chargeLGAD");
        utility::remapToLGADgeometry(tr, AmpChargeRatio, "ampChargeRatioLGAD");
        utility::remapToLGADgeometry(tr, SlewRateChargeRatio, "slewRateChargeRatioLGAD");
    
    }
        

public:

    PrepNTupleVars(const std::vector<std::shared_ptr<TProfile2D>>& histVec) : v_timeDiff_coarse_vs_xy_channel(histVec), doAmpSmearing_(false)
    {
    }

    void operator()(NTupleReader& tr)
    {
        prepNTupleVars(tr);
    }
};

#endif
