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

hist2D = hist.Project3D("y")
jitter_vs_y = hist2D.Clone("jitter_vs_y")

region = [hist.GetXaxis().FindBin(-0.25), hist.GetXaxis().FindBin(0.05)]
label = ["midgap", "stripCenter"]

for iter in range(len(region)):
    for j in range(1,hist.GetYaxis().GetNbins()+1):
        tmpHist = hist.ProjectionZ("pz",region[iter],region[iter]+1,j,j) #combining two x-bins to increase statistics
        myMean = tmpHist.GetMean()
        myRMS = tmpHist.GetRMS()
        value = myMean
        nEvents = tmpHist.GetEntries()
        if(nEvents>20):
            tmpHist.Rebin(4)
            # myLanGausFunction = fit.fit(tmpHist, fitrange=(myMean-1.9*myRMS,myMean+3*myRMS))
            # myMPV = myLanGausFunction.GetParameter(1)
            # value = myMPV
            # #For Debugging LanGauss
            # tmpHist.Draw("hist")
            # myLanGausFunction.Draw("same")
            # outdir_tmp = myStyle.GetPlotsDir(outdir, "jitter_y_fits/")
            # canvas.SaveAs(outdir_tmp+"q_"+str(j)+".gif")
            gaussian = TF1("gaussian", "gaus")
            gaussian.SetRange(myMean-2*myRMS,myMean+2*myRMS)
            tmpHist.Fit(gaussian, "R")
            myMean = gaussian.GetParameter(1)
            mySigma = gaussian.GetParameter(2)
            value = myMean
            #For Debugging Gaussian
            tmpHist.Draw("hist")
            gaussian.Draw("same")
            outdir_tmp = myStyle.GetPlotsDir(outdir, "Jitter/jitter_y_fits/")
            canvas.SaveAs(outdir_tmp+"q_"+str(region[iter])+","+str(region[iter]+1)+"_"+str(j)+".gif")
            jitter_vs_y.SetBinContent(j,value)
        else:
            jitter_vs_y.SetBinContent(j,0)
            
    jitter_vs_y.Draw("hist")
    jitter_vs_y.SetStats(0)
    jitter_vs_y.SetTitle("Weighted jitter vs Y")
    jitter_vs_y.GetXaxis().SetTitle("Track y position [mm]")
    jitter_vs_y.GetYaxis().SetTitle("Jitter [ps]")
    jitter_vs_y.GetYaxis().SetRangeUser(0,40)
    canvas.SetRightMargin(0.18)
    canvas.SetLeftMargin(0.12)
    #myStyle.SensorInfoSmart(dataset,2.0*myStyle.GetMargin())
    canvas.SaveAs(outdir+"Jitter/weighted_jitter_vs_y_"+str(label[iter])+".gif")

    file = TFile(outdir+"Jitter/jitter_vs_y_atX="+str(region[iter])+","+str(region[iter]+1)+".root", "RECREATE")
    jitter_vs_y.Write()
    file.Close()
