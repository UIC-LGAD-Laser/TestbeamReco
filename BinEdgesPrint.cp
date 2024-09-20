for (int i = 1; i<weighted2_timeDiff_tracker_vs_xy->GetXaxis()->GetNbins()+1; i++){std::cout<<weighted2_timeDiff_tracker_vs_xy->GetXaxis()->GetBinCenter(i)<<", ";}

for (int i = 1; i<weighted2_time_diffTracker->GetXaxis()->GetNbins()+1; i++){std::cout<<weighted2_time_diffTracker->GetXaxis()->GetBinCenter(i)<<", ";}

for (int i = 1; i<amplitude_vs_x_channel00->GetXaxis()->GetNbins()+1; i++){std::cout<<amplitude_vs_x_channel00->GetXaxis()->GetBinCenter(i)<<", ";}

for (int i = 1; i<weighted2_timeDiff_tracker_vs_xy->GetXaxis()->GetNbins()+1; i++){std::cout<<weighted2_timeDiff_tracker_vs_xy->GetBinContent(weighted2_timeDiff_tracker_vs_xy->GetXaxis->FindBin(0),5,i)<<", ";}