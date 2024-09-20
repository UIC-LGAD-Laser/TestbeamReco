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

outdir_tmp = myStyle.GetPlotsDir(outdir, "AmpStudy/")

colors = myStyle.GetColors(True)

sensor_Geometry = myStyle.GetGeometry(dataset)

sensor = sensor_Geometry['sensor']
pitch  = sensor_Geometry['pitch']

def get_res(outdir,tmpHist,xbin):
    myMean = tmpHist.GetMean()
    myRMS = tmpHist.GetRMS()
    value = myMean
    nEvents = tmpHist.GetEntries()
    print("\n",nEvents,"\n")
    # if(nEvents > 20):
    tmpHist.Rebin(2)
    gaussian = TF1("gaussian", "gaus")
    gaussian.SetRange(myMean-2*myRMS,myMean+2*myRMS)
    tmpHist.Fit(gaussian, "R")
    myMean = gaussian.GetParameter(1)
    mySigma = gaussian.GetParameter(2)
    mySigmaError = gaussian.GetParError(2)
    value = 1000.0*mySigma
    ##For Debugging
    tmpHist.Draw("hist")
    gaussian.Draw("same")
    outdir_tmp = myStyle.GetPlotsDir(outdir, "AmpStudy/TR_vs_Amp_fits/")
    canvas2.SaveAs(outdir_tmp+"q_"+str(xbin)+".gif")
    # else:
    #     value = -0.1
    return value

hist = inputfile.Get("amplitude_vs_dT")
profile2D = hist
#hist.Project3DProfile("yx")
# Change the limits of the X, Y and Z axis
profile2D.GetXaxis().SetRangeUser(0, 150)
profile2D.GetYaxis().SetRangeUser(-0.3, 0.3)
# profile2D.GetZaxis().SetRangeUser(0, 25)

# # Define canvas
# canvas = TCanvas("canvas", "2D Profile", 1000, 900)
# canvas.SetRightMargin(0.18)
# # Draw
# profile2D.Draw("COLZ")
# profile2D.GetXaxis().SetTitle("Amplitude [mV]")
# profile2D.GetYaxis().SetTitle("dT [ns]")
# profile2D.SetMarkerStyle(21)
# profile2D.SetMarkerSize(2)
# canvas.Update()
# gStyle.SetStatX(0.7)
# canvas.Update()
# canvas.SaveAs(outdir+"AmpStudy/Amp_vs_dT_"+sensor+".gif")


# plot amp vs resolution after taking Y-projection from amp vs dT plot.
amps = []
tr = []
for a in range(1,hist.GetXaxis().GetNbins()+1):
    if(hist.ProjectionY("py",a,a).GetEntries()>100):
        tr.append(get_res(outdir,hist.ProjectionY("py",a,a),a))
        amps.append(hist.GetXaxis().GetBinCenter(a))

plt.scatter(amps,tr,marker='s')
plt.xlabel('Amplitude [mV]')
plt.ylabel('Time resolution [ps]')
plt.show()
