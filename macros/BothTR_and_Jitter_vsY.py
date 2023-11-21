from ROOT import TFile,TTree,TCanvas,TPad,TH1F,TH2F,TLatex,TMath,TEfficiency,TGraphAsymmErrors,TLegend,TAttLine,gROOT,gStyle, kWhite, TF1
import os
import EfficiencyUtils
import langaus
import optparse
import time
import math
#from stripBox import getStripBox
import myStyle
gROOT.SetBatch( True )
gStyle.SetOptFit(1011)

#HPK_W5_17_2_50T_1P0_500P_50M_E600_190V_oldBinEdges

## Defining Style
myStyle.ForceStyle()
# gStyle.SetTitleYOffset(1.1)
organized_mode=True

# Construct the argument parser
parser = optparse.OptionParser("usage: %prog [options]\n")
parser.add_option('-D', dest='Dataset', default = "", help="Dataset, which determines filepath")
options, args = parser.parse_args()

dataset = options.Dataset
outdir=""
if organized_mode: 
    outdir = myStyle.getOutputDir(dataset)
    inputfile1 = TFile("%s/Jitter/jitter_vs_y_atX=12,13.root"%(outdir)) #midgap
    inputfile2 = TFile("%s/Jitter/jitter_vs_y_atX=18,19.root"%(outdir)) #near stripCenter
    inputfile3 = TFile("%s/TR/tr_vs_y_atX=12,13.root"%(outdir)) #midgap
    inputfile4 = TFile("%s/TR/tr_vs_y_atX=18,19.root"%(outdir)) #near stripCenter
else: 
    inputfile = TFile("../test/myoutputfile.root") 
    inputfile2 = TFile("../test/myoutputfile.root") 
    inputfile3 = TFile("../test/myoutputfile.root") 
    inputfile4 = TFile("../test/myoutputfile.root") 

region = ['midgap','stripCenter']

colors = myStyle.GetColors(True)

sensor_Geometry = myStyle.GetGeometry(dataset)

sensor = sensor_Geometry['sensor']
pitch  = sensor_Geometry['pitch']

canvas = TCanvas("canvas", "TR and Jitter vs X", 1000, 800)

jitter = []
jitter.append(inputfile1.Get("jitter_vs_y"))
jitter.append(inputfile2.Get("jitter_vs_y"))

tr = []
tr.append(inputfile3.Get("tr_vs_y"))
tr.append(inputfile4.Get("tr_vs_y"))

landau = []

for iter in range(len(jitter)):
    landau.append(jitter[iter].Clone("landau_vs_y"))

    jitter[iter].Draw("hist")
    jitter[iter].SetMaximum(100)
    jitter[iter].SetLineColor(2)
    jitter[iter].SetStats(0)
    tr[iter].Draw("hist same")
    tr[iter].SetLineColor(4)
    tr[iter].SetStats(0)
    jitter[iter].GetXaxis().SetTitle("Track y position [mm]")
    jitter[iter].GetYaxis().SetTitle("Time resolution [ps]")

    for number in range(1, jitter[iter].GetXaxis().GetNbins()+1):
        j = jitter[iter].GetBinContent(number)
        t = tr[iter].GetBinContent(number)
        if (t>=j):
            l = math.sqrt(t*t - j*j)
        else:
            l = 0
        landau[iter].SetBinContent(number, l)

    landau[iter].Draw("hist same")
    landau[iter].SetLineColor(46)

    legend = TLegend(2*myStyle.GetMargin()+0.02,1-myStyle.GetMargin()-0.02-0.2,1-myStyle.GetMargin()-0.02,1-myStyle.GetMargin()-0.02)
    legend.SetNColumns(1)
    legend.SetTextFont(myStyle.GetFont())
    legend.SetTextSize(myStyle.GetSize())
    legend.SetBorderSize(0)
    legend.SetFillColor(kWhite)
    legend.AddEntry(jitter[iter], "Jitter component only")
    legend.AddEntry(tr[iter], "Total time resolution")
    legend.AddEntry(landau[iter], "TR - Jitter (quadrature)")
    legend.Draw()

    canvas.Update()
    canvas.SaveAs(outdir+"TR_and_Jitter_vs_y_"+region[iter]+".gif")

# Close the file
inputfile1.Close()
inputfile2.Close()
inputfile3.Close()
inputfile4.Close()