HPK_W9_14_2_120V_85P4attn
HPK_W9_15_2_121V_85P4attn
HPK_W9_15_5_117V_85P4attn
HPK_W9_15_5_117V_oldAttn
HPK_W9_15_2_120V_oldAttn
cd ../TestbeamReco/test/
source setup.sh
./configure
make clean
make -j4
./MyAnalysis -A Analyze -D HPK_W9_15_2_120V_oldAttn
python ../macros/PlotAmplitudeVsXY.py -D HPK_W9_15_2_120V_oldAttn --zmin 10.0 --zmax 100.0

root -l ../output/HPK_W9_15_2_120V_oldAttn/HPK_W9_15_2_120V_oldAttn_Analyze.root
timeDiff_channel00->GetMean()
timeDiff_channel01->GetMean()
timeDiff_channel02->GetMean()
.q

make clean
make -j4
./MyAnalysis -A InitialAnalyzer -D HPK_W9_15_2_120V_oldAttn
python ../macros/FindDelayCorrections.py -D HPK_W9_15_2_120V_oldAttn
./MyAnalysis -A Analyze -D HPK_W9_15_2_120V_oldAttn
python ../macros/PlotAmplitudeVsXY.py -D HPK_W9_15_2_120V_oldAttn --zmin 10.0 --zmax 100.0
python ../macros/PlotAmplitudeVsX.py -D HPK_W9_15_2_120V_oldAttn
python ../macros/DoPositionRecoFit.py -D HPK_W9_15_2_120V_oldAttn -A --xmax 0.70 --fitOrder 5
make clean
make -j4
python ../macros/PlotAmplitudeVsX.py -D HPK_W9_15_2_120V_oldAttn
python ../macros/PlotSlewrateVsX.py -D HPK_W9_15_2_120V_oldAttn -d True
python ../macros/PlotSlewrateOverallVsX.py -D HPK_W9_15_2_120V_oldAttn -d True
python ../macros/PlotRisetimeVsX.py -D HPK_W9_15_2_120V_oldAttn -d True
python ../macros/PlotRisetimeOverallVsX.py -D HPK_W9_15_2_120V_oldAttn -d True
python ../macros/PlotNoise.py -D HPK_W9_15_2_120V_oldAttn
python ../macros/PlotNoiseVsX.py -D HPK_W9_15_2_120V_oldAttn -d True
python ../macros/PlotNoiseOverallVsX.py -D HPK_W9_15_2_120V_oldAttn -d True
python ../macros/PlotSignalOverNoiseVsX.py -D HPK_W9_15_2_120V_oldAttn -d True
python ../macros/PlotSignalOverNoiseOverallVsX.py -D HPK_W9_15_2_120V_oldAttn -d True
python ../macros/FitOverallJitter.py -D HPK_W9_15_2_120V_oldAttn
python ../macros/PlotJitterVsX.py -D HPK_W9_15_2_120V_oldAttn
python ../macros/PlotTimeDiffVsY.py -D HPK_W9_15_2_120V_oldAttn --xlength 0.8 --ylength 150.0 -d True
python ../macros/BothTR_and_Jitter_vsX.py -D HPK_W9_15_2_120V_oldAttn
python ../macros/PlotJitterVsY.py -D HPK_W9_15_2_120V_oldAttn
python ../macros/PlotTRvsY.py -D HPK_W9_15_2_120V_oldAttn
python ../macros/BothTR_and_Jitter_vsY.py -D HPK_W9_15_2_120V_oldAttn
python ../macros/PlotAmpVsdT.py -D HPK_W9_15_2_120V_oldAttn
python ../macros/PlotAmpVsRes.py -D HPK_W9_15_2_120V_oldAttn
python ../macros/PlotJitterVsXY.py -D HPK_W9_15_2_120V_oldAttn


make clean
make -j4
python ../macros/Paper_XRes.py -D HPK_W9_15_2_120V_oldAttn -x 0.8
python ../macros/FindStripCenters_gausFit.py -D HPK_W9_15_2_120V_oldAttn
cd ..
root -l FitHistogramInRange.C
.q
cd test/


./MyAnalysis -A InitialAnalyzer -D HPK_W9_15_2_120V_oldAttn
python ../macros/FindDelayCorrections.py -D HPK_W9_15_2_120V_oldAttn
./MyAnalysis -A Analyze -D HPK_W9_15_2_120V_oldAttn
./MyAnalysis -A InitialAnalyzer -D HPK_W9_15_2_120V_oldAttn
python ../macros/FindDelayCorrections.py -D HPK_W9_15_2_120V_oldAttn
./MyAnalysis -A Analyze -D HPK_W9_15_2_120V_oldAttn
./MyAnalysis -A InitialAnalyzer -D HPK_W9_15_2_120V_oldAttn
python ../macros/FindDelayCorrections.py -D HPK_W9_15_2_120V_oldAttn
./MyAnalysis -A Analyze -D HPK_W9_15_2_120V_oldAttn
./MyAnalysis -A InitialAnalyzer -D HPK_W9_15_2_120V_oldAttn
python ../macros/FindDelayCorrections.py -D HPK_W9_15_2_120V_oldAttn
./MyAnalysis -A Analyze -D HPK_W9_15_2_120V_oldAttn
