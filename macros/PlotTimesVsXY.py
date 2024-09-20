from ROOT import TFile,TTree,TCanvas,TH1F,TH2F,TLatex,TMath,TEfficiency,TGraphAsymmErrors,gROOT,gPad,TF1,gStyle,kBlack
import os
import optparse
import myStyle


organized_mode=True

gROOT.SetBatch( True )
gStyle.SetOptFit(1011)

class HistoInfo:
    def __init__(self, inHistoName, f, outHistoName):
        self.inHistoName = inHistoName
        self.f = f
        self.outHistoName = outHistoName
        self.th3 = self.getTH3(f, inHistoName)
        self.th2 = self.getTH2(self.th3, outHistoName)
    def getTH3(self, f, name):
        return f.Get(name)        

    def getTH2(self, th3, name):
        return th3.Project3D("yx").Clone(name)


parser = optparse.OptionParser("usage: %prog [options]\n")
parser.add_option('-D', dest='Dataset', default = "", help="Dataset, which determines filepath")
parser.add_option('-z','--zmin', dest='zmin', default = 11.10, help="Set min Time value in final plot")
parser.add_option('-Z','--zmax', dest='zmax', default = 11.30, help="Set max Time value in final plot")
parser.add_option('-d', dest='debugMode', action='store_true', default = False, help="Run debug mode")

options, args = parser.parse_args()
dataset = options.Dataset
zmin = float(options.zmin)
zmax = float(options.zmax)
debugMode = options.debugMode

outdir=""
if organized_mode: 
    outdir = myStyle.getOutputDir(dataset)
    inputfile = TFile("%s%s_Analyze.root"%(outdir,dataset))
else: 
    inputfile = TFile("../test/myoutputfile.root")

outdir = myStyle.GetPlotsDir(outdir, "Times/")

all_histoInfos = [
    HistoInfo("weighted2_time_tracker_vs_xy", inputfile, "weighted2_time_tracker"),
    HistoInfo("photektime_vs_xy", inputfile, "photektime")
]

canvas = TCanvas("cv","cv",800,800)
gPad.SetLeftMargin(0.12)
gPad.SetRightMargin(0.15)
gPad.SetTopMargin(0.08)
gPad.SetBottomMargin(0.12)
gPad.SetTicks(1,1)


if debugMode:
    outdir_q = myStyle.CreateFolder(outdir, "q_resTimeXY0/")

# all_histoInfos[0].th2.Rebin(2)
# all_histoInfos[1].th2.Rebin(2)
nXBins = all_histoInfos[0].th2.GetXaxis().GetNbins()
nYBins = all_histoInfos[0].th2.GetYaxis().GetNbins()

#loop over X bins
for info in all_histoInfos:
    totalEvents = info.th2.GetEntries()
    for i in range(1, nXBins+1):
        for j in range(1, nYBins+1):
            tmpHist = info.th3.ProjectionZ("pz",i,i,j,j)
            myMean = tmpHist.GetMean()
            myRMS = tmpHist.GetRMS()
            nEvents = tmpHist.GetEntries()
            value = myMean
            error = 0.0

            #Do fit 
            minEvtsCut = 0
            if(nEvents > minEvtsCut):                
                if (debugMode):
                    tmpHist.Draw("hist")
                    canvas.SaveAs(outdir_q+"q_"+info.outHistoName+str(i)+str(j)+".gif")
            else:
                value = -100.0            
                
            info.th2.SetBinContent(i,j,value)
                

# Plot 2D histograms
outputfile = TFile("%splotsTimesVsXY.root"%outdir,"RECREATE")
for info in all_histoInfos:
    info.th2.Draw("colz")
    info.th2.SetStats(0)
    info.th2.SetTitle(info.outHistoName)
    info.th2.SetMinimum(zmin)
    info.th2.SetMaximum(zmax)
    info.th2.SetLineColor(kBlack)

    canvas.SaveAs(outdir+"Times_vs_xy_"+info.outHistoName+".gif")
    canvas.SaveAs(outdir+"Times_vs_xy_"+info.outHistoName+".pdf")
    info.th2.Write()

outputfile.Close()