from ROOT import TFile,TTree,TCanvas,TH1F,TF1,TH2F,TLatex,TMath,TEfficiency,TGraphAsymmErrors,TLegend,gROOT,gStyle, kWhite, kRed, kBlue, kGreen, kMagenta, kCyan, kOrange, TGraph,TGraphErrors, TPaveText
import os
import EfficiencyUtils
import langaus
import optparse
import time
from stripBox import getStripBox
import myStyle
import numpy as np
from array import array
myStyle.ForceStyle()

# Read the file and parse the data
data_tr = {}
data_amp = {}
data_amp_tr = {}
data_risetime = {}
data_noise = {}
data_slewrate = {}
data_jitter = {}
data_landau = {}
data_risetime_tr = {}
data_noise_tr = {}
data_slewrate_tr = {}
data_jitter_tr = {}
data_landau_tr = {}

data_amp_tr['laser'] = []
data_amp_tr['ftbf'] = [57.34, 34.53]
data_risetime_tr['laser'] = []
data_noise_tr['laser'] = []
data_slewrate_tr['laser'] = []
data_jitter_tr['laser'] = []
data_landau_tr['laser'] = []

with open("time_resolutions_paper.txt", "r") as file:
    for line in file:
        if line.strip():
            parts = line.split(":")
            dataset = parts[0].strip()
            values = parts[1].split(",")
            midgap1_TR = float(values[0].strip())
            midgap1_TR_error = float(values[1].strip())
            midgap2_TR = float(values[2].strip())
            midgap2_TR_error = float(values[3].strip())
            midgap_amp = float(parts[2].split(",")[0].strip())
            midgap_amp_error = float(parts[2].split(",")[1].strip())
            midgap1_risetime = float(parts[3].split(",")[0].strip())
            midgap1_risetime_error = float(parts[3].split(",")[1].strip())
            midgap1_noise = float(parts[4].split(",")[0].strip())
            midgap1_noise_error = float(parts[4].split(",")[1].strip())
            midgap1_jitter = float(parts[5].split(",")[0].strip())
            midgap1_jitter_error = float(parts[5].split(",")[1].strip())
            midgap1_slewrate = float(parts[6].split(",")[0].strip())
            midgap1_slewrate_error = float(parts[6].split(",")[1].strip())
            midgap1_landau = np.sqrt(midgap1_TR**2 - midgap1_jitter**2)
            midgap1_landau_error = np.sqrt( ((midgap1_TR / np.sqrt(midgap1_TR**2 - midgap1_jitter**2)) * midgap1_TR_error)**2 + ((-midgap1_jitter / np.sqrt(midgap1_TR**2 - midgap1_jitter**2)) * midgap1_jitter_error)**2
    )
            
            dataset_parts = dataset.split('_')
            bias_voltage = dataset_parts[4][:-1]
            attenuation_str = dataset_parts[-1].replace("attn", "")
            attenuation = float(attenuation_str.replace("P", "."))  # Convert to float
            
            # Save data for TR
            if bias_voltage not in data_tr:
                data_tr[bias_voltage] = []
            data_tr[bias_voltage].append((attenuation, midgap1_TR, midgap1_TR_error))
            
            # Save data for amplitude
            if bias_voltage not in data_amp:
                data_amp[bias_voltage] = []
            data_amp[bias_voltage].append((attenuation, midgap_amp, midgap_amp_error))
            
            # Save amplitude vs TR data
            data_amp_tr['laser'].append((midgap_amp, midgap_amp_error, midgap1_TR, midgap1_TR_error))
            
            # Save risetime data
            if bias_voltage not in data_risetime:
                data_risetime[bias_voltage] = []
            data_risetime[bias_voltage].append((attenuation, midgap1_risetime, midgap1_risetime_error))
            
            # Save risetime vs TR data
            data_risetime_tr['laser'].append((midgap1_risetime, midgap1_risetime_error, midgap1_TR, midgap1_TR_error))
            
            # Save noise data
            if bias_voltage not in data_noise:
                data_noise[bias_voltage] = []
            data_noise[bias_voltage].append((attenuation, midgap1_noise, midgap1_noise_error))
            
            # Save noise vs TR data
            data_noise_tr['laser'].append((midgap1_noise, midgap1_noise_error, midgap1_TR, midgap1_TR_error))

            # Save jitter and landau data
            if bias_voltage not in data_jitter:
                data_jitter[bias_voltage] = []
            data_jitter[bias_voltage].append((attenuation, midgap1_jitter, midgap1_jitter_error))
            if bias_voltage not in data_landau:
                data_landau[bias_voltage] = []
            data_landau[bias_voltage].append((attenuation, midgap1_landau, midgap1_landau_error))
            
            # Save jitter and landau vs TR data
            data_jitter_tr['laser'].append((midgap1_jitter, midgap1_jitter_error, midgap1_TR, midgap1_TR_error))
            data_landau_tr['laser'].append((midgap1_landau, midgap1_landau_error, midgap1_TR, midgap1_TR_error))

            # Save slewrate data
            if bias_voltage not in data_slewrate:
                data_slewrate[bias_voltage] = []
            data_slewrate[bias_voltage].append((attenuation, midgap1_slewrate, midgap1_slewrate_error))
            
            # Save slewrate vs TR data
            data_slewrate_tr['laser'].append((midgap1_slewrate, midgap1_slewrate_error, midgap1_TR, midgap1_TR_error))

colors = [kRed, kBlue, kGreen, kMagenta, kCyan, kOrange]
plotAttnVsAmp=True
plotAttnVsTR=True
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
        x_err = array('d', [0] * len(x))  # Assuming no x-errors
        y = array('d', [p[1] for p in points])
        y_err = array('d', [p[2] for p in points])
        
        graph = TGraphErrors(len(x), x, y, x_err, y_err)
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
    myStyle.SensorInfo(sensor="Sensor: S3")
    canvas.SaveAs("../attenuation_vs_amplitude_withErrBars.pdf")

if(plotAttnVsTR):
    canvas2 = TCanvas("c2", "Attenuation vs Qty", 1000, 800)
    # legend = TLegend(0.2, 0.6, 0.5, 0.9)
    # legend.SetHeader("Bias Voltage", "C")
    gStyle.SetGridStyle()
    gStyle.SetGridColor(921)  # Set grid line width
    canvas2.SetGridy()
    graphs = []

    quantities = [
        ("Time Resolution", data_tr, data_amp, "../attenuation_vs_time_resolution_withErrBars.pdf", 20, 40, 'ps', [0.35, 0.6, 0.64, 0.9]),
        ("Noise", data_noise, data_amp, "../attenuation_vs_noise_withErrBars.pdf", 1.5, 2.0, 'mV', [0.45, 0.2, 0.74, 0.5]),
        ("Risetime", data_risetime, data_amp, "../attenuation_vs_risetime_withErrBars.pdf", 700, 800, 'ps', [0.45, 0.2, 0.74, 0.5]),
        ("Jitter", data_jitter, data_amp, "../attenuation_vs_jitter_withErrBars.pdf", 10, 30, 'ps', [0.15, 0.6, 0.44, 0.9]),
        ("Landau", data_landau, data_amp, "../attenuation_vs_landau_withErrBars.pdf", 10, 30, 'ps', [0.15, 0.6, 0.60, 0.9]),
        ("Slewrate", data_slewrate, data_amp, "../attenuation_vs_slewrate_withErrBars.pdf", 30, 120, 'mV/ps', [0.55, 0.6, 0.84, 0.9]),
    ]


    for qty_name, qty_data, amp_data, output_file, y_min, y_max, units, legendLimits in quantities:
        # legend.Clear()
        graphs.clear()
        # y_offset = 0.0 if "Resolution" in qty_name or "Jitter" in qty_name or "Landau" in qty_name or "Slewrate" in qty_name else -0.4
        legend = TLegend(legendLimits[0], legendLimits[1], legendLimits[2], legendLimits[3])
        legend.SetHeader("Bias Voltage", "C")

        all_landau_x = []
        all_landau_y = []
        all_landau_x_err = []
        all_landau_y_err = []
        for i, (bias_voltage, points) in enumerate(qty_data.items()):
            points.sort()  # Sort points by attenuation
            x = array('d', [p[0] for p in points])
            x_err = array('d', [0] * len(x))  # Assuming no x-errors
            y = array('d', [p[1] for p in points])
            y_err = array('d', [p[2] for p in points])
            
            graph = TGraphErrors(len(x), x, y, x_err, y_err)
            graph.SetMarkerStyle(20)
            graph.SetMarkerColor(colors[i % len(colors)])
            graph.SetLineColor(colors[i % len(colors)])
            graph.SetLineWidth(2)
            graph.SetTitle(f"")
            graph.GetXaxis().SetLimits(91, 95)
            graph.SetMinimum(y_min)
            graph.SetMaximum(y_max)
            
            if "Landau" in qty_name:  # Fit with a linear equation if "Landau" is in qty_name
                fit_function = TF1(f"fit_{bias_voltage}", "[0]*x + [1]", 91, 95)
                fit_function.SetLineStyle(2)
                fit_function.SetLineColor(colors[i % len(colors)])
                graph.Fit(fit_function, "R")
                param0 = fit_function.GetParameter(0)
                param1 = fit_function.GetParameter(1)
                legend.AddEntry(graph, f"{bias_voltage}V (fit: {param0:.2f}*x {param1:.1f})", "PL")
                all_landau_x.extend(x)
                all_landau_y.extend(y)
                all_landau_x_err.extend(x_err)
                all_landau_y_err.extend(y_err)
            else:
                legend.AddEntry(graph, f"{bias_voltage}V", "PL")
            graphs.append(graph)
            if i == 0:
                graph.Draw("APL")
                graph.GetXaxis().SetTitle("Attenuation [%]")
                graph.GetYaxis().SetTitle(f"{qty_name} [{units}]")
                graph.GetYaxis().SetTitleOffset(1.2)
            else:
                graph.Draw("PL same")
        if "Landau" in qty_name:
            global_fit_function = TF1("global_fit", "[0]*x + [1]", 91, 95)
            global_graph = TGraphErrors(len(all_landau_x), array('d',all_landau_x), array('d',all_landau_y), array('d',all_landau_x_err), array('d',all_landau_y_err))
            global_graph.Fit(global_fit_function, "R")
            param0 = global_fit_function.GetParameter(0)
            param1 = global_fit_function.GetParameter(1)
            legend.AddEntry(global_graph, f"Global fit: {param0:.2f}*x {param1:.1f}", "L")
        legend.SetTextFont(myStyle.GetFont())
        legend.SetTextSize(myStyle.GetSize()-6)
        legend.SetFillColor(kWhite)
        legend.SetFillStyle(4050)#
        legend.SetBorderSize(1)
        legend.Draw()
        canvas2.SaveAs(output_file)            

if(plotAmpVsTR):
    canvas = TCanvas("c3", "Plots", 1000, 800)
    gStyle.SetGridStyle()
    gStyle.SetGridColor(921)
    canvas.SetGridy()

    graphs = []

    quantities = [
        ("Time Resolution", data_tr, data_amp, "../amplitude_vs_time_resolution_withErrBars.pdf", 20, 40, 'ps'),
        ("Noise", data_noise, data_amp, "../amplitude_vs_noise_withErrBars.pdf", 1.5, 2.0, 'mV'),
        ("Risetime", data_risetime, data_amp, "../amplitude_vs_risetime_withErrBars.pdf", 700, 800, 'ps'),
        ("Jitter", data_jitter, data_amp, "../amplitude_vs_jitter_withErrBars.pdf", 10, 30, 'ps'),
        ("Landau", data_landau, data_amp, "../amplitude_vs_landau_withErrBars.pdf", 10, 30, 'ps'),
        ("Slewrate", data_slewrate, data_amp, "../amplitude_vs_slewrate_withErrBars.pdf", 30, 120, 'mV/ps'),
    ]

    for qty_name, qty_data, amp_data, output_file, y_min, y_max, units in quantities:
        # legend.Clear()
        graphs.clear()
        y_offset = 0.0 if "Resolution" in qty_name or "Jitter" in qty_name or "Landau" in qty_name else -0.4
        x_offset = -0.1 if "Resolution" in qty_name  else 0.0
        legend = TLegend(0.45+x_offset, 0.6+y_offset, 0.94+x_offset, 0.9+y_offset)
        legend.SetHeader("Bias Voltage", "C")

        all_landau_x = []
        all_landau_y = []
        all_landau_x_err = []
        all_landau_y_err = []
        for i, bias_voltage in enumerate(qty_data.keys()):
            if bias_voltage not in amp_data:
                continue

            qty_points = {att: (qty, qty_err) for att, qty, qty_err in qty_data[bias_voltage]}
            amp_points = {att: (amp, amp_err) for att, amp, amp_err in amp_data[bias_voltage]}
            combined_points = [
                (amp_points[att][0], amp_points[att][1], qty_points[att][0], qty_points[att][1])
                for att in amp_points if att in qty_points
            ]

            if not combined_points:
                continue

            combined_points.sort()
            x = array('d', [p[0] for p in combined_points])
            x_err = array('d', [p[1] for p in combined_points])
            y = array('d', [p[2] for p in combined_points])
            y_err = array('d', [p[3] for p in combined_points])

            graph = TGraphErrors(len(x), x, y, x_err, y_err)
            graph.SetMarkerStyle(20 + i)
            graph.SetMarkerColor(colors[i % len(colors)])
            graph.SetLineColor(colors[i % len(colors)])
            graph.SetLineWidth(2)
            graph.SetTitle("")
            graph.GetXaxis().SetLimits(30, 115)
            graph.SetMinimum(y_min)
            graph.SetMaximum(y_max)

            if "Resolution" in qty_name:  # Only fit if the condition is met
                fit_function = TF1(f"fit_{bias_voltage}", "[0]/x + [1]", 30, 115)
                fit_function.SetLineStyle(2)
                fit_function.SetLineColor(colors[i % len(colors)])
                graph.Fit(fit_function, "R")
                param0 = fit_function.GetParameter(0)
                param1 = fit_function.GetParameter(1)
                legend.AddEntry(graph, f"{bias_voltage}V (fit: {param0:.1f}/x + {param1:.1f})", "PL")
            elif "Landau" in qty_name:  # Fit with a linear equation if the condition is met
                fit_function = TF1(f"fit_{bias_voltage}", "[0]*x + [1]", 30, 115)
                fit_function.SetLineStyle(2)
                fit_function.SetLineColor(colors[i % len(colors)])
                graph.Fit(fit_function, "R")
                param0 = fit_function.GetParameter(0)
                param1 = fit_function.GetParameter(1)
                legend.AddEntry(graph, f"{bias_voltage}V (fit: {param0:.2f}*x + {param1:.1f})", "PL")

                all_landau_x.extend(x)
                all_landau_y.extend(y)
                all_landau_x_err.extend(x_err)
                all_landau_y_err.extend(y_err)
            else:
                legend.AddEntry(graph, f"{bias_voltage}V", "PL")

            if i == 0:
                graph.Draw("APL")
                graph.GetXaxis().SetTitle("Mid-gap amplitude [mV]")
                graph.GetYaxis().SetTitle(f"{qty_name} [{units}]")
                graph.GetYaxis().SetTitleOffset(1.2)
            else:
                graph.Draw("PL same")

            graphs.append(graph)
        if "Landau" in qty_name:
            global_fit_function = TF1("global_fit", "[0]*x + [1]", 91, 95)
            global_graph = TGraphErrors(len(all_landau_x), array('d',all_landau_x), array('d',all_landau_y), array('d',all_landau_x_err), array('d',all_landau_y_err))
            global_graph.Fit(global_fit_function, "R")
            param0 = global_fit_function.GetParameter(0)
            param1 = global_fit_function.GetParameter(1)
            legend.AddEntry(global_graph, f"Global fit: {param0:.2f}*x + {param1:.1f}", "L")
        legend.SetTextFont(myStyle.GetFont())
        legend.SetTextSize(myStyle.GetSize()-6)
        legend.SetFillColor(kWhite)
        legend.SetFillStyle(4050)
        legend.SetBorderSize(1)
        legend.Draw()
        myStyle.SensorInfo(sensor="Sensor: S3")
        canvas.SaveAs(output_file)