from ROOT import TFile,TTree,TCanvas,TH1F,TF1,TH2F,TLatex,TMath,TEfficiency,TGraphAsymmErrors,TLegend,gROOT,gStyle, kWhite, kRed, kBlue, kGreen, kMagenta, kCyan, kOrange, TGraph, TPaveText
import os
import EfficiencyUtils
import langaus
import optparse
import time
from stripBox import getStripBox
import myStyle

from array import array
myStyle.ForceStyle()

# Read the file and parse the data
data_tr = {}
data_amp = {}
data_amp_tr = {}
data_amp_tr['laser'] = []
data_amp_tr['ftbf'] = [57.34, 34.53]
with open("time_resolutions.txt", "r") as file:
    for line in file:
        if line.strip():
            parts = line.split(":")
            dataset = parts[0].strip()
            midgap_TR = float(parts[1].strip())
            midgap_amp = float(parts[2].strip())
            
            # Extract bias voltage and attenuation
            parts = dataset.split('_')
            bias_voltage = parts[4][:-1]
            attenuation_str = parts[-1].replace("attn", "")
            attenuation = float(attenuation_str.replace("P", "."))  # Convert to float
            
            if bias_voltage not in data_tr:
                data_tr[bias_voltage] = []
            data_tr[bias_voltage].append((attenuation, midgap_TR))
            if bias_voltage not in data_amp:
                data_amp[bias_voltage] = []
            data_amp[bias_voltage].append((attenuation, midgap_amp))

            data_amp_tr['laser'].append((midgap_amp, midgap_TR))

colors = [kRed, kBlue, kGreen, kMagenta, kCyan, kOrange]
plotAttnVsAmp=False
plotAttnVsTR=False
plotAmpVsTR=True

if(plotAttnVsAmp):
    canvas = TCanvas("c1", "Attenuation vs Amplitude", 1000, 800)
    # canvas.SetLeftMargin(0.15)
    legend = TLegend(0.6, 0.6, 0.9, 0.9)
    legend.SetHeader("Bias Voltage", "C")
    gStyle.SetGridStyle()
    gStyle.SetGridColor(921)  # Set grid line width
    canvas.SetGridy()
    graphs = []
    for i, (bias_voltage, points) in enumerate(data_amp.items()):
        points.sort()  # Sort points by attenuation
        x = array('d', [p[0] for p in points])
        y = array('d', [p[1] for p in points])
        
        graph = TGraph(len(x), x, y)
        myStyle.ForceStyle()

        graph.SetMarkerStyle(20)
        graph.SetMarkerColor(colors[i % len(colors)])
        graph.SetLineColor(colors[i % len(colors)])
        graph.SetLineWidth(2)
        graph.SetTitle(f"")
        if i == 0:
            graph.Draw("APL")
            graph.GetXaxis().SetTitle("Attenuation [%]")
            graph.GetYaxis().SetTitle("Mid-gap amplitude [mV]")
            graph.SetMinimum(35)  # Set the minimum value for the y-axis
            graph.SetMaximum(115)
            # graph.GetXaxis().SetTitleSize(0.05)
            # graph.GetYaxis().SetTitleSize(0.05)
            # graph.GetXaxis().SetLabelSize(0.04)
            # graph.GetYaxis().SetLabelSize(0.04)
            graph.GetYaxis().SetTitleOffset(1.2)
        else:
            graph.Draw("PL same")
        
        legend.AddEntry(graph, f"{bias_voltage}V", "PL")
        graphs.append(graph)
    # title = TPaveText(0.2, 0.91, 0.8, 1.0, "NDC")
    # title.AddText("Mid-gap amplitude vs attenuation")
    # title.AddText("for different operating voltages")
    # title.SetTextSize(0.04)  # Set the title font size
    # title.SetTextAlign(22)  # Center align
    # title.SetFillStyle(0)  # No fill color
    # title.Draw()
    legend.SetTextFont(myStyle.GetFont())
    legend.SetTextSize(myStyle.GetSize())
    legend.SetFillColor(kWhite)
    legend.SetFillStyle(4050)#
    legend.SetBorderSize(1)
    
    legend.Draw()
    canvas.SaveAs("../attenuation_vs_amplitude.pdf")

if(plotAttnVsTR):
    canvas2 = TCanvas("c2", "Attenuation vs Time Resolution", 1000, 800)
    legend = TLegend(0.2, 0.6, 0.5, 0.9)
    legend.SetHeader("Bias Voltage", "C")
    gStyle.SetGridStyle()
    gStyle.SetGridColor(921)  # Set grid line width
    canvas2.SetGridy()
    graphs = []
    for i, (bias_voltage, points) in enumerate(data_tr.items()):
        points.sort()  # Sort points by attenuation
        x = array('d', [p[0] for p in points])
        y = array('d', [p[1] for p in points])
        
        graph = TGraph(len(x), x, y)
        graph.SetMarkerStyle(20)
        graph.SetMarkerColor(colors[i % len(colors)])
        graph.SetLineColor(colors[i % len(colors)])
        graph.SetLineWidth(2)
        graph.SetTitle(f"")

        if i == 0:
            graph.Draw("APL")
            graph.GetXaxis().SetTitle("Attenuation [%]")
            graph.GetYaxis().SetTitle("Time Resolution [ps]")
            graph.SetMinimum(20)  # Set the minimum value for the y-axis
            graph.SetMaximum(36)
            # graph.GetXaxis().SetTitleSize(0.05)
            # graph.GetYaxis().SetTitleSize(0.05)
            # graph.GetXaxis().SetLabelSize(0.04)
            # graph.GetYaxis().SetLabelSize(0.04)
            graph.GetYaxis().SetTitleOffset(1.2)
        else:
            graph.Draw("PL same")
        
        legend.AddEntry(graph, f"{bias_voltage}V", "PL")
        graphs.append(graph)
    # title = TPaveText(0.2, 0.91, 0.8, 1.0, "NDC")
    # title.AddText("Mid-gap time resolution vs attenuation")
    # title.AddText("for different operating voltages")
    # title.SetTextSize(0.04)  # Set the title font size
    # title.SetTextAlign(22)  # Center align
    # title.SetFillStyle(0)  # No fill color
    # title.Draw()
    legend.SetTextFont(myStyle.GetFont())
    legend.SetTextSize(myStyle.GetSize())
    legend.SetFillColor(kWhite)
    legend.SetFillStyle(4050)#
    legend.SetBorderSize(1)
    legend.Draw()
    canvas2.SaveAs("../attenuation_vs_time_resolution.pdf")

if(plotAmpVsTR):
    canvas = TCanvas("c3", "Amplitude vs Time Resolution", 1000, 800)
    gStyle.SetGridStyle()
    gStyle.SetGridColor(921)  # Set grid line width
    canvas.SetGridy()

    legend = TLegend(0.45, 0.6, 0.94, 0.9)
    legend.SetHeader("Bias Voltage", "C")
    graphs = []

    for i, bias_voltage in enumerate(data_tr.keys()):
        if bias_voltage not in data_amp:
            continue  # Skip if no matching data in data_amp

        # Combine data_tr and data_amp for the same bias voltage
        tr_points = {att: tr for att, tr in data_tr[bias_voltage]}
        amp_points = {att: amp for att, amp in data_amp[bias_voltage]}
        combined_points = [
            (amp_points[att], tr_points[att]) for att in amp_points if att in tr_points
        ]

        if not combined_points:
            continue  # Skip if no matching attenuation points

        combined_points.sort()  # Sort by amplitude
        x = array('d', [p[0] for p in combined_points])  # Amplitude (midgap_amp)
        y = array('d', [p[1] for p in combined_points])  # Time Resolution (midgap_TR)

        graph = TGraph(len(x), x, y)
        graph.SetMarkerStyle(20 + i)
        graph.SetMarkerColor(colors[i % len(colors)])
        graph.SetLineColor(colors[i % len(colors)])
        graph.SetLineWidth(2)
        graph.SetTitle("")
        graph.GetXaxis().SetLimits(30, 115)
        graph.SetMinimum(20)

        # Fit the graph with 1/x + c
        fit_function = TF1(f"fit_{bias_voltage}", "[0]/x + [1]", 30, 115)
        fit_function.SetLineStyle(2)  # Set line style to dashed (dotted)
        fit_function.SetLineColor(colors[i % len(colors)])  # Match fit line color to graph
        graph.Fit(fit_function, "R")  # Perform the fit in the range [30, 115]

        # Extract fit parameters
        param0 = fit_function.GetParameter(0)  # Coefficient of 1/x
        param1 = fit_function.GetParameter(1)  # Constant term

        if i == 0:
            graph.Draw("APL")
            graph.GetXaxis().SetTitle("Mid-gap amplitude [mV]")
            graph.GetYaxis().SetTitle("Time Resolution [ps]")
            graph.GetYaxis().SetTitleOffset(1.2)
        else:
            graph.Draw("PL same")

        # Add fit parameters to the legend
        legend.AddEntry(graph, f"{bias_voltage}V (fit: {param0:.1f}/x + {param1:.1f})", "PL")
        graphs.append(graph)

    legend.SetTextFont(myStyle.GetFont())
    legend.SetTextSize(myStyle.GetSize()-6)
    legend.SetFillColor(kWhite)
    legend.SetFillStyle(4050)
    legend.SetBorderSize(1)
    legend.Draw()

    canvas.SaveAs("../amplitude_vs_time_resolution.pdf")

# if(plotAmpVsTR):

#     canvas = TCanvas("c3", "Amplitude vs Time Resolution", 1000, 800)
#     # canvas.SetBottomMargin(0.15)
#     # Extract data for laser
#     laser_data = data_amp_tr['laser']
#     laser_data.sort()  # Sort by the first element (amplitude) in each tuple
#     gStyle.SetGridStyle()
#     gStyle.SetGridColor(921)  # Set grid line width
#     canvas.SetGridy()
#     x_laser = array('d', [point[0] for point in laser_data])
#     y_laser = array('d', [point[1] for point in laser_data])

#     # Create a graph for laser data
#     graph_laser = TGraph(len(x_laser), x_laser, y_laser)
#     graph_laser.SetMarkerStyle(20)
#     graph_laser.SetMarkerColor(kBlue)
#     graph_laser.SetLineColor(kBlue)
#     graph_laser.SetLineWidth(2)
#     graph_laser.SetTitle("")
#     graph_laser.GetXaxis().SetTitle("Mid-gap amplitude [mV]")
#     graph_laser.GetYaxis().SetTitle("Time Resolution [ps]")
#     # graph_laser.GetXaxis().SetTitleSize(0.05)
#     # graph_laser.GetYaxis().SetTitleSize(0.05)
#     # graph_laser.GetXaxis().SetLabelSize(0.04)
#     # graph_laser.GetYaxis().SetLabelSize(0.04)
#     graph.GetYaxis().SetTitleOffset(1.2)
#     graph_laser.Draw("APL")

#     # Extract data for ftbf
#     ftbf_data = data_amp_tr['ftbf']
#     x_ftbf = array('d', [ftbf_data[0]])
#     y_ftbf = array('d', [ftbf_data[1]])

#     # # Create a graph for ftbf data
#     # graph_ftbf = TGraph(1, x_ftbf, y_ftbf)
#     # graph_ftbf.SetMarkerStyle(29)
#     # graph_ftbf.SetMarkerColor(kRed)
#     # graph_ftbf.SetMarkerSize(2.5)
#     # graph_ftbf.SetLineColor(kRed)
#     # graph_ftbf.SetLineWidth(2)
#     # graph_ftbf.Draw("P same")

#     # Create a legend
#     legend = TLegend(0.5, 0.6, 0.8, 0.8)
#     legend.AddEntry(graph_laser, "Laser source", "PL")
#     # legend.AddEntry(graph_ftbf, "MIP source", "P")
#     legend.SetTextFont(myStyle.GetFont())
#     legend.SetTextSize(myStyle.GetSize())
#     legend.SetFillColor(kWhite)
#     legend.SetFillStyle(4050)#
#     legend.SetBorderSize(1)
#     legend.Draw()
#     # title = TPaveText(0.2, 0.91, 0.8, 1.0, "NDC")
#     # title.AddText("Mid-gap amplitude vs time resolution")
#     # title.SetTextSize(0.04)  # Set the title font size
#     # title.SetTextAlign(22)  # Center align
#     # title.SetFillStyle(0)  # No fill color
#     # title.Draw()

#     # Save the canvas
#     canvas.SaveAs("../amplitude_vs_time_resolution.pdf")