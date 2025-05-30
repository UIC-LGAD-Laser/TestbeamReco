from ROOT import TFile,TTree,TCanvas,TH1F,TF1,TH2F,TLatex,TMath,TEfficiency,TGraphAsymmErrors,TLegend,gROOT,gStyle, kWhite
import os
import EfficiencyUtils
import langaus
import optparse
import time
from stripBox import getStripBox
import myStyle

def Make1DEfficiencyHist(num, den, plotname, topTitle="", xAxisTitle="", xAxisRangeLow=0, xAxisRangeHigh=0, shift=0.0, center=0):
    nbins = num.GetXaxis().GetNbins()
    # xmin, xmax = mf.get_shifted_limits(num, center)
    # this_hist = TH1F("h%s"%plotname, topTitle, nbins, xmin, xmax)
    this_hist = num.Clone("h%s"%plotname)

    for b in range(1,nbins+1):
        xtemp = num.GetXaxis().GetBinCenter(b)
        ratio = 0

        n1 = int(num.GetBinContent(b))
        n2 = int(den.GetBinContent(b))
        #print ("numerator: " + str(n1) + " and denominator: " + str(n2))
        if (n1 > n2):
            n1 = n2
            # Define warning if bin gets numerator > denominator
            warn_msg = "WARNING! Bin got numerator higher than denominator"
            print("%s (bin %i)"%(warn_msg, b))

        if (n2>0):
            ratio = float(n1)/float(n2)
            if (ratio > 1):
                ratio = 1
                # Define warning if bin gets efficicency higher than 1
                warn_msg = "WARNING! Bin got efficiency higher than unit"
                print("%s (bin %i)"%(warn_msg, b))
        this_bin = num.GetXaxis().FindBin(xtemp)

        this_hist.SetBinContent(this_bin, ratio)

    return this_hist

gROOT.SetBatch( True )
gStyle.SetOptFit(1011)

## Defining Style
myStyle.ForceStyle()
# gStyle.SetTitleYOffset(1.1)
organized_mode=True

# Construct the argument parser
parser = optparse.OptionParser("usage: %prog [options]\n")
parser.add_option('-x','--xlength', dest='xlength', default = 0.8, help="Limit x-axis in final plot")
parser.add_option('-y','--ylength', dest='ylength', default = 1.5, help="Max eff value in final plot")
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

outdirTmp = myStyle.GetPlotsDir(outdir, "Efficiency/")

list_name_coarse = []
list_legend_overall = ["One or more channels reconstruction", "Exactly one channel reconstruction", "Two channels reconstruction"]
for reco in ["denominator", "numerator", "oneStrip_numerator", "twoStrip_numerator"]:
    hname = "efficiency_vs_xy_%s_coarseBins"%(reco)
    # if (is_tight):
    #     hname+= "_tight"
    list_name_coarse.append(hname)

hname_denominator = list_name_coarse.pop(0)
th1_coarse_eff_denominator = inputfile.Get(hname_denominator).ProjectionX()

# shift = -0.25#inputfile.Get("stripBoxInfo03").GetMean(1)

# Save amplitude histograms
outputfile = TFile("%sPlotEfficiencyVsX.root"%(outdirTmp),"RECREATE")

canvas = TCanvas("cv","cv",1000,800)

efficiency_vs_x = TH1F("htemp","",1,-xlength,xlength)
efficiency_vs_x.Draw("hist")
efficiency_vs_x.SetStats(0)
efficiency_vs_x.SetTitle("")
efficiency_vs_x.GetXaxis().SetTitle("Track x position [mm]")
efficiency_vs_x.GetYaxis().SetTitle("Efficiency")
efficiency_vs_x.SetLineWidth(2)
efficiency_vs_x.SetMaximum(ylength)

legend = TLegend(2*myStyle.GetMargin()+0.02,1-myStyle.GetMargin()-0.02-0.2,1-myStyle.GetMargin()-0.02,1-myStyle.GetMargin()-0.02)
# legend.SetNColumns(3)
legend.SetTextFont(myStyle.GetFont())
legend.SetTextSize(myStyle.GetSize())
legend.SetBorderSize(0)
legend.SetFillColor(kWhite)

list_th1 = []
for i, in_name in enumerate(list_name_coarse):
    new_hname = in_name.replace("_xy_", "_x_")
    projX_efficiency = inputfile.Get(in_name).ProjectionX()
    th1_efficiency = Make1DEfficiencyHist(projX_efficiency, th1_coarse_eff_denominator, new_hname, center=0)
    th1_efficiency.SetLineWidth(3)
    th1_efficiency.SetLineColor(colors[i])
    th1_efficiency.Draw("hist same")
    th1_efficiency.Write()
    list_th1.append(th1_efficiency)
    legend.AddEntry(th1_efficiency, list_legend_overall[i])

efficiency_vs_x.Draw("AXIS same")
legend.Draw()

# myStyle.BeamInfo()
myStyle.SensorInfoSmart(dataset)

save_path = "%sEfficiencyCoarse"%(outdirTmp)
# if (is_tight):
#     save_path+= "_tight"
# canvas.SaveAs("%s.gif"%(save_path))
canvas.SaveAs("%s.pdf"%(save_path))

outputfile.Close()