from ROOT import TFile,TTree,TCanvas,TH1F,TH2F,TLatex,TMath,TEfficiency,TGraphAsymmErrors,TLegend,gROOT,gPad,gStyle, kWhite, TF1, TPaveStats
import os
import EfficiencyUtils
import langaus
import optparse
import time
#from stripBox import getStripBox
import myStyle
from matplotlib import pyplot as plt
gROOT.SetBatch( True )
gStyle.SetOptFit(1011)

## Defining Style
myStyle.ForceStyle()
# gStyle.SetTitleYOffset(1.1)
organized_mode=True
plt.rcParams.update({'font.size': 20})

# Construct the argument parser
parser = optparse.OptionParser("usage: %prog [options]\n")
parser.add_option('-D', dest='Dataset', default = "", help="Dataset, which determines filepath")
options, args = parser.parse_args()

dataset = options.Dataset
outdir=""
if organized_mode: 
    outdir = myStyle.getOutputDir(dataset)
    inputfile = TFile("%s%s_Analyze.root"%(outdir,dataset))
else:
    print("Analyze file not found.\n")
outdirTmp = myStyle.GetPlotsDir(outdir, "NoiseFits/")
canvas = TCanvas("cv","cv",800,800)
gPad.SetLeftMargin(0.12)
gPad.SetRightMargin(0.15)
gPad.SetTopMargin(0.08)
gPad.SetBottomMargin(0.12)
gPad.SetTicks(1,1)

colors = myStyle.GetColors(True)
sensor_Geometry = myStyle.GetGeometry(dataset)
sensor = sensor_Geometry['sensor']
pitch  = sensor_Geometry['pitch']
Noise = []
for i in range(3):
    channel = i
    strip_number = channel + 1
    hist = inputfile.Get("baselineRMS0"+str(channel))
    hist.Draw("hist")
    gaussian = TF1("gaussian", "gaus")
    myMean = hist.GetMean()
    myRMS = hist.GetRMS()
    gaussian.SetRange(myMean-1.5*myRMS,myMean+1.5*myRMS)
    hist.Fit(gaussian, "R")
    myMean = gaussian.GetParameter(1)
    mySigma = gaussian.GetParameter(2)
    Noise.append(myMean)
    gaussian.Draw("same")
    hist.GetXaxis().SetTitle("Counts")
    hist.GetXaxis().SetTitle("Noise [mV]")
    canvas.SetRightMargin(0.18)
    canvas.SetLeftMargin(0.12)
    canvas.SaveAs(outdirTmp+"Noise_channel"+str(channel)+".png")


print(Noise[0],",",Noise[1],",",Noise[2])