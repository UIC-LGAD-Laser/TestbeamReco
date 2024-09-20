from ROOT import TFile,TTree,TCanvas,TH1F,TH2F,TLatex,TMath,TEfficiency,TGraphAsymmErrors,TLegend,gROOT,gStyle, kWhite
import os
import EfficiencyUtils
import langaus
import optparse
import time
from stripBox import getStripBox
import myStyle

gROOT.SetBatch( True )
gStyle.SetOptFit(1011)

## Defining Style
myStyle.ForceStyle()
# gStyle.SetTitleYOffset(1.1)
organized_mode=True

# Construct the argument parser
parser = optparse.OptionParser("usage: %prog [options]\n")
parser.add_option('-x','--xlength', dest='xlength', default = 0.8, help="Limit x-axis in final plot")
parser.add_option('-y','--ylength', dest='ylength', default = 70, help="Max Risetime value in final plot")
parser.add_option('-n','--norm', dest='norm', default = False, help="Plot normalized amp")

options, args = parser.parse_args()
xlength = float(options.xlength)
ylength = float(options.ylength)
norm_bool = options.norm
colors = myStyle.GetColors(True)
# colors = [416+2, 432+2, 600, 880, 632, 400+2, 600-5, 1, 41, 45, 46, 47, 48, 3, 5, 7, 9, 28]
canvas = TCanvas("cv","cv",1200,800)
legend = TLegend(2*myStyle.GetMargin()+0.02,1-myStyle.GetMargin()-0.27,1-myStyle.GetMargin()-0.02,1-myStyle.GetMargin()-0.05)
legend.SetNColumns(3)

#Make final plots
# Varying attenuation

sensors = ["HPK_W9_15_2_121V_85P4attn", "HPK_W9_15_5_117V_85P4attn"]

tag = ["L=10mm, W=50um", "L=25mm, W=50um"]

ylength = 70
saveName_list = "HPK_Amplitude_vs_x_stripLength"
ymin = 1
suffix = "PlotAmplitudeVsX.root"

if(norm_bool):
    ylength = 1.5
    saveName_list = "HPK_AmplitudeNorm_vs_x_stripLength"
    ymin = 0
    suffix = "PlotAmplitudeNormalizedVsX.root"

hname = "amplitude_vs_x_channel01"


totalRisetime_vs_x = TH1F("htemp","",1,-xlength,xlength)
totalRisetime_vs_x.Draw("AXIS")
totalRisetime_vs_x.SetStats(0)
totalRisetime_vs_x.SetTitle("")
totalRisetime_vs_x.GetXaxis().SetTitle("Track x position [mm]")
totalRisetime_vs_x.GetYaxis().SetTitle("MPV Amplitude [mV]")
totalRisetime_vs_x.GetYaxis().SetTitleOffset(1)
totalRisetime_vs_x.SetLineWidth(3)
totalRisetime_vs_x.GetYaxis().SetRangeUser(ymin, ylength)

# inputfile = TFile("../output/%s/%s_Analyze.root"%(sensors[0],sensors[0]),"READ")
# shift = inputfile.Get("stripBoxInfo03").GetMean(1)
# boxes = getStripBox(inputfile,ymin,ylength-60.0,False, 18, True, shift)
# for box in boxes[1:len(boxes)-1]:
#    box.Draw()

plotfile = []
plotList_Risetime_vs_x = []
for i in range(len(sensors)):
   plotfile.append(TFile("../output/"+sensors[i]+"/"+suffix,"READ"))
   plotList_Risetime_vs_x.append(plotfile[i].Get(hname))
   plotList_Risetime_vs_x[i].SetLineWidth(3)
   plotList_Risetime_vs_x[i].SetLineColor(colors[i+1])
   plotList_Risetime_vs_x[i].Draw("hist same")
   legend.AddEntry(plotList_Risetime_vs_x[i], tag[i])

legend.Draw()
myStyle.LaserInfo()
# myStyle.SensorProductionInfo(sensor_prod)
totalRisetime_vs_x.Draw("AXIS same")
myStyle.SensorInfo("HPK May production")

canvas.SaveAs("../"+saveName_list+".png")