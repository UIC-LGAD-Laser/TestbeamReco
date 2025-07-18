from ROOT import TFile,TTree,TCanvas,TH1F,TF1,TH2F,TLatex,TMath,TEfficiency,TGraphAsymmErrors,TLegend,gROOT,gStyle, kWhite
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
parser.add_option('-x','--xlength', dest='xlength', default = 0.8, help="Limit x-axis in final plot")
parser.add_option('-y','--ylength', dest='ylength', default = 100, help="Max Amp value in final plot")
parser.add_option('-D', dest='Dataset', default = "", help="Dataset, which determines filepath")
options, args = parser.parse_args()

dataset = options.Dataset
outdir=""
if organized_mode: 
    outdir = myStyle.getOutputDir(dataset)
    inputfile = TFile("%s%s_Analyze.root"%(outdir,dataset))
else: 
    inputfile = TFile("../test/myoutputfile.root")   

colors = myStyle.GetColors(True)

sensor_Geometry = myStyle.GetGeometry(dataset)
sensor = sensor_Geometry['sensor']
xlength = float(options.xlength)
ylength = float(options.ylength)

outdirTmp = myStyle.GetPlotsDir(outdir, "PaperCommentsAmp_vs_X_fits/")

#Get 3D histograms
channel_good_index = []
th3_amplitude_vs_xy_ch = []
for i in range(3):
    hname = "amplitude_vs_xy_channel0"+str(i)
    if inputfile.Get(hname):
        channel_good_index.append(i)
        th3_amplitude_vs_xy_ch.append(inputfile.Get(hname))

th3_amplitude_vs_xy_channelall = inputfile.Get("totamplitude_vs_xy")

shift = 0#inputfile.Get("stripBoxInfo03").GetMean(1)

#Build 2D amp vs x histograms
list_th2_amplitude_vs_x = []
for i,ch in enumerate(channel_good_index):
    list_th2_amplitude_vs_x.append(th3_amplitude_vs_xy_ch[i].Project3D("zx"))

#Build amplitude histograms
th1 = th3_amplitude_vs_xy_ch[0].ProjectionX().Clone("th1")
th1_Nbins = th1.GetXaxis().GetNbins()
th1_Xmin = th1.GetXaxis().GetXmin()-shift
th1_Xmax = th1.GetXaxis().GetXmax()-shift
list_amplitude_vs_x = []

for i,ch in enumerate(channel_good_index):
    list_amplitude_vs_x.append(TH1F("amplitude_vs_x_channel0%i"%(ch),"", th1_Nbins, th1_Xmin, th1_Xmax))

print ("Amplitude vs X: " + str(th1.GetXaxis().GetBinLowEdge(1)-shift) + " -> " + str(th1.GetXaxis().GetBinUpEdge(th1.GetXaxis().GetNbins())-shift))

canvas = TCanvas("cv","cv",1000,800)

maxAmpChannels = []
maxAmpALL = 0
n_channels = 0
midgap_bins = [list_amplitude_vs_x[1].FindBin(0)]

amplitude_distrib = TFile("%sMidGapAmp_distribution.root"%(outdir),"RECREATE")

#loop over X,Y bins
for channel in range(0, len(list_amplitude_vs_x)):
    # print("Channel : " + str(channel))
    maxAmp = 0
    totalEvents = list_th2_amplitude_vs_x[channel].GetEntries()
    for i in range(1, list_amplitude_vs_x[channel].GetXaxis().GetNbins()+1):
    # for i in range(list_amplitude_vs_x[channel].GetXaxis().FindBin(-0.25), list_amplitude_vs_x[channel].GetXaxis().FindBin(0.25)):
        tmpHist = list_th2_amplitude_vs_x[channel].ProjectionY("py",i,i)
        tmpHist.GetXaxis().SetRangeUser(0,200)
        myMean = tmpHist.GetMean()
        myRMS = tmpHist.GetRMS()
        value = myMean     
        error = tmpHist.GetMeanError()        
        nEvents = tmpHist.GetEntries()

        nXBins = th1_Nbins
        minEvtsCut = totalEvents/nXBins*0.3
        if i==1: print("Channel %i: nEvents > %.2f (Total events: %i; N bins: %i)"%(channel,minEvtsCut,totalEvents,nXBins))

        if(nEvents > minEvtsCut):
            #use coarser bins when the signal is bigger
            if (myMean > 50) :
                tmpHist.Rebin(1)
            else :
                tmpHist.Rebin(1)
            
            gaussian = TF1("gaussian", "gaus")
            gaussian.SetRange(myMean-1.5*myRMS,myMean+1.5*myRMS)
            tmpHist.Fit(gaussian, "R")
            value = gaussian.GetParameter(1)
            error = gaussian.GetParError(1)

            ##For Debugging
            tmpHist.Draw("hist")
            gaussian.Draw("same")
            canvas.SaveAs(outdirTmp+"q_"+str(i)+"_"+str(channel)+".gif")
            if(i in midgap_bins and channel==2):
                max_bin = tmpHist.GetMaximumBin()
                max_count = tmpHist.GetBinContent(max_bin)
                tmpHist.Scale(1.0 / max_count)
                # tmpHist.Scale(1/tmpHist.Integral())
                tmpHist.GetXaxis().SetRangeUser(0,200)
                tmpHist.Write()
                gaussian2 = TF1("gaussian", "gaus")
                gaussian2.SetRange(myMean-2.*myRMS,myMean+2.*myRMS)
                tmpHist.Fit(gaussian2, "R")
                gaussian2.Write()
        else:
            value = 0.0
            error = 0.0

        value = value if(value>0.0) else 0.0
        error = error if(value>0.0) else 0.0
        list_amplitude_vs_x[channel].SetBinContent(i,value)
        list_amplitude_vs_x[channel].SetBinError(i, error)
                    
amplitude_distrib.Close()
# Save amplitude histograms
outputfile = TFile("%sPaperCommentsAmplitudeVsX.root"%(outdir),"RECREATE")
# for channel in range(0, len(list_amplitude_vs_x)):
#     list_amplitude_vs_x[channel].Write()

for hist in list_amplitude_vs_x:
    hist.Write()

outputfile.Close()

#Make final plots
plotfile = TFile("%sPaperCommentsAmplitudeVsX.root"%(outdir),"READ")
plotList_amplitude_vs_x  = []
for i,ch in enumerate(channel_good_index):
    plot_amplitude = plotfile.Get("amplitude_vs_x_channel0%i"%ch)
    plot_amplitude.SetLineWidth(2)
    plot_amplitude.SetLineColor(colors[i])
    plotList_amplitude_vs_x.append(plot_amplitude)

totalAmplitude_vs_x = TH1F("htemp","",1,-xlength,xlength)

totalAmplitude_vs_x.Draw("hist")
totalAmplitude_vs_x.SetStats(0)
totalAmplitude_vs_x.SetTitle("")
totalAmplitude_vs_x.GetXaxis().SetTitle("Track x position [mm]")
totalAmplitude_vs_x.GetYaxis().SetTitle("Mean signal amplitude [mV]")
totalAmplitude_vs_x.SetLineWidth(2)

totalAmplitude_vs_x.SetMaximum(ylength)

# boxes = getStripBox(inputfile,0,ylength-10.0,False, 18, True, shift)
# for box in boxes:
#    box.Draw()
# totalAmplitude_vs_x.Draw("AXIS same")
# totalAmplitude_vs_x.Draw("hist same")

print("\n")
# for laser paper plots, we look at amplitudes between the right two chnnels only.
temp1=list_amplitude_vs_x[2].GetBinContent(list_amplitude_vs_x[2].FindBin(-0.25))
temp2=list_amplitude_vs_x[1].GetBinContent(list_amplitude_vs_x[1].FindBin(-0.25))
temp3=list_amplitude_vs_x[1].GetBinContent(list_amplitude_vs_x[1].FindBin(0.25))
temp4=list_amplitude_vs_x[0].GetBinContent(list_amplitude_vs_x[0].FindBin(0.25))
print("Bins: ",list_amplitude_vs_x[2].FindBin(-0.25),list_amplitude_vs_x[1].FindBin(-0.25),list_amplitude_vs_x[1].FindBin(0.25),list_amplitude_vs_x[0].FindBin(0.25))
print("Mid-gap amplitude = ",temp1,temp2,temp3,temp4)
print("\nAverage mid-gap amplitude = ",(temp1+temp2+temp3+temp4)/4,"\n")
# temp3=list_amplitude_vs_x[1].GetBinContent(list_amplitude_vs_x[1].FindBin(0))
# error3 = list_amplitude_vs_x[1].GetBinError(list_amplitude_vs_x[1].FindBin(0))
# temp4=list_amplitude_vs_x[2].GetBinContent(list_amplitude_vs_x[2].FindBin(0))
# error4 = list_amplitude_vs_x[2].GetBinError(list_amplitude_vs_x[2].FindBin(0))

# print("Bins: ",list_amplitude_vs_x[1].FindBin(0),list_amplitude_vs_x[2].FindBin(0))
# print("Mid-gap amplitude = ",temp3,temp4)
# print("\nAverage mid-gap amplitude = ",(temp3+temp4)/2,"\n")

# midgapamplitude = (temp3+temp4)/2
# midgaperror = ((error3 / 2)**2 + (error4 / 2)**2)**0.5

# filename = '/uscms/home/dshekar/nobackup/laser_analysis/TestbeamReco/test/time_resolutions_paper.txt'
# with open(filename, 'r') as trfile:
#     lines = trfile.readlines()
# with open(filename, 'w') as trfile:
#     for line in lines:
#         if line.startswith(f'{dataset}:'):
#             line = line.strip() + f': {round(midgapamplitude, 2)}, {round(midgaperror, 2)}\n'
#         trfile.write(line)

legend = TLegend(2*myStyle.GetMargin()+0.02,1-myStyle.GetMargin()-0.02-0.2,1-myStyle.GetMargin()-0.02,1-myStyle.GetMargin()-0.02)
legend.SetNColumns(3)
legend.SetTextFont(myStyle.GetFont())
legend.SetTextSize(myStyle.GetSize())
legend.SetBorderSize(0)
legend.SetFillColor(kWhite)

for i,ch in enumerate(channel_good_index):
    plotList_amplitude_vs_x[i].Draw("histsame")
    legend.AddEntry(plotList_amplitude_vs_x[i], "Strip %i"%(ch+1))
legend.Draw()

# myStyle.BeamInfo()
myStyle.SensorInfoSmart(dataset)

canvas.SaveAs(outdir+"PaperCommentsTotalAmplitude_vs_x_"+sensor+".gif")
