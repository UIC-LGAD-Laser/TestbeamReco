HPK_W9_15_2_121V_85P4attn
HPK_W9_15_5_117V_85P4attn
HPK_W5_17_2_205V_94attn
LeCroy1GHzTrig_W4_17_2_222V_91P0attn
LeCroy_W4_17_2_222V_91P0attn
LeCroy_W2_3_2_198V_99P9attn
LeCroy_W4_17_2_222V_99P9attn
LeCroy_W9_15_2_121V_92P3attn

source setup_el9.sh
./configure
make clean
make -j4
./MyAnalysis -A Analyze -D LeCroy_W9_15_2_121V_92P3attn
python ../macros/PlotTimesVsXY.py -D LeCroy_W9_15_2_121V_92P3attn
python ../macros/PlotAmplitudeVsXY.py -D LeCroy_W9_15_2_121V_92P3attn --zmin 10.0 --zmax 100.0
root -l ../output/LeCroy_W9_15_2_121V_92P3attn/LeCroy_W9_15_2_121V_92P3attn_Analyze.root
timeDiff_channel00->GetMean()
timeDiff_channel01->GetMean()
timeDiff_channel02->GetMean()
.q

make clean
make -j4
./MyAnalysis -A InitialAnalyzer -D LeCroy_W9_15_2_121V_92P3attn
python ../macros/FindDelayCorrections.py -D LeCroy_W9_15_2_121V_92P3attn
./MyAnalysis -A Analyze -D LeCroy_W9_15_2_121V_92P3attn
python ../macros/PlotAmplitudeVsXY.py -D LeCroy_W9_15_2_121V_92P3attn --zmin 10.0 --zmax 100.0
python ../macros/PlotAmplitudeVsX.py -D HPK_W5_17_2_205V_94attn
python ../macros/DoPositionRecoFit.py -D LeCroy_W9_15_2_121V_92P3attn -A --xmax 0.78 --fitOrder 5

make clean
make -j4
./MyAnalysis -A Analyze -D LeCroy_W9_15_2_121V_92P3attn
python ../macros/PlotAmplitudeVsX.py -D LeCroy_W9_15_2_121V_92P3attn
python ../macros/PlotRisetimeVsX.py -D LeCroy_W9_15_2_121V_92P3attn -d True
python ../macros/PlotNoiseVsX.py -D LeCroy_W9_15_2_121V_92P3attn -d True
python ../macros/PlotJitterVsX.py -D LeCroy_W9_15_2_121V_92P3attn
python ../macros/PlotTimeDiffVsY.py -D LeCroy_W9_15_2_121V_92P3attn --xlength 0.8 --ylength 150.0 -d True
python ../macros/Paper_XRes.py -D LeCroy_W9_15_2_121V_92P3attn -x 0.8 -d
python ../macros/PlotSlewrateVsX.py -D LeCroy_W9_15_2_121V_92P3attn -d True
python ../macros/PlotSlewrateOverallVsX.py -D LeCroy_W9_15_2_121V_92P3attn -d True
python ../macros/PlotRisetimeOverallVsX.py -D LeCroy_W9_15_2_121V_92P3attn -d True
python ../macros/PlotNoise.py -D LeCroy_W9_15_2_121V_92P3attn
python ../macros/PlotNoiseOverallVsX.py -D LeCroy_W9_15_2_121V_92P3attn -d True
python ../macros/PlotSignalOverNoiseVsX.py -D LeCroy_W9_15_2_121V_92P3attn -d True
python ../macros/PlotSignalOverNoiseOverallVsX.py -D LeCroy_W9_15_2_121V_92P3attn -d True
python ../macros/FitOverallJitter.py -D LeCroy_W9_15_2_121V_92P3attn
python ../macros/BothTR_and_Jitter_vsX.py -D LeCroy_W9_15_2_121V_92P3attn
python ../macros/PlotTRvsY.py -D LeCroy_W9_15_2_121V_92P3attn
python ../macros/PlotJitterVsY.py -D LeCroy_W9_15_2_121V_92P3attn
python ../macros/BothTR_and_Jitter_vsY.py -D LeCroy_W9_15_2_121V_92P3attn

python ../macros/PlotAmpVsdT.py -D LeCroy_W9_15_2_121V_92P3attn
python ../macros/PlotAmpVsRes.py -D LeCroy_W9_15_2_121V_92P3attn
python ../macros/PlotJitterVsXY.py -D LeCroy_W9_15_2_121V_92P3attn
python ../macros/WavePlot.py -D LeCroy_W9_15_2_121V_92P3attn


make clean
make -j4
python ../macros/Paper_XRes.py -D LeCroy_W9_15_2_121V_92P3attn -x 0.8
python ../macros/FindStripCenters_gausFit.py -D LeCroy_W9_15_2_121V_92P3attn
cd ..
root -l FitHistogramInRange.C
.q
cd test/
