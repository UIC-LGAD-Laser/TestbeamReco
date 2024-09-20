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

def get_res_in_xy_bin(hist3D, xbin, ybin):
    tmpHist = hist3D.ProjectionZ("pz", xbin, xbin, ybin, ybin)
    myMean = tmpHist.GetMean()
    myRMS = tmpHist.GetRMS()
    value = myMean            
    nEvents = tmpHist.GetEntries()
    # print("\n",nEvents,"\n")
    if(nEvents > 20): #laser data does has around 50 points per XY bin. 
        tmpHist.Rebin(2) # by trial and error, seemed like the best number.
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
        outdir_tmp = myStyle.GetPlotsDir(outdir, "AmpStudy/TR_vs_Y_fits/")
        canvas2.SaveAs(outdir_tmp+"q_"+str(xbin)+"_"+str(ybin)+".gif")
    else:
        value = -0.1
    return value

def get_amp_in_xy_bin(hist3D, xbin, ybin):
    tmpHist = hist3D.ProjectionZ("pz", xbin, xbin, ybin, ybin)
    myMean = tmpHist.GetMean()
    myRMS = tmpHist.GetRMS()
    value = myMean            
    nEvents = tmpHist.GetEntries()
    # print("\n",nEvents,"\n")
    if(nEvents > 20):
        gaussian = TF1("gaussian", "gaus")
        gaussian.SetRange(myMean-2*myRMS,myMean+2*myRMS)
        tmpHist.Fit(gaussian, "R")
        value = gaussian.GetParameter(1)
        ##For Debugging
        tmpHist.Draw("hist")
        gaussian.Draw("same")
        outdir_tmp = myStyle.GetPlotsDir(outdir, "AmpStudy/Amp_vs_Y_fits/")
        canvas2.SaveAs(outdir_tmp+"q_"+str(xbin)+"_"+str(ybin)+".gif")
    else:
        value = -5.0
    return value
        
amp = inputfile.Get("amplitude_vs_xy")
dT = inputfile.Get("weighted2_timeDiff_tracker_vs_xy")
amp_vs_dT = TH2F("Amp_vs_TimeRes", "2D Histogram", amp.GetZaxis().GetNbins(), 0, 150, dT.GetZaxis().GetNbins(), 0, 70)
amp_vs_y = []
tr_vs_y = []
y_amp = []
y_tr = []
midgap = [-0.25,0.25]
print(amp.GetYaxis().GetNbins()+1)
print(dT.GetYaxis().GetNbins()+1)
for x in range(len(midgap)):
    for y in range(1,amp.GetYaxis().GetNbins()+1):
        tmpAmp = get_amp_in_xy_bin(amp, amp.GetXaxis().FindBin(midgap[x]), y)
        tmpRes = get_res_in_xy_bin(dT, dT.GetXaxis().FindBin(midgap[x]), y)
        amp_vs_dT.Fill(tmpAmp, tmpRes)
        if(tmpAmp>0):
            amp_vs_y.append(tmpAmp)
            y_amp.append(amp.GetYaxis().GetBinCenter(y))
        if(tmpRes>0):
            tr_vs_y.append(tmpRes)
            y_tr.append(dT.GetYaxis().GetBinCenter(y))

# # Define canvas
# canvas = TCanvas("canvas", "2D Profile", 1000, 900)
# canvas.SetRightMargin(0.18)
# # Draw
# amp_vs_dT.Draw("COLZ")
# amp_vs_dT.GetXaxis().SetTitle("Amplitude [mV]")
# amp_vs_dT.GetYaxis().SetTitle("Time resolution [ps]")
# amp_vs_dT.GetXaxis().SetRangeUser(20,100)
# amp_vs_dT.GetYaxis().SetRangeUser(5,65)
# amp_vs_dT.SetMarkerStyle(21)
# amp_vs_dT.SetMarkerSize(10)
# canvas.Update()
# gStyle.SetStatX(0.7)
# canvas.Update()
# canvas.SaveAs(outdir+"AmpStudy/Amp_vs_res_"+sensor+".gif")

# plot amp vs y-coordinate and TR vs y-coordinate from amp vs Y and tr vs Y plots respectively
plt.scatter(y_amp, amp_vs_y, marker='s')
plt.ylabel('Mid-gap amplitude [mV]')
# plt.scatter(y_tr, tr_vs_y, marker='s')
# plt.ylabel('Time resolution [ps]')
plt.xlabel('Y-coordinate [mm]')
plt.grid() 
plt.show()