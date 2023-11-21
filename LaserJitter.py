import ROOT
from ROOT import TFile,TTree,TCanvas,TH1F,TH2F,TLatex,TMath,TEfficiency,TGraphAsymmErrors,TLegend,gROOT,gPad,gStyle, kWhite, TF1, TPaveStats
import os
import langaus
import optparse
import time
from matplotlib import pyplot as plt
gROOT.SetBatch( True )
gStyle.SetOptFit(1011)

plt.rcParams.update({'font.size': 20})

canvas = TCanvas("cv","cv",800,800)
gPad.SetLeftMargin(0.12)
gPad.SetRightMargin(0.15)
gPad.SetTopMargin(0.08)
gPad.SetBottomMargin(0.12)
gPad.SetTicks(1,1)

fit = langaus.LanGausFit()
inputfile = TFile("./HPK_laser_jitter.root ")
tree = inputfile.Get("pulse")
hist = TH1F("jitter", "Jitter from trigger", 92, -10.0, 20.0)
# tree.SetBranchAddress("baseline_RMS", rms)
# tree.SetBranchAddress("risetime", dvdt)
for i in tree:
    hist.Fill(1e12*(i.baseline_RMS[3]/abs(i.risetime[3])))

# hist.Rebin(4)
myMean = hist.GetMean()
myRMS = hist.GetRMS()
value = myMean

myLanGausFunction = fit.fit(hist, fitrange=(myMean-1.5*myRMS,myMean+3*myRMS))
myMPV = myLanGausFunction.GetParameter(1)
value = myMPV
# gaussian = TF1("gaussian", "gaus")
# gaussian.SetRange(myMean-2*myRMS,myMean+2*myRMS)
# hist.Fit(gaussian, "R")
# myMean = gaussian.GetParameter(1)
# mySigma = gaussian.GetParameter(2)
# value = myMean

hist.Draw("hist")
myLanGausFunction.Draw("same")
# gaussian.Draw("same")
hist.SetTitle("Jitter from trigger")
hist.GetXaxis().SetTitle("Counts")
hist.GetXaxis().SetTitle("Jitter [ps]")
canvas.SetRightMargin(0.18)
canvas.SetLeftMargin(0.12)
canvas.SaveAs("Laser_jitter.png")