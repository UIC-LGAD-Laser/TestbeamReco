# HPK_W9_15_2_121V_85P4attn
# HPK_W9_15_5_117V_85P4attn
# HPK_W5_17_2_205V_94attn
# LeCroy1GHzTrig_W4_17_2_222V_91P0attn
# LeCroy_W4_17_2_222V_91P0attn
source setup_el9.sh
./configure

# For calibration
for dir in "LeCroy_W2_3_2_198V_99P9attn" "LeCroy_W4_17_2_222V_99P9attn" "LeCroy_W9_15_2_121V_92P3attn"
do
    make clean
    make -j4
    ./MyAnalysis -A Analyze -D ${dir}
    python ../macros/PlotTimesVsXY.py -D ${dir}
    python ../macros/PlotAmplitudeVsXY.py -D ${dir} --zmin 10.0 --zmax 100.0
    root -l ../output/${dir}/${dir}_Analyze.root
    timeDiff_channel00->GetMean()
    timeDiff_channel01->GetMean()
    timeDiff_channel02->GetMean()
    .q
done

# For Position Reco Fit 
for dir in "LeCroy_W2_3_2_198V_99P9attn" "LeCroy_W4_17_2_222V_99P9attn" "LeCroy_W9_15_2_121V_92P3attn"
do
    make clean
    make -j4
    ./MyAnalysis -A InitialAnalyzer -D ${dir}
    python ../macros/FindDelayCorrections.py -D ${dir}
    ./MyAnalysis -A Analyze -D ${dir}
    python ../macros/PlotAmplitudeVsXY.py -D ${dir} --zmin 10.0 --zmax 100.0
    python ../macros/DoPositionRecoFit.py -D ${dir} -A --xmax 0.78 --fitOrder 5
done

# Macros
for dir in "LeCroy_W2_3_2_198V_99P9attn" "LeCroy_W4_17_2_222V_99P9attn" "LeCroy_W9_15_2_121V_92P3attn"
do
    make clean
    make -j4
    ./MyAnalysis -A Analyze -D ${dir}
    python ../macros/PlotAmplitudeVsX.py -D ${dir}
    python ../macros/PlotRisetimeVsX.py -D ${dir} -d True
    python ../macros/PlotNoiseVsX.py -D ${dir} -d True
    python ../macros/PlotJitterVsX.py -D ${dir}
    python ../macros/PlotTimeDiffVsY.py -D ${dir} --xlength 0.8 --ylength 150.0 -d True
    python ../macros/Paper_XRes.py -D ${dir} -x 0.8 -d
    python ../macros/PlotSlewrateVsX.py -D ${dir} -d True
    python ../macros/PlotSlewrateOverallVsX.py -D ${dir} -d True
    python ../macros/PlotRisetimeOverallVsX.py -D ${dir} -d True
    python ../macros/PlotNoise.py -D ${dir}
    python ../macros/PlotNoiseOverallVsX.py -D ${dir} -d True
    python ../macros/PlotSignalOverNoiseVsX.py -D ${dir} -d True
    python ../macros/PlotSignalOverNoiseOverallVsX.py -D ${dir} -d True
    python ../macros/FitOverallJitter.py -D ${dir}
    python ../macros/BothTR_and_Jitter_vsX.py -D ${dir}
    python ../macros/PlotTRvsY.py -D ${dir}
    python ../macros/PlotJitterVsY.py -D ${dir}
    python ../macros/BothTR_and_Jitter_vsY.py -D ${dir}

    python ../macros/PlotAmpVsdT.py -D ${dir}
    python ../macros/PlotAmpVsRes.py -D ${dir}
    python ../macros/PlotJitterVsXY.py -D ${dir}
    python ../macros/WavePlot.py -D ${dir}


    make clean
    make -j4
    python ../macros/Paper_XRes.py -D ${dir} -x 0.8
    python ../macros/FindStripCenters_gausFit.py -D ${dir}
    cd ..
    root -l FitHistogramInRange.C
    .q
    cd test/
done