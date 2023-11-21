from ROOT import TFile,TTree,TCanvas,TH1F,TH2F,TLatex,TMath,TEfficiency,TGraphAsymmErrors,TLegend,gROOT,gPad,gStyle, kWhite, TF1, TPaveStats
import os
import EfficiencyUtils
import langaus
import optparse
import time
#from stripBox import getStripBox
import myStyle
from matplotlib import pyplot as plt
import numpy as np
gROOT.SetBatch( True )
gStyle.SetOptFit(1011)

## Defining Style
myStyle.ForceStyle()
# gStyle.SetTitleYOffset(1.1)
organized_mode=True
plt.rcParams.update({'font.size': 20})

canvas2 = TCanvas("cv","cv",800,800)
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

outdir_tmp = myStyle.GetPlotsDir(outdir, "RisetimeStudy/")
outdir_tmp2 = myStyle.GetPlotsDir(outdir_tmp, "Amp01_vs_risetime_fits/")
colors = myStyle.GetColors(True)

sensor_Geometry = myStyle.GetGeometry(dataset)

sensor = sensor_Geometry['sensor']
pitch  = sensor_Geometry['pitch']
fit = langaus.LanGausFit()

def get_risetime(outdir,tmpHist,xbin):
    myMean = tmpHist.GetMean()
    myRMS = tmpHist.GetRMS()
    value = myMean
    nEvents = tmpHist.GetEntries()
    # if(nEvents > 20):
    tmpHist.Rebin(10)
    myLanGausFunction = fit.fit(tmpHist, fitrange=(myMean-1.5*myRMS,myMean+3*myRMS))
    myMPV = myLanGausFunction.GetParameter(1)
    value = myMPV

    ##For Debugging
    tmpHist.Draw("hist")
    myLanGausFunction.Draw("same")
    canvas2.SaveAs(outdir_tmp2+"q_"+str(xbin)+".gif")
    # else:
    #     value = -0.1
    return value

# hist = inputfile.Get("amplitude_vs_risetime")
hist = inputfile.Get("amplitude_vs_risetime01")
profile2D = hist
# Change the limits of the X and Y axis
profile2D.GetXaxis().SetRangeUser(0, 100)
profile2D.GetYaxis().SetRangeUser(400, 1500)

# # Define canvas
# canvas = TCanvas("canvas", "2D Profile", 1200, 800)
# canvas.SetRightMargin(0.18)
# # Draw
# profile2D.Draw("COLZ")
# profile2D.GetXaxis().SetTitle("Amplitude [mV]")
# profile2D.GetYaxis().SetTitle("Risetime [ps]")
# profile2D.GetYaxis().SetTitleOffset(1.0)
# profile2D.SetMarkerStyle(21)
# profile2D.SetMarkerSize(2)
# canvas.Update()
# # gStyle.SetStatX(0.7)
# st = profile2D.FindObject("stats") 
# st.SetX1NDC(0.6)
# st.SetX2NDC(0.8)
# canvas.Update()
# canvas.SaveAs(outdir+"Risetime/Amp_vs_risetime_hist.png")

# plot amp vs risetime after taking Y-projection from amp vs risetime plot.
amps = []
risetime = []
for a in range(1,hist.GetXaxis().GetNbins()+1):
    if(hist.ProjectionY("py",a,a).GetEntries()>100):
        risetime.append(get_risetime(outdir,hist.ProjectionY("py",a,a),hist.GetXaxis().GetBinCenter(a)))
        amps.append(hist.GetXaxis().GetBinCenter(a))

plt.scatter(amps,risetime,marker='s')
plt.grid()
plt.xlabel('Amplitude [mV]')
plt.xlim(0,100)
plt.ylim(650,850)
plt.yticks(np.arange(650, 850, 20))
plt.ylabel('Risetime [ps]')
plt.show()