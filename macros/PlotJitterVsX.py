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

temp = inputfile.Get("weighted_jitter_vs_xy")
hist = temp.Project3D("zx")
hist1D = temp.Project3D("x")
jitter_vs_x = hist1D.Clone("jitter_vs_x")

for i in range(1,hist.GetXaxis().GetNbins()+1):
    tmpHist = hist.ProjectionY("py",i,i)
    myMean = tmpHist.GetMean()
    myRMS = tmpHist.GetRMS()
    value = myMean
    valueError = 0
    nEvents = tmpHist.GetEntries()
    minEvtsCut = 1500
    # Fit range specific for Lecroy datasets of W2, W4 and W9 sensors. 
    # DS(30May25) - removed specific selection for W9 after updated timeRes/jitter hists in analyze.
    # if("W9" in dataset):
    #     minEvtsCut = 50
    if(nEvents>minEvtsCut):
        if("W9" in dataset):
            tmpHist.Rebin(2)
        myLanGausFunction = fit.fit(tmpHist, fitrange=(myMean-1.5*myRMS,myMean+3*myRMS))
        myMPV = myLanGausFunction.GetParameter(1)
        myMPVError = myLanGausFunction.GetParError(1)
        value = myMPV
        valueError = myMPVError
        # gaussian = TF1("gaussian", "gaus")
        # gaussian.SetRange(myMean-2*myRMS,myMean+2*myRMS)
        # tmpHist.Fit(gaussian, "R")
        # myMean = gaussian.GetParameter(1)
        # mySigma = gaussian.GetParameter(2)
        # value = myMean

        # ##For Debugging Gaussian
        # tmpHist.Draw("hist")
        # gaussian.Draw("same")
        # outdir_tmp = myStyle.GetPlotsDir(outdir, "jitter_x_fits/")
        # canvas.SaveAs(outdir_tmp+"q_"+str(i)+".gif")
        #For Debugging LandGauss
        tmpHist.Draw("hist")
        myLanGausFunction.Draw("same")
        outdir_tmp = myStyle.GetPlotsDir(outdir, "Jitter/jitter_x_fits/")
        canvas.SaveAs(outdir_tmp+"q_"+str(i)+".gif")
        jitter_vs_x.SetBinContent(i,value)
        jitter_vs_x.SetBinError(i,valueError)
    else:
        jitter_vs_x.SetBinContent(i,0)
        jitter_vs_x.SetBinError(i,0)
            
jitter_vs_x.Draw("hist E")
jitter_vs_x.SetStats(0)
jitter_vs_x.SetTitle("Weighted jitter vs X")
jitter_vs_x.GetXaxis().SetTitle("Track x position [mm]")
jitter_vs_x.GetYaxis().SetTitle("Jitter [ps]")
jitter_vs_x.GetYaxis().SetRangeUser(0,120.0)
canvas.SetRightMargin(0.18)
canvas.SetLeftMargin(0.12)
#myStyle.SensorInfoSmart(dataset,2.0*myStyle.GetMargin())
canvas.SaveAs(outdir+"Jitter/weighted_jitter_vs_x.gif")


file = TFile(outdir+"Jitter/jitter_vs_x.root", "RECREATE")
jitter_vs_x.Write()
file.Close()
