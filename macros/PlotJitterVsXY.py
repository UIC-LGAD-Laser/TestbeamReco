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

dataset = options.Dataset
outdir=""
if organized_mode: 
    outdir = myStyle.getOutputDir(dataset)
    inputfile = TFile("%s%s_Analyze.root"%(outdir,dataset))
else: 
    inputfile = TFile("../test/myoutputfile.root")   

outdir_tmp = myStyle.GetPlotsDir(outdir, "Jitter/")

fit = langaus.LanGausFit()

colors = myStyle.GetColors(True)

sensor_Geometry = myStyle.GetGeometry(dataset)

sensor = sensor_Geometry['sensor']
pitch  = sensor_Geometry['pitch']

hist = inputfile.Get("weighted_jitter_vs_xy")

hist2D = hist.Project3D("yx")
jitter_vs_xy = hist2D.Clone("jitter_vs_xy")

for i in range(1,hist.GetXaxis().GetNbins()+1):
    for j in range(1,hist.GetYaxis().GetNbins()+1):
        tmpHist = hist.ProjectionZ("pz",i,i,j,j)
        myMean = tmpHist.GetMean()
        myRMS = tmpHist.GetRMS()
        value = myMean
        nEvents = tmpHist.GetEntries()
        if(nEvents>20):
            tmpHist.Rebin(2)
            myLanGausFunction = fit.fit(tmpHist, fitrange=(myMean-1.5*myRMS,myMean+3*myRMS))
            myMPV = myLanGausFunction.GetParameter(1)
            value = myMPV
            # gaussian = TF1("gaussian", "gaus")
            # gaussian.SetRange(myMean-2*myRMS,myMean+2*myRMS)
            # tmpHist.Fit(gaussian, "R")
            # myMean = gaussian.GetParameter(1)
            # mySigma = gaussian.GetParameter(2)
            # value = myMean
            ##For Debugging Gaussian
            # tmpHist.Draw("hist")
            # gaussian.Draw("same")
            # outdir_tmp = myStyle.GetPlotsDir(outdir, "jitter_xy_fits/")
            # canvas.SaveAs(outdir_tmp+"q_"+str(i)+"_"+str(j)+".gif")
            #For Debugging LanGauss
            tmpHist.Draw("hist")
            myLanGausFunction.Draw("same")
            outdir_tmp = myStyle.GetPlotsDir(outdir, "Jitter/jitter_xy_fits/")
            canvas.SaveAs(outdir_tmp+"q_"+str(i)+"_"+str(j)+".gif")
            jitter_vs_xy.SetBinContent(i,j,value)
        else:
            jitter_vs_xy.SetBinContent(i,j,0)
            
jitter_vs_xy.Draw("colz")
jitter_vs_xy.SetStats(0)
jitter_vs_xy.SetTitle("Weighted jitter vs XY")
jitter_vs_xy.GetXaxis().SetTitle("Track x position [mm]")
jitter_vs_xy.GetYaxis().SetTitle("Track x position [mm]")
canvas.SetRightMargin(0.18)
canvas.SetLeftMargin(0.12)
#myStyle.SensorInfoSmart(dataset,2.0*myStyle.GetMargin())
canvas.SaveAs(outdir+"Jitter/weighted_jitter_vs_xy.gif")