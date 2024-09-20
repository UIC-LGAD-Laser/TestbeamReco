from ROOT import TFile,TTree,TCanvas,TH1F,TH2F,TLatex,TMath,TEfficiency,TGraphAsymmErrors,gROOT,gPad,TF1,gStyle,kBlack,TH1
import ROOT
import optparse
import os
import myStyle

gROOT.SetBatch( True )
gStyle.SetOptFit(1011)

## Defining Style
myStyle.ForceStyle()

class HistoInfo:
    def __init__(self, inHistoName, f, outHistoName, color=ROOT.kBlack):
        self.inHistoName = inHistoName
        self.f = f
        self.outHistoName = outHistoName
        self.th1 = self.getTH1(f, inHistoName)
        self.th1.SetLineColor(color)

    def getTH1(self, f, name):
        th1 = f.Get(name)
        return th1

# Construct the argument parser
parser = optparse.OptionParser("usage: %prog [options]\n")
parser.add_option('-D', dest='Dataset', default = "", help="Dataset, which determines filepath")

options, args = parser.parse_args()

dataset = options.Dataset
outdir=""
outdir = myStyle.getOutputDir(dataset)
inputfile = TFile("%s%s_Analyze.root"%(outdir,dataset))

options, args = parser.parse_args()

colors = myStyle.GetColors()

all_histoInfos = [
    HistoInfo("waveProf3nearStripX", inputfile, "Near strip", colors[0]),
    HistoInfo("waveProf3leftMostGapX", inputfile, "LeftMost midgap", colors[1]),
    HistoInfo("waveProf3rightMostGapX", inputfile, "RightMost midgap", colors[2]),
    # HistoInfo("waveProf3centerStripX", inputfile, "Strip 4", colors[1]),
    # HistoInfo("waveProf6leftStripX", inputfile, "Strip 7", colors[2]),
    # HistoInfo("waveProf3centerStripX", inputfile, "Strip 4", colors[1]),
]

canvas = TCanvas("cv","cv",1000,800)
gPad.SetTicks(1,1)
legend = ROOT.TLegend(2*myStyle.GetMargin()+0.05,2*myStyle.GetMargin()+0.05,2*myStyle.GetMargin()+0.05+0.2,2*myStyle.GetMargin()+0.05+0.2)

all_histoInfos[0].th1.Draw("l")
# all_histoInfos[0].th1.SetMinimum(-3000)
# all_histoInfos[0].th1.SetMaximum(0)
for info in all_histoInfos:
    info.th1.Draw("l same")
    info.th1.SetLineWidth(2)
    legend.AddEntry(info.th1, info.outHistoName,"l")
legend.Draw()

# myStyle.BeamInfo()
myStyle.SensorInfo(dataset)

canvas.SaveAs(outdir+"Waveforms-Trigger.png")

# outputfile.Close()

