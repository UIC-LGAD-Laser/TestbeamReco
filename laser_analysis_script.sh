cd ../TestbeamReco/test/
source setup.sh
./configure
make clean
make -j4
./MyAnalysis -A Analyze -D Hannah_W4_17_2_223V_92P3attn
python3 ../macros/PlotAmplitudeVsXY.py -D Hannah_W4_17_2_223V_92P3attn --zmin 10.0 --zmax 100.0

root -l ../output/Hannah_W4_17_2_223V_92P3attn/Hannah_W4_17_2_223V_92P3attn_Analyze.root
timeDiff_channel00->GetMean()
timeDiff_channel01->GetMean()
timeDiff_channel02->GetMean()
.q

make clean
make -j4
./MyAnalysis -A InitialAnalyzer -D Hannah_W4_17_2_223V_92P3attn
python3 ../macros/FindDelayCorrections.py -D Hannah_W4_17_2_223V_92P3attn
./MyAnalysis -A Analyze -D Hannah_W4_17_2_223V_92P3attn
python3 ../macros/PlotAmplitudeVsXY.py -D Hannah_W4_17_2_223V_92P3attn --zmin 10.0 --zmax 100.0
python3 ../macros/PlotAmplitudeVsX.py -D Hannah_W4_17_2_223V_92P3attn
python3 ../macros/DoPositionRecoFit.py -D Hannah_W4_17_2_223V_92P3attn -A --xmax 0.70 --fitOrder 5
make clean
make -j4
python3 ../macros/PlotAmplitudeVsX.py -D Hannah_W4_17_2_223V_92P3attn
python3 ../macros/PlotSlewrateVsX.py -D Hannah_W4_17_2_223V_92P3attn -d True
python3 ../macros/PlotSlewrateOverallVsX.py -D Hannah_W4_17_2_223V_92P3attn -d True
python3 ../macros/PlotRisetimeVsX.py -D Hannah_W4_17_2_223V_92P3attn -d True
python3 ../macros/PlotRisetimeOverallVsX.py -D Hannah_W4_17_2_223V_92P3attn -d True
python3 ../macros/PlotNoise.py -D Hannah_W4_17_2_223V_92P3attn
python3 ../macros/PlotNoiseVsX.py -D Hannah_W4_17_2_223V_92P3attn -d True
python3 ../macros/PlotNoiseOverallVsX.py -D Hannah_W4_17_2_223V_92P3attn -d True
python3 ../macros/PlotSignalOverNoiseVsX.py -D Hannah_W4_17_2_223V_92P3attn -d True
python3 ../macros/PlotSignalOverNoiseOverallVsX.py -D Hannah_W4_17_2_223V_92P3attn -d True
python3 ../macros/FitOverallJitter.py -D Hannah_W4_17_2_223V_92P3attn
python3 ../macros/PlotJitterVsX.py -D Hannah_W4_17_2_223V_92P3attn
python3 ../macros/PlotTimeDiffVsY.py -D Hannah_W4_17_2_223V_92P3attn --xlength 0.8 --ylength 150.0 -d True
python3 ../macros/BothTR_and_Jitter_vsX.py -D Hannah_W4_17_2_223V_92P3attn
python3 ../macros/PlotJitterVsY.py -D Hannah_W4_17_2_223V_92P3attn
python3 ../macros/PlotTRvsY.py -D Hannah_W4_17_2_223V_92P3attn
python3 ../macros/BothTR_and_Jitter_vsY.py -D Hannah_W4_17_2_223V_92P3attn
python3 ../macros/PlotAmpVsdT.py -D Hannah_W4_17_2_223V_92P3attn
python3 ../macros/PlotAmpVsRes.py -D Hannah_W4_17_2_223V_92P3attn
python3 ../macros/PlotJitterVsXY.py -D Hannah_W4_17_2_223V_92P3attn


make clean
make -j4
python3 ../macros/Paper_XRes.py -D Hannah_W4_17_2_223V_92P3attn -x 0.8
python3 ../macros/FindStripCenters_gausFit.py -D Hannah_W4_17_2_223V_92P3attn
cd ..
root -l FitHistogramInRange.C
.q
cd test/


./MyAnalysis -A InitialAnalyzer -D Hannah_W4_17_2_223V_92P3attn
python3 ../macros/FindDelayCorrections.py -D Hannah_W4_17_2_223V_92P3attn
./MyAnalysis -A Analyze -D Hannah_W4_17_2_223V_92P3attn
./MyAnalysis -A InitialAnalyzer -D Hannah_W4_17_2_223V_92P3attn
python3 ../macros/FindDelayCorrections.py -D Hannah_W4_17_2_223V_92P3attn
./MyAnalysis -A Analyze -D Hannah_W4_17_2_223V_92P3attn
./MyAnalysis -A InitialAnalyzer -D Hannah_W4_17_2_223V_92P3attn
python3 ../macros/FindDelayCorrections.py -D Hannah_W4_17_2_223V_92P3attn
./MyAnalysis -A Analyze -D Hannah_W4_17_2_223V_92P3attn
./MyAnalysis -A InitialAnalyzer -D Hannah_W4_17_2_223V_92P3attn
python3 ../macros/FindDelayCorrections.py -D Hannah_W4_17_2_223V_92P3attn
./MyAnalysis -A Analyze -D Hannah_W4_17_2_223V_92P3attn
