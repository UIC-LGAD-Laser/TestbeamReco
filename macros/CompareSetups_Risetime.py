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
parser.add_option('-x','--xlength', dest='xlength', default = 1.25, help="Limit x-axis in final plot")
parser.add_option('-y','--ylength', dest='ylength', default = 1200, help="Max Risetime value in final plot")
options, args = parser.parse_args()
xlength = float(options.xlength)
ylength = float(options.ylength)
# colors = myStyle.GetColors(True)
colors = [416+2, 432+2, 600, 880, 632, 400+2, 600-5, 1, 41, 45, 46, 47, 48, 3, 5, 7, 9, 28]
canvas = TCanvas("cv","cv",1200,800)
legend = TLegend(2*myStyle.GetMargin()+0.02,1-myStyle.GetMargin()-0.27,1-myStyle.GetMargin()-0.02,1-myStyle.GetMargin()-0.05)
legend.SetNColumns(3)

#Make final plots
# Varying attenuation
sensors = ["HPK_W9_15_2_121V_74attn_rtStudy", "HPK_W9_15_2_121V_75attn_rtStudy", "HPK_W9_15_2_121V_76attn_rtStudy", "HPK_W9_15_2_121V_77attn_rtStudy", "HPK_W9_15_2_121V_78attn_rtStudy", "HPK_W9_15_2_121V_79attn_rtStudy", "HPK_W9_15_2_121V_80attn_rtStudy", "HPK_W9_15_2_121V_81attn_rtStudy", "HPK_W9_15_2_121V_82attn_rtStudy", "HPK_W9_15_2_121V_82P5attn_rtStudy", "HPK_W9_15_2_121V_83attn_rtStudy", "HPK_W9_15_2_121V_83P5attn_rtStudy", "HPK_W9_15_2_121V_84attn_rtStudy", "HPK_W9_15_2_121V_84P5attn_rtStudy", "HPK_W9_15_2_121V_85attn_rtStudy", "HPK_W9_15_2_121V_85P4attn_rtStudy", "HPK_W9_15_2_121V_86attn_rtStudy", "HPK_W9_15_2_121V_86P5attn_rtStudy"]
tag = ["74%", "75%", "76%", "77%", "78%", "79%", "80%", "81%", "82%", "82.5%", "83%", "83.5%", "84%", "84.5%", "85%", "85.4%", "86%", "86.5%"]

hname = "risetime_vs_x"
ymin = 1

# sensor_prod = "W9 (20T, E600, 50M)"

totalRisetime_vs_x = TH1F("htemp","",1,-xlength,xlength)
totalRisetime_vs_x.Draw("AXIS")
totalRisetime_vs_x.SetStats(0)
totalRisetime_vs_x.SetTitle("")
totalRisetime_vs_x.GetXaxis().SetTitle("Track x position [mm]")
totalRisetime_vs_x.GetYaxis().SetTitle("Risetime [ps]")
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
   plotfile.append(TFile("../output/"+sensors[i]+"/RisetimeStudy/PlotRisetimeOverallVsX.root","READ"))
   plotList_Risetime_vs_x.append(plotfile[i].Get(hname))
   plotList_Risetime_vs_x[i].SetLineWidth(3)
   plotList_Risetime_vs_x[i].SetLineColor(colors[i])
   plotList_Risetime_vs_x[i].Draw("hist same")
   legend.AddEntry(plotList_Risetime_vs_x[i], tag[i])

legend.Draw()
myStyle.LaserInfo()
# myStyle.SensorProductionInfo(sensor_prod)
totalRisetime_vs_x.Draw("AXIS same")
# myStyle.SensorInfoSmart(dataset)

canvas.SaveAs("../HPK_Risetime_vs_x_attenuation.png")
