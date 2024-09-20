from ROOT import TFile,TTree,TCanvas,TH1F, TF1,TH2F,TLatex,TMath,TEfficiency,TGraphAsymmErrors,TLegend,gROOT,gStyle, kWhite
import os
import EfficiencyUtils
import langaus
import optparse
import time
from stripBox import getStripBox
import myStyle

gROOT.SetBatch( True )
gStyle.SetOptFit(1011)

## Defining Style
myStyle.ForceStyle()
# gStyle.SetTitleYOffset(1.1)
organized_mode=True

# Construct the argument parser
parser = optparse.OptionParser("usage: %prog [options]\n")
parser.add_option('-x','--xlength', dest='xlength', default = 2.0, help="Limit x-axis in final plot")
parser.add_option('-y','--ylength', dest='ylength', default = 200, help="Max slewrate value in final plot")
parser.add_option('-D', dest='Dataset', default = "", help="Dataset, which determines filepath")
parser.add_option('-d', dest='Debug', default = False, help="Debug mode")
options, args = parser.parse_args()

dataset = options.Dataset
debugMode = options.Debug
outdir=""
if organized_mode: 
    outdir = myStyle.getOutputDir(dataset)
    inputfile = TFile("%s%s_Analyze.root"%(outdir,dataset))
else: 
    print("Analyze file not found.") 

colors = myStyle.GetColors(True)

sensor_Geometry = myStyle.GetGeometry(dataset)
sensor = sensor_Geometry['sensor']
xlength = float(options.xlength)
ylength = float(options.ylength)

outdirTmp1 = myStyle.GetPlotsDir(outdir, "SlewrateStudy/")
outdirTmp2 = myStyle.GetPlotsDir(outdirTmp1, "SlewrateOverall_vs_X_fits/")

#Get 3D histograms
channel_good_index = []
hname = "slewRate_vs_xy"
th3_slewrate_vs_xy = inputfile.Get(hname)
list_th2_slewrate_vs_x = th3_slewrate_vs_xy.Project3D("zx")

shift = 0 #inputfile.Get("stripBoxInfo03").GetMean(1)

#Build 2D slewrate vs x histograms

#Build slewrate histograms
th1 = th3_slewrate_vs_xy.ProjectionX().Clone("th1")
th1_Nbins = th1.GetXaxis().GetNbins()
th1_Xmin = th1.GetXaxis().GetXmin() - shift
th1_Xmax = th1.GetXaxis().GetXmax() - shift
print(th1_Xmin)
print(th1_Xmax)
list_slewrate_vs_x = TH1F("slewrate_vs_x","", th1_Nbins, th1_Xmin, th1_Xmax)

print ("Slewrate vs X: " + str(th1.GetXaxis().GetBinLowEdge(1) - shift) + " -> " + str(th1.GetXaxis().GetBinUpEdge(th1.GetXaxis().GetNbins()) - shift))

print("Setting up Langaus")
fit = langaus.LanGausFit()
print("Setup Langaus")
canvas = TCanvas("cv","cv",1000,800)

totalEvents = list_th2_slewrate_vs_x.GetEntries()
for i in range(1, list_slewrate_vs_x.GetXaxis().GetNbins()+1):
    tmpHist = list_th2_slewrate_vs_x.ProjectionY("py",i,i)
    myTotalEvents=tmpHist.Integral()
    myMean = tmpHist.GetMean()
    myRMS = tmpHist.GetRMS()
    value = myMean            
    nEvents = tmpHist.GetEntries()

    nXBins = th1_Nbins
    minEvtsCut = 0.75*totalEvents/nXBins
    if i==1: print("nEvents > %.2f (Total events: %i; N bins: %i)"%(minEvtsCut,totalEvents,nXBins))
    if(nEvents > minEvtsCut):
        tmpHist.Rebin(5)
        gaussian = TF1("gaussian", "gaus")
        gaussian.SetRange(myMean-1.5*myRMS,myMean+1.5*myRMS)
        tmpHist.Fit(gaussian, "R")
        myMean = gaussian.GetParameter(1)
        value = myMean
        # myLanGausFunction = fit.fit(tmpHist, fitrange=(myMean-1*myRMS,myMean+3*myRMS))
        # myMPV = myLanGausFunction.GetParameter(1)
        # value = myMPV

        ##For Debugging
        if(debugMode):
            tmpHist.Draw("hist")
            gaussian.Draw("same") # For Debugging - Gaussian
            # myLanGausFunction.Draw("same") # For Debugging - LanGauss
            canvas.SaveAs(outdirTmp2+"q_"+str(i)+".gif")
    else:
        value = 0.0

    value = value if(value>0.0) else 0.0

    list_slewrate_vs_x.SetBinContent(i,value)


# Save slewrate histograms
outputfile = TFile("%sPlotSlewrateOverallVsX.root"%(outdirTmp1),"RECREATE")
list_slewrate_vs_x.Write()

outputfile.Close()

#Make final plots
plotfile = TFile("%sPlotSlewrateOverallVsX.root"%(outdirTmp1),"READ")
plotList_slewrate_vs_x = plotfile.Get("slewrate_vs_x")
plotList_slewrate_vs_x.SetLineWidth(2)

totalSlewrate_vs_x = TH1F("htemp","",1,-xlength,xlength)
totalSlewrate_vs_x.Draw("hist")
totalSlewrate_vs_x.SetStats(0)
totalSlewrate_vs_x.SetTitle("")
totalSlewrate_vs_x.GetXaxis().SetTitle("Track x position [mm]")
totalSlewrate_vs_x.GetYaxis().SetTitle("Slewrate [mV/ns]")
totalSlewrate_vs_x.SetLineWidth(2)

totalSlewrate_vs_x.SetMaximum(ylength)

# boxes = getStripBox(inputfile,0,ylength-10.0,False, 18, True, shift)
# for box in boxes:
#    box.Draw()
totalSlewrate_vs_x.Draw("AXIS same")
totalSlewrate_vs_x.Draw("hist same")


legend = TLegend(2*myStyle.GetMargin()+0.02,1-myStyle.GetMargin()-0.02-0.2,1-myStyle.GetMargin()-0.02,1-myStyle.GetMargin()-0.02)
legend.SetNColumns(3)
legend.SetTextFont(myStyle.GetFont())
legend.SetTextSize(myStyle.GetSize())
legend.SetBorderSize(0)
legend.SetFillColor(kWhite)

plotList_slewrate_vs_x.Draw("hist same")

# myStyle.BeamInfo()
myStyle.SensorInfoSmart(dataset)

canvas.SaveAs(outdir+"SlewrateOverall_vs_x_"+sensor+".gif")