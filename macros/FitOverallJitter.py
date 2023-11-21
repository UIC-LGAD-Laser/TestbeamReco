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

canvas = TCanvas("cv","cv",800,800)
gPad.SetLeftMargin(0.12)
gPad.SetRightMargin(0.15)
gPad.SetTopMargin(0.08)
gPad.SetBottomMargin(0.12)
gPad.SetTicks(1,1)

# Construct the argument parser
parser = optparse.OptionParser("usage: %prog [options]\n")
parser.add_option('-D', dest='Dataset', default = "", help="Dataset, which determines filepath")
options, args = parser.parse_args()

fit = langaus.LanGausFit()

dataset = options.Dataset
outdir=""
if organized_mode: 
    outdir = myStyle.getOutputDir(dataset)
    inputfile = TFile("%s%s_Analyze.root"%(outdir,dataset))
else: 
    inputfile = TFile("../test/myoutputfile.root")   

outdir_tmp = myStyle.GetPlotsDir(outdir, "Jitter/")

colors = myStyle.GetColors(True)

sensor_Geometry = myStyle.GetGeometry(dataset)

sensor = sensor_Geometry['sensor']
pitch  = sensor_Geometry['pitch']

hist = inputfile.Get("weighted_jitter_hist")

hist.Rebin(2)
myMean = hist.GetMean()
myRMS = hist.GetRMS()
value = myMean

myLanGausFunction = fit.fit(hist, fitrange=(myMean-1.5*myRMS,myMean+3*myRMS))
myMPV = myLanGausFunction.GetParameter(1)
value = myMPV
# gaussian = TF1("gaussian", "gaus")
# gaussian.SetRange(myMean-1.5*myRMS,myMean+1.5*myRMS)
# hist.Fit(gaussian, "R")
# myMean = gaussian.GetParameter(1)
# mySigma = gaussian.GetParameter(2)
# value = myMean

hist.Draw("hist")
myLanGausFunction.Draw("same")
# gaussian.Draw("same")
hist.SetTitle("Overall weighted jitter")
hist.GetXaxis().SetTitle("Counts")
hist.GetXaxis().SetTitle("Jitter [ps]")
canvas.SetRightMargin(0.18)
canvas.SetLeftMargin(0.12)
canvas.SaveAs(outdir+"Jitter/Overall_jitter.gif")