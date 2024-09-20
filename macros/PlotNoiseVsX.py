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
parser.add_option('-x','--xlength', dest='xlength', default = 1.0, help="Limit x-axis in final plot")
parser.add_option('-y','--ylength', dest='ylength', default = 5, help="Max Noise value in final plot")
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

outdirTmp1 = myStyle.GetPlotsDir(outdir, "NoiseStudy/")
outdirTmp2 = myStyle.GetPlotsDir(outdirTmp1, "Noise_vs_X_fits/")

#Get 3D histograms
channel_good_index = []
th3_baselineRMS_vs_xy_ch = []
for i in range(3):
    hname = "baselineRMS_vs_xy_channel0"+str(i)
    if inputfile.Get(hname):
        channel_good_index.append(i)
        th3_baselineRMS_vs_xy_ch.append(inputfile.Get(hname))


shift = 0#inputfile.Get("stripBoxInfo03").GetMean(1)

#Build 2D amp vs x histograms
list_th2_baselineRMS_vs_x = []
for i,ch in enumerate(channel_good_index):
    list_th2_baselineRMS_vs_x.append(th3_baselineRMS_vs_xy_ch[i].Project3D("zx"))

#Build baselineRMS histograms
th1 = th3_baselineRMS_vs_xy_ch[0].ProjectionX().Clone("th1")
th1_Nbins = th1.GetXaxis().GetNbins()
th1_Xmin = th1.GetXaxis().GetXmin()-shift
th1_Xmax = th1.GetXaxis().GetXmax()-shift
list_baselineRMS_vs_x = []

for i,ch in enumerate(channel_good_index):
    list_baselineRMS_vs_x.append(TH1F("baselineRMS_vs_x_channel0%i"%(ch),"", th1_Nbins, th1_Xmin, th1_Xmax))

print ("BaselineRMS vs X: " + str(th1.GetXaxis().GetBinLowEdge(1)-shift) + " -> " + str(th1.GetXaxis().GetBinUpEdge(th1.GetXaxis().GetNbins())-shift))

print("Setting up Langaus")
fit = langaus.LanGausFit()
print("Setup Langaus")
canvas = TCanvas("cv","cv",1000,800)

maxAmpChannels = []
maxAmpALL = 0
n_channels = 0
#loop over X,Y bins
for channel in range(0, len(list_baselineRMS_vs_x)):
    # print("Channel : " + str(channel))
    maxAmp = 0
    totalEvents = list_th2_baselineRMS_vs_x[channel].GetEntries()
    for i in range(1, list_baselineRMS_vs_x[channel].GetXaxis().GetNbins()+1):
        tmpHist = list_th2_baselineRMS_vs_x[channel].ProjectionY("py",i,i)
        myMean = tmpHist.GetMean()
        myRMS = tmpHist.GetRMS()
        value = myMean            
        nEvents = tmpHist.GetEntries()

        nXBins = th1_Nbins
        minEvtsCut = totalEvents/nXBins
        if i==1: print("Channel %i: nEvents > %.2f (Total events: %i; N bins: %i)"%(channel,minEvtsCut,totalEvents,nXBins))

        if(nEvents > minEvtsCut):
            gaussian = TF1("gaussian", "gaus")
            gaussian.SetRange(myMean-1.5*myRMS,myMean+1.5*myRMS)
            tmpHist.Fit(gaussian, "R")
            myMean = gaussian.GetParameter(1)
            value = myMean
            # myLanGausFunction = fit.fit(tmpHist, fitrange=(myMean-1*myRMS,myMean+3*myRMS))
            # myMPV = myLanGausFunction.GetParameter(1)
            # value = myMPV

            if(debugMode):
                tmpHist.Draw("hist")
                gaussian.Draw("same") # For Debugging - Gaussian
                # myLanGausFunction.Draw("same") # For Debugging - LanGauss
                canvas.SaveAs(outdirTmp2+"q_"+str(i)+"_"+str(channel)+".gif")
        else:
            value = 0.0
        value = value if(value>0.0) else 0.0

        list_baselineRMS_vs_x[channel].SetBinContent(i,value)
                    
# Save baselineRMS histograms
outputfile = TFile("%sPlotNoiseVsX.root"%(outdirTmp1),"RECREATE")

for hist in list_baselineRMS_vs_x:
    hist.Write()

outputfile.Close()


#Make final plots
plotfile = TFile("%sPlotNoiseVsX.root"%(outdirTmp1),"READ")
plotList_baselineRMS_vs_x  = []
for i,ch in enumerate(channel_good_index):
    plot_baselineRMS = plotfile.Get("baselineRMS_vs_x_channel0%i"%ch)
    plot_baselineRMS.SetLineWidth(2)
    plot_baselineRMS.SetLineColor(colors[i])
    plotList_baselineRMS_vs_x.append(plot_baselineRMS)


tempbaselineRMS_vs_x = TH1F("htemp","",1,-xlength,xlength)
tempbaselineRMS_vs_x.Draw("hist")
tempbaselineRMS_vs_x.SetStats(0)
tempbaselineRMS_vs_x.SetTitle("")
tempbaselineRMS_vs_x.GetXaxis().SetTitle("Track x position [mm]")
tempbaselineRMS_vs_x.GetYaxis().SetTitle("BaselineRMS [mV]")
tempbaselineRMS_vs_x.SetLineWidth(2)

tempbaselineRMS_vs_x.SetMaximum(ylength)

# boxes = getStripBox(inputfile,0,ylength-10.0,False, 18, True, shift)
# for box in boxes:
#    box.Draw()
tempbaselineRMS_vs_x.Draw("AXIS same")
tempbaselineRMS_vs_x.Draw("hist same")

print("\n")
temp1=list_baselineRMS_vs_x[2].GetBinContent(list_baselineRMS_vs_x[2].FindBin(-0.25))
temp2=list_baselineRMS_vs_x[1].GetBinContent(list_baselineRMS_vs_x[1].FindBin(-0.25))
temp3=list_baselineRMS_vs_x[1].GetBinContent(list_baselineRMS_vs_x[1].FindBin(0.25))
temp4=list_baselineRMS_vs_x[0].GetBinContent(list_baselineRMS_vs_x[0].FindBin(0.25))
print("Bins: ",list_baselineRMS_vs_x[2].FindBin(-0.25),list_baselineRMS_vs_x[1].FindBin(-0.25),list_baselineRMS_vs_x[1].FindBin(0.25),list_baselineRMS_vs_x[0].FindBin(0.25))
print("Mid-gap noise = ",temp1,temp2,temp3,temp4)
print("\nAverage mid-gap noise = ",(temp1+temp2+temp3+temp4)/4,"\n")

legend = TLegend(2*myStyle.GetMargin()+0.02,1-myStyle.GetMargin()-0.02-0.2,1-myStyle.GetMargin()-0.02,1-myStyle.GetMargin()-0.02)
legend.SetNColumns(3)
legend.SetTextFont(myStyle.GetFont())
legend.SetTextSize(myStyle.GetSize())
legend.SetBorderSize(0)
legend.SetFillColor(kWhite)

for i,ch in enumerate(channel_good_index):
    plotList_baselineRMS_vs_x[i].Draw("hist same")
    legend.AddEntry(plotList_baselineRMS_vs_x[i], "Strip %i"%(ch+1))
legend.Draw()

# myStyle.BeamInfo()
myStyle.SensorInfoSmart(dataset)

canvas.SaveAs(outdir+"BaselineRMS_vs_x_"+sensor+".gif")