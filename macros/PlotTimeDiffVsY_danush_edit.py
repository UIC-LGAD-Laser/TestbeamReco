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
        th1_temp = TH1D(name,"",th2.GetXaxis().GetNbins(),th2.GetXaxis().GetXmin()+0.013,th2.GetXaxis().GetXmax()+0.013)
        return th1_temp
    

# Construct the argument parser
parser = optparse.OptionParser("usage: %prog [options]\n")
parser.add_option('-x','--xlength', dest='xlength', default = 4.0, help="Limit x-axis in final plot")
parser.add_option('-y','--ylength', dest='ylength', default = 200.0, help="Max TimeResolution value in final plot")
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

outdir = myStyle.GetPlotsDir(outdir, "TimeRes/")

sensor_Geometry = myStyle.GetGeometry(dataset)

sensor = sensor_Geometry['sensor']
pitch  = sensor_Geometry['pitch']
xlength = float(options.xlength)
ylength = float(options.ylength)
debugMode = options.debugMode

all_histoInfos = []
th1_hists = []

all_histoInfos.append(inputfile.Get("timeDiff_vs_xy"))
all_histoInfos.append(inputfile.Get("timeDiffTracker_vs_xy"))
all_histoInfos.append(inputfile.Get("weighted2_timeDiff_tracker_vs_xy"))

th1_hists.append(TH1D("timeDiff","",all_histoInfos[0].GetXaxis().GetNbins(),all_histoInfos[0].GetXaxis().GetXmin()+0.013,all_histoInfos[0].GetXaxis().GetXmax()+0.013))
th1_hists.append(TH1D("timeDiffTracker","",all_histoInfos[1].GetXaxis().GetNbins(),all_histoInfos[1].GetXaxis().GetXmin()+0.013,all_histoInfos[1].GetXaxis().GetXmax()+0.013))
th1_hists.append(TH1D("weighted2_timeDiff_tracker","",all_histoInfos[2].GetXaxis().GetNbins(),all_histoInfos[2].GetXaxis().GetXmin()+0.013,all_histoInfos[2].GetXaxis().GetXmax()+0.013))


names = ["timeDiff_vs_xy", "timeDiffTracker_vs_xy", "weighted2_timeDiff_tracker_vs_xy"]


# all_histoInfos = [HistoInfo("timeDiff_vs_xy", inputfile, "time_diff"), HistoInfo("timeDiffTracker_vs_xy", inputfile, "time_diffTracker"), HistoInfo("weighted2_timeDiff_tracker_vs_xy", inputfile, "weighted2_time_diffTracker")]

canvas = TCanvas("cv","cv",1000,800)
# gPad.SetLeftMargin(0.12)
# gPad.SetRightMargin(0.15)
# gPad.SetTopMargin(0.08)
# gPad.SetBottomMargin(0.12)
# gPad.SetTicks(1,1)
#gPad.SetLogy()
canvas.SetGrid(0,1)
TH1.SetDefaultSumw2()
gStyle.SetOptStat(0)
print("Finished setting up langaus fit class")

if debugMode:
    outdir_q = myStyle.CreateFolder(outdir, "q_resTimeY0/")

nXBins = all_histoInfos[0].GetXaxis().GetNbins()

#loop over X bins
for iter in range(len(all_histoInfos)):
    for i in range(1, nXBins+1):
        totalEvents = all_histoInfos[iter].GetEntries()
        tmpHist = all_histoInfos[iter].ProjectionY("py",i,i)
        myRMS = tmpHist.GetRMS()
        myMean = tmpHist.GetMean()
        nEvents = tmpHist.GetEntries()
        fitlow = myMean - 1.5*myRMS
        fithigh = myMean + 1.5*myRMS
        value = myRMS
        error = 0.0
        valueMean = myMean
        errorMean = 0.0
        minEvtsCut = 0.25*totalEvents/nXBins
        #Do fit 
        if(nEvents > minEvtsCut):
            fit = TF1('fit','gaus',fitlow,fithigh)
            tmpHist.Fit(fit,"Q", "", fitlow, fithigh)
            myFitMean = fit.GetParameter(1)
            myFitMeanError = fit.GetParError(1)
            mySigma = fit.GetParameter(2)
            mySigmaError = fit.GetParError(2)
            value = 1000.0*mySigma
            error = 1000.0*mySigmaError
            valueMean = abs(1000.0*myFitMean)
            errorMean = 1000.0*myFitMeanError
            if (debugMode):
                tmpHist.Draw("hist")
                fit.Draw("same")
                canvas.SaveAs(outdir_q+"q_"+names[iter]+str(i)+".gif")
                print ("Bin : " + str(i) + " (x = %.3f"%(all_histoInfos[iter].th1.GetXaxis().GetBinCenter(i)) +") -> Resolution: %.3f +/- %.3f"%(value, error))
        else:
            value = 0.0
            valueMean = 0.0

        # Removing telescope contribution
        #if value!=0.0:
            #error = error*value/TMath.Sqrt(value*value - 9*9)
            #value = TMath.Sqrt(value*value - 9*9)
            #value = TMath.Sqrt(value*value - 9*9)

        th1_hists[iter].SetBinContent(i,value)
        th1_hists[iter].SetBinError(i,error)
        # th1_hists[iter]Mean.SetBinContent(i,valueMean)
        # th1_hists[iter]Mean.SetBinError(i,errorMean)
                        
# Plot 2D histograms
outputfile = TFile(outdir+"timeDiffVsY.root","RECREATE")
for iter in range(len(all_histoInfos)):
    th1_hists[iter].Draw("hist e")
    th1_hists[iter].SetStats(0)
    # th1_hists[iter].GetXaxis().SetTitle(info.xlabel)
    # th1_hists[iter].GetYaxis().SetTitle(info.ylabel)
    th1_hists[iter].SetMinimum(0.0001)
    th1_hists[iter].SetMaximum(ylength)
    th1_hists[iter].SetLineColor(kBlack)
    th1_hists[iter].GetXaxis().SetTitle("Track y position [mm]")
    th1_hists[iter].GetXaxis().SetRangeUser(-xlength,xlength)
    th1_hists[iter].GetYaxis().SetTitle("Time resolution [ps]")

    ymin = th1_hists[iter].GetMinimum()
    ymax = ylength
    
    gPad.RedrawAxis("g")

    th1_hists[iter].Draw("AXIS same")
    th1_hists[iter].Draw("hist e same")

    # myStyle.BeamInfo()
    myStyle.SensorInfoSmart(dataset)

    canvas.SaveAs(outdir+"TimeRes_vs_y_"+names[iter][:-6]+".gif")
    canvas.SaveAs(outdir+"TimeRes_vs_y_"+names[iter][:-6]+".pdf")
    th1_hists[iter].Write()


hTimeRes = th1_hists[0] # 6
hTimeResCorr = th1_hists[1]
hTimeResW2 = th1_hists[2] #7
hTimeRes.SetLineColor(28)
hTimeResCorr.SetLineColor(kBlack)
hTimeResW2.SetLineColor(416+2) #kGreen+2 #(TColor.GetColor(136,34,85))

#hTimeRes.Draw("hist e")

ymin = hTimeRes.GetMinimum()
ymax = ylength

gPad.RedrawAxis("g")

hTimeRes.Draw("hist e")#
hTimeRes.Draw("AXIS same")
hTimeResCorr.Draw("hist e same")#
hTimeResW2.Draw("hist e same")

legend = TLegend(myStyle.GetPadCenter()-0.4,0.70,myStyle.GetPadCenter()+0.4,0.90)
legend.SetFillColor(kWhite)
legend.SetFillStyle(4050)#
legend.AddEntry(hTimeRes, "Single-channel (w/o TrackerCorrection)")#
legend.AddEntry(hTimeResCorr, "Single-channel (w/ TrackerCorrection)")#
legend.AddEntry(hTimeResW2, "Multi-channel (w/ TrackerCorrection)")
legend.Draw();

# myStyle.BeamInfo()
#myStyle.SensorInfoSmart(dataset)

canvas.SaveAs(outdir+"TimeRes_vs_y_BothMethods.gif")
canvas.SaveAs(outdir+"TimeRes_vs_y_BothMethods.pdf")

outputfile.Close()
