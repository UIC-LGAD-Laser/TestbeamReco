from ROOT import TFile,TTree,TCanvas,TH1D,TH1F,TH2F,TLatex,TMath,TColor,TLegend,TEfficiency,TGraphAsymmErrors,gROOT,gPad,TF1,gStyle,kBlack,kRed,kWhite,TH1
import os
import optparse
import myStyle

gROOT.SetBatch( True )
gStyle.SetOptFit(1011)

## Defining Style
myStyle.ForceStyle()
organized_mode=True

class HistoInfo:
    def __init__(self, inHistoName, f, outHistoName, xlabel="Tracker Position [mm]", ylabel="Time resolution [ps]"):
        self.inHistoName = inHistoName
        self.f = f
        self.outHistoName = outHistoName
        self.xlabel = xlabel
        self.ylabel = ylabel
        self.th2 = self.getTH2(f, inHistoName)
        self.th1 = self.getTH1(self.th2, outHistoName)
        # self.th1Mean = self.getTH1(self.th2, outHistoName)

    def getTH2(self, f, name, axis='zx'):
        th3 = f.Get(name)
        th2 = th3.Project3D(axis)
        # th2.RebinX(2)
        return th2

    def getTH1(self, th2, name):
        th1_temp = TH1D(name,"",th2.GetXaxis().GetNbins(),th2.GetXaxis().GetXmin(),th2.GetXaxis().GetXmax())
        return th1_temp
    

# Construct the argument parser
parser = optparse.OptionParser("usage: %prog [options]\n")
parser.add_option('-x','--xlength', dest='xlength', default = 1.0, help="Limit x-axis in final plot")
parser.add_option('-y','--ylength', dest='ylength', default = 12.0, help="Max TimeResolution value in final plot")
parser.add_option('-D', dest='Dataset', default = "", help="Dataset, which determines filepath")
parser.add_option('-d', dest='debugMode', action='store_true', default = False, help="Run debug mode")
options, args = parser.parse_args()

dataset = options.Dataset
outdir=""
if organized_mode: 
    outdir = myStyle.getOutputDir(dataset)
    inputfile = TFile("%s%s_Analyze.root"%(outdir,dataset))
else:
    inputfile = TFile("../test/myoutputfile.root")

outdir = myStyle.GetPlotsDir(outdir, "Times/")

sensor_Geometry = myStyle.GetGeometry(dataset)

sensor = sensor_Geometry['sensor']
pitch  = sensor_Geometry['pitch']
xlength = float(options.xlength)
ylength = float(options.ylength)
debugMode = options.debugMode

all_histoInfos = [
    HistoInfo("weighted2_time_tracker_vs_xy", inputfile, "weighted2_time_tracker"),
    HistoInfo("photektime_vs_xy", inputfile, "photektime")
]
canvas = TCanvas("cv","cv",1000,800)
canvas.SetGrid(0,1)
TH1.SetDefaultSumw2()
gStyle.SetOptStat(0)
print("Finished setting up langaus fit class")

if debugMode:
    outdir_q = myStyle.CreateFolder(outdir, "TimesX0/")

nXBins = all_histoInfos[0].th2.GetXaxis().GetNbins()

#loop over X bins
for i in range(1, nXBins+1):
    for info in all_histoInfos:
        totalEvents = info.th2.GetEntries()
        tmpHist = info.th2.ProjectionY("py",i,i)
        myRMS = tmpHist.GetRMS()
        myMean = tmpHist.GetMean()
        nEvents = tmpHist.GetEntries()
        fitlow = myMean - 1.5*myRMS
        fithigh = myMean + 1.5*myRMS
        value = myMean
        error = myRMS
        valueMean = myMean
        errorMean = myRMS
        info.th1.SetBinContent(i,value)
        info.th1.SetBinError(i,error)
        if (debugMode):
            tmpHist.Draw("hist")
            canvas.SaveAs(outdir_q+"q_"+info.outHistoName+str(i)+".gif")
            print ("Bin : " + str(i) + " (x = %.3f"%(info.th1.GetXaxis().GetBinCenter(i)) +") -> Resolution: %.3f +/- %.3f"%(value, error))
                        
# Plot 2D histograms
outputfile = TFile(outdir+"timesVsX.root","RECREATE")
for info in all_histoInfos:
    info.th1.Draw("hist e")
    info.th1.SetStats(0)
    info.th1.SetMinimum(10)
    info.th1.SetMaximum(ylength)
    info.th1.SetLineColor(kBlack)
    info.th1.GetXaxis().SetTitle("Track X position [mm]")
    info.th1.GetXaxis().SetRangeUser(-xlength,xlength)
    info.th1.GetYaxis().SetTitle("Trigger time [ps]")

    ymin = info.th1.GetMinimum()
    ymax = ylength
    gPad.RedrawAxis("g")

    info.th1.Draw("AXIS same")
    info.th1.Draw("hist e same")

    # myStyle.BeamInfo()
    myStyle.SensorInfoSmart(dataset)

    canvas.SaveAs(outdir+"Times_vs_x_"+info.outHistoName+".gif")
    canvas.SaveAs(outdir+"Times_vs_x_"+info.outHistoName+".pdf")
    info.th1.Write()

outputfile.Close()
