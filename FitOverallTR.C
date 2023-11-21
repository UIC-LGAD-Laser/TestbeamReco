#include <TFile.h>
#include <TH1F.h>
#include <TF1.h>
#include <TCanvas.h>
#include <TPaveText.h>
#include <TLegend.h>

void FitOverallTR()
{
    // Open the ROOT file
    // 
    const char* fileName = "./output/HPK_W9_15_2_120V_oldAttn/HPK_W9_15_2_120V_oldAttn_Analyze.root";
    const char* histogramName = "weighted2_timeDiff_tracker";
    
    TFile* file = TFile::Open(fileName);
    // TFile* file2 = TFile::Open(fileName2);
    if (!file || file->IsZombie()) {
        std::cerr << "Error opening file: " << fileName << std::endl;
        return;
    }
    
    // Access the histogram
    TH1F* histogram = (TH1F*)file->Get(histogramName);
    // TH1F* histogram2 = (TH1F*)file2->Get(histogramName);
    if (!histogram) {
        std::cerr << "Error accessing histogram: " << histogramName << " in file: " << fileName << std::endl;
        file->Close();
        return;
    }
    
    // Create a Gaussian function for fitting
    TF1* gaussian = new TF1("gaussian", "gaus");
    // TF1* gaussian2 = new TF1("gaussian2", "gaus");
    
    double xmin = histogram->GetMean() - (1.5*histogram->GetRMS());
    double xmax = histogram->GetMean() + (1.5*histogram->GetRMS());
    // double xmin2 = histogram2->GetMean() - (1.5*histogram2->GetRMS());
    // double xmax2 = histogram2->GetMean() + (1.5*histogram2->GetRMS());
    
    // Set the fit range
    gaussian->SetRange(xmin, xmax);
    // gaussian2->SetRange(xmin2, xmax2);
    
    // Fit the histogram with the Gaussian function in the specified range
    histogram->Fit(gaussian, "R");
    // histogram2->Fit(gaussian2, "R");
    
    // Create a canvas for visualization
    TCanvas* canvas = new TCanvas("canvas", "Histogram Fit", 1200, 900);
    
    // Draw the histogram
    histogram->Draw("hist");
    // histogram2->Draw("hist same");
    histogram->SetLineColor(kRed);
    // histogram2->SetLineColor(kGreen);
    // gStyle->SetHistTopMargin(1.5);

    // Draw the fitted function
    gaussian->Draw("same");

    // Create a TPaveText to display the fit parameters
    // TPaveText* paveText = new TPaveText(0.6, 0.5, 0.9, 0.7, "NDC");
    // paveText->AddText("Fit Parameters:");
    // paveText->AddText(Form("Mean: %.2f +/- %.2f", gaussian->GetParameter(1), gaussian->GetParError(1)));
    // paveText->AddText(Form("Sigma: %.2f +/- %.2f", gaussian->GetParameter(2), gaussian->GetParError(2)));
    // paveText->SetFillColor(0);
    // paveText->SetBorderSize(0);
    // paveText->Draw();

    // gaussian2->Draw("same l");
    gaussian->SetLineColor(kRed);
    // gaussian2->SetLineColor(kGreen);
    cout << "UIC Laser fit: " << gaussian->GetParameter(2)*1000.0 << endl;
    // cout << "UIC Laser TR with photek correction: " << sqrt(gaussian->GetParameter(2)*1000.0*gaussian->GetParameter(2)*1000.0 - 100)<< endl;
    
    // Create a legend
    TLegend* legend = new TLegend(0.1, 0.7, 0.45, 0.8);
    legend->AddEntry(gaussian, "Gaussian Fit - UIC Laser", "l");
    // legend->AddEntry(gaussian2, "Gaussian Fit - FTBF", "l");
    legend->SetTextSize(0.03);
    legend->Draw();
    
    // Save the canvas as an image file
    canvas->SaveAs("histogram_fit_HPK_W9_15_2_120V_oldAttn.png");
    
    // Clean up
    file->Close();
    //delete canvas;
}

