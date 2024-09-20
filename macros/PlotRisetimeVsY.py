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

canvas = TCanvas("cv","cv",1000,800)
gPad.SetLeftMargin(0.12)
gPad.SetRightMargin(0.19)
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

outdir_tmp1 = myStyle.GetPlotsDir(outdir, "RisetimeStudy/")
outdir_tmp2 = myStyle.GetPlotsDir(outdir_tmp1, "Risetime_vs_Y_fits/")

fit = langaus.LanGausFit()

colors = myStyle.GetColors(True)

sensor_Geometry = myStyle.GetGeometry(dataset)

sensor = sensor_Geometry['sensor']
pitch  = sensor_Geometry['pitch']

hist = inputfile.Get("risetime_vs_xy")

hist2D = hist.Project3D("y")
risetime_vs_y = hist2D.Clone("risetime_vs_y")

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
            tmpHist.Rebin(10)
            myLanGausFunction = fit.fit(tmpHist, fitrange=(myMean-1.5*myRMS,myMean+3*myRMS))
            myMPV = myLanGausFunction.GetParameter(1)
            value = myMPV
            #For Debugging LanGauss
            tmpHist.Draw("hist")
            myLanGausFunction.Draw("same")
            # gaussian = TF1("gaussian", "gaus")
            # gaussian.SetRange(myMean-2*myRMS,myMean+2*myRMS)
            # tmpHist.Fit(gaussian, "R")
            # myMean = gaussian.GetParameter(1)
            # mySigma = gaussian.GetParameter(2)
            # value = myMean
            # #For Debugging Gaussian
            # tmpHist.Draw("hist")
            # gaussian.Draw("same")
            canvas.SaveAs(outdir_tmp2+"q_"+str(region[iter])+","+str(region[iter]+1)+"_"+str(j)+".gif")
            risetime_vs_y.SetBinContent(j,value)
        else:
            risetime_vs_y.SetBinContent(j,0)
            
    risetime_vs_y.Draw("hist")
    risetime_vs_y.SetStats(0)
    risetime_vs_y.SetTitle("Risetime vs Y")
    risetime_vs_y.GetXaxis().SetTitle("Track y position [mm]")
    risetime_vs_y.GetXaxis().SetRangeUser(-3,3)
    risetime_vs_y.GetYaxis().SetTitle("Risetime [ps]")
    risetime_vs_y.GetYaxis().SetRangeUser(0,1000)
    risetime_vs_y.GetYaxis().SetTitleOffset(1.2)
    #myStyle.SensorInfoSmart(dataset,2.0*myStyle.GetMargin())
    canvas.SaveAs(outdir+"risetime_vs_y_"+str(label[iter])+".png")

    file = TFile(outdir_tmp1+"risetime_vs_y_atX="+str(region[iter])+","+str(region[iter]+1)+".root", "RECREATE")
    risetime_vs_y.Write()
    file.Close()
