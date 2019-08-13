#include "/phenix/u/shlim/Style.h"

void Draw_dNdy_pAl(){

	const int ncent = 3;
	const int cent_per[ncent+1] = {0, 20, 40, 72};

	const int nColor[ncent] = {2, 4, 6};

	const int narm = 2;
	const int nybin = 4;

	double xx[narm][nybin] = {{-1.325, -1.575, -1.825, -2.075}, {1.325, 1.575, 1.825, 2.075}};
	double xx_err[narm][nybin] = {{0.1, 0.1, 0.1, 0.1}, {0.1, 0.1, 0.1, 0.1}};

	const double Ncoll_cent[ncent] = {3.35, 2.3, 1.7};
	const double Ncoll_cent_sys[ncent] = {0.3/3.5, 0.1/2.3, 0.1/1.7};
	const double Npart_cent[ncent] = {4.35, 3.3, 2.7};
	const double BiasF_cent[ncent] = {0.81, 0.90, 1.01};
	const double BiasF_cent_sys[ncent] = {0.01/0.81, 0.02/0.90, 0.04/1.01};

	const double Njpsi[ncent][narm][nybin] = {
		{{396, 1446, 1114, 329}, {358, 1544, 1657, 993}},
		{{302, 999, 715, 207}, {227, 1272, 1388, 747}},
		{{250, 917, 714, 206}, {292, 1290, 1450, 929}}
	};

	const double Njpsi_err[ncent][narm][nybin] = {
		{{25, 52, 47, 25}, {22, 49, 54, 37}},
		{{19, 37, 36, 17}, {17, 42, 44, 34}},
		{{18, 30, 31, 18}, {19, 42, 48, 39}}
	};

	const double sys_fit[narm] = {0.046, 0.031};
	const double sys_corrbkg[ncent][narm] = {{0.032, 0.016}, {0.020, 0.029}, {0.029, 0.016}};
	const double sys_var[narm] = {0.033, 0.028};
	const double sys_acceff[narm] = {0.039, 0.041};
	double sys_trigeff[ncent][narm] = {0.}; //will be updated later
	double sys_trigeff_y[ncent][narm][nybin] = {0.}; //will be updated later

	//Run15pp200
	const double eff_pp_bbc = 0.55;
	const double eff_pp_trk = 0.79;

	const double Njpsi_pp15[narm][nybin] = {{3151, 12079, 10645, 2978}, {2082, 10583, 12170, 7040}};
	const double Njpsi_pp15_err[narm][nybin] = {{66, 132, 124, 63}, {54, 120, 138, 109}};

	const double sys_fit_pp[narm] = {0.011, 0.010};
	const double sys_corrbkg_pp[narm] = {0.020, 0.020};
	const double sys_var_pp[narm] = {0.047, 0.040};
	const double sys_acceff_pp[narm] = {0.054, 0.061};
	double sys_trigeff_pp[narm] = {0.026, 0.023}; //will be updated later
	double sys_trigeff_y_pp[narm][4] = {{0.010, 0.017, 0.040, 0.073}, {0.012, 0.010, 0.027, 0.054}}; //will be updated later
	const double sys_pol_pp[narm][4] = {{0.138, 0.128, 0.116, 0.101}, {0.129, 0.1333, 0.116, 0.104}};

	TFile *infile_pp = new TFile("/gpfs/mnt/gpfs02/phenix/hhj/hhj1/shlim/work/15.run15/10.runQA/00.eventhist/Run15pp200_eventhist_for_dimuon_20180402.root","read");

	double NMB_pp[narm];
	TH1F *hBBCZ_pp[narm];
	for (int iarm=0; iarm<narm; iarm++){
		hBBCZ_pp[iarm] = (TH1F*)infile_pp->Get(Form("hBBCZ_arm%d",iarm));
		NMB_pp[iarm] = hBBCZ_pp[iarm]->Integral();
	}
	infile_pp->Close();

	TFile *infile1_pp = new TFile("/gpfs/mnt/gpfs02/phenix/hhj/hhj1/shlim/work/15.run15/14.acc_by_eff/01.Inclusive_Jpsi/eff_files/Run15pp200_acceff_InclusiveJpsi_C.root","read");

	TH1F *heff_y_pp[narm];
	TH1F *heff_y_int_pp[narm];
	double eff_y_pp[narm][nybin], eff_y_int_pp[narm];

	for (int iarm=0; iarm<narm; iarm++){
		heff_y_pp[iarm] = (TH1F*)infile1_pp->Get(Form("heff_yy_w_pp_set1_arm%d",iarm));
		heff_y_int_pp[iarm] = (TH1F*)infile1_pp->Get(Form("heff_yy_int_w_pp_set1_arm%d",iarm));

		for (int iy=0; iy<nybin; iy++){
			eff_y_pp[iarm][iy] = heff_y_pp[iarm]->GetBinContent(iy+1);
			cout << "pp ARM: " << iarm << ", Y: " << iy << ", eff0: " << eff_y_pp[iarm][iy] << endl;
		}

		eff_y_int_pp[iarm] = heff_y_int_pp[iarm]->GetBinContent(1);
	}
	infile1_pp->Close();

	TFile *infile2_pp = new TFile("/gpfs/mnt/gpfs02/phenix/hhj/hhj1/shlim/work/15.run15/14.acc_by_eff/01.Inclusive_Jpsi/eff_files/Run15pp200_C_trigeff_MUID2D_output.root","read");

	TH1F *htrigeff_pp[narm];
	TH1F *htrigeff_pp_int[narm];
	TH1F *htrigeff_wt_pp[narm];
	TH1F *htrigeff_wt_pp_int[narm];
	double trigeff_y_pp[narm][nybin];
	double trigeff_y_int_pp[narm];

	for (int iarm=0; iarm<narm; iarm++){
		htrigeff_pp[iarm] = (TH1F*)infile2_pp->Get(Form("htrigeff_y_w_pp_set1_arm%d",iarm));
		htrigeff_wt_pp[iarm] = (TH1F*)infile2_pp->Get(Form("htrigeff_y_wt_w_pp_set1_arm%d",iarm));
		htrigeff_pp_int[iarm] = (TH1F*)infile2_pp->Get(Form("htrigeff_y_int_w_pp_set1_arm%d",iarm));
		htrigeff_wt_pp_int[iarm] = (TH1F*)infile2_pp->Get(Form("htrigeff_y_int_wt_w_pp_set1_arm%d",iarm));

		for (int iy=0; iy<nybin; iy++){
			float eff0 = htrigeff_pp[iarm]->GetBinContent(iy+1);
			float eff1 = htrigeff_wt_pp[iarm]->GetBinContent(iy+1);

			trigeff_y_pp[iarm][iy] = (eff0 + eff1)/2;
			sys_trigeff_y_pp[iarm][iy] = fabs(eff0 - eff1)/(eff0 + eff1);

			cout << "pp ARM: " << iarm << ", Y: " << iy << ", TRIG EFF: " << trigeff_y_pp[iarm][iy] << ", Err: " << sys_trigeff_y_pp[iarm][iy] << endl;
		}

		float eff0 = htrigeff_pp_int[iarm]->GetBinContent(1);
		float eff1 = htrigeff_wt_pp_int[iarm]->GetBinContent(1);

		trigeff_y_int_pp[iarm] = (eff0 + eff1)/2;
		sys_trigeff_pp[iarm] = fabs(eff0 - eff1)/(eff0 + eff1);
	}
	infile2_pp->Close();

	double Xec_pp15[narm][nybin], Xec_pp15_err[narm][nybin], Xec_pp15_syserr[narm][nybin];
	double Y_pp15[narm][nybin], Y_pp15_err[narm][nybin], Y_pp15_syserr[narm][nybin];

	for (int iarm=0; iarm<narm; iarm++){
		for (int iy=0; iy<nybin; iy++){
			Y_pp15[iarm][iy] = (Njpsi_pp15[iarm][iy]/eff_pp_trk) / (NMB_pp[iarm]/eff_pp_bbc) / 0.25 / eff_y_pp[iarm][iy] / trigeff_y_pp[iarm][iy];
			Y_pp15_err[iarm][iy] = (Njpsi_pp15_err[iarm][iy]/eff_pp_trk) / (NMB_pp[iarm]/eff_pp_bbc) / 0.25 / eff_y_pp[iarm][iy] / trigeff_y_pp[iarm][iy];
			Y_pp15_syserr[iarm][iy] = sys_fit_pp[iarm]*sys_fit_pp[iarm];
			Y_pp15_syserr[iarm][iy] += sys_corrbkg_pp[iarm]*sys_corrbkg_pp[iarm];
			Y_pp15_syserr[iarm][iy] += sys_var_pp[iarm]*sys_var_pp[iarm];
			Y_pp15_syserr[iarm][iy] += sys_acceff_pp[iarm]*sys_acceff_pp[iarm];
			Y_pp15_syserr[iarm][iy] += sys_trigeff_y_pp[iarm][iy]*sys_trigeff_y_pp[iarm][iy];
			Y_pp15_syserr[iarm][iy] += sys_pol_pp[iarm][iy]*sys_pol_pp[iarm][iy];
			Y_pp15_syserr[iarm][iy] = Y_pp15[iarm][iy] * sqrt(Y_pp15_syserr[iarm][iy]); 

			Xec_pp15[iarm][iy] = Y_pp15[iarm][iy] * 42.0 * 1e6;
			Xec_pp15_err[iarm][iy] = Y_pp15_err[iarm][iy] * 42.0 * 1e6;
			Xec_pp15_syserr[iarm][iy] = Y_pp15_syserr[iarm][iy] * 42.0 * 1e6;
		}
	}

	TGraphErrors *gy_pp15[narm];
	TGraphErrors *gy_pp15_sys[narm];
	TGraphErrors *gy_xec_pp15[narm];
	TGraphErrors *gy_xec_pp15_sys[narm];

	for (int iarm=0; iarm<narm; iarm++){
		gy_pp15[iarm] = new TGraphErrors(nybin, &xx[iarm][0], &Y_pp15[iarm][0], 0, &Y_pp15_err[iarm][0]);
		gy_pp15[iarm]->SetMarkerStyle(20);
		gy_pp15[iarm]->SetMarkerColor(1);
		gy_pp15[iarm]->SetLineWidth(1);
		gy_pp15[iarm]->SetLineColor(1);

		gy_pp15_sys[iarm] = new TGraphErrors(nybin, &xx[iarm][0], &Y_pp15[iarm][0], &xx_err[iarm][0], &Y_pp15_syserr[iarm][0]);
		gy_pp15_sys[iarm]->SetMarkerStyle(20);
		gy_pp15_sys[iarm]->SetMarkerColor(1);
		gy_pp15_sys[iarm]->SetLineWidth(1);
		gy_pp15_sys[iarm]->SetLineColor(1);
		gy_pp15_sys[iarm]->SetFillStyle(0);

		gy_xec_pp15[iarm] = new TGraphErrors(nybin, &xx[iarm][0], &Xec_pp15[iarm][0], 0, &Xec_pp15_err[iarm][0]);
		gy_xec_pp15[iarm]->SetMarkerStyle(20);
		gy_xec_pp15[iarm]->SetMarkerColor(1);
		gy_xec_pp15[iarm]->SetLineWidth(1);
		gy_xec_pp15[iarm]->SetLineColor(1);

		gy_xec_pp15_sys[iarm] = new TGraphErrors(nybin, &xx[iarm][0], &Xec_pp15[iarm][0], &xx_err[iarm][0], &Xec_pp15_syserr[iarm][0]);
		gy_xec_pp15_sys[iarm]->SetMarkerStyle(29);
		gy_xec_pp15_sys[iarm]->SetMarkerColor(1);
		gy_xec_pp15_sys[iarm]->SetLineWidth(1);
		gy_xec_pp15_sys[iarm]->SetLineColor(1);
		gy_xec_pp15_sys[iarm]->SetFillStyle(0);
	}

	TCanvas *cpp = new TCanvas("cpp","cpp",1.2*400,400);
	SetPadStyle();
	htmp = (TH1F*)gPad->DrawFrame(-3,0,3,60);
	SetHistoStyle("y","B_{ll}d#sigma/dy (nb)");

	for (int iarm=0; iarm<narm; iarm++){
		gy_xec_pp15_sys[iarm]->Draw("2");
		gy_xec_pp15[iarm]->Draw("p");
	}

	TCanvas *c10 = new TCanvas("c10","c10",1.1*2*400,1*400);
	c10->Divide(2,1);
	c10->cd(1);
	SetPadStyle();
	htmp = (TH1F*)gPad->DrawFrame(-3,0,3,1.6e-6);
	SetHistoStyle("y","B_{ll}dN/dy");

	for (int iarm=0; iarm<narm; iarm++){
		gy_pp15_sys[iarm]->Draw("2");
		gy_pp15[iarm]->Draw("p");
	}

	TFile *infile = new TFile("/gpfs/mnt/gpfs02/phenix/hhj/hhj1/shlim/work/15.run15/10.runQA/00.eventhist/Run15pAl200_eventhist_for_dimuon_20180314.root","read");

	TH1D *hBBCZ[ncent][narm];
	double NMB[ncent][narm];
	for (int icent=0; icent<ncent; icent++){
		for (int iarm=0; iarm<narm; iarm++){
			hBBCZ[icent][iarm] = (TH1D*)infile->Get(Form("hBBCZ_CENT%02d%02d_arm%d",cent_per[icent],cent_per[icent+1],iarm));
			NMB[icent][iarm] = hBBCZ[icent][iarm]->Integral();
		}
	}

	TH1D *hBBCZ_ALL[narm];
	TH1D *hBBCZ_A[narm];
	double NMB_ALL[narm], NMB_A[narm];
	for (int iarm=0; iarm<narm; iarm++){
		hBBCZ_ALL[iarm] = (TH1D*)infile->Get(Form("hBBCZ_arm%d",iarm));
		hBBCZ_A[iarm] = (TH1D*)infile->Get(Form("hBBCZ_Z_arm%d",iarm));
		NMB_ALL[iarm] = hBBCZ_ALL[iarm]->Integral();
		NMB_A[iarm] = hBBCZ_A[iarm]->Integral();
	}

	TH1F *heff_y[narm];
	TH1F *heff_y_int[narm];
	TH1F *heff_y_A[narm];
	TH1F *heff_y_int_A[narm];

	double eff_y[ncent][narm][nybin], eff_y_A[ncent][narm][nybin];
	double eff_y_int[ncent][narm], eff_y_int_A[ncent][narm];

	for (int icent=0; icent<ncent; icent++){

		TFile *infile1 = new TFile(Form("/gpfs/mnt/gpfs02/phenix/hhj/hhj1/shlim/work/15.run15/14.acc_by_eff/01.Inclusive_Jpsi/eff_files/Run15pAl200_CENT%02d%02d_acceff_InclusiveJpsi_C.root",cent_per[icent],cent_per[icent+1]),"read");

		for (int iarm=0; iarm<narm; iarm++){
			heff_y[iarm] = (TH1F*)infile1->Get(Form("heff_yy_w_dAu_set1_arm%d",iarm));
			heff_y_A[iarm] = (TH1F*)infile1->Get(Form("heff_yy_half_w_dAu_set1_arm%d",iarm));

			heff_y_int[iarm] = (TH1F*)infile1->Get(Form("heff_yy_int_w_dAu_set1_arm%d",iarm));
			heff_y_int_A[iarm] = (TH1F*)infile1->Get(Form("heff_yy_int_half_w_dAu_set1_arm%d",iarm));

			for (int iy=0; iy<nybin; iy++){
				eff_y[icent][iarm][iy] = heff_y[iarm]->GetBinContent(iy+1);
				eff_y_A[icent][iarm][iy] = heff_y_A[iarm]->GetBinContent(iy+1);

				cout << "pAl CENT: " << icent<< ", ARM: " << iarm << ", Y: " << iy << ", eff0: " << eff_y[icent][iarm][iy] << ", eff1: " << eff_y_A[icent][iarm][iy] << endl;

				if ( iarm==0 ){
					double F = NMB_A[iarm]/NMB_ALL[iarm];
					eff_y[icent][iarm][iy] = eff_y[icent][iarm][iy]*(1-F) + eff_y_A[icent][iarm][iy]*F;
					cout << "pAl CENT: " << icent << ", ARM: " << iarm << ", Y: " << iy << ", eff mod: " << eff_y[icent][iarm][iy] << endl;
				}
			}

		}//iarm

		infile1->Close();

	}//icent

	TH1F *htrigeff[narm];
	TH1F *htrigeff_int[narm];
	TH1F *htrigeff_A[narm];
	TH1F *htrigeff_int_A[narm];
	TH1F *htrigeff_wt[narm];
	TH1F *htrigeff_wt_int[narm];
	TH1F *htrigeff_wt_A[narm];
	TH1F *htrigeff_wt_int_A[narm];

	double trigeff_y[ncent][narm][nybin];
	double trigeff_y_int[ncent][narm];
	double trigeff_y_A[ncent][narm][nybin];
	double trigeff_y_int_A[ncent][narm];

	for (int icent=0; icent<ncent; icent++){

		TFile *infile2 = new TFile(Form("/gpfs/mnt/gpfs02/phenix/hhj/hhj1/shlim/work/15.run15/14.acc_by_eff/01.Inclusive_Jpsi/eff_files/Run15pAl200_CENT%02d%02d_C_trigeff_MUID2D_output.root",cent_per[icent],cent_per[icent+1]),"read");

		for (int iarm=0; iarm<narm; iarm++){

			htrigeff[iarm] = (TH1F*)infile2->Get(Form("htrigeff_y_set1_arm%d",iarm));
			htrigeff_A[iarm] = (TH1F*)infile2->Get(Form("htrigeff_y_half_set1_arm%d",iarm));
			htrigeff_int[iarm] = (TH1F*)infile2->Get(Form("htrigeff_y_int_set1_arm%d",iarm));
			htrigeff_int_A[iarm] = (TH1F*)infile2->Get(Form("htrigeff_y_int_half_set1_arm%d",iarm));

			htrigeff_wt[iarm] = (TH1F*)infile2->Get(Form("htrigeff_y_wt_set1_arm%d",iarm));
			htrigeff_wt_A[iarm] = (TH1F*)infile2->Get(Form("htrigeff_y_half_wt_set1_arm%d",iarm));
			htrigeff_wt_int[iarm] = (TH1F*)infile2->Get(Form("htrigeff_y_int_wt_set1_arm%d",iarm));
			htrigeff_wt_int_A[iarm] = (TH1F*)infile2->Get(Form("htrigeff_y_int_half_wt_set1_arm%d",iarm));

			for (int iy=0; iy<nybin; iy++){
				float eff0 = htrigeff[iarm]->GetBinContent(iy+1);
				float eff1 = htrigeff_wt[iarm]->GetBinContent(iy+1);
				trigeff_y[icent][iarm][iy] = (eff0 + eff1)/2;
				sys_trigeff_y[icent][iarm][iy] = fabs(eff0 - eff1)/(eff0 + eff1);

				eff0 = htrigeff_A[iarm]->GetBinContent(iy+1);
				eff1 = htrigeff_wt_A[iarm]->GetBinContent(iy+1);
				trigeff_y_A[icent][iarm][iy] = (eff0 + eff1)/2;

				cout << "pAl CENT: " << icent<< ", ARM: " << iarm << ", Y: " << iy << ", TRIG EFF: " << trigeff_y[icent][iarm][iy] << ", TRIG EFF A: " << trigeff_y_A[icent][iarm][iy] << ", Err: " << sys_trigeff_y[icent][iarm][iy] << endl;

				if ( iarm==0 ){
					double F = NMB_A[iarm]/NMB_ALL[iarm];
					trigeff_y[icent][iarm][iy] = trigeff_y[icent][iarm][iy]*(1-F) + trigeff_y_A[icent][iarm][iy]*F;
					cout << "TRIG EFF MOD: " << trigeff_y[icent][iarm][iy] << endl; 
				}
			}

		}//iarm

		infile2->Close();
	}//icent

	double Y[ncent][narm][nybin], Y_err[ncent][narm][nybin], Y_syserr[ncent][narm][nybin];
	double rpA[ncent][narm][nybin], rpA_err[ncent][narm][nybin], rpA_syserr[ncent][narm][nybin];

	TGraphErrors *gy[ncent][narm];
	TGraphErrors *gy_sys[ncent][narm];

	TGraphErrors *gR[ncent][narm];
	TGraphErrors *gR_sys[ncent][narm];

	for (int icent=0; icent<ncent; icent++){
		for (int iarm=0; iarm<narm; iarm++){
			for (int iy=0; iy<nybin; iy++){

				Y[icent][iarm][iy] = Njpsi[icent][iarm][iy] / NMB[icent][iarm] / 0.25 / Ncoll_cent[icent] * BiasF_cent[icent] / eff_y[icent][iarm][iy] / trigeff_y[icent][iarm][iy];
				Y_err[icent][iarm][iy] = Njpsi_err[icent][iarm][iy] / NMB[icent][iarm] / 0.25 / Ncoll_cent[icent] * BiasF_cent[icent] / eff_y[icent][iarm][iy] / trigeff_y[icent][iarm][iy];
				Y_syserr[icent][iarm][iy] = sys_fit[iarm]*sys_fit[iarm];
				Y_syserr[icent][iarm][iy] += sys_corrbkg[icent][iarm]*sys_corrbkg[icent][iarm];
				Y_syserr[icent][iarm][iy] += sys_var[iarm]*sys_var[iarm];
				Y_syserr[icent][iarm][iy] += sys_acceff[iarm]*sys_acceff[iarm];
				Y_syserr[icent][iarm][iy] += sys_trigeff_y[icent][iarm][iy]*sys_trigeff_y[icent][iarm][iy];
				Y_syserr[icent][iarm][iy] = Y[icent][iarm][iy] * sqrt(Y_syserr[icent][iarm][iy]); 

				rpA[icent][iarm][iy] = Y[icent][iarm][iy] / Y_pp15[iarm][iy];
				float err0 = Y_pp15_err[iarm][iy]/Y_pp15[iarm][iy];
				float err1 = Y_err[icent][iarm][iy]/Y[icent][iarm][iy];

				//TypeA err
				rpA_err[icent][iarm][iy] = rpA[icent][iarm][iy]*sqrt(err0*err0 + err1*err1 + sys_fit_pp[iarm]*sys_fit_pp[iarm] + sys_fit[iarm]*sys_fit[iarm]); 

				//TypeB err
				err0 = sqrt(sys_var_pp[iarm]*sys_var_pp[iarm] + sys_acceff_pp[iarm]*sys_acceff_pp[iarm] + sys_trigeff_y_pp[iarm][iy]*sys_trigeff_y_pp[iarm][iy] + sys_corrbkg_pp[iarm]*sys_corrbkg_pp[iarm]);
				err1 = sqrt(sys_var[iarm]*sys_var[iarm] + sys_acceff[iarm]*sys_acceff[iarm] + sys_trigeff_y[icent][iarm][iy]*sys_trigeff_y[icent][iarm][iy] + sys_corrbkg[icent][iarm]*sys_corrbkg[icent][iarm]);
				rpA_syserr[icent][iarm][iy] = rpA[icent][iarm][iy]*sqrt(err0*err0 + err1*err1);

			}//iy

			gy[icent][iarm] = new TGraphErrors(nybin, &xx[iarm][0], &Y[icent][iarm][0], 0, &Y_err[icent][iarm][0]);
			gy[icent][iarm]->SetMarkerStyle(24);
			gy[icent][iarm]->SetMarkerColor(nColor[icent]);
			gy[icent][iarm]->SetLineWidth(1);
			gy[icent][iarm]->SetLineColor(nColor[icent]);

			gy_sys[icent][iarm] = new TGraphErrors(nybin, &xx[iarm][0], &Y[icent][iarm][0], &xx_err[iarm][0], &Y_syserr[icent][iarm][0]);
			gy_sys[icent][iarm]->SetMarkerStyle(24);
			gy_sys[icent][iarm]->SetMarkerColor(nColor[icent]);
			gy_sys[icent][iarm]->SetLineWidth(1);
			gy_sys[icent][iarm]->SetLineColor(nColor[icent]);
			gy_sys[icent][iarm]->SetFillStyle(0);

			gR[icent][iarm] = new TGraphErrors(nybin, &xx[iarm][0], &rpA[icent][iarm][0], 0, &rpA_err[icent][iarm][0]);
			gR[icent][iarm]->SetMarkerStyle(24);
			gR[icent][iarm]->SetMarkerColor(nColor[icent]);
			gR[icent][iarm]->SetLineWidth(1);
			gR[icent][iarm]->SetLineColor(nColor[icent]);

			gR_sys[icent][iarm] = new TGraphErrors(nybin, &xx[iarm][0], &rpA[icent][iarm][0], &xx_err[iarm][0], &rpA_syserr[icent][iarm][0]);
			gR_sys[icent][iarm]->SetMarkerStyle(24);
			gR_sys[icent][iarm]->SetMarkerColor(nColor[icent]);
			gR_sys[icent][iarm]->SetLineWidth(1);
			gR_sys[icent][iarm]->SetLineColor(nColor[icent]);
			gR_sys[icent][iarm]->SetFillStyle(0);
		}//iarm
	}//icent

	//return;

	c10->cd(1);

	for (int icent=0; icent<ncent; icent++){
		for (int iarm=0; iarm<narm; iarm++){
			gy_sys[icent][iarm]->Draw("2");
			gy[icent][iarm]->Draw("p");
		}
	}

	c10->cd(2);

	SetPadStyle();
	htmp = (TH1F*)gPad->DrawFrame(-3,0,3,2.0);
	SetHistoStyle("y","B_{ll}dN/dy");

	TLine *line_rap = new TLine(-3,1,3,1);
	line_rap->SetLineWidth(2);
	line_rap->SetLineStyle(2);
	line_rap->Draw();

	for (int icent=0; icent<ncent; icent++){
		for (int iarm=0; iarm<narm; iarm++){
			gR_sys[icent][iarm]->Draw("2");
			gR[icent][iarm]->Draw("p");
		}
	}

	{
		TLegend *leg = new TLegend(0.10,0.75,0.5,0.90);
		leg->SetFillStyle(0);
		leg->SetBorderSize(0);
		le = leg->AddEntry("","p+Al #sqrt{s_{NN}}=200 GeV","");
		le->SetTextSize(0.055);
		le = leg->AddEntry("","J/#psi#rightarrow#mu#mu","");
		le->SetTextSize(0.055);
		leg->Draw();
	}

	{
		TLegend *leg = new TLegend(0.65,0.7,0.9,0.90);
		leg->SetFillStyle(0);
		leg->SetBorderSize(0);
		for (int icent=0; icent<ncent; icent++){
			le = leg->AddEntry(gR[icent][0],Form("%d-%d%c",cent_per[icent],cent_per[icent+1],'%'),"p");
			le->SetTextSize(0.055);
		}
		leg->Draw();
	}

	TCanvas *c12 = new TCanvas("c12","c12",1.3*3*300,1*300);
	c12->Divide(3,1);

	for (int icent=0; icent<ncent; icent++){
		c12->cd(icent+1);
		SetPadStyle();
		gPad->SetRightMargin(0.02);
		gPad->SetLeftMargin(0.15);
		htmp = (TH1F*)gPad->DrawFrame(-3,0,3,2.0);
		SetHistoStyle("y","R_{AB}","",0.08,0.07);
		htmp->GetYaxis()->SetTitleOffset(0.9);
		htmp->GetXaxis()->SetTitleOffset(0.85);

		for (int iarm=0; iarm<narm; iarm++){
			gR_sys[icent][iarm]->Draw("2");
			gR[icent][iarm]->Draw("p");
		}

		{
			TLegend *leg = new TLegend(0.40,0.70,0.9,0.90);
			leg->SetFillStyle(0);
			leg->SetBorderSize(0);
			le = leg->AddEntry("","p+Al #sqrt{s_{NN}}=200 GeV","");
			le->SetTextSize(0.07);
			le = leg->AddEntry("","J/#psi#rightarrow#mu#mu","");
			le->SetTextSize(0.07);
			le = leg->AddEntry("",Form("%d-%d%c Centrality",cent_per[icent],cent_per[icent+1],'%'),"");
			le->SetTextSize(0.07);
			leg->Draw();
		}
	}

}
