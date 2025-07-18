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

outdir_tmp = myStyle.GetPlotsDir(outdir, "JitterForSimulation/")

colors = myStyle.GetColors(True)

sensor_Geometry = myStyle.GetGeometry(dataset)

sensor = sensor_Geometry['sensor']
pitch  = sensor_Geometry['pitch']

temp = inputfile.Get("weighted_jitter_vs_xy")
temp2 = inputfile.Get("jitter1_res_vs_xy")
temp3 = inputfile.Get("jitter2_res_vs_xy")
hist = temp.Project3D("zx")
hist2 = temp2.Project3D("zx")
hist3 = temp3.Project3D("zx")

jitter_vs_x = temp.Project3D("x").Clone("jitter_vs_x")
jitter1_vs_x = temp2.Project3D("x").Clone("jitter1_vs_x")
jitter2_vs_x = temp3.Project3D("x").Clone("jitter2_vs_x")
jitter_vs_x.Draw("hist")
jitter_vs_x.SetStats(0)
jitter_vs_x.SetTitle("Jitter vs X")
jitter_vs_x.GetXaxis().SetTitle("Track x position [mm]")
jitter_vs_x.GetYaxis().SetTitle("Jitter [ps]")
jitter_vs_x.GetYaxis().SetRangeUser(0,150.0)

histograms = [hist, hist2, hist3]
colors = [8,9, 46]
save_histograms = [jitter_vs_x, jitter1_vs_x, jitter2_vs_x]
names = ["weightedJitter", "jitter1_", "jitter2_"]
first=True
fit_canvas = TCanvas("fit_canvas", "fit_canvas", 800, 800)

for temphist, tempnames, savehist, plotcolor in zip(histograms, names, save_histograms, colors):
    for i in range(1, temphist.GetXaxis().GetNbins() + 1):
        tmpHist = temphist.ProjectionY("py", i, i)
        myMean = tmpHist.GetMean()
        myRMS = tmpHist.GetRMS()
        value = myMean
        valueError = 0
        nEvents = tmpHist.GetEntries()
        minEvtsCut = 350 if "jitter2" in tempnames else 1500
        if nEvents > minEvtsCut:
            if "W9" in dataset:
                tmpHist.Rebin(2)
            myLanGausFunction = fit.fit(tmpHist, fitrange=(myMean - 1.5 * myRMS, myMean + 3 * myRMS))
            myMPV = myLanGausFunction.GetParameter(1)
            myMPVError = myLanGausFunction.GetParError(1)
            value = myMPV
            valueError = myMPVError

            # Use the fit canvas for fits
            fit_canvas.cd()
            tmpHist.Draw("hist")
            myLanGausFunction.Draw("same")
            outdir_tmp = myStyle.GetPlotsDir(outdir, "JitterForSimulation/jitter_x_fits/")
            fit_canvas.SaveAs(outdir_tmp + tempnames + str(i) + ".gif")
            savehist.SetBinContent(i, value)
            savehist.SetBinError(i, valueError)
        else:
            savehist.SetBinContent(i, 0)
            savehist.SetBinError(i, 0)

    # Use the main canvas for the main plot
    canvas.cd()
    if first:
        savehist.Draw("hist E")
        first = False
    else:
        savehist.Draw("hist E same")
    savehist.SetLineColor(plotcolor)

# canvas.SetRightMargin(0.18)
# canvas.SetLeftMargin(0.12)

legend = TLegend(myStyle.GetPadCenter()-0.4,0.70,myStyle.GetPadCenter()+0.4,0.90)
legend.SetFillColor(kWhite)
legend.SetFillStyle(4050)#
legend.AddEntry(jitter1_vs_x, "Jitter1")#
legend.AddEntry(jitter2_vs_x, "Jitter2")#
legend.AddEntry(jitter_vs_x, "Weighted jitter")#
legend.Draw()

canvas.SaveAs(outdir+"JitterForSimulation/AllJitter_vs_x.gif")

file = TFile(outdir+"JitterForSimulation/jitter_vs_x.root", "RECREATE")
jitter_vs_x.Write()
jitter1_vs_x.Write()
jitter2_vs_x.Write()
file.Close()
