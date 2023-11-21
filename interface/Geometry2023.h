#ifndef Geometry2023_h
#define Geometry2023_h

#include "TestbeamReco/interface/NTupleReader.h"
#include "TestbeamReco/interface/Geometry.h"
#include "TestbeamReco/interface/Utility.h"


class HPK_W9_14_2_120V_85P4attn_StripsGeometry : public DefaultGeometry
{
public:
    // 
    // Used lecroy scope channels 0-7
    // Scope channel 0-6 was AC channels, and scope channel 7 was the photek
    // 
    // |-----------|             -----
    // | 0 0 0 0 0 |             |777|
    // | 1 1 1 1 1 |             |777|
    // | 2 2 2 2 2 |             -----
    // | 3 3 3 3 3 |
    // | 4 4 4 4 4 |
    // | 5 5 5 5 5 |
    // | 6 6 6 6 6 |
    // |-----------|

    HPK_W9_14_2_120V_85P4attn_StripsGeometry(const int v=0) : voltage(v){}
    const int voltage;
    std::map<int, std::vector<int>> indexToGeometryMap = {{0,{0,0}}, {1,{0,1}}, {2,{0,2}}, {3,{1,0}}};   
    std::vector<std::vector<int>> geometry = {{0,1,2},{3}};
    std::map<int, bool> acLGADChannelMap = {{0,true}, {1,true}, {2,true}, {3,false}};
    std::map<int, double> amplitudeCorrectionFactor = {{0,1.0}, {1,1.0}, {2,1.0},{3,1.0}};
    std::map<int, double> timeCalibrationCorrection = {{0,-43.936493}, {1,-44.108489}, {2,-43.988063}, {3,0.0}};
    // std::map<int, double> timeCalibrationCorrection = {{0,0.0}, {1,0.0}, {2,0.0}, {3,0.0}};
    double stripWidth = 0.100;
    double pitch = 0.500;
    std::vector<double> stripCenterXPosition = {0.5, 0.0, -0.5, 0.0}; // Iter3
    int numLGADchannels = 3;
    int lowGoodStripIndex = 0;
    int highGoodStripIndex = 2;
    double xBinSize = 0.05;
    double yBinSize = 0.1;
    double xmin = -0.80-xBinSize/2; // Sensor's local frame
    double xmax =  0.80+xBinSize/2; // Sensor's local frame
    double ymin = -2.9-yBinSize/2; // Sensor's local frame
    double ymax = 2.9+yBinSize/2; // Sensor's local frame
    double positionRecoMaxPoint = 0.70;
    double noiseAmpThreshold  = 15.0;
    double signalAmpThreshold = 15.0;
    bool enablePositionReconstruction = true;
    int CFD_threshold = 50;
    std::vector<double> positionRecoPar = {0.250000, -0.590290, 1.756152, -24.558585, 120.896939, -216.216957};
    std::vector<std::vector<double>> sensorEdges = {{-0.7, -2.9}, {0.7, 2.9}}; // Sensor's local frame
    std::vector<std::vector<double>> sensorEdgesTight = {{stripCenterXPosition[highGoodStripIndex], -2.9}, {stripCenterXPosition[lowGoodStripIndex], 2.9}}; // Sensor's local frame
    double offset = stripWidth;
    int centerGoodStripIndex = 1;
    double centerStripX = stripCenterXPosition[centerGoodStripIndex];
    double leftGapX = centerStripX - (pitch/2);
	double rightGapX = centerStripX + (pitch/2);
	std::vector<utility::ROI> regionsOfIntrest = {{"nearStripX", centerStripX + offset - stripWidth/2, centerStripX + offset + stripWidth/2, -2.5,2.5}, {"leftGapX", leftGapX - stripWidth/2, leftGapX + stripWidth/2, -2.5,2.5}, {"rightGapX", rightGapX - stripWidth/2, rightGapX + stripWidth/2, -2.5,2.5}};
};

class HPK_W9_15_2_121V_85P4attn_StripsGeometry : public DefaultGeometry
{
public:
    // 
    // Used lecroy scope channels 0-7
    // Scope channel 0-6 was AC channels, and scope channel 7 was the photek
    // 
    // |-----------|             -----
    // | 0 0 0 0 0 |             |777|
    // | 1 1 1 1 1 |             |777|
    // | 2 2 2 2 2 |             -----
    // | 3 3 3 3 3 |
    // | 4 4 4 4 4 |
    // | 5 5 5 5 5 |
    // | 6 6 6 6 6 |
    // |-----------|

    HPK_W9_15_2_121V_85P4attn_StripsGeometry(const int v=0) : voltage(v){}
    const int voltage;
    std::map<int, std::vector<int>> indexToGeometryMap = {{0,{0,0}}, {1,{0,1}}, {2,{0,2}}, {3,{1,0}}};   
    std::vector<std::vector<int>> geometry = {{0,1,2},{3}};
    std::map<int, bool> acLGADChannelMap = {{0,true}, {1,true}, {2,true}, {3,false}};
    std::map<int, double> amplitudeCorrectionFactor = {{0,1.0}, {1,1.0}, {2,1.0},{3,1.0}};
    std::map<int, double> timeCalibrationCorrection = {{0,-44.006910}, {1,-44.173752}, {2,-44.018802}, {3,0.0}};
    // std::map<int, double> timeCalibrationCorrection = {{0,0.0}, {1,0.0}, {2,0.0}, {3,0.0}};
    double stripWidth = 0.050;
    double pitch = 0.500;
    std::vector<double> stripCenterXPosition = {0.5, 0.0, -0.5, 0.0}; // Iter3
    int numLGADchannels = 3;
    int lowGoodStripIndex = 0;
    int highGoodStripIndex = 2;
    double xBinSize = 0.05;
    double yBinSize = 0.1;
    double xmin = -0.80-xBinSize/2; // Sensor's local frame
    double xmax =  0.80+xBinSize/2; // Sensor's local frame
    double ymin = -2.9-yBinSize/2; // Sensor's local frame
    double ymax = 2.9+yBinSize/2; // Sensor's local frame
    double positionRecoMaxPoint = 0.78;
    double noiseAmpThreshold  = 15.0;
    double signalAmpThreshold = 15.0;
    bool enablePositionReconstruction = true;
    int CFD_threshold = 50;
    std::vector<double> positionRecoPar = {0.250000, -0.580028, 0.215066, -0.836168, -9.005392, 17.517882};
    std::vector<std::vector<double>> sensorEdges = {{-0.7, -2.9}, {0.7, 2.9}}; // Sensor's local frame
    std::vector<std::vector<double>> sensorEdgesTight = {{stripCenterXPosition[highGoodStripIndex], -2.9}, {stripCenterXPosition[lowGoodStripIndex], 2.9}}; // Sensor's local frame
    double offset = stripWidth;
    int centerGoodStripIndex = 1;
    double centerStripX = stripCenterXPosition[centerGoodStripIndex];
    double leftGapX = centerStripX - (pitch/2);
	double rightGapX = centerStripX + (pitch/2);
	std::vector<utility::ROI> regionsOfIntrest = {{"nearStripX", centerStripX + offset - stripWidth/2, centerStripX + offset + stripWidth/2, -2.5,2.5}, {"leftGapX", leftGapX - stripWidth/2, leftGapX + stripWidth/2, -2.5,2.5}, {"rightGapX", rightGapX - stripWidth/2, rightGapX + stripWidth/2, -2.5,2.5}};
};

class HPK_W9_15_5_117V_85P4attn_StripsGeometry : public DefaultGeometry
{
public:
    // 
    // Used lecroy scope channels 0-7
    // Scope channel 0-6 was AC channels, and scope channel 7 was the photek
    // 
    // |-----------|             -----
    // | 0 0 0 0 0 |             |777|
    // | 1 1 1 1 1 |             |777|
    // | 2 2 2 2 2 |             -----
    // | 3 3 3 3 3 |
    // | 4 4 4 4 4 |
    // | 5 5 5 5 5 |
    // | 6 6 6 6 6 |
    // |-----------|

    HPK_W9_15_5_117V_85P4attn_StripsGeometry(const int v=0) : voltage(v){}
    const int voltage;
    std::map<int, std::vector<int>> indexToGeometryMap = {{0,{0,0}}, {1,{0,1}}, {2,{0,2}}, {3,{1,0}}};   
    std::vector<std::vector<int>> geometry = {{0,1,2},{3}};
    std::map<int, bool> acLGADChannelMap = {{0,true}, {1,true}, {2,true}, {3,false}};
    std::map<int, double> amplitudeCorrectionFactor = {{0,1.0}, {1,1.0}, {2,1.0},{3,1.0}};
    std::map<int, double> timeCalibrationCorrection = {{0,-44.042180}, {1,-44.247212}, {2,-44.098899}, {3,0.0}};
    // std::map<int, double> timeCalibrationCorrection = {{0,0.0}, {1,0.0}, {2,0.0}, {3,0.0}};
    double stripWidth = 0.050;
    double pitch = 0.500;
    std::vector<double> stripCenterXPosition = {0.5, 0.0, -0.5, 0.0}; // Iter3
    int numLGADchannels = 3;
    int lowGoodStripIndex = 0;
    int highGoodStripIndex = 2;
    double xBinSize = 0.05;
    double yBinSize = 0.1;
    double xmin = -0.80-xBinSize/2; // Sensor's local frame
    double xmax =  0.80+xBinSize/2; // Sensor's local frame
    double ymin = -10.7-yBinSize/2; // Sensor's local frame
    double ymax = 10.7+yBinSize/2; // Sensor's local frame
    double positionRecoMaxPoint = 0.59;
    double noiseAmpThreshold  = 15.0;
    double signalAmpThreshold = 15.0;
    bool enablePositionReconstruction = true;
    int CFD_threshold = 50;
    std::vector<double> positionRecoPar = {0.250000, -0.601897, -13.956148, 704.546989, -13725.932674, 79100.081583};
    std::vector<std::vector<double>> sensorEdges = {{-0.7, -10.7}, {0.7, 10.7}}; // Sensor's local frame
    std::vector<std::vector<double>> sensorEdgesTight = {{stripCenterXPosition[highGoodStripIndex], -10.5}, {stripCenterXPosition[lowGoodStripIndex], 10.5}}; // Sensor's local frame
    int centerGoodStripIndex = 1;
    double leftHighGainX = stripCenterXPosition[centerGoodStripIndex] - (stripWidth/2);
    double rightHighGainX = stripCenterXPosition[centerGoodStripIndex] + (stripWidth/2);
    double leftLowGainX = stripCenterXPosition[centerGoodStripIndex] - (pitch/2) - (stripWidth/2);
    double rightLowGainX = stripCenterXPosition[centerGoodStripIndex] - (pitch/2) + (stripWidth/2);
    std::vector<utility::ROI> regionsOfIntrest = {{"highGain", leftHighGainX, rightHighGainX, -10.5, 10.5}, {"lowGain", leftLowGainX, rightLowGainX, -10.5, 10.5}};
};

class HPK_W9_15_5_117V_oldAttn_StripsGeometry : public DefaultGeometry
{
public:
    // 
    // Used lecroy scope channels 0-7
    // Scope channel 0-6 was AC channels, and scope channel 7 was the photek
    // 
    // |-----------|             -----
    // | 0 0 0 0 0 |             |777|
    // | 1 1 1 1 1 |             |777|
    // | 2 2 2 2 2 |             -----
    // | 3 3 3 3 3 |
    // | 4 4 4 4 4 |
    // | 5 5 5 5 5 |
    // | 6 6 6 6 6 |
    // |-----------|

    HPK_W9_15_5_117V_oldAttn_StripsGeometry(const int v=0) : voltage(v){}
    const int voltage;
    std::map<int, std::vector<int>> indexToGeometryMap = {{0,{0,0}}, {1,{0,1}}, {2,{0,2}}, {3,{1,0}}};   
    std::vector<std::vector<int>> geometry = {{0,1,2},{3}};
    std::map<int, bool> acLGADChannelMap = {{0,true}, {1,true}, {2,true}, {3,false}};
    std::map<int, double> amplitudeCorrectionFactor = {{0,1.0}, {1,1.0}, {2,1.0},{3,1.0}};
    std::map<int, double> timeCalibrationCorrection = {{0,-45.999776}, {1,-46.245778}, {2,-45.356668}, {3,0.0}};
    // std::map<int, double> timeCalibrationCorrection = {{0,0.0}, {1,0.0}, {2,0.0}, {3,0.0}};
    double stripWidth = 0.050;
    double pitch = 0.500;
    std::vector<double> stripCenterXPosition = {0.5, 0.0, -0.5, 0.0}; // Iter3
    int numLGADchannels = 3;
    int lowGoodStripIndex = 0;
    int highGoodStripIndex = 2;
    double xBinSize = 0.05;
    double yBinSize = 0.1;
    double xmin = -0.80-xBinSize/2; // Sensor's local frame
    double xmax =  0.80+xBinSize/2; // Sensor's local frame
    double ymin = -10.7-yBinSize/2; // Sensor's local frame
    double ymax = 10.7+yBinSize/2; // Sensor's local frame
    double positionRecoMaxPoint = 0.85;
    double noiseAmpThreshold  = 15.0;
    double signalAmpThreshold = 15.0;
    bool enablePositionReconstruction = true;
    int CFD_threshold = 50;
    std::vector<double> positionRecoPar = {0.250000, -0.598948, -0.279959, 5.008686, -36.920418, 72.945824};
    std::vector<std::vector<double>> sensorEdges = {{-0.7, -10.7}, {0.7, 10.7}}; // Sensor's local frame
    std::vector<std::vector<double>> sensorEdgesTight = {{stripCenterXPosition[highGoodStripIndex], -10.5}, {stripCenterXPosition[lowGoodStripIndex], 10.5}}; // Sensor's local frame
    int centerGoodStripIndex = 1;
    double leftHighGainX = stripCenterXPosition[centerGoodStripIndex] - (stripWidth/2);
    double rightHighGainX = stripCenterXPosition[centerGoodStripIndex] + (stripWidth/2);
    double leftLowGainX = stripCenterXPosition[centerGoodStripIndex] - (pitch/2) - (stripWidth/2);
    double rightLowGainX = stripCenterXPosition[centerGoodStripIndex] - (pitch/2) + (stripWidth/2);
    std::vector<utility::ROI> regionsOfIntrest = {{"highGain", leftHighGainX, rightHighGainX, -10.5, 10.5}, {"lowGain", leftLowGainX, rightLowGainX, -10.5, 10.5}};
};

class HPK_W9_15_2_120V_oldAttn_StripsGeometry : public DefaultGeometry
{
public:
    // 
    // Used lecroy scope channels 0-7
    // Scope channel 0-6 was AC channels, and scope channel 7 was the photek
    // 
    // |-----------|             -----
    // | 0 0 0 0 0 |             |777|
    // | 1 1 1 1 1 |             |777|
    // | 2 2 2 2 2 |             -----
    // | 3 3 3 3 3 |
    // | 4 4 4 4 4 |
    // | 5 5 5 5 5 |
    // | 6 6 6 6 6 |
    // |-----------|

    HPK_W9_15_2_120V_oldAttn_StripsGeometry(const int v=0) : voltage(v){}
    const int voltage;
    std::map<int, std::vector<int>> indexToGeometryMap = {{0,{0,0}}, {1,{0,1}}, {2,{0,2}}, {3,{1,0}}};
    std::vector<std::vector<int>> geometry = {{0,1,2},{3}};
    std::map<int, bool> acLGADChannelMap = {{0,true}, {1,true}, {2,true}, {3,false}};
    std::map<int, double> amplitudeCorrectionFactor = {{0,1.0}, {1,1.0}, {2,1.0},{3,1.0}};
    std::map<int, double> timeCalibrationCorrection = {{0,-45.834268}, {1,-46.032814}, {2,-45.179717}, {3,0.0}};
    // std::map<int, double> timeCalibrationCorrection = {{0,0.0}, {1,0.0}, {2,0.0}, {3,0.0}};
    double stripWidth = 0.050;
    double pitch = 0.500;
    std::vector<double> stripCenterXPosition = {0.5, 0.0, -0.5, 0.0}; // Iter3
    int numLGADchannels = 3;
    int lowGoodStripIndex = 0;
    int highGoodStripIndex = 2;
    double xBinSize = 0.025;
    double yBinSize = 0.1;
    double xmin = -0.80-xBinSize/2; // Sensor's local frame
    double xmax =  0.80+xBinSize/2; // Sensor's local frame
    double ymin = -4.9-yBinSize/2; // Sensor's local frame
    double ymax = 4.9+yBinSize/2; // Sensor's local frame
    double positionRecoMaxPoint = 0.86;
    double noiseAmpThreshold  = 15.0;
    double signalAmpThreshold = 15.0;
    bool enablePositionReconstruction = true;
    int CFD_threshold = 50;
    std::vector<double> positionRecoPar = {0.250000, -0.496925, -0.956245, 8.029132, -29.982933, 36.477270};
    std::vector<std::vector<double>> sensorEdges = {{-0.7, -4.9}, {0.7, 4.9}}; // Sensor's local frame
    std::vector<std::vector<double>> sensorEdgesTight = {{stripCenterXPosition[highGoodStripIndex], -4.8}, {stripCenterXPosition[lowGoodStripIndex], 4.8}}; // Sensor's local frame
    int centerGoodStripIndex = 1;
    double leftHighGainX = stripCenterXPosition[centerGoodStripIndex] - (stripWidth/2);
    double rightHighGainX = stripCenterXPosition[centerGoodStripIndex] + (stripWidth/2);
    double leftLowGainX = stripCenterXPosition[centerGoodStripIndex] - (pitch/2) - (stripWidth/2);
    double rightLowGainX = stripCenterXPosition[centerGoodStripIndex] - (pitch/2) + (stripWidth/2);
    std::vector<utility::ROI> regionsOfIntrest = {{"highGain", leftHighGainX, rightHighGainX, -4.8, 4.8}, {"lowGain", leftLowGainX, rightLowGainX, -4.8, 4.8}};
};

class HPK_W4_17_2_220V_86attn_StripsGeometry : public DefaultGeometry
{
public:
    // 
    // Used lecroy scope channels 0-7
    // Scope channel 0-6 was AC channels, and scope channel 7 was the photek
    // 
    // |-----------|             -----
    // | 0 0 0 0 0 |             |777|
    // | 1 1 1 1 1 |             |777|
    // | 2 2 2 2 2 |             -----
    // | 3 3 3 3 3 |
    // | 4 4 4 4 4 |
    // | 5 5 5 5 5 |
    // | 6 6 6 6 6 |
    // |-----------|

    HPK_W4_17_2_220V_86attn_StripsGeometry(const int v=0) : voltage(v){}
    const int voltage;
    std::map<int, std::vector<int>> indexToGeometryMap = {{0,{0,0}}, {1,{0,1}}, {2,{0,2}}, {3,{1,0}}};   
    std::vector<std::vector<int>> geometry = {{0,1,2},{3}};
    std::map<int, bool> acLGADChannelMap = {{0,true}, {1,true}, {2,true}, {3,false}};
    std::map<int, double> amplitudeCorrectionFactor = {{0,1.0}, {1,1.0}, {2,1.0},{3,1.0}};
    std::map<int, double> timeCalibrationCorrection = {{0,-44.383082}, {1,-44.482794}, {2,-43.732550}, {3,0.0}};
    // std::map<int, double> timeCalibrationCorrection = {{0,0.0}, {1,0.0}, {2,0.0}, {3,0.0}};
    double stripWidth = 0.050;
    double pitch = 0.500;
    std::vector<double> stripCenterXPosition = {0.5, 0.0, -0.5, 0.0}; // Iter3
    int numLGADchannels = 3;
    int lowGoodStripIndex = 0;
    int highGoodStripIndex = 2;
    double xBinSize = 0.05;
    double yBinSize = 0.1;
    double xmin = -0.80-stripWidth/2; // Sensor's local frame
    double xmax =  0.80+stripWidth/2; // Sensor's local frame
    double ymin = -2.9-stripWidth/2; // Sensor's local frame
    double ymax = 2.9+stripWidth/2; // Sensor's local frame
    double positionRecoMaxPoint = 0.67;
    double noiseAmpThreshold  = 15.0;
    double signalAmpThreshold = 15.0;
    bool enablePositionReconstruction = true;
    int CFD_threshold = 50;
    std::vector<double> positionRecoPar = {0.250000, -1.198367, -4.931577, 121.461067, -1127.942159, 3443.097448};
    std::vector<std::vector<double>> sensorEdges = {{-0.7, -2.9}, {0.7, 2.9}}; // Sensor's local frame
    std::vector<std::vector<double>> sensorEdgesTight = {{stripCenterXPosition[highGoodStripIndex], -2.9}, {stripCenterXPosition[lowGoodStripIndex], 2.9}}; // Sensor's local frame
    int centerGoodStripIndex = 1;
    double leftHighGainX = stripCenterXPosition[centerGoodStripIndex] - (stripWidth/2);
    double rightHighGainX = stripCenterXPosition[centerGoodStripIndex] + (stripWidth/2);
    double leftLowGainX = stripCenterXPosition[centerGoodStripIndex] - (pitch/2) - (stripWidth/2);
    double rightLowGainX = stripCenterXPosition[centerGoodStripIndex] - (pitch/2) + (stripWidth/2);
    std::vector<utility::ROI> regionsOfIntrest = {{"highGain", leftHighGainX, rightHighGainX, -2.9, 2.9}, {"lowGain", leftLowGainX, rightLowGainX, -2.9, 2.9}};
};

class HPK_W4_17_2_223V_92P3attn_StripsGeometry : public DefaultGeometry
{
public:
    // 
    // Used lecroy scope channels 0-7
    // Scope channel 0-6 was AC channels, and scope channel 7 was the photek
    // 
    // |-----------|             -----
    // | 0 0 0 0 0 |             |777|
    // | 1 1 1 1 1 |             |777|
    // | 2 2 2 2 2 |             -----
    // | 3 3 3 3 3 |
    // | 4 4 4 4 4 |
    // | 5 5 5 5 5 |
    // | 6 6 6 6 6 |
    // |-----------|

    HPK_W4_17_2_223V_92P3attn_StripsGeometry(const int v=0) : voltage(v){}
    const int voltage;
    std::map<int, std::vector<int>> indexToGeometryMap = {{0,{0,0}}, {1,{0,1}}, {2,{0,2}}, {3,{1,0}}};   
    std::vector<std::vector<int>> geometry = {{0,1,2},{3}};
    std::map<int, bool> acLGADChannelMap = {{0,true}, {1,true}, {2,true}, {3,false}};
    std::map<int, double> amplitudeCorrectionFactor = {{0,1.0}, {1,1.0}, {2,1.0},{3,1.0}};
    std::map<int, double> timeCalibrationCorrection = {{0,-44.407430}, {1,-44.516147}, {2,-43.758894}, {3,0.0}};
    // std::map<int, double> timeCalibrationCorrection = {{0,0.0}, {1,0.0}, {2,0.0}, {3,0.0}};
    double stripWidth = 0.050;
    double pitch = 0.500;
    std::vector<double> stripCenterXPosition = {0.5, 0.0, -0.5, 0.0}; // Iter3
    int numLGADchannels = 3;
    int lowGoodStripIndex = 0;
    int highGoodStripIndex = 2;
    double xBinSize = 0.05;
    double yBinSize = 0.1;
    double xmin = -0.80-stripWidth/2; // Sensor's local frame
    double xmax =  0.80+stripWidth/2; // Sensor's local frame
    double ymin = -2.9-stripWidth/2; // Sensor's local frame
    double ymax = 2.9+stripWidth/2; // Sensor's local frame
    double positionRecoMaxPoint = 0.66;
    double noiseAmpThreshold  = 15.0;
    double signalAmpThreshold = 15.0;
    bool enablePositionReconstruction = true;
    int CFD_threshold = 50;
    std::vector<double> positionRecoPar = {0.250000, -1.282863, -2.157824, 74.391135, -836.971302, 2942.375710};
    std::vector<std::vector<double>> sensorEdges = {{-0.7, -2.9}, {0.7, 2.9}}; // Sensor's local frame
    std::vector<std::vector<double>> sensorEdgesTight = {{stripCenterXPosition[highGoodStripIndex], -2.9}, {stripCenterXPosition[lowGoodStripIndex], 2.9}}; // Sensor's local frame
    double offset = stripWidth;
    int centerGoodStripIndex = 1;
    double centerStripX = stripCenterXPosition[centerGoodStripIndex];
    double leftGapX = centerStripX - (pitch/2);
	double rightGapX = centerStripX + (pitch/2);
	std::vector<utility::ROI> regionsOfIntrest = {{"nearStripX", centerStripX + offset - stripWidth/2, centerStripX + offset + stripWidth/2, -2.5,2.5}, {"leftGapX", leftGapX - stripWidth/2, leftGapX + stripWidth/2, -2.5,2.5}, {"rightGapX", rightGapX - stripWidth/2, rightGapX + stripWidth/2, -2.5,2.5}};
};


class HPK_W4_17_2_NewCable_223V_92P3attn_StripsGeometry : public DefaultGeometry
{
public:
    // 
    // Used lecroy scope channels 0-7
    // Scope channel 0-6 was AC channels, and scope channel 7 was the photek
    // 
    // |-----------|             -----
    // | 0 0 0 0 0 |             |777|
    // | 1 1 1 1 1 |             |777|
    // | 2 2 2 2 2 |             -----
    // | 3 3 3 3 3 |
    // | 4 4 4 4 4 |
    // | 5 5 5 5 5 |
    // | 6 6 6 6 6 |
    // |-----------|

    HPK_W4_17_2_NewCable_223V_92P3attn_StripsGeometry(const int v=0) : voltage(v){}
    const int voltage;
    std::map<int, std::vector<int>> indexToGeometryMap = {{0,{0,0}}, {1,{0,1}}, {2,{0,2}}, {3,{1,0}}};   
    std::vector<std::vector<int>> geometry = {{0,1,2},{3}};
    std::map<int, bool> acLGADChannelMap = {{0,true}, {1,true}, {2,true}, {3,false}};
    std::map<int, double> amplitudeCorrectionFactor = {{0,1.0}, {1,1.0}, {2,1.0},{3,1.0}};
    std::map<int, double> timeCalibrationCorrection = {{0,-44.200125}, {1,-44.293281}, {2,-44.224748}, {3,0.0}};
    // std::map<int, double> timeCalibrationCorrection = {{0,0.0}, {1,0.0}, {2,0.0}, {3,0.0}};
    double stripWidth = 0.050;
    double pitch = 0.500;
    std::vector<double> stripCenterXPosition = {0.5, 0.0, -0.5, 0.0}; // Iter3
    int numLGADchannels = 3;
    int lowGoodStripIndex = 0;
    int highGoodStripIndex = 2;
    double xBinSize = 0.05;
    double yBinSize = 0.1;
    double xmin = -0.80-stripWidth/2; // Sensor's local frame
    double xmax =  0.80+stripWidth/2; // Sensor's local frame
    double ymin = -2.9-stripWidth/2; // Sensor's local frame
    double ymax = 2.9+stripWidth/2; // Sensor's local frame
    double positionRecoMaxPoint = 0.67;
    double noiseAmpThreshold  = 15.0;
    double signalAmpThreshold = 15.0;
    bool enablePositionReconstruction = true;
    int CFD_threshold = 50;
    std::vector<double> positionRecoPar = {0.250000, -1.251756, -3.290870, 88.492451, -897.696590, 2995.524175};
    std::vector<std::vector<double>> sensorEdges = {{-0.7, -2.9}, {0.7, 2.9}}; // Sensor's local frame
    std::vector<std::vector<double>> sensorEdgesTight = {{stripCenterXPosition[highGoodStripIndex], -2.9}, {stripCenterXPosition[lowGoodStripIndex], 2.9}}; // Sensor's local frame
    double offset = stripWidth;
    int centerGoodStripIndex = 1;
    double centerStripX = stripCenterXPosition[centerGoodStripIndex];
    double leftGapX = centerStripX - (pitch/2);
	double rightGapX = centerStripX + (pitch/2);
	std::vector<utility::ROI> regionsOfIntrest = {{"nearStripX", centerStripX + offset - stripWidth/2, centerStripX + offset + stripWidth/2, -2.5,2.5}, {"leftGapX", leftGapX - stripWidth/2, leftGapX + stripWidth/2, -2.5,2.5}, {"rightGapX", rightGapX - stripWidth/2, rightGapX + stripWidth/2, -2.5,2.5}};
};


class HPK_W4_17_2_224V_94attn_StripsGeometry : public DefaultGeometry
{
public:
    // 
    // Used lecroy scope channels 0-7
    // Scope channel 0-6 was AC channels, and scope channel 7 was the photek
    // 
    // |-----------|             -----
    // | 0 0 0 0 0 |             |777|
    // | 1 1 1 1 1 |             |777|
    // | 2 2 2 2 2 |             -----
    // | 3 3 3 3 3 |
    // | 4 4 4 4 4 |
    // | 5 5 5 5 5 |
    // | 6 6 6 6 6 |
    // |-----------|

    HPK_W4_17_2_224V_94attn_StripsGeometry(const int v=0) : voltage(v){}
    const int voltage;
    std::map<int, std::vector<int>> indexToGeometryMap = {{0,{0,0}}, {1,{0,1}}, {2,{0,2}}, {3,{1,0}}};   
    std::vector<std::vector<int>> geometry = {{0,1,2},{3}};
    std::map<int, bool> acLGADChannelMap = {{0,true}, {1,true}, {2,true}, {3,false}};
    std::map<int, double> amplitudeCorrectionFactor = {{0,1.0}, {1,1.0}, {2,1.0},{3,1.0}};
    std::map<int, double> timeCalibrationCorrection = {{0,-44.427605}, {1,-44.532944}, {2,-43.775416}, {3,0.0}};
    // std::map<int, double> timeCalibrationCorrection = {{0,0.0}, {1,0.0}, {2,0.0}, {3,0.0}};
    double stripWidth = 0.050;
    double pitch = 0.500;
    std::vector<double> stripCenterXPosition = {0.5, 0.0, -0.5, 0.0}; // Iter3
    int numLGADchannels = 3;
    int lowGoodStripIndex = 0;
    int highGoodStripIndex = 2;
    double xBinSize = 0.05;
    double yBinSize = 0.1;
    double xmin = -0.80-stripWidth/2; // Sensor's local frame
    double xmax =  0.80+stripWidth/2; // Sensor's local frame
    double ymin = -2.9-stripWidth/2; // Sensor's local frame
    double ymax = 2.9+stripWidth/2; // Sensor's local frame
    double positionRecoMaxPoint = 0.66;
    double noiseAmpThreshold  = 15.0;
    double signalAmpThreshold = 15.0;
    bool enablePositionReconstruction = true;
    int CFD_threshold = 50;
    std::vector<double> positionRecoPar = {0.250000, -1.282863, -2.157824, 74.391135, -836.971302, 2942.375710};
    std::vector<std::vector<double>> sensorEdges = {{-0.7, -2.9}, {0.7, 2.9}}; // Sensor's local frame
    std::vector<std::vector<double>> sensorEdgesTight = {{stripCenterXPosition[highGoodStripIndex], -2.9}, {stripCenterXPosition[lowGoodStripIndex], 2.9}}; // Sensor's local frame
    double offset = stripWidth;
    int centerGoodStripIndex = 1;
    double centerStripX = stripCenterXPosition[centerGoodStripIndex];
    double leftGapX = centerStripX - (pitch/2);
	double rightGapX = centerStripX + (pitch/2);
	std::vector<utility::ROI> regionsOfIntrest = {{"nearStripX", centerStripX + offset - stripWidth/2, centerStripX + offset + stripWidth/2, -2.5,2.5}, {"leftGapX", leftGapX - stripWidth/2, leftGapX + stripWidth/2, -2.5,2.5}, {"rightGapX", rightGapX - stripWidth/2, rightGapX + stripWidth/2, -2.5,2.5}};
};


//done
class HPK_W5_17_2_201V_91P5attn_StripsGeometry : public DefaultGeometry
{
public:
    // 
    // Used lecroy scope channels 0-7
    // Scope channel 0-6 was AC channels, and scope channel 7 was the photek
    // 
    // |-----------|             -----
    // | 0 0 0 0 0 |             |777|
    // | 1 1 1 1 1 |             |777|
    // | 2 2 2 2 2 |             -----
    // | 3 3 3 3 3 |
    // | 4 4 4 4 4 |
    // | 5 5 5 5 5 |
    // | 6 6 6 6 6 |
    // |-----------|

    HPK_W5_17_2_201V_91P5attn_StripsGeometry(const int v=0) : voltage(v){}
    const int voltage;
    std::map<int, std::vector<int>> indexToGeometryMap = {{0,{0,0}}, {1,{0,1}}, {2,{0,2}}, {3,{1,0}}};   
    std::vector<std::vector<int>> geometry = {{0,1,2},{3}};
    std::map<int, bool> acLGADChannelMap = {{0,true}, {1,true}, {2,true}, {3,false}};
    std::map<int, double> amplitudeCorrectionFactor = {{0,1.0}, {1,1.0}, {2,1.0}, {3,1.0}};
    std::map<int, double> timeCalibrationCorrection = {{0,-46.069359}, {1,-46.233257}, {2,-45.406565}, {3,0.0}};
    // std::map<int, double> timeCalibrationCorrection = {{0,0.0}, {1,0.0}, {2,0.0}, {3,0.0}};
    double stripWidth = 0.050;
    double pitch = 0.500;
    std::vector<double> stripCenterXPosition = {0.5, 0.0, -0.5, 0.0}; // Iter3
    int numLGADchannels = 3;
    int lowGoodStripIndex = 0;
    int highGoodStripIndex = 2;
    double xBinSize = 0.05;
    double yBinSize = 0.1;
    double xmin = -0.80-stripWidth/2; // Sensor's local frame
    double xmax =  0.80+stripWidth/2; // Sensor's local frame
    double ymin = -2.9-stripWidth/2; // Sensor's local frame
    double ymax = 2.9+stripWidth/2; // Sensor's local frame
    double positionRecoMaxPoint = 0.8;
    double noiseAmpThreshold  = 15.0;
    double signalAmpThreshold = 15.0;
    bool enablePositionReconstruction = true;
    int CFD_threshold = 50;
    std::vector<double> positionRecoPar = {0.250000, -0.654949, 0.136302, -2.405088, 13.563573, -26.926092};
    std::vector<std::vector<double>> sensorEdges = {{-0.7, -2.9}, {0.7, 2.9}};//{{-0.7, -4.5}, {0.7, 4.5}}; // Sensor's local frame
    std::vector<std::vector<double>> sensorEdgesTight = {{stripCenterXPosition[highGoodStripIndex], -2.9}, {stripCenterXPosition[lowGoodStripIndex], 2.9}}; // Sensor's local frame
    int centerGoodStripIndex = 1;
    double leftHighGainX = stripCenterXPosition[centerGoodStripIndex] - (stripWidth/2);
    double rightHighGainX = stripCenterXPosition[centerGoodStripIndex] + (stripWidth/2);
    double leftLowGainX = stripCenterXPosition[centerGoodStripIndex] - (pitch/2) - (stripWidth/2);
    double rightLowGainX = stripCenterXPosition[centerGoodStripIndex] - (pitch/2) + (stripWidth/2);
    std::vector<utility::ROI> regionsOfIntrest = {{"highGain", leftHighGainX, rightHighGainX, -2.9, 2.9}, {"lowGain", leftLowGainX, rightLowGainX, -2.9, 2.9}};
};

//done
class HPK_W5_17_2_201V_92attn_StripsGeometry : public DefaultGeometry
{
public:
    // 
    // Used lecroy scope channels 0-7
    // Scope channel 0-6 was AC channels, and scope channel 7 was the photek
    // 
    // |-----------|             -----
    // | 0 0 0 0 0 |             |777|
    // | 1 1 1 1 1 |             |777|
    // | 2 2 2 2 2 |             -----
    // | 3 3 3 3 3 |
    // | 4 4 4 4 4 |
    // | 5 5 5 5 5 |
    // | 6 6 6 6 6 |
    // |-----------|

    HPK_W5_17_2_201V_92attn_StripsGeometry(const int v=0) : voltage(v){}
    const int voltage;
    std::map<int, std::vector<int>> indexToGeometryMap = {{0,{0,0}}, {1,{0,1}}, {2,{0,2}}, {3,{1,0}}};   
    std::vector<std::vector<int>> geometry = {{0,1,2},{3}};
    std::map<int, bool> acLGADChannelMap = {{0,true}, {1,true}, {2,true}, {3,false}};
    std::map<int, double> amplitudeCorrectionFactor = {{0,1.0}, {1,1.0}, {2,1.0}, {3,1.0}};
    std::map<int, double> timeCalibrationCorrection = {{0,-46.045368}, {1,-46.219813}, {2,-45.384286}, {3,0.0}};
    // std::map<int, double> timeCalibrationCorrection = {{0,0.0}, {1,0.0}, {2,0.0}, {3,0.0}};
    double stripWidth = 0.050;
    double pitch = 0.500;
    std::vector<double> stripCenterXPosition = {0.5, 0.0, -0.5, 0.0}; // Iter3
    int numLGADchannels = 3;
    int lowGoodStripIndex = 0;
    int highGoodStripIndex = 2;
    double xBinSize = 0.05;
    double yBinSize = 0.1;
    double xmin = -0.80-stripWidth/2; // Sensor's local frame
    double xmax =  0.80+stripWidth/2; // Sensor's local frame
    double ymin = -2.9-stripWidth/2; // Sensor's local frame
    double ymax = 2.9+stripWidth/2; // Sensor's local frame
    double positionRecoMaxPoint = 0.8;
    double noiseAmpThreshold  = 15.0;
    double signalAmpThreshold = 15.0;
    bool enablePositionReconstruction = true;
    int CFD_threshold = 50;
    std::vector<double> positionRecoPar = {0.250000, -0.656372, 0.154696, -1.991036, 10.155932, -20.745642};
    std::vector<std::vector<double>> sensorEdges = {{-0.7, -2.9}, {0.7, 2.9}};//{{-0.7, -4.5}, {0.7, 4.5}}; // Sensor's local frame
    std::vector<std::vector<double>> sensorEdgesTight = {{stripCenterXPosition[highGoodStripIndex], -2.9}, {stripCenterXPosition[lowGoodStripIndex], 2.9}}; // Sensor's local frame
    int centerGoodStripIndex = 1;
    double leftHighGainX = stripCenterXPosition[centerGoodStripIndex] - (stripWidth/2);
    double rightHighGainX = stripCenterXPosition[centerGoodStripIndex] + (stripWidth/2);
    double leftLowGainX = stripCenterXPosition[centerGoodStripIndex] - (pitch/2) - (stripWidth/2);
    double rightLowGainX = stripCenterXPosition[centerGoodStripIndex] - (pitch/2) + (stripWidth/2);
    std::vector<utility::ROI> regionsOfIntrest = {{"highGain", leftHighGainX, rightHighGainX, -2.9, 2.9}, {"lowGain", leftLowGainX, rightLowGainX, -2.9, 2.9}};
};

//done
class HPK_W5_17_2_201V_92P5attn_StripsGeometry : public DefaultGeometry
{
public:
    // 
    // Used lecroy scope channels 0-7
    // Scope channel 0-6 was AC channels, and scope channel 7 was the photek
    // 
    // |-----------|             -----
    // | 0 0 0 0 0 |             |777|
    // | 1 1 1 1 1 |             |777|
    // | 2 2 2 2 2 |             -----
    // | 3 3 3 3 3 |
    // | 4 4 4 4 4 |
    // | 5 5 5 5 5 |
    // | 6 6 6 6 6 |
    // |-----------|

    HPK_W5_17_2_201V_92P5attn_StripsGeometry(const int v=0) : voltage(v){}
    const int voltage;
    std::map<int, std::vector<int>> indexToGeometryMap = {{0,{0,0}}, {1,{0,1}}, {2,{0,2}}, {3,{1,0}}};   
    std::vector<std::vector<int>> geometry = {{0,1,2},{3}};
    std::map<int, bool> acLGADChannelMap = {{0,true}, {1,true}, {2,true}, {3,false}};
    std::map<int, double> amplitudeCorrectionFactor = {{0,1.0}, {1,1.0}, {2,1.0}, {3,1.0}};
    std::map<int, double> timeCalibrationCorrection = {{0,-46.029372}, {1,-46.200854}, {2,-45.369979}, {3,0.0}};
    // std::map<int, double> timeCalibrationCorrection = {{0,0.0}, {1,0.0}, {2,0.0}, {3,0.0}};
    double stripWidth = 0.050;
    double pitch = 0.500;
    std::vector<double> stripCenterXPosition = {0.5, 0.0, -0.5, 0.0}; // Iter3
    int numLGADchannels = 3;
    int lowGoodStripIndex = 0;
    int highGoodStripIndex = 2;
    double xBinSize = 0.05;
    double yBinSize = 0.1;
    double xmin = -0.80-stripWidth/2; // Sensor's local frame
    double xmax =  0.80+stripWidth/2; // Sensor's local frame
    double ymin = -2.9-stripWidth/2; // Sensor's local frame
    double ymax = 2.9+stripWidth/2; // Sensor's local frame
    double positionRecoMaxPoint = 0.8;
    double noiseAmpThreshold  = 15.0;
    double signalAmpThreshold = 15.0;
    bool enablePositionReconstruction = true;
    int CFD_threshold = 50;
    std::vector<double> positionRecoPar = {0.250000, -0.647033, 0.113372, -2.800081, 15.949423, -30.947705};
    std::vector<std::vector<double>> sensorEdges = {{-0.7, -2.9}, {0.7, 2.9}};//{{-0.7, -4.5}, {0.7, 4.5}}; // Sensor's local frame
    std::vector<std::vector<double>> sensorEdgesTight = {{stripCenterXPosition[highGoodStripIndex], -2.9}, {stripCenterXPosition[lowGoodStripIndex], 2.9}}; // Sensor's local frame
    int centerGoodStripIndex = 1;
    double leftHighGainX = stripCenterXPosition[centerGoodStripIndex] - (stripWidth/2);
    double rightHighGainX = stripCenterXPosition[centerGoodStripIndex] + (stripWidth/2);
    double leftLowGainX = stripCenterXPosition[centerGoodStripIndex] - (pitch/2) - (stripWidth/2);
    double rightLowGainX = stripCenterXPosition[centerGoodStripIndex] - (pitch/2) + (stripWidth/2);
    std::vector<utility::ROI> regionsOfIntrest = {{"highGain", leftHighGainX, rightHighGainX, -2.9, 2.9}, {"lowGain", leftLowGainX, rightLowGainX, -2.9, 2.9}};
};

//done
class HPK_W5_17_2_201V_93attn_StripsGeometry : public DefaultGeometry
{
public:
    // 
    // Used lecroy scope channels 0-7
    // Scope channel 0-6 was AC channels, and scope channel 7 was the photek
    // 
    // |-----------|             -----
    // | 0 0 0 0 0 |             |777|
    // | 1 1 1 1 1 |             |777|
    // | 2 2 2 2 2 |             -----
    // | 3 3 3 3 3 |
    // | 4 4 4 4 4 |
    // | 5 5 5 5 5 |
    // | 6 6 6 6 6 |
    // |-----------|

    HPK_W5_17_2_201V_93attn_StripsGeometry(const int v=0) : voltage(v){}
    const int voltage;
    std::map<int, std::vector<int>> indexToGeometryMap = {{0,{0,0}}, {1,{0,1}}, {2,{0,2}}, {3,{1,0}}};   
    std::vector<std::vector<int>> geometry = {{0,1,2},{3}};
    std::map<int, bool> acLGADChannelMap = {{0,true}, {1,true}, {2,true}, {3,false}};
    std::map<int, double> amplitudeCorrectionFactor = {{0,1.0}, {1,1.0}, {2,1.0}, {3,1.0}};
    std::map<int, double> timeCalibrationCorrection = {{0,-45.997376}, {1,-46.174820}, {2,-45.337424}, {3,0.0}};
    // std::map<int, double> timeCalibrationCorrection = {{0,0.0}, {1,0.0}, {2,0.0}, {3,0.0}};
    double stripWidth = 0.050;
    double pitch = 0.500;
    std::vector<double> stripCenterXPosition = {0.5, 0.0, -0.5, 0.0}; // Iter3
    int numLGADchannels = 3;
    int lowGoodStripIndex = 0;
    int highGoodStripIndex = 2;
    double xBinSize = 0.05;
    double yBinSize = 0.1;
    double xmin = -0.80-stripWidth/2; // Sensor's local frame
    double xmax =  0.80+stripWidth/2; // Sensor's local frame
    double ymin = -2.9-stripWidth/2; // Sensor's local frame
    double ymax = 2.9+stripWidth/2; // Sensor's local frame
    double positionRecoMaxPoint = 0.8;
    double noiseAmpThreshold  = 15.0;
    double signalAmpThreshold = 15.0;
    bool enablePositionReconstruction = true;
    int CFD_threshold = 50;
    std::vector<double> positionRecoPar = {0.250000, -0.644028, 0.041097, -2.307275, 15.203857, -31.007728};
    std::vector<std::vector<double>> sensorEdges = {{-0.7, -2.9}, {0.7, 2.9}};//{{-0.7, -4.5}, {0.7, 4.5}}; // Sensor's local frame
    std::vector<std::vector<double>> sensorEdgesTight = {{stripCenterXPosition[highGoodStripIndex], -2.9}, {stripCenterXPosition[lowGoodStripIndex], 2.9}}; // Sensor's local frame
    int centerGoodStripIndex = 1;
    double leftHighGainX = stripCenterXPosition[centerGoodStripIndex] - (stripWidth/2);
    double rightHighGainX = stripCenterXPosition[centerGoodStripIndex] + (stripWidth/2);
    double leftLowGainX = stripCenterXPosition[centerGoodStripIndex] - (pitch/2) - (stripWidth/2);
    double rightLowGainX = stripCenterXPosition[centerGoodStripIndex] - (pitch/2) + (stripWidth/2);
    std::vector<utility::ROI> regionsOfIntrest = {{"highGain", leftHighGainX, rightHighGainX, -2.9, 2.9}, {"lowGain", leftLowGainX, rightLowGainX, -2.9, 2.9}};
};

//done
class HPK_W5_17_2_201V_93P5attn_StripsGeometry : public DefaultGeometry
{
public:
    // 
    // Used lecroy scope channels 0-7
    // Scope channel 0-6 was AC channels, and scope channel 7 was the photek
    // 
    // |-----------|             -----
    // | 0 0 0 0 0 |             |777|
    // | 1 1 1 1 1 |             |777|
    // | 2 2 2 2 2 |             -----
    // | 3 3 3 3 3 |
    // | 4 4 4 4 4 |
    // | 5 5 5 5 5 |
    // | 6 6 6 6 6 |
    // |-----------|

    HPK_W5_17_2_201V_93P5attn_StripsGeometry(const int v=0) : voltage(v){}
    const int voltage;
    std::map<int, std::vector<int>> indexToGeometryMap = {{0,{0,0}}, {1,{0,1}}, {2,{0,2}}, {3,{1,0}}};   
    std::vector<std::vector<int>> geometry = {{0,1,2},{3}};
    std::map<int, bool> acLGADChannelMap = {{0,true}, {1,true}, {2,true}, {3,false}};
    std::map<int, double> amplitudeCorrectionFactor = {{0,1.0}, {1,1.0}, {2,1.0}, {3,1.0}};
    std::map<int, double> timeCalibrationCorrection = {{0,-46.000697}, {1,-46.172908}, {2,-45.341928}, {3,0.0}};
    // std::map<int, double> timeCalibrationCorrection = {{0,0.0}, {1,0.0}, {2,0.0}, {3,0.0}};
    double stripWidth = 0.050;
    double pitch = 0.500;
    std::vector<double> stripCenterXPosition = {0.5, 0.0, -0.5, 0.0}; // Iter3
    int numLGADchannels = 3;
    int lowGoodStripIndex = 0;
    int highGoodStripIndex = 2;
    double xBinSize = 0.05;
    double yBinSize = 0.1;
    double xmin = -0.80-stripWidth/2; // Sensor's local frame
    double xmax =  0.80+stripWidth/2; // Sensor's local frame
    double ymin = -2.9-stripWidth/2; // Sensor's local frame
    double ymax = 2.9+stripWidth/2; // Sensor's local frame
    double positionRecoMaxPoint = 0.8;
    double noiseAmpThreshold  = 15.0;
    double signalAmpThreshold = 15.0;
    bool enablePositionReconstruction = true;
    int CFD_threshold = 50;
    std::vector<double> positionRecoPar = {0.250000, -0.638384, 0.019097, -2.746838, 16.888081, -32.046352};
    std::vector<std::vector<double>> sensorEdges = {{-0.7, -2.9}, {0.7, 2.9}};//{{-0.7, -4.5}, {0.7, 4.5}}; // Sensor's local frame
    std::vector<std::vector<double>> sensorEdgesTight = {{stripCenterXPosition[highGoodStripIndex], -2.9}, {stripCenterXPosition[lowGoodStripIndex], 2.9}}; // Sensor's local frame
    int centerGoodStripIndex = 1;
    double leftHighGainX = stripCenterXPosition[centerGoodStripIndex] - (stripWidth/2);
    double rightHighGainX = stripCenterXPosition[centerGoodStripIndex] + (stripWidth/2);
    double leftLowGainX = stripCenterXPosition[centerGoodStripIndex] - (pitch/2) - (stripWidth/2);
    double rightLowGainX = stripCenterXPosition[centerGoodStripIndex] - (pitch/2) + (stripWidth/2);
    std::vector<utility::ROI> regionsOfIntrest = {{"highGain", leftHighGainX, rightHighGainX, -2.9, 2.9}, {"lowGain", leftLowGainX, rightLowGainX, -2.9, 2.9}};
};

//done
class HPK_W5_17_2_201V_94attn_StripsGeometry : public DefaultGeometry
{
public:
    // 
    // Used lecroy scope channels 0-7
    // Scope channel 0-6 was AC channels, and scope channel 7 was the photek
    // 
    // |-----------|             -----
    // | 0 0 0 0 0 |             |777|
    // | 1 1 1 1 1 |             |777|
    // | 2 2 2 2 2 |             -----
    // | 3 3 3 3 3 |
    // | 4 4 4 4 4 |
    // | 5 5 5 5 5 |
    // | 6 6 6 6 6 |
    // |-----------|

    HPK_W5_17_2_201V_94attn_StripsGeometry(const int v=0) : voltage(v){}
    const int voltage;
    std::map<int, std::vector<int>> indexToGeometryMap = {{0,{0,0}}, {1,{0,1}}, {2,{0,2}}, {3,{1,0}}};   
    std::vector<std::vector<int>> geometry = {{0,1,2},{3}};
    std::map<int, bool> acLGADChannelMap = {{0,true}, {1,true}, {2,true}, {3,false}};
    std::map<int, double> amplitudeCorrectionFactor = {{0,1.0}, {1,1.0}, {2,1.0}, {3,1.0}};
    std::map<int, double> timeCalibrationCorrection = {{0,-46.000042}, {1,-46.168090}, {2,-45.343360}, {3,0.0}};
    // std::map<int, double> timeCalibrationCorrection = {{0,0.0}, {1,0.0}, {2,0.0}, {3,0.0}};
    double stripWidth = 0.050;
    double pitch = 0.500;
    std::vector<double> stripCenterXPosition = {0.5, 0.0, -0.5, 0.0}; // Iter3
    int numLGADchannels = 3;
    int lowGoodStripIndex = 0;
    int highGoodStripIndex = 2;
    double xBinSize = 0.05;
    double yBinSize = 0.1;
    double xmin = -0.80-stripWidth/2; // Sensor's local frame
    double xmax =  0.80+stripWidth/2; // Sensor's local frame
    double ymin = -2.9-stripWidth/2; // Sensor's local frame
    double ymax = 2.9+stripWidth/2; // Sensor's local frame
    double positionRecoMaxPoint = 0.8;
    double noiseAmpThreshold  = 15.0;
    double signalAmpThreshold = 15.0;
    bool enablePositionReconstruction = true;
    int CFD_threshold = 50;
    std::vector<double> positionRecoPar = {0.250000, -0.628261, -0.517843, 3.112663, -6.966303, 1.318337};
    std::vector<std::vector<double>> sensorEdges = {{-0.7, -2.9}, {0.7, 2.9}};//{{-0.7, -4.5}, {0.7, 4.5}}; // Sensor's local frame
    std::vector<std::vector<double>> sensorEdgesTight = {{stripCenterXPosition[highGoodStripIndex], -2.9}, {stripCenterXPosition[lowGoodStripIndex], 2.9}}; // Sensor's local frame
    int centerGoodStripIndex = 1;
    double leftHighGainX = stripCenterXPosition[centerGoodStripIndex] - (stripWidth/2);
    double rightHighGainX = stripCenterXPosition[centerGoodStripIndex] + (stripWidth/2);
    double leftLowGainX = stripCenterXPosition[centerGoodStripIndex] - (pitch/2) - (stripWidth/2);
    double rightLowGainX = stripCenterXPosition[centerGoodStripIndex] - (pitch/2) + (stripWidth/2);
    std::vector<utility::ROI> regionsOfIntrest = {{"highGain", leftHighGainX, rightHighGainX, -2.9, 2.9}, {"lowGain", leftLowGainX, rightLowGainX, -2.9, 2.9}};
};

//done
class HPK_W5_17_2_201V_94P5attn_StripsGeometry : public DefaultGeometry
{
public:
    // 
    // Used lecroy scope channels 0-7
    // Scope channel 0-6 was AC channels, and scope channel 7 was the photek
    // 
    // |-----------|             -----
    // | 0 0 0 0 0 |             |777|
    // | 1 1 1 1 1 |             |777|
    // | 2 2 2 2 2 |             -----
    // | 3 3 3 3 3 |
    // | 4 4 4 4 4 |
    // | 5 5 5 5 5 |
    // | 6 6 6 6 6 |
    // |-----------|

    HPK_W5_17_2_201V_94P5attn_StripsGeometry(const int v=0) : voltage(v){}
    const int voltage;
    std::map<int, std::vector<int>> indexToGeometryMap = {{0,{0,0}}, {1,{0,1}}, {2,{0,2}}, {3,{1,0}}};   
    std::vector<std::vector<int>> geometry = {{0,1,2},{3}};
    std::map<int, bool> acLGADChannelMap = {{0,true}, {1,true}, {2,true}, {3,false}};
    std::map<int, double> amplitudeCorrectionFactor = {{0,1.0}, {1,1.0}, {2,1.0}, {3,1.0}};
    std::map<int, double> timeCalibrationCorrection = {{0,-45.995573}, {1,-46.162193}, {2,-45.339738}, {3,0.0}};
    // std::map<int, double> timeCalibrationCorrection = {{0,0.0}, {1,0.0}, {2,0.0}, {3,0.0}};
    double stripWidth = 0.050;
    double pitch = 0.500;
    std::vector<double> stripCenterXPosition = {0.5, 0.0, -0.5, 0.0}; // Iter3
    int numLGADchannels = 3;
    int lowGoodStripIndex = 0;
    int highGoodStripIndex = 2;
    double xBinSize = 0.05;
    double yBinSize = 0.1;
    double xmin = -0.80-stripWidth/2; // Sensor's local frame
    double xmax =  0.80+stripWidth/2; // Sensor's local frame
    double ymin = -2.9-stripWidth/2; // Sensor's local frame
    double ymax = 2.9+stripWidth/2; // Sensor's local frame
    double positionRecoMaxPoint = 0.8;
    double noiseAmpThreshold  = 15.0;
    double signalAmpThreshold = 15.0;
    bool enablePositionReconstruction = true;
    int CFD_threshold = 50;
    std::vector<double> positionRecoPar = {0.250000, -0.597614, -1.618751, 15.274049, -59.688262, 79.902007};
    std::vector<std::vector<double>> sensorEdges = {{-0.7, -2.9}, {0.7, 2.9}};//{{-0.7, -4.5}, {0.7, 4.5}}; // Sensor's local frame
    std::vector<std::vector<double>> sensorEdgesTight = {{stripCenterXPosition[highGoodStripIndex], -2.9}, {stripCenterXPosition[lowGoodStripIndex], 2.9}}; // Sensor's local frame
    int centerGoodStripIndex = 1;
    double leftHighGainX = stripCenterXPosition[centerGoodStripIndex] - (stripWidth/2);
    double rightHighGainX = stripCenterXPosition[centerGoodStripIndex] + (stripWidth/2);
    double leftLowGainX = stripCenterXPosition[centerGoodStripIndex] - (pitch/2) - (stripWidth/2);
    double rightLowGainX = stripCenterXPosition[centerGoodStripIndex] - (pitch/2) + (stripWidth/2);
    std::vector<utility::ROI> regionsOfIntrest = {{"highGain", leftHighGainX, rightHighGainX, -2.9, 2.9}, {"lowGain", leftLowGainX, rightLowGainX, -2.9, 2.9}};
};


//done
class HPK_W5_17_2_203V_91P5attn_StripsGeometry : public DefaultGeometry
{
public:
    // 
    // Used lecroy scope channels 0-7
    // Scope channel 0-6 was AC channels, and scope channel 7 was the photek
    // 
    // |-----------|             -----
    // | 0 0 0 0 0 |             |777|
    // | 1 1 1 1 1 |             |777|
    // | 2 2 2 2 2 |             -----
    // | 3 3 3 3 3 |
    // | 4 4 4 4 4 |
    // | 5 5 5 5 5 |
    // | 6 6 6 6 6 |
    // |-----------|

    HPK_W5_17_2_203V_91P5attn_StripsGeometry(const int v=0) : voltage(v){}
    const int voltage;
    std::map<int, std::vector<int>> indexToGeometryMap = {{0,{0,0}}, {1,{0,1}}, {2,{0,2}}, {3,{1,0}}};   
    std::vector<std::vector<int>> geometry = {{0,1,2},{3}};
    std::map<int, bool> acLGADChannelMap = {{0,true}, {1,true}, {2,true}, {3,false}};
    std::map<int, double> amplitudeCorrectionFactor = {{0,1.0}, {1,1.0}, {2,1.0},{3,1.0}};
    std::map<int, double> timeCalibrationCorrection = {{0,-46.068321}, {1,-46.233859}, {2,-45.408159}, {3,0.0}};
    // std::map<int, double> timeCalibrationCorrection = {{0,0.0}, {1,0.0}, {2,0.0}, {3,0.0}};
    double stripWidth = 0.050;
    double pitch = 0.500;
    std::vector<double> stripCenterXPosition = {0.5, 0.0, -0.5, 0.0}; // Iter3
    int numLGADchannels = 3;
    int lowGoodStripIndex = 0;
    int highGoodStripIndex = 2;
    double xBinSize = 0.05;
    double yBinSize = 0.1;
    double xmin = -0.80-stripWidth/2; // Sensor's local frame
    double xmax =  0.80+stripWidth/2; // Sensor's local frame
    double ymin = -2.9-stripWidth/2; // Sensor's local frame
    double ymax = 2.9+stripWidth/2; // Sensor's local frame
    double positionRecoMaxPoint = 0.8;
    double noiseAmpThreshold  = 15.0;
    double signalAmpThreshold = 15.0;
    bool enablePositionReconstruction = true;
    int CFD_threshold = 50;
    std::vector<double> positionRecoPar = {0.250000, -0.657670, 0.401025, -4.606069, 19.837329, -32.334438};
    std::vector<std::vector<double>> sensorEdges = {{-0.7, -2.9}, {0.7, 2.9}};//{{-0.7, -4.5}, {0.7, 4.5}}; // Sensor's local frame
    std::vector<std::vector<double>> sensorEdgesTight = {{stripCenterXPosition[highGoodStripIndex], -2.9}, {stripCenterXPosition[lowGoodStripIndex], 2.9}}; // Sensor's local frame
    int centerGoodStripIndex = 1;
    double leftHighGainX = stripCenterXPosition[centerGoodStripIndex] - (stripWidth/2);
    double rightHighGainX = stripCenterXPosition[centerGoodStripIndex] + (stripWidth/2);
    double leftLowGainX = stripCenterXPosition[centerGoodStripIndex] - (pitch/2) - (stripWidth/2);
    double rightLowGainX = stripCenterXPosition[centerGoodStripIndex] - (pitch/2) + (stripWidth/2);
    std::vector<utility::ROI> regionsOfIntrest = {{"highGain", leftHighGainX, rightHighGainX, -2.9, 2.9}, {"lowGain", leftLowGainX, rightLowGainX, -2.9, 2.9}};
};

//done
class HPK_W5_17_2_203V_92attn_StripsGeometry : public DefaultGeometry
{
public:
    // 
    // Used lecroy scope channels 0-7
    // Scope channel 0-6 was AC channels, and scope channel 7 was the photek
    // 
    // |-----------|             -----
    // | 0 0 0 0 0 |             |777|
    // | 1 1 1 1 1 |             |777|
    // | 2 2 2 2 2 |             -----
    // | 3 3 3 3 3 |
    // | 4 4 4 4 4 |
    // | 5 5 5 5 5 |
    // | 6 6 6 6 6 |
    // |-----------|

    HPK_W5_17_2_203V_92attn_StripsGeometry(const int v=0) : voltage(v){}
    const int voltage;
    std::map<int, std::vector<int>> indexToGeometryMap = {{0,{0,0}}, {1,{0,1}}, {2,{0,2}}, {3,{1,0}}};   
    std::vector<std::vector<int>> geometry = {{0,1,2},{3}};
    std::map<int, bool> acLGADChannelMap = {{0,true}, {1,true}, {2,true}, {3,false}};
    std::map<int, double> amplitudeCorrectionFactor = {{0,1.0}, {1,1.0}, {2,1.0},{3,1.0}};
    std::map<int, double> timeCalibrationCorrection = {{0,-46.049579}, {1,-46.225791}, {2,-45.388057}, {3,0.0}};
    // std::map<int, double> timeCalibrationCorrection = {{0,0.0}, {1,0.0}, {2,0.0}, {3,0.0}};
    double stripWidth = 0.050;
    double pitch = 0.500;
    std::vector<double> stripCenterXPosition = {0.5, 0.0, -0.5, 0.0}; // Iter3
    int numLGADchannels = 3;
    int lowGoodStripIndex = 0;
    int highGoodStripIndex = 2;
    double xBinSize = 0.05;
    double yBinSize = 0.1;
    double xmin = -0.80-stripWidth/2; // Sensor's local frame
    double xmax =  0.80+stripWidth/2; // Sensor's local frame
    double ymin = -2.9-stripWidth/2; // Sensor's local frame
    double ymax = 2.9+stripWidth/2; // Sensor's local frame
    double positionRecoMaxPoint = 0.8;
    double noiseAmpThreshold  = 15.0;
    double signalAmpThreshold = 15.0;
    bool enablePositionReconstruction = true;
    int CFD_threshold = 50;
    std::vector<double> positionRecoPar = {0.250000, -0.645155, 0.149249, -2.784503, 13.799987, -24.711136};
    std::vector<std::vector<double>> sensorEdges = {{-0.7, -2.9}, {0.7, 2.9}};//{{-0.7, -4.5}, {0.7, 4.5}}; // Sensor's local frame
    std::vector<std::vector<double>> sensorEdgesTight = {{stripCenterXPosition[highGoodStripIndex], -2.9}, {stripCenterXPosition[lowGoodStripIndex], 2.9}}; // Sensor's local frame
    int centerGoodStripIndex = 1;
    double leftHighGainX = stripCenterXPosition[centerGoodStripIndex] - (stripWidth/2);
    double rightHighGainX = stripCenterXPosition[centerGoodStripIndex] + (stripWidth/2);
    double leftLowGainX = stripCenterXPosition[centerGoodStripIndex] - (pitch/2) - (stripWidth/2);
    double rightLowGainX = stripCenterXPosition[centerGoodStripIndex] - (pitch/2) + (stripWidth/2);
    std::vector<utility::ROI> regionsOfIntrest = {{"highGain", leftHighGainX, rightHighGainX, -2.9, 2.9}, {"lowGain", leftLowGainX, rightLowGainX, -2.9, 2.9}};
};

//done
class HPK_W5_17_2_203V_92P5attn_StripsGeometry : public DefaultGeometry
{
public:
    // 
    // Used lecroy scope channels 0-7
    // Scope channel 0-6 was AC channels, and scope channel 7 was the photek
    // 
    // |-----------|             -----
    // | 0 0 0 0 0 |             |777|
    // | 1 1 1 1 1 |             |777|
    // | 2 2 2 2 2 |             -----
    // | 3 3 3 3 3 |
    // | 4 4 4 4 4 |
    // | 5 5 5 5 5 |
    // | 6 6 6 6 6 |
    // |-----------|

    HPK_W5_17_2_203V_92P5attn_StripsGeometry(const int v=0) : voltage(v){}
    const int voltage;
    std::map<int, std::vector<int>> indexToGeometryMap = {{0,{0,0}}, {1,{0,1}}, {2,{0,2}}, {3,{1,0}}};   
    std::vector<std::vector<int>> geometry = {{0,1,2},{3}};
    std::map<int, bool> acLGADChannelMap = {{0,true}, {1,true}, {2,true}, {3,false}};
    std::map<int, double> amplitudeCorrectionFactor = {{0,1.0}, {1,1.0}, {2,1.0},{3,1.0}};
    std::map<int, double> timeCalibrationCorrection = {{0,-46.040885}, {1,-46.214082}, {2,-45.381512}, {3,0.0}};
    // std::map<int, double> timeCalibrationCorrection = {{0,0.0}, {1,0.0}, {2,0.0}, {3,0.0}};
    double stripWidth = 0.050;
    double pitch = 0.500;
    std::vector<double> stripCenterXPosition = {0.5, 0.0, -0.5, 0.0}; // Iter3
    int numLGADchannels = 3;
    int lowGoodStripIndex = 0;
    int highGoodStripIndex = 2;
    double xBinSize = 0.05;
    double yBinSize = 0.1;
    double xmin = -0.80-stripWidth/2; // Sensor's local frame
    double xmax =  0.80+stripWidth/2; // Sensor's local frame
    double ymin = -2.9-stripWidth/2; // Sensor's local frame
    double ymax = 2.9+stripWidth/2; // Sensor's local frame
    double positionRecoMaxPoint = 0.8;
    double noiseAmpThreshold  = 15.0;
    double signalAmpThreshold = 15.0;
    bool enablePositionReconstruction = true;
    int CFD_threshold = 50;
    std::vector<double> positionRecoPar = {0.250000, -0.669844, 0.550296, -6.540007, 30.736339, -52.701310};
    std::vector<std::vector<double>> sensorEdges = {{-0.7, -2.9}, {0.7, 2.9}};//{{-0.7, -4.5}, {0.7, 4.5}}; // Sensor's local frame
    std::vector<std::vector<double>> sensorEdgesTight = {{stripCenterXPosition[highGoodStripIndex], -2.9}, {stripCenterXPosition[lowGoodStripIndex], 2.9}}; // Sensor's local frame
    int centerGoodStripIndex = 1;
    double leftHighGainX = stripCenterXPosition[centerGoodStripIndex] - (stripWidth/2);
    double rightHighGainX = stripCenterXPosition[centerGoodStripIndex] + (stripWidth/2);
    double leftLowGainX = stripCenterXPosition[centerGoodStripIndex] - (pitch/2) - (stripWidth/2);
    double rightLowGainX = stripCenterXPosition[centerGoodStripIndex] - (pitch/2) + (stripWidth/2);
    std::vector<utility::ROI> regionsOfIntrest = {{"highGain", leftHighGainX, rightHighGainX, -2.9, 2.9}, {"lowGain", leftLowGainX, rightLowGainX, -2.9, 2.9}};
};

//done
class HPK_W5_17_2_203V_93attn_StripsGeometry : public DefaultGeometry
{
public:
    // 
    // Used lecroy scope channels 0-7
    // Scope channel 0-6 was AC channels, and scope channel 7 was the photek
    // 
    // |-----------|             -----
    // | 0 0 0 0 0 |             |777|
    // | 1 1 1 1 1 |             |777|
    // | 2 2 2 2 2 |             -----
    // | 3 3 3 3 3 |
    // | 4 4 4 4 4 |
    // | 5 5 5 5 5 |
    // | 6 6 6 6 6 |
    // |-----------|

    HPK_W5_17_2_203V_93attn_StripsGeometry(const int v=0) : voltage(v){}
    const int voltage;
    std::map<int, std::vector<int>> indexToGeometryMap = {{0,{0,0}}, {1,{0,1}}, {2,{0,2}}, {3,{1,0}}};   
    std::vector<std::vector<int>> geometry = {{0,1,2},{3}};
    std::map<int, bool> acLGADChannelMap = {{0,true}, {1,true}, {2,true}, {3,false}};
    std::map<int, double> amplitudeCorrectionFactor = {{0,1.0}, {1,1.0}, {2,1.0},{3,1.0}};
    std::map<int, double> timeCalibrationCorrection = {{0,-46.029624}, {1,-46.202076}, {2,-45.369464}, {3,0.0}};
    // std::map<int, double> timeCalibrationCorrection = {{0,0.0}, {1,0.0}, {2,0.0}, {3,0.0}};
    double stripWidth = 0.050;
    double pitch = 0.500;
    std::vector<double> stripCenterXPosition = {0.5, 0.0, -0.5, 0.0}; // Iter3
    int numLGADchannels = 3;
    int lowGoodStripIndex = 0;
    int highGoodStripIndex = 2;
    double xBinSize = 0.05;
    double yBinSize = 0.1;
    double xmin = -0.80-stripWidth/2; // Sensor's local frame
    double xmax =  0.80+stripWidth/2; // Sensor's local frame
    double ymin = -2.9-stripWidth/2; // Sensor's local frame
    double ymax = 2.9+stripWidth/2; // Sensor's local frame
    double positionRecoMaxPoint = 0.8;
    double noiseAmpThreshold  = 15.0;
    double signalAmpThreshold = 15.0;
    bool enablePositionReconstruction = true;
    int CFD_threshold = 50;
    std::vector<double> positionRecoPar = {0.250000, -0.662673, 0.329791, -3.770656, 16.791356, -29.433423};
    std::vector<std::vector<double>> sensorEdges = {{-0.7, -2.9}, {0.7, 2.9}};//{{-0.7, -4.5}, {0.7, 4.5}}; // Sensor's local frame
    std::vector<std::vector<double>> sensorEdgesTight = {{stripCenterXPosition[highGoodStripIndex], -2.9}, {stripCenterXPosition[lowGoodStripIndex], 2.9}}; // Sensor's local frame
    int centerGoodStripIndex = 1;
    double leftHighGainX = stripCenterXPosition[centerGoodStripIndex] - (stripWidth/2);
    double rightHighGainX = stripCenterXPosition[centerGoodStripIndex] + (stripWidth/2);
    double leftLowGainX = stripCenterXPosition[centerGoodStripIndex] - (pitch/2) - (stripWidth/2);
    double rightLowGainX = stripCenterXPosition[centerGoodStripIndex] - (pitch/2) + (stripWidth/2);
    std::vector<utility::ROI> regionsOfIntrest = {{"highGain", leftHighGainX, rightHighGainX, -2.9, 2.9}, {"lowGain", leftLowGainX, rightLowGainX, -2.9, 2.9}};
};

//done
class HPK_W5_17_2_203V_93P5attn_StripsGeometry : public DefaultGeometry
{
public:
    // 
    // Used lecroy scope channels 0-7
    // Scope channel 0-6 was AC channels, and scope channel 7 was the photek
    // 
    // |-----------|             -----
    // | 0 0 0 0 0 |             |777|
    // | 1 1 1 1 1 |             |777|
    // | 2 2 2 2 2 |             -----
    // | 3 3 3 3 3 |
    // | 4 4 4 4 4 |
    // | 5 5 5 5 5 |
    // | 6 6 6 6 6 |
    // |-----------|

    HPK_W5_17_2_203V_93P5attn_StripsGeometry(const int v=0) : voltage(v){}
    const int voltage;
    std::map<int, std::vector<int>> indexToGeometryMap = {{0,{0,0}}, {1,{0,1}}, {2,{0,2}}, {3,{1,0}}};   
    std::vector<std::vector<int>> geometry = {{0,1,2},{3}};
    std::map<int, bool> acLGADChannelMap = {{0,true}, {1,true}, {2,true}, {3,false}};
    std::map<int, double> amplitudeCorrectionFactor = {{0,1.0}, {1,1.0}, {2,1.0},{3,1.0}};
    std::map<int, double> timeCalibrationCorrection = {{0,-46.021152}, {1,-46.192284}, {2,-45.361976}, {3,0.0}};
    // std::map<int, double> timeCalibrationCorrection = {{0,0.0}, {1,0.0}, {2,0.0}, {3,0.0}};
    double stripWidth = 0.050;
    double pitch = 0.500;
    std::vector<double> stripCenterXPosition = {0.5, 0.0, -0.5, 0.0}; // Iter3
    int numLGADchannels = 3;
    int lowGoodStripIndex = 0;
    int highGoodStripIndex = 2;
    double xBinSize = 0.05;
    double yBinSize = 0.1;
    double xmin = -0.80-stripWidth/2; // Sensor's local frame
    double xmax =  0.80+stripWidth/2; // Sensor's local frame
    double ymin = -2.9-stripWidth/2; // Sensor's local frame
    double ymax = 2.9+stripWidth/2; // Sensor's local frame
    double positionRecoMaxPoint = 0.8;
    double noiseAmpThreshold  = 15.0;
    double signalAmpThreshold = 15.0;
    bool enablePositionReconstruction = true;
    int CFD_threshold = 50;
    std::vector<double> positionRecoPar = {0.250000, -0.649814, 0.107460, -2.583056, 13.833388, -26.055542};
    std::vector<std::vector<double>> sensorEdges = {{-0.7, -2.9}, {0.7, 2.9}};//{{-0.7, -4.5}, {0.7, 4.5}}; // Sensor's local frame
    std::vector<std::vector<double>> sensorEdgesTight = {{stripCenterXPosition[highGoodStripIndex], -2.9}, {stripCenterXPosition[lowGoodStripIndex], 2.9}}; // Sensor's local frame
    int centerGoodStripIndex = 1;
    double leftHighGainX = stripCenterXPosition[centerGoodStripIndex] - (stripWidth/2);
    double rightHighGainX = stripCenterXPosition[centerGoodStripIndex] + (stripWidth/2);
    double leftLowGainX = stripCenterXPosition[centerGoodStripIndex] - (pitch/2) - (stripWidth/2);
    double rightLowGainX = stripCenterXPosition[centerGoodStripIndex] - (pitch/2) + (stripWidth/2);
    std::vector<utility::ROI> regionsOfIntrest = {{"highGain", leftHighGainX, rightHighGainX, -2.9, 2.9}, {"lowGain", leftLowGainX, rightLowGainX, -2.9, 2.9}};
};

//done
class HPK_W5_17_2_203V_94attn_StripsGeometry : public DefaultGeometry
{
public:
    // 
    // Used lecroy scope channels 0-7
    // Scope channel 0-6 was AC channels, and scope channel 7 was the photek
    // 
    // |-----------|             -----
    // | 0 0 0 0 0 |             |777|
    // | 1 1 1 1 1 |             |777|
    // | 2 2 2 2 2 |             -----
    // | 3 3 3 3 3 |
    // | 4 4 4 4 4 |
    // | 5 5 5 5 5 |
    // | 6 6 6 6 6 |
    // |-----------|

    HPK_W5_17_2_203V_94attn_StripsGeometry(const int v=0) : voltage(v){}
    const int voltage;
    std::map<int, std::vector<int>> indexToGeometryMap = {{0,{0,0}}, {1,{0,1}}, {2,{0,2}}, {3,{1,0}}};   
    std::vector<std::vector<int>> geometry = {{0,1,2},{3}};
    std::map<int, bool> acLGADChannelMap = {{0,true}, {1,true}, {2,true}, {3,false}};
    std::map<int, double> amplitudeCorrectionFactor = {{0,1.0}, {1,1.0}, {2,1.0},{3,1.0}};
    std::map<int, double> timeCalibrationCorrection = {{0,-46.010240}, {1,-46.177651}, {2,-45.354078}, {3,0.0}};
    // std::map<int, double> timeCalibrationCorrection = {{0,0.0}, {1,0.0}, {2,0.0}, {3,0.0}};
    double stripWidth = 0.050;
    double pitch = 0.500;
    std::vector<double> stripCenterXPosition = {0.5, 0.0, -0.5, 0.0}; // Iter3
    int numLGADchannels = 3;
    int lowGoodStripIndex = 0;
    int highGoodStripIndex = 2;
    double xBinSize = 0.05;
    double yBinSize = 0.1;
    double xmin = -0.80-stripWidth/2; // Sensor's local frame
    double xmax =  0.80+stripWidth/2; // Sensor's local frame
    double ymin = -2.9-stripWidth/2; // Sensor's local frame
    double ymax = 2.9+stripWidth/2; // Sensor's local frame
    double positionRecoMaxPoint = 0.8;
    double noiseAmpThreshold  = 15.0;
    double signalAmpThreshold = 15.0;
    bool enablePositionReconstruction = true;
    int CFD_threshold = 50;
    std::vector<double> positionRecoPar = {0.250000, -0.635605, -0.402467, 3.293503, -12.556372, 14.488987};
    std::vector<std::vector<double>> sensorEdges = {{-0.7, -2.9}, {0.7, 2.9}};//{{-0.7, -4.5}, {0.7, 4.5}}; // Sensor's local frame
    std::vector<std::vector<double>> sensorEdgesTight = {{stripCenterXPosition[highGoodStripIndex], -2.9}, {stripCenterXPosition[lowGoodStripIndex], 2.9}}; // Sensor's local frame
    int centerGoodStripIndex = 1;
    double leftHighGainX = stripCenterXPosition[centerGoodStripIndex] - (stripWidth/2);
    double rightHighGainX = stripCenterXPosition[centerGoodStripIndex] + (stripWidth/2);
    double leftLowGainX = stripCenterXPosition[centerGoodStripIndex] - (pitch/2) - (stripWidth/2);
    double rightLowGainX = stripCenterXPosition[centerGoodStripIndex] - (pitch/2) + (stripWidth/2);
    std::vector<utility::ROI> regionsOfIntrest = {{"highGain", leftHighGainX, rightHighGainX, -2.9, 2.9}, {"lowGain", leftLowGainX, rightLowGainX, -2.9, 2.9}};
};

//done
class HPK_W5_17_2_203V_94P5attn_StripsGeometry : public DefaultGeometry
{
public:
    // 
    // Used lecroy scope channels 0-7
    // Scope channel 0-6 was AC channels, and scope channel 7 was the photek
    // 
    // |-----------|             -----
    // | 0 0 0 0 0 |             |777|
    // | 1 1 1 1 1 |             |777|
    // | 2 2 2 2 2 |             -----
    // | 3 3 3 3 3 |
    // | 4 4 4 4 4 |
    // | 5 5 5 5 5 |
    // | 6 6 6 6 6 |
    // |-----------|

    HPK_W5_17_2_203V_94P5attn_StripsGeometry(const int v=0) : voltage(v){}
    const int voltage;
    std::map<int, std::vector<int>> indexToGeometryMap = {{0,{0,0}}, {1,{0,1}}, {2,{0,2}}, {3,{1,0}}};   
    std::vector<std::vector<int>> geometry = {{0,1,2},{3}};
    std::map<int, bool> acLGADChannelMap = {{0,true}, {1,true}, {2,true}, {3,false}};
    std::map<int, double> amplitudeCorrectionFactor = {{0,1.0}, {1,1.0}, {2,1.0},{3,1.0}};
    std::map<int, double> timeCalibrationCorrection = {{0,-46.003261}, {1,-46.167615}, {2,-45.348590}, {3,0.0}};
    // std::map<int, double> timeCalibrationCorrection = {{0,0.0}, {1,0.0}, {2,0.0}, {3,0.0}};
    double stripWidth = 0.050;
    double pitch = 0.500;
    std::vector<double> stripCenterXPosition = {0.5, 0.0, -0.5, 0.0}; // Iter3
    int numLGADchannels = 3;
    int lowGoodStripIndex = 0;
    int highGoodStripIndex = 2;
    double xBinSize = 0.05;
    double yBinSize = 0.1;
    double xmin = -0.80-stripWidth/2; // Sensor's local frame
    double xmax =  0.80+stripWidth/2; // Sensor's local frame
    double ymin = -2.9-stripWidth/2; // Sensor's local frame
    double ymax = 2.9+stripWidth/2; // Sensor's local frame
    double positionRecoMaxPoint = 0.8;
    double noiseAmpThreshold  = 15.0;
    double signalAmpThreshold = 15.0;
    bool enablePositionReconstruction = true;
    int CFD_threshold = 50;
    std::vector<double> positionRecoPar = {0.250000, -0.620309, -0.748820, 5.955054, -21.881453, 27.428734};
    std::vector<std::vector<double>> sensorEdges = {{-0.7, -2.9}, {0.7, 2.9}};//{{-0.7, -4.5}, {0.7, 4.5}}; // Sensor's local frame
    std::vector<std::vector<double>> sensorEdgesTight = {{stripCenterXPosition[highGoodStripIndex], -2.9}, {stripCenterXPosition[lowGoodStripIndex], 2.9}}; // Sensor's local frame
    int centerGoodStripIndex = 1;
    double leftHighGainX = stripCenterXPosition[centerGoodStripIndex] - (stripWidth/2);
    double rightHighGainX = stripCenterXPosition[centerGoodStripIndex] + (stripWidth/2);
    double leftLowGainX = stripCenterXPosition[centerGoodStripIndex] - (pitch/2) - (stripWidth/2);
    double rightLowGainX = stripCenterXPosition[centerGoodStripIndex] - (pitch/2) + (stripWidth/2);
    std::vector<utility::ROI> regionsOfIntrest = {{"highGain", leftHighGainX, rightHighGainX, -2.9, 2.9}, {"lowGain", leftLowGainX, rightLowGainX, -2.9, 2.9}};
};

//done
class HPK_W5_17_2_205V_91P5attn_StripsGeometry : public DefaultGeometry
{
public:
    // 
    // Used lecroy scope channels 0-7
    // Scope channel 0-6 was AC channels, and scope channel 7 was the photek
    // 
    // |-----------|             -----
    // | 0 0 0 0 0 |             |777|
    // | 1 1 1 1 1 |             |777|
    // | 2 2 2 2 2 |             -----
    // | 3 3 3 3 3 |
    // | 4 4 4 4 4 |
    // | 5 5 5 5 5 |
    // | 6 6 6 6 6 |
    // |-----------|

    HPK_W5_17_2_205V_91P5attn_StripsGeometry(const int v=0) : voltage(v){}
    const int voltage;
    std::map<int, std::vector<int>> indexToGeometryMap = {{0,{0,0}}, {1,{0,1}}, {2,{0,2}}, {3,{1,0}}};   
    std::vector<std::vector<int>> geometry = {{0,1,2},{3}};
    std::map<int, bool> acLGADChannelMap = {{0,true}, {1,true}, {2,true}, {3,false}};
    std::map<int, double> amplitudeCorrectionFactor = {{0,1.0}, {1,1.0}, {2,1.0},{3,1.0}};
    std::map<int, double> timeCalibrationCorrection = {{0,-46.095174}, {1,-46.246652}, {2,-45.435811}, {3,0.0}};
    // std::map<int, double> timeCalibrationCorrection = {{0,0.0}, {1,0.0}, {2,0.0}, {3,0.0}};
    double stripWidth = 0.050;
    double pitch = 0.500;
    std::vector<double> stripCenterXPosition = {0.5, 0.0, -0.5, 0.0}; // Iter3
    int numLGADchannels = 3;
    int lowGoodStripIndex = 0;
    int highGoodStripIndex = 2;
    double xBinSize = 0.05;
    double yBinSize = 0.1;
    double xmin = -0.80-stripWidth/2; // Sensor's local frame
    double xmax =  0.80+stripWidth/2; // Sensor's local frame
    double ymin = -2.9-stripWidth/2; // Sensor's local frame
    double ymax = 2.9+stripWidth/2; // Sensor's local frame
    double positionRecoMaxPoint = 0.8;
    double noiseAmpThreshold  = 15.0;
    double signalAmpThreshold = 15.0;
    bool enablePositionReconstruction = true;
    int CFD_threshold = 50;
    std::vector<double> positionRecoPar = {0.250000, -0.648881, 0.021952, -0.752229, 5.363846, -13.994077};
    std::vector<std::vector<double>> sensorEdges = {{-0.7, -2.9}, {0.7, 2.9}};//{{-0.7, -4.5}, {0.7, 4.5}}; // Sensor's local frame
    std::vector<std::vector<double>> sensorEdgesTight = {{stripCenterXPosition[highGoodStripIndex], -2.9}, {stripCenterXPosition[lowGoodStripIndex], 2.9}}; // Sensor's local frame
    int centerGoodStripIndex = 1;
    double leftHighGainX = stripCenterXPosition[centerGoodStripIndex] - (stripWidth/2);
    double rightHighGainX = stripCenterXPosition[centerGoodStripIndex] + (stripWidth/2);
    double leftLowGainX = stripCenterXPosition[centerGoodStripIndex] - (pitch/2) - (stripWidth/2);
    double rightLowGainX = stripCenterXPosition[centerGoodStripIndex] - (pitch/2) + (stripWidth/2);
    std::vector<utility::ROI> regionsOfIntrest = {{"highGain", leftHighGainX, rightHighGainX, -2.9, 2.9}, {"lowGain", leftLowGainX, rightLowGainX, -2.9, 2.9}};
};

//done
class HPK_W5_17_2_205V_92attn_StripsGeometry : public DefaultGeometry
{
public:
    // 
    // Used lecroy scope channels 0-7
    // Scope channel 0-6 was AC channels, and scope channel 7 was the photek
    // 
    // |-----------|             -----
    // | 0 0 0 0 0 |             |777|
    // | 1 1 1 1 1 |             |777|
    // | 2 2 2 2 2 |             -----
    // | 3 3 3 3 3 |
    // | 4 4 4 4 4 |
    // | 5 5 5 5 5 |
    // | 6 6 6 6 6 |
    // |-----------|

    HPK_W5_17_2_205V_92attn_StripsGeometry(const int v=0) : voltage(v){}
    const int voltage;
    std::map<int, std::vector<int>> indexToGeometryMap = {{0,{0,0}}, {1,{0,1}}, {2,{0,2}}, {3,{1,0}}};   
    std::vector<std::vector<int>> geometry = {{0,1,2},{3}};
    std::map<int, bool> acLGADChannelMap = {{0,true}, {1,true}, {2,true}, {3,false}};
    std::map<int, double> amplitudeCorrectionFactor = {{0,1.0}, {1,1.0}, {2,1.0},{3,1.0}};
    std::map<int, double> timeCalibrationCorrection = {{0,-46.074014}, {1,-46.237481}, {2,-45.412666}, {3,0.0}};
    // std::map<int, double> timeCalibrationCorrection = {{0,0.0}, {1,0.0}, {2,0.0}, {3,0.0}};
    double stripWidth = 0.050;
    double pitch = 0.500;
    std::vector<double> stripCenterXPosition = {0.5, 0.0, -0.5, 0.0}; // Iter3
    int numLGADchannels = 3;
    int lowGoodStripIndex = 0;
    int highGoodStripIndex = 2;
    double xBinSize = 0.05;
    double yBinSize = 0.1;
    double xmin = -0.80-stripWidth/2; // Sensor's local frame
    double xmax =  0.80+stripWidth/2; // Sensor's local frame
    double ymin = -2.9-stripWidth/2; // Sensor's local frame
    double ymax = 2.9+stripWidth/2; // Sensor's local frame
    double positionRecoMaxPoint = 0.8;
    double noiseAmpThreshold  = 15.0;
    double signalAmpThreshold = 15.0;
    bool enablePositionReconstruction = true;
    int CFD_threshold = 50;
    std::vector<double> positionRecoPar = {0.250000, -0.649054, 0.070225, -1.582531, 9.493960, -20.628319};
    std::vector<std::vector<double>> sensorEdges = {{-0.7, -2.9}, {0.7, 2.9}};//{{-0.7, -4.5}, {0.7, 4.5}}; // Sensor's local frame
    std::vector<std::vector<double>> sensorEdgesTight = {{stripCenterXPosition[highGoodStripIndex], -2.9}, {stripCenterXPosition[lowGoodStripIndex], 2.9}}; // Sensor's local frame
    int centerGoodStripIndex = 1;
    double leftHighGainX = stripCenterXPosition[centerGoodStripIndex] - (stripWidth/2);
    double rightHighGainX = stripCenterXPosition[centerGoodStripIndex] + (stripWidth/2);
    double leftLowGainX = stripCenterXPosition[centerGoodStripIndex] - (pitch/2) - (stripWidth/2);
    double rightLowGainX = stripCenterXPosition[centerGoodStripIndex] - (pitch/2) + (stripWidth/2);
    std::vector<utility::ROI> regionsOfIntrest = {{"highGain", leftHighGainX, rightHighGainX, -2.9, 2.9}, {"lowGain", leftLowGainX, rightLowGainX, -2.9, 2.9}};
};

//done
class HPK_W5_17_2_205V_92P5attn_StripsGeometry : public DefaultGeometry
{
public:
    // 
    // Used lecroy scope channels 0-7
    // Scope channel 0-6 was AC channels, and scope channel 7 was the photek
    // 
    // |-----------|             -----
    // | 0 0 0 0 0 |             |777|
    // | 1 1 1 1 1 |             |777|
    // | 2 2 2 2 2 |             -----
    // | 3 3 3 3 3 |
    // | 4 4 4 4 4 |
    // | 5 5 5 5 5 |
    // | 6 6 6 6 6 |
    // |-----------|

    HPK_W5_17_2_205V_92P5attn_StripsGeometry(const int v=0) : voltage(v){}
    const int voltage;
    std::map<int, std::vector<int>> indexToGeometryMap = {{0,{0,0}}, {1,{0,1}}, {2,{0,2}}, {3,{1,0}}};   
    std::vector<std::vector<int>> geometry = {{0,1,2},{3}};
    std::map<int, bool> acLGADChannelMap = {{0,true}, {1,true}, {2,true}, {3,false}};
    std::map<int, double> amplitudeCorrectionFactor = {{0,1.0}, {1,1.0}, {2,1.0},{3,1.0}};
    std::map<int, double> timeCalibrationCorrection = {{0,-46.072609}, {1,-46.235897}, {2,-45.410329}, {3,0.0}};
    // std::map<int, double> timeCalibrationCorrection = {{0,0.0}, {1,0.0}, {2,0.0}, {3,0.0}};
    double stripWidth = 0.050;
    double pitch = 0.500;
    std::vector<double> stripCenterXPosition = {0.5, 0.0, -0.5, 0.0}; // Iter3
    int numLGADchannels = 3;
    int lowGoodStripIndex = 0;
    int highGoodStripIndex = 2;
    double xBinSize = 0.05;
    double yBinSize = 0.1;
    double xmin = -0.80-stripWidth/2; // Sensor's local frame
    double xmax =  0.80+stripWidth/2; // Sensor's local frame
    double ymin = -2.9-stripWidth/2; // Sensor's local frame
    double ymax = 2.9+stripWidth/2; // Sensor's local frame
    double positionRecoMaxPoint = 0.8;
    double noiseAmpThreshold  = 15.0;
    double signalAmpThreshold = 15.0;
    bool enablePositionReconstruction = true;
    int CFD_threshold = 50;
    std::vector<double> positionRecoPar = {0.250000, -0.658214, 0.150976, -3.049833, 18.951582, -38.960630};
    std::vector<std::vector<double>> sensorEdges = {{-0.7, -2.9}, {0.7, 2.9}};//{{-0.7, -4.5}, {0.7, 4.5}}; // Sensor's local frame
    std::vector<std::vector<double>> sensorEdgesTight = {{stripCenterXPosition[highGoodStripIndex], -2.9}, {stripCenterXPosition[lowGoodStripIndex], 2.9}}; // Sensor's local frame
    int centerGoodStripIndex = 1;
    double leftHighGainX = stripCenterXPosition[centerGoodStripIndex] - (stripWidth/2);
    double rightHighGainX = stripCenterXPosition[centerGoodStripIndex] + (stripWidth/2);
    double leftLowGainX = stripCenterXPosition[centerGoodStripIndex] - (pitch/2) - (stripWidth/2);
    double rightLowGainX = stripCenterXPosition[centerGoodStripIndex] - (pitch/2) + (stripWidth/2);
    std::vector<utility::ROI> regionsOfIntrest = {{"highGain", leftHighGainX, rightHighGainX, -2.9, 2.9}, {"lowGain", leftLowGainX, rightLowGainX, -2.9, 2.9}};
};

//done
class HPK_W5_17_2_205V_93attn_StripsGeometry : public DefaultGeometry
{
public:
    // 
    // Used lecroy scope channels 0-7
    // Scope channel 0-6 was AC channels, and scope channel 7 was the photek
    // 
    // |-----------|             -----
    // | 0 0 0 0 0 |             |777|
    // | 1 1 1 1 1 |             |777|
    // | 2 2 2 2 2 |             -----
    // | 3 3 3 3 3 |
    // | 4 4 4 4 4 |
    // | 5 5 5 5 5 |
    // | 6 6 6 6 6 |
    // |-----------|

    HPK_W5_17_2_205V_93attn_StripsGeometry(const int v=0) : voltage(v){}
    const int voltage;
    std::map<int, std::vector<int>> indexToGeometryMap = {{0,{0,0}}, {1,{0,1}}, {2,{0,2}}, {3,{1,0}}};   
    std::vector<std::vector<int>> geometry = {{0,1,2},{3}};
    std::map<int, bool> acLGADChannelMap = {{0,true}, {1,true}, {2,true}, {3,false}};
    std::map<int, double> amplitudeCorrectionFactor = {{0,1.0}, {1,1.0}, {2,1.0},{3,1.0}};
    std::map<int, double> timeCalibrationCorrection = {{0,-46.057126}, {1,-46.229171}, {2,-45.397903}, {3,0.0}};
    // std::map<int, double> timeCalibrationCorrection = {{0,0.0}, {1,0.0}, {2,0.0}, {3,0.0}};
    double stripWidth = 0.050;
    double pitch = 0.500;
    std::vector<double> stripCenterXPosition = {0.5, 0.0, -0.5, 0.0}; // Iter3
    int numLGADchannels = 3;
    int lowGoodStripIndex = 0;
    int highGoodStripIndex = 2;
    double xBinSize = 0.05;
    double yBinSize = 0.1;
    double xmin = -0.80-stripWidth/2; // Sensor's local frame
    double xmax =  0.80+stripWidth/2; // Sensor's local frame
    double ymin = -2.9-stripWidth/2; // Sensor's local frame
    double ymax = 2.9+stripWidth/2; // Sensor's local frame
    double positionRecoMaxPoint = 0.8;
    double noiseAmpThreshold  = 15.0;
    double signalAmpThreshold = 15.0;
    bool enablePositionReconstruction = true;
    int CFD_threshold = 50;
    std::vector<double> positionRecoPar = {0.250000, -0.640707, -0.285328, 1.096543, 1.934813, -13.655797};
    std::vector<std::vector<double>> sensorEdges = {{-0.7, -2.9}, {0.7, 2.9}};//{{-0.7, -4.5}, {0.7, 4.5}}; // Sensor's local frame
    std::vector<std::vector<double>> sensorEdgesTight = {{stripCenterXPosition[highGoodStripIndex], -2.9}, {stripCenterXPosition[lowGoodStripIndex], 2.9}}; // Sensor's local frame
    int centerGoodStripIndex = 1;
    double leftHighGainX = stripCenterXPosition[centerGoodStripIndex] - (stripWidth/2);
    double rightHighGainX = stripCenterXPosition[centerGoodStripIndex] + (stripWidth/2);
    double leftLowGainX = stripCenterXPosition[centerGoodStripIndex] - (pitch/2) - (stripWidth/2);
    double rightLowGainX = stripCenterXPosition[centerGoodStripIndex] - (pitch/2) + (stripWidth/2);
    std::vector<utility::ROI> regionsOfIntrest = {{"highGain", leftHighGainX, rightHighGainX, -2.9, 2.9}, {"lowGain", leftLowGainX, rightLowGainX, -2.9, 2.9}};
};

//done
class HPK_W5_17_2_205V_93P5attn_StripsGeometry : public DefaultGeometry
{
public:
    // 
    // Used lecroy scope channels 0-7
    // Scope channel 0-6 was AC channels, and scope channel 7 was the photek
    // 
    // |-----------|             -----
    // | 0 0 0 0 0 |             |777|
    // | 1 1 1 1 1 |             |777|
    // | 2 2 2 2 2 |             -----
    // | 3 3 3 3 3 |
    // | 4 4 4 4 4 |
    // | 5 5 5 5 5 |
    // | 6 6 6 6 6 |
    // |-----------|

    HPK_W5_17_2_205V_93P5attn_StripsGeometry(const int v=0) : voltage(v){}
    const int voltage;
    std::map<int, std::vector<int>> indexToGeometryMap = {{0,{0,0}}, {1,{0,1}}, {2,{0,2}}, {3,{1,0}}};   
    std::vector<std::vector<int>> geometry = {{0,1,2},{3}};
    std::map<int, bool> acLGADChannelMap = {{0,true}, {1,true}, {2,true}, {3,false}};
    std::map<int, double> amplitudeCorrectionFactor = {{0,1.0}, {1,1.0}, {2,1.0},{3,1.0}};
    std::map<int, double> timeCalibrationCorrection = {{0,-46.046249}, {1,-46.219624}, {2,-45.384986}, {3,0.0}};
    // std::map<int, double> timeCalibrationCorrection = {{0,0.0}, {1,0.0}, {2,0.0}, {3,0.0}};
    double stripWidth = 0.050;
    double pitch = 0.500;
    std::vector<double> stripCenterXPosition = {0.5, 0.0, -0.5, 0.0}; // Iter3
    int numLGADchannels = 3;
    int lowGoodStripIndex = 0;
    int highGoodStripIndex = 2;
    double xBinSize = 0.05;
    double yBinSize = 0.1;
    double xmin = -0.80-stripWidth/2; // Sensor's local frame
    double xmax =  0.80+stripWidth/2; // Sensor's local frame
    double ymin = -2.9-stripWidth/2; // Sensor's local frame
    double ymax = 2.9+stripWidth/2; // Sensor's local frame
    double positionRecoMaxPoint = 0.8;
    double noiseAmpThreshold  = 15.0;
    double signalAmpThreshold = 15.0;
    bool enablePositionReconstruction = true;
    int CFD_threshold = 50;
    std::vector<double> positionRecoPar = {0.250000, -0.651665, 0.162069, -3.169949, 16.910074, -31.713908};
    std::vector<std::vector<double>> sensorEdges = {{-0.7, -2.9}, {0.7, 2.9}};//{{-0.7, -4.5}, {0.7, 4.5}}; // Sensor's local frame
    std::vector<std::vector<double>> sensorEdgesTight = {{stripCenterXPosition[highGoodStripIndex], -2.9}, {stripCenterXPosition[lowGoodStripIndex], 2.9}}; // Sensor's local frame
    int centerGoodStripIndex = 1;
    double leftHighGainX = stripCenterXPosition[centerGoodStripIndex] - (stripWidth/2);
    double rightHighGainX = stripCenterXPosition[centerGoodStripIndex] + (stripWidth/2);
    double leftLowGainX = stripCenterXPosition[centerGoodStripIndex] - (pitch/2) - (stripWidth/2);
    double rightLowGainX = stripCenterXPosition[centerGoodStripIndex] - (pitch/2) + (stripWidth/2);
    std::vector<utility::ROI> regionsOfIntrest = {{"highGain", leftHighGainX, rightHighGainX, -2.9, 2.9}, {"lowGain", leftLowGainX, rightLowGainX, -2.9, 2.9}};
};

//done
class HPK_W5_17_2_205V_94attn_StripsGeometry : public DefaultGeometry
{
public:
    // 
    // Used lecroy scope channels 0-7
    // Scope channel 0-6 was AC channels, and scope channel 7 was the photek
    // 
    // |-----------|             -----
    // | 0 0 0 0 0 |             |777|
    // | 1 1 1 1 1 |             |777|
    // | 2 2 2 2 2 |             -----
    // | 3 3 3 3 3 |
    // | 4 4 4 4 4 |
    // | 5 5 5 5 5 |
    // | 6 6 6 6 6 |
    // |-----------|

    HPK_W5_17_2_205V_94attn_StripsGeometry(const int v=0) : voltage(v){}
    const int voltage;
    std::map<int, std::vector<int>> indexToGeometryMap = {{0,{0,0}}, {1,{0,1}}, {2,{0,2}}, {3,{1,0}}};   
    std::vector<std::vector<int>> geometry = {{0,1,2},{3}};
    std::map<int, bool> acLGADChannelMap = {{0,true}, {1,true}, {2,true}, {3,false}};
    std::map<int, double> amplitudeCorrectionFactor = {{0,1.0}, {1,1.0}, {2,1.0},{3,1.0}};
    std::map<int, double> timeCalibrationCorrection = {{0,-46.031910}, {1,-46.205258}, {2,-45.372926}, {3,0.0}};
    // std::map<int, double> timeCalibrationCorrection = {{0,0.0}, {1,0.0}, {2,0.0}, {3,0.0}};
    double stripWidth = 0.050;
    double pitch = 0.500;
    std::vector<double> stripCenterXPosition = {0.5, 0.0, -0.5, 0.0}; // Iter3
    int numLGADchannels = 3;
    int lowGoodStripIndex = 0;
    int highGoodStripIndex = 2;
    double xBinSize = 0.05;
    double yBinSize = 0.1;
    double xmin = -0.80-stripWidth/2; // Sensor's local frame
    double xmax =  0.80+stripWidth/2; // Sensor's local frame
    double ymin = -2.9-stripWidth/2; // Sensor's local frame
    double ymax = 2.9+stripWidth/2; // Sensor's local frame
    double positionRecoMaxPoint = 0.8;
    double noiseAmpThreshold  = 15.0;
    double signalAmpThreshold = 15.0;
    bool enablePositionReconstruction = true;
    int CFD_threshold = 50;
    std::vector<double> positionRecoPar = {0.250000, -0.640232, -0.166140, 0.233647, 2.478833, -10.546522};
    std::vector<std::vector<double>> sensorEdges = {{-0.7, -2.9}, {0.7, 2.9}};//{{-0.7, -4.5}, {0.7, 4.5}}; // Sensor's local frame
    std::vector<std::vector<double>> sensorEdgesTight = {{stripCenterXPosition[highGoodStripIndex], -2.9}, {stripCenterXPosition[lowGoodStripIndex], 2.9}}; // Sensor's local frame
    double offset = stripWidth;
    int centerGoodStripIndex = 1;
    double centerStripX = stripCenterXPosition[centerGoodStripIndex];
    double leftGapX = centerStripX - (pitch/2);
	double rightGapX = centerStripX + (pitch/2);
	std::vector<utility::ROI> regionsOfIntrest = {{"nearStripX", centerStripX + offset - stripWidth/2, centerStripX + offset + stripWidth/2, -2.5,2.5}, {"leftGapX", leftGapX - stripWidth/2, leftGapX + stripWidth/2, -2.5,2.5}, {"rightGapX", rightGapX - stripWidth/2, rightGapX + stripWidth/2, -2.5,2.5}};
};

//done
class HPK_W5_17_2_205V_94P5attn_StripsGeometry : public DefaultGeometry
{
public:
    // 
    // Used lecroy scope channels 0-7
    // Scope channel 0-6 was AC channels, and scope channel 7 was the photek
    // 
    // |-----------|             -----
    // | 0 0 0 0 0 |             |777|
    // | 1 1 1 1 1 |             |777|
    // | 2 2 2 2 2 |             -----
    // | 3 3 3 3 3 |
    // | 4 4 4 4 4 |
    // | 5 5 5 5 5 |
    // | 6 6 6 6 6 |
    // |-----------|

    HPK_W5_17_2_205V_94P5attn_StripsGeometry(const int v=0) : voltage(v){}
    const int voltage;
    std::map<int, std::vector<int>> indexToGeometryMap = {{0,{0,0}}, {1,{0,1}}, {2,{0,2}}, {3,{1,0}}};   
    std::vector<std::vector<int>> geometry = {{0,1,2},{3}};
    std::map<int, bool> acLGADChannelMap = {{0,true}, {1,true}, {2,true}, {3,false}};
    std::map<int, double> amplitudeCorrectionFactor = {{0,1.0}, {1,1.0}, {2,1.0},{3,1.0}};
    std::map<int, double> timeCalibrationCorrection = {{0,-46.024336}, {1,-46.194764}, {2,-45.364236}, {3,0.0}};
    // std::map<int, double> timeCalibrationCorrection = {{0,0.0}, {1,0.0}, {2,0.0}, {3,0.0}};
    double stripWidth = 0.050;
    double pitch = 0.500;
    std::vector<double> stripCenterXPosition = {0.5, 0.0, -0.5, 0.0}; // Iter3
    int numLGADchannels = 3;
    int lowGoodStripIndex = 0;
    int highGoodStripIndex = 2;
    double xBinSize = 0.05;
    double yBinSize = 0.1;
    double xmin = -0.80-stripWidth/2; // Sensor's local frame
    double xmax =  0.80+stripWidth/2; // Sensor's local frame
    double ymin = -2.9-stripWidth/2; // Sensor's local frame
    double ymax = 2.9+stripWidth/2; // Sensor's local frame
    double positionRecoMaxPoint = 0.8;
    double noiseAmpThreshold  = 15.0;
    double signalAmpThreshold = 15.0;
    bool enablePositionReconstruction = true;
    int CFD_threshold = 50;
    std::vector<double> positionRecoPar = {0.250000, -0.634354, -0.451113, 3.177398, -9.442413, 6.130750};
    std::vector<std::vector<double>> sensorEdges = {{-0.7, -2.9}, {0.7, 2.9}};//{{-0.7, -4.5}, {0.7, 4.5}}; // Sensor's local frame
    std::vector<std::vector<double>> sensorEdgesTight = {{stripCenterXPosition[highGoodStripIndex], -2.9}, {stripCenterXPosition[lowGoodStripIndex], 2.9}}; // Sensor's local frame
    int centerGoodStripIndex = 1;
    double leftHighGainX = stripCenterXPosition[centerGoodStripIndex] - (stripWidth/2);
    double rightHighGainX = stripCenterXPosition[centerGoodStripIndex] + (stripWidth/2);
    double leftLowGainX = stripCenterXPosition[centerGoodStripIndex] - (pitch/2) - (stripWidth/2);
    double rightLowGainX = stripCenterXPosition[centerGoodStripIndex] - (pitch/2) + (stripWidth/2);
    std::vector<utility::ROI> regionsOfIntrest = {{"highGain", leftHighGainX, rightHighGainX, -2.9, 2.9}, {"lowGain", leftLowGainX, rightLowGainX, -2.9, 2.9}};
};

//done
class HPK_W5_17_2_207V_91P5attn_StripsGeometry : public DefaultGeometry
{
public:
    // 
    // Used lecroy scope channels 0-7
    // Scope channel 0-6 was AC channels, and scope channel 7 was the photek
    // 
    // |-----------|             -----
    // | 0 0 0 0 0 |             |777|
    // | 1 1 1 1 1 |             |777|
    // | 2 2 2 2 2 |             -----
    // | 3 3 3 3 3 |
    // | 4 4 4 4 4 |
    // | 5 5 5 5 5 |
    // | 6 6 6 6 6 |
    // |-----------|

    HPK_W5_17_2_207V_91P5attn_StripsGeometry(const int v=0) : voltage(v){}
    const int voltage;
    std::map<int, std::vector<int>> indexToGeometryMap = {{0,{0,0}}, {1,{0,1}}, {2,{0,2}}, {3,{1,0}}};   
    std::vector<std::vector<int>> geometry = {{0,1,2},{3}};
    std::map<int, bool> acLGADChannelMap = {{0,true}, {1,true}, {2,true}, {3,false}};
    std::map<int, double> amplitudeCorrectionFactor = {{0,1.0}, {1,1.0}, {2,1.0},{3,1.0}};
    std::map<int, double> timeCalibrationCorrection = {{0,-46.117644}, {1,-46.242801}, {2,-45.457294}, {3,0.0}};
    // std::map<int, double> timeCalibrationCorrection = {{0,0.0}, {1,0.0}, {2,0.0}, {3,0.0}};
    double stripWidth = 0.050;
    double pitch = 0.500;
    std::vector<double> stripCenterXPosition = {0.5, 0.0, -0.5, 0.0}; // Iter3
    int numLGADchannels = 3;
    int lowGoodStripIndex = 0;
    int highGoodStripIndex = 2;
    double xBinSize = 0.05;
    double yBinSize = 0.1;
    double xmin = -0.80-stripWidth/2; // Sensor's local frame
    double xmax =  0.80+stripWidth/2; // Sensor's local frame
    double ymin = -2.9-stripWidth/2; // Sensor's local frame
    double ymax = 2.9+stripWidth/2; // Sensor's local frame
    double positionRecoMaxPoint = 0.8;
    double noiseAmpThreshold  = 15.0;
    double signalAmpThreshold = 15.0;
    bool enablePositionReconstruction = true;
    int CFD_threshold = 50;
    std::vector<double> positionRecoPar = {0.250000, -0.652975, 0.198757, -3.027026, 15.217532, -27.512544};
    std::vector<std::vector<double>> sensorEdges = {{-0.7, -2.9}, {0.7, 2.9}};//{{-0.7, -4.5}, {0.7, 4.5}}; // Sensor's local frame
    std::vector<std::vector<double>> sensorEdgesTight = {{stripCenterXPosition[highGoodStripIndex], -2.9}, {stripCenterXPosition[lowGoodStripIndex], 2.9}}; // Sensor's local frame
    int centerGoodStripIndex = 1;
    double leftHighGainX = stripCenterXPosition[centerGoodStripIndex] - (stripWidth/2);
    double rightHighGainX = stripCenterXPosition[centerGoodStripIndex] + (stripWidth/2);
    double leftLowGainX = stripCenterXPosition[centerGoodStripIndex] - (pitch/2) - (stripWidth/2);
    double rightLowGainX = stripCenterXPosition[centerGoodStripIndex] - (pitch/2) + (stripWidth/2);
    std::vector<utility::ROI> regionsOfIntrest = {{"highGain", leftHighGainX, rightHighGainX, -2.9, 2.9}, {"lowGain", leftLowGainX, rightLowGainX, -2.9, 2.9}};
};

//done
class HPK_W5_17_2_207V_92attn_StripsGeometry : public DefaultGeometry
{
public:
    // 
    // Used lecroy scope channels 0-7
    // Scope channel 0-6 was AC channels, and scope channel 7 was the photek
    // 
    // |-----------|             -----
    // | 0 0 0 0 0 |             |777|
    // | 1 1 1 1 1 |             |777|
    // | 2 2 2 2 2 |             -----
    // | 3 3 3 3 3 |
    // | 4 4 4 4 4 |
    // | 5 5 5 5 5 |
    // | 6 6 6 6 6 |
    // |-----------|

    HPK_W5_17_2_207V_92attn_StripsGeometry(const int v=0) : voltage(v){}
    const int voltage;
    std::map<int, std::vector<int>> indexToGeometryMap = {{0,{0,0}}, {1,{0,1}}, {2,{0,2}}, {3,{1,0}}};   
    std::vector<std::vector<int>> geometry = {{0,1,2},{3}};
    std::map<int, bool> acLGADChannelMap = {{0,true}, {1,true}, {2,true}, {3,false}};
    std::map<int, double> amplitudeCorrectionFactor = {{0,1.0}, {1,1.0}, {2,1.0},{3,1.0}};
    std::map<int, double> timeCalibrationCorrection = {{0,-46.105524}, {1,-46.252425}, {2,-45.444149}, {3,0.0}};
    // std::map<int, double> timeCalibrationCorrection = {{0,0.0}, {1,0.0}, {2,0.0}, {3,0.0}};
    double stripWidth = 0.050;
    double pitch = 0.500;
    std::vector<double> stripCenterXPosition = {0.5, 0.0, -0.5, 0.0}; // Iter3
    int numLGADchannels = 3;
    int lowGoodStripIndex = 0;
    int highGoodStripIndex = 2;
    double xBinSize = 0.05;
    double yBinSize = 0.1;
    double xmin = -0.80-stripWidth/2; // Sensor's local frame
    double xmax =  0.80+stripWidth/2; // Sensor's local frame
    double ymin = -2.9-stripWidth/2; // Sensor's local frame
    double ymax = 2.9+stripWidth/2; // Sensor's local frame
    double positionRecoMaxPoint = 0.8;
    double noiseAmpThreshold  = 15.0;
    double signalAmpThreshold = 15.0;
    bool enablePositionReconstruction = true;
    int CFD_threshold = 50;
    std::vector<double> positionRecoPar = {0.250000, -0.657220, 0.321317, -4.417842, 21.965400, -38.915772};
    std::vector<std::vector<double>> sensorEdges = {{-0.7, -2.9}, {0.7, 2.9}};//{{-0.7, -4.5}, {0.7, 4.5}}; // Sensor's local frame
    std::vector<std::vector<double>> sensorEdgesTight = {{stripCenterXPosition[highGoodStripIndex], -2.9}, {stripCenterXPosition[lowGoodStripIndex], 2.9}}; // Sensor's local frame
    int centerGoodStripIndex = 1;
    double leftHighGainX = stripCenterXPosition[centerGoodStripIndex] - (stripWidth/2);
    double rightHighGainX = stripCenterXPosition[centerGoodStripIndex] + (stripWidth/2);
    double leftLowGainX = stripCenterXPosition[centerGoodStripIndex] - (pitch/2) - (stripWidth/2);
    double rightLowGainX = stripCenterXPosition[centerGoodStripIndex] - (pitch/2) + (stripWidth/2);
    std::vector<utility::ROI> regionsOfIntrest = {{"highGain", leftHighGainX, rightHighGainX, -2.9, 2.9}, {"lowGain", leftLowGainX, rightLowGainX, -2.9, 2.9}};
};

//done
class HPK_W5_17_2_207V_92P5attn_StripsGeometry : public DefaultGeometry
{
public:
    // 
    // Used lecroy scope channels 0-7
    // Scope channel 0-6 was AC channels, and scope channel 7 was the photek
    // 
    // |-----------|             -----
    // | 0 0 0 0 0 |             |777|
    // | 1 1 1 1 1 |             |777|
    // | 2 2 2 2 2 |             -----
    // | 3 3 3 3 3 |
    // | 4 4 4 4 4 |
    // | 5 5 5 5 5 |
    // | 6 6 6 6 6 |
    // |-----------|

    HPK_W5_17_2_207V_92P5attn_StripsGeometry(const int v=0) : voltage(v){}
    const int voltage;
    std::map<int, std::vector<int>> indexToGeometryMap = {{0,{0,0}}, {1,{0,1}}, {2,{0,2}}, {3,{1,0}}};   
    std::vector<std::vector<int>> geometry = {{0,1,2},{3}};
    std::map<int, bool> acLGADChannelMap = {{0,true}, {1,true}, {2,true}, {3,false}};
    std::map<int, double> amplitudeCorrectionFactor = {{0,1.0}, {1,1.0}, {2,1.0},{3,1.0}};
    std::map<int, double> timeCalibrationCorrection = {{0,-46.085940}, {1,-46.245177}, {2,-45.423845}, {3,0.0}};
    // std::map<int, double> timeCalibrationCorrection = {{0,0.0}, {1,0.0}, {2,0.0}, {3,0.0}};
    double stripWidth = 0.050;
    double pitch = 0.500;
    std::vector<double> stripCenterXPosition = {0.5, 0.0, -0.5, 0.0}; // Iter3
    int numLGADchannels = 3;
    int lowGoodStripIndex = 0;
    int highGoodStripIndex = 2;
    double xBinSize = 0.05;
    double yBinSize = 0.1;
    double xmin = -0.80-stripWidth/2; // Sensor's local frame
    double xmax =  0.80+stripWidth/2; // Sensor's local frame
    double ymin = -2.9-stripWidth/2; // Sensor's local frame
    double ymax = 2.9+stripWidth/2; // Sensor's local frame
    double positionRecoMaxPoint = 0.8;
    double noiseAmpThreshold  = 15.0;
    double signalAmpThreshold = 15.0;
    bool enablePositionReconstruction = true;
    int CFD_threshold = 50;
    std::vector<double> positionRecoPar = {0.250000, -0.652585, 0.232474, -3.911244, 21.059082, -39.134378};
    std::vector<std::vector<double>> sensorEdges = {{-0.7, -2.9}, {0.7, 2.9}};//{{-0.7, -4.5}, {0.7, 4.5}}; // Sensor's local frame
    std::vector<std::vector<double>> sensorEdgesTight = {{stripCenterXPosition[highGoodStripIndex], -2.9}, {stripCenterXPosition[lowGoodStripIndex], 2.9}}; // Sensor's local frame
    int centerGoodStripIndex = 1;
    double leftHighGainX = stripCenterXPosition[centerGoodStripIndex] - (stripWidth/2);
    double rightHighGainX = stripCenterXPosition[centerGoodStripIndex] + (stripWidth/2);
    double leftLowGainX = stripCenterXPosition[centerGoodStripIndex] - (pitch/2) - (stripWidth/2);
    double rightLowGainX = stripCenterXPosition[centerGoodStripIndex] - (pitch/2) + (stripWidth/2);
    std::vector<utility::ROI> regionsOfIntrest = {{"highGain", leftHighGainX, rightHighGainX, -2.9, 2.9}, {"lowGain", leftLowGainX, rightLowGainX, -2.9, 2.9}};
};

//done
class HPK_W5_17_2_207V_93attn_StripsGeometry : public DefaultGeometry
{
public:
    // 
    // Used lecroy scope channels 0-7
    // Scope channel 0-6 was AC channels, and scope channel 7 was the photek
    // 
    // |-----------|             -----
    // | 0 0 0 0 0 |             |777|
    // | 1 1 1 1 1 |             |777|
    // | 2 2 2 2 2 |             -----
    // | 3 3 3 3 3 |
    // | 4 4 4 4 4 |
    // | 5 5 5 5 5 |
    // | 6 6 6 6 6 |
    // |-----------|

    HPK_W5_17_2_207V_93attn_StripsGeometry(const int v=0) : voltage(v){}
    const int voltage;
    std::map<int, std::vector<int>> indexToGeometryMap = {{0,{0,0}}, {1,{0,1}}, {2,{0,2}}, {3,{1,0}}};   
    std::vector<std::vector<int>> geometry = {{0,1,2},{3}};
    std::map<int, bool> acLGADChannelMap = {{0,true}, {1,true}, {2,true}, {3,false}};
    std::map<int, double> amplitudeCorrectionFactor = {{0,1.0}, {1,1.0}, {2,1.0},{3,1.0}};
    std::map<int, double> timeCalibrationCorrection = {{0,-46.091380}, {1,-46.249149}, {2,-45.427833}, {3,0.0}};
    // std::map<int, double> timeCalibrationCorrection = {{0,0.0}, {1,0.0}, {2,0.0}, {3,0.0}};
    double stripWidth = 0.050;
    double pitch = 0.500;
    std::vector<double> stripCenterXPosition = {0.5, 0.0, -0.5, 0.0}; // Iter3
    int numLGADchannels = 3;
    int lowGoodStripIndex = 0;
    int highGoodStripIndex = 2;
    double xBinSize = 0.05;
    double yBinSize = 0.1;
    double xmin = -0.80-stripWidth/2; // Sensor's local frame
    double xmax =  0.80+stripWidth/2; // Sensor's local frame
    double ymin = -2.9-stripWidth/2; // Sensor's local frame
    double ymax = 2.9+stripWidth/2; // Sensor's local frame
    double positionRecoMaxPoint = 0.8;
    double noiseAmpThreshold  = 15.0;
    double signalAmpThreshold = 15.0;
    bool enablePositionReconstruction = true;
    int CFD_threshold = 50;
    std::vector<double> positionRecoPar = {0.250000, -0.674070, 0.558224, -6.805405, 33.154666, -57.964838};
    std::vector<std::vector<double>> sensorEdges = {{-0.7, -2.9}, {0.7, 2.9}};//{{-0.7, -4.5}, {0.7, 4.5}}; // Sensor's local frame
    std::vector<std::vector<double>> sensorEdgesTight = {{stripCenterXPosition[highGoodStripIndex], -2.9}, {stripCenterXPosition[lowGoodStripIndex], 2.9}}; // Sensor's local frame
    int centerGoodStripIndex = 1;
    double leftHighGainX = stripCenterXPosition[centerGoodStripIndex] - (stripWidth/2);
    double rightHighGainX = stripCenterXPosition[centerGoodStripIndex] + (stripWidth/2);
    double leftLowGainX = stripCenterXPosition[centerGoodStripIndex] - (pitch/2) - (stripWidth/2);
    double rightLowGainX = stripCenterXPosition[centerGoodStripIndex] - (pitch/2) + (stripWidth/2);
    std::vector<utility::ROI> regionsOfIntrest = {{"highGain", leftHighGainX, rightHighGainX, -2.9, 2.9}, {"lowGain", leftLowGainX, rightLowGainX, -2.9, 2.9}};
};

//done
class HPK_W5_17_2_207V_93P5attn_StripsGeometry : public DefaultGeometry
{
public:
    // 
    // Used lecroy scope channels 0-7
    // Scope channel 0-6 was AC channels, and scope channel 7 was the photek
    // 
    // |-----------|             -----
    // | 0 0 0 0 0 |             |777|
    // | 1 1 1 1 1 |             |777|
    // | 2 2 2 2 2 |             -----
    // | 3 3 3 3 3 |
    // | 4 4 4 4 4 |
    // | 5 5 5 5 5 |
    // | 6 6 6 6 6 |
    // |-----------|

    HPK_W5_17_2_207V_93P5attn_StripsGeometry(const int v=0) : voltage(v){}
    const int voltage;
    std::map<int, std::vector<int>> indexToGeometryMap = {{0,{0,0}}, {1,{0,1}}, {2,{0,2}}, {3,{1,0}}};   
    std::vector<std::vector<int>> geometry = {{0,1,2},{3}};
    std::map<int, bool> acLGADChannelMap = {{0,true}, {1,true}, {2,true}, {3,false}};
    std::map<int, double> amplitudeCorrectionFactor = {{0,1.0}, {1,1.0}, {2,1.0},{3,1.0}};
    std::map<int, double> timeCalibrationCorrection = {{0,-46.080898}, {1,-46.246493}, {2,-45.415655}, {3,0.0}};
    // std::map<int, double> timeCalibrationCorrection = {{0,0.0}, {1,0.0}, {2,0.0}, {3,0.0}};
    double stripWidth = 0.050;
    double pitch = 0.500;
    std::vector<double> stripCenterXPosition = {0.5, 0.0, -0.5, 0.0}; // Iter3
    int numLGADchannels = 3;
    int lowGoodStripIndex = 0;
    int highGoodStripIndex = 2;
    double xBinSize = 0.05;
    double yBinSize = 0.1;
    double xmin = -0.80-stripWidth/2; // Sensor's local frame
    double xmax =  0.80+stripWidth/2; // Sensor's local frame
    double ymin = -2.9-stripWidth/2; // Sensor's local frame
    double ymax = 2.9+stripWidth/2; // Sensor's local frame
    double positionRecoMaxPoint = 0.8;
    double noiseAmpThreshold  = 15.0;
    double signalAmpThreshold = 15.0;
    bool enablePositionReconstruction = true;
    int CFD_threshold = 50;
    std::vector<double> positionRecoPar = {0.250000, -0.643004, -0.301374, 1.212123, 2.274019, -15.654314};
    std::vector<std::vector<double>> sensorEdges = {{-0.7, -2.9}, {0.7, 2.9}};//{{-0.7, -4.5}, {0.7, 4.5}}; // Sensor's local frame
    std::vector<std::vector<double>> sensorEdgesTight = {{stripCenterXPosition[highGoodStripIndex], -2.9}, {stripCenterXPosition[lowGoodStripIndex], 2.9}}; // Sensor's local frame
    int centerGoodStripIndex = 1;
    double leftHighGainX = stripCenterXPosition[centerGoodStripIndex] - (stripWidth/2);
    double rightHighGainX = stripCenterXPosition[centerGoodStripIndex] + (stripWidth/2);
    double leftLowGainX = stripCenterXPosition[centerGoodStripIndex] - (pitch/2) - (stripWidth/2);
    double rightLowGainX = stripCenterXPosition[centerGoodStripIndex] - (pitch/2) + (stripWidth/2);
    std::vector<utility::ROI> regionsOfIntrest = {{"highGain", leftHighGainX, rightHighGainX, -2.9, 2.9}, {"lowGain", leftLowGainX, rightLowGainX, -2.9, 2.9}};
};

//done
class HPK_W5_17_2_207V_94attn_StripsGeometry : public DefaultGeometry
{
public:
    // Used lecroy scope channels 0-7
    // Scope channel 0-6 was AC channels, and scope channel 7 was the photek
    // 
    // |-----------|             -----
    // | 0 0 0 0 0 |             |777|
    // | 1 1 1 1 1 |             |777|
    // | 2 2 2 2 2 |             -----
    // | 3 3 3 3 3 |
    // | 4 4 4 4 4 |
    // | 5 5 5 5 5 |
    // | 6 6 6 6 6 |
    // |-----------|

    HPK_W5_17_2_207V_94attn_StripsGeometry(const int v=0) : voltage(v){}
    const int voltage;
    std::map<int, std::vector<int>> indexToGeometryMap = {{0,{0,0}}, {1,{0,1}}, {2,{0,2}}, {3,{1,0}}};   
    std::vector<std::vector<int>> geometry = {{0,1,2},{3}};
    std::map<int, bool> acLGADChannelMap = {{0,true}, {1,true}, {2,true}, {3,false}};
    std::map<int, double> amplitudeCorrectionFactor = {{0,1.0}, {1,1.0}, {2,1.0},{3,1.0}};
    std::map<int, double> timeCalibrationCorrection = {{0,-46.070543}, {1,-46.241223}, {2,-45.405999}, {3,0.0}};
    // std::map<int, double> timeCalibrationCorrection = {{0,0.0}, {1,0.0}, {2,0.0}, {3,0.0}};
    double stripWidth = 0.050;
    double pitch = 0.500;
    std::vector<double> stripCenterXPosition = {0.5, 0.0, -0.5, 0.0}; // Iter3
    int numLGADchannels = 3;
    int lowGoodStripIndex = 0;
    int highGoodStripIndex = 2;
    double xBinSize = 0.05;
    double yBinSize = 0.1;
    double xmin = -0.80-stripWidth/2; // Sensor's local frame
    double xmax =  0.80+stripWidth/2; // Sensor's local frame
    double ymin = -2.9-stripWidth/2; // Sensor's local frame
    double ymax = 2.9+stripWidth/2; // Sensor's local frame
    double positionRecoMaxPoint = 0.8;
    double noiseAmpThreshold  = 15.0;
    double signalAmpThreshold = 15.0;
    bool enablePositionReconstruction = true;
    int CFD_threshold = 50;
    std::vector<double> positionRecoPar = {0.250000, -0.651142, -0.044405, -0.680307, 6.901751, -18.230262};
    std::vector<std::vector<double>> sensorEdges = {{-0.7, -2.9}, {0.7, 2.9}};//{{-0.7, -4.5}, {0.7, 4.5}}; // Sensor's local frame
    std::vector<std::vector<double>> sensorEdgesTight = {{stripCenterXPosition[highGoodStripIndex], -2.9}, {stripCenterXPosition[lowGoodStripIndex], 2.9}}; // Sensor's local frame
    int centerGoodStripIndex = 1;
    double leftHighGainX = stripCenterXPosition[centerGoodStripIndex] - (stripWidth/2);
    double rightHighGainX = stripCenterXPosition[centerGoodStripIndex] + (stripWidth/2);
    double leftLowGainX = stripCenterXPosition[centerGoodStripIndex] - (pitch/2) - (stripWidth/2);
    double rightLowGainX = stripCenterXPosition[centerGoodStripIndex] - (pitch/2) + (stripWidth/2);
    std::vector<utility::ROI> regionsOfIntrest = {{"highGain", leftHighGainX, rightHighGainX, -2.9, 2.9}, {"lowGain", leftLowGainX, rightLowGainX, -2.9, 2.9}};

};

/*
class HPK_W5_17_2_207V_94attn_run2_StripsGeometry : public DefaultGeometry
{
public:
    // Used lecroy scope channels 0-7
    // Scope channel 0-6 was AC channels, and scope channel 7 was the photek
    // 
    // |-----------|             -----
    // | 0 0 0 0 0 |             |777|
    // | 1 1 1 1 1 |             |777|
    // | 2 2 2 2 2 |             -----
    // | 3 3 3 3 3 |
    // | 4 4 4 4 4 |
    // | 5 5 5 5 5 |
    // | 6 6 6 6 6 |
    // |-----------|

    HPK_W5_17_2_207V_94attn_run2_StripsGeometry(const int v=0) : voltage(v){}
    const int voltage;
    std::map<int, std::vector<int>> indexToGeometryMap = {{0,{0,0}}, {1,{0,1}}, {2,{0,2}}, {3,{1,0}}};   
    std::vector<std::vector<int>> geometry = {{0,1,2},{3}};
    std::map<int, bool> acLGADChannelMap = {{0,true}, {1,true}, {2,true}, {3,false}};
    std::map<int, double> amplitudeCorrectionFactor = {{0,1.0}, {1,1.0}, {2,1.0},{3,1.0}};
    // std::map<int, double> timeCalibrationCorrection = {{0,-46.033607}, {1,-46.209223}, {2,-45.371753}, {3,0.0}};
    std::map<int, double> timeCalibrationCorrection = {{0,0.0}, {1,0.0}, {2,0.0}, {3,0.0}};
    double stripWidth = 0.050;
    double pitch = 0.500;
    std::vector<double> stripCenterXPosition = {0.5, 0.0, -0.5, 0.0}; // Iter3
    int numLGADchannels = 3;
    int lowGoodStripIndex = 0;
    int highGoodStripIndex = 2;
    double xBinSize = 0.05;
    double yBinSize = 0.1;
    double xmin = -0.80-stripWidth/2; // Sensor's local frame
    double xmax =  0.80+stripWidth/2; // Sensor's local frame
    double ymin = -2.9-stripWidth/2; // Sensor's local frame
    double ymax = 2.9+stripWidth/2; // Sensor's local frame
    double positionRecoMaxPoint = 0.8;
    double noiseAmpThreshold  = 15.0;
    double signalAmpThreshold = 15.0;
    bool enablePositionReconstruction = true;
    int CFD_threshold = 50;
    std::vector<double> positionRecoPar = {0.250000, -0.639939, -0.330629, 2.461978, -7.247526, 3.503195};
    std::vector<std::vector<double>> sensorEdges = {{-0.7, -2.9}, {0.7, 2.9}};//{{-0.7, -4.5}, {0.7, 4.5}}; // Sensor's local frame
    std::vector<std::vector<double>> sensorEdgesTight = {{stripCenterXPosition[highGoodStripIndex], -2.9}, {stripCenterXPosition[lowGoodStripIndex], 2.9}}; // Sensor's local frame
    int centerGoodStripIndex = 1;
    double leftHighGainX = stripCenterXPosition[centerGoodStripIndex] - (stripWidth/2);
    double rightHighGainX = stripCenterXPosition[centerGoodStripIndex] + (stripWidth/2);
    double leftLowGainX = stripCenterXPosition[centerGoodStripIndex] - (pitch/2) - (stripWidth/2);
    double rightLowGainX = stripCenterXPosition[centerGoodStripIndex] - (pitch/2) + (stripWidth/2);
    std::vector<utility::ROI> regionsOfIntrest = {{"highGain", leftHighGainX, rightHighGainX, -2.9, 2.9}, {"lowGain", leftLowGainX, rightLowGainX, -2.9, 2.9}};

};


class HPK_W5_17_2_207V_94attn_run2_65scale_StripsGeometry : public DefaultGeometry
{
public:
    // Used lecroy scope channels 0-7
    // Scope channel 0-6 was AC channels, and scope channel 7 was the photek
    // 
    // |-----------|             -----
    // | 0 0 0 0 0 |             |777|
    // | 1 1 1 1 1 |             |777|
    // | 2 2 2 2 2 |             -----
    // | 3 3 3 3 3 |
    // | 4 4 4 4 4 |
    // | 5 5 5 5 5 |
    // | 6 6 6 6 6 |
    // |-----------|

    HPK_W5_17_2_207V_94attn_run2_65scale_StripsGeometry(const int v=0) : voltage(v){}
    const int voltage;
    std::map<int, std::vector<int>> indexToGeometryMap = {{0,{0,0}}, {1,{0,1}}, {2,{0,2}}, {3,{1,0}}};   
    std::vector<std::vector<int>> geometry = {{0,1,2},{3}};
    std::map<int, bool> acLGADChannelMap = {{0,true}, {1,true}, {2,true}, {3,false}};
    std::map<int, double> amplitudeCorrectionFactor = {{0,1.0}, {1,1.0}, {2,1.0},{3,1.0}};
    // std::map<int, double> timeCalibrationCorrection = {{0,-46.013384}, {1,-46.181515}, {2,-45.348356}, {3,0.0}};
    std::map<int, double> timeCalibrationCorrection = {{0,0.0}, {1,0.0}, {2,0.0}, {3,0.0}};
    double stripWidth = 0.050;
    double pitch = 0.500;
    std::vector<double> stripCenterXPosition = {0.5, 0.0, -0.5, 0.0}; // Iter3
    int numLGADchannels = 3;
    int lowGoodStripIndex = 0;
    int highGoodStripIndex = 2;
    double xBinSize = 0.05;
    double yBinSize = 0.1;
    double xmin = -0.80-stripWidth/2; // Sensor's local frame
    double xmax =  0.80+stripWidth/2; // Sensor's local frame
    double ymin = -2.9-stripWidth/2; // Sensor's local frame
    double ymax = 2.9+stripWidth/2; // Sensor's local frame
    double positionRecoMaxPoint = 0.8;
    double noiseAmpThreshold  = 15.0;
    double signalAmpThreshold = 15.0;
    bool enablePositionReconstruction = true;
    int CFD_threshold = 50;
    std::vector<double> positionRecoPar = {0.250000, -0.589871, -1.843711, 16.376317, -57.010190, 62.935244};
    std::vector<std::vector<double>> sensorEdges = {{-0.7, -2.9}, {0.7, 2.9}};//{{-0.7, -4.5}, {0.7, 4.5}}; // Sensor's local frame
    std::vector<std::vector<double>> sensorEdgesTight = {{stripCenterXPosition[highGoodStripIndex], -2.9}, {stripCenterXPosition[lowGoodStripIndex], 2.9}}; // Sensor's local frame
    int centerGoodStripIndex = 1;
    double leftHighGainX = stripCenterXPosition[centerGoodStripIndex] - (stripWidth/2);
    double rightHighGainX = stripCenterXPosition[centerGoodStripIndex] + (stripWidth/2);
    double leftLowGainX = stripCenterXPosition[centerGoodStripIndex] - (pitch/2) - (stripWidth/2);
    double rightLowGainX = stripCenterXPosition[centerGoodStripIndex] - (pitch/2) + (stripWidth/2);
    std::vector<utility::ROI> regionsOfIntrest = {{"highGain", leftHighGainX, rightHighGainX, -2.9, 2.9}, {"lowGain", leftLowGainX, rightLowGainX, -2.9, 2.9}};

};
*/
//done
class HPK_W5_17_2_207V_94P5attn_StripsGeometry : public DefaultGeometry
{
public:
    // 
    // Used lecroy scope channels 0-7
    // Scope channel 0-6 was AC channels, and scope channel 7 was the photek
    // 
    // |-----------|             -----
    // | 0 0 0 0 0 |             |777|
    // | 1 1 1 1 1 |             |777|
    // | 2 2 2 2 2 |             -----
    // | 3 3 3 3 3 |
    // | 4 4 4 4 4 |
    // | 5 5 5 5 5 |
    // | 6 6 6 6 6 |
    // |-----------|

    HPK_W5_17_2_207V_94P5attn_StripsGeometry(const int v=0) : voltage(v){}
    const int voltage;
    std::map<int, std::vector<int>> indexToGeometryMap = {{0,{0,0}}, {1,{0,1}}, {2,{0,2}}, {3,{1,0}}};   
    std::vector<std::vector<int>> geometry = {{0,1,2},{3}};
    std::map<int, bool> acLGADChannelMap = {{0,true}, {1,true}, {2,true}, {3,false}};
    std::map<int, double> amplitudeCorrectionFactor = {{0,1.0}, {1,1.0}, {2,1.0},{3,1.0}};
    std::map<int, double> timeCalibrationCorrection = {{0,-46.059342}, {1,-46.233027}, {2,-45.397350}, {3,0.0}};
    // std::map<int, double> timeCalibrationCorrection = {{0,0.0}, {1,0.0}, {2,0.0}, {3,0.0}};
    double stripWidth = 0.050;
    double pitch = 0.500;
    std::vector<double> stripCenterXPosition = {0.5, 0.0, -0.5, 0.0}; // Iter3
    int numLGADchannels = 3;
    int lowGoodStripIndex = 0;
    int highGoodStripIndex = 2;
    double xBinSize = 0.05;
    double yBinSize = 0.1;
    double xmin = -0.80-stripWidth/2; // Sensor's local frame
    double xmax =  0.80+stripWidth/2; // Sensor's local frame
    double ymin = -2.9-stripWidth/2; // Sensor's local frame
    double ymax = 2.9+stripWidth/2; // Sensor's local frame
    double positionRecoMaxPoint = 0.8;
    double noiseAmpThreshold  = 15.0;
    double signalAmpThreshold = 15.0;
    bool enablePositionReconstruction = true;
    int CFD_threshold = 50;
    std::vector<double> positionRecoPar = {0.250000, -0.655331, 0.114311, -2.096754, 11.086814, -21.797546};
    std::vector<std::vector<double>> sensorEdges = {{-0.7, -2.9}, {0.7, 2.9}};//{{-0.7, -4.5}, {0.7, 4.5}}; // Sensor's local frame
    std::vector<std::vector<double>> sensorEdgesTight = {{stripCenterXPosition[highGoodStripIndex], -2.9}, {stripCenterXPosition[lowGoodStripIndex], 2.9}}; // Sensor's local frame
    int centerGoodStripIndex = 1;
    double leftHighGainX = stripCenterXPosition[centerGoodStripIndex] - (stripWidth/2);
    double rightHighGainX = stripCenterXPosition[centerGoodStripIndex] + (stripWidth/2);
    double leftLowGainX = stripCenterXPosition[centerGoodStripIndex] - (pitch/2) - (stripWidth/2);
    double rightLowGainX = stripCenterXPosition[centerGoodStripIndex] - (pitch/2) + (stripWidth/2);
    std::vector<utility::ROI> regionsOfIntrest = {{"highGain", leftHighGainX, rightHighGainX, -2.9, 2.9}, {"lowGain", leftLowGainX, rightLowGainX, -2.9, 2.9}};
};

/*
class HPK_W5_17_2_205V_93P5attn_fine2DScan_StripsGeometry : public DefaultGeometry
{
public:
    // 
    // Used lecroy scope channels 0-7
    // Scope channel 0-6 was AC channels, and scope channel 7 was the photek
    // 
    // |-----------|             -----
    // | 0 0 0 0 0 |             |777|
    // | 1 1 1 1 1 |             |777|
    // | 2 2 2 2 2 |             -----
    // | 3 3 3 3 3 |
    // | 4 4 4 4 4 |
    // | 5 5 5 5 5 |
    // | 6 6 6 6 6 |
    // |-----------|

    HPK_W5_17_2_205V_93P5attn_fine2DScan_StripsGeometry(const int v=0) : voltage(v){}
    const int voltage;
    std::map<int, std::vector<int>> indexToGeometryMap = {{0,{0,0}}, {1,{0,1}}, {2,{0,2}}, {3,{1,0}}};   
    std::vector<std::vector<int>> geometry = {{0,1,2},{3}};
    std::map<int, bool> acLGADChannelMap = {{0,true}, {1,true}, {2,true}, {3,false}};
    std::map<int, double> amplitudeCorrectionFactor = {{0,1.0}, {1,1.0}, {2,1.0},{3,1.0}};
    std::map<int, double> timeCalibrationCorrection = {{0,-46.034040}, {1,-46.208042}, {2,-45.370644}, {3,0.0}};
    // std::map<int, double> timeCalibrationCorrection = {{0,0.0}, {1,0.0}, {2,0.0}, {3,0.0}};
    double stripWidth = 0.050;
    double pitch = 0.500;
    std::vector<double> stripCenterXPosition = {0.5, 0.0, -0.5, 0.0}; // Iter3
    int numLGADchannels = 3;
    int lowGoodStripIndex = 0;
    int highGoodStripIndex = 2;
    double xBinSize = 0.025;
    double yBinSize = 0.1;
    double xmin = -0.80; // Sensor's local frame
    double xmax =  0.80; // Sensor's local frame
    double ymin = -4.9; // Sensor's local frame
    double ymax = 4.9; // Sensor's local frame
    double positionRecoMaxPoint = 0.8;
    double noiseAmpThreshold  = 15.0;
    double signalAmpThreshold = 15.0;
    bool enablePositionReconstruction = true;
    int CFD_threshold = 50;
    std::vector<double> positionRecoPar = {0.250000, -0.663267, 0.295333, -2.927016, 12.355079, -22.931582};
    std::vector<std::vector<double>> sensorEdges = {{-0.7, -4.5}, {0.7, 4.5}}; // Sensor's local frame
    std::vector<std::vector<double>> sensorEdgesTight = {{stripCenterXPosition[highGoodStripIndex], -4.5}, {stripCenterXPosition[lowGoodStripIndex], 4.5}}; // Sensor's local frame
    int centerGoodStripIndex = 1;
    double leftHighGainX = stripCenterXPosition[centerGoodStripIndex] - (stripWidth/2);
    double rightHighGainX = stripCenterXPosition[centerGoodStripIndex] + (stripWidth/2);
    double leftLowGainX = stripCenterXPosition[centerGoodStripIndex] - (pitch/2) - (stripWidth/2);
    double rightLowGainX = stripCenterXPosition[centerGoodStripIndex] - (pitch/2) + (stripWidth/2);
    std::vector<utility::ROI> regionsOfIntrest = {{"highGain", leftHighGainX, rightHighGainX, -4.9, 4.9}, {"lowGain", leftLowGainX, rightLowGainX, -4.9, 4.9}};
};
*/


class BNL_50um_1cm_450um_W3051_2_2_StripsGeometry : public DefaultGeometry
// BNL_50um_1cm_450um_W3051_2_2_170V
{
public:
    // 
    // Used lecroy scope channels 0-7
    // Scope channel 0-6 was AC channels, and scope channel 7 was the photek
    // 
    // |-----------|             -----
    // | 0 0 0 0 0 |             |777|
    // | 1 1 1 1 1 |             |777|
    // | 2 2 2 2 2 |             -----
    // | 3 3 3 3 3 |
    // | 4 4 4 4 4 |
    // | 5 5 5 5 5 |
    // | 6 6 6 6 6 |
    // |-----------|

    BNL_50um_1cm_450um_W3051_2_2_StripsGeometry(const int v=0) : voltage(v){}
    const int voltage;
    std::map<int, std::vector<int>> indexToGeometryMap = {{0,{0,0}}, {1,{0,1}}, {2,{0,2}}, {3,{1,0}}};   
    std::vector<std::vector<int>> geometry = {{0,1,2},{3}};
    std::map<int, bool> acLGADChannelMap = {{0,true}, {1,true}, {2,true}, {3,false}};
    std::map<int, double> amplitudeCorrectionFactor = {{0,1.0}, {1,1.0}, {2,1.0},{3,1.0}};
    std::map<int, double> timeCalibrationCorrection = {{0,-45.993968}, {1,-46.165238}, {2,-45.335088},{3,0.0}};
    // std::map<int, double> timeCalibrationCorrection = {{0,0.0}, {1,0.0}, {2,0.0}};
    double stripWidth = 0.050;
    double pitch = 0.500;
    std::vector<double> stripCenterXPosition = {0.5, 0.0, -0.5, 0.0}; // Iter3
    int numLGADchannels = 3;
    int lowGoodStripIndex = 0;
    int highGoodStripIndex = 2;
    double xBinSize = 0.05;
    double yBinSize = 0.1;
    double xmin = -0.80; // Sensor's local frame
    double xmax =  0.80; // Sensor's local frame
    double ymin = -2.9; // Sensor's local frame
    double ymax = 2.9; // Sensor's local frame
    double positionRecoMaxPoint = 0.8;
    double noiseAmpThreshold  = 15.0; // 10.0; // 7.0;
    double signalAmpThreshold = 15.0; // 10.0; // 7.0;
    bool enablePositionReconstruction = true;
    int CFD_threshold = 50;
    std::vector<double> positionRecoPar = {0.250000, -0.647302, 0.008472, -1.786845, 14.532465, -34.769396};
    std::vector<std::vector<double>> sensorEdges = {{-0.7, -2.9}, {0.7, 2.9}};//{{-0.7, -4.5}, {0.7, 4.5}}; // Sensor's local frame
    std::vector<std::vector<double>> sensorEdgesTight = {{stripCenterXPosition[highGoodStripIndex], -2.9}, {stripCenterXPosition[lowGoodStripIndex], 2.9}};//{{stripCenterXPosition[highGoodStripIndex], -4.6}, {stripCenterXPosition[lowGoodStripIndex], 4.6}}; // Sensor's local frame
    int centerGoodStripIndex = 3;
    double leftHighGainX = stripCenterXPosition[centerGoodStripIndex] - (stripWidth/2);
    double rightHighGainX = stripCenterXPosition[centerGoodStripIndex] + (stripWidth/2);
    double leftLowGainX = stripCenterXPosition[centerGoodStripIndex] - (pitch/2) - (stripWidth/2);
    double rightLowGainX = stripCenterXPosition[centerGoodStripIndex] - (pitch/2) + (stripWidth/2);
    std::vector<utility::ROI> regionsOfIntrest = {{"highGain", leftHighGainX, rightHighGainX, -2.9, 2.9}, {"lowGain", leftLowGainX, rightLowGainX, -2.9, 2.9}};//{{"highGain", leftHighGainX,rightHighGainX, -4.6,4.6},{"lowGain", leftLowGainX,rightLowGainX, -4.6,4.6}};

};

class BNL_50um_1cm_400um_W3051_1_4_StripsGeometry : public DefaultGeometry
// BNL_50um_1cm_400um_W3051_1_4_160V
{
public:
    // 
    // Used lecroy scope channels 0-7
    // Scope channel 0-6 was AC channels, and scope channel 7 was the photek
    // 
    // |-----------|             -----
    // | 0 0 0 0 0 |             |777|
    // | 1 1 1 1 1 |             |777|
    // | 2 2 2 2 2 |             -----
    // | 3 3 3 3 3 |
    // | 4 4 4 4 4 |
    // | 5 5 5 5 5 |
    // | 6 6 6 6 6 |
    // |-----------|

    BNL_50um_1cm_400um_W3051_1_4_StripsGeometry(const int v=0) : voltage(v){}
    const int voltage;
    std::map<int, std::vector<int>> indexToGeometryMap = {{0,{0,0}}, {1,{0,1}}, {2,{0,2}}, {3,{0,3}}, {4,{0,4}}, {5,{0,5}}, {6,{0,6}}, {7,{1,0}}};   
    std::vector<std::vector<int>> geometry = {{0,1,2,3,4,5,6}, {7}};
    std::map<int, bool> acLGADChannelMap = {{0,true}, {1,true}, {2,true}, {3,true}, {4,true}, {5,true}, {6,true}, {7,false}};
    std::map<int, double> amplitudeCorrectionFactor = {{0,1.0}, {1,1.0}, {2,1.0}, {3,1.0}, {4,1.0}, {5,1.0}, {6,1.0}, {7,1.0}};
	std::map<int, double> timeCalibrationCorrection = {{0,1.5571204}, {1,1.4723113}, {2,1.5837402}, {3,1.4558382}, {4,1.5302476}, {5,1.4469072}, {6,1.5334498}, {7,0.0}};
	// std::map<int, double> timeCalibrationCorrection = {{0,0.0}, {1,0.0}, {2,0.0}, {3,0.0}, {4,0.0}, {5,0.0}, {6,0.0}, {7,0.0}};
    double stripWidth = 0.100;
    double pitch = 0.500;
    double sensorCenter  = -0.2; // Lab-Tracker's frame ->  y_dut
    double sensorCenterY = 0.5; // Lab-Tracker's frame -> -x_dut
	std::vector<double> stripCenterXPosition = {1.531, 1.034, 0.530, 0.032, -0.468, -0.967, -1.469, 0.0};
	int numLGADchannels = 7;
    int lowGoodStripIndex = 1;
    int highGoodStripIndex = 5;
    double alpha = -0.24;
    double beta  = 0.00;
    double gamma = 0.00;
    double z_dut = -18.30;
    double xBinSize = 0.050;
    double yBinSize = 0.2;
    double xmin = -2.50; // Sensor's local frame
    double xmax =  2.50; // Sensor's local frame
    double ymin = -5.60; // Sensor's local frame
    double ymax =  5.60; // Sensor's local frame
    double positionRecoMaxPoint = 0.78; // 0.79;
    double photekSignalThreshold = 200.0;
    double noiseAmpThreshold  = 15.0; // 15.0;
    double signalAmpThreshold = 15.0; // 15.0;
    bool uses2022Pix = true;
    bool isHorizontal = true;
    bool enablePositionReconstruction = true;
    int minPixHits = 2;
    int minStripHits = 6;
    int CFD_threshold = 50;
	std::vector<double> positionRecoPar = {0.250000, -0.718665, -0.139214, 1.987639, -8.425333, -2.053463};
	// std::vector<std::vector<double>> sensorEdges = {{-3.0, -2.0}, {1.0, 7.6}};
    // std::vector<std::vector<double>> sensorEdges = {{-2.0, -4.8}, {2.0, 4.8}}; // Sensor's local frame
	std::vector<std::vector<double>> sensorEdges = {{-2.4, -5.5}, {2.4, 5.5}}; // Sensor's local frame
	std::vector<std::vector<double>> sensorEdgesTight = {{stripCenterXPosition[highGoodStripIndex], -4.6}, {stripCenterXPosition[lowGoodStripIndex], 4.6}}; // Sensor's local frame
    int centerGoodStripIndex = 3;
	double leftHighGainX = stripCenterXPosition[centerGoodStripIndex] - (stripWidth/2);
	double rightHighGainX = stripCenterXPosition[centerGoodStripIndex] + (stripWidth/2);
	double leftLowGainX = stripCenterXPosition[centerGoodStripIndex] - (pitch/2) - (stripWidth/2);
	double rightLowGainX = stripCenterXPosition[centerGoodStripIndex] - (pitch/2) + (stripWidth/2);
	std::vector<utility::ROI> regionsOfIntrest = {{"highGain", leftHighGainX,rightHighGainX, -4.6,4.6},{"lowGain", leftLowGainX,rightLowGainX, -4.6,4.6}};
};


class BNL_50um_1cm_450um_W3052_2_4_StripsGeometry : public DefaultGeometry
// BNL_50um_1cm_450um_W3052_2_4_185V
{
public:
    // 
    // Used lecroy scope channels 0-7
    // Scope channel 0-6 was AC channels, and scope channel 7 was the photek
    // 
    // |-----------|             -----
    // | 0 0 0 0 0 |             |777|
    // | 1 1 1 1 1 |             |777|
    // | 2 2 2 2 2 |             -----
    // | 3 3 3 3 3 |
    // | 4 4 4 4 4 |
    // | 5 5 5 5 5 |
    // | 6 6 6 6 6 |
    // |-----------|

    BNL_50um_1cm_450um_W3052_2_4_StripsGeometry(const int v=0) : voltage(v){}
    const int voltage;
    std::map<int, std::vector<int>> indexToGeometryMap = {{0,{0,0}}, {1,{0,1}}, {2,{0,2}}, {3,{0,3}}, {4,{0,4}}, {5,{0,5}}, {6,{0,6}}, {7,{1,0}}};   
    std::vector<std::vector<int>> geometry = {{0,1,2,3,4,5,6}, {7}};
    std::map<int, bool> acLGADChannelMap = {{0,true}, {1,true}, {2,true}, {3,true}, {4,true}, {5,true}, {6,true}, {7,false}};
    std::map<int, double> amplitudeCorrectionFactor = {{0,1.0}, {1,1.0}, {2,1.0}, {3,1.0}, {4,1.0}, {5,1.0}, {6,1.0}, {7,1.0}};
	std::map<int, double> timeCalibrationCorrection = {{0,1.5689530}, {1,1.4867041}, {2,1.5966171}, {3,1.4800527}, {4,1.5412827}, {5,1.4494462}, {6,1.5337527}, {7,0.0}};
	// std::map<int, double> timeCalibrationCorrection = {{0,0.0}, {1,0.0}, {2,0.0}, {3,0.0}, {4,0.0}, {5,0.0}, {6,0.0}, {7,0.0}};
    double stripWidth = 0.050;
    double pitch = 0.500;
    double sensorCenter  = 0.1; // Lab-Tracker's frame ->  y_dut
    double sensorCenterY = 0.5; // Lab-Tracker's frame -> -x_dut
    std::vector<double> stripCenterXPosition = {1.504, 1.005, 0.498, -0.000, -0.490, -0.995, -1.493, 0.0};
	int numLGADchannels = 7;
    int lowGoodStripIndex = 1;
    int highGoodStripIndex = 5;
    double alpha = 0.48;
    double beta  = 0.00;
    double gamma = 0.00;
    double z_dut = -19.0;
    double xBinSize = 0.050;
    double yBinSize = 0.2;
    double xmin = -2.50; // Sensor's local frame
    double xmax =  2.50; // Sensor's local frame
    double ymin = -5.60; // Sensor's local frame
    double ymax =  5.60; // Sensor's local frame
    double positionRecoMaxPoint = 0.76; // 0.79;
    double photekSignalThreshold = 200.0;
    double noiseAmpThreshold  = 15.0; // 15.0;
    double signalAmpThreshold = 15.0; // 15.0;
    bool uses2022Pix = true;
    bool isHorizontal = true;
    bool enablePositionReconstruction = true;
    int minPixHits = 2;
    int minStripHits = 6;
    int CFD_threshold = 50;
	std::vector<double> positionRecoPar = {0.250000, -0.810944, 1.960402, -28.122023, 158.066782, -313.770118};
	// std::vector<std::vector<double>> sensorEdges = {{-3.0, -2.0}, {1.0, 7.6}};
    // std::vector<std::vector<double>> sensorEdges = {{-2.0, -4.8}, {2.0, 4.8}}; // Sensor's local frame
	std::vector<std::vector<double>> sensorEdges = {{-2.4, -5.5}, {2.4, 5.5}}; // Sensor's local frame
	std::vector<std::vector<double>> sensorEdgesTight = {{stripCenterXPosition[highGoodStripIndex], -4.6}, {stripCenterXPosition[lowGoodStripIndex], 4.6}}; // Sensor's local frame
    int centerGoodStripIndex = 3;
	double leftHighGainX = stripCenterXPosition[centerGoodStripIndex] - (stripWidth/2);
	double rightHighGainX = stripCenterXPosition[centerGoodStripIndex] + (stripWidth/2);
	double leftLowGainX = stripCenterXPosition[centerGoodStripIndex] - (pitch/2) - (stripWidth/2);
	double rightLowGainX = stripCenterXPosition[centerGoodStripIndex] - (pitch/2) + (stripWidth/2);
	std::vector<utility::ROI> regionsOfIntrest = {{"highGain", leftHighGainX,rightHighGainX, -4.6,4.6},{"lowGain", leftLowGainX,rightLowGainX, -4.6,4.6}};
};


class BNL_20um_1cm_400um_W3074_1_4_StripsGeometry : public DefaultGeometry
// BNL_20um_1cm_400um_W3074_1_4_95V
{
public:
    // 
    // Used lecroy scope channels 0-7
    // Scope channel 0-6 was AC channels, and scope channel 7 was the photek
    // 
    // |-----------|             -----
    // | 0 0 0 0 0 |             |777|
    // | 1 1 1 1 1 |             |777|
    // | 2 2 2 2 2 |             -----
    // | 3 3 3 3 3 |
    // | 4 4 4 4 4 |
    // | 5 5 5 5 5 |
    // | 6 6 6 6 6 |
    // |-----------|

    BNL_20um_1cm_400um_W3074_1_4_StripsGeometry(const int v=0) : voltage(v){}
    const int voltage;
    std::map<int, std::vector<int>> indexToGeometryMap = {{0,{0,0}}, {1,{0,1}}, {2,{0,2}}, {3,{0,3}}, {4,{0,4}}, {5,{0,5}}, {6,{0,6}}, {7,{1,0}}};   
    std::vector<std::vector<int>> geometry = {{0,1,2,3,4,5,6}, {7}};
    std::map<int, bool> acLGADChannelMap = {{0,true}, {1,true}, {2,true}, {3,true}, {4,true}, {5,true}, {6,true}, {7,false}};
    std::map<int, double> amplitudeCorrectionFactor = {{0,1.0}, {1,1.0}, {2,1.0}, {3,1.0}, {4,1.0}, {5,1.0}, {6,1.0}, {7,1.0}};
    std::map<int, double> timeCalibrationCorrection = {{0,0.94679459}, {1,0.82059504}, {2,0.92001622}, {3,0.81254756}, {4,0.88364704}, {5,0.79850545}, {6,0.93318906}, {7,0.0}};
    // std::map<int, double> timeCalibrationCorrection = {{0,0.0}, {1,0.0}, {2,0.0}, {3,0.0}, {4,0.0}, {5,0.0}, {6,0.0}, {7,0.0}};
    double stripWidth = 0.100;
    double pitch = 0.500;
    double sensorCenter  =-0.95; // Lab-Tracker's frame ->  y_dut
    double sensorCenterY = 2.7; // Lab-Tracker's frame -> -x_dut
    std::vector<double> stripCenterXPosition = {1.516, 1.013, 0.514, 0.015, -0.484, -0.985, -1.485, 0.0};
    int numLGADchannels = 7;
    int lowGoodStripIndex = 1;
    int highGoodStripIndex = 5;
    double alpha = 0.00;
    double beta  = 0.00;
    double gamma = 0.00;
    double z_dut = 0.00;
    double xBinSize = 0.025;
    double yBinSize = 0.2;
    double xmin = -2.50; // Sensor's local frame
    double xmax =  2.50; // Sensor's local frame
    double ymin = -5.20; // Sensor's local frame
    double ymax =  5.20; // Sensor's local frame
    double positionRecoMaxPoint = 0.77; // 0.79;
    double photekSignalThreshold = 200.0;
    double noiseAmpThreshold  = 7.0; // 15.0;
    double signalAmpThreshold = 7.0; // 15.0;
    bool uses2022Pix = true;
    bool isHorizontal = true;
    bool enablePositionReconstruction = true;
    int minPixHits = 2;
    int minStripHits = 6;
    int CFD_threshold = 50;
    std::vector<double> positionRecoPar = {0.250000, -0.592554, 1.695367, -24.201246, 132.757266, -259.853428};
    // std::vector<std::vector<double>> sensorEdges = {{-3.0, -2.0}, {1.0, 7.6}};
    // std::vector<std::vector<double>> sensorEdges = {{-2.0, -4.8}, {2.0, 4.8}}; // Sensor's local frame
    std::vector<std::vector<double>> sensorEdges = {{-1.5, -7.0}, {3.0, 5.0}}; // Sensor's local frame
    std::vector<std::vector<double>> sensorEdgesTight = {{stripCenterXPosition[highGoodStripIndex], -4.6}, {stripCenterXPosition[lowGoodStripIndex], 4.6}}; // Sensor's local frame
    int centerGoodStripIndex = 3;
	double leftHighGainX = stripCenterXPosition[centerGoodStripIndex] - (stripWidth/2);
	double rightHighGainX = stripCenterXPosition[centerGoodStripIndex] + (stripWidth/2);
	double leftLowGainX = stripCenterXPosition[centerGoodStripIndex] - (pitch/2) - (stripWidth/2);
	double rightLowGainX = stripCenterXPosition[centerGoodStripIndex] - (pitch/2) + (stripWidth/2);
	std::vector<utility::ROI> regionsOfIntrest = {{"highGain", leftHighGainX,rightHighGainX, -4.6,4.6},{"lowGain", leftLowGainX,rightLowGainX, -4.6,4.6}};
};


class BNL_20um_1cm_400um_W3075_1_2_StripsGeometry : public DefaultGeometry
// BNL_20um_1cm_400um_W3075_1_2_80V
{
public:
    // 
    // Used lecroy scope channels 0-7
    // Scope channel 0-6 was AC channels, and scope channel 7 was the photek
    // 
    // |-----------|             -----
    // | 0 0 0 0 0 |             |777|
    // | 1 1 1 1 1 |             |777|
    // | 2 2 2 2 2 |             -----
    // | 3 3 3 3 3 |
    // | 4 4 4 4 4 |
    // | 5 5 5 5 5 |
    // | 6 6 6 6 6 |
    // |-----------|

    BNL_20um_1cm_400um_W3075_1_2_StripsGeometry(const int v=0) : voltage(v){}
    const int voltage;
    std::map<int, std::vector<int>> indexToGeometryMap = {{0,{0,0}}, {1,{0,1}}, {2,{0,2}}, {3,{0,3}}, {4,{0,4}}, {5,{0,5}}, {6,{0,6}}, {7,{1,0}}};   
    std::vector<std::vector<int>> geometry = {{0,1,2,3,4,5,6}, {7}};
    std::map<int, bool> acLGADChannelMap = {{0,true}, {1,true}, {2,true}, {3,true}, {4,true}, {5,true}, {6,true}, {7,false}};
    std::map<int, double> amplitudeCorrectionFactor = {{0,1.0}, {1,1.0}, {2,1.0}, {3,1.0}, {4,1.0}, {5,1.0}, {6,1.0}, {7,1.0}};
    std::map<int, double> timeCalibrationCorrection = {{0,0.94679459}, {1,0.82059504}, {2,0.92001622}, {3,0.81254756}, {4,0.88364704}, {5,0.79850545}, {6,0.93318906}, {7,0.0}};
    // std::map<int, double> timeCalibrationCorrection = {{0,0.0}, {1,0.0}, {2,0.0}, {3,0.0}, {4,0.0}, {5,0.0}, {6,0.0}, {7,0.0}};
    double stripWidth = 0.050;
    double pitch = 0.500;
    double sensorCenter  =-0.95; // Lab-Tracker's frame ->  y_dut
    double sensorCenterY = 2.7; // Lab-Tracker's frame -> -x_dut
    std::vector<double> stripCenterXPosition = {1.516, 1.013, 0.514, 0.015, -0.484, -0.985, -1.485, 0.0};
    int numLGADchannels = 7;
    int lowGoodStripIndex = 1;
    int highGoodStripIndex = 5;
    double alpha = 0.00;
    double beta  = 0.00;
    double gamma = 0.00;
    double z_dut = 0.00;
    double xBinSize = 0.025;
    double yBinSize = 0.2;
    double xmin = -2.50; // Sensor's local frame
    double xmax =  2.50; // Sensor's local frame
    double ymin = -5.20; // Sensor's local frame
    double ymax =  5.20; // Sensor's local frame
    double positionRecoMaxPoint = 0.77; // 0.79;
    double photekSignalThreshold = 200.0;
    double noiseAmpThreshold  = 7.0; // 15.0;
    double signalAmpThreshold = 7.0; // 15.0;
    bool uses2022Pix = true;
    bool isHorizontal = true;
    bool enablePositionReconstruction = true;
    int minPixHits = 2;
    int minStripHits = 6;
    int CFD_threshold = 50;
    std::vector<double> positionRecoPar = {0.250000, -0.592554, 1.695367, -24.201246, 132.757266, -259.853428};
    // std::vector<std::vector<double>> sensorEdges = {{-3.0, -2.0}, {1.0, 7.6}};
    // std::vector<std::vector<double>> sensorEdges = {{-2.0, -4.8}, {2.0, 4.8}}; // Sensor's local frame
    std::vector<std::vector<double>> sensorEdges = {{-1.5, -7.0}, {3.0, 5.0}}; // Sensor's local frame
    std::vector<std::vector<double>> sensorEdgesTight = {{stripCenterXPosition[highGoodStripIndex], -4.6}, {stripCenterXPosition[lowGoodStripIndex], 4.6}}; // Sensor's local frame
    int centerGoodStripIndex = 3;
	double leftHighGainX = stripCenterXPosition[centerGoodStripIndex] - (stripWidth/2);
	double rightHighGainX = stripCenterXPosition[centerGoodStripIndex] + (stripWidth/2);
	double leftLowGainX = stripCenterXPosition[centerGoodStripIndex] - (pitch/2) - (stripWidth/2);
	double rightLowGainX = stripCenterXPosition[centerGoodStripIndex] - (pitch/2) + (stripWidth/2);
	std::vector<utility::ROI> regionsOfIntrest = {{"highGain", leftHighGainX,rightHighGainX, -4.6,4.6},{"lowGain", leftLowGainX,rightLowGainX, -4.6,4.6}};
};


class BNL_20um_1cm_450um_W3074_2_1_StripsGeometry : public DefaultGeometry
// BNL_20um_1cm_450um_W3074_2_1_95V
{
public:
    // 
    // Used lecroy scope channels 0-7
    // Scope channel 0-6 was AC channels, and scope channel 7 was the photek
    // 
    // |-----------|             -----
    // | 0 0 0 0 0 |             |777|
    // | 1 1 1 1 1 |             |777|
    // | 2 2 2 2 2 |             -----
    // | 3 3 3 3 3 |
    // | 4 4 4 4 4 |
    // | 5 5 5 5 5 |
    // | 6 6 6 6 6 |
    // |-----------|

    BNL_20um_1cm_450um_W3074_2_1_StripsGeometry(const int v=0) : voltage(v){}
    const int voltage;
    std::map<int, std::vector<int>> indexToGeometryMap = {{0,{0,0}}, {1,{0,1}}, {2,{0,2}}, {3,{0,3}}, {4,{0,4}}, {5,{0,5}}, {6,{0,6}}, {7,{1,0}}};   
    std::vector<std::vector<int>> geometry = {{0,1,2,3,4,5,6}, {7}};
    std::map<int, bool> acLGADChannelMap = {{0,true}, {1,true}, {2,true}, {3,true}, {4,true}, {5,true}, {6,true}, {7,false}};
    std::map<int, double> amplitudeCorrectionFactor = {{0,1.0}, {1,1.0}, {2,1.0}, {3,1.0}, {4,1.0}, {5,1.0}, {6,1.0}, {7,1.0}};
    std::map<int, double> timeCalibrationCorrection = {{0,0.94679459}, {1,0.82059504}, {2,0.92001622}, {3,0.81254756}, {4,0.88364704}, {5,0.79850545}, {6,0.93318906}, {7,0.0}};
    // std::map<int, double> timeCalibrationCorrection = {{0,0.0}, {1,0.0}, {2,0.0}, {3,0.0}, {4,0.0}, {5,0.0}, {6,0.0}, {7,0.0}};
    double stripWidth = 0.050;
    double pitch = 0.500;
    double sensorCenter  =-0.95; // Lab-Tracker's frame ->  y_dut
    double sensorCenterY = 2.7; // Lab-Tracker's frame -> -x_dut
    std::vector<double> stripCenterXPosition = {1.516, 1.013, 0.514, 0.015, -0.484, -0.985, -1.485, 0.0};
    int numLGADchannels = 7;
    int lowGoodStripIndex = 1;
    int highGoodStripIndex = 5;
    double alpha = 0.00;
    double beta  = 0.00;
    double gamma = 0.00;
    double z_dut = 0.00;
    double xBinSize = 0.025;
    double yBinSize = 0.2;
    double xmin = -2.50; // Sensor's local frame
    double xmax =  2.50; // Sensor's local frame
    double ymin = -5.20; // Sensor's local frame
    double ymax =  5.20; // Sensor's local frame
    double positionRecoMaxPoint = 0.77; // 0.79;
    double photekSignalThreshold = 200.0;
    double noiseAmpThreshold  = 7.0; // 15.0;
    double signalAmpThreshold = 7.0; // 15.0;
    bool uses2022Pix = true;
    bool isHorizontal = true;
    bool enablePositionReconstruction = true;
    int minPixHits = 2;
    int minStripHits = 6;
    int CFD_threshold = 50;
    std::vector<double> positionRecoPar = {0.250000, -0.592554, 1.695367, -24.201246, 132.757266, -259.853428};
    // std::vector<std::vector<double>> sensorEdges = {{-3.0, -2.0}, {1.0, 7.6}};
    // std::vector<std::vector<double>> sensorEdges = {{-2.0, -4.8}, {2.0, 4.8}}; // Sensor's local frame
    std::vector<std::vector<double>> sensorEdges = {{-1.5, -7.0}, {3.0, 5.0}}; // Sensor's local frame
    std::vector<std::vector<double>> sensorEdgesTight = {{stripCenterXPosition[highGoodStripIndex], -4.6}, {stripCenterXPosition[lowGoodStripIndex], 4.6}}; // Sensor's local frame
    int centerGoodStripIndex = 3;
	double leftHighGainX = stripCenterXPosition[centerGoodStripIndex] - (stripWidth/2);
	double rightHighGainX = stripCenterXPosition[centerGoodStripIndex] + (stripWidth/2);
	double leftLowGainX = stripCenterXPosition[centerGoodStripIndex] - (pitch/2) - (stripWidth/2);
	double rightLowGainX = stripCenterXPosition[centerGoodStripIndex] - (pitch/2) + (stripWidth/2);
	std::vector<utility::ROI> regionsOfIntrest = {{"highGain", leftHighGainX,rightHighGainX, -4.6,4.6},{"lowGain", leftLowGainX,rightLowGainX, -4.6,4.6}};
};


class BNL_20um_1cm_450um_W3075_2_4_StripsGeometry : public DefaultGeometry
// BNL_20um_1cm_450um_W3075_2_4_80V
{
public:
    // 
    // Used lecroy scope channels 0-7
    // Scope channel 0-6 was AC channels, and scope channel 7 was the photek
    // 
    // |-----------|             -----
    // | 0 0 0 0 0 |             |777|
    // | 1 1 1 1 1 |             |777|
    // | 2 2 2 2 2 |             -----
    // | 3 3 3 3 3 |
    // | 4 4 4 4 4 |
    // | 5 5 5 5 5 |
    // | 6 6 6 6 6 |
    // |-----------|

    BNL_20um_1cm_450um_W3075_2_4_StripsGeometry(const int v=0) : voltage(v){}
    const int voltage;
    std::map<int, std::vector<int>> indexToGeometryMap = {{0,{0,0}}, {1,{0,1}}, {2,{0,2}}, {3,{0,3}}, {4,{0,4}}, {5,{0,5}}, {6,{0,6}}, {7,{1,0}}};   
    std::vector<std::vector<int>> geometry = {{0,1,2,3,4,5,6}, {7}};
    std::map<int, bool> acLGADChannelMap = {{0,true}, {1,true}, {2,true}, {3,true}, {4,true}, {5,true}, {6,true}, {7,false}};
    std::map<int, double> amplitudeCorrectionFactor = {{0,1.0}, {1,1.0}, {2,1.0}, {3,1.0}, {4,1.0}, {5,1.0}, {6,1.0}, {7,1.0}};
    std::map<int, double> timeCalibrationCorrection = {{0,1.7733575}, {1,1.7179600}, {2,1.7824067}, {3,1.6949863}, {4,1.7409882}, {5,1.6785454}, {6,1.7660326}, {7,0.0}};
    double stripWidth = 0.050;
    double pitch = 0.500;
    double sensorCenter  =-0.2; // Lab-Tracker's frame ->  y_dut
    double sensorCenterY = 0.7; // Lab-Tracker's frame -> -x_dut
    // std::vector<double> stripCenterXPosition = {1.478, 1.030, 0.490, 0.018, -0.473, -1.019, -1.479, 0.0};
    // std::vector<double> stripCenterXPosition = {1.511, 1.024, 0.509, -0.001, -0.469, -1.001, -1.471, 0.0};
    std::vector<double> stripCenterXPosition = {1.509, 1.025, 0.504, -0.001, -0.467, -1.000, -1.472, 0.0};
    int numLGADchannels = 7;
    int lowGoodStripIndex = 1;
    int highGoodStripIndex = 5;
    double alpha =-0.30; //-0.30; // 0.00;
    double beta  = 0.00; // 0.00; // 0.00; // 0.00;
    double gamma = 0.00; // 0.00; // 0.00; // 0.00;
    double z_dut =-6.00; //-6.00; // 0.00; // 0.00;
    double xBinSize = 0.05;
    double yBinSize = 0.2;
    double xmin = -2.50; // Sensor's local frame
    double xmax =  2.50; // Sensor's local frame
    double ymin = -5.20; // Sensor's local frame
    double ymax =  5.20; // Sensor's local frame
    double positionRecoMaxPoint = 0.83; // 0.84;
    double photekSignalThreshold = 200.0;
    double noiseAmpThreshold  = 15.0; // 7.0;
    double signalAmpThreshold = 15.0; // 7.0;
    bool uses2022Pix = true;
    bool isHorizontal = true;
    bool enablePositionReconstruction = true;
    int minPixHits = 2;
    int minStripHits = 6;
    int CFD_threshold = 50;
    // std::vector<double> positionRecoPar = {0.250000, -0.936464, 1.897516, -15.593843, 32.081749};
    // std::vector<double> positionRecoPar = {0.250000, -0.989627, 3.870174, -40.279305, 160.215629, -229.438954};
    // std::vector<double> positionRecoPar = {0.250000, -0.997329, 4.084599, -42.707886, 171.844257, -249.440159};
    // std::vector<double> positionRecoPar = {0.250000, -0.980770, 3.669108, -39.123618, 159.022355, -231.519371};
    std::vector<double> positionRecoPar = {0.250000, -0.806497, 1.475103, -4.704219, 5.096062, -0.764719};
    // std::vector<std::vector<double>> sensorEdges = {{-3.0, -2.0}, {1.0, 7.6}};
    // std::vector<std::vector<double>> sensorEdges = {{-2.0, -4.8}, {2.0, 4.8}}; // Sensor's local frame
    std::vector<std::vector<double>> sensorEdges = {{-2.4, -5.5}, {2.4, 5.5}}; // Sensor's local frame
    std::vector<std::vector<double>> sensorEdgesTight = {{stripCenterXPosition[highGoodStripIndex], -4.6}, {stripCenterXPosition[lowGoodStripIndex], 4.6}}; // Sensor's local frame
    int centerGoodStripIndex = 3;
	double leftHighGainX = stripCenterXPosition[centerGoodStripIndex] - (stripWidth/2);
	double rightHighGainX = stripCenterXPosition[centerGoodStripIndex] + (stripWidth/2);
	double leftLowGainX = stripCenterXPosition[centerGoodStripIndex] - (pitch/2) - (stripWidth/2);
	double rightLowGainX = stripCenterXPosition[centerGoodStripIndex] - (pitch/2) + (stripWidth/2);
	std::vector<utility::ROI> regionsOfIntrest = {{"highGain", leftHighGainX,rightHighGainX, -4.6,4.6},{"lowGain", leftLowGainX,rightLowGainX, -4.6,4.6}};
};


class BNL_50um_2p5cm_mixConfig1_W3051_1_4_StripsGeometry : public DefaultGeometry
// BNL_50um_2p5cm_mixConfig1_W3051_1_4_170V
{
public:
    // 
    // Used lecroy scope channels 0-7
    // Scope channel 0-6 was AC channels, and scope channel 7 was the photek
    // 
    // |-----------|              -----
    // | 0 0 0 0 0 | <- Config 1  |777|
    // | 1 1 1 1 1 | <- Config 1  |777|
    // | 2 2 2 2 2 | <- Config 1  -----
    // | 3 3 3 3 3 | <- Config 1
    // | 4 4 4 4 4 | <- Config 1
    // | 5 5 5 5 5 | <- Config 2
    // | 6 6 6 6 6 | <- Config 2
    // |-----------|

    BNL_50um_2p5cm_mixConfig1_W3051_1_4_StripsGeometry(const int v=0) : voltage(v){}
    const int voltage;
    std::map<int, std::vector<int>> indexToGeometryMap = {{0,{0,0}}, {1,{0,1}}, {2,{0,2}}, {3,{0,3}}, {4,{0,4}}, {5,{0,5}}, {6,{0,6}}, {7,{1,0}}};   
    std::vector<std::vector<int>> geometry = {{0,1,2,3,4,5,6}, {7}};
    std::map<int, bool> acLGADChannelMap = {{0,true}, {1,true}, {2,true}, {3,true}, {4,true}, {5,true}, {6,true}, {7,false}};
    std::map<int, double> amplitudeCorrectionFactor = {{0,1.0}, {1,1.0}, {2,1.0}, {3,1.0}, {4,1.0}, {5,1.0}, {6,1.0}, {7,1.0}};
    std::map<int, double> timeCalibrationCorrection = {{0,1.1705073}, {1,1.4564536}, {2,1.2600368}, {3,1.4158836}, {4,1.2403504}, {5,1.4185924}, {6,1.1507471}, {7,0.0}};
    // std::map<int, double> timeCalibrationCorrection = {{0,0.0}, {1,0.0}, {2,0.0}, {3,0.0}, {4,0.0}, {5,0.0}, {6,0.0}, {7,0.0}};
    double stripWidth = 0.100; // Config1 has strips of 100 micron width
    double pitch = 0.500;
    // Center of Config1 + Config2
    double sensorCenter  =-0.4; // Lab-Tracker's frame ->  y_dut
    double sensorCenterY = 1.0; // Lab-Tracker's frame -> -x_dut
    // Only Config1
    // double sensorCenter  = 0.2; // Lab-Tracker's frame ->  y_dut
    // double sensorCenterY = 1.0; // Lab-Tracker's frame -> -x_dut
    // std::vector<double> stripCenterXPosition = {2.181, 1.732, 1.228, 0.726, 0.225, -0.270, -0.770, 0.0}; // Iter1
    std::vector<double> stripCenterXPosition = {2.181, 1.730, 1.236, 0.735, 0.232, -0.264, -0.766, 0.0}; // Iter2
    int numLGADchannels = 7;
    int lowGoodStripIndex = 1;
    int highGoodStripIndex = 3;
    double alpha = -0.25; // -0.21; //-0.21; // 0.00;
    double beta  =  0.00; //  0.00; // 0.00; // 0.00;
    double gamma =  0.00; //  0.00; // 0.00; // 0.00;
    double z_dut =-10.41; //-10.41; // 0.00; // 0.00;
    double xBinSize = 0.050; // 0.025;
    double yBinSize = 0.2;
    double xmin = -2.70; // Sensor's local frame
    double xmax =  2.70; // Sensor's local frame
    double ymin = -13.20; // Sensor's local frame
    double ymax =  13.20; // Sensor's local frame
    double positionRecoMaxPoint = 0.71; // 0.72;
    double photekSignalThreshold = 200.0;
    double noiseAmpThreshold  = 15.0; // 12.0; // 7.0;
    double signalAmpThreshold = 15.0; // 12.0; // 7.0;
    bool uses2022Pix = true;
    bool isHorizontal = true;
    bool enablePositionReconstruction = true;
    int minPixHits = 0;
    int minStripHits = 6;
    int CFD_threshold = 50;
    // std::vector<double> positionRecoPar = {0.250000, -0.667970, -9.010738, 112.238851, -643.639801, 1280.390139}; // Iter1
    std::vector<double> positionRecoPar = {0.250000, -0.668684, -8.909631, 109.086460, -614.727996, 1204.484787}; // Iter2
    // std::vector<std::vector<double>> sensorEdges = {{-3.0, -2.0}, {1.0, 7.6}};
    // std::vector<std::vector<double>> sensorEdges = {{-2.0, -4.8}, {2.0, 4.8}}; // Sensor's local frame
    // std::vector<std::vector<double>> sensorEdges = {{-2.6, -13.0}, {2.6, 13.0}}; // Sensor's local frame
    std::vector<std::vector<double>> sensorEdges = {{-1.3, -13.0}, {2.5, 13.0}}; // Sensor's local frame
    std::vector<std::vector<double>> sensorEdgesTight = {{stripCenterXPosition[highGoodStripIndex], -11.5}, {stripCenterXPosition[lowGoodStripIndex], 11.5}}; // Sensor's local frame
    int centerGoodStripIndex = 2;
	double leftHighGainX = stripCenterXPosition[centerGoodStripIndex] - (stripWidth/2);
	double rightHighGainX = stripCenterXPosition[centerGoodStripIndex] + (stripWidth/2);
	double leftLowGainX = stripCenterXPosition[centerGoodStripIndex] - (pitch/2) - (stripWidth/2);
	double rightLowGainX = stripCenterXPosition[centerGoodStripIndex] - (pitch/2) + (stripWidth/2);
	std::vector<utility::ROI> regionsOfIntrest = {{"highGain", leftHighGainX,rightHighGainX, -11.5,11.5},{"lowGain", leftLowGainX,rightLowGainX, -11.5,11.5}};
};


class BNL_50um_2p5cm_mixConfig2_W3051_1_4_StripsGeometry : public DefaultGeometry
// BNL_50um_2p5cm_mixConfig2_W3051_1_4_170V
{
public:
    // 
    // Used lecroy scope channels 0-7
    // Scope channel 0-6 was AC channels, and scope channel 7 was the photek
    // 
    // |-----------|              -----
    // | 0 0 0 0 0 | <- Config 1  |777|
    // | 1 1 1 1 1 | <- Config 1  |777|
    // | 2 2 2 2 2 | <- Config 2  -----
    // | 3 3 3 3 3 | <- Config 2
    // | 4 4 4 4 4 | <- Config 2
    // | 5 5 5 5 5 | <- Config 2
    // | 6 6 6 6 6 | <- Config 2
    // |-----------|

    BNL_50um_2p5cm_mixConfig2_W3051_1_4_StripsGeometry(const int v=0) : voltage(v){}
    const int voltage;
    std::map<int, std::vector<int>> indexToGeometryMap = {{0,{0,0}}, {1,{0,1}}, {2,{0,2}}, {3,{0,3}}, {4,{0,4}}, {5,{0,5}}, {6,{0,6}}, {7,{1,0}}};   
    std::vector<std::vector<int>> geometry = {{0,1,2,3,4,5,6}, {7}};
    std::map<int, bool> acLGADChannelMap = {{0,true}, {1,true}, {2,true}, {3,true}, {4,true}, {5,true}, {6,true}, {7,false}};
    std::map<int, double> amplitudeCorrectionFactor = {{0,1.0}, {1,1.0}, {2,1.0}, {3,1.0}, {4,1.0}, {5,1.0}, {6,1.0}, {7,1.0}};
    std::map<int, double> timeCalibrationCorrection = {{0,1.3716686}, {1,1.2568552}, {2,1.4215433}, {3,1.2103310}, {4,1.3574690}, {5,1.1304036}, {6,1.4516399}, {7,0.0}};
    // std::map<int, double> timeCalibrationCorrection = {{0,0.0}, {1,0.0}, {2,0.0}, {3,0.0}, {4,0.0}, {5,0.0}, {6,0.0}, {7,0.0}};
    double stripWidth = 0.050; // Config2 has strips of 50 micron width
    double pitch = 0.500;
    // Center of Config1 + Config2
    double sensorCenter  =-0.4; // Lab-Tracker's frame ->  y_dut
    double sensorCenterY = 1.0; // Lab-Tracker's frame -> -x_dut
    // Only Config2
    // double sensorCenter  =-0.95; // Lab-Tracker's frame ->  y_dut
    // double sensorCenterY = 1.0; // Lab-Tracker's frame -> -x_dut
    // std::vector<double> stripCenterXPosition = {0.739, 0.237, -0.259, -0.758, -1.255, -1.748, -2.196, 0.0}; // Iter1
    std::vector<double> stripCenterXPosition = {0.746, 0.245, -0.250, -0.753, -1.244, -1.746, -2.181, 0.0}; // Iter2
    int numLGADchannels = 7;
    int lowGoodStripIndex = 3;
    int highGoodStripIndex = 5;
    double alpha = -0.21; // -0.15; //-0.15; // 0.00;
    double beta  =  0.00; //  0.00; // 0.00; // 0.00;
    double gamma =  0.00; //  0.00; // 0.00; // 0.00;
    double z_dut =-21.33; //-21.33; // 0.00; // 0.00;
    double xBinSize = 0.050; // 0.025;
    double yBinSize = 0.2;
    double xmin = -2.70; // Sensor's local frame
    double xmax =  2.70; // Sensor's local frame
    double ymin = -13.20; // Sensor's local frame
    double ymax =  13.20; // Sensor's local frame
    double positionRecoMaxPoint = 0.71; // 0.72;
    double photekSignalThreshold = 200.0;
    double noiseAmpThreshold  = 15.0; // 12.0; // 7.0;
    double signalAmpThreshold = 15.0; // 12.0; // 7.0;
    bool uses2022Pix = true;
    bool isHorizontal = true;
    bool enablePositionReconstruction = true;
    int minPixHits = 0;
    int minStripHits = 6;
    int CFD_threshold = 50;
    // std::vector<double> positionRecoPar = {0.250000, -0.706613, -5.565170, 36.746184, -97.191069}; // Iter1
    std::vector<double> positionRecoPar = {0.250000, -0.709684, -5.430126, 34.929432, -88.611179}; // Iter2
    // std::vector<std::vector<double>> sensorEdges = {{-3.0, -2.0}, {1.0, 7.6}};
    // std::vector<std::vector<double>> sensorEdges = {{-2.0, -4.8}, {2.0, 4.8}}; // Sensor's local frame
    std::vector<std::vector<double>> sensorEdges = {{-2.5, -13.0}, {1.3, 13.0}}; // Sensor's local frame
    std::vector<std::vector<double>> sensorEdgesTight = {{stripCenterXPosition[highGoodStripIndex], -11.5}, {stripCenterXPosition[lowGoodStripIndex], 11.5}}; // Sensor's local frame
    int centerGoodStripIndex = 4;
	double leftHighGainX = stripCenterXPosition[centerGoodStripIndex] - (stripWidth/2);
	double rightHighGainX = stripCenterXPosition[centerGoodStripIndex] + (stripWidth/2);
	double leftLowGainX = stripCenterXPosition[centerGoodStripIndex] - (pitch/2) - (stripWidth/2);
	double rightLowGainX = stripCenterXPosition[centerGoodStripIndex] - (pitch/2) + (stripWidth/2);
	std::vector<utility::ROI> regionsOfIntrest = {{"highGain", leftHighGainX,rightHighGainX, -11.5,11.5},{"lowGain", leftLowGainX,rightLowGainX, -11.5,11.5}};
};


class CFD : public DefaultGeometry
{
public:
    // 
    // Used lecroy scope channels 0-7
    // Channel one is spy, channel two is CFD output, and channel 8 is photek

    CFD(const int v=0) : voltage(v){}
    const int voltage;
    std::map<int, std::vector<int>> indexToGeometryMap = {{0,{0,0}}, {1,{0,1}}, {2,{0,2}}, {3,{0,3}}, {4,{0,4}}, {5,{0,5}}, {6,{0,6}}, {7,{1,0}}};   
    std::vector<std::vector<int>> geometry = {{0,1}, {7}};
    std::map<int, bool> acLGADChannelMap = {{0,true}, {1,true}, {2,false}, {3,false}, {4,false}, {5,false}, {6,false}, {7,false}};
    std::map<int, double> amplitudeCorrectionFactor = {{0,1.}, {1,1.}, {2,1.}, {3,1.}, {4,1.}, {5,1.}, {6,1.}, {7,1.0}};
    std::map<int, double> timeCalibrationCorrection = {{0,0.62594}, {1,0.038095}, {2,0.0}, {3,0.0}, {4,0.0}, {5,0.0}, {6,0.0}, {7,0.0}};
    //double stripWidth = 0.100;
    //double pitch = 0.500;
    double sensorCenter  = 0.0; // Lab-Tracker's frame
    double sensorCenterY = 0.0; // Lab-Tracker's frame
    //std::vector<double> stripCenterXPosition = {2.332, 1.849, 1.339, 0.843, 0.335, -0.195, -0.681, 0.0};
    int numLGADchannels = 2;
    int lowGoodStripIndex = 0;
    int highGoodStripIndex = 1;
    double alpha = 0.00;
    double beta  = 0.00;
    double gamma = 0.00;
    double z_dut = -2.00;
    double xBinSize = 0.015;
    double yBinSize = 0.015;
    double xmin = -0.2; // Sensor's local frame
    double xmax =  1.5; // Sensor's local frame
    double ymin = -0.2; // Sensor's local frame
    double ymax =  1.5; // Sensor's local frame
    //double positionRecoMaxPoint = 0.77;
    double photekSignalThreshold = 100.0;
    double photekSignalMax = 280.0; //in mV
    double noiseAmpThreshold  = 5.0;
    double signalAmpThreshold = 5.0;
    bool uses2022Pix = true;
    bool isHorizontal = true;
    bool enablePositionReconstruction = false;
    int minPixHits = 4;
    int minStripHits = 12;
    int CFD_threshold = 20;
    std::vector<double> positionRecoPar = {0.250000, -0.610460, -2.619740, 23.242264, -92.980050, 106.189949};
    //std::vector<std::vector<double>> sensorEdges = {{-2.48, 1.15}, {-1.18, 2.45}}; // Sensor's local frame
    std::vector<std::vector<double>> sensorEdges = {{-2.35, 0.15}, {-1.05, 1.45}}; // Sensor's local frame
    std::vector<std::vector<double>> sensorEdgesTight = {{stripCenterXPosition[highGoodStripIndex], -4.6}, {stripCenterXPosition[lowGoodStripIndex], 4.6}}; // Sensor's local frame
    //std::vector<utility::ROI> regionsOfIntrest = {{"hot", 0.90,1.10, -1.5,-0.5},{"cold", 0.90,1.10, -3.5,-2.5},{"gap", 0.70,0.80, 0.5,2.5},
    //                                              {"hot_ySlice", -1.95,1.95, -1.5,-0.25}, {"cold_ySlice", -1.95,1.95, -4.15,-2.90},
    //                                              {"hotspot", -1.95,1.95, -1.50,-0.50}};
};


class HPK_20um_500x500um_E600_2x2PadGeometry : public DefaultGeometry
{
public:
    // HPK 2022 Mapping set
    // Used lecroy scope channels 0-7
    // scope channel 0-3 was AC pads on FNAL board, 4 was the same sensor type AC channel on UCSC board, 5-6 were 50D and scope channel 7 was the photek
    // ----- -----
    // |1 0| |4 x|           -----
    // |2 3| |x x|           |777|
    // ----- -----           |777|
    //                       -----
    // 
    HPK_20um_500x500um_E600_2x2PadGeometry(const int v=0) : voltage(v){}
    const int voltage;
    std::map<int, std::vector<int>> indexToGeometryMap = {{0,{0,1}}, {1,{0,0}}, {2,{1,0}}, {3,{1,1}}, {4,{2,0}}, {5,{2,1}}, {7,{3,0}}};
    std::vector<std::vector<int>> geometry = {{1,0},{2,3},{4,5},{7}};
    std::map<int, bool> acLGADChannelMap = {{0,true}, {1,true}, {2,true}, {3,true}, {4,true}, {5, false}, {6, false}, {7,false}};
    int numLGADchannels = 5;
    int extraChannelIndex = 4;
    int lowGoodStripIndex = 0;
    int highGoodStripIndex = 2;
    std::map<int, double> amplitudeCorrectionFactor = {{0,1.0}, {1,1.0}, {2,1.0}, {3,1.0}, {4,1.0}, {5,0.0}, {6,1.0}, {7,1.0}};
    std::map<int, double> timeCalibrationCorrection = {{0,1.9320245},{1,1.9407506}, {2,1.8931535}, {3,1.907246289}, {4,1.7342231}, {5,2.0}, {6,2.0}, {7,0.0}};
    double stripWidth = 0.5; 
    double pitch = 0.5;
    double sensorCenter =-2.0;// Lab-Tracker's frame ->  y_dut
    double sensorCenterY = 2.0; // Lab-Tracker's frame -> -x_dut
    std::vector<double> stripCenterXPosition = {-1.5,-2.5, -2.5, -1.5, -1.4, 0.0, 0.0, -2.0};
    //std::vector<double> stripCenterYPosition = {0.0, 10.641, 10.641, 10.141, 10.141, 0.0};
    double alpha = 0.0;
    double beta  = 0.0;
    double gamma = 0.0;
    double z_dut = -10.0;
    double xmin = 0.3;
    double xmax = 2.3;
    double ymin =  -4.8;
    double ymax = -3.2; 
    double xBinSize = 0.05;
    double yBinSize = 0.05;
    double photekSignalThreshold = 50.0;
    double noiseAmpThreshold = 15.0;
    double signalAmpThreshold = 15.0; 
    int minPixHits = 4;
    int minStripHits = 12;
    int CFD_threshold = 50;
    bool isPadSensor = true; 
    bool enablePositionReconstruction = false;
    bool enablePositionReconstructionPad = true;
    std::vector<double> positionRecoParTop = {-0.494315,  1.28059, 1.92055, -9.89445, 11.8025, -4.01589};
    std::vector<double> positionRecoParBot = {-0.0849671, -3.72958, 25.6829, -63.7924, 70.3368, -28.3888};
    std::vector<double> positionRecoParRight = {-0.046495, -3.91451, 24.6937, -57.5006, 59.3214, -22.163};
    std::vector<double> positionRecoParLeft = {0.0339823, -5.42069, 33.1184, -78.8264, 84.4803, -33.3587};
    //std::vector<std::vector<double>> sensorEdges = {{-3.5 , -4.0}, { 0.5, 0.0}}; //square interior of pads
    std::vector<std::vector<double>> sensorEdges = {{0.45 , -4.4}, { 1.45, -3.4}}; //square interior of pads
    std::vector<std::vector<double>> sensorEdgesExtra = {{1.6 , -4.0}, { 1.9, -3.7}}; //square interior of pads
    //std::vector<std::vector<double>> ySlices = {{10.05, 10.35}, {10.55, 10.85}};
    //std::vector<std::vector<double>> xSlices = {{-6.1, -5.8}, {-5.6, -5.3}};
    //std::vector<std::vector<double>> boxes_XY ={{-6.1, -5.8,10.05, 10.35}}; 
};

class HPK_30um_500x500um_E600_2x2PadGeometry : public DefaultGeometry
{
public:
    // HPK 2022 Mapping set
    // Used lecroy scope channels 0-7
    // scope channel 0-3 was AC pads on FNAL board, 4 was the same sensor type AC channel on UCSC board, 5-6 were 50D and scope channel 7 was the photek
    // ----- -----
    // |1 0| |4 x|           -----
    // |2 3| |x x|           |777|
    // ----- -----           |777|
    //                       -----
    //
    HPK_30um_500x500um_E600_2x2PadGeometry(const int v=0) : voltage(v){}
    const int voltage;
    std::map<int, std::vector<int>> indexToGeometryMap = {{0,{0,1}}, {1,{0,0}}, {2,{1,0}}, {3,{1,1}}, {4,{2,0}}, {5,{2,1}}, {7,{3,0}}};
    std::vector<std::vector<int>> geometry = {{1,0},{2,3},{4,5},{7}};
    std::map<int, bool> acLGADChannelMap = {{0,true}, {1,true}, {2,true}, {3,true}, {4,true}, {5, false}, {6, false}, {7,false}};
    int numLGADchannels = 5;
    int extraChannelIndex = 4;
    int lowGoodStripIndex = 0;
    int highGoodStripIndex = 2;
    std::map<int, double> amplitudeCorrectionFactor = {{0,1.0}, {1,1.0}, {2,1.0}, {3,1.0}, {4,1.0}, {5,0.0}, {6,1.0}, {7,1.0}};
    std::map<int, double> timeCalibrationCorrection = {{0,1.8435231}, {1,1.8658946}, {2,1.8200936}, {3,1.8310432}, {4,1.6554349}, {5,2.0}, {6,2.0}, {7,0.0}};
    double stripWidth = 0.5; 
    double pitch = 0.5;
    double sensorCenter =-2.0;// Lab-Tracker's frame ->  y_dut
    double sensorCenterY = 2.0; // Lab-Tracker's frame -> -x_dut
    std::vector<double> stripCenterXPosition = {-1.5,-2.5, -2.5, -1.5, -1.4, 0.0, 0.0, -2.0};
    //std::vector<double> stripCenterYPosition = {0.0, 10.641, 10.641, 10.141, 10.141, 0.0};
    double alpha = 0.0;
    double beta  = 0.0;
    double gamma = 0.0;
    double z_dut = -10.0;
    double xmin = -0.6;
    double xmax =  1.8;
    double ymin =  -4.8;
    double ymax = -3.2; 
    double xBinSize = 0.05;
    double yBinSize = 0.05;
    double photekSignalThreshold = 50.0;
    double noiseAmpThreshold = 15.0;
    double signalAmpThreshold = 15.0; 
    int minPixHits = 4;
    int minStripHits = 12;
    int CFD_threshold = 50;
    bool isPadSensor = true; 
    bool enablePositionReconstruction = false;
    bool enablePositionReconstructionPad = true;
    std::vector<double> positionRecoParTop = {-0.494315,  1.28059, 1.92055, -9.89445, 11.8025, -4.01589};
    std::vector<double> positionRecoParBot = {-0.0849671, -3.72958, 25.6829, -63.7924, 70.3368, -28.3888};
    std::vector<double> positionRecoParRight = {-0.046495, -3.91451, 24.6937, -57.5006, 59.3214, -22.163};
    std::vector<double> positionRecoParLeft = {0.0339823, -5.42069, 33.1184, -78.8264, 84.4803, -33.3587};
    //std::vector<std::vector<double>> sensorEdges = {{-3.5 , -4.0}, { 0.5, 0.0}}; //square interior of pads
    std::vector<std::vector<double>> sensorEdges = {{0.5 , -4.5}, { 1.4, -3.6}}; //square interior of pads
    std::vector<std::vector<double>> sensorEdgesExtra = {{-0.1 , -4.14}, { 0.45, -3.65}}; //square interior of pads
    //std::vector<std::vector<double>> ySlices = {{10.05, 10.35}, {10.55, 10.85}};
    //std::vector<std::vector<double>> xSlices = {{-6.1, -5.8}, {-5.6, -5.3}};
    //std::vector<std::vector<double>> boxes_XY ={{-6.1, -5.8,10.05, 10.35}}; 
};

class HPK_50um_500x500um_E600_2x2PadGeometry : public DefaultGeometry
{
public:
    // HPK 2022 Mapping set
    // Used lecroy scope channels 0-7
    // scope channel 0-3 was AC pads on FNAL board, 4 was the same sensor type AC channel on UCSC board, 5-6 were 50D and scope channel 7 was the photek
    // ----- -----
    // |1 0| |4 x|           -----
    // |2 3| |x x|           |777|
    // ----- -----           |777|
    //                       -----
    //
    HPK_50um_500x500um_E600_2x2PadGeometry(const int v=0) : voltage(v){}
    const int voltage;
    std::map<int, std::vector<int>> indexToGeometryMap = {{0,{0,1}}, {1,{0,0}}, {2,{1,0}}, {3,{1,1}}, {4,{2,0}}, {5,{2,1}}, {7,{3,0}}};
    std::vector<std::vector<int>> geometry = {{1,0},{2,3},{4,5},{7}};
    std::map<int, bool> acLGADChannelMap = {{0,true}, {1,true}, {2,true}, {3,true}, {4,true}, {5, false}, {6, false}, {7,false}};
    int numLGADchannels = 5;
    int extraChannelIndex = 4;
    int lowGoodStripIndex = 0;
    int highGoodStripIndex = 2;
    std::map<int, double> amplitudeCorrectionFactor = {{0,1.0}, {1,1.0}, {2,1.0}, {3,1.0}, {4,1.0}, {5,0.0}, {6,1.0}, {7,1.0}};
    std::map<int, double> timeCalibrationCorrection = {{0,1.7194699}, {1,1.7460299}, {2,1.7017298}, {3,1.7091336}, {4,1.5604737}, {5,2.0}, {6,2.0}, {7,0.0}};
    double stripWidth = 0.5; 
    double pitch = 0.5;
    double sensorCenter =-2.0;// Lab-Tracker's frame ->  y_dut
    double sensorCenterY = 2.0; // Lab-Tracker's frame -> -x_dut
    std::vector<double> stripCenterXPosition = {-1.5,-2.5, -2.5, -1.5, -1.4, 0.0, 0.0, -2.0};
    //std::vector<double> stripCenterYPosition = {0.0, 10.641, 10.641, 10.141, 10.141, 0.0};
    double alpha = 0.0;
    double beta  = 0.0;
    double gamma = 0.0;
    double z_dut = -10.0;
    double xmin = -1.0;
    double xmax =  2.0;
    double ymin = -5.0;
    double ymax = -3.0; 
    double xBinSize = 0.15;
    double yBinSize = 0.15;
    double photekSignalThreshold = 50.0;
    double noiseAmpThreshold = 15.0;
    double signalAmpThreshold = 15.0; 
    int minPixHits = 4;
    int minStripHits = 12;
    int CFD_threshold = 50;
    bool isPadSensor = true; 
    bool enablePositionReconstruction = false;
    bool enablePositionReconstructionPad = true;
    std::vector<double> positionRecoParTop = {-0.494315,  1.28059, 1.92055, -9.89445, 11.8025, -4.01589};
    std::vector<double> positionRecoParBot = {-0.0849671, -3.72958, 25.6829, -63.7924, 70.3368, -28.3888};
    std::vector<double> positionRecoParRight = {-0.046495, -3.91451, 24.6937, -57.5006, 59.3214, -22.163};
    std::vector<double> positionRecoParLeft = {0.0339823, -5.42069, 33.1184, -78.8264, 84.4803, -33.3587};
    //std::vector<std::vector<double>> sensorEdges = {{-3.5 , -4.0}, { 0.5, 0.0}}; //square interior of pads
    std::vector<std::vector<double>> sensorEdges = {{-0.6 , -4.75}, { 0.35, -3.8}}; //square interior of pads
    std::vector<std::vector<double>> sensorEdgesExtra = {{1.0 , -3.95}, { 1.4, -3.65}}; //square interior of pads
    //std::vector<std::vector<double>> ySlices = {{10.05, 10.35}, {10.55, 10.85}};
    //std::vector<std::vector<double>> xSlices = {{-6.1, -5.8}, {-5.6, -5.3}};
    //std::vector<std::vector<double>> boxes_XY ={{-6.1, -5.8,10.05, 10.35}}; 
};


//===========================================
//                  NOISE
//===========================================

class HPK_W4_17_2_217V_92P3attn_StripsGeometry : public DefaultGeometry
{
public:
    // 
    // Used lecroy scope channels 0-7
    // Scope channel 0-6 was AC channels, and scope channel 7 was the photek
    // 
    // |-----------|             -----
    // | 0 0 0 0 0 |             |777|
    // | 1 1 1 1 1 |             |777|
    // | 2 2 2 2 2 |             -----
    // | 3 3 3 3 3 |
    // | 4 4 4 4 4 |
    // | 5 5 5 5 5 |
    // | 6 6 6 6 6 |
    // |-----------|

    HPK_W4_17_2_217V_92P3attn_StripsGeometry(const int v=0) : voltage(v){}
    const int voltage;
    std::map<int, std::vector<int>> indexToGeometryMap = {{0,{0,0}}, {1,{0,1}}, {2,{0,2}}, {3,{1,0}}};   
    std::vector<std::vector<int>> geometry = {{0,1,2},{3}};
    std::map<int, bool> acLGADChannelMap = {{0,true}, {1,true}, {2,true}, {3,false}};
    std::map<int, double> amplitudeCorrectionFactor = {{0,1.0}, {1,1.0}, {2,1.0},{3,1.0}};
    // std::map<int, double> timeCalibrationCorrection = {{0,-44.407430}, {1,-44.516147}, {2,-43.758894}, {3,0.0}};
    std::map<int, double> timeCalibrationCorrection = {{0,0.0}, {1,0.0}, {2,0.0}, {3,0.0}};
    double stripWidth = 0.050;
    double pitch = 0.500;
    std::vector<double> stripCenterXPosition = {0.5, 0.0, -0.5, 0.0}; // Iter3
    int numLGADchannels = 3;
    int lowGoodStripIndex = 0;
    int highGoodStripIndex = 2;
    double xBinSize = 0.05;
    double yBinSize = 0.1;
    double xmin = -0.80-stripWidth/2; // Sensor's local frame
    double xmax =  0.80+stripWidth/2; // Sensor's local frame
    double ymin = -2.9-stripWidth/2; // Sensor's local frame
    double ymax = 2.9+stripWidth/2; // Sensor's local frame
    double positionRecoMaxPoint = 0.66;
    double noiseAmpThreshold  = 0.0;
    double signalAmpThreshold = 0.0;
    bool enablePositionReconstruction = true;
    int CFD_threshold = 50;
    std::vector<double> positionRecoPar = {0.250000, -1.282863, -2.157824, 74.391135, -836.971302, 2942.375710};
    std::vector<std::vector<double>> sensorEdges = {{-0.7, -2.9}, {0.7, 2.9}}; // Sensor's local frame
    std::vector<std::vector<double>> sensorEdgesTight = {{stripCenterXPosition[highGoodStripIndex], -2.9}, {stripCenterXPosition[lowGoodStripIndex], 2.9}}; // Sensor's local frame
    int centerGoodStripIndex = 1;
    double leftHighGainX = stripCenterXPosition[centerGoodStripIndex] - (stripWidth/2);
    double rightHighGainX = stripCenterXPosition[centerGoodStripIndex] + (stripWidth/2);
    double leftLowGainX = stripCenterXPosition[centerGoodStripIndex] - (pitch/2) - (stripWidth/2);
    double rightLowGainX = stripCenterXPosition[centerGoodStripIndex] - (pitch/2) + (stripWidth/2);
    std::vector<utility::ROI> regionsOfIntrest = {{"highGain", leftHighGainX, rightHighGainX, -2.9, 2.9}, {"lowGain", leftLowGainX, rightLowGainX, -2.9, 2.9}};
};

class HPK_W4_17_2_218V_92P3attn_StripsGeometry : public DefaultGeometry
{
public:
    // 
    // Used lecroy scope channels 0-7
    // Scope channel 0-6 was AC channels, and scope channel 7 was the photek
    // 
    // |-----------|             -----
    // | 0 0 0 0 0 |             |777|
    // | 1 1 1 1 1 |             |777|
    // | 2 2 2 2 2 |             -----
    // | 3 3 3 3 3 |
    // | 4 4 4 4 4 |
    // | 5 5 5 5 5 |
    // | 6 6 6 6 6 |
    // |-----------|

    HPK_W4_17_2_218V_92P3attn_StripsGeometry(const int v=0) : voltage(v){}
    const int voltage;
    std::map<int, std::vector<int>> indexToGeometryMap = {{0,{0,0}}, {1,{0,1}}, {2,{0,2}}, {3,{1,0}}};   
    std::vector<std::vector<int>> geometry = {{0,1,2},{3}};
    std::map<int, bool> acLGADChannelMap = {{0,true}, {1,true}, {2,true}, {3,false}};
    std::map<int, double> amplitudeCorrectionFactor = {{0,1.0}, {1,1.0}, {2,1.0},{3,1.0}};
    std::map<int, double> timeCalibrationCorrection = {{0,-44.407430}, {1,-44.516147}, {2,-43.758894}, {3,0.0}};
    // std::map<int, double> timeCalibrationCorrection = {{0,0.0}, {1,0.0}, {2,0.0}, {3,0.0}};
    double stripWidth = 0.050;
    double pitch = 0.500;
    std::vector<double> stripCenterXPosition = {0.5, 0.0, -0.5, 0.0}; // Iter3
    int numLGADchannels = 3;
    int lowGoodStripIndex = 0;
    int highGoodStripIndex = 2;
    double xBinSize = 0.05;
    double yBinSize = 0.1;
    double xmin = -0.80-stripWidth/2; // Sensor's local frame
    double xmax =  0.80+stripWidth/2; // Sensor's local frame
    double ymin = -2.9-stripWidth/2; // Sensor's local frame
    double ymax = 2.9+stripWidth/2; // Sensor's local frame
    double positionRecoMaxPoint = 0.66;
    double noiseAmpThreshold  = 0.0;
    double signalAmpThreshold = 0.0;
    bool enablePositionReconstruction = true;
    int CFD_threshold = 50;
    std::vector<double> positionRecoPar = {0.250000, -1.282863, -2.157824, 74.391135, -836.971302, 2942.375710};
    std::vector<std::vector<double>> sensorEdges = {{-0.7, -2.9}, {0.7, 2.9}}; // Sensor's local frame
    std::vector<std::vector<double>> sensorEdgesTight = {{stripCenterXPosition[highGoodStripIndex], -2.9}, {stripCenterXPosition[lowGoodStripIndex], 2.9}}; // Sensor's local frame
    int centerGoodStripIndex = 1;
    double leftHighGainX = stripCenterXPosition[centerGoodStripIndex] - (stripWidth/2);
    double rightHighGainX = stripCenterXPosition[centerGoodStripIndex] + (stripWidth/2);
    double leftLowGainX = stripCenterXPosition[centerGoodStripIndex] - (pitch/2) - (stripWidth/2);
    double rightLowGainX = stripCenterXPosition[centerGoodStripIndex] - (pitch/2) + (stripWidth/2);
    std::vector<utility::ROI> regionsOfIntrest = {{"highGain", leftHighGainX, rightHighGainX, -2.9, 2.9}, {"lowGain", leftLowGainX, rightLowGainX, -2.9, 2.9}};
};

class HPK_W4_17_2_219V_92P3attn_StripsGeometry : public DefaultGeometry
{
public:
    // 
    // Used lecroy scope channels 0-7
    // Scope channel 0-6 was AC channels, and scope channel 7 was the photek
    // 
    // |-----------|             -----
    // | 0 0 0 0 0 |             |777|
    // | 1 1 1 1 1 |             |777|
    // | 2 2 2 2 2 |             -----
    // | 3 3 3 3 3 |
    // | 4 4 4 4 4 |
    // | 5 5 5 5 5 |
    // | 6 6 6 6 6 |
    // |-----------|

    HPK_W4_17_2_219V_92P3attn_StripsGeometry(const int v=0) : voltage(v){}
    const int voltage;
    std::map<int, std::vector<int>> indexToGeometryMap = {{0,{0,0}}, {1,{0,1}}, {2,{0,2}}, {3,{1,0}}};   
    std::vector<std::vector<int>> geometry = {{0,1,2},{3}};
    std::map<int, bool> acLGADChannelMap = {{0,true}, {1,true}, {2,true}, {3,false}};
    std::map<int, double> amplitudeCorrectionFactor = {{0,1.0}, {1,1.0}, {2,1.0},{3,1.0}};
    std::map<int, double> timeCalibrationCorrection = {{0,-44.407430}, {1,-44.516147}, {2,-43.758894}, {3,0.0}};
    // std::map<int, double> timeCalibrationCorrection = {{0,0.0}, {1,0.0}, {2,0.0}, {3,0.0}};
    double stripWidth = 0.050;
    double pitch = 0.500;
    std::vector<double> stripCenterXPosition = {0.5, 0.0, -0.5, 0.0}; // Iter3
    int numLGADchannels = 3;
    int lowGoodStripIndex = 0;
    int highGoodStripIndex = 2;
    double xBinSize = 0.05;
    double yBinSize = 0.1;
    double xmin = -0.80-stripWidth/2; // Sensor's local frame
    double xmax =  0.80+stripWidth/2; // Sensor's local frame
    double ymin = -2.9-stripWidth/2; // Sensor's local frame
    double ymax = 2.9+stripWidth/2; // Sensor's local frame
    double positionRecoMaxPoint = 0.66;
    double noiseAmpThreshold  = 0.0;
    double signalAmpThreshold = 0.0;
    bool enablePositionReconstruction = true;
    int CFD_threshold = 50;
    std::vector<double> positionRecoPar = {0.250000, -1.282863, -2.157824, 74.391135, -836.971302, 2942.375710};
    std::vector<std::vector<double>> sensorEdges = {{-0.7, -2.9}, {0.7, 2.9}}; // Sensor's local frame
    std::vector<std::vector<double>> sensorEdgesTight = {{stripCenterXPosition[highGoodStripIndex], -2.9}, {stripCenterXPosition[lowGoodStripIndex], 2.9}}; // Sensor's local frame
    int centerGoodStripIndex = 1;
    double leftHighGainX = stripCenterXPosition[centerGoodStripIndex] - (stripWidth/2);
    double rightHighGainX = stripCenterXPosition[centerGoodStripIndex] + (stripWidth/2);
    double leftLowGainX = stripCenterXPosition[centerGoodStripIndex] - (pitch/2) - (stripWidth/2);
    double rightLowGainX = stripCenterXPosition[centerGoodStripIndex] - (pitch/2) + (stripWidth/2);
    std::vector<utility::ROI> regionsOfIntrest = {{"highGain", leftHighGainX, rightHighGainX, -2.9, 2.9}, {"lowGain", leftLowGainX, rightLowGainX, -2.9, 2.9}};
};

class HPK_W4_17_2_220V_92P3attn_StripsGeometry : public DefaultGeometry
{
public:
    // 
    // Used lecroy scope channels 0-7
    // Scope channel 0-6 was AC channels, and scope channel 7 was the photek
    // 
    // |-----------|             -----
    // | 0 0 0 0 0 |             |777|
    // | 1 1 1 1 1 |             |777|
    // | 2 2 2 2 2 |             -----
    // | 3 3 3 3 3 |
    // | 4 4 4 4 4 |
    // | 5 5 5 5 5 |
    // | 6 6 6 6 6 |
    // |-----------|

    HPK_W4_17_2_220V_92P3attn_StripsGeometry(const int v=0) : voltage(v){}
    const int voltage;
    std::map<int, std::vector<int>> indexToGeometryMap = {{0,{0,0}}, {1,{0,1}}, {2,{0,2}}, {3,{1,0}}};   
    std::vector<std::vector<int>> geometry = {{0,1,2},{3}};
    std::map<int, bool> acLGADChannelMap = {{0,true}, {1,true}, {2,true}, {3,false}};
    std::map<int, double> amplitudeCorrectionFactor = {{0,1.0}, {1,1.0}, {2,1.0},{3,1.0}};
    std::map<int, double> timeCalibrationCorrection = {{0,-44.407430}, {1,-44.516147}, {2,-43.758894}, {3,0.0}};
    // std::map<int, double> timeCalibrationCorrection = {{0,0.0}, {1,0.0}, {2,0.0}, {3,0.0}};
    double stripWidth = 0.050;
    double pitch = 0.500;
    std::vector<double> stripCenterXPosition = {0.5, 0.0, -0.5, 0.0}; // Iter3
    int numLGADchannels = 3;
    int lowGoodStripIndex = 0;
    int highGoodStripIndex = 2;
    double xBinSize = 0.05;
    double yBinSize = 0.1;
    double xmin = -0.80-stripWidth/2; // Sensor's local frame
    double xmax =  0.80+stripWidth/2; // Sensor's local frame
    double ymin = -2.9-stripWidth/2; // Sensor's local frame
    double ymax = 2.9+stripWidth/2; // Sensor's local frame
    double positionRecoMaxPoint = 0.66;
    double noiseAmpThreshold  = 0.0;
    double signalAmpThreshold = 0.0;
    bool enablePositionReconstruction = true;
    int CFD_threshold = 50;
    std::vector<double> positionRecoPar = {0.250000, -1.282863, -2.157824, 74.391135, -836.971302, 2942.375710};
    std::vector<std::vector<double>> sensorEdges = {{-0.7, -2.9}, {0.7, 2.9}}; // Sensor's local frame
    std::vector<std::vector<double>> sensorEdgesTight = {{stripCenterXPosition[highGoodStripIndex], -2.9}, {stripCenterXPosition[lowGoodStripIndex], 2.9}}; // Sensor's local frame
    int centerGoodStripIndex = 1;
    double leftHighGainX = stripCenterXPosition[centerGoodStripIndex] - (stripWidth/2);
    double rightHighGainX = stripCenterXPosition[centerGoodStripIndex] + (stripWidth/2);
    double leftLowGainX = stripCenterXPosition[centerGoodStripIndex] - (pitch/2) - (stripWidth/2);
    double rightLowGainX = stripCenterXPosition[centerGoodStripIndex] - (pitch/2) + (stripWidth/2);
    std::vector<utility::ROI> regionsOfIntrest = {{"highGain", leftHighGainX, rightHighGainX, -2.9, 2.9}, {"lowGain", leftLowGainX, rightLowGainX, -2.9, 2.9}};
};

class HPK_W4_17_2_221V_92P3attn_StripsGeometry : public DefaultGeometry
{
public:
    // 
    // Used lecroy scope channels 0-7
    // Scope channel 0-6 was AC channels, and scope channel 7 was the photek
    // 
    // |-----------|             -----
    // | 0 0 0 0 0 |             |777|
    // | 1 1 1 1 1 |             |777|
    // | 2 2 2 2 2 |             -----
    // | 3 3 3 3 3 |
    // | 4 4 4 4 4 |
    // | 5 5 5 5 5 |
    // | 6 6 6 6 6 |
    // |-----------|

    HPK_W4_17_2_221V_92P3attn_StripsGeometry(const int v=0) : voltage(v){}
    const int voltage;
    std::map<int, std::vector<int>> indexToGeometryMap = {{0,{0,0}}, {1,{0,1}}, {2,{0,2}}, {3,{1,0}}};   
    std::vector<std::vector<int>> geometry = {{0,1,2},{3}};
    std::map<int, bool> acLGADChannelMap = {{0,true}, {1,true}, {2,true}, {3,false}};
    std::map<int, double> amplitudeCorrectionFactor = {{0,1.0}, {1,1.0}, {2,1.0},{3,1.0}};
    std::map<int, double> timeCalibrationCorrection = {{0,-44.407430}, {1,-44.516147}, {2,-43.758894}, {3,0.0}};
    // std::map<int, double> timeCalibrationCorrection = {{0,0.0}, {1,0.0}, {2,0.0}, {3,0.0}};
    double stripWidth = 0.050;
    double pitch = 0.500;
    std::vector<double> stripCenterXPosition = {0.5, 0.0, -0.5, 0.0}; // Iter3
    int numLGADchannels = 3;
    int lowGoodStripIndex = 0;
    int highGoodStripIndex = 2;
    double xBinSize = 0.05;
    double yBinSize = 0.1;
    double xmin = -0.80-stripWidth/2; // Sensor's local frame
    double xmax =  0.80+stripWidth/2; // Sensor's local frame
    double ymin = -2.9-stripWidth/2; // Sensor's local frame
    double ymax = 2.9+stripWidth/2; // Sensor's local frame
    double positionRecoMaxPoint = 0.66;
    double noiseAmpThreshold  = 0.0;
    double signalAmpThreshold = 0.0;
    bool enablePositionReconstruction = true;
    int CFD_threshold = 50;
    std::vector<double> positionRecoPar = {0.250000, -1.282863, -2.157824, 74.391135, -836.971302, 2942.375710};
    std::vector<std::vector<double>> sensorEdges = {{-0.7, -2.9}, {0.7, 2.9}}; // Sensor's local frame
    std::vector<std::vector<double>> sensorEdgesTight = {{stripCenterXPosition[highGoodStripIndex], -2.9}, {stripCenterXPosition[lowGoodStripIndex], 2.9}}; // Sensor's local frame
    int centerGoodStripIndex = 1;
    double leftHighGainX = stripCenterXPosition[centerGoodStripIndex] - (stripWidth/2);
    double rightHighGainX = stripCenterXPosition[centerGoodStripIndex] + (stripWidth/2);
    double leftLowGainX = stripCenterXPosition[centerGoodStripIndex] - (pitch/2) - (stripWidth/2);
    double rightLowGainX = stripCenterXPosition[centerGoodStripIndex] - (pitch/2) + (stripWidth/2);
    std::vector<utility::ROI> regionsOfIntrest = {{"highGain", leftHighGainX, rightHighGainX, -2.9, 2.9}, {"lowGain", leftLowGainX, rightLowGainX, -2.9, 2.9}};
};

class HPK_W4_17_2_222V_92P3attn_StripsGeometry : public DefaultGeometry
{
public:
    // 
    // Used lecroy scope channels 0-7
    // Scope channel 0-6 was AC channels, and scope channel 7 was the photek
    // 
    // |-----------|             -----
    // | 0 0 0 0 0 |             |777|
    // | 1 1 1 1 1 |             |777|
    // | 2 2 2 2 2 |             -----
    // | 3 3 3 3 3 |
    // | 4 4 4 4 4 |
    // | 5 5 5 5 5 |
    // | 6 6 6 6 6 |
    // |-----------|

    HPK_W4_17_2_222V_92P3attn_StripsGeometry(const int v=0) : voltage(v){}
    const int voltage;
    std::map<int, std::vector<int>> indexToGeometryMap = {{0,{0,0}}, {1,{0,1}}, {2,{0,2}}, {3,{1,0}}};   
    std::vector<std::vector<int>> geometry = {{0,1,2},{3}};
    std::map<int, bool> acLGADChannelMap = {{0,true}, {1,true}, {2,true}, {3,false}};
    std::map<int, double> amplitudeCorrectionFactor = {{0,1.0}, {1,1.0}, {2,1.0},{3,1.0}};
    std::map<int, double> timeCalibrationCorrection = {{0,-44.407430}, {1,-44.516147}, {2,-43.758894}, {3,0.0}};
    // std::map<int, double> timeCalibrationCorrection = {{0,0.0}, {1,0.0}, {2,0.0}, {3,0.0}};
    double stripWidth = 0.050;
    double pitch = 0.500;
    std::vector<double> stripCenterXPosition = {0.5, 0.0, -0.5, 0.0}; // Iter3
    int numLGADchannels = 3;
    int lowGoodStripIndex = 0;
    int highGoodStripIndex = 2;
    double xBinSize = 0.05;
    double yBinSize = 0.1;
    double xmin = -0.80-stripWidth/2; // Sensor's local frame
    double xmax =  0.80+stripWidth/2; // Sensor's local frame
    double ymin = -2.9-stripWidth/2; // Sensor's local frame
    double ymax = 2.9+stripWidth/2; // Sensor's local frame
    double positionRecoMaxPoint = 0.66;
    double noiseAmpThreshold  = 0.0;
    double signalAmpThreshold = 0.0;
    bool enablePositionReconstruction = true;
    int CFD_threshold = 50;
    std::vector<double> positionRecoPar = {0.250000, -1.282863, -2.157824, 74.391135, -836.971302, 2942.375710};
    std::vector<std::vector<double>> sensorEdges = {{-0.7, -2.9}, {0.7, 2.9}}; // Sensor's local frame
    std::vector<std::vector<double>> sensorEdgesTight = {{stripCenterXPosition[highGoodStripIndex], -2.9}, {stripCenterXPosition[lowGoodStripIndex], 2.9}}; // Sensor's local frame
    int centerGoodStripIndex = 1;
    double leftHighGainX = stripCenterXPosition[centerGoodStripIndex] - (stripWidth/2);
    double rightHighGainX = stripCenterXPosition[centerGoodStripIndex] + (stripWidth/2);
    double leftLowGainX = stripCenterXPosition[centerGoodStripIndex] - (pitch/2) - (stripWidth/2);
    double rightLowGainX = stripCenterXPosition[centerGoodStripIndex] - (pitch/2) + (stripWidth/2);
    std::vector<utility::ROI> regionsOfIntrest = {{"highGain", leftHighGainX, rightHighGainX, -2.9, 2.9}, {"lowGain", leftLowGainX, rightLowGainX, -2.9, 2.9}};
};

/*
class run2_HPK_W4_17_2_223V_92P3attn_StripsGeometry : public DefaultGeometry
{
public:
    // 
    // Used lecroy scope channels 0-7
    // Scope channel 0-6 was AC channels, and scope channel 7 was the photek
    // 
    // |-----------|             -----
    // | 0 0 0 0 0 |             |777|
    // | 1 1 1 1 1 |             |777|
    // | 2 2 2 2 2 |             -----
    // | 3 3 3 3 3 |
    // | 4 4 4 4 4 |
    // | 5 5 5 5 5 |
    // | 6 6 6 6 6 |
    // |-----------|

    run2_HPK_W4_17_2_223V_92P3attn_StripsGeometry(const int v=0) : voltage(v){}
    const int voltage;
    std::map<int, std::vector<int>> indexToGeometryMap = {{0,{0,0}}, {1,{0,1}}, {2,{0,2}}, {3,{1,0}}};   
    std::vector<std::vector<int>> geometry = {{0,1,2},{3}};
    std::map<int, bool> acLGADChannelMap = {{0,true}, {1,true}, {2,true}, {3,false}};
    std::map<int, double> amplitudeCorrectionFactor = {{0,1.0}, {1,1.0}, {2,1.0},{3,1.0}};
    std::map<int, double> timeCalibrationCorrection = {{0,-44.407430}, {1,-44.516147}, {2,-43.758894}, {3,0.0}};
    // std::map<int, double> timeCalibrationCorrection = {{0,0.0}, {1,0.0}, {2,0.0}, {3,0.0}};
    double stripWidth = 0.050;
    double pitch = 0.500;
    std::vector<double> stripCenterXPosition = {0.5, 0.0, -0.5, 0.0}; // Iter3
    int numLGADchannels = 3;
    int lowGoodStripIndex = 0;
    int highGoodStripIndex = 2;
    double xBinSize = 0.05;
    double yBinSize = 0.1;
    double xmin = -0.80-stripWidth/2; // Sensor's local frame
    double xmax =  0.80+stripWidth/2; // Sensor's local frame
    double ymin = -2.9-stripWidth/2; // Sensor's local frame
    double ymax = 2.9+stripWidth/2; // Sensor's local frame
    double positionRecoMaxPoint = 0.66;
    double noiseAmpThreshold  = 0.0;
    double signalAmpThreshold = 0.0;
    bool enablePositionReconstruction = true;
    int CFD_threshold = 50;
    std::vector<double> positionRecoPar = {0.250000, -1.282863, -2.157824, 74.391135, -836.971302, 2942.375710};
    std::vector<std::vector<double>> sensorEdges = {{-0.7, -2.9}, {0.7, 2.9}}; // Sensor's local frame
    std::vector<std::vector<double>> sensorEdgesTight = {{stripCenterXPosition[highGoodStripIndex], -2.9}, {stripCenterXPosition[lowGoodStripIndex], 2.9}}; // Sensor's local frame
    int centerGoodStripIndex = 1;
    double leftHighGainX = stripCenterXPosition[centerGoodStripIndex] - (stripWidth/2);
    double rightHighGainX = stripCenterXPosition[centerGoodStripIndex] + (stripWidth/2);
    double leftLowGainX = stripCenterXPosition[centerGoodStripIndex] - (pitch/2) - (stripWidth/2);
    double rightLowGainX = stripCenterXPosition[centerGoodStripIndex] - (pitch/2) + (stripWidth/2);
    std::vector<utility::ROI> regionsOfIntrest = {{"highGain", leftHighGainX, rightHighGainX, -2.9, 2.9}, {"lowGain", leftLowGainX, rightLowGainX, -2.9, 2.9}};
};
*/
class HPK_W4_17_2_224V_92P3attn_StripsGeometry : public DefaultGeometry
{
public:
    // 
    // Used lecroy scope channels 0-7
    // Scope channel 0-6 was AC channels, and scope channel 7 was the photek
    // 
    // |-----------|             -----
    // | 0 0 0 0 0 |             |777|
    // | 1 1 1 1 1 |             |777|
    // | 2 2 2 2 2 |             -----
    // | 3 3 3 3 3 |
    // | 4 4 4 4 4 |
    // | 5 5 5 5 5 |
    // | 6 6 6 6 6 |
    // |-----------|

    HPK_W4_17_2_224V_92P3attn_StripsGeometry(const int v=0) : voltage(v){}
    const int voltage;
    std::map<int, std::vector<int>> indexToGeometryMap = {{0,{0,0}}, {1,{0,1}}, {2,{0,2}}, {3,{1,0}}};   
    std::vector<std::vector<int>> geometry = {{0,1,2},{3}};
    std::map<int, bool> acLGADChannelMap = {{0,true}, {1,true}, {2,true}, {3,false}};
    std::map<int, double> amplitudeCorrectionFactor = {{0,1.0}, {1,1.0}, {2,1.0},{3,1.0}};
    std::map<int, double> timeCalibrationCorrection = {{0,-44.407430}, {1,-44.516147}, {2,-43.758894}, {3,0.0}};
    // std::map<int, double> timeCalibrationCorrection = {{0,0.0}, {1,0.0}, {2,0.0}, {3,0.0}};
    double stripWidth = 0.050;
    double pitch = 0.500;
    std::vector<double> stripCenterXPosition = {0.5, 0.0, -0.5, 0.0}; // Iter3
    int numLGADchannels = 3;
    int lowGoodStripIndex = 0;
    int highGoodStripIndex = 2;
    double xBinSize = 0.05;
    double yBinSize = 0.1;
    double xmin = -0.80-stripWidth/2; // Sensor's local frame
    double xmax =  0.80+stripWidth/2; // Sensor's local frame
    double ymin = -2.9-stripWidth/2; // Sensor's local frame
    double ymax = 2.9+stripWidth/2; // Sensor's local frame
    double positionRecoMaxPoint = 0.66;
    double noiseAmpThreshold  = 0.0;
    double signalAmpThreshold = 0.0;
    bool enablePositionReconstruction = true;
    int CFD_threshold = 50;
    std::vector<double> positionRecoPar = {0.250000, -1.282863, -2.157824, 74.391135, -836.971302, 2942.375710};
    std::vector<std::vector<double>> sensorEdges = {{-0.7, -2.9}, {0.7, 2.9}}; // Sensor's local frame
    std::vector<std::vector<double>> sensorEdgesTight = {{stripCenterXPosition[highGoodStripIndex], -2.9}, {stripCenterXPosition[lowGoodStripIndex], 2.9}}; // Sensor's local frame
    int centerGoodStripIndex = 1;
    double leftHighGainX = stripCenterXPosition[centerGoodStripIndex] - (stripWidth/2);
    double rightHighGainX = stripCenterXPosition[centerGoodStripIndex] + (stripWidth/2);
    double leftLowGainX = stripCenterXPosition[centerGoodStripIndex] - (pitch/2) - (stripWidth/2);
    double rightLowGainX = stripCenterXPosition[centerGoodStripIndex] - (pitch/2) + (stripWidth/2);
    std::vector<utility::ROI> regionsOfIntrest = {{"highGain", leftHighGainX, rightHighGainX, -2.9, 2.9}, {"lowGain", leftLowGainX, rightLowGainX, -2.9, 2.9}};
};

class HPK_W4_17_2_225V_92P3attn_StripsGeometry : public DefaultGeometry
{
public:
    // 
    // Used lecroy scope channels 0-7
    // Scope channel 0-6 was AC channels, and scope channel 7 was the photek
    // 
    // |-----------|             -----
    // | 0 0 0 0 0 |             |777|
    // | 1 1 1 1 1 |             |777|
    // | 2 2 2 2 2 |             -----
    // | 3 3 3 3 3 |
    // | 4 4 4 4 4 |
    // | 5 5 5 5 5 |
    // | 6 6 6 6 6 |
    // |-----------|

    HPK_W4_17_2_225V_92P3attn_StripsGeometry(const int v=0) : voltage(v){}
    const int voltage;
    std::map<int, std::vector<int>> indexToGeometryMap = {{0,{0,0}}, {1,{0,1}}, {2,{0,2}}, {3,{1,0}}};   
    std::vector<std::vector<int>> geometry = {{0,1,2},{3}};
    std::map<int, bool> acLGADChannelMap = {{0,true}, {1,true}, {2,true}, {3,false}};
    std::map<int, double> amplitudeCorrectionFactor = {{0,1.0}, {1,1.0}, {2,1.0},{3,1.0}};
    std::map<int, double> timeCalibrationCorrection = {{0,-44.407430}, {1,-44.516147}, {2,-43.758894}, {3,0.0}};
    // std::map<int, double> timeCalibrationCorrection = {{0,0.0}, {1,0.0}, {2,0.0}, {3,0.0}};
    double stripWidth = 0.050;
    double pitch = 0.500;
    std::vector<double> stripCenterXPosition = {0.5, 0.0, -0.5, 0.0}; // Iter3
    int numLGADchannels = 3;
    int lowGoodStripIndex = 0;
    int highGoodStripIndex = 2;
    double xBinSize = 0.05;
    double yBinSize = 0.1;
    double xmin = -0.80-stripWidth/2; // Sensor's local frame
    double xmax =  0.80+stripWidth/2; // Sensor's local frame
    double ymin = -2.9-stripWidth/2; // Sensor's local frame
    double ymax = 2.9+stripWidth/2; // Sensor's local frame
    double positionRecoMaxPoint = 0.66;
    double noiseAmpThreshold  = 0.0;
    double signalAmpThreshold = 0.0;
    bool enablePositionReconstruction = true;
    int CFD_threshold = 50;
    std::vector<double> positionRecoPar = {0.250000, -1.282863, -2.157824, 74.391135, -836.971302, 2942.375710};
    std::vector<std::vector<double>> sensorEdges = {{-0.7, -2.9}, {0.7, 2.9}}; // Sensor's local frame
    std::vector<std::vector<double>> sensorEdgesTight = {{stripCenterXPosition[highGoodStripIndex], -2.9}, {stripCenterXPosition[lowGoodStripIndex], 2.9}}; // Sensor's local frame
    int centerGoodStripIndex = 1;
    double leftHighGainX = stripCenterXPosition[centerGoodStripIndex] - (stripWidth/2);
    double rightHighGainX = stripCenterXPosition[centerGoodStripIndex] + (stripWidth/2);
    double leftLowGainX = stripCenterXPosition[centerGoodStripIndex] - (pitch/2) - (stripWidth/2);
    double rightLowGainX = stripCenterXPosition[centerGoodStripIndex] - (pitch/2) + (stripWidth/2);
    std::vector<utility::ROI> regionsOfIntrest = {{"highGain", leftHighGainX, rightHighGainX, -2.9, 2.9}, {"lowGain", leftLowGainX, rightLowGainX, -2.9, 2.9}};
};

class HPK_W4_17_2_226V_92P3attn_StripsGeometry : public DefaultGeometry
{
public:
    // 
    // Used lecroy scope channels 0-7
    // Scope channel 0-6 was AC channels, and scope channel 7 was the photek
    // 
    // |-----------|             -----
    // | 0 0 0 0 0 |             |777|
    // | 1 1 1 1 1 |             |777|
    // | 2 2 2 2 2 |             -----
    // | 3 3 3 3 3 |
    // | 4 4 4 4 4 |
    // | 5 5 5 5 5 |
    // | 6 6 6 6 6 |
    // |-----------|

    HPK_W4_17_2_226V_92P3attn_StripsGeometry(const int v=0) : voltage(v){}
    const int voltage;
    std::map<int, std::vector<int>> indexToGeometryMap = {{0,{0,0}}, {1,{0,1}}, {2,{0,2}}, {3,{1,0}}};   
    std::vector<std::vector<int>> geometry = {{0,1,2},{3}};
    std::map<int, bool> acLGADChannelMap = {{0,true}, {1,true}, {2,true}, {3,false}};
    std::map<int, double> amplitudeCorrectionFactor = {{0,1.0}, {1,1.0}, {2,1.0},{3,1.0}};
    std::map<int, double> timeCalibrationCorrection = {{0,-44.407430}, {1,-44.516147}, {2,-43.758894}, {3,0.0}};
    // std::map<int, double> timeCalibrationCorrection = {{0,0.0}, {1,0.0}, {2,0.0}, {3,0.0}};
    double stripWidth = 0.050;
    double pitch = 0.500;
    std::vector<double> stripCenterXPosition = {0.5, 0.0, -0.5, 0.0}; // Iter3
    int numLGADchannels = 3;
    int lowGoodStripIndex = 0;
    int highGoodStripIndex = 2;
    double xBinSize = 0.05;
    double yBinSize = 0.1;
    double xmin = -0.80-stripWidth/2; // Sensor's local frame
    double xmax =  0.80+stripWidth/2; // Sensor's local frame
    double ymin = -2.9-stripWidth/2; // Sensor's local frame
    double ymax = 2.9+stripWidth/2; // Sensor's local frame
    double positionRecoMaxPoint = 0.66;
    double noiseAmpThreshold  = 0.0;
    double signalAmpThreshold = 0.0;
    bool enablePositionReconstruction = true;
    int CFD_threshold = 50;
    std::vector<double> positionRecoPar = {0.250000, -1.282863, -2.157824, 74.391135, -836.971302, 2942.375710};
    std::vector<std::vector<double>> sensorEdges = {{-0.7, -2.9}, {0.7, 2.9}}; // Sensor's local frame
    std::vector<std::vector<double>> sensorEdgesTight = {{stripCenterXPosition[highGoodStripIndex], -2.9}, {stripCenterXPosition[lowGoodStripIndex], 2.9}}; // Sensor's local frame
    int centerGoodStripIndex = 1;
    double leftHighGainX = stripCenterXPosition[centerGoodStripIndex] - (stripWidth/2);
    double rightHighGainX = stripCenterXPosition[centerGoodStripIndex] + (stripWidth/2);
    double leftLowGainX = stripCenterXPosition[centerGoodStripIndex] - (pitch/2) - (stripWidth/2);
    double rightLowGainX = stripCenterXPosition[centerGoodStripIndex] - (pitch/2) + (stripWidth/2);
    std::vector<utility::ROI> regionsOfIntrest = {{"highGain", leftHighGainX, rightHighGainX, -2.9, 2.9}, {"lowGain", leftLowGainX, rightLowGainX, -2.9, 2.9}};
};

class HPK_W4_17_2_227V_92P3attn_StripsGeometry : public DefaultGeometry
{
public:
    // 
    // Used lecroy scope channels 0-7
    // Scope channel 0-6 was AC channels, and scope channel 7 was the photek
    // 
    // |-----------|             -----
    // | 0 0 0 0 0 |             |777|
    // | 1 1 1 1 1 |             |777|
    // | 2 2 2 2 2 |             -----
    // | 3 3 3 3 3 |
    // | 4 4 4 4 4 |
    // | 5 5 5 5 5 |
    // | 6 6 6 6 6 |
    // |-----------|

    HPK_W4_17_2_227V_92P3attn_StripsGeometry(const int v=0) : voltage(v){}
    const int voltage;
    std::map<int, std::vector<int>> indexToGeometryMap = {{0,{0,0}}, {1,{0,1}}, {2,{0,2}}, {3,{1,0}}};   
    std::vector<std::vector<int>> geometry = {{0,1,2},{3}};
    std::map<int, bool> acLGADChannelMap = {{0,true}, {1,true}, {2,true}, {3,false}};
    std::map<int, double> amplitudeCorrectionFactor = {{0,1.0}, {1,1.0}, {2,1.0},{3,1.0}};
    std::map<int, double> timeCalibrationCorrection = {{0,-44.407430}, {1,-44.516147}, {2,-43.758894}, {3,0.0}};
    // std::map<int, double> timeCalibrationCorrection = {{0,0.0}, {1,0.0}, {2,0.0}, {3,0.0}};
    double stripWidth = 0.050;
    double pitch = 0.500;
    std::vector<double> stripCenterXPosition = {0.5, 0.0, -0.5, 0.0}; // Iter3
    int numLGADchannels = 3;
    int lowGoodStripIndex = 0;
    int highGoodStripIndex = 2;
    double xBinSize = 0.05;
    double yBinSize = 0.1;
    double xmin = -0.80-stripWidth/2; // Sensor's local frame
    double xmax =  0.80+stripWidth/2; // Sensor's local frame
    double ymin = -2.9-stripWidth/2; // Sensor's local frame
    double ymax = 2.9+stripWidth/2; // Sensor's local frame
    double positionRecoMaxPoint = 0.66;
    double noiseAmpThreshold  = 0.0;
    double signalAmpThreshold = 0.0;
    bool enablePositionReconstruction = true;
    int CFD_threshold = 50;
    std::vector<double> positionRecoPar = {0.250000, -1.282863, -2.157824, 74.391135, -836.971302, 2942.375710};
    std::vector<std::vector<double>> sensorEdges = {{-0.7, -2.9}, {0.7, 2.9}}; // Sensor's local frame
    std::vector<std::vector<double>> sensorEdgesTight = {{stripCenterXPosition[highGoodStripIndex], -2.9}, {stripCenterXPosition[lowGoodStripIndex], 2.9}}; // Sensor's local frame
    int centerGoodStripIndex = 1;
    double leftHighGainX = stripCenterXPosition[centerGoodStripIndex] - (stripWidth/2);
    double rightHighGainX = stripCenterXPosition[centerGoodStripIndex] + (stripWidth/2);
    double leftLowGainX = stripCenterXPosition[centerGoodStripIndex] - (pitch/2) - (stripWidth/2);
    double rightLowGainX = stripCenterXPosition[centerGoodStripIndex] - (pitch/2) + (stripWidth/2);
    std::vector<utility::ROI> regionsOfIntrest = {{"highGain", leftHighGainX, rightHighGainX, -2.9, 2.9}, {"lowGain", leftLowGainX, rightLowGainX, -2.9, 2.9}};
};

// ============================================
//         Risetime vs amp study
// ============================================


class HPK_W9_15_2_121V_74attn_rtStudy_StripsGeometry : public DefaultGeometry
{
public:
    // 
    // Used lecroy scope channels 0-7
    // Scope channel 0-6 was AC channels, and scope channel 7 was the photek
    // 
    // |-----------|             -----
    // | 0 0 0 0 0 |             |777|
    // | 1 1 1 1 1 |             |777|
    // | 2 2 2 2 2 |             -----
    // | 3 3 3 3 3 |
    // | 4 4 4 4 4 |
    // | 5 5 5 5 5 |
    // | 6 6 6 6 6 |
    // |-----------|

    HPK_W9_15_2_121V_74attn_rtStudy_StripsGeometry(const int v=0) : voltage(v){}
    const int voltage;
    std::map<int, std::vector<int>> indexToGeometryMap = {{0,{0,0}}, {1,{0,1}}, {2,{0,2}}, {3,{1,0}}};   
    std::vector<std::vector<int>> geometry = {{0,1,2},{3}};
    std::map<int, bool> acLGADChannelMap = {{0,true}, {1,true}, {2,true}, {3,false}};
    std::map<int, double> amplitudeCorrectionFactor = {{0,1.0}, {1,1.0}, {2,1.0},{3,1.0}};
    std::map<int, double> timeCalibrationCorrection = {{0,-44.005707}, {1,-44.189732}, {2,-44.049251}, {3,0.0}};
    // std::map<int, double> timeCalibrationCorrection = {{0,0.0}, {1,0.0}, {2,0.0}, {3,0.0}};
    double stripWidth = 0.050;
    double pitch = 0.500;
    std::vector<double> stripCenterXPosition = {0.5, 0.0, -0.5, 0.0}; // Iter3
    int numLGADchannels = 3;
    int lowGoodStripIndex = 0;
    int highGoodStripIndex = 2;
    double xBinSize = 0.025;
    double yBinSize = 0.1;
    double xmin = -0.80-xBinSize/2; // Sensor's local frame
    double xmax =  0.80+xBinSize/2; // Sensor's local frame
    double ymin = -2.9-yBinSize/2; // Sensor's local frame
    double ymax = 2.9+yBinSize/2; // Sensor's local frame
    double positionRecoMaxPoint = 0.78;
    double noiseAmpThreshold  = 15.0;
    double signalAmpThreshold = 15.0;
    bool enablePositionReconstruction = true;
    int CFD_threshold = 50;
    std::vector<double> positionRecoPar = {0.250000, -0.580028, 0.215066, -0.836168, -9.005392, 17.517882};
    std::vector<std::vector<double>> sensorEdges = {{-0.7, -2.9}, {0.7, 2.9}}; // Sensor's local frame
    std::vector<std::vector<double>> sensorEdgesTight = {{stripCenterXPosition[highGoodStripIndex], -2.9}, {stripCenterXPosition[lowGoodStripIndex], 2.9}}; // Sensor's local frame
    double offset = stripWidth;
    int centerGoodStripIndex = 1;
    double centerStripX = stripCenterXPosition[centerGoodStripIndex];
    double leftGapX = centerStripX - (pitch/2);
	double rightGapX = centerStripX + (pitch/2);
	std::vector<utility::ROI> regionsOfIntrest = {{"nearStripX", centerStripX + offset - stripWidth/2, centerStripX + offset + stripWidth/2, -2.5,2.5}, {"leftGapX", leftGapX - stripWidth/2, leftGapX + stripWidth/2, -2.5,2.5}, {"rightGapX", rightGapX - stripWidth/2, rightGapX + stripWidth/2, -2.5,2.5}};
};


class HPK_W9_15_2_121V_75attn_rtStudy_StripsGeometry : public DefaultGeometry
{
public:
    // 
    // Used lecroy scope channels 0-7
    // Scope channel 0-6 was AC channels, and scope channel 7 was the photek
    // 
    // |-----------|             -----
    // | 0 0 0 0 0 |             |777|
    // | 1 1 1 1 1 |             |777|
    // | 2 2 2 2 2 |             -----
    // | 3 3 3 3 3 |
    // | 4 4 4 4 4 |
    // | 5 5 5 5 5 |
    // | 6 6 6 6 6 |
    // |-----------|

    HPK_W9_15_2_121V_75attn_rtStudy_StripsGeometry(const int v=0) : voltage(v){}
    const int voltage;
    std::map<int, std::vector<int>> indexToGeometryMap = {{0,{0,0}}, {1,{0,1}}, {2,{0,2}}, {3,{1,0}}};   
    std::vector<std::vector<int>> geometry = {{0,1,2},{3}};
    std::map<int, bool> acLGADChannelMap = {{0,true}, {1,true}, {2,true}, {3,false}};
    std::map<int, double> amplitudeCorrectionFactor = {{0,1.0}, {1,1.0}, {2,1.0},{3,1.0}};
    std::map<int, double> timeCalibrationCorrection = {{0,-44.005707}, {1,-44.189732}, {2,-44.049251}, {3,0.0}};
    // std::map<int, double> timeCalibrationCorrection = {{0,0.0}, {1,0.0}, {2,0.0}, {3,0.0}};
    double stripWidth = 0.050;
    double pitch = 0.500;
    std::vector<double> stripCenterXPosition = {0.5, 0.0, -0.5, 0.0}; // Iter3
    int numLGADchannels = 3;
    int lowGoodStripIndex = 0;
    int highGoodStripIndex = 2;
    double xBinSize = 0.025;
    double yBinSize = 0.1;
    double xmin = -0.80-xBinSize/2; // Sensor's local frame
    double xmax =  0.80+xBinSize/2; // Sensor's local frame
    double ymin = -2.9-yBinSize/2; // Sensor's local frame
    double ymax = 2.9+yBinSize/2; // Sensor's local frame
    double positionRecoMaxPoint = 0.78;
    double noiseAmpThreshold  = 15.0;
    double signalAmpThreshold = 15.0;
    bool enablePositionReconstruction = true;
    int CFD_threshold = 50;
    std::vector<double> positionRecoPar = {0.250000, -0.580028, 0.215066, -0.836168, -9.005392, 17.517882};
    std::vector<std::vector<double>> sensorEdges = {{-0.7, -2.9}, {0.7, 2.9}}; // Sensor's local frame
    std::vector<std::vector<double>> sensorEdgesTight = {{stripCenterXPosition[highGoodStripIndex], -2.9}, {stripCenterXPosition[lowGoodStripIndex], 2.9}}; // Sensor's local frame
    double offset = stripWidth;
    int centerGoodStripIndex = 1;
    double centerStripX = stripCenterXPosition[centerGoodStripIndex];
    double leftGapX = centerStripX - (pitch/2);
	double rightGapX = centerStripX + (pitch/2);
	std::vector<utility::ROI> regionsOfIntrest = {{"nearStripX", centerStripX + offset - stripWidth/2, centerStripX + offset + stripWidth/2, -2.5,2.5}, {"leftGapX", leftGapX - stripWidth/2, leftGapX + stripWidth/2, -2.5,2.5}, {"rightGapX", rightGapX - stripWidth/2, rightGapX + stripWidth/2, -2.5,2.5}};
};


class HPK_W9_15_2_121V_76attn_rtStudy_StripsGeometry : public DefaultGeometry
{
public:
    // 
    // Used lecroy scope channels 0-7
    // Scope channel 0-6 was AC channels, and scope channel 7 was the photek
    // 
    // |-----------|             -----
    // | 0 0 0 0 0 |             |777|
    // | 1 1 1 1 1 |             |777|
    // | 2 2 2 2 2 |             -----
    // | 3 3 3 3 3 |
    // | 4 4 4 4 4 |
    // | 5 5 5 5 5 |
    // | 6 6 6 6 6 |
    // |-----------|

    HPK_W9_15_2_121V_76attn_rtStudy_StripsGeometry(const int v=0) : voltage(v){}
    const int voltage;
    std::map<int, std::vector<int>> indexToGeometryMap = {{0,{0,0}}, {1,{0,1}}, {2,{0,2}}, {3,{1,0}}};   
    std::vector<std::vector<int>> geometry = {{0,1,2},{3}};
    std::map<int, bool> acLGADChannelMap = {{0,true}, {1,true}, {2,true}, {3,false}};
    std::map<int, double> amplitudeCorrectionFactor = {{0,1.0}, {1,1.0}, {2,1.0},{3,1.0}};
    std::map<int, double> timeCalibrationCorrection = {{0,-44.005707}, {1,-44.189732}, {2,-44.049251}, {3,0.0}};
    // std::map<int, double> timeCalibrationCorrection = {{0,0.0}, {1,0.0}, {2,0.0}, {3,0.0}};
    double stripWidth = 0.050;
    double pitch = 0.500;
    std::vector<double> stripCenterXPosition = {0.5, 0.0, -0.5, 0.0}; // Iter3
    int numLGADchannels = 3;
    int lowGoodStripIndex = 0;
    int highGoodStripIndex = 2;
    double xBinSize = 0.025;
    double yBinSize = 0.1;
    double xmin = -0.80-xBinSize/2; // Sensor's local frame
    double xmax =  0.80+xBinSize/2; // Sensor's local frame
    double ymin = -2.9-yBinSize/2; // Sensor's local frame
    double ymax = 2.9+yBinSize/2; // Sensor's local frame
    double positionRecoMaxPoint = 0.78;
    double noiseAmpThreshold  = 15.0;
    double signalAmpThreshold = 15.0;
    bool enablePositionReconstruction = true;
    int CFD_threshold = 50;
    std::vector<double> positionRecoPar = {0.250000, -0.580028, 0.215066, -0.836168, -9.005392, 17.517882};
    std::vector<std::vector<double>> sensorEdges = {{-0.7, -2.9}, {0.7, 2.9}}; // Sensor's local frame
    std::vector<std::vector<double>> sensorEdgesTight = {{stripCenterXPosition[highGoodStripIndex], -2.9}, {stripCenterXPosition[lowGoodStripIndex], 2.9}}; // Sensor's local frame
    double offset = stripWidth;
    int centerGoodStripIndex = 1;
    double centerStripX = stripCenterXPosition[centerGoodStripIndex];
    double leftGapX = centerStripX - (pitch/2);
	double rightGapX = centerStripX + (pitch/2);
	std::vector<utility::ROI> regionsOfIntrest = {{"nearStripX", centerStripX + offset - stripWidth/2, centerStripX + offset + stripWidth/2, -2.5,2.5}, {"leftGapX", leftGapX - stripWidth/2, leftGapX + stripWidth/2, -2.5,2.5}, {"rightGapX", rightGapX - stripWidth/2, rightGapX + stripWidth/2, -2.5,2.5}};
};



class HPK_W9_15_2_121V_77attn_rtStudy_StripsGeometry : public DefaultGeometry
{
public:
    // 
    // Used lecroy scope channels 0-7
    // Scope channel 0-6 was AC channels, and scope channel 7 was the photek
    // 
    // |-----------|             -----
    // | 0 0 0 0 0 |             |777|
    // | 1 1 1 1 1 |             |777|
    // | 2 2 2 2 2 |             -----
    // | 3 3 3 3 3 |
    // | 4 4 4 4 4 |
    // | 5 5 5 5 5 |
    // | 6 6 6 6 6 |
    // |-----------|

    HPK_W9_15_2_121V_77attn_rtStudy_StripsGeometry(const int v=0) : voltage(v){}
    const int voltage;
    std::map<int, std::vector<int>> indexToGeometryMap = {{0,{0,0}}, {1,{0,1}}, {2,{0,2}}, {3,{1,0}}};   
    std::vector<std::vector<int>> geometry = {{0,1,2},{3}};
    std::map<int, bool> acLGADChannelMap = {{0,true}, {1,true}, {2,true}, {3,false}};
    std::map<int, double> amplitudeCorrectionFactor = {{0,1.0}, {1,1.0}, {2,1.0},{3,1.0}};
    std::map<int, double> timeCalibrationCorrection = {{0,-44.005707}, {1,-44.189732}, {2,-44.049251}, {3,0.0}};
    // std::map<int, double> timeCalibrationCorrection = {{0,0.0}, {1,0.0}, {2,0.0}, {3,0.0}};
    double stripWidth = 0.050;
    double pitch = 0.500;
    std::vector<double> stripCenterXPosition = {0.5, 0.0, -0.5, 0.0}; // Iter3
    int numLGADchannels = 3;
    int lowGoodStripIndex = 0;
    int highGoodStripIndex = 2;
    double xBinSize = 0.025;
    double yBinSize = 0.1;
    double xmin = -0.80-xBinSize/2; // Sensor's local frame
    double xmax =  0.80+xBinSize/2; // Sensor's local frame
    double ymin = -2.9-yBinSize/2; // Sensor's local frame
    double ymax = 2.9+yBinSize/2; // Sensor's local frame
    double positionRecoMaxPoint = 0.78;
    double noiseAmpThreshold  = 15.0;
    double signalAmpThreshold = 15.0;
    bool enablePositionReconstruction = true;
    int CFD_threshold = 50;
    std::vector<double> positionRecoPar = {0.250000, -0.580028, 0.215066, -0.836168, -9.005392, 17.517882};
    std::vector<std::vector<double>> sensorEdges = {{-0.7, -2.9}, {0.7, 2.9}}; // Sensor's local frame
    std::vector<std::vector<double>> sensorEdgesTight = {{stripCenterXPosition[highGoodStripIndex], -2.9}, {stripCenterXPosition[lowGoodStripIndex], 2.9}}; // Sensor's local frame
    double offset = stripWidth;
    int centerGoodStripIndex = 1;
    double centerStripX = stripCenterXPosition[centerGoodStripIndex];
    double leftGapX = centerStripX - (pitch/2);
	double rightGapX = centerStripX + (pitch/2);
	std::vector<utility::ROI> regionsOfIntrest = {{"nearStripX", centerStripX + offset - stripWidth/2, centerStripX + offset + stripWidth/2, -2.5,2.5}, {"leftGapX", leftGapX - stripWidth/2, leftGapX + stripWidth/2, -2.5,2.5}, {"rightGapX", rightGapX - stripWidth/2, rightGapX + stripWidth/2, -2.5,2.5}};
};


class HPK_W9_15_2_121V_78attn_rtStudy_StripsGeometry : public DefaultGeometry
{
public:
    // 
    // Used lecroy scope channels 0-7
    // Scope channel 0-6 was AC channels, and scope channel 7 was the photek
    // 
    // |-----------|             -----
    // | 0 0 0 0 0 |             |777|
    // | 1 1 1 1 1 |             |777|
    // | 2 2 2 2 2 |             -----
    // | 3 3 3 3 3 |
    // | 4 4 4 4 4 |
    // | 5 5 5 5 5 |
    // | 6 6 6 6 6 |
    // |-----------|

    HPK_W9_15_2_121V_78attn_rtStudy_StripsGeometry(const int v=0) : voltage(v){}
    const int voltage;
    std::map<int, std::vector<int>> indexToGeometryMap = {{0,{0,0}}, {1,{0,1}}, {2,{0,2}}, {3,{1,0}}};   
    std::vector<std::vector<int>> geometry = {{0,1,2},{3}};
    std::map<int, bool> acLGADChannelMap = {{0,true}, {1,true}, {2,true}, {3,false}};
    std::map<int, double> amplitudeCorrectionFactor = {{0,1.0}, {1,1.0}, {2,1.0},{3,1.0}};
    std::map<int, double> timeCalibrationCorrection = {{0,-44.005707}, {1,-44.189732}, {2,-44.049251}, {3,0.0}};
    // std::map<int, double> timeCalibrationCorrection = {{0,0.0}, {1,0.0}, {2,0.0}, {3,0.0}};
    double stripWidth = 0.050;
    double pitch = 0.500;
    std::vector<double> stripCenterXPosition = {0.5, 0.0, -0.5, 0.0}; // Iter3
    int numLGADchannels = 3;
    int lowGoodStripIndex = 0;
    int highGoodStripIndex = 2;
    double xBinSize = 0.025;
    double yBinSize = 0.1;
    double xmin = -0.80-xBinSize/2; // Sensor's local frame
    double xmax =  0.80+xBinSize/2; // Sensor's local frame
    double ymin = -2.9-yBinSize/2; // Sensor's local frame
    double ymax = 2.9+yBinSize/2; // Sensor's local frame
    double positionRecoMaxPoint = 0.78;
    double noiseAmpThreshold  = 15.0;
    double signalAmpThreshold = 15.0;
    bool enablePositionReconstruction = true;
    int CFD_threshold = 50;
    std::vector<double> positionRecoPar = {0.250000, -0.580028, 0.215066, -0.836168, -9.005392, 17.517882};
    std::vector<std::vector<double>> sensorEdges = {{-0.7, -2.9}, {0.7, 2.9}}; // Sensor's local frame
    std::vector<std::vector<double>> sensorEdgesTight = {{stripCenterXPosition[highGoodStripIndex], -2.9}, {stripCenterXPosition[lowGoodStripIndex], 2.9}}; // Sensor's local frame
    double offset = stripWidth;
    int centerGoodStripIndex = 1;
    double centerStripX = stripCenterXPosition[centerGoodStripIndex];
    double leftGapX = centerStripX - (pitch/2);
	double rightGapX = centerStripX + (pitch/2);
	std::vector<utility::ROI> regionsOfIntrest = {{"nearStripX", centerStripX + offset - stripWidth/2, centerStripX + offset + stripWidth/2, -2.5,2.5}, {"leftGapX", leftGapX - stripWidth/2, leftGapX + stripWidth/2, -2.5,2.5}, {"rightGapX", rightGapX - stripWidth/2, rightGapX + stripWidth/2, -2.5,2.5}};
};



class HPK_W9_15_2_121V_79attn_rtStudy_StripsGeometry : public DefaultGeometry
{
public:
    // 
    // Used lecroy scope channels 0-7
    // Scope channel 0-6 was AC channels, and scope channel 7 was the photek
    // 
    // |-----------|             -----
    // | 0 0 0 0 0 |             |777|
    // | 1 1 1 1 1 |             |777|
    // | 2 2 2 2 2 |             -----
    // | 3 3 3 3 3 |
    // | 4 4 4 4 4 |
    // | 5 5 5 5 5 |
    // | 6 6 6 6 6 |
    // |-----------|

    HPK_W9_15_2_121V_79attn_rtStudy_StripsGeometry(const int v=0) : voltage(v){}
    const int voltage;
    std::map<int, std::vector<int>> indexToGeometryMap = {{0,{0,0}}, {1,{0,1}}, {2,{0,2}}, {3,{1,0}}};   
    std::vector<std::vector<int>> geometry = {{0,1,2},{3}};
    std::map<int, bool> acLGADChannelMap = {{0,true}, {1,true}, {2,true}, {3,false}};
    std::map<int, double> amplitudeCorrectionFactor = {{0,1.0}, {1,1.0}, {2,1.0},{3,1.0}};
    std::map<int, double> timeCalibrationCorrection = {{0,-44.005707}, {1,-44.189732}, {2,-44.049251}, {3,0.0}};
    // std::map<int, double> timeCalibrationCorrection = {{0,0.0}, {1,0.0}, {2,0.0}, {3,0.0}};
    double stripWidth = 0.050;
    double pitch = 0.500;
    std::vector<double> stripCenterXPosition = {0.5, 0.0, -0.5, 0.0}; // Iter3
    int numLGADchannels = 3;
    int lowGoodStripIndex = 0;
    int highGoodStripIndex = 2;
    double xBinSize = 0.025;
    double yBinSize = 0.1;
    double xmin = -0.80-xBinSize/2; // Sensor's local frame
    double xmax =  0.80+xBinSize/2; // Sensor's local frame
    double ymin = -2.9-yBinSize/2; // Sensor's local frame
    double ymax = 2.9+yBinSize/2; // Sensor's local frame
    double positionRecoMaxPoint = 0.78;
    double noiseAmpThreshold  = 15.0;
    double signalAmpThreshold = 15.0;
    bool enablePositionReconstruction = true;
    int CFD_threshold = 50;
    std::vector<double> positionRecoPar = {0.250000, -0.580028, 0.215066, -0.836168, -9.005392, 17.517882};
    std::vector<std::vector<double>> sensorEdges = {{-0.7, -2.9}, {0.7, 2.9}}; // Sensor's local frame
    std::vector<std::vector<double>> sensorEdgesTight = {{stripCenterXPosition[highGoodStripIndex], -2.9}, {stripCenterXPosition[lowGoodStripIndex], 2.9}}; // Sensor's local frame
    double offset = stripWidth;
    int centerGoodStripIndex = 1;
    double centerStripX = stripCenterXPosition[centerGoodStripIndex];
    double leftGapX = centerStripX - (pitch/2);
	double rightGapX = centerStripX + (pitch/2);
	std::vector<utility::ROI> regionsOfIntrest = {{"nearStripX", centerStripX + offset - stripWidth/2, centerStripX + offset + stripWidth/2, -2.5,2.5}, {"leftGapX", leftGapX - stripWidth/2, leftGapX + stripWidth/2, -2.5,2.5}, {"rightGapX", rightGapX - stripWidth/2, rightGapX + stripWidth/2, -2.5,2.5}};
};



class HPK_W9_15_2_121V_80attn_rtStudy_StripsGeometry : public DefaultGeometry
{
public:
    // 
    // Used lecroy scope channels 0-7
    // Scope channel 0-6 was AC channels, and scope channel 7 was the photek
    // 
    // |-----------|             -----
    // | 0 0 0 0 0 |             |777|
    // | 1 1 1 1 1 |             |777|
    // | 2 2 2 2 2 |             -----
    // | 3 3 3 3 3 |
    // | 4 4 4 4 4 |
    // | 5 5 5 5 5 |
    // | 6 6 6 6 6 |
    // |-----------|

    HPK_W9_15_2_121V_80attn_rtStudy_StripsGeometry(const int v=0) : voltage(v){}
    const int voltage;
    std::map<int, std::vector<int>> indexToGeometryMap = {{0,{0,0}}, {1,{0,1}}, {2,{0,2}}, {3,{1,0}}};   
    std::vector<std::vector<int>> geometry = {{0,1,2},{3}};
    std::map<int, bool> acLGADChannelMap = {{0,true}, {1,true}, {2,true}, {3,false}};
    std::map<int, double> amplitudeCorrectionFactor = {{0,1.0}, {1,1.0}, {2,1.0},{3,1.0}};
    std::map<int, double> timeCalibrationCorrection = {{0,-44.005707}, {1,-44.189732}, {2,-44.049251}, {3,0.0}};
    // std::map<int, double> timeCalibrationCorrection = {{0,0.0}, {1,0.0}, {2,0.0}, {3,0.0}};
    double stripWidth = 0.050;
    double pitch = 0.500;
    std::vector<double> stripCenterXPosition = {0.5, 0.0, -0.5, 0.0}; // Iter3
    int numLGADchannels = 3;
    int lowGoodStripIndex = 0;
    int highGoodStripIndex = 2;
    double xBinSize = 0.025;
    double yBinSize = 0.1;
    double xmin = -0.80-xBinSize/2; // Sensor's local frame
    double xmax =  0.80+xBinSize/2; // Sensor's local frame
    double ymin = -2.9-yBinSize/2; // Sensor's local frame
    double ymax = 2.9+yBinSize/2; // Sensor's local frame
    double positionRecoMaxPoint = 0.78;
    double noiseAmpThreshold  = 15.0;
    double signalAmpThreshold = 15.0;
    bool enablePositionReconstruction = true;
    int CFD_threshold = 50;
    std::vector<double> positionRecoPar = {0.250000, -0.580028, 0.215066, -0.836168, -9.005392, 17.517882};
    std::vector<std::vector<double>> sensorEdges = {{-0.7, -2.9}, {0.7, 2.9}}; // Sensor's local frame
    std::vector<std::vector<double>> sensorEdgesTight = {{stripCenterXPosition[highGoodStripIndex], -2.9}, {stripCenterXPosition[lowGoodStripIndex], 2.9}}; // Sensor's local frame
    double offset = stripWidth;
    int centerGoodStripIndex = 1;
    double centerStripX = stripCenterXPosition[centerGoodStripIndex];
    double leftGapX = centerStripX - (pitch/2);
	double rightGapX = centerStripX + (pitch/2);
	std::vector<utility::ROI> regionsOfIntrest = {{"nearStripX", centerStripX + offset - stripWidth/2, centerStripX + offset + stripWidth/2, -2.5,2.5}, {"leftGapX", leftGapX - stripWidth/2, leftGapX + stripWidth/2, -2.5,2.5}, {"rightGapX", rightGapX - stripWidth/2, rightGapX + stripWidth/2, -2.5,2.5}};
};


class HPK_W9_15_2_121V_81attn_rtStudy_StripsGeometry : public DefaultGeometry
{
public:
    // 
    // Used lecroy scope channels 0-7
    // Scope channel 0-6 was AC channels, and scope channel 7 was the photek
    // 
    // |-----------|             -----
    // | 0 0 0 0 0 |             |777|
    // | 1 1 1 1 1 |             |777|
    // | 2 2 2 2 2 |             -----
    // | 3 3 3 3 3 |
    // | 4 4 4 4 4 |
    // | 5 5 5 5 5 |
    // | 6 6 6 6 6 |
    // |-----------|

    HPK_W9_15_2_121V_81attn_rtStudy_StripsGeometry(const int v=0) : voltage(v){}
    const int voltage;
    std::map<int, std::vector<int>> indexToGeometryMap = {{0,{0,0}}, {1,{0,1}}, {2,{0,2}}, {3,{1,0}}};   
    std::vector<std::vector<int>> geometry = {{0,1,2},{3}};
    std::map<int, bool> acLGADChannelMap = {{0,true}, {1,true}, {2,true}, {3,false}};
    std::map<int, double> amplitudeCorrectionFactor = {{0,1.0}, {1,1.0}, {2,1.0},{3,1.0}};
    std::map<int, double> timeCalibrationCorrection = {{0,-44.005707}, {1,-44.189732}, {2,-44.049251}, {3,0.0}};
    // std::map<int, double> timeCalibrationCorrection = {{0,0.0}, {1,0.0}, {2,0.0}, {3,0.0}};
    double stripWidth = 0.050;
    double pitch = 0.500;
    std::vector<double> stripCenterXPosition = {0.5, 0.0, -0.5, 0.0}; // Iter3
    int numLGADchannels = 3;
    int lowGoodStripIndex = 0;
    int highGoodStripIndex = 2;
    double xBinSize = 0.025;
    double yBinSize = 0.1;
    double xmin = -0.80-xBinSize/2; // Sensor's local frame
    double xmax =  0.80+xBinSize/2; // Sensor's local frame
    double ymin = -2.9-yBinSize/2; // Sensor's local frame
    double ymax = 2.9+yBinSize/2; // Sensor's local frame
    double positionRecoMaxPoint = 0.78;
    double noiseAmpThreshold  = 15.0;
    double signalAmpThreshold = 15.0;
    bool enablePositionReconstruction = true;
    int CFD_threshold = 50;
    std::vector<double> positionRecoPar = {0.250000, -0.580028, 0.215066, -0.836168, -9.005392, 17.517882};
    std::vector<std::vector<double>> sensorEdges = {{-0.7, -2.9}, {0.7, 2.9}}; // Sensor's local frame
    std::vector<std::vector<double>> sensorEdgesTight = {{stripCenterXPosition[highGoodStripIndex], -2.9}, {stripCenterXPosition[lowGoodStripIndex], 2.9}}; // Sensor's local frame
    double offset = stripWidth;
    int centerGoodStripIndex = 1;
    double centerStripX = stripCenterXPosition[centerGoodStripIndex];
    double leftGapX = centerStripX - (pitch/2);
	double rightGapX = centerStripX + (pitch/2);
	std::vector<utility::ROI> regionsOfIntrest = {{"nearStripX", centerStripX + offset - stripWidth/2, centerStripX + offset + stripWidth/2, -2.5,2.5}, {"leftGapX", leftGapX - stripWidth/2, leftGapX + stripWidth/2, -2.5,2.5}, {"rightGapX", rightGapX - stripWidth/2, rightGapX + stripWidth/2, -2.5,2.5}};
};



class HPK_W9_15_2_121V_82attn_rtStudy_StripsGeometry : public DefaultGeometry
{
public:
    // 
    // Used lecroy scope channels 0-7
    // Scope channel 0-6 was AC channels, and scope channel 7 was the photek
    // 
    // |-----------|             -----
    // | 0 0 0 0 0 |             |777|
    // | 1 1 1 1 1 |             |777|
    // | 2 2 2 2 2 |             -----
    // | 3 3 3 3 3 |
    // | 4 4 4 4 4 |
    // | 5 5 5 5 5 |
    // | 6 6 6 6 6 |
    // |-----------|

    HPK_W9_15_2_121V_82attn_rtStudy_StripsGeometry(const int v=0) : voltage(v){}
    const int voltage;
    std::map<int, std::vector<int>> indexToGeometryMap = {{0,{0,0}}, {1,{0,1}}, {2,{0,2}}, {3,{1,0}}};   
    std::vector<std::vector<int>> geometry = {{0,1,2},{3}};
    std::map<int, bool> acLGADChannelMap = {{0,true}, {1,true}, {2,true}, {3,false}};
    std::map<int, double> amplitudeCorrectionFactor = {{0,1.0}, {1,1.0}, {2,1.0},{3,1.0}};
    std::map<int, double> timeCalibrationCorrection = {{0,-44.005707}, {1,-44.189732}, {2,-44.049251}, {3,0.0}};
    // std::map<int, double> timeCalibrationCorrection = {{0,0.0}, {1,0.0}, {2,0.0}, {3,0.0}};
    double stripWidth = 0.050;
    double pitch = 0.500;
    std::vector<double> stripCenterXPosition = {0.5, 0.0, -0.5, 0.0}; // Iter3
    int numLGADchannels = 3;
    int lowGoodStripIndex = 0;
    int highGoodStripIndex = 2;
    double xBinSize = 0.025;
    double yBinSize = 0.1;
    double xmin = -0.80-xBinSize/2; // Sensor's local frame
    double xmax =  0.80+xBinSize/2; // Sensor's local frame
    double ymin = -2.9-yBinSize/2; // Sensor's local frame
    double ymax = 2.9+yBinSize/2; // Sensor's local frame
    double positionRecoMaxPoint = 0.78;
    double noiseAmpThreshold  = 15.0;
    double signalAmpThreshold = 15.0;
    bool enablePositionReconstruction = true;
    int CFD_threshold = 50;
    std::vector<double> positionRecoPar = {0.250000, -0.580028, 0.215066, -0.836168, -9.005392, 17.517882};
    std::vector<std::vector<double>> sensorEdges = {{-0.7, -2.9}, {0.7, 2.9}}; // Sensor's local frame
    std::vector<std::vector<double>> sensorEdgesTight = {{stripCenterXPosition[highGoodStripIndex], -2.9}, {stripCenterXPosition[lowGoodStripIndex], 2.9}}; // Sensor's local frame
    double offset = stripWidth;
    int centerGoodStripIndex = 1;
    double centerStripX = stripCenterXPosition[centerGoodStripIndex];
    double leftGapX = centerStripX - (pitch/2);
	double rightGapX = centerStripX + (pitch/2);
	std::vector<utility::ROI> regionsOfIntrest = {{"nearStripX", centerStripX + offset - stripWidth/2, centerStripX + offset + stripWidth/2, -2.5,2.5}, {"leftGapX", leftGapX - stripWidth/2, leftGapX + stripWidth/2, -2.5,2.5}, {"rightGapX", rightGapX - stripWidth/2, rightGapX + stripWidth/2, -2.5,2.5}};
};




class HPK_W9_15_2_121V_82P5attn_rtStudy_StripsGeometry : public DefaultGeometry
{
public:
    // 
    // Used lecroy scope channels 0-7
    // Scope channel 0-6 was AC channels, and scope channel 7 was the photek
    // 
    // |-----------|             -----
    // | 0 0 0 0 0 |             |777|
    // | 1 1 1 1 1 |             |777|
    // | 2 2 2 2 2 |             -----
    // | 3 3 3 3 3 |
    // | 4 4 4 4 4 |
    // | 5 5 5 5 5 |
    // | 6 6 6 6 6 |
    // |-----------|

    HPK_W9_15_2_121V_82P5attn_rtStudy_StripsGeometry(const int v=0) : voltage(v){}
    const int voltage;
    std::map<int, std::vector<int>> indexToGeometryMap = {{0,{0,0}}, {1,{0,1}}, {2,{0,2}}, {3,{1,0}}};   
    std::vector<std::vector<int>> geometry = {{0,1,2},{3}};
    std::map<int, bool> acLGADChannelMap = {{0,true}, {1,true}, {2,true}, {3,false}};
    std::map<int, double> amplitudeCorrectionFactor = {{0,1.0}, {1,1.0}, {2,1.0},{3,1.0}};
    std::map<int, double> timeCalibrationCorrection = {{0,-44.005707}, {1,-44.189732}, {2,-44.049251}, {3,0.0}};
    // std::map<int, double> timeCalibrationCorrection = {{0,0.0}, {1,0.0}, {2,0.0}, {3,0.0}};
    double stripWidth = 0.050;
    double pitch = 0.500;
    std::vector<double> stripCenterXPosition = {0.5, 0.0, -0.5, 0.0}; // Iter3
    int numLGADchannels = 3;
    int lowGoodStripIndex = 0;
    int highGoodStripIndex = 2;
    double xBinSize = 0.025;
    double yBinSize = 0.1;
    double xmin = -0.80-xBinSize/2; // Sensor's local frame
    double xmax =  0.80+xBinSize/2; // Sensor's local frame
    double ymin = -2.9-yBinSize/2; // Sensor's local frame
    double ymax = 2.9+yBinSize/2; // Sensor's local frame
    double positionRecoMaxPoint = 0.78;
    double noiseAmpThreshold  = 15.0;
    double signalAmpThreshold = 15.0;
    bool enablePositionReconstruction = true;
    int CFD_threshold = 50;
    std::vector<double> positionRecoPar = {0.250000, -0.580028, 0.215066, -0.836168, -9.005392, 17.517882};
    std::vector<std::vector<double>> sensorEdges = {{-0.7, -2.9}, {0.7, 2.9}}; // Sensor's local frame
    std::vector<std::vector<double>> sensorEdgesTight = {{stripCenterXPosition[highGoodStripIndex], -2.9}, {stripCenterXPosition[lowGoodStripIndex], 2.9}}; // Sensor's local frame
    double offset = stripWidth;
    int centerGoodStripIndex = 1;
    double centerStripX = stripCenterXPosition[centerGoodStripIndex];
    double leftGapX = centerStripX - (pitch/2);
	double rightGapX = centerStripX + (pitch/2);
	std::vector<utility::ROI> regionsOfIntrest = {{"nearStripX", centerStripX + offset - stripWidth/2, centerStripX + offset + stripWidth/2, -2.5,2.5}, {"leftGapX", leftGapX - stripWidth/2, leftGapX + stripWidth/2, -2.5,2.5}, {"rightGapX", rightGapX - stripWidth/2, rightGapX + stripWidth/2, -2.5,2.5}};
};


class HPK_W9_15_2_121V_83attn_rtStudy_StripsGeometry : public DefaultGeometry
{
public:
    // 
    // Used lecroy scope channels 0-7
    // Scope channel 0-6 was AC channels, and scope channel 7 was the photek
    // 
    // |-----------|             -----
    // | 0 0 0 0 0 |             |777|
    // | 1 1 1 1 1 |             |777|
    // | 2 2 2 2 2 |             -----
    // | 3 3 3 3 3 |
    // | 4 4 4 4 4 |
    // | 5 5 5 5 5 |
    // | 6 6 6 6 6 |
    // |-----------|

    HPK_W9_15_2_121V_83attn_rtStudy_StripsGeometry(const int v=0) : voltage(v){}
    const int voltage;
    std::map<int, std::vector<int>> indexToGeometryMap = {{0,{0,0}}, {1,{0,1}}, {2,{0,2}}, {3,{1,0}}};   
    std::vector<std::vector<int>> geometry = {{0,1,2},{3}};
    std::map<int, bool> acLGADChannelMap = {{0,true}, {1,true}, {2,true}, {3,false}};
    std::map<int, double> amplitudeCorrectionFactor = {{0,1.0}, {1,1.0}, {2,1.0},{3,1.0}};
    std::map<int, double> timeCalibrationCorrection = {{0,-44.005707}, {1,-44.189732}, {2,-44.049251}, {3,0.0}};
    // std::map<int, double> timeCalibrationCorrection = {{0,0.0}, {1,0.0}, {2,0.0}, {3,0.0}};
    double stripWidth = 0.050;
    double pitch = 0.500;
    std::vector<double> stripCenterXPosition = {0.5, 0.0, -0.5, 0.0}; // Iter3
    int numLGADchannels = 3;
    int lowGoodStripIndex = 0;
    int highGoodStripIndex = 2;
    double xBinSize = 0.025;
    double yBinSize = 0.1;
    double xmin = -0.80-xBinSize/2; // Sensor's local frame
    double xmax =  0.80+xBinSize/2; // Sensor's local frame
    double ymin = -2.9-yBinSize/2; // Sensor's local frame
    double ymax = 2.9+yBinSize/2; // Sensor's local frame
    double positionRecoMaxPoint = 0.78;
    double noiseAmpThreshold  = 15.0;
    double signalAmpThreshold = 15.0;
    bool enablePositionReconstruction = true;
    int CFD_threshold = 50;
    std::vector<double> positionRecoPar = {0.250000, -0.580028, 0.215066, -0.836168, -9.005392, 17.517882};
    std::vector<std::vector<double>> sensorEdges = {{-0.7, -2.9}, {0.7, 2.9}}; // Sensor's local frame
    std::vector<std::vector<double>> sensorEdgesTight = {{stripCenterXPosition[highGoodStripIndex], -2.9}, {stripCenterXPosition[lowGoodStripIndex], 2.9}}; // Sensor's local frame
    double offset = stripWidth;
    int centerGoodStripIndex = 1;
    double centerStripX = stripCenterXPosition[centerGoodStripIndex];
    double leftGapX = centerStripX - (pitch/2);
	double rightGapX = centerStripX + (pitch/2);
	std::vector<utility::ROI> regionsOfIntrest = {{"nearStripX", centerStripX + offset - stripWidth/2, centerStripX + offset + stripWidth/2, -2.5,2.5}, {"leftGapX", leftGapX - stripWidth/2, leftGapX + stripWidth/2, -2.5,2.5}, {"rightGapX", rightGapX - stripWidth/2, rightGapX + stripWidth/2, -2.5,2.5}};
};


class HPK_W9_15_2_121V_83P5attn_rtStudy_StripsGeometry : public DefaultGeometry
{
public:
    // 
    // Used lecroy scope channels 0-7
    // Scope channel 0-6 was AC channels, and scope channel 7 was the photek
    // 
    // |-----------|             -----
    // | 0 0 0 0 0 |             |777|
    // | 1 1 1 1 1 |             |777|
    // | 2 2 2 2 2 |             -----
    // | 3 3 3 3 3 |
    // | 4 4 4 4 4 |
    // | 5 5 5 5 5 |
    // | 6 6 6 6 6 |
    // |-----------|

    HPK_W9_15_2_121V_83P5attn_rtStudy_StripsGeometry(const int v=0) : voltage(v){}
    const int voltage;
    std::map<int, std::vector<int>> indexToGeometryMap = {{0,{0,0}}, {1,{0,1}}, {2,{0,2}}, {3,{1,0}}};   
    std::vector<std::vector<int>> geometry = {{0,1,2},{3}};
    std::map<int, bool> acLGADChannelMap = {{0,true}, {1,true}, {2,true}, {3,false}};
    std::map<int, double> amplitudeCorrectionFactor = {{0,1.0}, {1,1.0}, {2,1.0},{3,1.0}};
    std::map<int, double> timeCalibrationCorrection = {{0,-44.005707}, {1,-44.189732}, {2,-44.049251}, {3,0.0}};
    // std::map<int, double> timeCalibrationCorrection = {{0,0.0}, {1,0.0}, {2,0.0}, {3,0.0}};
    double stripWidth = 0.050;
    double pitch = 0.500;
    std::vector<double> stripCenterXPosition = {0.5, 0.0, -0.5, 0.0}; // Iter3
    int numLGADchannels = 3;
    int lowGoodStripIndex = 0;
    int highGoodStripIndex = 2;
    double xBinSize = 0.025;
    double yBinSize = 0.1;
    double xmin = -0.80-xBinSize/2; // Sensor's local frame
    double xmax =  0.80+xBinSize/2; // Sensor's local frame
    double ymin = -2.9-yBinSize/2; // Sensor's local frame
    double ymax = 2.9+yBinSize/2; // Sensor's local frame
    double positionRecoMaxPoint = 0.78;
    double noiseAmpThreshold  = 15.0;
    double signalAmpThreshold = 15.0;
    bool enablePositionReconstruction = true;
    int CFD_threshold = 50;
    std::vector<double> positionRecoPar = {0.250000, -0.580028, 0.215066, -0.836168, -9.005392, 17.517882};
    std::vector<std::vector<double>> sensorEdges = {{-0.7, -2.9}, {0.7, 2.9}}; // Sensor's local frame
    std::vector<std::vector<double>> sensorEdgesTight = {{stripCenterXPosition[highGoodStripIndex], -2.9}, {stripCenterXPosition[lowGoodStripIndex], 2.9}}; // Sensor's local frame
    double offset = stripWidth;
    int centerGoodStripIndex = 1;
    double centerStripX = stripCenterXPosition[centerGoodStripIndex];
    double leftGapX = centerStripX - (pitch/2);
	double rightGapX = centerStripX + (pitch/2);
	std::vector<utility::ROI> regionsOfIntrest = {{"nearStripX", centerStripX + offset - stripWidth/2, centerStripX + offset + stripWidth/2, -2.5,2.5}, {"leftGapX", leftGapX - stripWidth/2, leftGapX + stripWidth/2, -2.5,2.5}, {"rightGapX", rightGapX - stripWidth/2, rightGapX + stripWidth/2, -2.5,2.5}};
};


class HPK_W9_15_2_121V_84attn_rtStudy_StripsGeometry : public DefaultGeometry
{
public:
    // 
    // Used lecroy scope channels 0-7
    // Scope channel 0-6 was AC channels, and scope channel 7 was the photek
    // 
    // |-----------|             -----
    // | 0 0 0 0 0 |             |777|
    // | 1 1 1 1 1 |             |777|
    // | 2 2 2 2 2 |             -----
    // | 3 3 3 3 3 |
    // | 4 4 4 4 4 |
    // | 5 5 5 5 5 |
    // | 6 6 6 6 6 |
    // |-----------|

    HPK_W9_15_2_121V_84attn_rtStudy_StripsGeometry(const int v=0) : voltage(v){}
    const int voltage;
    std::map<int, std::vector<int>> indexToGeometryMap = {{0,{0,0}}, {1,{0,1}}, {2,{0,2}}, {3,{1,0}}};   
    std::vector<std::vector<int>> geometry = {{0,1,2},{3}};
    std::map<int, bool> acLGADChannelMap = {{0,true}, {1,true}, {2,true}, {3,false}};
    std::map<int, double> amplitudeCorrectionFactor = {{0,1.0}, {1,1.0}, {2,1.0},{3,1.0}};
    std::map<int, double> timeCalibrationCorrection = {{0,-44.005707}, {1,-44.189732}, {2,-44.049251}, {3,0.0}};
    // std::map<int, double> timeCalibrationCorrection = {{0,0.0}, {1,0.0}, {2,0.0}, {3,0.0}};
    double stripWidth = 0.050;
    double pitch = 0.500;
    std::vector<double> stripCenterXPosition = {0.5, 0.0, -0.5, 0.0}; // Iter3
    int numLGADchannels = 3;
    int lowGoodStripIndex = 0;
    int highGoodStripIndex = 2;
    double xBinSize = 0.025;
    double yBinSize = 0.1;
    double xmin = -0.80-xBinSize/2; // Sensor's local frame
    double xmax =  0.80+xBinSize/2; // Sensor's local frame
    double ymin = -2.9-yBinSize/2; // Sensor's local frame
    double ymax = 2.9+yBinSize/2; // Sensor's local frame
    double positionRecoMaxPoint = 0.78;
    double noiseAmpThreshold  = 15.0;
    double signalAmpThreshold = 15.0;
    bool enablePositionReconstruction = true;
    int CFD_threshold = 50;
    std::vector<double> positionRecoPar = {0.250000, -0.580028, 0.215066, -0.836168, -9.005392, 17.517882};
    std::vector<std::vector<double>> sensorEdges = {{-0.7, -2.9}, {0.7, 2.9}}; // Sensor's local frame
    std::vector<std::vector<double>> sensorEdgesTight = {{stripCenterXPosition[highGoodStripIndex], -2.9}, {stripCenterXPosition[lowGoodStripIndex], 2.9}}; // Sensor's local frame
    double offset = stripWidth;
    int centerGoodStripIndex = 1;
    double centerStripX = stripCenterXPosition[centerGoodStripIndex];
    double leftGapX = centerStripX - (pitch/2);
	double rightGapX = centerStripX + (pitch/2);
	std::vector<utility::ROI> regionsOfIntrest = {{"nearStripX", centerStripX + offset - stripWidth/2, centerStripX + offset + stripWidth/2, -2.5,2.5}, {"leftGapX", leftGapX - stripWidth/2, leftGapX + stripWidth/2, -2.5,2.5}, {"rightGapX", rightGapX - stripWidth/2, rightGapX + stripWidth/2, -2.5,2.5}};
};



class HPK_W9_15_2_121V_84P5attn_rtStudy_StripsGeometry : public DefaultGeometry
{
public:
    // 
    // Used lecroy scope channels 0-7
    // Scope channel 0-6 was AC channels, and scope channel 7 was the photek
    // 
    // |-----------|             -----
    // | 0 0 0 0 0 |             |777|
    // | 1 1 1 1 1 |             |777|
    // | 2 2 2 2 2 |             -----
    // | 3 3 3 3 3 |
    // | 4 4 4 4 4 |
    // | 5 5 5 5 5 |
    // | 6 6 6 6 6 |
    // |-----------|

    HPK_W9_15_2_121V_84P5attn_rtStudy_StripsGeometry(const int v=0) : voltage(v){}
    const int voltage;
    std::map<int, std::vector<int>> indexToGeometryMap = {{0,{0,0}}, {1,{0,1}}, {2,{0,2}}, {3,{1,0}}};   
    std::vector<std::vector<int>> geometry = {{0,1,2},{3}};
    std::map<int, bool> acLGADChannelMap = {{0,true}, {1,true}, {2,true}, {3,false}};
    std::map<int, double> amplitudeCorrectionFactor = {{0,1.0}, {1,1.0}, {2,1.0},{3,1.0}};
    std::map<int, double> timeCalibrationCorrection = {{0,-44.005707}, {1,-44.189732}, {2,-44.049251}, {3,0.0}};
    // std::map<int, double> timeCalibrationCorrection = {{0,0.0}, {1,0.0}, {2,0.0}, {3,0.0}};
    double stripWidth = 0.050;
    double pitch = 0.500;
    std::vector<double> stripCenterXPosition = {0.5, 0.0, -0.5, 0.0}; // Iter3
    int numLGADchannels = 3;
    int lowGoodStripIndex = 0;
    int highGoodStripIndex = 2;
    double xBinSize = 0.025;
    double yBinSize = 0.1;
    double xmin = -0.80-xBinSize/2; // Sensor's local frame
    double xmax =  0.80+xBinSize/2; // Sensor's local frame
    double ymin = -2.9-yBinSize/2; // Sensor's local frame
    double ymax = 2.9+yBinSize/2; // Sensor's local frame
    double positionRecoMaxPoint = 0.78;
    double noiseAmpThreshold  = 15.0;
    double signalAmpThreshold = 15.0;
    bool enablePositionReconstruction = true;
    int CFD_threshold = 50;
    std::vector<double> positionRecoPar = {0.250000, -0.580028, 0.215066, -0.836168, -9.005392, 17.517882};
    std::vector<std::vector<double>> sensorEdges = {{-0.7, -2.9}, {0.7, 2.9}}; // Sensor's local frame
    std::vector<std::vector<double>> sensorEdgesTight = {{stripCenterXPosition[highGoodStripIndex], -2.9}, {stripCenterXPosition[lowGoodStripIndex], 2.9}}; // Sensor's local frame
    double offset = stripWidth;
    int centerGoodStripIndex = 1;
    double centerStripX = stripCenterXPosition[centerGoodStripIndex];
    double leftGapX = centerStripX - (pitch/2);
	double rightGapX = centerStripX + (pitch/2);
	std::vector<utility::ROI> regionsOfIntrest = {{"nearStripX", centerStripX + offset - stripWidth/2, centerStripX + offset + stripWidth/2, -2.5,2.5}, {"leftGapX", leftGapX - stripWidth/2, leftGapX + stripWidth/2, -2.5,2.5}, {"rightGapX", rightGapX - stripWidth/2, rightGapX + stripWidth/2, -2.5,2.5}};
};


class HPK_W9_15_2_121V_85attn_rtStudy_StripsGeometry : public DefaultGeometry
{
public:
    // 
    // Used lecroy scope channels 0-7
    // Scope channel 0-6 was AC channels, and scope channel 7 was the photek
    // 
    // |-----------|             -----
    // | 0 0 0 0 0 |             |777|
    // | 1 1 1 1 1 |             |777|
    // | 2 2 2 2 2 |             -----
    // | 3 3 3 3 3 |
    // | 4 4 4 4 4 |
    // | 5 5 5 5 5 |
    // | 6 6 6 6 6 |
    // |-----------|

    HPK_W9_15_2_121V_85attn_rtStudy_StripsGeometry(const int v=0) : voltage(v){}
    const int voltage;
    std::map<int, std::vector<int>> indexToGeometryMap = {{0,{0,0}}, {1,{0,1}}, {2,{0,2}}, {3,{1,0}}};   
    std::vector<std::vector<int>> geometry = {{0,1,2},{3}};
    std::map<int, bool> acLGADChannelMap = {{0,true}, {1,true}, {2,true}, {3,false}};
    std::map<int, double> amplitudeCorrectionFactor = {{0,1.0}, {1,1.0}, {2,1.0},{3,1.0}};
    std::map<int, double> timeCalibrationCorrection = {{0,-44.005707}, {1,-44.189732}, {2,-44.049251}, {3,0.0}};
    // std::map<int, double> timeCalibrationCorrection = {{0,0.0}, {1,0.0}, {2,0.0}, {3,0.0}};
    double stripWidth = 0.050;
    double pitch = 0.500;
    std::vector<double> stripCenterXPosition = {0.5, 0.0, -0.5, 0.0}; // Iter3
    int numLGADchannels = 3;
    int lowGoodStripIndex = 0;
    int highGoodStripIndex = 2;
    double xBinSize = 0.025;
    double yBinSize = 0.1;
    double xmin = -0.80-xBinSize/2; // Sensor's local frame
    double xmax =  0.80+xBinSize/2; // Sensor's local frame
    double ymin = -2.9-yBinSize/2; // Sensor's local frame
    double ymax = 2.9+yBinSize/2; // Sensor's local frame
    double positionRecoMaxPoint = 0.78;
    double noiseAmpThreshold  = 15.0;
    double signalAmpThreshold = 15.0;
    bool enablePositionReconstruction = true;
    int CFD_threshold = 50;
    std::vector<double> positionRecoPar = {0.250000, -0.580028, 0.215066, -0.836168, -9.005392, 17.517882};
    std::vector<std::vector<double>> sensorEdges = {{-0.7, -2.9}, {0.7, 2.9}}; // Sensor's local frame
    std::vector<std::vector<double>> sensorEdgesTight = {{stripCenterXPosition[highGoodStripIndex], -2.9}, {stripCenterXPosition[lowGoodStripIndex], 2.9}}; // Sensor's local frame
    double offset = stripWidth;
    int centerGoodStripIndex = 1;
    double centerStripX = stripCenterXPosition[centerGoodStripIndex];
    double leftGapX = centerStripX - (pitch/2);
	double rightGapX = centerStripX + (pitch/2);
	std::vector<utility::ROI> regionsOfIntrest = {{"nearStripX", centerStripX + offset - stripWidth/2, centerStripX + offset + stripWidth/2, -2.5,2.5}, {"leftGapX", leftGapX - stripWidth/2, leftGapX + stripWidth/2, -2.5,2.5}, {"rightGapX", rightGapX - stripWidth/2, rightGapX + stripWidth/2, -2.5,2.5}};
};


// class HPK_W9_15_2_121V_85P4attn_rtStudy_StripsGeometry : public DefaultGeometry
// {
// public:
//     // 
//     // Used lecroy scope channels 0-7
//     // Scope channel 0-6 was AC channels, and scope channel 7 was the photek
//     // 
//     // |-----------|             -----
//     // | 0 0 0 0 0 |             |777|
//     // | 1 1 1 1 1 |             |777|
//     // | 2 2 2 2 2 |             -----
//     // | 3 3 3 3 3 |
//     // | 4 4 4 4 4 |
//     // | 5 5 5 5 5 |
//     // | 6 6 6 6 6 |
//     // |-----------|

//     HPK_W9_15_2_121V_85P4attn_rtStudy_StripsGeometry(const int v=0) : voltage(v){}
//     const int voltage;
//     std::map<int, std::vector<int>> indexToGeometryMap = {{0,{0,0}}, {1,{0,1}}, {2,{0,2}}, {3,{1,0}}};   
//     std::vector<std::vector<int>> geometry = {{0,1,2},{3}};
//     std::map<int, bool> acLGADChannelMap = {{0,true}, {1,true}, {2,true}, {3,false}};
//     std::map<int, double> amplitudeCorrectionFactor = {{0,1.0}, {1,1.0}, {2,1.0},{3,1.0}};
//     std::map<int, double> timeCalibrationCorrection = {{0,-44.005707}, {1,-44.189732}, {2,-44.049251}, {3,0.0}};
//     // std::map<int, double> timeCalibrationCorrection = {{0,0.0}, {1,0.0}, {2,0.0}, {3,0.0}};
//     double stripWidth = 0.050;
//     double pitch = 0.500;
//     std::vector<double> stripCenterXPosition = {0.5, 0.0, -0.5, 0.0}; // Iter3
//     int numLGADchannels = 3;
//     int lowGoodStripIndex = 0;
//     int highGoodStripIndex = 2;
//     double xBinSize = 0.025;
//     double yBinSize = 0.1;
//     double xmin = -0.80-xBinSize/2; // Sensor's local frame
//     double xmax =  0.80+xBinSize/2; // Sensor's local frame
//     double ymin = -2.9-yBinSize/2; // Sensor's local frame
//     double ymax = 2.9+yBinSize/2; // Sensor's local frame
//     double positionRecoMaxPoint = 0.78;
//     double noiseAmpThreshold  = 15.0;
//     double signalAmpThreshold = 15.0;
//     bool enablePositionReconstruction = true;
//     int CFD_threshold = 50;
//     std::vector<double> positionRecoPar = {0.250000, -0.580028, 0.215066, -0.836168, -9.005392, 17.517882};
//     std::vector<std::vector<double>> sensorEdges = {{-0.7, -2.9}, {0.7, 2.9}}; // Sensor's local frame
//     std::vector<std::vector<double>> sensorEdgesTight = {{stripCenterXPosition[highGoodStripIndex], -2.9}, {stripCenterXPosition[lowGoodStripIndex], 2.9}}; // Sensor's local frame
//     double offset = stripWidth;
//     int centerGoodStripIndex = 1;
//     double centerStripX = stripCenterXPosition[centerGoodStripIndex];
//     double leftGapX = centerStripX - (pitch/2);
// 	double rightGapX = centerStripX + (pitch/2);
// 	std::vector<utility::ROI> regionsOfIntrest = {{"nearStripX", centerStripX + offset - stripWidth/2, centerStripX + offset + stripWidth/2, -2.5,2.5}, {"leftGapX", leftGapX - stripWidth/2, leftGapX + stripWidth/2, -2.5,2.5}, {"rightGapX", rightGapX - stripWidth/2, rightGapX + stripWidth/2, -2.5,2.5}};
// };


class HPK_W9_15_2_121V_86attn_rtStudy_StripsGeometry : public DefaultGeometry
{
public:
    // 
    // Used lecroy scope channels 0-7
    // Scope channel 0-6 was AC channels, and scope channel 7 was the photek
    // 
    // |-----------|             -----
    // | 0 0 0 0 0 |             |777|
    // | 1 1 1 1 1 |             |777|
    // | 2 2 2 2 2 |             -----
    // | 3 3 3 3 3 |
    // | 4 4 4 4 4 |
    // | 5 5 5 5 5 |
    // | 6 6 6 6 6 |
    // |-----------|

    HPK_W9_15_2_121V_86attn_rtStudy_StripsGeometry(const int v=0) : voltage(v){}
    const int voltage;
    std::map<int, std::vector<int>> indexToGeometryMap = {{0,{0,0}}, {1,{0,1}}, {2,{0,2}}, {3,{1,0}}};   
    std::vector<std::vector<int>> geometry = {{0,1,2},{3}};
    std::map<int, bool> acLGADChannelMap = {{0,true}, {1,true}, {2,true}, {3,false}};
    std::map<int, double> amplitudeCorrectionFactor = {{0,1.0}, {1,1.0}, {2,1.0},{3,1.0}};
    std::map<int, double> timeCalibrationCorrection = {{0,-44.005707}, {1,-44.189732}, {2,-44.049251}, {3,0.0}};
    // std::map<int, double> timeCalibrationCorrection = {{0,0.0}, {1,0.0}, {2,0.0}, {3,0.0}};
    double stripWidth = 0.050;
    double pitch = 0.500;
    std::vector<double> stripCenterXPosition = {0.5, 0.0, -0.5, 0.0}; // Iter3
    int numLGADchannels = 3;
    int lowGoodStripIndex = 0;
    int highGoodStripIndex = 2;
    double xBinSize = 0.025;
    double yBinSize = 0.1;
    double xmin = -0.80-xBinSize/2; // Sensor's local frame
    double xmax =  0.80+xBinSize/2; // Sensor's local frame
    double ymin = -2.9-yBinSize/2; // Sensor's local frame
    double ymax = 2.9+yBinSize/2; // Sensor's local frame
    double positionRecoMaxPoint = 0.78;
    double noiseAmpThreshold  = 15.0;
    double signalAmpThreshold = 15.0;
    bool enablePositionReconstruction = true;
    int CFD_threshold = 50;
    std::vector<double> positionRecoPar = {0.250000, -0.580028, 0.215066, -0.836168, -9.005392, 17.517882};
    std::vector<std::vector<double>> sensorEdges = {{-0.7, -2.9}, {0.7, 2.9}}; // Sensor's local frame
    std::vector<std::vector<double>> sensorEdgesTight = {{stripCenterXPosition[highGoodStripIndex], -2.9}, {stripCenterXPosition[lowGoodStripIndex], 2.9}}; // Sensor's local frame
    double offset = stripWidth;
    int centerGoodStripIndex = 1;
    double centerStripX = stripCenterXPosition[centerGoodStripIndex];
    double leftGapX = centerStripX - (pitch/2);
	double rightGapX = centerStripX + (pitch/2);
	std::vector<utility::ROI> regionsOfIntrest = {{"nearStripX", centerStripX + offset - stripWidth/2, centerStripX + offset + stripWidth/2, -2.5,2.5}, {"leftGapX", leftGapX - stripWidth/2, leftGapX + stripWidth/2, -2.5,2.5}, {"rightGapX", rightGapX - stripWidth/2, rightGapX + stripWidth/2, -2.5,2.5}};
};


class HPK_W9_15_2_121V_86P5attn_rtStudy_StripsGeometry : public DefaultGeometry
{
public:
    // 
    // Used lecroy scope channels 0-7
    // Scope channel 0-6 was AC channels, and scope channel 7 was the photek
    // 
    // |-----------|             -----
    // | 0 0 0 0 0 |             |777|
    // | 1 1 1 1 1 |             |777|
    // | 2 2 2 2 2 |             -----
    // | 3 3 3 3 3 |
    // | 4 4 4 4 4 |
    // | 5 5 5 5 5 |
    // | 6 6 6 6 6 |
    // |-----------|

    HPK_W9_15_2_121V_86P5attn_rtStudy_StripsGeometry(const int v=0) : voltage(v){}
    const int voltage;
    std::map<int, std::vector<int>> indexToGeometryMap = {{0,{0,0}}, {1,{0,1}}, {2,{0,2}}, {3,{1,0}}};   
    std::vector<std::vector<int>> geometry = {{0,1,2},{3}};
    std::map<int, bool> acLGADChannelMap = {{0,true}, {1,true}, {2,true}, {3,false}};
    std::map<int, double> amplitudeCorrectionFactor = {{0,1.0}, {1,1.0}, {2,1.0},{3,1.0}};
    std::map<int, double> timeCalibrationCorrection = {{0,-44.005707}, {1,-44.189732}, {2,-44.049251}, {3,0.0}};
    // std::map<int, double> timeCalibrationCorrection = {{0,0.0}, {1,0.0}, {2,0.0}, {3,0.0}};
    double stripWidth = 0.050;
    double pitch = 0.500;
    std::vector<double> stripCenterXPosition = {0.5, 0.0, -0.5, 0.0}; // Iter3
    int numLGADchannels = 3;
    int lowGoodStripIndex = 0;
    int highGoodStripIndex = 2;
    double xBinSize = 0.025;
    double yBinSize = 0.1;
    double xmin = -0.80-xBinSize/2; // Sensor's local frame
    double xmax =  0.80+xBinSize/2; // Sensor's local frame
    double ymin = -2.9-yBinSize/2; // Sensor's local frame
    double ymax = 2.9+yBinSize/2; // Sensor's local frame
    double positionRecoMaxPoint = 0.78;
    double noiseAmpThreshold  = 15.0;
    double signalAmpThreshold = 15.0;
    bool enablePositionReconstruction = true;
    int CFD_threshold = 50;
    std::vector<double> positionRecoPar = {0.250000, -0.580028, 0.215066, -0.836168, -9.005392, 17.517882};
    std::vector<std::vector<double>> sensorEdges = {{-0.7, -2.9}, {0.7, 2.9}}; // Sensor's local frame
    std::vector<std::vector<double>> sensorEdgesTight = {{stripCenterXPosition[highGoodStripIndex], -2.9}, {stripCenterXPosition[lowGoodStripIndex], 2.9}}; // Sensor's local frame
    double offset = stripWidth;
    int centerGoodStripIndex = 1;
    double centerStripX = stripCenterXPosition[centerGoodStripIndex];
    double leftGapX = centerStripX - (pitch/2);
	double rightGapX = centerStripX + (pitch/2);
	std::vector<utility::ROI> regionsOfIntrest = {{"nearStripX", centerStripX + offset - stripWidth/2, centerStripX + offset + stripWidth/2, -2.5,2.5}, {"leftGapX", leftGapX - stripWidth/2, leftGapX + stripWidth/2, -2.5,2.5}, {"rightGapX", rightGapX - stripWidth/2, rightGapX + stripWidth/2, -2.5,2.5}};
};
#endif
