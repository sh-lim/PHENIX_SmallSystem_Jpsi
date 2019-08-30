void Draw_Y_for_AuAu(){

	TFile *infile0 = new TFile("Ypp_vs_pT.root","read");
	
	const int narm = 2;
	const char c_arm[narm] = {'S', 'N'};

	const int nptbin = 5;
	const float pt_array[nptbin+1] = {0.0, 1.5, 2.0, 3.0, 5.0, 7.0};

	int N[narm][nptbin] = {0};
	float Y[narm][nptbin] = {0.0};
	float Y_err[narm][nptbin] = {0.0};
	float Y_syserr[narm][nptbin] = {0.0};

	TH1D *hdNdpT_for_AuAu[narm];
	TH1D *hdNdpT_sys_for_AuAu[narm];
	
	TH1D *hdNdpT[narm];
	TH1D *hdNdpT_sys[narm];

	TGraphErrors *gdNdpT[narm];
	TGraphErrors *gdNdpT_sys[narm];

	TGraphErrors *gdNdpT_for_AuAu[narm];
	TGraphErrors *gdNdpT_sys_for_AuAu[narm];

	for (int iarm=0; iarm<narm; iarm++){
		hdNdpT[iarm] = (TH1D*)infile0->Get(Form("Ypp_vs_pT_%c",c_arm[iarm]));
		hdNdpT_sys[iarm] = (TH1D*)infile0->Get(Form("Ypp_vs_pT_%c_frac_sys",c_arm[iarm]));

		gdNdpT[iarm] = new TGraphErrors;
		gdNdpT_sys[iarm] = new TGraphErrors;

		gdNdpT_for_AuAu[iarm] = new TGraphErrors;
		gdNdpT_sys_for_AuAu[iarm] = new TGraphErrors;

		double Y_int0 = 0.0, Y_int1 = 0.0;

		for (int ipt=0; ipt<hdNdpT[iarm]->GetNbinsX(); ipt++){

			float xx = hdNdpT[iarm]->GetBinCenter(ipt+1);
			float dd = hdNdpT[iarm]->GetBinWidth(ipt+1);
			float yy = hdNdpT[iarm]->GetBinContent(ipt+1);
			float yy_err = hdNdpT[iarm]->GetBinError(ipt+1);
			float yy_syserr = hdNdpT_sys[iarm]->GetBinError(ipt+1);

			gdNdpT[iarm]->SetPoint(ipt, xx, yy);
			gdNdpT[iarm]->SetPointError(ipt, 0, yy_err);
			gdNdpT_sys[iarm]->SetPoint(ipt, xx, yy);
			gdNdpT_sys[iarm]->SetPointError(ipt, 0.125, yy_syserr*yy);

			cout << hdNdpT_sys[iarm]->GetBinError(ipt+1) << endl;

			Y_int0 += yy*xx;

			for (int jpt=0; jpt<nptbin; jpt++){
				if ( xx>pt_array[jpt] && xx<pt_array[jpt+1] ){
					Y_int1 += yy*xx;
					Y[iarm][jpt] += yy*xx*dd;
					Y_err[iarm][jpt] += pow(yy_err*xx*dd,2);
					Y_syserr[iarm][jpt] += yy_syserr;
					N[iarm][jpt]++;
					break;
				}
			}

		}//ipt

		cout << "ARM: " << iarm << ", INT0: " << Y_int0 << ", INT1: " << Y_int1 << endl;

		hdNdpT_for_AuAu[iarm] = new TH1D(Form("hdNdpT_for_AuAu_arm%d",iarm),"",nptbin,pt_array);
		hdNdpT_sys_for_AuAu[iarm] = new TH1D(Form("hdNdpT_sys_for_AuAu_arm%d",iarm),"",nptbin,pt_array);

		for (int jpt=0; jpt<nptbin; jpt++){
			float xx = (pt_array[jpt] + pt_array[jpt+1])/2;
			float dd = fabs(pt_array[jpt] - pt_array[jpt+1]);
			hdNdpT_for_AuAu[iarm]->SetBinContent(jpt+1, Y[iarm][jpt]/xx/dd);
			hdNdpT_for_AuAu[iarm]->SetBinError(jpt+1, sqrt(Y_err[iarm][jpt])/xx/dd);

			hdNdpT_sys_for_AuAu[iarm]->SetBinContent(jpt+1, Y[iarm][jpt]/xx/dd);
			hdNdpT_sys_for_AuAu[iarm]->SetBinError(jpt+1, Y_syserr[iarm][jpt]/N[iarm][jpt]*hdNdpT_sys_for_AuAu[iarm]->GetBinContent(jpt+1));

			gdNdpT_for_AuAu[iarm]->SetPoint(jpt, xx, hdNdpT_for_AuAu[iarm]->GetBinContent(jpt+1));
			gdNdpT_for_AuAu[iarm]->SetPointError(jpt, 0, hdNdpT_for_AuAu[iarm]->GetBinError(jpt+1));

			gdNdpT_sys_for_AuAu[iarm]->SetPoint(jpt, xx, hdNdpT_sys_for_AuAu[iarm]->GetBinContent(jpt+1));
			gdNdpT_sys_for_AuAu[iarm]->SetPointError(jpt, 0.125, hdNdpT_sys_for_AuAu[iarm]->GetBinError(jpt+1));

			cout << "PT: " << jpt 
				<< ", Y: " << hdNdpT_for_AuAu[iarm]->GetBinContent(jpt+1)
				<< ", Y_err: " << hdNdpT_for_AuAu[iarm]->GetBinError(jpt+1)/hdNdpT_for_AuAu[iarm]->GetBinContent(jpt+1)
				<< ", Y_syserr: " << hdNdpT_sys_for_AuAu[iarm]->GetBinError(jpt+1)/hdNdpT_for_AuAu[iarm]->GetBinContent(jpt+1)
				<< endl;
		}//jpt

	}//iarm

	TCanvas *c1 = new TCanvas("c1","c1",1.3*2*400,400);
	c1->Divide(2,1);

	for (int iarm=0; iarm<narm; iarm++){
		c1->cd(iarm+1);
		gPad->SetLogy();
		gPad->DrawFrame(0,1e-12,8,1e-6);

		gdNdpT_sys[iarm]->SetMarkerStyle(20);
		gdNdpT_sys[iarm]->SetLineColor(1);
		gdNdpT_sys[iarm]->SetLineWidth(1);
		gdNdpT_sys[iarm]->SetFillStyle(0);
		gdNdpT_sys[iarm]->Draw("2");

		gdNdpT[iarm]->SetMarkerStyle(20);
		gdNdpT[iarm]->SetLineColor(1);
		gdNdpT[iarm]->SetLineWidth(2);
		gdNdpT[iarm]->Draw("p");

		gdNdpT_sys_for_AuAu[iarm]->SetMarkerStyle(24);
		gdNdpT_sys_for_AuAu[iarm]->SetMarkerColor(2);
		gdNdpT_sys_for_AuAu[iarm]->SetLineColor(2);
		gdNdpT_sys_for_AuAu[iarm]->SetLineWidth(1);
		gdNdpT_sys_for_AuAu[iarm]->SetFillStyle(0);
		gdNdpT_sys_for_AuAu[iarm]->Draw("2");

		gdNdpT_for_AuAu[iarm]->SetMarkerStyle(24);
		gdNdpT_for_AuAu[iarm]->SetMarkerColor(2);
		gdNdpT_for_AuAu[iarm]->SetLineColor(2);
		gdNdpT_for_AuAu[iarm]->SetLineWidth(2);
		gdNdpT_for_AuAu[iarm]->Draw("p");
	}

	TFile *outfile = new TFile("Jpsi_dNdpT_pp_for_AuAu.root","recreate");
	for (int iarm=0; iarm<narm; iarm++){
		hdNdpT_for_AuAu[iarm]->Write();
		hdNdpT_sys_for_AuAu[iarm]->Write();
	}

}
