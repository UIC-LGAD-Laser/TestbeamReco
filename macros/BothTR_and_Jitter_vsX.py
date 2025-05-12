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
    inputfile = TFile("%s/Jitter/jitter_vs_x.root"%(outdir))
    inputfile2 = TFile("%s/TimeRes/timeDiffVsY.root"%(outdir))
else: 
    inputfile = TFile("../test/myoutputfile.root") 
    inputfile2 = TFile("../test/myoutputfile.root") 

colors = myStyle.GetColors(True)

sensor_Geometry = myStyle.GetGeometry(dataset)

sensor = sensor_Geometry['sensor']
pitch  = sensor_Geometry['pitch']

canvas = TCanvas("canvas", "TR and Jitter vs X", 1000, 800)

jitter = inputfile.Get("jitter_vs_x")
tr = inputfile2.Get("weighted2_time_diffTracker")
landau = jitter.Clone("landau_vs_x")

jitter.Draw("hist E")
jitter.SetMaximum(130)
jitter.SetLineColor(2)
jitter.SetStats(0)
tr.Draw("hist same E")
tr.SetLineColor(4)
tr.SetStats(0)
jitter.GetXaxis().SetTitle("Track x position [mm]")
jitter.GetYaxis().SetTitle("Time resolution [ps]")

for number in range(1, jitter.GetXaxis().GetNbins()+1):
    j = jitter.GetBinContent(number)
    j_error = jitter.GetBinError(number)
    x_position = jitter.GetXaxis().GetBinCenter(number)
    bin_number_tr = tr.FindBin(x_position)
    t = tr.GetBinContent(bin_number_tr)
    t_error = tr.GetBinError(bin_number_tr)
    # t = tr.GetBinContent(number);/
    if (t>j):
        l = math.sqrt(t*t - j*j)
        l_error = math.sqrt((t**2 * t_error**2 / l**2) + (j**2 * j_error**2 / l**2))
    else:
        l = 0
        l_error = 0
    landau.SetBinContent(number, l)
    landau.SetBinError(number,l_error)


landau.Draw("hist E same")
landau.SetLineColor(46)

legend = TLegend(2*myStyle.GetMargin()+0.02,1-myStyle.GetMargin()-0.02-0.2,1-myStyle.GetMargin()-0.02,1-myStyle.GetMargin()-0.02)
legend.SetNColumns(1)
legend.SetTextFont(myStyle.GetFont())
legend.SetTextSize(myStyle.GetSize())
legend.SetBorderSize(0)
legend.SetFillColor(kWhite)
legend.AddEntry(jitter, "Jitter component only")
legend.AddEntry(tr, "Total time resolution")
legend.AddEntry(landau, "TR - Jitter (quadrature)")
legend.Draw()

canvas.Update()
canvas.SaveAs(outdir+"TR_and_Jitter_vs_x.gif")

# Close the file
outputfile = TFile(outdir+"./AllTRs.root","RECREATE")
tr.Write()
jitter.Write()
landau.Write()
outputfile.Close()
inputfile.Close()
inputfile2.Close()