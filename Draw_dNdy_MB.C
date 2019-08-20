#include "/phenix/u/shlim/Style.h"

void Draw_dNdy_v0(){

	TLegendEntry *entry;

	const bool bSAVE = false;
	const bool bWRITE = false;

	double rap_pp[12], rap_pp_y[12], rap_pp_e1[12], rap_pp_e2[12], rap_pp_err[12];
	double xec_pp[12], xec_pp_y[12], xec_pp_e1[12], xec_pp_e2[12], xec_pp_err[12];
	rap_pp[0]  = -2.075; rap_pp_y[0]  = 17.6; rap_pp_e1[0]   = 0.5; rap_pp_e2[0]  = 1.5;
	rap_pp[1]  = -1.825; rap_pp_y[1]  = 24.4; rap_pp_e1[1]   = 0.4; rap_pp_e2[1]  = 1.9;
	rap_pp[2]  = -1.575; rap_pp_y[2]  = 31.5; rap_pp_e1[2]   = 0.5; rap_pp_e2[2]  = 2.2;
	rap_pp[3]  = -1.325; rap_pp_y[3]  = 41.2; rap_pp_e1[3]   = 1.1; rap_pp_e2[3]  = 5.3;
	rap_pp[4]  = -0.3;   rap_pp_y[4]  = 49.0; rap_pp_e1[4]   = 2.1; rap_pp_e2[4]  = 5.4;
	rap_pp[5]  = 0.0;    rap_pp_y[5]  = 45.6; rap_pp_e1[5]   = 1.6; rap_pp_e2[5]  = 5.0;
	rap_pp[6]  = 0.35;   rap_pp_y[6]  = 46.1; rap_pp_e1[6]   = 1.9; rap_pp_e2[6]  = 5.1;
	rap_pp[7]  = 1.325;  rap_pp_y[7]  = 40.7; rap_pp_e1[7]   = 1.2; rap_pp_e2[7]  = 5.7;
	rap_pp[8]  = 1.575;  rap_pp_y[8]  = 33.6; rap_pp_e1[8]   = 0.7; rap_pp_e2[8]  = 3.0;
	rap_pp[9]  = 1.825;  rap_pp_y[9]  = 25.6; rap_pp_e1[9]   = 0.4; rap_pp_e2[9]  = 2.5;
	rap_pp[10] = 2.075;  rap_pp_y[10] = 18.9; rap_pp_e1[10]  = 0.4; rap_pp_e2[10] = 1.9;
	rap_pp[11] = 2.325;  rap_pp_y[11] = 13.9; rap_pp_e1[11]  = 0.9; rap_pp_e2[11] = 1.4;

	for (int irap=0; irap<12; irap++){
		xec_pp[irap] = rap_pp[irap];
		xec_pp_y[irap] = rap_pp_y[irap];
		xec_pp_e1[irap] = rap_pp_e1[irap];
		xec_pp_e2[irap] = rap_pp_e2[irap];

		rap_pp_y[irap] = rap_pp_y[irap]/42.0*1e-6;
		rap_pp_e1[irap] = rap_pp_e1[irap]/42.0*1e-6;
		rap_pp_e2[irap] = rap_pp_e2[irap]/42.0*1e-6;

		rap_pp_err[irap] = 0.1;
	}

	double rap_dAu_y[12] = {
		2.5e-06, 4.0e-06, 5.4e-06, 7.2e-06,
		8.9e-07, 8.3e-07, 8.6e-07,
		5.5e-06, 4.2e-06, 3.2e-06, 2.5e-06, 1.5e-06};
	double rap_dAu_eA[12] = {
		5.1e-08, 4.2e-08, 5.0e-08, 1.1e-07,
		2.2e-08, 1.8e-08, 2.2e-08,
		8.5e-08, 3.8e-08, 3.1e-08, 3.1e-08, 4.9e-08};
	double rap_dAu_eB[12] = {
		2.2e-07, 3.5e-07, 4.8e-07, 6.3e-07,
		6.0e-08, 5.6e-08, 3.8e-08,
		5.1e-07, 3.9e-07, 3.0e-07, 2.3e-07, 1.4e-07};
	double rap_dAu_eC[12] = {
		5.3e-08, 8.5e-08, 1.1e-07, 1.5e-07,
		3.1e-08, 2.8e-08, 2.9e-08,
		1.2e-07, 8.9e-08, 6.8e-08, 5.2e-08, 3.2e-08};

	double rap_dAu_y_cent[4][8] = {
		{4.8e-06, 7.5e-06, 1.0e-05, 1.3e-05,
			9.8e-06, 7.7e-06, 5.4e-06, 4.1e-06},
		{3.0e-06, 4.8e-06, 6.7e-06, 8.5e-06,
			7.5e-06, 5.5e-06, 4.2e-06, 3.1e-06},
		{2.0e-06, 3.2e-06, 4.3e-06, 6.0e-06,
			5.3e-06, 4.0e-06, 3.1e-06, 2.4e-06},
		{9.8e-07, 1.6e-06, 2.2e-06, 2.8e-06,
			2.7e-06, 2.1e-06, 1.7e-06, 1.3e-06}
	};

	double rap_dAu_eS_cent[4][8] = {
		{1.5e-07, 1.3e-07, 1.6e-07, 3.4e-07,
			2.7e-07, 1.2e-07, 9.1e-08, 9.6e-08},
		{1.1e-07, 1.0e-07, 1.2e-07, 2.7e-07,
			2.3e-07, 1.0e-07, 8.3e-08, 8.3e-08},
		{8.6e-08, 8.0e-08, 9.4e-08, 2.2e-07,
			1.9e-07, 8.2e-08, 6.8e-08, 7.0e-08},
		{5.2e-08, 4.6e-08, 5.5e-08, 1.2e-07,
			1.1e-07, 4.9e-08, 4.1e-08, 4.3e-08},
	};

	double rap_dAu_eA_cent[4][8] = {
		{1.50E-07, 1.20E-07, 1.40E-07, 3.00E-07,
			2.50E-07, 1.10E-07, 8.60E-08, 9.00E-08},
		{1.10E-07, 9.50E-08, 1.10E-07, 2.50E-07,
			2.10E-07, 9.40E-08, 7.90E-08, 8.00E-08},
		{8.40E-08, 7.80E-08, 9.10E-08, 2.10E-07,
			1.80E-07, 8.00E-08, 6.60E-08, 6.80E-08},
		{5.20E-08, 4.50E-08, 5.50E-08, 1.20E-07,
			1.10E-07, 4.90E-08, 4.10E-08, 4.30E-08}
	};

	double rap_dAu_eB_cent[4][8] = {
		{4.20E-07, 6.60E-07, 8.70E-07, 1.10E-06,
			9.00E-07, 7.10E-07, 5.00E-07, 3.80E-07},
		{2.70E-07, 4.20E-07, 5.90E-07, 7.40E-07,
			6.90E-07, 5.10E-07, 3.90E-07, 2.90E-07},
		{1.70E-07, 2.80E-07, 3.80E-07, 5.30E-07,
			4.90E-07, 3.70E-07, 2.90E-07, 2.20E-07},
		{8.60E-08, 1.40E-07, 1.90E-07, 2.50E-07,
			2.50E-07, 1.90E-07, 1.60E-07, 1.20E-07}
	};

	double Ncoll_dAu = 7.6;
	double BiasF_dAu = 0.89;
	double Ncoll_dAu_sys = 0.427 / 7.590; 
	double BiasF_dAu_sys = 0.001 / 0.889; 
	for (int irap=0; irap<12; irap++){

		//rap_dAu_y[irap] *= BiasF_dAu;
		//rap_dAu_eA[irap] *= BiasF_dAu;
		//rap_dAu_eB[irap] *= BiasF_dAu;
		//rap_dAu_eC[irap] *= BiasF_dAu;

		if ( fabs(rap_pp[irap])<1.0 ) continue;
		rap_dAu_y[irap] /= Ncoll_dAu;
		rap_dAu_eA[irap] /= Ncoll_dAu;
		rap_dAu_eB[irap] /= Ncoll_dAu;
		rap_dAu_eC[irap] /= Ncoll_dAu;
	}

	double Ncoll_dAu_cent[4] = {15.061, 10.248, 6.579, 3.198};
	double Ncoll_dAu_cent_sys[4] = {1.103/15.061, 0.704/10.248, 0.444/6.579, 0.193/3.198};
	double BiasF_dAu_cent[4] = {0.941, 1.000, 1.034, 1.031};
	double BiasF_dAu_cent_sys[4] = {0.010/0.941, 0.006/1.000, 0.017/1.034, 0.055/1.031};
	double dNch_deta_dAu_cent[2][4] = {{19.403,13.789,9.06808,4.41948}, {13.007, 9.88559,7.46558,4.19178}};

	TGraphErrors *gpp = new TGraphErrors(12, rap_pp, rap_pp_y, 0, rap_pp_e1);
	gpp->SetMarkerStyle(20);
	gpp->SetMarkerColor(2);
	gpp->SetLineWidth(2);

	TGraphErrors *gpp_sys = new TGraphErrors(12, rap_pp, rap_pp_y, rap_pp_err, rap_pp_e2);
	gpp_sys->SetLineWidth(2);
	gpp_sys->SetFillStyle(0);
	gpp_sys->SetLineColor(2);
	gpp_sys->SetMarkerColor(2);

	TGraphErrors *gpp_xec = new TGraphErrors(12, xec_pp, xec_pp_y, 0, xec_pp_e1);
	gpp_xec->SetMarkerStyle(20);
	gpp_xec->SetLineWidth(2);

	TGraphErrors *gpp_xec_sys = new TGraphErrors(12, xec_pp, xec_pp_y, rap_pp_err, xec_pp_e2);
	gpp_xec_sys->SetLineWidth(2);
	gpp_xec_sys->SetFillStyle(0);
	gpp_xec_sys->SetLineColor(1);

	TGraphErrors *gdAu = new TGraphErrors(12, rap_pp, rap_dAu_y, 0, rap_dAu_eA);
	gdAu->SetMarkerStyle(20);
	gdAu->SetMarkerColor(4);
	gdAu->SetLineWidth(2);
	gdAu->SetLineColor(4);

	TGraphErrors *gdAu_sys = new TGraphErrors(12, rap_pp, rap_dAu_y, rap_pp_err, rap_dAu_eB);
	gdAu_sys->SetLineWidth(2);
	gdAu_sys->SetFillStyle(0);
	gdAu_sys->SetLineColor(4);

	TCanvas *cpp0 = new TCanvas("cpp0","cpp0",1.1*800,400);
	cpp0->Divide(2,1);

	cpp0->cd(1);
	SetPadStyle();
	htmp = (TH1F*)gPad->DrawFrame(-3,0,3,80);
	SetHistoStyle("y","B_{ll}d#sigma/dy (nb)");

	cpp0->cd(2);
	SetPadStyle();
	htmp = (TH1F*)gPad->DrawFrame(-3,0,3,80);
	SetHistoStyle("y","B_{ll}d#sigma/dy (nb)");

	gpp_xec_sys->Draw("2");
	gpp_xec->Draw("p");

	TCanvas *cpp = new TCanvas("cpp","cpp",1.1*800,400);
	cpp->Divide(2,1);

	cpp->cd(1);
	SetPadStyle();
	htmp = (TH1F*)gPad->DrawFrame(-3,0,3,1.5e-6);
	SetHistoStyle("y","dN/dy");

	cpp->cd(2);
	SetPadStyle();
	htmp = (TH1F*)gPad->DrawFrame(-3,0,3,1.5e-6);
	SetHistoStyle("y","dN/dy");

	gpp_sys->Draw("2");
	gpp->Draw("p");
	
	TCanvas *c0 = new TCanvas("c0","c0",1.1*400,400);
	SetPadStyle();
	htmp = (TH1F*)gPad->DrawFrame(-3,0,3,1.5e-6);
	SetHistoStyle("y","dN/dy");

	gpp_sys->Draw("2");
	gdAu_sys->Draw("2");

	gpp->Draw("p");
	gdAu->Draw("p");

	double rda_dAu[12] = {
		0.770, 0.880, 0.910, 0.920,
		0.765, 0.764, 0.784,
		0.710, 0.660, 0.660, 0.690, 0.560};
	double rda_dAu_eA[12] ={
		0.034, 0.020, 0.018, 0.030,
		0.038, 0.032, 0.038,
		0.032, 0.019, 0.020, 0.026, 0.074};
	double rda_dAu_eB[12] = {
		0.078, 0.078, 0.078, 0.078,
		0.099, 0.098, 0.100,
		0.083, 0.083, 0.083, 0.083, 0.083};

	TGraphErrors *grda_dAu = new TGraphErrors(12, rap_pp, rda_dAu, 0, rda_dAu_eA);
	grda_dAu->SetMarkerStyle(20);
	grda_dAu->SetLineWidth(2);

	TGraphErrors *grda_dAu_sys = new TGraphErrors(12, rap_pp, rda_dAu, rap_pp_err, rda_dAu_eB);
	grda_dAu_sys->SetFillStyle(0);
	grda_dAu_sys->SetLineWidth(2);

	TCanvas *c1 = new TCanvas("c1","c1",1.1*2*400,2*400);
	c1->Divide(2,2);
	c1->cd(1);
	SetPadStyle();
	htmp = (TH1F*)gPad->DrawFrame(-3,0,3,1.5);
	SetHistoStyle("y","R_{AB}");

	TLine *line_rap = new TLine(-3,1,3,1);
	line_rap->SetLineWidth(2);
	line_rap->SetLineStyle(2);
	line_rap->Draw();

	grda_dAu->Draw("p");
	grda_dAu_sys->Draw("2");


	const double Ncoll = 2.071;
	const double Ncoll_sys = 0.047;
	const double Npart = 3.3;
	const double BiasF = 0.796;
	const double BiasF_sys = 0.025;

	const double Ncoll_cent[3] = {3.35, 2.3, 1.7};
	const double Ncoll_cent_sys[3] = {0.3/3.5, 0.1/2.3, 0.1/1.7};
	const double Npart_cent[3] = {4.35, 3.3, 2.7};
	const double BiasF_cent[3] = {0.81, 0.90, 1.01};
	const double BiasF_cent_sys[3] = {0.01/0.81, 0.02/0.90, 0.04/1.01};
	const double dNch_deta_cent[2][4] = {{6.359,4.4015,3.21075}, {4.383,3.62334,3.08519}};

	const double Ncoll_pAu = 4.667;
	const double Ncoll_pAu_sys = 0.064;
	const double Npart_pAu = 5.667;
	const double BiasF_pAu = 0.858;
	const double BiasF_pAu_sys = 0.016;

	//const double Ncoll_pAu_cent[4] = {8.2, 6.1, 4.4, 2.6};
	//const double Ncoll_pAu_cent_sys[4] = {0.5/8.2, 0.4/6.1, 0.3/4.4, 0.2/2.6};
	//const double Npart_pAu_cent[4] = {9.2, 7.1, 5.4, 3.6};
	//const double BiasF_pAu_cent[4] = {0.90, 0.98, 1.02, 1.00};
	//const double BiasF_pAu_cent_sys[4] = {0.01/0.9, 0.01/0.98, 0.01/1.02, 0.06/1.00};
	//const double dNch_deta_pAu_cent[2][4] = {{13.399,9.14218,6.7201,4.45344}, {8.479,7.24308,5.99872,4.47823}};

	const double Ncoll_pAu_cent[5] = {9.7, 8.2, 6.1, 4.4, 2.6};
	const double Ncoll_pAu_cent_sys[5] = {0.6/9.7, 0.5/8.2, 0.4/6.1, 0.3/4.4, 0.2/2.6};
	const double Npart_pAu_cent[5] = {10.7, 9.2, 7.1, 5.4, 3.6};
	const double BiasF_pAu_cent[5] = {0.86, 0.90, 0.98, 1.02, 1.00};
	const double BiasF_pAu_cent_sys[5] = {0.01/0.86, 0.01/0.9, 0.01/0.98, 0.01/1.02, 0.06/1.00};
	const double dNch_deta_pAu_cent[2][5] = {{15.0, 13.399,9.14218,6.7201,4.45344}, {9.0, 8.479,7.24308,5.99872,4.47823}};

	const double Ncoll_HeAu = 10.446;
	const double Ncoll_HeAu_sys = 0.661/10.446;
	const double Npart_HeAu = 12.06;
	const double BiasF_HeAu = 0.889;
	const double BiasF_HeAu_sys = 0.01/0.89;

	const double Ncoll_HeAu_cent[4] = {22.3, 14.8, 8.40, 3.40};
	const double Ncoll_HeAu_cent_sys[4] = {1.7/22.3, 1.1/14.8, 0.6/8.4, 0.3/3.4};
	const double Npart_HeAu_cent[4] = {21.8, 15.4, 9.51, 4.55};
	const double BiasF_HeAu_cent[4] = {0.95, 1.01, 1.02, 1.03};
	const double BiasF_HeAu_cent_sys[4] = {0.01/0.95, 0.01/1.01, 0.01/1.02, 0.05/1.03};
	const double dNch_deta_HeAu_cent[2][4] = {{25.329,18.7539,11.6963,4.95968}, {16.744,12.9771,8.86729,4.1905}};

	const double eff_pp_bbc = 0.55;
	const double eff_pp_trk = 0.79;

	const int narm = 2;
	const int nybin = 4;

	//Run15pAl200
	const double Njpsi[narm][nybin] = {{907, 3288, 2497, 765}, {853, 4004, 4406, 2615}};
	const double Njpsi_err[narm][nybin] = {{36, 72, 65, 42}, {33, 77, 84, 66}};

	const double Njpsi_int[narm] = {7455, 11738};
	const double Njpsi_int_err[narm] = {115, 138};

	//3.7% scaling to match the total number of Njpsi in y bins
	const double Njpsi_cent[narm][3] = {{3025*0.963, 1821*0.963, 1968*0.963}, {4289, 3257, 3610}};
	const double Njpsi_cent_err[narm][3] = {{129, 84, 74}, {118, 95, 109}};

	const double sys_fit_pAl[narm] = {0.046, 0.031};
	const double sys_corrbkg_pAl[narm] = {0.024, 0.024};
	const double sys_var_pAl[narm] = {0.033, 0.028};
	const double sys_acceff_pAl[narm] = {0.039, 0.041};
	double sys_trigeff_pAl[narm] = {0.019, 0.045}; //will be updated later
	double sys_trigeff_y_pAl[narm][4] = {{0.010, 0.038, 0.071, 0.118}, {0.025, 0.010, 0.027, 0.056}}; //will be updated later

	//Run15pAu200
	const double Njpsi_pAu[narm][nybin] = {{1570, 5076, 3887, 913}, {1393, 6635, 6376, 3674}};
	const double Njpsi_pAu_err[narm][nybin] = {{52, 100, 78, 40}, {43, 100, 107, 83}};

	const double Njpsi_pAu_int[narm] = {11602, 18194};
	const double Njpsi_pAu_int_err[narm] = {193, 224};

	double double Njpsi_pAu_cent[narm][5] = {{1568, 5002, 3082, 2026, 1438}, {1575, 6026, 5077, 4122, 3146}};
	double double Njpsi_pAu_cent_err[narm][5] = {{56, 95, 105, 98, 43}, {75, 138, 120, 152, 81}};

	const double sys_fit_pAu[narm] = {0.017, 0.028};
	const double sys_corrbkg_pAu[narm] = {0.027, 0.031};
	const double sys_var_pAu[narm] = {0.035, 0.016};
	const double sys_acceff_pAu[narm] = {0.045, 0.039};
	double sys_trigeff_pAu[narm] = {0.019, 0.045}; //will be updated later
	double sys_trigeff_y_pAu[narm][4] = {{0.011, 0.010, 0.034, 0.087}, {0.052, 0.041, 0.040, 0.054}}; //will be updated later

	//Run14HeAu200
	const double Njpsi_HeAu[narm][nybin] = {{505, 1684, 1427, 477}, {325, 1346, 1503, 639}};
	const double Njpsi_HeAu_err[narm][nybin] = {{31, 64, 62, 41}, {21, 29, 54, 34}};

	const double Njpsi_HeAu_int[narm] = {3987, 3825};
	const double Njpsi_HeAu_int_err[narm] = {118, 91};

	double double Njpsi_HeAu_cent[narm][4] = {{1837, 1116, 766, 395}, {1517, 1182, 694, 432}};
	double double Njpsi_HeAu_cent_err[narm][4] = {{83, 49, 33, 24}, {64, 40, 38, 36}};

	const double sys_fit_HeAu[narm] = {0.030, 0.028};
	const double sys_corrbkg_HeAu[narm] = {0.039, 0.034};
	const double sys_var_HeAu[narm] = {0.050, 0.015};
	const double sys_acceff_HeAu[narm] = {0.032, 0.037};
	double sys_trigeff_HeAu[narm] = {0.017, 0.041}; //will be updated later
	double sys_trigeff_y_HeAu[narm][4] = {{0.038, 0.018, 0.011, 0.050}, {0.030, 0.010, 0.016, 0.041}}; //will be updated later

	//Run15pp200
	const double Njpsi_pp15[narm][nybin] = {{3151, 12079, 10645, 2978}, {2082, 10583, 12170, 7040}};
	const double Njpsi_pp15_err[narm][nybin] = {{66, 132, 124, 63}, {54, 120, 138, 109}};

	const double Njpsi_int_pp15[narm] = {28511, 31487};
	const double Njpsi_int_pp15_err[narm] = {205, 215};

	const double sys_fit_pp[narm] = {0.011, 0.010};
	const double sys_corrbkg_pp[narm] = {0.020, 0.020};
	const double sys_var_pp[narm] = {0.047, 0.040};
	const double sys_acceff_pp[narm] = {0.054, 0.061};
	double sys_trigeff_pp[narm] = {0.026, 0.023}; //will be updated later
	double sys_trigeff_y_pp[narm][4] = {{0.010, 0.017, 0.040, 0.073}, {0.012, 0.010, 0.027, 0.054}}; //will be updated later
	const double sys_pol_pp[narm][4] = {{0.138, 0.128, 0.116, 0.101}, {0.129, 0.1333, 0.116, 0.104}};

	double xx[narm][nybin] = {{-1.325, -1.575, -1.825, -2.075}, {1.325, 1.575, 1.825, 2.075}};
	double xx_err[narm][nybin] = {{0.1, 0.1, 0.1, 0.1}, {0.1, 0.1, 0.1, 0.1}};

	TFile *infile = new TFile("/gpfs/mnt/gpfs02/phenix/hhj/hhj1/shlim/work/15.run15/10.runQA/00.eventhist/Run15pAl200_eventhist_for_dimuon_20180314.root","read");
	TFile *infile_pAu = new TFile("/gpfs/mnt/gpfs02/phenix/hhj/hhj1/shlim/work/15.run15/10.runQA/00.eventhist/Run15pAu200_eventhist_for_dimuon_20180314.root","read");
	TFile *infile_HeAu = new TFile("/gpfs/mnt/gpfs02/phenix/hhj/hhj1/shlim/work/15.run15/10.runQA/00.eventhist/Run14HeAu200_eventhist_for_dimuon_20180314.root","read");
	TFile *infile_pp = new TFile("/gpfs/mnt/gpfs02/phenix/hhj/hhj1/shlim/work/15.run15/10.runQA/00.eventhist/Run15pp200_eventhist_for_dimuon_20180402.root","read");

	TH1F *hBBCZ_livetime[narm];
	TH1F *hBBCZ_livetime_A[narm];
	TH1F *hBBCZ_livetime_cent[narm][3];
	TH1F *hBBCZ_livetime_pAu[narm];
	TH1F *hBBCZ_livetime_pAu_cent[narm][4];
	TH1F *hBBCZ_livetime_HeAu[narm];
	TH1F *hBBCZ_livetime_HeAu_A[narm];
	TH1F *hBBCZ_livetime_HeAu_cent[narm][4];
	TH1F *hBBCZ_livetime_pp[narm];

	double NMB[narm], NMB_A[narm], NMB_cent[narm][3];
	double NMB_pAu[narm], NMB_pAu_cent[narm][5];
	double NMB_HeAu[narm], NMB_HeAu_A[narm], NMB_HeAu_cent[narm][4];
	double NMB_pp[narm];

	for (int iarm=0; iarm<narm; iarm++){
		hBBCZ_livetime[iarm] = (TH1F*)infile->Get(Form("hBBCZ_arm%d",iarm));
		hBBCZ_livetime_A[iarm] = (TH1F*)infile->Get(Form("hBBCZ_Z_arm%d",iarm));
		hBBCZ_livetime_cent[iarm][0] = (TH1F*)infile->Get(Form("hBBCZ_CENT0020_arm%d",iarm));
		hBBCZ_livetime_cent[iarm][1] = (TH1F*)infile->Get(Form("hBBCZ_CENT2040_arm%d",iarm));
		hBBCZ_livetime_cent[iarm][2] = (TH1F*)infile->Get(Form("hBBCZ_CENT4072_arm%d",iarm));

		hBBCZ_livetime_pAu[iarm] = (TH1F*)infile_pAu->Get(Form("hBBCZ_arm%d",iarm));
		hBBCZ_livetime_pAu_cent[iarm][1] = (TH1F*)infile_pAu->Get(Form("hBBCZ_CENT0020_arm%d",iarm));
		hBBCZ_livetime_pAu_cent[iarm][2] = (TH1F*)infile_pAu->Get(Form("hBBCZ_CENT2040_arm%d",iarm));
		hBBCZ_livetime_pAu_cent[iarm][3] = (TH1F*)infile_pAu->Get(Form("hBBCZ_CENT4060_arm%d",iarm));
		hBBCZ_livetime_pAu_cent[iarm][4] = (TH1F*)infile_pAu->Get(Form("hBBCZ_CENT6084_arm%d",iarm));

		hBBCZ_livetime_HeAu[iarm] = (TH1F*)infile_HeAu->Get(Form("hBBCZ_arm%d",iarm));
		hBBCZ_livetime_HeAu_A[iarm] = (TH1F*)infile_HeAu->Get(Form("hBBCZ_Z_arm%d",iarm));
		hBBCZ_livetime_HeAu_cent[iarm][0] = (TH1F*)infile_HeAu->Get(Form("hBBCZ_CENT0020_arm%d",iarm));
		hBBCZ_livetime_HeAu_cent[iarm][1] = (TH1F*)infile_HeAu->Get(Form("hBBCZ_CENT2040_arm%d",iarm));
		hBBCZ_livetime_HeAu_cent[iarm][2] = (TH1F*)infile_HeAu->Get(Form("hBBCZ_CENT4060_arm%d",iarm));
		hBBCZ_livetime_HeAu_cent[iarm][3] = (TH1F*)infile_HeAu->Get(Form("hBBCZ_CENT6088_arm%d",iarm));

		hBBCZ_livetime_pp[iarm] = (TH1F*)infile_pp->Get(Form("hBBCZ_arm%d",iarm));

		NMB[iarm] = hBBCZ_livetime[iarm]->Integral();
		NMB_A[iarm] = hBBCZ_livetime_A[iarm]->Integral();
		cout << "Ratio A in pAl: " << NMB_A[iarm]/NMB[iarm] << endl;
		cout << "ARM: " << iarm << ", NMB pAl: " << NMB[iarm] << endl;

		NMB_pAu[iarm] = hBBCZ_livetime_pAu[iarm]->Integral();
		cout << "ARM: " << iarm << ", NMB pAu: " << NMB_pAu[iarm] << endl;

		NMB_HeAu[iarm] = hBBCZ_livetime_HeAu[iarm]->Integral();
		NMB_HeAu_A[iarm] = hBBCZ_livetime_HeAu_A[iarm]->Integral();
		cout << "Ratio A in HeAu: " << NMB_HeAu_A[iarm]/NMB_HeAu[iarm] << endl;
		cout << "NMB_HeAu ARM: " << iarm << ", " << NMB_HeAu[iarm] << endl;

		NMB_pp[iarm] = hBBCZ_livetime_pp[iarm]->Integral();
		cout << "ARM: " << iarm << ", NMB pp:" << NMB_pp[iarm] << endl;

		for (int icent=0; icent<4; icent++){
			NMB_HeAu_cent[iarm][icent] = hBBCZ_livetime_HeAu_cent[iarm][icent]->Integral();
		}

		for (int icent=1; icent<5; icent++){
			NMB_pAu_cent[iarm][icent] = hBBCZ_livetime_pAu_cent[iarm][icent]->Integral();
		}
		NMB_pAu_cent[iarm][0] = 0.251*NMB_pAu_cent[iarm][1];

		for (int icent=0; icent<3; icent++){
			NMB_cent[iarm][icent] = hBBCZ_livetime_cent[iarm][icent]->Integral();
		}
	}

	infile->Close();
	infile_pAu->Close();
	infile_HeAu->Close();
	infile_pp->Close();

	//return;

	TH1F *heff_y_w_dAu[narm];
	TH1F *heff_y_w_pp[narm];
	TH1F *heff_y_int_w_dAu[narm][2];
	TH1F *heff_y_int_w_pp[narm][2];
	TH1F *heff_y_w_dAu_A[narm];
	TH1F *heff_y_w_pp_A[narm];
	TH1F *heff_y_int_w_dAu_A[narm][2];
	TH1F *heff_y_int_w_pp_A[narm][2];

	double eff_y[narm][nybin], eff_y_A[narm][nybin];
	double eff_y_int[narm][2], eff_y_int_A[narm][2];

	TFile *infile1 = new TFile("/gpfs/mnt/gpfs02/phenix/hhj/hhj1/shlim/work/15.run15/14.acc_by_eff/01.Inclusive_Jpsi/eff_files/Run15pAl200_CENT0072_acceff_InclusiveJpsi_C.root","read");
	for (int iarm=0; iarm<narm; iarm++){
		heff_y_w_dAu[iarm] = (TH1F*)infile1->Get(Form("heff_yy_w_dAu_set1_arm%d",iarm));
		heff_y_w_pp[iarm] = (TH1F*)infile1->Get(Form("heff_yy_w_pp_set1_arm%d",iarm));
		heff_y_w_dAu_A[iarm] = (TH1F*)infile1->Get(Form("heff_yy_half_w_dAu_set1_arm%d",iarm));
		heff_y_w_pp_A[iarm] = (TH1F*)infile1->Get(Form("heff_yy_half_w_pp_set1_arm%d",iarm));

		heff_y_int_w_dAu[iarm][0] = (TH1F*)infile1->Get(Form("heff_yy_int_w_dAu_set0_arm%d",iarm));
		heff_y_int_w_pp[iarm][0] = (TH1F*)infile1->Get(Form("heff_yy_int_w_pp_set0_arm%d",iarm));
		heff_y_int_w_dAu[iarm][1] = (TH1F*)infile1->Get(Form("heff_yy_int_w_dAu_set1_arm%d",iarm));
		heff_y_int_w_pp[iarm][1] = (TH1F*)infile1->Get(Form("heff_yy_int_w_pp_set1_arm%d",iarm));

		heff_y_int_w_dAu_A[iarm][0] = (TH1F*)infile1->Get(Form("heff_yy_int_half_w_dAu_set0_arm%d",iarm));
		heff_y_int_w_pp_A[iarm][0] = (TH1F*)infile1->Get(Form("heff_yy_int_half_w_pp_set0_arm%d",iarm));
		heff_y_int_w_dAu_A[iarm][1] = (TH1F*)infile1->Get(Form("heff_yy_int_half_w_dAu_set1_arm%d",iarm));
		heff_y_int_w_pp_A[iarm][1] = (TH1F*)infile1->Get(Form("heff_yy_int_half_w_pp_set1_arm%d",iarm));

		for (int iy=0; iy<nybin; iy++){
			eff_y[iarm][iy] = (heff_y_w_dAu[iarm]->GetBinContent(iy+1) + heff_y_w_pp[iarm]->GetBinContent(iy+1))/2.0;
			eff_y_A[iarm][iy] = (heff_y_w_dAu_A[iarm]->GetBinContent(iy+1) + heff_y_w_pp_A[iarm]->GetBinContent(iy+1))/2.0;

			cout << "pAl ARM: " << iarm << ", Y: " << iy << ", eff0: " << eff_y[iarm][iy] << ", eff1: " << eff_y_A[iarm][iy] << endl;

			if ( iarm==0 ){
				double F = NMB_A[iarm]/NMB[iarm];
				eff_y[iarm][iy] = eff_y[iarm][iy]*(1-F) + eff_y_A[iarm][iy]*F;
				cout << "pAl ARM: " << iarm << ", Y: " << iy << ", eff mod: " << eff_y[iarm][iy] << endl;
			}
		}

		eff_y_int[iarm][0] = (heff_y_int_w_dAu[iarm][0]->GetBinContent(1) + heff_y_int_w_pp[iarm][0]->GetBinContent(1))/2.0;
		eff_y_int[iarm][1] = (heff_y_int_w_dAu[iarm][1]->GetBinContent(1) + heff_y_int_w_pp[iarm][1]->GetBinContent(1))/2.0;
		eff_y_int_A[iarm][0] = (heff_y_int_w_dAu_A[iarm][0]->GetBinContent(1) + heff_y_int_w_pp_A[iarm][0]->GetBinContent(1))/2.0;
		eff_y_int_A[iarm][1] = (heff_y_int_w_dAu_A[iarm][1]->GetBinContent(1) + heff_y_int_w_pp_A[iarm][1]->GetBinContent(1))/2.0;

		if ( iarm==0 ){
			double F = NMB_A[iarm]/NMB[iarm];
			eff_y_int[iarm][0] = eff_y_int[iarm][0]*(1-F) + eff_y_int_A[iarm][0]*F;
			eff_y_int[iarm][1] = eff_y_int[iarm][1]*(1-F) + eff_y_int_A[iarm][1]*F;
		}
	}
	infile1->Close();

	//return;

	double eff_y_pAu[narm][nybin], eff_y_int_pAu[narm][2];
	TFile *infile1_pAu = new TFile("/gpfs/mnt/gpfs02/phenix/hhj/hhj1/shlim/work/15.run15/14.acc_by_eff/01.Inclusive_Jpsi/eff_files/Run15pAu200_CENT0084_acceff_InclusiveJpsi_C.root","read");

	for (int iarm=0; iarm<narm; iarm++){
		heff_y_w_dAu[iarm] = (TH1F*)infile1_pAu->Get(Form("heff_yy_w_dAu_set1_arm%d",iarm));
		heff_y_w_pp[iarm] = (TH1F*)infile1_pAu->Get(Form("heff_yy_w_pp_set1_arm%d",iarm));

		heff_y_int_w_dAu[iarm][0] = (TH1F*)infile1_pAu->Get(Form("heff_yy_int_w_dAu_set0_arm%d",iarm));
		heff_y_int_w_pp[iarm][0] = (TH1F*)infile1_pAu->Get(Form("heff_yy_int_w_pp_set0_arm%d",iarm));

		heff_y_int_w_dAu[iarm][1] = (TH1F*)infile1_pAu->Get(Form("heff_yy_int_w_dAu_set1_arm%d",iarm));
		heff_y_int_w_pp[iarm][1] = (TH1F*)infile1_pAu->Get(Form("heff_yy_int_w_pp_set1_arm%d",iarm));

		for (int iy=0; iy<nybin; iy++){
			eff_y_pAu[iarm][iy] = (heff_y_w_dAu[iarm]->GetBinContent(iy+1) + heff_y_w_pp[iarm]->GetBinContent(iy+1))/2.0;

			cout << "pAu ARM: " << iarm << ", Y: " << iy << ", eff0: " << eff_y_pAu[iarm][iy] << endl;
		}

		eff_y_int_pAu[iarm][0] = (heff_y_int_w_dAu[iarm][0]->GetBinContent(1) + heff_y_int_w_pp[iarm][0]->GetBinContent(1))/2.0;
		eff_y_int_pAu[iarm][1] = (heff_y_int_w_dAu[iarm][1]->GetBinContent(1) + heff_y_int_w_pp[iarm][1]->GetBinContent(1))/2.0;
	}
	infile1_pAu->Close();


	TFile *infile1_HeAu = new TFile("/gpfs/mnt/gpfs02/phenix/hhj/hhj1/shlim/work/15.run15/14.acc_by_eff/01.Inclusive_Jpsi/eff_files/Run14HeAu200_CENT0088_acceff_InclusiveJpsi_B.root","read");
	TFile *infile1_HeAu_A = new TFile("/gpfs/mnt/gpfs02/phenix/hhj/hhj1/shlim/work/15.run15/14.acc_by_eff/01.Inclusive_Jpsi/eff_files/Run14HeAu200_CENT0088_acceff_InclusiveJpsi_A.root","read"); //first ~30 runs showing a better efficiency at North
	double eff_y_HeAu[narm][nybin], eff_y_HeAu_A[narm][nybin];
	double eff_y_int_HeAu[narm][2], eff_y_int_HeAu_A[narm][2];

	for (int iarm=0; iarm<narm; iarm++){
		heff_y_w_dAu[iarm] = (TH1F*)infile1_HeAu->Get(Form("heff_yy_w_dAu_set1_arm%d",iarm));
		heff_y_w_pp[iarm] = (TH1F*)infile1_HeAu->Get(Form("heff_yy_w_pp_set1_arm%d",iarm));
		heff_y_w_dAu_A[iarm] = (TH1F*)infile1_HeAu_A->Get(Form("heff_yy_w_dAu_set1_arm%d",iarm));
		heff_y_w_pp_A[iarm] = (TH1F*)infile1_HeAu_A->Get(Form("heff_yy_w_pp_set1_arm%d",iarm));

		heff_y_int_w_dAu[iarm][0] = (TH1F*)infile1_HeAu->Get(Form("heff_yy_int_w_dAu_set0_arm%d",iarm));
		heff_y_int_w_pp[iarm][0] = (TH1F*)infile1_HeAu->Get(Form("heff_yy_int_w_pp_set0_arm%d",iarm));
		heff_y_int_w_dAu[iarm][1] = (TH1F*)infile1_HeAu->Get(Form("heff_yy_int_w_dAu_set1_arm%d",iarm));
		heff_y_int_w_pp[iarm][1] = (TH1F*)infile1_HeAu->Get(Form("heff_yy_int_w_pp_set1_arm%d",iarm));

		heff_y_int_w_dAu_A[iarm][0] = (TH1F*)infile1_HeAu_A->Get(Form("heff_yy_int_w_dAu_set0_arm%d",iarm));
		heff_y_int_w_pp_A[iarm][0] = (TH1F*)infile1_HeAu_A->Get(Form("heff_yy_int_w_pp_set0_arm%d",iarm));
		heff_y_int_w_dAu_A[iarm][1] = (TH1F*)infile1_HeAu_A->Get(Form("heff_yy_int_w_dAu_set1_arm%d",iarm));
		heff_y_int_w_pp_A[iarm][1] = (TH1F*)infile1_HeAu_A->Get(Form("heff_yy_int_w_pp_set1_arm%d",iarm));

		for (int iy=0; iy<nybin; iy++){
			eff_y_HeAu[iarm][iy] = (heff_y_w_dAu[iarm]->GetBinContent(iy+1) + heff_y_w_pp[iarm]->GetBinContent(iy+1))/2.0;
			eff_y_HeAu_A[iarm][iy] = (heff_y_w_dAu_A[iarm]->GetBinContent(iy+1) + heff_y_w_pp_A[iarm]->GetBinContent(iy+1))/2.0;

			cout << "HeAu ARM: " << iarm << ", Y: " << iy << ", eff0: " << eff_y_HeAu[iarm][iy] << ", eff1: " << eff_y_HeAu_A[iarm][iy] << endl;

			double F = NMB_HeAu_A[iarm]/NMB_HeAu[iarm];
			eff_y_HeAu[iarm][iy] = eff_y_HeAu[iarm][iy]*(1-F) + eff_y_HeAu_A[iarm][iy]*F;
			cout << "HeAu ARM: " << iarm << ", Y: " << iy << ", eff mod: " << eff_y_HeAu[iarm][iy] << endl;
		}

		eff_y_int_HeAu[iarm][0] = (heff_y_int_w_dAu[iarm][0]->GetBinContent(1) + heff_y_int_w_pp[iarm][0]->GetBinContent(1))/2.0;
		eff_y_int_HeAu[iarm][1] = (heff_y_int_w_dAu[iarm][1]->GetBinContent(1) + heff_y_int_w_pp[iarm][1]->GetBinContent(1))/2.0;
		eff_y_int_HeAu_A[iarm][0] = (heff_y_int_w_dAu_A[iarm][0]->GetBinContent(1) + heff_y_int_w_pp_A[iarm][0]->GetBinContent(1))/2.0;
		eff_y_int_HeAu_A[iarm][1] = (heff_y_int_w_dAu_A[iarm][1]->GetBinContent(1) + heff_y_int_w_pp_A[iarm][1]->GetBinContent(1))/2.0;

		double F = NMB_HeAu_A[iarm]/NMB_HeAu[iarm];
		eff_y_int_HeAu[iarm][0] = eff_y_int_HeAu[iarm][0]*(1-F) + eff_y_int_HeAu_A[iarm][0]*F;
		eff_y_int_HeAu[iarm][1] = eff_y_int_HeAu[iarm][1]*(1-F) + eff_y_int_HeAu_A[iarm][1]*F;
	}
	infile1_HeAu->Close();
	infile1_HeAu_A->Close();

	//return;

	TFile *infile1_pp = new TFile("/gpfs/mnt/gpfs02/phenix/hhj/hhj1/shlim/work/15.run15/14.acc_by_eff/01.Inclusive_Jpsi/eff_files/Run15pp200_acceff_InclusiveJpsi_C.root","read");
	double eff_y_pp[narm][nybin], eff_y_int_pp[narm][2];

	for (int iarm=0; iarm<narm; iarm++){
		heff_y_w_pp[iarm] = (TH1F*)infile1_pp->Get(Form("heff_yy_w_pp_set1_arm%d",iarm));
		heff_y_int_w_pp[iarm][0] = (TH1F*)infile1_pp->Get(Form("heff_yy_int_w_pp_set0_arm%d",iarm));
		heff_y_int_w_pp[iarm][1] = (TH1F*)infile1_pp->Get(Form("heff_yy_int_w_pp_set1_arm%d",iarm));

		for (int iy=0; iy<nybin; iy++){
			eff_y_pp[iarm][iy] = heff_y_w_pp[iarm]->GetBinContent(iy+1);
			cout << "pp ARM: " << iarm << ", Y: " << iy << ", eff0: " << eff_y_pp[iarm][iy] << endl;
		}

		eff_y_int_pp[iarm][0] = (heff_y_int_w_pp[iarm][0]->GetBinContent(1));
		eff_y_int_pp[iarm][1] = (heff_y_int_w_pp[iarm][1]->GetBinContent(1));
	}
	infile1_pp->Close();

	//return;

	TH1F *htrigeff[narm];
	TH1F *htrigeff_int[narm][2];
	TH1F *htrigeff_A[narm];
	TH1F *htrigeff_int_A[narm][2];
	TH1F *htrigeff_wt[narm];
	TH1F *htrigeff_wt_int[narm][2];
	TH1F *htrigeff_wt_A[narm];
	TH1F *htrigeff_wt_int_A[narm][2];

	TH1F *htrigeff_pAu[narm];
	TH1F *htrigeff_pAu_int[narm][2];
	TH1F *htrigeff_wt_pAu[narm];
	TH1F *htrigeff_wt_pAu_int[narm][2];

	TH1F *htrigeff_HeAu[narm];
	TH1F *htrigeff_HeAu_int[narm][2];
	TH1F *htrigeff_HeAu_A[narm];
	TH1F *htrigeff_HeAu_int_A[narm][2];
	TH1F *htrigeff_wt_HeAu[narm];
	TH1F *htrigeff_wt_HeAu_int[narm][2];
	TH1F *htrigeff_wt_HeAu_A[narm];
	TH1F *htrigeff_wt_HeAu_int_A[narm][2];

	TH1F *htrigeff_pp[narm];
	TH1F *htrigeff_pp_int[narm][2];
	TH1F *htrigeff_wt_pp[narm];
	TH1F *htrigeff_wt_pp_int[narm][2];

	double trigeff_y[narm][nybin];
	double trigeff_y_int[narm][2];
	double trigeff_y_A[narm][nybin];
	double trigeff_y_int_A[narm][2];
	double trigeff_y_pAu[narm][nybin];
	double trigeff_y_int_pAu[narm][2];
	double trigeff_y_HeAu[narm][nybin];
	double trigeff_y_int_HeAu[narm][2];
	double trigeff_y_HeAu_A[narm][nybin];
	double trigeff_y_int_HeAu_A[narm][2];
	double trigeff_y_pp[narm][nybin];
	double trigeff_y_int_pp[narm];

	TFile *infile2 = new TFile("/gpfs/mnt/gpfs02/phenix/hhj/hhj1/shlim/work/15.run15/14.acc_by_eff/01.Inclusive_Jpsi/eff_files/Run15pAl200_CENT0072_C_trigeff_MUID2D_output.root","read");
	for (int iarm=0; iarm<narm; iarm++){
		htrigeff[iarm] = (TH1F*)infile2->Get(Form("htrigeff_y_set1_arm%d",iarm));
		htrigeff_A[iarm] = (TH1F*)infile2->Get(Form("htrigeff_y_half_set1_arm%d",iarm));
		htrigeff_int[iarm][0] = (TH1F*)infile2->Get(Form("htrigeff_y_int_set0_arm%d",iarm));
		htrigeff_int[iarm][1] = (TH1F*)infile2->Get(Form("htrigeff_y_int_set1_arm%d",iarm));
		htrigeff_int_A[iarm][0] = (TH1F*)infile2->Get(Form("htrigeff_y_int_half_set0_arm%d",iarm));
		htrigeff_int_A[iarm][1] = (TH1F*)infile2->Get(Form("htrigeff_y_int_half_set1_arm%d",iarm));

		htrigeff_wt[iarm] = (TH1F*)infile2->Get(Form("htrigeff_y_wt_set1_arm%d",iarm));
		htrigeff_wt_A[iarm] = (TH1F*)infile2->Get(Form("htrigeff_y_half_wt_set1_arm%d",iarm));
		htrigeff_wt_int[iarm][0] = (TH1F*)infile2->Get(Form("htrigeff_y_int_wt_set0_arm%d",iarm));
		htrigeff_wt_int[iarm][1] = (TH1F*)infile2->Get(Form("htrigeff_y_int_wt_set1_arm%d",iarm));
		htrigeff_wt_int_A[iarm][0] = (TH1F*)infile2->Get(Form("htrigeff_y_int_half_wt_set0_arm%d",iarm));
		htrigeff_wt_int_A[iarm][1] = (TH1F*)infile2->Get(Form("htrigeff_y_int_half_wt_set1_arm%d",iarm));

		for (int iy=0; iy<nybin; iy++){
			float eff0 = htrigeff[iarm]->GetBinContent(iy+1);
			float eff1 = htrigeff_wt[iarm]->GetBinContent(iy+1);
			trigeff_y[iarm][iy] = (eff0 + eff1)/2;
			sys_trigeff_y_pAl[iarm][iy] = fabs(eff0 - eff1)/(eff0 + eff1);

			eff0 = htrigeff_A[iarm]->GetBinContent(iy+1);
			eff1 = htrigeff_wt_A[iarm]->GetBinContent(iy+1);
			trigeff_y_A[iarm][iy] = (eff0 + eff1)/2;

			cout << "pAl ARM: " << iarm << ", Y: " << iy << ", TRIG EFF: " << trigeff_y[iarm][iy] << ", TRIG EFF A: " << trigeff_y_A[iarm][iy] << ", Err: " << sys_trigeff_y_pAl[iarm][iy] << endl;

			if ( iarm==0 ){
				double F = NMB_A[iarm]/NMB[iarm];
				trigeff_y[iarm][iy] = trigeff_y[iarm][iy]*(1-F) + trigeff_y_A[iarm][iy]*F;
				cout << "TRIG EFF MOD: " << trigeff_y[iarm][iy] << endl; 
			}
		}

		for (int iset=0; iset<2; iset++){
			float eff0 = htrigeff_int[iarm][iset]->GetBinContent(1);
			float eff1 = htrigeff_wt_int[iarm][iset]->GetBinContent(1);
			trigeff_y_int[iarm][iset] = (eff0 + eff1)/2;
			if ( iset==1 ){
				sys_trigeff_pAl[iarm] = fabs(eff0 - eff1)/(eff0 + eff1);
			}

			eff0 = htrigeff_int_A[iarm][iset]->GetBinContent(1);
			eff1 = htrigeff_wt_int_A[iarm][iset]->GetBinContent(1);
			trigeff_y_int_A[iarm][iset] = (eff0 + eff1)/2;
			if ( iarm==0 ){
				double F = NMB_A[iarm]/NMB[iarm];
				trigeff_y_int[iarm][iset] = trigeff_y_int[iarm][iset]*(1-F) + trigeff_y_int_A[iarm][iset]*F;
			}
		}
	}
	infile2->Close();

	//return;

	TFile *infile2_pAu = new TFile("/gpfs/mnt/gpfs02/phenix/hhj/hhj1/shlim/work/15.run15/14.acc_by_eff/01.Inclusive_Jpsi/eff_files/Run15pAu200_CENT0084_C_trigeff_MUID2D_output.root","read");
	for (int iarm=0; iarm<narm; iarm++){
		htrigeff_pAu[iarm] = (TH1F*)infile2_pAu->Get(Form("htrigeff_y_set1_arm%d",iarm));
		htrigeff_pAu_int[iarm][0] = (TH1F*)infile2_pAu->Get(Form("htrigeff_y_int_set0_arm%d",iarm));
		htrigeff_pAu_int[iarm][1] = (TH1F*)infile2_pAu->Get(Form("htrigeff_y_int_set1_arm%d",iarm));

		htrigeff_wt_pAu[iarm] = (TH1F*)infile2_pAu->Get(Form("htrigeff_y_wt_set1_arm%d",iarm));
		htrigeff_wt_pAu_int[iarm][0] = (TH1F*)infile2_pAu->Get(Form("htrigeff_y_int_wt_set0_arm%d",iarm));
		htrigeff_wt_pAu_int[iarm][1] = (TH1F*)infile2_pAu->Get(Form("htrigeff_y_int_wt_set1_arm%d",iarm));

		for (int iy=0; iy<nybin; iy++){
			float eff0 = htrigeff_pAu[iarm]->GetBinContent(iy+1);
			float eff1 = htrigeff_wt_pAu[iarm]->GetBinContent(iy+1);
			trigeff_y_pAu[iarm][iy] = (eff0 + eff1)/2;
			sys_trigeff_y_pAu[iarm][iy] = fabs(eff0 - eff1)/(eff0 + eff1);

			cout << "pAu ARM: " << iarm << ", Y: " << iy << ", TRIG EFF: " << trigeff_y_pAu[iarm][iy] << ", Err: " << sys_trigeff_y_pAu[iarm][iy] << endl;
		}

		for (int iset=0; iset<2; iset++){
			float eff0 = htrigeff_pAu_int[iarm][iset]->GetBinContent(1);
			float eff1 = htrigeff_wt_pAu_int[iarm][iset]->GetBinContent(1);

			trigeff_y_int_pAu[iarm][iset] = (eff0 + eff1)/2;
			if ( iset==1 ){
				sys_trigeff_pAu[iarm] = fabs(eff0 - eff1)/(eff0 + eff1);
			}
		}
	}
	infile2_pAu->Close();

	TFile *infile2_HeAu = new TFile("/gpfs/mnt/gpfs02/phenix/hhj/hhj1/shlim/work/15.run15/14.acc_by_eff/01.Inclusive_Jpsi/eff_files/Run14HeAu200_CENT0088_B_trigeff_MUID2D_output.root","read");
	TFile *infile2_HeAu_A = new TFile("/gpfs/mnt/gpfs02/phenix/hhj/hhj1/shlim/work/15.run15/14.acc_by_eff/01.Inclusive_Jpsi/eff_files/Run14HeAu200_CENT0088_A_trigeff_MUID2D_output.root","read");
	for (int iarm=0; iarm<narm; iarm++){
		htrigeff_HeAu[iarm] = (TH1F*)infile2_HeAu->Get(Form("htrigeff_y_set1_arm%d",iarm));
		htrigeff_HeAu_A[iarm] = (TH1F*)infile2_HeAu_A->Get(Form("htrigeff_y_set1_arm%d",iarm));
		htrigeff_HeAu_int[iarm][0] = (TH1F*)infile2_HeAu->Get(Form("htrigeff_y_int_set0_arm%d",iarm));
		htrigeff_HeAu_int[iarm][1] = (TH1F*)infile2_HeAu->Get(Form("htrigeff_y_int_set1_arm%d",iarm));
		htrigeff_HeAu_int_A[iarm][0] = (TH1F*)infile2_HeAu_A->Get(Form("htrigeff_y_int_set0_arm%d",iarm));
		htrigeff_HeAu_int_A[iarm][1] = (TH1F*)infile2_HeAu_A->Get(Form("htrigeff_y_int_set1_arm%d",iarm));

		htrigeff_wt_HeAu[iarm] = (TH1F*)infile2_HeAu->Get(Form("htrigeff_y_wt_set1_arm%d",iarm));
		htrigeff_wt_HeAu_A[iarm] = (TH1F*)infile2_HeAu_A->Get(Form("htrigeff_y_wt_set1_arm%d",iarm));
		htrigeff_wt_HeAu_int[iarm][0] = (TH1F*)infile2_HeAu->Get(Form("htrigeff_y_int_wt_set0_arm%d",iarm));
		htrigeff_wt_HeAu_int[iarm][1] = (TH1F*)infile2_HeAu->Get(Form("htrigeff_y_int_wt_set1_arm%d",iarm));
		htrigeff_wt_HeAu_int_A[iarm][0] = (TH1F*)infile2_HeAu_A->Get(Form("htrigeff_y_int_wt_set0_arm%d",iarm));
		htrigeff_wt_HeAu_int_A[iarm][1] = (TH1F*)infile2_HeAu_A->Get(Form("htrigeff_y_int_wt_set1_arm%d",iarm));

		for (int iy=0; iy<nybin; iy++){
			float eff0 = htrigeff_HeAu[iarm]->GetBinContent(iy+1);
			float eff1 = htrigeff_wt_HeAu[iarm]->GetBinContent(iy+1);
			trigeff_y_HeAu[iarm][iy] = (eff0 + eff1)/2;
			sys_trigeff_y_HeAu[iarm][iy] = fabs(eff0 - eff1)/(eff0 + eff1);

			eff0 = htrigeff_HeAu_A[iarm]->GetBinContent(iy+1);
			eff1 = htrigeff_wt_HeAu_A[iarm]->GetBinContent(iy+1);
			trigeff_y_HeAu_A[iarm][iy] = (eff0 + eff1)/2;

			cout << "HeAu ARM: " << iarm << ", Y: " << iy << ", TRIG EFF: " << trigeff_y_HeAu[iarm][iy] << ", TRIG EFF A: " << trigeff_y_HeAu_A[iarm][iy] << ", Err: " << sys_trigeff_y_HeAu[iarm][iy] << endl;

			double F = NMB_HeAu_A[iarm]/NMB_HeAu[iarm];
			trigeff_y_HeAu[iarm][iy] = trigeff_y_HeAu[iarm][iy]*(1-F) + trigeff_y_HeAu_A[iarm][iy]*F;
			cout << "TRIG EFF MOD: " << trigeff_y_HeAu[iarm][iy] << endl; 
		}

		for (int iset=0; iset<2; iset++){
			float eff0 = htrigeff_HeAu_int[iarm][iset]->GetBinContent(1);
			float eff1 = htrigeff_wt_HeAu_int[iarm][iset]->GetBinContent(1);
			trigeff_y_int_HeAu[iarm][iset] = (eff0 + eff1)/2;

			eff0 = htrigeff_HeAu_int_A[iarm][iset]->GetBinContent(1);
			eff1 = htrigeff_wt_HeAu_int_A[iarm][iset]->GetBinContent(1);
			trigeff_y_int_HeAu_A[iarm][iset] = (eff0 + eff1)/2;

			double F = NMB_HeAu_A[iarm]/NMB_HeAu[iarm];
			trigeff_y_int_HeAu[iarm][iset] = trigeff_y_int_HeAu[iarm][iset]*(1-F) + trigeff_y_int_HeAu_A[iarm][iset]*F;
		}
	}
	infile2_HeAu->Close();
	infile2_HeAu_A->Close();


	TFile *infile2_pp = new TFile("/gpfs/mnt/gpfs02/phenix/hhj/hhj1/shlim/work/15.run15/14.acc_by_eff/01.Inclusive_Jpsi/eff_files/Run15pp200_C_trigeff_MUID2D_output.root","read");
	for (int iarm=0; iarm<narm; iarm++){
		htrigeff_pp[iarm] = (TH1F*)infile2_pp->Get(Form("htrigeff_y_w_pp_set1_arm%d",iarm));
		htrigeff_wt_pp[iarm] = (TH1F*)infile2_pp->Get(Form("htrigeff_y_wt_w_pp_set1_arm%d",iarm));
		htrigeff_pp_int[iarm][0] = (TH1F*)infile2_pp->Get(Form("htrigeff_y_int_w_pp_set0_arm%d",iarm));
		htrigeff_pp_int[iarm][1] = (TH1F*)infile2_pp->Get(Form("htrigeff_y_int_w_pp_set1_arm%d",iarm));
		htrigeff_wt_pp_int[iarm][0] = (TH1F*)infile2_pp->Get(Form("htrigeff_y_int_wt_w_pp_set0_arm%d",iarm));
		htrigeff_wt_pp_int[iarm][1] = (TH1F*)infile2_pp->Get(Form("htrigeff_y_int_wt_w_pp_set1_arm%d",iarm));

		for (int iy=0; iy<nybin; iy++){
			float eff0 = htrigeff_pp[iarm]->GetBinContent(iy+1);
			float eff1 = htrigeff_wt_pp[iarm]->GetBinContent(iy+1);

			trigeff_y_pp[iarm][iy] = (eff0 + eff1)/2;
			sys_trigeff_y_pp[iarm][iy] = fabs(eff0 - eff1)/(eff0 + eff1);

			cout << "pp ARM: " << iarm << ", Y: " << iy << ", TRIG EFF: " << trigeff_y_pp[iarm][iy] << ", Err: " << sys_trigeff_y_pp[iarm][iy] << endl;
		}

		float eff0 = htrigeff_pp_int[iarm][1]->GetBinContent(1);
		float eff1 = htrigeff_wt_pp_int[iarm][1]->GetBinContent(1);

		trigeff_y_int_pp[iarm] = (eff0 + eff1)/2;
		sys_trigeff_pp[iarm] = fabs(eff0 - eff1)/(eff0 + eff1);
	}
	infile2_pp->Close();

	//return;

	double Y_pp[narm][nybin], Y_pp_err[narm][nybin], Y_pp_syserr[narm][nybin];
	double Y_dAu[narm][nybin], Y_dAu_errA[narm][nybin], Y_dAu_errB[narm][nybin];
	for (int iy=0; iy<nybin; iy++){
		Y_pp[0][iy] = rap_pp_y[3-iy];
		Y_pp[1][iy] = rap_pp_y[7+iy];
		Y_pp_err[0][iy] = rap_pp_e1[3-iy];
		Y_pp_err[1][iy] = rap_pp_e1[7+iy];
		Y_pp_syserr[0][iy] = rap_pp_e2[3-iy];
		Y_pp_syserr[1][iy] = rap_pp_e2[7+iy];

		Y_dAu[0][iy] = rap_dAu_y[3-iy];
		Y_dAu[1][iy] = rap_dAu_y[7+iy];
		Y_dAu_errA[0][iy] = rap_dAu_eA[3-iy];
		Y_dAu_errA[1][iy] = rap_dAu_eA[7+iy];
	}

	double Xec_pp15[narm][nybin], Xec_pp15_err[narm][nybin], Xec_pp15_syserr[narm][nybin];
	double Y_pp15[narm][nybin], Y_pp15_err[narm][nybin], Y_pp15_syserr[narm][nybin];
	double Y[narm][nybin], Y_err[narm][nybin], Y_syserr[narm][nybin];
	double Y_pAu[narm][nybin], Y_pAu_err[narm][nybin], Y_pAu_syserr[narm][nybin];
	double Y_HeAu[narm][nybin], Y_HeAu_err[narm][nybin], Y_HeAu_syserr[narm][nybin];
	double rpA[narm][nybin], rpA_err[narm][nybin], rpA_syserr[narm][nybin];
	double rpA_pAu[narm][nybin], rpA_pAu_err[narm][nybin], rpA_pAu_syserr[narm][nybin];
	double rpA_HeAu[narm][nybin], rpA_HeAu_err[narm][nybin], rpA_HeAu_syserr[narm][nybin];

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

			Y[iarm][iy] = Njpsi[iarm][iy] / NMB[iarm] / 0.25 / Ncoll * BiasF / eff_y[iarm][iy] / trigeff_y[iarm][iy];
			Y_err[iarm][iy] = Njpsi_err[iarm][iy] / NMB[iarm] / 0.25 / Ncoll * BiasF / eff_y[iarm][iy] / trigeff_y[iarm][iy];
			Y_syserr[iarm][iy] = sys_fit_pAl[iarm]*sys_fit_pAl[iarm];
			Y_syserr[iarm][iy] += sys_var_pAl[iarm]*sys_var_pAl[iarm];
			Y_syserr[iarm][iy] += sys_acceff_pAl[iarm]*sys_acceff_pAl[iarm];
			Y_syserr[iarm][iy] += sys_trigeff_y_pAl[iarm][iy]*sys_trigeff_y_pAl[iarm][iy];
			Y_syserr[iarm][iy] = Y[iarm][iy] * sqrt(Y_syserr[iarm][iy]); 

			Y_pAu[iarm][iy] = Njpsi_pAu[iarm][iy] / NMB_pAu[iarm] / 0.25 / Ncoll_pAu * BiasF_pAu / eff_y_pAu[iarm][iy] / trigeff_y_pAu[iarm][iy];
			Y_pAu_err[iarm][iy] = Njpsi_pAu_err[iarm][iy] / NMB_pAu[iarm] / 0.25 / Ncoll_pAu * BiasF_pAu / eff_y_pAu[iarm][iy] / trigeff_y_pAu[iarm][iy];
			Y_pAu_syserr[iarm][iy] = sys_fit_pAu[iarm]*sys_fit_pAu[iarm];
			Y_pAu_syserr[iarm][iy] += sys_var_pAu[iarm]*sys_var_pAu[iarm];
			Y_pAu_syserr[iarm][iy] += sys_acceff_pAu[iarm]*sys_acceff_pAu[iarm];
			Y_pAu_syserr[iarm][iy] += sys_trigeff_y_pAu[iarm][iy]*sys_trigeff_y_pAu[iarm][iy];
			Y_pAu_syserr[iarm][iy] = Y_pAu[iarm][iy] * sqrt(Y_pAu_syserr[iarm][iy]); 

			Y_HeAu[iarm][iy] = Njpsi_HeAu[iarm][iy] / NMB_HeAu[iarm] / 0.25 / Ncoll_HeAu * BiasF_HeAu / eff_y_HeAu[iarm][iy] / trigeff_y_HeAu[iarm][iy];
			Y_HeAu_err[iarm][iy] = Njpsi_HeAu_err[iarm][iy] / NMB_HeAu[iarm] / 0.25 / Ncoll_HeAu * BiasF_HeAu / eff_y_HeAu[iarm][iy] / trigeff_y_HeAu[iarm][iy];
			Y_HeAu_syserr[iarm][iy] = sys_fit_HeAu[iarm]*sys_fit_HeAu[iarm];
			Y_HeAu_syserr[iarm][iy] += sys_var_HeAu[iarm]*sys_var_HeAu[iarm];
			Y_HeAu_syserr[iarm][iy] += sys_acceff_HeAu[iarm]*sys_acceff_HeAu[iarm];
			Y_HeAu_syserr[iarm][iy] += sys_trigeff_y_HeAu[iarm][iy]*sys_trigeff_y_HeAu[iarm][iy];
			Y_HeAu_syserr[iarm][iy] = Y_HeAu[iarm][iy] * sqrt(Y_HeAu_syserr[iarm][iy]); 

			rpA[iarm][iy] = Y[iarm][iy] / Y_pp15[iarm][iy];
			float err0 = Y_pp15_err[iarm][iy]/Y_pp15[iarm][iy];
			float err1 = Y_err[iarm][iy]/Y[iarm][iy];
			//TypeA err
			rpA_err[iarm][iy] = rpA[iarm][iy]*sqrt(err0*err0 + err1*err1 + sys_fit_pp[iarm]*sys_fit_pp[iarm] + sys_fit_pAl[iarm]*sys_fit_pAl[iarm]); 
			//TypeB err
			err0 = sqrt(sys_var_pp[iarm]*sys_var_pp[iarm] + sys_acceff_pp[iarm]*sys_acceff_pp[iarm] + sys_trigeff_y_pp[iarm][iy]*sys_trigeff_y_pp[iarm][iy] + sys_corrbkg_pp[iarm]*sys_corrbkg_pp[iarm]);
			err1 = sqrt(sys_var_pAl[iarm]*sys_var_pAl[iarm] + sys_acceff_pAl[iarm]*sys_acceff_pAl[iarm] + sys_trigeff_y_pAl[iarm][iy]*sys_trigeff_y_pAl[iarm][iy]);
			rpA_syserr[iarm][iy] = rpA[iarm][iy]*sqrt(err0*err0 + err1*err1);

			rpA_pAu[iarm][iy] = Y_pAu[iarm][iy] / Y_pp15[iarm][iy];
			err0 = Y_pp15_err[iarm][iy]/Y_pp15[iarm][iy];
			err1 = Y_pAu_err[iarm][iy]/Y_pAu[iarm][iy];
			//TypeA err
			rpA_pAu_err[iarm][iy] = rpA_pAu[iarm][iy]*sqrt(err0*err0 + err1*err1 +sys_fit_pp[iarm]*sys_fit_pp[iarm] + sys_fit_pAu[iarm]*sys_fit_pAu[iarm]); 
			//TypeB err
			err0 = sqrt(sys_var_pp[iarm]*sys_var_pp[iarm] + sys_acceff_pp[iarm]*sys_acceff_pp[iarm] + sys_trigeff_y_pp[iarm][iy]*sys_trigeff_y_pp[iarm][iy] + sys_corrbkg_pp[iarm]*sys_corrbkg_pp[iarm]);
			err1 = sqrt(sys_var_pAu[iarm]*sys_var_pAu[iarm] + sys_acceff_pAu[iarm]*sys_acceff_pAu[iarm] + sys_trigeff_y_pAu[iarm][iy]*sys_trigeff_y_pAu[iarm][iy]);
			rpA_pAu_syserr[iarm][iy] = rpA_pAu[iarm][iy]*sqrt(err0*err0 + err1*err1);

			rpA_HeAu[iarm][iy] = Y_HeAu[iarm][iy] / Y_pp15[iarm][iy];
			err0 = Y_pp15_err[iarm][iy]/Y_pp15[iarm][iy];
			err1 = Y_HeAu_err[iarm][iy]/Y_HeAu[iarm][iy];
			//TypeA err
			rpA_HeAu_err[iarm][iy] = rpA_HeAu[iarm][iy]*sqrt(err0*err0 + err1*err1 + sys_fit_pp[iarm]*sys_fit_pp[iarm] + sys_fit_HeAu[iarm]*sys_fit_HeAu[iarm]); 
			//TypeB err
			err0 = sqrt(sys_var_pp[iarm]*sys_var_pp[iarm] + sys_acceff_pp[iarm]*sys_acceff_pp[iarm] + sys_trigeff_y_pp[iarm][iy]*sys_trigeff_y_pp[iarm][iy] + sys_corrbkg_pp[iarm]*sys_corrbkg_pp[iarm]);
			err1 = sqrt(sys_var_HeAu[iarm]*sys_var_HeAu[iarm] + sys_acceff_HeAu[iarm]*sys_acceff_HeAu[iarm] + sys_trigeff_y_HeAu[iarm][iy]*sys_trigeff_y_HeAu[iarm][iy]);
			rpA_HeAu_syserr[iarm][iy] = rpA_HeAu[iarm][iy]*sqrt(err0*err0 + err1*err1);
		}
	}

	//return;

	TGraphErrors *gy_pp15[narm];
	TGraphErrors *gy_pp15_sys[narm];
	TGraphErrors *gy_xec_pp15[narm];
	TGraphErrors *gy_xec_pp15_sys[narm];
	TGraphErrors *gy[narm];
	TGraphErrors *gy_sys[narm];
	TGraphErrors *gy_pAu[narm];
	TGraphErrors *gy_pAu_sys[narm];
	TGraphErrors *gy_HeAu[narm];
	TGraphErrors *gy_HeAu_sys[narm];
	TGraphErrors *gR[narm];
	TGraphErrors *gR_sys[narm];
	TGraphErrors *gR_pAu[narm];
	TGraphErrors *gR_pAu_sys[narm];
	TGraphErrors *gR_HeAu[narm];
	TGraphErrors *gR_HeAu_sys[narm];
	for (int iarm=0; iarm<narm; iarm++){
		gy_pp15[iarm] = new TGraphErrors(nybin, &xx[iarm][0], &Y_pp15[iarm][0], 0, &Y_pp15_err[iarm][0]);
		gy_pp15[iarm]->SetMarkerStyle(20);
		gy_pp15[iarm]->SetMarkerColor(1);
		gy_pp15[iarm]->SetLineWidth(2);
		gy_pp15[iarm]->SetLineColor(1);

		gy_pp15_sys[iarm] = new TGraphErrors(nybin, &xx[iarm][0], &Y_pp15[iarm][0], &xx_err[iarm][0], &Y_pp15_syserr[iarm][0]);
		gy_pp15_sys[iarm]->SetMarkerStyle(20);
		gy_pp15_sys[iarm]->SetMarkerColor(1);
		gy_pp15_sys[iarm]->SetLineWidth(2);
		gy_pp15_sys[iarm]->SetLineColor(1);
		gy_pp15_sys[iarm]->SetFillStyle(0);

		gy_xec_pp15[iarm] = new TGraphErrors(nybin, &xx[iarm][0], &Xec_pp15[iarm][0], 0, &Xec_pp15_err[iarm][0]);
		gy_xec_pp15[iarm]->SetMarkerStyle(24);
		gy_xec_pp15[iarm]->SetMarkerColor(2);
		gy_xec_pp15[iarm]->SetLineWidth(2);
		gy_xec_pp15[iarm]->SetLineColor(2);

		gy_xec_pp15_sys[iarm] = new TGraphErrors(nybin, &xx[iarm][0], &Xec_pp15[iarm][0], &xx_err[iarm][0], &Xec_pp15_syserr[iarm][0]);
		gy_xec_pp15_sys[iarm]->SetMarkerStyle(24);
		gy_xec_pp15_sys[iarm]->SetMarkerColor(2);
		gy_xec_pp15_sys[iarm]->SetLineWidth(2);
		gy_xec_pp15_sys[iarm]->SetLineColor(2);
		gy_xec_pp15_sys[iarm]->SetFillStyle(0);

		gy[iarm] = new TGraphErrors(nybin, &xx[iarm][0], &Y[iarm][0], 0, &Y_err[iarm][0]);
		gy[iarm]->SetMarkerStyle(20);
		gy[iarm]->SetMarkerColor(2);
		gy[iarm]->SetLineWidth(2);
		gy[iarm]->SetLineColor(2);

		gy_sys[iarm] = new TGraphErrors(nybin, &xx[iarm][0], &Y[iarm][0], &xx_err[iarm][0], &Y_syserr[iarm][0]);
		gy_sys[iarm]->SetMarkerStyle(20);
		gy_sys[iarm]->SetMarkerColor(2);
		gy_sys[iarm]->SetLineWidth(2);
		gy_sys[iarm]->SetLineColor(2);
		gy_sys[iarm]->SetFillStyle(0);

		gy_pAu[iarm] = new TGraphErrors(nybin, &xx[iarm][0], &Y_pAu[iarm][0], 0, &Y_pAu_err[iarm][0]);
		gy_pAu[iarm]->SetMarkerStyle(20);
		gy_pAu[iarm]->SetMarkerColor(kGreen+3);
		gy_pAu[iarm]->SetLineWidth(2);
		gy_pAu[iarm]->SetLineColor(kGreen+3);

		gy_pAu_sys[iarm] = new TGraphErrors(nybin, &xx[iarm][0], &Y_pAu[iarm][0], &xx_err[iarm][0], &Y_pAu_syserr[iarm][0]);
		gy_pAu_sys[iarm]->SetMarkerStyle(20);
		gy_pAu_sys[iarm]->SetMarkerColor(kGreen+3);
		gy_pAu_sys[iarm]->SetLineWidth(2);
		gy_pAu_sys[iarm]->SetLineColor(kGreen+3);
		gy_pAu_sys[iarm]->SetFillStyle(0);

		gy_HeAu[iarm] = new TGraphErrors(nybin, &xx[iarm][0], &Y_HeAu[iarm][0], 0, &Y_HeAu_err[iarm][0]);
		gy_HeAu[iarm]->SetMarkerStyle(20);
		gy_HeAu[iarm]->SetMarkerColor(kMagenta+1);
		gy_HeAu[iarm]->SetLineWidth(2);
		gy_HeAu[iarm]->SetLineColor(kMagenta+1);

		gy_HeAu_sys[iarm] = new TGraphErrors(nybin, &xx[iarm][0], &Y_HeAu[iarm][0], &xx_err[iarm][0], &Y_HeAu_syserr[iarm][0]);
		gy_HeAu_sys[iarm]->SetMarkerStyle(20);
		gy_HeAu_sys[iarm]->SetMarkerColor(kMagenta+1);
		gy_HeAu_sys[iarm]->SetLineWidth(2);
		gy_HeAu_sys[iarm]->SetLineColor(kMagenta+1);
		gy_HeAu_sys[iarm]->SetFillStyle(0);

		gR[iarm] = new TGraphErrors(nybin, &xx[iarm][0], &rpA[iarm][0], 0, &rpA_err[iarm][0]);
		gR[iarm]->SetMarkerStyle(20);
		gR[iarm]->SetMarkerColor(2);
		gR[iarm]->SetLineWidth(2);
		gR[iarm]->SetLineColor(2);

		gR_sys[iarm] = new TGraphErrors(nybin, &xx[iarm][0], &rpA[iarm][0], &xx_err[iarm][0], &rpA_syserr[iarm][0]);
		gR_sys[iarm]->SetMarkerStyle(20);
		gR_sys[iarm]->SetMarkerColor(2);
		gR_sys[iarm]->SetLineWidth(2);
		gR_sys[iarm]->SetLineColor(2);
		gR_sys[iarm]->SetFillStyle(0);

		gR_pAu[iarm] = new TGraphErrors(nybin, &xx[iarm][0], &rpA_pAu[iarm][0], 0, &rpA_pAu_err[iarm][0]);
		gR_pAu[iarm]->SetMarkerStyle(20);
		gR_pAu[iarm]->SetMarkerColor(kGreen+3);
		gR_pAu[iarm]->SetLineWidth(2);
		gR_pAu[iarm]->SetLineColor(kGreen+3);

		gR_pAu_sys[iarm] = new TGraphErrors(nybin, &xx[iarm][0], &rpA_pAu[iarm][0], &xx_err[iarm][0], &rpA_pAu_syserr[iarm][0]);
		gR_pAu_sys[iarm]->SetMarkerStyle(20);
		gR_pAu_sys[iarm]->SetMarkerColor(kGreen+3);
		gR_pAu_sys[iarm]->SetLineWidth(2);
		gR_pAu_sys[iarm]->SetLineColor(kGreen+3);
		gR_pAu_sys[iarm]->SetFillStyle(0);

		gR_HeAu[iarm] = new TGraphErrors(nybin, &xx[iarm][0], &rpA_HeAu[iarm][0], 0, &rpA_HeAu_err[iarm][0]);
		gR_HeAu[iarm]->SetMarkerStyle(20);
		gR_HeAu[iarm]->SetMarkerColor(kMagenta+1);
		gR_HeAu[iarm]->SetLineWidth(2);
		gR_HeAu[iarm]->SetLineColor(kMagenta+1);

		gR_HeAu_sys[iarm] = new TGraphErrors(nybin, &xx[iarm][0], &rpA_HeAu[iarm][0], &xx_err[iarm][0], &rpA_HeAu_syserr[iarm][0]);
		gR_HeAu_sys[iarm]->SetMarkerStyle(20);
		gR_HeAu_sys[iarm]->SetMarkerColor(kMagenta+1);
		gR_HeAu_sys[iarm]->SetLineWidth(2);
		gR_HeAu_sys[iarm]->SetLineColor(kMagenta+1);
		gR_HeAu_sys[iarm]->SetFillStyle(0);

		cpp->cd(1);
		gy_pp15_sys[iarm]->Draw("2");
		gy_pp15[iarm]->Draw("p");

		cpp->cd(2);
		gy_pp15_sys[iarm]->Draw("2");
		gy_pp15[iarm]->Draw("p");

		cpp0->cd(1);
		gy_xec_pp15_sys[iarm]->Draw("2");
		gy_xec_pp15[iarm]->Draw("p");

		cpp0->cd(2);
		gy_xec_pp15_sys[iarm]->Draw("2");
		gy_xec_pp15[iarm]->Draw("p");

		//c0->cd();
		//gy[iarm]->Draw("p");
		//gy_pAu[iarm]->Draw("p");
		//gy_HeAu[iarm]->Draw("p");

		//c1->cd();
		//gR_pAu[iarm]->Draw("p");
		//gR_HeAu[iarm]->Draw("p");

	}//iarm

	cpp0->cd(1);
	TLegend *leg = new TLegend(0.25,0.7,0.9,0.9);
	leg->SetFillStyle(0);
	leg->AddEntry("","p+p #sqrt{s}=200 GeV","");
	leg->AddEntry(gpp_xec,"2006+2008 (PPG104)","p");
	leg->AddEntry(gy_xec_pp15[0],"2015","p");
	leg->Draw();

	cpp0->cd(2);
	leg->Draw();

	//return;

	TCanvas *c10 = new TCanvas("c10","c10",1.1*2*400,2*400);
	c10->Divide(2,2);
	c10->cd(1);
	SetPadStyle();
	htmp = (TH1F*)gPad->DrawFrame(-3,0,3,1.4e-6);
	SetHistoStyle("y","B_{ll}dN/dy");

	gy_pp15_sys[0]->Draw("2");
	gy_pp15_sys[1]->Draw("2");
	gy_pp15[0]->Draw("p");
	gy_pp15[1]->Draw("p");

	TLegend *leg = new TLegend(0.20,0.77,0.9,0.90);
	leg->SetFillStyle(0);
	entry = leg->AddEntry("","J/#psi#rightarrow#mu#mu, #sqrt{s}=200 GeV","");
	entry->SetTextSize(0.055);
	leg->AddEntry("","","");
	entry = leg->AddEntry(gy_pp15[0],"p+p","p");
	entry->SetTextSize(0.055);
	leg->Draw();

	c10->cd(2);
	SetPadStyle();
	htmp = (TH1F*)gPad->DrawFrame(-3,0,3,1.4e-6);
	SetHistoStyle("y","B_{ll}dN/dy");

	gy_sys[0]->Draw("2");
	gy_sys[1]->Draw("2");
	gy[0]->Draw("p");
	gy[1]->Draw("p");

	TLegend *leg = new TLegend(0.20,0.77,0.9,0.90);
	leg->SetFillStyle(0);
	entry = leg->AddEntry("","J/#psi#rightarrow#mu#mu, #sqrt{s_{NN}}=200 GeV","");
	entry->SetTextSize(0.055);
	leg->AddEntry("","","");
	entry = leg->AddEntry(gy[0],"p+Al/<N_{coll}^{p+Al}>","p");
	entry->SetTextSize(0.055);
	leg->Draw();

	c10->cd(3);
	SetPadStyle();
	htmp = (TH1F*)gPad->DrawFrame(-3,0,3,1.4e-6);
	SetHistoStyle("y","B_{ll}dN/dy");

	gy_pAu_sys[0]->Draw("2");
	gy_pAu_sys[1]->Draw("2");
	gy_pAu[0]->Draw("p");
	gy_pAu[1]->Draw("p");

	TLegend *leg = new TLegend(0.20,0.77,0.9,0.90);
	leg->SetFillStyle(0);
	entry = leg->AddEntry("","J/#psi#rightarrow#mu#mu, #sqrt{s_{NN}}=200 GeV","");
	entry->SetTextSize(0.055);
	leg->AddEntry("","","");
	entry = leg->AddEntry(gy_pAu[0],"p+Au/<N_{coll}^{p+Au}>","p");
	entry->SetTextSize(0.055);
	leg->Draw();

	c10->cd(4);
	SetPadStyle();
	htmp = (TH1F*)gPad->DrawFrame(-3,0,3,1.4e-6);
	SetHistoStyle("y","B_{ll}dN/dy");

	gy_HeAu_sys[0]->Draw("2");
	gy_HeAu_sys[1]->Draw("2");
	gy_HeAu[0]->Draw("p");
	gy_HeAu[1]->Draw("p");

	TLegend *leg = new TLegend(0.20,0.77,0.9,0.90);
	leg->SetFillStyle(0);
	entry = leg->AddEntry("","J/#psi#rightarrow#mu#mu, #sqrt{s_{NN}}=200 GeV","");
	entry->SetTextSize(0.055);
	leg->AddEntry("","","");
	entry = leg->AddEntry(gy_HeAu[0],"^{3}He+Au/<N_{coll}^{^{3}He+Au}>","p");
	entry->SetTextSize(0.055);
	leg->Draw();


	c1->cd(1);

	TLegend *leg = new TLegend(0.20,0.27,0.9,0.40);
	leg->SetFillStyle(0);
	leg->AddEntry("","J/#psi, #sqrt{s_{NN}}=200 GeV","");
	leg->AddEntry(grda_dAu,"d+Au","p");
	leg->Draw();

	double global_sys_y_dAu = sqrt(0.1*0.1 + Ncoll_dAu_sys*Ncoll_dAu_sys + BiasF_dAu_sys*BiasF_dAu_sys);
	TBox *sysbox_y_dAu = new TBox(2.8,1-global_sys_y_dAu,3.0,1+global_sys_y_dAu);
	sysbox_y_dAu->SetFillStyle(1);
	sysbox_y_dAu->SetFillColor(1);
	sysbox_y_dAu->Draw();

	c1->cd(2);
	SetPadStyle();
	htmp = (TH1F*)gPad->DrawFrame(-3,0,3,1.5);
	SetHistoStyle("y","R_{AB}");

	line_rap->Draw();
	gR_sys[0]->Draw("2");
	gR_sys[1]->Draw("2");
	gR[0]->Draw("p");
	gR[1]->Draw("p");

	TLegend *leg = new TLegend(0.20,0.27,0.9,0.4);
	leg->SetFillStyle(0);
	leg->AddEntry("","J/#psi, #sqrt{s_{NN}}=200 GeV","");
	leg->AddEntry(gR[0],"p+Al","p");
	leg->Draw();

	double global_sys_y_pAl = sqrt(0.1*0.1 + Ncoll_sys*Ncoll_sys + BiasF_sys*BiasF_sys);
	TBox *sysbox_y_pAl = new TBox(2.8,1-global_sys_y_pAl,3.0,1+global_sys_y_pAl);
	sysbox_y_pAl->SetFillStyle(1);
	sysbox_y_pAl->SetFillColor(2);
	sysbox_y_pAl->Draw();

	c1->cd(3);
	SetPadStyle();
	htmp = (TH1F*)gPad->DrawFrame(-3,0,3,1.5);
	SetHistoStyle("y","R_{AB}");

	line_rap->Draw();
	gR_pAu_sys[0]->Draw("2");
	gR_pAu_sys[1]->Draw("2");
	gR_pAu[0]->Draw("p");
	gR_pAu[1]->Draw("p");

	TLegend *leg = new TLegend(0.20,0.27,0.9,0.4);
	leg->SetFillStyle(0);
	leg->AddEntry("","J/#psi, #sqrt{s_{NN}}=200 GeV","");
	leg->AddEntry(gR_pAu[0],"p+Au","p");
	leg->Draw();

	double global_sys_y_pAu = sqrt(0.1*0.1 + Ncoll_pAu_sys*Ncoll_pAu_sys + BiasF_pAu_sys*BiasF_pAu_sys);
	TBox *sysbox_y_pAu = new TBox(2.8,1-global_sys_y_pAu,3.0,1+global_sys_y_pAu);
	sysbox_y_pAu->SetFillStyle(1);
	sysbox_y_pAu->SetFillColor(kGreen+3);
	sysbox_y_pAu->Draw();

	c1->cd(4);
	SetPadStyle();
	htmp = (TH1F*)gPad->DrawFrame(-3,0,3,1.5);
	SetHistoStyle("y","R_{AB}");

	line_rap->Draw();
	gR_HeAu_sys[0]->Draw("2");
	gR_HeAu_sys[1]->Draw("2");
	gR_HeAu[0]->Draw("p");
	gR_HeAu[1]->Draw("p");

	TLegend *leg = new TLegend(0.20,0.27,0.9,0.4);
	leg->SetFillStyle(0);
	leg->AddEntry("","J/#psi, #sqrt{s_{NN}}=200 GeV","");
	leg->AddEntry(gR_HeAu[0],"^{3}He+Au","p");
	leg->Draw();

	double global_sys_y_HeAu = sqrt(0.1*0.1 + Ncoll_HeAu_sys*Ncoll_HeAu_sys + BiasF_HeAu_sys*BiasF_HeAu_sys);
	TBox *sysbox_y_HeAu = new TBox(2.8,1-global_sys_y_HeAu,3.0,1+global_sys_y_HeAu);
	sysbox_y_HeAu->SetFillStyle(1);
	sysbox_y_HeAu->SetFillColor(kMagenta+1);
	sysbox_y_HeAu->Draw();

	return;

	double xx_int_err[narm] = {0.1, 0.1};
	double xx_int[narm] = {-1.7, 1.7};
	double xx_int2[narm] = {-1.9, 1.5};
	double xx_int3[narm] = {-1.5, 1.9};
	double xx_int4[narm] = {-2.1, 1.3};
	double Yint_pp[narm] = {0}, Yint_pp_err[narm] = {0}, Yint_pp_syserr[narm] = {0};
	double Yint_pp15[narm] = {0}, Yint_pp15_err[narm] = {0}, Yint_pp15_syserr[narm] = {0};
	double Y1S_pp[narm] = {0}, Y1S_pp_err[narm] = {0};
	double Y2S_pp[narm] = {0}, Y2S_pp_err[narm] = {0};

	double Yint_pAl[narm] = {0}, Yint_pAl_err[narm] = {0}, Yint_pAl_syserr[narm] = {0};
	double Y1S_pAl[narm] = {0}, Y1S_pAl_err[narm] = {0}, Y1S_pAl_syserr[narm] = {0};
	double Y2S_pAl[narm] = {0}, Y2S_pAl_err[narm] = {0}, Y2S_pAl_syserr[narm] = {0};

	double Yint_pAu[narm] = {0}, Yint_pAu_err[narm] = {0}, Yint_pAu_syserr[narm] = {0};
	double Y1S_pAu[narm] = {0}, Y1S_pAu_err[narm] = {0}, Y1S_pAu_syserr[narm] = {0};
	double Y2S_pAu[narm] = {0}, Y2S_pAu_err[narm] = {0}, Y2S_pAu_syserr[narm] = {0};

	double Yint_HeAu[narm] = {0}, Yint_HeAu_err[narm] = {0}, Yint_HeAu_syserr[narm] = {0};
	double Y1S_HeAu[narm] = {0}, Y1S_HeAu_err[narm] = {0}, Y1S_HeAu_syserr[narm] = {0};
	double Y2S_HeAu[narm] = {0}, Y2S_HeAu_err[narm] = {0}, Y2S_HeAu_syserr[narm] = {0};

	double Yint_dAu[narm] = {0}, Yint_dAu_errA[narm] = {0}, Yint_dAu_errB[narm] = {0};

	double R_pp[narm] = {0.0243, 0.0243}, R_pp_err[narm] = {0.0018, 0.0018};
	double R_pAl[narm] = {0.0137, 0.0273}, R_pAl_err[narm] = {0.0061, 0.0064};
	double R_pAu[narm] = {0.0116, 0.0238}, R_pAu_err[narm] = {0.0042, 0.0037};
	double R_HeAu[narm] = {0.0159, 0.0224}, R_HeAu_err[narm] = {0.0067, 0.0078};

	double RpA_dAu_1S[narm], RpA_dAu_1S_err[narm], RpA_dAu_1S_errB[narm];
	double RpA_1S[narm], RpA_1S_err[narm], RpA_1S_syserr[narm];
	double RpA_2S[narm], RpA_2S_err[narm], RpA_2S_syserr[narm];
	double RpA_pAu_1S[narm], RpA_pAu_1S_err[narm], RpA_pAu_1S_syserr[narm];
	double RpA_pAu_2S[narm], RpA_pAu_2S_err[narm], RpA_pAu_2S_syserr[narm];
	double RpA_HeAu_1S[narm], RpA_HeAu_1S_err[narm], RpA_HeAu_1S_syserr[narm];
	double RpA_HeAu_2S[narm], RpA_HeAu_2S_err[narm], RpA_HeAu_2S_syserr[narm];

	for (int iarm=0; iarm<narm; iarm++){
		for (int iy=0; iy<nybin; iy++){
			Yint_pp[iarm] += Y_pp[iarm][iy]*0.25;
			Yint_pp_err[iarm] += (Y_pp_err[iarm][iy]*Y_pp_err[iarm][iy]*0.25*0.25);
			Yint_pp_syserr[iarm] += Y_pp_syserr[iarm][iy]/Y_pp[iarm][iy]; 

			Yint_dAu[iarm] += Y_dAu[iarm][iy]*0.25;
			Yint_dAu_errA[iarm] += (Y_dAu_errA[iarm][iy]*Y_dAu_errA[iarm][iy]*0.25*0.25);
		}

		Yint_dAu_errA[iarm] = sqrt(Yint_dAu_errA[iarm]);
		Yint_pp_syserr[iarm] = Yint_pp_syserr[iarm]/nybin*Yint_pp[iarm];
		Yint_pp_err[iarm] = sqrt(Yint_pp_err[iarm]);

		Yint_pp15[iarm] =  (Njpsi_int_pp15[iarm]/eff_pp_trk) / (NMB_pp[iarm]/eff_pp_bbc) / 1.0 / eff_y_int_pp[iarm][1] / trigeff_y_int_pp[iarm];
		Yint_pp15_err[iarm] =  (Njpsi_int_pp15_err[iarm]/eff_pp_trk) / (NMB_pp[iarm]/eff_pp_bbc) / 1.0 / eff_y_int_pp[iarm][1] / trigeff_y_int_pp[iarm];
		Yint_pp15_syserr[iarm] = 0.15*Yint_pp15[iarm];

		cout << "ARM: " << iarm << ", PPG104 Y: " << Yint_pp[iarm]*42.0*1e6 << ", ERR: " << Yint_pp_err[iarm]*42.0*1e6 << ", SYS ERR: " << Yint_pp_syserr[iarm]*42.0*1e6 << endl;
		cout << "ARM: " << iarm << ", 2015/PPG104: " << Yint_pp15[iarm]/Yint_pp[iarm] << endl;

		Yint_pAl[iarm] =  Njpsi_int[iarm] / NMB[iarm] * BiasF / Ncoll / 1.0 / eff_y_int[iarm][1] / trigeff_y_int[iarm][1];
		Yint_pAl_err[iarm] =  Njpsi_int_err[iarm]/ NMB[iarm] * BiasF / Ncoll / 1.0 / eff_y_int[iarm][1] / trigeff_y_int[iarm][1];

		Yint_pAu[iarm] =  Njpsi_pAu_int[iarm] / NMB_pAu[iarm] * BiasF_pAu / Ncoll_pAu / 1.0 / eff_y_int_pAu[iarm][1] / trigeff_y_int_pAu[iarm][1];
		Yint_pAu_err[iarm] =  Njpsi_pAu_int_err[iarm]/ NMB_pAu[iarm] * BiasF_pAu / Ncoll_pAu / 1.0 / eff_y_int_pAu[iarm][1] / trigeff_y_int_pAu[iarm][1];

		Yint_HeAu[iarm] =  Njpsi_HeAu_int[iarm] / NMB_HeAu[iarm] * BiasF_HeAu / Ncoll_HeAu / 1.0 / eff_y_int_HeAu[iarm][1] / trigeff_y_int_HeAu[iarm][1];
		Yint_HeAu_err[iarm] =  Njpsi_HeAu_int_err[iarm]/ NMB_HeAu[iarm] * BiasF_HeAu / Ncoll_HeAu / 1.0 / eff_y_int_HeAu[iarm][1] / trigeff_y_int_HeAu[iarm][1];

		Y1S_pp[iarm] = Yint_pp15[iarm];
		Y2S_pp[iarm] = Yint_pp15[iarm] * (R_pp[iarm]);

		float err0 = Yint_pp15_err[iarm] / Yint_pp15[iarm];
		float err1 = R_pp_err[iarm] / R_pp[iarm];
		Y1S_pp_err[iarm] = Y1S_pp[iarm] * err0; 
		Y2S_pp_err[iarm] = Y2S_pp[iarm] * sqrt(err0*err0 + err1*err1); 

		Y1S_pAl[iarm] = Yint_pAl[iarm];
		Y2S_pAl[iarm] = Yint_pAl[iarm] * (R_pAl[iarm]);

		err0 = Yint_pAl_err[iarm] / Yint_pAl[iarm];
		err1 = R_pAl_err[iarm] / R_pAl[iarm];
		Y1S_pAl_err[iarm] = Y1S_pAl[iarm] * err0; 
		Y2S_pAl_err[iarm] = Y2S_pAl[iarm] * sqrt(err0*err0 + err1*err1); 

		Y1S_pAu[iarm] = Yint_pAu[iarm];
		Y2S_pAu[iarm] = Yint_pAu[iarm] * (R_pAu[iarm]);

		err0 = Yint_pAu_err[iarm] / Yint_pAu[iarm];
		err1 = R_pAu_err[iarm] / R_pAu[iarm];
		Y1S_pAu_err[iarm] = Y1S_pAu[iarm] * err0; 
		Y2S_pAu_err[iarm] = Y2S_pAu[iarm] * sqrt(err0*err0 + err1*err1); 

		Y1S_HeAu[iarm] = Yint_HeAu[iarm];
		Y2S_HeAu[iarm] = Yint_HeAu[iarm] * (R_HeAu[iarm]);

		err0 = Yint_HeAu_err[iarm] / Yint_HeAu[iarm];
		err1 = R_HeAu_err[iarm] / R_HeAu[iarm];
		Y1S_HeAu_err[iarm] = Y1S_HeAu[iarm] * err0; 
		Y2S_HeAu_err[iarm] = Y2S_HeAu[iarm] * sqrt(err0*err0 + err1*err1); 

		cout << "ARM: " << iarm << ", Y1S_pp: " << Y1S_pp[iarm] << ", ERR: " << Y1S_pp_err[iarm]/Y1S_pp[iarm] << endl;
		cout << "ARM: " << iarm << ", Y2S_pp: " << Y2S_pp[iarm] << ", ERR: " << Y2S_pp_err[iarm]/Y2S_pp[iarm] << endl;
		cout << "ARM: " << iarm << ", Y1S_pAl: " << Y1S_pAl[iarm] << ", ERR: " << Y1S_pAl_err[iarm]/Y1S_pAl[iarm] << endl;
		cout << "ARM: " << iarm << ", Y2S_pAl: " << Y2S_pAl[iarm] << ", ERR: " << Y2S_pAl_err[iarm]/Y2S_pAl[iarm] << endl;
		cout << "ARM: " << iarm << ", Y1S_pAu: " << Y1S_pAu[iarm] << ", ERR: " << Y1S_pAu_err[iarm]/Y1S_pAu[iarm] << endl;
		cout << "ARM: " << iarm << ", Y2S_pAu: " << Y2S_pAu[iarm] << ", ERR: " << Y2S_pAu_err[iarm]/Y2S_pAu[iarm] << endl;
		cout << "ARM: " << iarm << ", Y1S_HeAu: " << Y1S_HeAu[iarm] << ", ERR: " << Y1S_HeAu_err[iarm]/Y1S_HeAu[iarm] << endl;
		cout << "ARM: " << iarm << ", Y2S_HeAu: " << Y2S_HeAu[iarm] << ", ERR: " << Y2S_HeAu_err[iarm]/Y2S_HeAu[iarm] << endl;

		//return;

		//OLD pp for Run8
		RpA_dAu_1S[iarm] = Yint_dAu[iarm] / Yint_pp[iarm];
		//NEW pp for Run8
		RpA_1S[iarm] = Y1S_pAl[iarm] / Y1S_pp[iarm];
		RpA_2S[iarm] = Y2S_pAl[iarm] / Y2S_pp[iarm];
		RpA_pAu_1S[iarm] = Y1S_pAu[iarm] / Y1S_pp[iarm];
		RpA_pAu_2S[iarm] = Y2S_pAu[iarm] / Y2S_pp[iarm];
		RpA_HeAu_1S[iarm] = Y1S_HeAu[iarm] / Y1S_pp[iarm];
		RpA_HeAu_2S[iarm] = Y2S_HeAu[iarm] / Y2S_pp[iarm];

		err0 = Yint_dAu_errA[iarm]/Yint_dAu[iarm];
		err1 = Yint_pp_err[iarm]/Yint_pp[iarm];
		RpA_dAu_1S_err[iarm] = RpA_dAu_1S[iarm] * sqrt(err0*err0 + err1*err1);
		RpA_dAu_1S_errB[iarm] = (iarm==0) ? 0.078 : 0.083;
		RpA_dAu_1S_errB[iarm] *= RpA_pAu_1S[iarm];

		err0 = Y1S_pAl_err[iarm]/Y1S_pAl[iarm];
		err1 = Y1S_pp_err[iarm]/Y1S_pp[iarm];
		RpA_1S_err[iarm] = RpA_1S[iarm] * sqrt(err0*err0 + err1*err1);
		RpA_1S_syserr[iarm] = (iarm==0) ? 0.078 : 0.083;
		RpA_1S_syserr[iarm] *= RpA_1S[iarm];

		err0 = Y2S_pAl_err[iarm]/Y2S_pAl[iarm];
		err1 = Y2S_pp_err[iarm]/Y2S_pp[iarm];
		RpA_2S_err[iarm] = RpA_2S[iarm] * sqrt(err0*err0 + err1*err1);

		err0 = Y1S_pAu_err[iarm]/Y1S_pAu[iarm];
		err1 = Y1S_pp_err[iarm]/Y1S_pp[iarm];
		RpA_pAu_1S_err[iarm] = RpA_pAu_1S[iarm] * sqrt(err0*err0 + err1*err1);
		RpA_pAu_1S_syserr[iarm] = (iarm==0) ? 0.078 : 0.083;
		RpA_pAu_1S_syserr[iarm] *= RpA_pAu_1S[iarm];

		err0 = Y2S_pAu_err[iarm]/Y2S_pAu[iarm];
		err1 = Y2S_pp_err[iarm]/Y2S_pp[iarm];
		RpA_pAu_2S_err[iarm] = RpA_pAu_2S[iarm] * sqrt(err0*err0 + err1*err1);

		err0 = Y1S_HeAu_err[iarm]/Y1S_HeAu[iarm];
		err1 = Y1S_pp_err[iarm]/Y1S_pp[iarm];
		RpA_HeAu_1S_err[iarm] = RpA_HeAu_1S[iarm] * sqrt(err0*err0 + err1*err1);
		RpA_HeAu_1S_syserr[iarm] = (iarm==0) ? 0.078 : 0.083;
		RpA_HeAu_1S_syserr[iarm] *= RpA_HeAu_1S[iarm];

		err0 = Y2S_HeAu_err[iarm]/Y2S_HeAu[iarm];
		err1 = Y2S_pp_err[iarm]/Y2S_pp[iarm];
		RpA_HeAu_2S_err[iarm] = RpA_HeAu_2S[iarm] * sqrt(err0*err0 + err1*err1);

	}//iarm

	//return;

	TGraphErrors *gYint_pp104 = new TGraphErrors(2, xx_int, Yint_pp, 0, Yint_pp_err);
	gYint_pp104->SetLineWidth(2);
	gYint_pp104->SetLineColor(1);
	gYint_pp104->SetMarkerStyle(20);
	gYint_pp104->SetMarkerColor(1);

	TGraphErrors *gYint_pp104_sys = new TGraphErrors(2, xx_int, Yint_pp, xx_int_err, Yint_pp_syserr);
	gYint_pp104_sys->SetLineWidth(2);
	gYint_pp104_sys->SetLineColor(1);
	gYint_pp104_sys->SetMarkerStyle(20);
	gYint_pp104_sys->SetMarkerColor(1);
	gYint_pp104_sys->SetFillStyle(0);

	TGraphErrors *gYint_pp15 = new TGraphErrors(2, xx_int2, Yint_pp15, 0, Yint_pp15_err); 
	gYint_pp15->SetLineWidth(2);
	gYint_pp15->SetLineColor(1);
	gYint_pp15->SetMarkerStyle(24);
	gYint_pp15->SetMarkerColor(1);

	TGraphErrors *gYint_pp15_sys = new TGraphErrors(2, xx_int2, Yint_pp15, xx_int_err, Yint_pp15_syserr); 
	gYint_pp15_sys->SetLineWidth(2);
	gYint_pp15_sys->SetLineColor(2);
	gYint_pp15_sys->SetMarkerStyle(24);
	gYint_pp15_sys->SetMarkerColor(2);
	gYint_pp15_sys->SetFillStyle(0);

	TCanvas *cpp_int = new TCanvas("cpp_int","cpp_int",1.1*400,400);
	SetPadStyle();
	htmp = (TH1F*)gPad->DrawFrame(-3,0,3,1.5e-6);
	SetHistoStyle("y","B_{ll} dN/dy");

	gYint_pp104_sys->Draw("2");
	gYint_pp104->Draw("p");
	gYint_pp15_sys->Draw("2");
	gYint_pp15->SetLineColor(2);
	gYint_pp15->SetMarkerColor(2);
	gYint_pp15->Draw("p");

	TLegend *leg = new TLegend(0.3,0.7,0.9,0.85);
	leg->SetFillStyle(0);
	leg->SetBorderSize(0);
	leg->AddEntry(gYint_pp104,"PPG104","P");
	leg->AddEntry(gYint_pp15,"Run15","P");
	leg->Draw();

	return;

	TCanvas *c2 = new TCanvas("c2","c2",1.1*800,400);
	c2->Divide(2,1);
	c2->cd(1);
	SetPadStyle();
	htmp = (TH1F*)gPad->DrawFrame(-3,0,3,1.5);
	SetHistoStyle("y","R_{AB}^{#psi(1S)}");

	TGraphErrors *gR_dAu_1S_sys = new TGraphErrors(2, xx_int, RpA_dAu_1S, xx_int_err, RpA_dAu_1S_errB);
	gR_dAu_1S_sys->SetFillStyle(0);
	gR_dAu_1S_sys->SetLineWidth(2);
	gR_dAu_1S_sys->SetLineColor(1);
	gR_dAu_1S_sys->Draw("2");

	TGraphErrors *gR_dAu_1S = new TGraphErrors(2, xx_int, RpA_dAu_1S, 0, RpA_dAu_1S_err);
	gR_dAu_1S->SetMarkerStyle(20);
	gR_dAu_1S->SetMarkerColor(1);
	gR_dAu_1S->SetLineWidth(2);
	gR_dAu_1S->SetLineColor(1);
	gR_dAu_1S->Draw("p");

	TGraphErrors *gR_1S_sys = new TGraphErrors(2, xx_int2, RpA_1S, xx_int_err, RpA_1S_syserr);
	gR_1S_sys->SetMarkerStyle(20);
	gR_1S_sys->SetMarkerColor(2);
	gR_1S_sys->SetLineWidth(2);
	gR_1S_sys->SetLineColor(2);
	gR_1S_sys->SetFillStyle(0);
	gR_1S_sys->Draw("2");

	TGraphErrors *gR_1S = new TGraphErrors(2, xx_int2, RpA_1S, 0, RpA_1S_err);
	gR_1S->SetMarkerStyle(20);
	gR_1S->SetMarkerColor(2);
	gR_1S->SetLineWidth(2);
	gR_1S->SetLineColor(2);
	gR_1S->Draw("p");

	TGraphErrors *gR_pAu_1S_sys = new TGraphErrors(2, xx_int3, RpA_pAu_1S, xx_int_err, RpA_pAu_1S_syserr);
	gR_pAu_1S_sys->SetMarkerStyle(20);
	gR_pAu_1S_sys->SetMarkerColor(kGreen+3);
	gR_pAu_1S_sys->SetLineWidth(2);
	gR_pAu_1S_sys->SetLineColor(kGreen+3);
	gR_pAu_1S_sys->SetFillStyle(0);
	gR_pAu_1S_sys->Draw("2");

	TGraphErrors *gR_pAu_1S = new TGraphErrors(2, xx_int3, RpA_pAu_1S, 0, RpA_pAu_1S_err);
	gR_pAu_1S->SetMarkerStyle(20);
	gR_pAu_1S->SetMarkerColor(kGreen+3);
	gR_pAu_1S->SetLineWidth(2);
	gR_pAu_1S->SetLineColor(kGreen+3);
	gR_pAu_1S->Draw("p");

	TGraphErrors *gR_HeAu_1S_sys = new TGraphErrors(2, xx_int4, RpA_HeAu_1S, xx_int_err, RpA_HeAu_1S_syserr);
	gR_HeAu_1S_sys->SetMarkerStyle(20);
	gR_HeAu_1S_sys->SetMarkerColor(kMagenta+1);
	gR_HeAu_1S_sys->SetLineWidth(2);
	gR_HeAu_1S_sys->SetLineColor(kMagenta+1);
	gR_HeAu_1S_sys->SetFillStyle(0);
	gR_HeAu_1S_sys->Draw("2");

	TGraphErrors *gR_HeAu_1S = new TGraphErrors(2, xx_int4, RpA_HeAu_1S, 0, RpA_HeAu_1S_err);
	gR_HeAu_1S->SetMarkerStyle(20);
	gR_HeAu_1S->SetMarkerColor(kMagenta+1);
	gR_HeAu_1S->SetLineWidth(2);
	gR_HeAu_1S->SetLineColor(kMagenta+1);
	gR_HeAu_1S->Draw("p");

	TLegend *leg = new TLegend(0.3,0.20,0.9,0.35);
	leg->SetFillStyle(0);
	leg->SetNColumns(2);
	leg->AddEntry(gR_dAu_1S,"d+Au","p");
	leg->AddEntry(gR_1S,"p+Al","p");
	leg->AddEntry(gR_pAu_1S,"p+Au","p");
	leg->AddEntry(gR_HeAu_1S,"^{3}He+Au","p");
	leg->Draw();

	//return;

	//TCanvas *c3 = new TCanvas("c3","c3",1.1*400,400);
	c2->cd(2);
	SetPadStyle();
	htmp = (TH1F*)gPad->DrawFrame(-3,0,3,1.5);
	SetHistoStyle("y","R_{AB}^{#psi(2S)}");

	TGraphErrors *gR_2S = new TGraphErrors(2, xx_int2, RpA_2S, 0, RpA_2S_err);
	gR_2S->SetMarkerStyle(24);
	gR_2S->SetMarkerColor(2);
	gR_2S->SetLineWidth(2);
	gR_2S->SetLineColor(2);
	gR_2S->Draw("p");

	TGraphErrors *gR_pAu_2S = new TGraphErrors(2, xx_int3, RpA_pAu_2S, 0, RpA_pAu_2S_err);
	gR_pAu_2S->SetMarkerStyle(24);
	gR_pAu_2S->SetMarkerColor(kGreen+3);
	gR_pAu_2S->SetLineWidth(2);
	gR_pAu_2S->SetLineColor(kGreen+3);
	gR_pAu_2S->Draw("p");

	TGraphErrors *gR_HeAu_2S = new TGraphErrors(2, xx_int, RpA_HeAu_2S, 0, RpA_HeAu_2S_err);
	gR_HeAu_2S->SetMarkerStyle(24);
	gR_HeAu_2S->SetMarkerColor(kMagenta+1);
	gR_HeAu_2S->SetLineWidth(2);
	gR_HeAu_2S->SetLineColor(kMagenta+1);
	gR_HeAu_2S->Draw("p");

	TLegend *leg = new TLegend(0.45,0.20,0.8,0.45);
	leg->SetFillStyle(0);
	leg->AddEntry("","","");
	leg->AddEntry(gR_2S,"p+Al","p");
	leg->AddEntry(gR_pAu_2S,"p+Au","p");
	leg->AddEntry(gR_HeAu_2S,"^{3}He+Au","p");
	leg->Draw();

	//return;

	double Y_dAu_cent[narm][4] = {0.}, Y_dAu_cent_err[narm][4] = {0.}, Y_dAu_cent_syserr_A[narm][4] = {0.}, Y_dAu_cent_syserr_B[narm][4] = {0.};
	double rpA_dAu_cent[narm][4], rpA_dAu_cent_err[narm][4], rpA_dAu_cent_syserr[narm][4];

	for (int icent=0; icent<4; icent++){
		for (int iy=0; iy<4; iy++){
			Y_dAu_cent[0][icent] += (rap_dAu_y_cent[icent][iy]*0.25);
			Y_dAu_cent[1][icent] += (rap_dAu_y_cent[icent][7-iy]*0.25);

			Y_dAu_cent_err[0][icent] += (rap_dAu_eS_cent[icent][iy]*rap_dAu_eS_cent[icent][iy]*0.25*0.25);
			Y_dAu_cent_err[1][icent] += (rap_dAu_eS_cent[icent][7-iy]*rap_dAu_eS_cent[icent][7-iy]*0.25*0.25);

			Y_dAu_cent_syserr_A[0][icent] += (rap_dAu_eA_cent[icent][iy]*rap_dAu_eA_cent[icent][iy]*0.25*0.25);
			Y_dAu_cent_syserr_A[1][icent] += (rap_dAu_eA_cent[icent][7-iy]*rap_dAu_eA_cent[icent][7-iy]*0.25*0.25);

			Y_dAu_cent_syserr_B[0][icent] += rap_dAu_eB_cent[icent][iy]/rap_dAu_y_cent[icent][iy];
			Y_dAu_cent_syserr_B[1][icent] += rap_dAu_eB_cent[icent][7-iy]/rap_dAu_y_cent[icent][7-iy];
			//Y_dAu_cent_syserr_B[0][icent] += rap_dAu_eB_cent[icent][iy];
			//Y_dAu_cent_syserr_B[1][icent] += rap_dAu_eB_cent[icent][7-iy];
		}

		Y_dAu_cent_err[0][icent] = sqrt(Y_dAu_cent_err[0][icent]);
		Y_dAu_cent_err[1][icent] = sqrt(Y_dAu_cent_err[1][icent]);

		Y_dAu_cent_syserr_A[0][icent] = sqrt(Y_dAu_cent_syserr_A[0][icent]);
		Y_dAu_cent_syserr_A[1][icent] = sqrt(Y_dAu_cent_syserr_A[1][icent]);

		Y_dAu_cent_syserr_B[0][icent] = 0.25*Y_dAu_cent_syserr_B[0][icent]*Y_dAu_cent[0][icent];
		Y_dAu_cent_syserr_B[1][icent] = 0.25*Y_dAu_cent_syserr_B[1][icent]*Y_dAu_cent[1][icent];

		Y_dAu_cent[0][icent] /= Ncoll_dAu_cent[icent];
		Y_dAu_cent[1][icent] /= Ncoll_dAu_cent[icent];

		Y_dAu_cent_err[0][icent] /= Ncoll_dAu_cent[icent];
		Y_dAu_cent_err[1][icent] /= Ncoll_dAu_cent[icent];

		Y_dAu_cent_syserr_A[0][icent] /= Ncoll_dAu_cent[icent];
		Y_dAu_cent_syserr_A[1][icent] /= Ncoll_dAu_cent[icent];

		Y_dAu_cent_syserr_B[0][icent] /= Ncoll_dAu_cent[icent];
		Y_dAu_cent_syserr_B[1][icent] /= Ncoll_dAu_cent[icent];

		//Y_dAu_cent[0][icent] *= BiasF_dAu_cent[icent];
		//Y_dAu_cent[1][icent] *= BiasF_dAu_cent[icent];

		//Y_dAu_cent_err[0][icent] *= BiasF_dAu_cent[icent];
		//Y_dAu_cent_err[1][icent] *= BiasF_dAu_cent[icent];
	}

	double trigeff_cent[narm][3], acceff_cent[narm][3];
	double trigeff_cent_HeAu[narm][4], acceff_cent_HeAu[narm][4];
	double trigeff_cent_pAu[narm][5], acceff_cent_pAu[narm][5];

	TH1F *htrigeff_cent[narm][10];
	TH1F *htrigeff_cent_A[narm][10];
	TH1F *hacceff_cent_dAu[narm][10];
	TH1F *hacceff_cent_pp[narm][10];
	TH1F *hacceff_cent_A_dAu[narm][10];
	TH1F *hacceff_cent_A_pp[narm][10];

	TFile *ftrigeff_cent = new TFile("/gpfs/mnt/gpfs02/phenix/hhj/hhj1/shlim/work/15.run15/14.acc_by_eff/01.Inclusive_Jpsi/Run15pAl200_CCCCC_centbin_trigeff_MUID2D_output.root","read");
	for (int iarm=0; iarm<narm; iarm++){
		for (int icent=0; icent<3; icent++){
			htrigeff_cent[iarm][icent] = (TH1F*)ftrigeff_cent->Get(Form("htrigeff_y_int_cent%d_set1_arm%d",icent,iarm));
			htrigeff_cent_A[iarm][icent] = (TH1F*)ftrigeff_cent->Get(Form("htrigeff_y_int_half_cent%d_set1_arm%d",icent,iarm));

			if ( iarm==0 ){
				double F = NMB_A[iarm]/NMB[iarm];
				trigeff_cent[iarm][icent] = (1-F)*htrigeff_cent[iarm][icent]->GetBinContent(1) + F*htrigeff_cent_A[iarm][icent]->GetBinContent(1);
			}else{
				trigeff_cent[iarm][icent] = htrigeff_cent[iarm][icent]->GetBinContent(1);
			}
		}
	}
	ftrigeff_cent->Close();

	TFile *ftrigeff_cent_HeAu = new TFile("/gpfs/mnt/gpfs02/phenix/hhj/hhj1/shlim/work/15.run15/14.acc_by_eff/01.Inclusive_Jpsi/Run14HeAu200_BBBBB_centbin_trigeff_MUID2D_output.root","read");
	TFile *ftrigeff_cent_HeAu_A = new TFile("/gpfs/mnt/gpfs02/phenix/hhj/hhj1/shlim/work/15.run15/14.acc_by_eff/01.Inclusive_Jpsi/Run14HeAu200_AAAAA_centbin_trigeff_MUID2D_output.root","read");
	for (int iarm=0; iarm<narm; iarm++){
		for (int icent=0; icent<4; icent++){
			htrigeff_cent[iarm][icent] = (TH1F*)ftrigeff_cent_HeAu->Get(Form("htrigeff_y_int_cent%d_set1_arm%d",icent,iarm));
			htrigeff_cent_A[iarm][icent] = (TH1F*)ftrigeff_cent_HeAu_A->Get(Form("htrigeff_y_int_cent%d_set1_arm%d",icent,iarm));

			double F = NMB_HeAu_A[iarm]/NMB_HeAu[iarm];
			trigeff_cent_HeAu[iarm][icent] = (1-F)*htrigeff_cent[iarm][icent]->GetBinContent(1) + F*htrigeff_cent_A[iarm][icent]->GetBinContent(1);
		}
	}
	ftrigeff_cent_HeAu->Close();
	ftrigeff_cent_HeAu_A->Close();

	TFile *ftrigeff_cent_pAu = new TFile("/gpfs/mnt/gpfs02/phenix/hhj/hhj1/shlim/work/15.run15/14.acc_by_eff/01.Inclusive_Jpsi/Run15pAu200_CCCC_centbin_trigeff_MUID2D_output.root","read");
	for (int iarm=0; iarm<narm; iarm++){
		for (int icent=0; icent<4; icent++){
			htrigeff_cent[iarm][icent] = (TH1F*)ftrigeff_cent_pAu->Get(Form("htrigeff_y_int_cent%d_set1_arm%d",icent,iarm));
			trigeff_cent_pAu[iarm][icent+1] = htrigeff_cent[iarm][icent]->GetBinContent(1);
		}
		trigeff_cent_pAu[iarm][0] = trigeff_cent_pAu[iarm][1];
	}
	ftrigeff_cent_pAu->Close();

	TFile *facceff_cent = new TFile("/gpfs/mnt/gpfs02/phenix/hhj/hhj1/shlim/work/15.run15/14.acc_by_eff/01.Inclusive_Jpsi/Run15pAl200_acceff_InclusiveJpsi_CCCCC_centbin.root","read");
	for (int iarm=0; iarm<narm; iarm++){
		for (int icent=0; icent<3; icent++){
			hacceff_cent_dAu[iarm][icent] = (TH1F*)facceff_cent->Get(Form("heff_yy_int_w_dAu_cent%d_set1_arm%d",icent,iarm));
			hacceff_cent_pp[iarm][icent] = (TH1F*)facceff_cent->Get(Form("heff_yy_int_w_pp_cent%d_set1_arm%d",icent,iarm));
			hacceff_cent_A_dAu[iarm][icent] = (TH1F*)facceff_cent->Get(Form("heff_yy_int_half_w_dAu_cent%d_set1_arm%d",icent,iarm));
			hacceff_cent_A_pp[iarm][icent] = (TH1F*)facceff_cent->Get(Form("heff_yy_int_half_w_pp_cent%d_set1_arm%d",icent,iarm));

			double eff0 = 0.5*(hacceff_cent_dAu[iarm][icent]->GetBinContent(1) + hacceff_cent_pp[iarm][icent]->GetBinContent(1));
			double eff1 = 0.5*(hacceff_cent_A_dAu[iarm][icent]->GetBinContent(1) + hacceff_cent_A_pp[iarm][icent]->GetBinContent(1));

			if ( iarm==0 ){
				double F = NMB_A[iarm]/NMB[iarm];
				acceff_cent[iarm][icent] = (1-F)*eff0 + F*eff1;
			}else{
				acceff_cent[iarm][icent] = eff0;
			}
		}
	}
	facceff_cent->Close();

	TFile *facceff_cent_HeAu = new TFile("/gpfs/mnt/gpfs02/phenix/hhj/hhj1/shlim/work/15.run15/14.acc_by_eff/01.Inclusive_Jpsi/Run14HeAu200_acceff_InclusiveJpsi_BBBBB_centbin.root","read");
	TFile *facceff_cent_HeAu_A = new TFile("/gpfs/mnt/gpfs02/phenix/hhj/hhj1/shlim/work/15.run15/14.acc_by_eff/01.Inclusive_Jpsi/Run14HeAu200_acceff_InclusiveJpsi_AAAAA_centbin.root","read");
	for (int iarm=0; iarm<narm; iarm++){
		for (int icent=0; icent<4; icent++){
			hacceff_cent_dAu[iarm][icent] = (TH1F*)facceff_cent_HeAu->Get(Form("heff_yy_int_w_dAu_cent%d_set1_arm%d",icent,iarm));
			hacceff_cent_pp[iarm][icent] = (TH1F*)facceff_cent_HeAu->Get(Form("heff_yy_int_w_pp_cent%d_set1_arm%d",icent,iarm));
			hacceff_cent_A_dAu[iarm][icent] = (TH1F*)facceff_cent_HeAu_A->Get(Form("heff_yy_int_w_dAu_cent%d_set1_arm%d",icent,iarm));
			hacceff_cent_A_pp[iarm][icent] = (TH1F*)facceff_cent_HeAu_A->Get(Form("heff_yy_int_w_pp_cent%d_set1_arm%d",icent,iarm));

			double eff0 = 0.5*(hacceff_cent_dAu[iarm][icent]->GetBinContent(1) + hacceff_cent_pp[iarm][icent]->GetBinContent(1));
			double eff1 = 0.5*(hacceff_cent_A_dAu[iarm][icent]->GetBinContent(1) + hacceff_cent_A_pp[iarm][icent]->GetBinContent(1));

			double F = NMB_HeAu_A[iarm]/NMB_HeAu[iarm];
			acceff_cent_HeAu[iarm][icent] = (1-F)*eff0 + F*eff1;
		}
	}
	facceff_cent_HeAu->Close();
	facceff_cent_HeAu_A->Close();

	TFile *facceff_cent_pAu = new TFile("/gpfs/mnt/gpfs02/phenix/hhj/hhj1/shlim/work/15.run15/14.acc_by_eff/01.Inclusive_Jpsi/Run15pAu200_acceff_InclusiveJpsi_CCCC_centbin.root","read");
	for (int iarm=0; iarm<narm; iarm++){
		for (int icent=0; icent<4; icent++){
			hacceff_cent_dAu[iarm][icent] = (TH1F*)facceff_cent_pAu->Get(Form("heff_yy_int_w_dAu_cent%d_set1_arm%d",icent,iarm));
			hacceff_cent_pp[iarm][icent] = (TH1F*)facceff_cent_pAu->Get(Form("heff_yy_int_w_pp_cent%d_set1_arm%d",icent,iarm));
			acceff_cent_pAu[iarm][icent+1] = 0.5*(hacceff_cent_dAu[iarm][icent]->GetBinContent(1) + hacceff_cent_pp[iarm][icent]->GetBinContent(1));
		}
		acceff_cent_pAu[iarm][0] = acceff_cent_pAu[iarm][1];
	}
	facceff_cent_pAu->Close();


	//return;

	double Y_HeAu_cent[narm][4], Y_HeAu_cent_err[narm][4], Y_HeAu_cent_syserr[narm][4];
	double rpA_HeAu_cent[narm][4], rpA_HeAu_cent_err[narm][4], rpA_HeAu_cent_syserr[narm][4];

	double Y_pAu_cent[narm][5], Y_pAu_cent_err[narm][5], Y_pAu_cent_syserr[narm][5];
	double rpA_pAu_cent[narm][5], rpA_pAu_cent_err[narm][5], rpA_pAu_cent_syserr[narm][5];

	double Y_cent[narm][3], Y_cent_err[narm][3], Y_cent_syserr[narm][3];
	double rpA_cent[narm][3], rpA_cent_err[narm][3], rpA_cent_syserr[narm][3];

	for (int iarm=0; iarm<narm; iarm++){
		for (int icent=0; icent<4; icent++){
			double eff = acceff_cent_HeAu[iarm][icent];
			double trigeff = trigeff_cent_HeAu[iarm][icent];

			Y_HeAu_cent[iarm][icent] = Njpsi_HeAu_cent[iarm][icent] / NMB_HeAu_cent[iarm][icent] / 1.0 / Ncoll_HeAu_cent[icent] * BiasF_HeAu_cent[icent] / eff / trigeff;
			Y_HeAu_cent_err[iarm][icent] = Njpsi_HeAu_cent_err[iarm][icent] / NMB_HeAu_cent[iarm][icent] / 1.0 / Ncoll_HeAu_cent[icent] * BiasF_HeAu_cent[icent] / eff / trigeff;

			rpA_HeAu_cent[iarm][icent] = Y_HeAu_cent[iarm][icent] / Yint_pp15[iarm];
			float err0 = Yint_pp15_err[iarm]/Yint_pp15[iarm];
			float err1 = Y_HeAu_cent_err[iarm][icent]/Y_HeAu_cent[iarm][icent];
			//TypeA
			rpA_HeAu_cent_err[iarm][icent] = rpA_HeAu_cent[iarm][icent]*sqrt(err0*err0 + err1*err1 + sys_fit_pp[iarm]*sys_fit_pp[iarm] + sys_fit_HeAu[iarm]*sys_fit_HeAu[iarm]); 
			//TypeB
			err0 = sqrt(sys_var_pp[iarm]*sys_var_pp[iarm] + sys_acceff_pp[iarm]*sys_acceff_pp[iarm] + sys_trigeff_pp[iarm]*sys_trigeff_pp[iarm]);
			err1 = sqrt(sys_var_HeAu[iarm]*sys_var_HeAu[iarm] + sys_acceff_HeAu[iarm]*sys_acceff_HeAu[iarm] + sys_trigeff_HeAu[iarm]*sys_trigeff_HeAu[iarm]);
			rpA_HeAu_cent_syserr[iarm][icent] = rpA_HeAu_cent[iarm][icent]*sqrt(err0*err0 + err1*err1 + Ncoll_HeAu_cent_sys[icent]*Ncoll_HeAu_cent_sys[icent] + BiasF_HeAu_cent_sys[icent]*BiasF_HeAu_cent_sys[icent]);

			/*
			eff = acceff_cent_pAu[iarm][icent];
			trigeff = trigeff_cent_pAu[iarm][icent];

			Y_pAu_cent[iarm][icent] = Njpsi_pAu_cent[iarm][icent] / NMB_pAu_cent[iarm][icent] / 1.0 / Ncoll_pAu_cent[icent] * BiasF_pAu_cent[icent] / eff / trigeff;
			Y_pAu_cent_err[iarm][icent] = Njpsi_pAu_cent_err[iarm][icent] / NMB_pAu_cent[iarm][icent] / 1.0 / Ncoll_pAu_cent[icent] * BiasF_pAu_cent[icent] / eff / trigeff;

			rpA_pAu_cent[iarm][icent] = Y_pAu_cent[iarm][icent] / Yint_pp15[iarm];
			float err0 = Yint_pp15_err[iarm]/Yint_pp15[iarm];
			float err1 = Y_pAu_cent_err[iarm][icent]/Y_pAu_cent[iarm][icent];
			//TypeA
			rpA_pAu_cent_err[iarm][icent] = rpA_pAu_cent[iarm][icent]*sqrt(err0*err0 + err1*err1 + sys_fit_pp[iarm]*sys_fit_pp[iarm] + sys_fit_pAu[iarm]*sys_fit_pAu[iarm]); 
			//TypeB
			err0 = sqrt(sys_var_pp[iarm]*sys_var_pp[iarm] + sys_acceff_pp[iarm]*sys_acceff_pp[iarm] + sys_trigeff_pp[iarm]*sys_trigeff_pp[iarm]);
			err1 = sqrt(sys_var_pAu[iarm]*sys_var_pAu[iarm] + sys_acceff_pAu[iarm]*sys_acceff_pAu[iarm] + sys_trigeff_pAu[iarm]*sys_trigeff_pAu[iarm]);
			rpA_pAu_cent_syserr[iarm][icent] = rpA_pAu_cent[iarm][icent]*sqrt(err0*err0 + err1*err1 + Ncoll_pAu_cent_sys[icent]*Ncoll_pAu_cent_sys[icent] + BiasF_pAu_cent_sys[icent]*BiasF_pAu_cent_sys[icent]);
			*/

			//OLD p+p for d+Au
			rpA_dAu_cent[iarm][icent] = Y_dAu_cent[iarm][icent] / Yint_pp[iarm];
			err0 = Yint_pp_err[iarm]/Yint_pp[iarm];
			err1 = Y_dAu_cent_err[iarm][icent]/Y_dAu_cent[iarm][icent];
			float err2 = Y_dAu_cent_syserr_A[iarm][icent]/Y_dAu_cent[iarm][icent];  
			//TypeA
			rpA_dAu_cent_err[iarm][icent] = rpA_dAu_cent[iarm][icent]*sqrt(err0*err0 + err1*err1 + err2*err2); 
			//TypeB
			err0 = 0;
			for (int iy=0; iy<4; iy++){
				if ( iarm==0 )
					err0 += rda_dAu_eB[3-iy]/rda_dAu[3-iy];
				else
					err0 += rda_dAu_eB[7+iy]/rda_dAu[7+iy];
			}
			err1 = sqrt(Ncoll_dAu_cent_sys[icent]*Ncoll_dAu_cent_sys[icent] + BiasF_dAu_cent_sys[icent]*BiasF_dAu_cent_sys[icent]);
			rpA_dAu_cent_syserr[iarm][icent] = rpA_dAu_cent[iarm][icent]*sqrt(0.25*0.25*err0*err0 + err1*err1);
		}

		for (int icent=0; icent<5; icent++){
			double eff = acceff_cent_pAu[iarm][icent];
			double trigeff = trigeff_cent_pAu[iarm][icent];

			Y_pAu_cent[iarm][icent] = Njpsi_pAu_cent[iarm][icent] / NMB_pAu_cent[iarm][icent] / 1.0 / Ncoll_pAu_cent[icent] * BiasF_pAu_cent[icent] / eff / trigeff;
			Y_pAu_cent_err[iarm][icent] = Njpsi_pAu_cent_err[iarm][icent] / NMB_pAu_cent[iarm][icent] / 1.0 / Ncoll_pAu_cent[icent] * BiasF_pAu_cent[icent] / eff / trigeff;

			rpA_pAu_cent[iarm][icent] = Y_pAu_cent[iarm][icent] / Yint_pp15[iarm];
			float err0 = Yint_pp15_err[iarm]/Yint_pp15[iarm];
			float err1 = Y_pAu_cent_err[iarm][icent]/Y_pAu_cent[iarm][icent];
			//TypeA
			rpA_pAu_cent_err[iarm][icent] = rpA_pAu_cent[iarm][icent]*sqrt(err0*err0 + err1*err1 + sys_fit_pp[iarm]*sys_fit_pp[iarm] + sys_fit_pAu[iarm]*sys_fit_pAu[iarm]); 
			//TypeB
			err0 = sqrt(sys_var_pp[iarm]*sys_var_pp[iarm] + sys_acceff_pp[iarm]*sys_acceff_pp[iarm] + sys_trigeff_pp[iarm]*sys_trigeff_pp[iarm]);
			err1 = sqrt(sys_var_pAu[iarm]*sys_var_pAu[iarm] + sys_acceff_pAu[iarm]*sys_acceff_pAu[iarm] + sys_trigeff_pAu[iarm]*sys_trigeff_pAu[iarm]);
			rpA_pAu_cent_syserr[iarm][icent] = rpA_pAu_cent[iarm][icent]*sqrt(err0*err0 + err1*err1 + Ncoll_pAu_cent_sys[icent]*Ncoll_pAu_cent_sys[icent] + BiasF_pAu_cent_sys[icent]*BiasF_pAu_cent_sys[icent]);
		}

		for (int icent=0; icent<3; icent++){
			double eff = acceff_cent[iarm][icent];
			double trigeff = trigeff_cent[iarm][icent];

			Y_cent[iarm][icent] = Njpsi_cent[iarm][icent] / NMB_cent[iarm][icent] / 1.0 / Ncoll_cent[icent] * BiasF_cent[icent] / eff / trigeff;
			Y_cent_err[iarm][icent] = Njpsi_cent_err[iarm][icent] / NMB_cent[iarm][icent] / 1.0 / Ncoll_cent[icent] * BiasF_cent[icent] / eff / trigeff;

			rpA_cent[iarm][icent] = Y_cent[iarm][icent] / Yint_pp15[iarm];
			float err0 = Yint_pp15_err[iarm]/Yint_pp15[iarm];
			float err1 = Y_cent_err[iarm][icent]/Y_cent[iarm][icent];
			//TypeA
			rpA_cent_err[iarm][icent] = rpA_cent[iarm][icent]*sqrt(err0*err0 + err1*err1 + sys_fit_pp[iarm]*sys_fit_pp[iarm] + sys_fit_pAl[iarm]*sys_fit_pAl[iarm]); 
			//TypeB
			err0 = sqrt(sys_var_pp[iarm]*sys_var_pp[iarm] + sys_acceff_pp[iarm]*sys_acceff_pp[iarm] + sys_trigeff_pp[iarm]*sys_trigeff_pp[iarm]);
			err1 = sqrt(sys_var_pAl[iarm]*sys_var_pAl[iarm] + sys_acceff_pAl[iarm]*sys_acceff_pAl[iarm] + sys_trigeff_pAl[iarm]*sys_trigeff_pAl[iarm]);
			rpA_cent_syserr[iarm][icent] = rpA_cent[iarm][icent]*sqrt(err0*err0 + err1*err1 + BiasF_cent_sys[icent]*BiasF_cent_sys[icent] + Ncoll_cent_sys[icent]*Ncoll_cent_sys[icent]);
		}
	}


	TGraphErrors *gR_HeAu_cent[2];
	TGraphErrors *gR_HeAu_cent_sys[2];
	TGraphErrors *gR_dAu_cent[2];
	TGraphErrors *gR_dAu_cent_sys[2];
	TGraphErrors *gR_pAl_cent[2];
	TGraphErrors *gR_pAl_cent_sys[2];
	TGraphErrors *gR_pAu_cent[2];
	TGraphErrors *gR_pAu_cent_sys[2];

	TGraphErrors *gR_pAl_mult[2];
	TGraphErrors *gR_pAl_mult_sys[2];
	TGraphErrors *gR_dAu_mult[2];
	TGraphErrors *gR_dAu_mult_sys[2];
	TGraphErrors *gR_HeAu_mult[2];
	TGraphErrors *gR_HeAu_mult_sys[2];
	TGraphErrors *gR_pAu_mult[2];
	TGraphErrors *gR_pAu_mult_sys[2];

	double xx_cent_err[5] = {0.5, 0.5, 0.5, 0.5, 0.5};
	double xx_mult_err[5] = {0.5, 0.5, 0.5, 0.5, 0.5};

	for (int iarm=0; iarm<narm; iarm++){
		gR_HeAu_cent[iarm] = new TGraphErrors(4, Ncoll_HeAu_cent, &rpA_HeAu_cent[iarm][0], 0, &rpA_HeAu_cent_err[iarm][0]);
		gR_HeAu_cent[iarm]->SetMarkerStyle(20);
		gR_HeAu_cent[iarm]->SetMarkerColor(kMagenta+1);
		gR_HeAu_cent[iarm]->SetLineWidth(2);
		gR_HeAu_cent[iarm]->SetLineColor(kMagenta+1);

		gR_HeAu_cent_sys[iarm] = new TGraphErrors(4, Ncoll_HeAu_cent, &rpA_HeAu_cent[iarm][0], xx_cent_err, &rpA_HeAu_cent_syserr[iarm][0]);
		gR_HeAu_cent_sys[iarm]->SetMarkerStyle(20);
		gR_HeAu_cent_sys[iarm]->SetMarkerColor(kMagenta+1);
		gR_HeAu_cent_sys[iarm]->SetLineWidth(2);
		gR_HeAu_cent_sys[iarm]->SetLineColor(kMagenta+1);
		gR_HeAu_cent_sys[iarm]->SetFillStyle(0);

		gR_dAu_cent[iarm] = new TGraphErrors(4, Ncoll_dAu_cent, &rpA_dAu_cent[iarm][0], 0, &rpA_dAu_cent_err[iarm][0]);
		gR_dAu_cent[iarm]->SetMarkerStyle(20);
		gR_dAu_cent[iarm]->SetMarkerColor(1);
		gR_dAu_cent[iarm]->SetLineWidth(2);
		gR_dAu_cent[iarm]->SetLineColor(1);

		gR_dAu_cent_sys[iarm] = new TGraphErrors(4, Ncoll_dAu_cent, &rpA_dAu_cent[iarm][0], xx_cent_err, &rpA_dAu_cent_syserr[iarm][0]);
		gR_dAu_cent_sys[iarm]->SetMarkerStyle(20);
		gR_dAu_cent_sys[iarm]->SetMarkerColor(1);
		gR_dAu_cent_sys[iarm]->SetLineWidth(2);
		gR_dAu_cent_sys[iarm]->SetLineColor(1);
		gR_dAu_cent_sys[iarm]->SetFillStyle(0);

		gR_pAl_cent[iarm] = new TGraphErrors(3, Ncoll_cent, &rpA_cent[iarm][0], 0, &rpA_cent_err[iarm][0]);
		gR_pAl_cent[iarm]->SetMarkerStyle(20);
		gR_pAl_cent[iarm]->SetMarkerColor(2);
		gR_pAl_cent[iarm]->SetLineWidth(2);
		gR_pAl_cent[iarm]->SetLineColor(2);

		gR_pAl_cent_sys[iarm] = new TGraphErrors(3, Ncoll_cent, &rpA_cent[iarm][0], &xx_cent_err[0], &rpA_cent_syserr[iarm][0]);
		gR_pAl_cent_sys[iarm]->SetMarkerStyle(20);
		gR_pAl_cent_sys[iarm]->SetMarkerColor(2);
		gR_pAl_cent_sys[iarm]->SetLineWidth(2);
		gR_pAl_cent_sys[iarm]->SetLineColor(2);
		gR_pAl_cent_sys[iarm]->SetFillStyle(0);

		gR_pAu_cent[iarm] = new TGraphErrors(5, Ncoll_pAu_cent, &rpA_pAu_cent[iarm][0], 0, &rpA_pAu_cent_err[iarm][0]);
		gR_pAu_cent[iarm]->SetMarkerStyle(20);
		gR_pAu_cent[iarm]->SetMarkerColor(kGreen+3);
		gR_pAu_cent[iarm]->SetLineWidth(2);
		gR_pAu_cent[iarm]->SetLineColor(kGreen+3);

		gR_pAu_cent_sys[iarm] = new TGraphErrors(5, Ncoll_pAu_cent, &rpA_pAu_cent[iarm][0], xx_cent_err, &rpA_pAu_cent_syserr[iarm][0]);
		gR_pAu_cent_sys[iarm]->SetMarkerStyle(20);
		gR_pAu_cent_sys[iarm]->SetMarkerColor(kGreen+3);
		gR_pAu_cent_sys[iarm]->SetLineWidth(2);
		gR_pAu_cent_sys[iarm]->SetLineColor(kGreen+3);
		gR_pAu_cent_sys[iarm]->SetFillStyle(0);

		gR_dAu_mult[iarm] = new TGraphErrors(4, &dNch_deta_dAu_cent[iarm][0], &rpA_dAu_cent[iarm][0], 0, &rpA_dAu_cent_err[iarm][0]);
		gR_dAu_mult[iarm]->SetMarkerStyle(20);
		gR_dAu_mult[iarm]->SetMarkerColor(1);
		gR_dAu_mult[iarm]->SetLineWidth(2);
		gR_dAu_mult[iarm]->SetLineColor(1);

		gR_dAu_mult_sys[iarm] = new TGraphErrors(4, &dNch_deta_dAu_cent[iarm][0], &rpA_dAu_cent[iarm][0], xx_mult_err, &rpA_dAu_cent_syserr[iarm][0]);
		gR_dAu_mult_sys[iarm]->SetMarkerStyle(20);
		gR_dAu_mult_sys[iarm]->SetMarkerColor(1);
		gR_dAu_mult_sys[iarm]->SetLineWidth(2);
		gR_dAu_mult_sys[iarm]->SetLineColor(1);
		gR_dAu_mult_sys[iarm]->SetFillStyle(0);

		gR_pAl_mult[iarm] = new TGraphErrors(3, &dNch_deta_cent[iarm][0], &rpA_cent[iarm][0], 0, &rpA_cent_err[iarm][0]);
		gR_pAl_mult[iarm]->SetMarkerStyle(20);
		gR_pAl_mult[iarm]->SetMarkerColor(2);
		gR_pAl_mult[iarm]->SetLineWidth(2);
		gR_pAl_mult[iarm]->SetLineColor(2);

		gR_pAl_mult_sys[iarm] = new TGraphErrors(3, &dNch_deta_cent[iarm][0], &rpA_cent[iarm][0], &xx_mult_err[0], &rpA_cent_syserr[iarm][0]);
		gR_pAl_mult_sys[iarm]->SetMarkerStyle(20);
		gR_pAl_mult_sys[iarm]->SetMarkerColor(2);
		gR_pAl_mult_sys[iarm]->SetLineWidth(2);
		gR_pAl_mult_sys[iarm]->SetLineColor(2);
		gR_pAl_mult_sys[iarm]->SetFillStyle(0);

		gR_HeAu_mult[iarm] = new TGraphErrors(4, &dNch_deta_HeAu_cent[iarm][0], &rpA_HeAu_cent[iarm][0], 0, &rpA_HeAu_cent_err[iarm][0]);
		gR_HeAu_mult[iarm]->SetMarkerStyle(20);
		gR_HeAu_mult[iarm]->SetMarkerColor(kMagenta+1);
		gR_HeAu_mult[iarm]->SetLineWidth(2);
		gR_HeAu_mult[iarm]->SetLineColor(kMagenta+1);

		gR_HeAu_mult_sys[iarm] = new TGraphErrors(4, &dNch_deta_HeAu_cent[iarm][0], &rpA_HeAu_cent[iarm][0], xx_mult_err, &rpA_HeAu_cent_syserr[iarm][0]);
		gR_HeAu_mult_sys[iarm]->SetMarkerStyle(20);
		gR_HeAu_mult_sys[iarm]->SetMarkerColor(kMagenta+1);
		gR_HeAu_mult_sys[iarm]->SetLineWidth(2);
		gR_HeAu_mult_sys[iarm]->SetLineColor(kMagenta+1);
		gR_HeAu_mult_sys[iarm]->SetFillStyle(0);

		gR_pAu_mult[iarm] = new TGraphErrors(4, &dNch_deta_pAu_cent[iarm][0], &rpA_pAu_cent[iarm][0], 0, &rpA_pAu_cent_err[iarm][0]);
		gR_pAu_mult[iarm]->SetMarkerStyle(20);
		gR_pAu_mult[iarm]->SetMarkerColor(kGreen+3);
		gR_pAu_mult[iarm]->SetLineWidth(2);
		gR_pAu_mult[iarm]->SetLineColor(kGreen+3);

		gR_pAu_mult_sys[iarm] = new TGraphErrors(4, &dNch_deta_pAu_cent[iarm][0], &rpA_pAu_cent[iarm][0], xx_mult_err, &rpA_pAu_cent_syserr[iarm][0]);
		gR_pAu_mult_sys[iarm]->SetMarkerStyle(20);
		gR_pAu_mult_sys[iarm]->SetMarkerColor(kGreen+3);
		gR_pAu_mult_sys[iarm]->SetLineWidth(2);
		gR_pAu_mult_sys[iarm]->SetLineColor(kGreen+3);
		gR_pAu_mult_sys[iarm]->SetFillStyle(0);
	}

	TCanvas *c11 = new TCanvas("c11","c11",1.1*2*400,400);
	c11->Divide(2,1);

	for (int iarm=0; iarm<narm; iarm++){
		c11->cd(iarm+1);
		SetPadStyle();

		htmp = (TH1F*)gPad->DrawFrame(0,0,30,1.6);
		SetHistoStyle("<N_{coll}>","R_{AB}");

		TLine *line = new TLine(0,1,30,1);
		line->SetLineWidth(2);
		line->SetLineStyle(2);
		line->Draw();

		gR_dAu_cent_sys[iarm]->Draw("2");
		gR_HeAu_cent_sys[iarm]->Draw("2");
		gR_pAu_cent_sys[iarm]->Draw("2");
		gR_pAl_cent_sys[iarm]->Draw("2");

		gR_dAu_cent[iarm]->Draw("p");
		gR_HeAu_cent[iarm]->Draw("p");
		gR_pAu_cent[iarm]->Draw("p");
		gR_pAl_cent[iarm]->Draw("p");

		if ( iarm==0 ){
			TLegend *leg = new TLegend(0.3,0.2,0.9,0.32);
			leg->SetFillStyle(0);
			leg->SetNColumns(2);
			entry = leg->AddEntry(gR_pAl_cent[iarm],"p+Al","p");
			entry->SetTextSize(0.055);
			entry = leg->AddEntry(gR_pAu_cent[iarm],"p+Au","p");
			entry->SetTextSize(0.055);
			entry = leg->AddEntry(gR_dAu_cent[iarm],"d+Au","p");
			entry->SetTextSize(0.055);
			entry = leg->AddEntry(gR_HeAu_cent[iarm],"^{3}He+Au","p");
			entry->SetTextSize(0.055);
			leg->Draw();
		}else{
			TLatex *tex = new TLatex(5, 0.2, "Global sys. 10%");
			tex->SetTextSize(0.055);
			tex->Draw();
		}

		if ( iarm==0 ){
			TLatex *tex = new TLatex(15,1.4,"#splitline{J/#psi, -2.2<y<-1.2}{Al/Au-direction}");
			tex->SetTextSize(0.055);
		}else{
			TLatex *tex = new TLatex(15,1.4,"#splitline{J/#psi, 1.2<y<2.2}{p/d/^{3}He-direction}");
			tex->SetTextSize(0.055);
		}
		tex->Draw();
	}

	return;

	TCanvas *c12 = new TCanvas("c12","c12",1.1*2*400,400);
	c12->Divide(2,1);

	for (int iarm=0; iarm<narm; iarm++){
		c12->cd(iarm+1);
		SetPadStyle();

		htmp = (TH1F*)gPad->DrawFrame(0,0,30,1.6);
		SetHistoStyle("dN_{ch}/d#eta","R_{AB}");

		TLine *line = new TLine(0,1,30,1);
		line->SetLineWidth(2);
		line->SetLineStyle(2);
		line->Draw();

		gR_dAu_mult_sys[iarm]->Draw("2");
		gR_HeAu_mult_sys[iarm]->Draw("2");
		gR_pAu_mult_sys[iarm]->Draw("2");
		gR_pAl_mult_sys[iarm]->Draw("2");

		gR_dAu_mult[iarm]->Draw("p");
		gR_HeAu_mult[iarm]->Draw("p");
		gR_pAu_mult[iarm]->Draw("p");
		gR_pAl_mult[iarm]->Draw("p");

		if ( iarm==0 ){
			TLegend *leg = new TLegend(0.3,0.2,0.9,0.32);
			leg->SetFillStyle(0);
			leg->SetNColumns(2);
			entry = leg->AddEntry(gR_pAl_cent[iarm],"p+Al","p");
			entry->SetTextSize(0.055);
			entry = leg->AddEntry(gR_pAu_cent[iarm],"p+Au","p");
			entry->SetTextSize(0.055);
			entry = leg->AddEntry(gR_dAu_cent[iarm],"d+Au","p");
			entry->SetTextSize(0.055);
			entry = leg->AddEntry(gR_HeAu_cent[iarm],"^{3}He+Au","p");
			entry->SetTextSize(0.055);
			leg->Draw();
		}else{
			TLatex *tex = new TLatex(5, 0.2, "Global sys. 10%");
			tex->SetTextSize(0.055);
			tex->Draw();
		}

		if ( iarm==0 ){
			TLatex *tex = new TLatex(15,1.4,"#splitline{J/#psi, -2.2<y<-1.2}{Al/Au-direction}");
			tex->SetTextSize(0.055);
		}else{
			TLatex *tex = new TLatex(15,1.4,"#splitline{J/#psi, 1.2<y<2.2}{p/d/^{3}He-direction}");
			tex->SetTextSize(0.055);
		}
		tex->Draw();

	}

	if ( bSAVE ){

		cpp0->cd();
		cpp0->SaveAs("/phenix/u/shlim/plots/Run15pp200_inclusive_jpsi/results_dsdy_vs_y_pp_comp.gif");
		cpp0->SaveAs("/phenix/u/shlim/plots/Run15pp200_inclusive_jpsi/results_dsdy_vs_y_pp_comp.pdf");

		c10->cd();
		c10->SaveAs("/phenix/u/shlim/plots/Run15pp200_inclusive_jpsi/results_dNdy_vs_y_all.gif");
		c10->SaveAs("/phenix/u/shlim/plots/Run15pp200_inclusive_jpsi/results_dNdy_vs_y_all.pdf");

		c1->cd();
		c1->SaveAs("/phenix/u/shlim/plots/Run15pp200_inclusive_jpsi/results_RAB_vs_y_all.gif");
		c1->SaveAs("/phenix/u/shlim/plots/Run15pp200_inclusive_jpsi/results_RAB_vs_y_all.pdf");

		c11->cd();
		c11->SaveAs("/phenix/u/shlim/plots/Run15pp200_inclusive_jpsi/results_RAB_vs_Ncoll_all.gif");
		c11->SaveAs("/phenix/u/shlim/plots/Run15pp200_inclusive_jpsi/results_RAB_vs_Ncoll_all.pdf");

		c12->cd();
		c12->SaveAs("/phenix/u/shlim/plots/Run15pp200_inclusive_jpsi/results_RAB_vs_mult_all.gif");
		c12->SaveAs("/phenix/u/shlim/plots/Run15pp200_inclusive_jpsi/results_RAB_vs_mult_all.pdf");

	}

	if ( bWRITE ){
		TFile *outfile = new TFile("data_inclusive_jpsi_rAB.root","recreate");

		grda_dAu->Write("gRdAu_vs_y");
		grda_dAu_sys->Write("gRdAu_vs_y_sys");
		for (int iarm=0; iarm<narm; iarm++){
			gR[iarm]->Write(Form("gRpAl_vs_y_arm%d",iarm));
			gR_sys[iarm]->Write(Form("gRpAl_vs_y_sys_arm%d",iarm));
			gR_pAu[iarm]->Write(Form("gRpAu_vs_y_arm%d",iarm));
			gR_pAu_sys[iarm]->Write(Form("gRpAu_vs_y_sys_arm%d",iarm));
			gR_HeAu[iarm]->Write(Form("gRHeAu_vs_y_arm%d",iarm));
			gR_HeAu_sys[iarm]->Write(Form("gRHeAu_vs_y_sys_arm%d",iarm));
		}

		for (int iarm=0; iarm<narm; iarm++){
			gR_dAu_cent[iarm]->Write(Form("gRdAu_vs_ncoll_arm%d",iarm));
			gR_dAu_cent_sys[iarm]->Write(Form("gRdAu_vs_ncoll_sys_arm%d",iarm));
			gR_pAu_cent[iarm]->Write(Form("gRpAu_vs_ncoll_arm%d",iarm));
			gR_pAu_cent_sys[iarm]->Write(Form("gRpAu_vs_ncoll_sys_arm%d",iarm));
			gR_pAl_cent[iarm]->Write(Form("gRpAl_vs_ncoll_arm%d",iarm));
			gR_pAl_cent_sys[iarm]->Write(Form("gRpAl_vs_ncoll_sys_arm%d",iarm));
			gR_HeAu_cent[iarm]->Write(Form("gRHeAu_vs_ncoll_arm%d",iarm));
			gR_HeAu_cent_sys[iarm]->Write(Form("gRHeAu_vs_ncoll_sys_arm%d",iarm));
		}

		for (int iarm=0; iarm<narm; iarm++){
			gR_dAu_mult[iarm]->Write(Form("gRdAu_vs_mult_arm%d",iarm));
			gR_dAu_mult_sys[iarm]->Write(Form("gRdAu_vs_mult_sys_arm%d",iarm));
			gR_pAu_mult[iarm]->Write(Form("gRpAu_vs_mult_arm%d",iarm));
			gR_pAu_mult_sys[iarm]->Write(Form("gRpAu_vs_mult_sys_arm%d",iarm));
			gR_pAl_mult[iarm]->Write(Form("gRpAl_vs_mult_arm%d",iarm));
			gR_pAl_mult_sys[iarm]->Write(Form("gRpAl_vs_mult_sys_arm%d",iarm));
			gR_HeAu_mult[iarm]->Write(Form("gRHeAu_vs_mult_arm%d",iarm));
			gR_HeAu_mult_sys[iarm]->Write(Form("gRHeAu_vs_mult_sys_arm%d",iarm));
		}
	}


}
