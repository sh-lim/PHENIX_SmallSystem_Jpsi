#include "Style.h"

void Draw_RAB_pT_all()
{

	const bool bSAVE = false;

	SetStyle();
	gStyle->SetLegendTextSize(20);

  char name1[500];
  char name2[500];
  char name3[500];

	TFile *file_pAu;	  
	TFile *file_pAl;	  
	TFile *file_HeAu;	  

	const int narm = 2;
	const int nptbin_pAu = 19;
	const int nptbin_pAl = 18;
	const int nptbin_HeAu = 15;
	const int nptbin_dAu = 23;

	const int ncentbin_pAu = 7;
	const int ncentbin_pAl = 3;
	const int ncentbin_HeAu = 3;
	const int ncentbin_dAu = 4;

	const int cent_per_pAu_min[ncentbin_pAu] = {0, 5, 10, 0, 20, 40, 60};
	const int cent_per_pAu_max[ncentbin_pAu] = {5, 10, 20, 20, 40, 60, 84};

	const int cent_per_pAl_min[ncentbin_pAl] = {0, 20, 40};
	const int cent_per_pAl_max[ncentbin_pAl] = {20, 40, 72};

	const int cent_per_HeAu_min[ncentbin_HeAu] = {0, 20, 40};
	const int cent_per_HeAu_max[ncentbin_HeAu] = {20, 40, 88};

	const int cent_per_dAu_min[ncentbin_dAu] = {0, 20, 40, 60};
	const int cent_per_dAu_max[ncentbin_dAu] = {20, 40, 60, 84};

	const char c_arm[narm] = {'S', 'N'};

	const double Ncoll_pAu_sys[ncentbin_pAu] = {0.6/9.7, 0.5/8.4, 0.5/7.4, 0.5/8.2, 0.4/6.1, 0.3/4.4, 0.2/2.6};
	const double BiasF_pAu_sys[ncentbin_pAu] = {0.01/0.86, 0.01/0.90, 0.01/0.94, 0.01/0.90, 0.01/0.98, 0.01/1.02, 0.06/1.00};

	const double Ncoll_pAl_sys[ncentbin_pAl] = {0.3/3.5, 0.1/2.3, 0.1/1.7};
	const double BiasF_pAl_sys[ncentbin_pAl] = {0.01/0.81, 0.02/0.90, 0.04/1.01};

	const double Ncoll_HeAu_sys[ncentbin_HeAu] = {0.076233184, 0.074324324, 0.080272996};
	const double BiasF_HeAu_sys[ncentbin_HeAu] = {0.010526316, 0.0099009901, 0.035018614};

	const double Ncoll_dAu_sys[ncentbin_dAu] = {1.0/15.1, 0.7/10.2, 0.4/6.6, 0.2/3.2};
	const double BiasF_dAu_sys[ncentbin_dAu] = {0.01/0.94, 0.006/1.000, 0.02/1.03, 0.06/1.03};

	// RAB arrays for TGraphs
	double RpAu_array[ncentbin_pAu][narm][nptbin_pAu] = {0};
	double RpAl_array[ncentbin_pAl][narm][nptbin_pAl] = {0};
	double RHeAu_array[ncentbin_HeAu][narm][nptbin_HeAu] = {0};

  // Type A error arrays for TGraphs
  double x_errors[nptbin_pAu] = {0};
  // Width of type B Errors
  double width[nptbin_pAu] = {0};

	double RpAu_ERR_array[ncentbin_pAu][narm][nptbin_pAu] = {0};
	double RpAl_ERR_array[ncentbin_pAl][narm][nptbin_pAl] = {0};
	double RHeAu_ERR_array[ncentbin_HeAu][narm][nptbin_HeAu] = {0};

	// Type B absolute error arrays for TGraphs
	double RpAu_sys_array[ncentbin_pAu][narm][nptbin_pAu] = {0};
	double RpAl_sys_array[ncentbin_pAl][narm][nptbin_pAl] = {0};
	double RHeAu_sys_array[ncentbin_HeAu][narm][nptbin_HeAu] = {0};


	TH1F *RpAu[ncentbin_pAu][narm];
	TH1F *RpAl[ncentbin_pAl][narm];
	TH1F *RHeAu[ncentbin_HeAu][narm];

	TH1F *RpAu_SYS_FRAC_ERR[ncentbin_pAu][narm];
	TH1F *RpAl_SYS_FRAC_ERR[ncentbin_pAl][narm];
	TH1F *RHeAu_SYS_FRAC_ERR[ncentbin_HeAu][narm];

	file_pAu = new TFile("RpAu_YpAu_vs_pT_cent.root","read");
	file_pAl = new TFile("RpAl_YpAl_vs_pT_cent.root","read");
	file_HeAu = new TFile("RHeAu_YHeAu_vs_pT_cent.root","read");

	for (int iarm=0; iarm<narm; iarm++){
		for (int icent=0; icent<ncentbin_pAu; icent++){
			RpAu[icent][iarm] = (TH1F*)file_pAu->Get(Form("RpAu_vs_pT_%c_%d%d",c_arm[iarm],cent_per_pAu_min[icent],cent_per_pAu_max[icent]));
			RpAu_SYS_FRAC_ERR[icent][iarm] = (TH1F*)file_pAu->Get(Form("RpAu_vs_pT_%c_%d%d_sys_frac",c_arm[iarm],cent_per_pAu_min[icent],cent_per_pAu_max[icent]));
		}
		RpAl[0][iarm] = (TH1F*)file_pAl->Get(Form("RpAl_vs_pT_%c_020",c_arm[iarm]));
		RpAl[1][iarm] = (TH1F*)file_pAl->Get(Form("RpAl_vs_pT_%c_2040",c_arm[iarm]));
		RpAl[2][iarm] = (TH1F*)file_pAl->Get(Form("RpAl_vs_pT_%c_4072",c_arm[iarm]));

		RpAl_SYS_FRAC_ERR[0][iarm] = (TH1F*)file_pAl->Get(Form("RpAl_vs_pT_%c_020_sys_frac",c_arm[iarm]));
		RpAl_SYS_FRAC_ERR[1][iarm] = (TH1F*)file_pAl->Get(Form("RpAl_vs_pT_%c_2040_sys_frac",c_arm[iarm]));
		RpAl_SYS_FRAC_ERR[2][iarm] = (TH1F*)file_pAl->Get(Form("RpAl_vs_pT_%c_4072_sys_frac",c_arm[iarm]));

		RHeAu[0][iarm] = (TH1F*)file_HeAu->Get(Form("RHeAu_vs_pT_%c_020",c_arm[iarm]));
		RHeAu[1][iarm] = (TH1F*)file_HeAu->Get(Form("RHeAu_vs_pT_%c_2040",c_arm[iarm]));
		RHeAu[2][iarm] = (TH1F*)file_HeAu->Get(Form("RHeAu_vs_pT_%c_4088",c_arm[iarm]));

		RHeAu_SYS_FRAC_ERR[0][iarm] = (TH1F*)file_HeAu->Get(Form("RHeAu_vs_pT_%c_020_sys_frac",c_arm[iarm]));
		RHeAu_SYS_FRAC_ERR[1][iarm] = (TH1F*)file_HeAu->Get(Form("RHeAu_vs_pT_%c_2040_sys_frac",c_arm[iarm]));
		RHeAu_SYS_FRAC_ERR[2][iarm] = (TH1F*)file_HeAu->Get(Form("RHeAu_vs_pT_%c_4088_sys_frac",c_arm[iarm]));
	}

	// R_dAu data points from PPG125
 double RAA_dAu[2][4][28] = {
    {
     0.702,0.760,0.840,0.894,0.954,1.008,1.000,1.058,1.058,1.252,1.240,1.249,1.230,1.088,1.406,1.131,1.244,1.209,1.824,1.508,1.182,1.171,1.848,2.079,0.0,0.0,0.0,0.0,
     0.706,0.739,0.815,0.925,0.984,0.874,1.021,1.008,1.067,1.169,1.103,1.137,1.160,1.099,1.234,0.957,1.376,1.077,1.401,1.028,1.481,1.188,0.793,0.996,0.0,0.0,0.0,0.0,
     0.953,0.865,0.995,0.920,0.976,0.929,0.979,1.018,1.015,1.159,1.227,1.036,1.046,1.114,1.152,1.124,1.313,1.427,1.080,1.365,0.985,1.354,1.297,4.130,0.0,0.0,0.0,0.0,
     0.829,0.823,0.922,0.965,0.947,0.965,0.990,0.888,1.097,1.073,1.047,1.175,1.132,0.908,0.926,0.804,1.277,0.642,1.827,0.700,1.193,3.141,1.122,0.443,0.0,0.0,0.0,0.0},
     {
     0.566,0.557,0.557,0.563,0.559,0.594,0.634,0.587,0.698,0.691,0.691,0.713,0.812,0.631,0.708,0.772,0.922,0.834,0.953,0.922,0.735,0.997,0.971,0.989,0.0,0.0,0.0,0.0,
     0.649,0.735,0.680,0.697,0.661,0.653,0.712,0.701,0.716,0.818,0.831,0.831,0.844,0.728,0.752,0.819,1.191,1.252,1.276,1.206,0.859,0.960,1.111,1.519,0.0,0.0,0.0,0.0,
     0.897,0.731,0.816,0.778,0.802,0.862,0.916,0.865,0.859,0.854,0.781,0.933,0.907,0.807,0.878,0.868,1.109,0.911,1.082,1.246,1.114,1.417,1.268,0.747,0.0,0.0,0.0,0.0,
     1.038,1.100,0.961,0.873,0.859,0.800,1.028,0.963,0.864,0.939,0.966,1.146,0.999,0.886,0.897,0.741,0.985,1.228,1.477,0.906,0.913,1.622,1.381,1.527,0.0,0.0,0.0,0.0}};

  double RAA_dAu_ERR[2][4][28] = {
    {
     0.121,0.104,0.105,0.076,0.059,0.066,0.061,0.066,0.062,0.072,0.076,0.083,0.095,0.093,0.13,0.124,0.165,0.186,0.314,0.329,0.33,0.522,0.83,1.364,0.0,0.0,0.0,0.0,
     0.123,0.108,0.113,0.069,0.051,0.059,0.054,0.054,0.06,0.072,0.073,0.084,0.101,0.102,0.131,0.121,0.195,0.19,0.28,0.266,0.496,0.641,0.469,0.836,0.0,0.0,0.0,0.0,
     0.103,0.104,0.094,0.06,0.055,0.056,0.067,0.06,0.074,0.091,0.086,0.088,0.101,0.114,0.14,0.153,0.212,0.253,0.263,0.356,0.345,0.796,0.671,2.905,0.0,0.0,0.0,0.0,
     0.14,0.091,0.074,0.068,0.057,0.059,0.058,0.059,0.077,0.084,0.09,0.107,0.122,0.115,0.138,0.136,0.234,0.187,0.401,0.251,0.42,1.737,0.714,0.0,0.0,0.0,0.0,0.0},   
    {
     0.054,0.046,0.034,0.031,0.029,0.029,0.031,0.029,0.034,0.037,0.041,0.047,0.056,0.052,0.064,0.081,0.112,0.124,0.163,0.183,0.192,0.396,0.378,0.739,0.0,0.0,0.0,0.0,
     0.076,0.066,0.065,0.05,0.042,0.035,0.037,0.037,0.039, 0.047,0.052,0.057,0.065,0.066,0.075,0.095,0.148,0.192,0.223,0.247,0.237,0.356,0.448,1.038,0.0,0.0,0.0,0.0,
     0.098,0.087,0.093,0.046,0.042,0.046,0.045,0.047,0.051,0.056,0.057,0.072,0.079,0.081,0.096,0.115,0.161,0.167,0.23,0.281,0.343,0.632,0.55,0.0,0.0,0.0,0.0,0.0,
     0.123,0.089,0.064,0.065,0.05,0.051,0.054,0.058,0.062,0.068,0.076,0.094,0.097,0.097,0.112,0.116,0.169,0.227,0.305,0.257,0.309,0.816,0.628,1.12,0.0,0.0,0.0,0.0}};
   
  double  RAA_dAu_SYS_FRAC_ERR[2][4][28] = {
    {
     0.049,0.053,0.058,0.062,0.065,0.069,0.069,0.073,0.073,0.086,0.085,0.086,0.085,0.075,0.097,0.078,0.086,0.084,0.127,0.106,0.082,0.082,0.128,0.146,0.0,0.0,0.0,0.0,
     0.049,0.042,0.057,0.064,0.068,0.060,0.07,0.069,0.073,0.08,0.076,0.078,0.08,0.076,0.085,0.066,0.095,0.075,0.097,0.072,0.103,0.083,0.055,0.07,0.0,0.0,0.0,0.0,
     0.066,0.061,0.069,0.063,0.067,0.064,0.067,0.07,0.07,0.08,0.085,0.071,0.072,0.077,0.08,0.078,0.091,0.099,0.075,0.096,0.069,0.094,0.09,0.291,0.0,0.0,0.0,0.0,
     0.057,0.058,0.064,0.066,0.065,0.066,0.068,0.061,0.075,0.074,0.072,0.081,0.078,0.063,0.064,0.056,0.088,0.044,0.127,0.049,0.083,0.219,0.078,0.031,0.0,0.0,0.0,0.0},
     {
     0.042,0.042,0.042,0.042,0.042,0.044,0.047,0.044,0.052,0.051,0.052,0.053,0.061,0.047,0.053,0.058,0.069,0.062,0.071,0.07,0.055,0.075,0.073,0.075,0.0,0.0,0.0,0.0,
     0.049,0.056,0.051,0.052,0.049,0.048,0.053,0.052,0.053,0.061,0.062,0.062,0.063,0.054,0.056,0.061,0.089,0.094,0.096,0.091,0.065,0.072,0.083,0.115,0.0,0.0,0.0,0.0,
     0.067,0.055,0.061,0.058,0.06,0.064,0.068,0.064,0.064,0.064,0.058,0.069,0.068,0.06,0.066,0.065,0.083,0.068,0.081,0.094,0.084,0.107,0.095,0.057,0.0,0.0,0.0,0.0,
     0.078,0.083,0.072,0.065,0.064,0.059,0.076,0.072,0.064,0.07,0.072,0.085,0.075,0.066,0.067,0.055,0.074,0.092,0.111,0.068,0.069,0.122,0.103,0.116,0.0,0.0,0.0,0.0}};
    

	TGraphErrors *gr_pAu[ncentbin_pAu][narm];
	TGraphErrors *gr_pAl[ncentbin_pAl][narm];
	TGraphErrors *gr_HeAu[ncentbin_HeAu][narm];
	TGraphErrors *gr_dAu[ncentbin_dAu][narm];

	TGraphErrors *gr_pAu_sys[ncentbin_pAu][narm];
	TGraphErrors *gr_pAl_sys[ncentbin_pAl][narm];
	TGraphErrors *gr_HeAu_sys[ncentbin_HeAu][narm];
	TGraphErrors *gr_dAu_sys[ncentbin_dAu][narm];

	//plot arrays
	double pt_array_pAu[nptbin_pAu] =  {0.125,0.375,0.625,0.875,1.125,1.375,1.625,1.875,2.125,2.375,2.625,2.875,3.125,3.375,3.625,3.875,4.25,4.75,6.0};
	double pt_array_pAl[nptbin_pAl] =  {0.125,0.375,0.625,0.875,1.125,1.375,1.625,1.875,2.125,2.375,2.625,2.875,3.125,3.375,3.625,3.875,4.5,6.0};
	double pt_array_HeAu[nptbin_HeAu] = {0.125,0.375,0.625,0.875,1.125,1.375,1.625,1.875,2.125,2.375,2.75,3.25,3.75,4.5,6.0};
	double pt_array_dAu[nptbin_dAu] = {0.125,0.375,0.625,0.875,1.125,1.375,1.625,1.875,2.125,2.375,2.625,2.875,3.125,3.375,3.625,3.875,4.125,4.375,4.625,4.875,5.25,5.75,6.50};

	for (int icent=0; icent<ncentbin_dAu; icent++){
		for (int iarm=0; iarm<narm; iarm++){
			gr_dAu[icent][iarm] = new TGraphErrors;
			gr_dAu[icent][iarm]->SetMarkerStyle(20+4*iarm);
			gr_dAu[icent][iarm]->SetMarkerColor(iarm+1);
			gr_dAu[icent][iarm]->SetMarkerSize(0.8);
			gr_dAu[icent][iarm]->SetLineColor(iarm+1);

			gr_dAu_sys[icent][iarm] = new TGraphErrors;
			gr_dAu_sys[icent][iarm]->SetMarkerStyle(20+4*iarm);
			gr_dAu_sys[icent][iarm]->SetMarkerColor(iarm+1);
			gr_dAu_sys[icent][iarm]->SetMarkerSize(0.8);
			gr_dAu_sys[icent][iarm]->SetLineColor(iarm+1);
			gr_dAu_sys[icent][iarm]->SetFillStyle(0);

			for (int ipt=0; ipt<nptbin_dAu; ipt++){
				double xx = pt_array_dAu[ipt];
				double yy = RAA_dAu[iarm][icent][ipt];
				double yy_err = RAA_dAu_ERR[iarm][icent][ipt];
				double yy_syserr = yy*RAA_dAu_SYS_FRAC_ERR[iarm][icent][ipt];
				gr_dAu[icent][iarm]->SetPoint(ipt, pt_array_dAu[ipt], yy);
				gr_dAu[icent][iarm]->SetPointError(ipt, 0, yy_err);

				gr_dAu_sys[icent][iarm]->SetPoint(ipt, pt_array_dAu[ipt], yy);
				gr_dAu_sys[icent][iarm]->SetPointError(ipt, 0.25/2, yy_syserr);
			}//ipt
		}//iarm
	}//icent

	for (int icent=0; icent<ncentbin_pAu; icent++){
		for (int iarm=0; iarm<narm; iarm++){
			gr_pAu[icent][iarm] = new TGraphErrors;
			gr_pAu[icent][iarm]->SetMarkerStyle(20+4*iarm);
			gr_pAu[icent][iarm]->SetMarkerColor(iarm+1);
			gr_pAu[icent][iarm]->SetMarkerSize(0.8);
			gr_pAu[icent][iarm]->SetLineColor(iarm+1);

			gr_pAu_sys[icent][iarm] = new TGraphErrors;
			gr_pAu_sys[icent][iarm]->SetMarkerStyle(20+4*iarm);
			gr_pAu_sys[icent][iarm]->SetMarkerColor(iarm+1);
			gr_pAu_sys[icent][iarm]->SetMarkerSize(0.8);
			gr_pAu_sys[icent][iarm]->SetLineColor(iarm+1);
			gr_pAu_sys[icent][iarm]->SetFillStyle(0);

			for (int ipt=0; ipt<nptbin_pAu; ipt++){
				double xx = pt_array_pAu[ipt];
				double yy = RpAu[icent][iarm]->GetBinContent(ipt+1);
				double yy_err = RpAu[icent][iarm]->GetBinError(ipt+1);
				double yy_syserr = yy*RpAu_SYS_FRAC_ERR[icent][iarm]->GetBinError(ipt+1);
				gr_pAu[icent][iarm]->SetPoint(ipt, pt_array_pAu[ipt], yy);
				gr_pAu[icent][iarm]->SetPointError(ipt, 0, yy_err);

				gr_pAu_sys[icent][iarm]->SetPoint(ipt, pt_array_pAu[ipt], yy);
				gr_pAu_sys[icent][iarm]->SetPointError(ipt, 0.25/2, yy_syserr);
			}//ipt
		}//iarm
	}//icent

	for (int icent=0; icent<ncentbin_pAl; icent++){
		for (int iarm=0; iarm<narm; iarm++){
			gr_pAl[icent][iarm] = new TGraphErrors;
			gr_pAl[icent][iarm]->SetMarkerStyle(20+4*iarm);
			gr_pAl[icent][iarm]->SetMarkerColor(iarm+1);
			gr_pAl[icent][iarm]->SetMarkerSize(0.8);
			gr_pAl[icent][iarm]->SetLineColor(iarm+1);

			gr_pAl_sys[icent][iarm] = new TGraphErrors;
			gr_pAl_sys[icent][iarm]->SetMarkerStyle(20+4*iarm);
			gr_pAl_sys[icent][iarm]->SetMarkerColor(iarm+1);
			gr_pAl_sys[icent][iarm]->SetMarkerSize(0.8);
			gr_pAl_sys[icent][iarm]->SetLineColor(iarm+1);
			gr_pAl_sys[icent][iarm]->SetFillStyle(0);

			for (int ipt=0; ipt<nptbin_pAl; ipt++){
				double xx = pt_array_pAl[ipt];
				double yy = RpAl[icent][iarm]->GetBinContent(ipt+1);
				double yy_err = RpAl[icent][iarm]->GetBinError(ipt+1);
				double yy_syserr = yy*RpAl_SYS_FRAC_ERR[icent][iarm]->GetBinError(ipt+1);
				gr_pAl[icent][iarm]->SetPoint(ipt, pt_array_pAl[ipt], yy);
				gr_pAl[icent][iarm]->SetPointError(ipt, 0, yy_err);

				gr_pAl_sys[icent][iarm]->SetPoint(ipt, pt_array_pAl[ipt], yy);
				gr_pAl_sys[icent][iarm]->SetPointError(ipt, 0.25/2, yy_syserr);
			}//ipt
		}//iarm
	}//icent

	for (int icent=0; icent<ncentbin_HeAu; icent++){
		for (int iarm=0; iarm<narm; iarm++){
			gr_HeAu[icent][iarm] = new TGraphErrors;
			gr_HeAu[icent][iarm]->SetMarkerStyle(20+4*iarm);
			gr_HeAu[icent][iarm]->SetMarkerColor(iarm+1);
			gr_HeAu[icent][iarm]->SetMarkerSize(0.8);
			gr_HeAu[icent][iarm]->SetLineColor(iarm+1);

			gr_HeAu_sys[icent][iarm] = new TGraphErrors;
			gr_HeAu_sys[icent][iarm]->SetMarkerStyle(20+4*iarm);
			gr_HeAu_sys[icent][iarm]->SetMarkerColor(iarm+1);
			gr_HeAu_sys[icent][iarm]->SetMarkerSize(0.8);
			gr_HeAu_sys[icent][iarm]->SetLineColor(iarm+1);
			gr_HeAu_sys[icent][iarm]->SetFillStyle(0);

			for (int ipt=0; ipt<nptbin_HeAu; ipt++){
				double xx = pt_array_HeAu[ipt];
				double yy = RHeAu[icent][iarm]->GetBinContent(ipt+1);
				double yy_err = RHeAu[icent][iarm]->GetBinError(ipt+1);
				double yy_syserr = yy*RHeAu_SYS_FRAC_ERR[icent][iarm]->GetBinError(ipt+1);
				gr_HeAu[icent][iarm]->SetPoint(ipt, pt_array_HeAu[ipt], yy);
				gr_HeAu[icent][iarm]->SetPointError(ipt, 0, yy_err);

				gr_HeAu_sys[icent][iarm]->SetPoint(ipt, pt_array_HeAu[ipt], yy);
				gr_HeAu_sys[icent][iarm]->SetPointError(ipt, 0.25/2, yy_syserr);
			}//ipt
		}//iarm
	}//icent

	TCanvas *c00 = new TCanvas("c00","c00",1.3*3*300,2*300);
	c00->Divide(3,2);

	TCanvas *c000[ncentbin_pAu];

	int count = 0;
	for (int icent=0; icent<ncentbin_pAu; icent++){
		if ( icent==3 ) continue;
		c00->cd(count+1);
		SetPadStyle();
		gPad->SetRightMargin(0.00);
		gPad->SetLeftMargin(0.14);
		gPad->SetBottomMargin(0.16);
		htmp = (TH1F*)gPad->DrawFrame(0,0,8,2.5);
		SetHistoStyle("p_{T} (GeV/c)","R_{AB}","",20,18);
		htmp->GetYaxis()->SetTitleOffset(2.0);
		htmp->GetXaxis()->SetTitleOffset(2.2);

		{
			TLegend *leg = new TLegend(0.15,0.7,0.6,0.9);
			leg->SetFillStyle(0);
			leg->SetBorderSize(0);
			le = leg->AddEntry("","p+Au #sqrt{s_{NN}}=200 GeV","h");
			le = leg->AddEntry("","Inclusive J/#psi","h");
			le = leg->AddEntry("",Form("%d%c-%d%c",cent_per_pAu_min[icent],'%',cent_per_pAu_max[icent],'%'),"h");
			leg->Draw();

			TLine *line = new TLine(0, 1, 8, 1);
			line->SetLineStyle(2);
			line->Draw();

			float global_sys = sqrt(Ncoll_pAu_sys[icent]*Ncoll_pAu_sys[icent] + BiasF_pAu_sys[icent]*BiasF_pAu_sys[icent] + 0.101*0.101);
			TBox *box = new TBox(9.5,1-global_sys,9.8,1+global_sys);
			box->SetFillStyle(1000);
			box->SetFillColorAlpha(1,0.5);
			box->Draw();
		}

		{
			TLegend *leg = new TLegend(0.65,0.75,0.95,0.9);
			leg->SetFillStyle(0);
			leg->SetBorderSize(0);
			leg->AddEntry(gr_pAu[icent][0],"-2.2<y<-1.2","p");
			leg->AddEntry(gr_pAu[icent][1],"1.2<y<2.2","p");
			leg->Draw();
		}

		for (int iarm=0; iarm<narm; iarm++){
			gr_pAu_sys[icent][iarm]->Draw("2");
			gr_pAu[icent][iarm]->Draw("p");
		}

		c000[icent] = new TCanvas(Form("c000_%d",icent),Form("c000_%d",icent),1.4*400,400);
		SetPadStyle();
		gPad->SetTopMargin(0.05);
		gPad->SetRightMargin(0.015);
		gPad->SetLeftMargin(0.14);
		gPad->SetBottomMargin(0.16);
		htmp = (TH1F*)gPad->DrawFrame(0,0,8,2.5);
		SetHistoStyle("p_{T} (GeV/c)","R_{AB}","",28,24);
		htmp->GetYaxis()->SetTitleOffset(0.8);
		htmp->GetXaxis()->SetTitleOffset(0.95);
		for (int iarm=0; iarm<narm; iarm++){
			gr_pAu_sys[icent][iarm]->Draw("2");
			gr_pAu[icent][iarm]->Draw("p");
		}

		{
			TLegend *leg = new TLegend(0.17,0.72,0.6,0.93);
			leg->SetFillStyle(0);
			leg->SetBorderSize(0);
			leg->SetTextSize(24);
			le = leg->AddEntry("","Inclusive J/#psi","h");
			le = leg->AddEntry("","#sqrt{s_{NN}}=200 GeV","h");
			le = leg->AddEntry("","PHENIX","h");
			leg->Draw();

			TLine *line = new TLine(0, 1, 8, 1);
			line->SetLineStyle(2);
			line->Draw();

			float global_sys = sqrt(Ncoll_pAu_sys[icent]*Ncoll_pAu_sys[icent] + BiasF_pAu_sys[icent]*BiasF_pAu_sys[icent] + 0.101*0.101);
			TBox *box = new TBox(7.7,1-global_sys,8.0,1+global_sys);
			box->SetFillStyle(1000);
			box->SetFillColorAlpha(1,0.5);
			box->Draw();
		}

		{
			TLegend *leg = new TLegend(0.65,0.72,0.95,0.93);
			leg->SetFillStyle(0);
			leg->SetBorderSize(0);
			leg->SetTextSize(24);
			le = leg->AddEntry("",Form("%d%c-%d%c, p+Au",cent_per_pAu_min[icent],'%',cent_per_pAu_max[icent],'%'),"h");
			le = leg->AddEntry(gr_pAu[icent][0],"-2.2<y<-1.2","p");
			le = leg->AddEntry(gr_pAu[icent][1],"1.2<y<2.2","p");
			leg->Draw();
		}

		{
			TLatex *tex = new TLatex(7.2, 1.5, Form("(%c)",97+count));
			tex->SetTextFont(43);
			tex->SetTextSize(24);
			tex->Draw();
		}

		count++;
	}

	//return;


	TCanvas *c01 = new TCanvas("c01","c01",1.3*3*300,1*300);
	c01->Divide(3,1);

	TCanvas *c001[ncentbin_pAl];

	for (int icent=0; icent<ncentbin_pAl; icent++){
		c01->cd(icent+1);
		SetPadStyle();
		gPad->SetRightMargin(0.00);
		gPad->SetLeftMargin(0.14);
		gPad->SetBottomMargin(0.16);
		htmp = (TH1F*)gPad->DrawFrame(0,0,4.8,2.5);
		SetHistoStyle("p_{T} (GeV/c)","R_{AB}","",20,18);
		htmp->GetYaxis()->SetTitleOffset(0.9);
		htmp->GetXaxis()->SetTitleOffset(1.0);

		{
			TLegend *leg = new TLegend(0.17,0.72,0.6,0.93);
			leg->SetFillStyle(0);
			leg->SetBorderSize(0);
			leg->SetTextSize(24);
			le = leg->AddEntry("","Inclusive J/#psi","h");
			le = leg->AddEntry("","#sqrt{s_{NN}}=200 GeV","h");
			le = leg->AddEntry("","PHENIX","h");
			leg->Draw();

			TLine *line = new TLine(0, 1, 9.8, 1);
			line->SetLineStyle(2);
			line->Draw();

			float global_sys = sqrt(Ncoll_pAl_sys[icent]*Ncoll_pAl_sys[icent] + BiasF_pAl_sys[icent]*BiasF_pAl_sys[icent] + 0.101*0.101);
			TBox *box = new TBox(9.5,1-global_sys,9.8,1+global_sys);
			box->SetFillStyle(1000);
			box->SetFillColorAlpha(1,0.5);
			box->Draw();
		}

		{
			TLegend *leg = new TLegend(0.65,0.72,0.95,0.93);
			leg->SetFillStyle(0);
			leg->SetBorderSize(0);
			leg->SetTextSize(24);
			le = leg->AddEntry("",Form("%d%c-%d%c, p+Al",cent_per_pAl_min[icent],'%',cent_per_pAl_max[icent],'%'),"h");
			le = leg->AddEntry(gr_pAu[icent][0],"-2.2<y<-1.2","p");
			le = leg->AddEntry(gr_pAu[icent][1],"1.2<y<2.2","p");
			leg->Draw();
		}

		for (int iarm=0; iarm<narm; iarm++){
			gr_pAl_sys[icent][iarm]->Draw("2");
			gr_pAl[icent][iarm]->Draw("p");
		}

		c001[icent] = new TCanvas(Form("c001_%d",icent),Form("c001_%d",icent),1.4*400,400);
		SetPadStyle();
		gPad->SetTopMargin(0.05);
		gPad->SetRightMargin(0.015);
		gPad->SetLeftMargin(0.14);
		gPad->SetBottomMargin(0.16);
		htmp = (TH1F*)gPad->DrawFrame(0,0,8,2.5);
		SetHistoStyle("p_{T} (GeV/c)","R_{AB}","",28,24);
		htmp->GetYaxis()->SetTitleOffset(0.8);
		htmp->GetXaxis()->SetTitleOffset(0.95);
		for (int iarm=0; iarm<narm; iarm++){
			gr_pAl_sys[icent][iarm]->Draw("2");
			gr_pAl[icent][iarm]->Draw("p");
		}

		{
			TLegend *leg = new TLegend(0.17,0.72,0.6,0.93);
			leg->SetFillStyle(0);
			leg->SetBorderSize(0);
			leg->SetTextSize(24);
			le = leg->AddEntry("","Inclusive J/#psi","h");
			le = leg->AddEntry("","#sqrt{s_{NN}}=200 GeV","h");
			le = leg->AddEntry("","PHENIX","h");
			leg->Draw();

			TLine *line = new TLine(0, 1, 8, 1);
			line->SetLineStyle(2);
			line->Draw();

			float global_sys = sqrt(Ncoll_pAl_sys[icent]*Ncoll_pAl_sys[icent] + BiasF_pAl_sys[icent]*BiasF_pAl_sys[icent] + 0.101*0.101);
			TBox *box = new TBox(7.7,1-global_sys,8.0,1+global_sys);
			box->SetFillStyle(1000);
			box->SetFillColorAlpha(1,0.5);
			box->Draw();
		}

		{
			TLegend *leg = new TLegend(0.65,0.72,0.95,0.93);
			leg->SetFillStyle(0);
			leg->SetBorderSize(0);
			leg->SetTextSize(24);
			le = leg->AddEntry("",Form("%d%c-%d%c, p+Al",cent_per_pAl_min[icent],'%',cent_per_pAl_max[icent],'%'),"h");
			le = leg->AddEntry(gr_pAu[icent][0],"-2.2<y<-1.2","p");
			le = leg->AddEntry(gr_pAu[icent][1],"1.2<y<2.2","p");
			leg->Draw();
		}

		{
			TLatex *tex = new TLatex(7.2, 1.5, Form("(%c)",97+icent));
			tex->SetTextFont(43);
			tex->SetTextSize(24);
			tex->Draw();
		}

	}


	TCanvas *c1002 = new TCanvas("c1002","c1002",1.3*3*400,400);

	TPad *pad = new TPad("c1002_pad0","c1002_pad0",0.0,0.0,0.35,1.0);
	pad->Draw();
	pad->cd();
	SetPadStyle();
	gPad->SetRightMargin(0.0);
	gPad->SetLeftMargin(0.13);
	gPad->SetBottomMargin(0.17);
	htmp = (TH1F*)gPad->DrawFrame(0,0,7.9,2.5);
	SetHistoStyle("p_{T} (GeV/c)","R_{AB}","",28,24);
	htmp->GetYaxis()->SetTitleOffset(0.8);
	htmp->GetXaxis()->SetTitleOffset(1.0);

	{
		int icent = 0;
		for (int iarm=0; iarm<narm; iarm++){
			gr_pAl_sys[icent][iarm]->Draw("2");
			gr_pAl[icent][iarm]->Draw("p");
		}

		{
			TLegend *leg = new TLegend(0.17,0.72,0.6,0.93);
			leg->SetFillStyle(0);
			leg->SetBorderSize(0);
			leg->SetTextSize(24);
			le = leg->AddEntry("","Inclusive J/#psi","h");
			le = leg->AddEntry("","#sqrt{s_{NN}}=200 GeV","h");
			le = leg->AddEntry("","PHENIX","h");
			leg->Draw();

			TLine *line = new TLine(0, 1, 8, 1);
			line->SetLineStyle(2);
			line->Draw();

			float global_sys = sqrt(Ncoll_pAl_sys[icent]*Ncoll_pAl_sys[icent] + BiasF_pAl_sys[icent]*BiasF_pAl_sys[icent] + 0.101*0.101);
			TBox *box = new TBox(7.7,1-global_sys,7.9,1+global_sys);
			box->SetFillStyle(1000);
			box->SetFillColorAlpha(1,0.5);
			box->Draw();
		}

		{
			TLegend *leg = new TLegend(0.65,0.72,0.95,0.93);
			leg->SetFillStyle(0);
			leg->SetBorderSize(0);
			leg->SetTextSize(24);
			le = leg->AddEntry("",Form("%d%c-%d%c, p+Al",cent_per_pAl_min[icent],'%',cent_per_pAl_max[icent],'%'),"h");
			le = leg->AddEntry(gr_pAu[icent][0],"-2.2<y<-1.2","p");
			le = leg->AddEntry(gr_pAu[icent][1],"1.2<y<2.2","p");
			leg->Draw();
		}

		{
			TLatex *tex = new TLatex(7.2, 1.5, Form("(%c)",97+icent));
			tex->SetTextFont(43);
			tex->SetTextSize(24);
			tex->Draw();
		}
	}

	c1002->cd();
	pad = new TPad("c1002_pad1","c1002_pad1",0.35,0.0,0.67,1.0);
	pad->Draw();
	pad->cd();
	SetPadStyle();
	gPad->SetRightMargin(0.00);
	gPad->SetLeftMargin(0.0);
	gPad->SetBottomMargin(0.17);
	htmp = (TH1F*)gPad->DrawFrame(-0.1,0,7.9,2.5);
	SetHistoStyle("p_{T} (GeV/c)","R_{AB}","",28,24);
	htmp->GetYaxis()->SetTitleOffset(0.8);
	htmp->GetXaxis()->SetTitleOffset(1.0);

	{
		int icent = 1;
		for (int iarm=0; iarm<narm; iarm++){
			gr_pAl_sys[icent][iarm]->Draw("2");
			gr_pAl[icent][iarm]->Draw("p");
		}

		{
			TLegend *leg = new TLegend(0.05,0.72,0.45,0.93);
			leg->SetFillStyle(0);
			leg->SetBorderSize(0);
			leg->SetTextSize(24);
			le = leg->AddEntry("","Inclusive J/#psi","h");
			le = leg->AddEntry("","#sqrt{s_{NN}}=200 GeV","h");
			le = leg->AddEntry("","PHENIX","h");
			leg->Draw();

			TLine *line = new TLine(0, 1, 8, 1);
			line->SetLineStyle(2);
			line->Draw();

			float global_sys = sqrt(Ncoll_pAl_sys[icent]*Ncoll_pAl_sys[icent] + BiasF_pAl_sys[icent]*BiasF_pAl_sys[icent] + 0.101*0.101);
			TBox *box = new TBox(7.7,1-global_sys,7.9,1+global_sys);
			box->SetFillStyle(1000);
			box->SetFillColorAlpha(1,0.5);
			box->Draw();
		}

		{
			TLegend *leg = new TLegend(0.6,0.72,0.9,0.93);
			leg->SetFillStyle(0);
			leg->SetBorderSize(0);
			leg->SetTextSize(24);
			le = leg->AddEntry("",Form("%d%c-%d%c, p+Al",cent_per_pAl_min[icent],'%',cent_per_pAl_max[icent],'%'),"h");
			le = leg->AddEntry(gr_pAu[icent][0],"-2.2<y<-1.2","p");
			le = leg->AddEntry(gr_pAu[icent][1],"1.2<y<2.2","p");
			leg->Draw();
		}

		{
			TLatex *tex = new TLatex(7.2, 1.5, Form("(%c)",97+icent));
			tex->SetTextFont(43);
			tex->SetTextSize(24);
			tex->Draw();
		}
	}

	c1002->cd();
	pad = new TPad("c1002_pad2","c0002_pad2",0.67,0.0,0.99,1.0);
	pad->Draw();
	pad->cd();
	SetPadStyle();
	gPad->SetRightMargin(0.00);
	gPad->SetLeftMargin(0.0);
	gPad->SetBottomMargin(0.17);
	htmp = (TH1F*)gPad->DrawFrame(-0.1,0,7.9,2.5);
	SetHistoStyle("p_{T} (GeV/c)","R_{AB}","",28,24);
	htmp->GetYaxis()->SetTitleOffset(0.8);
	htmp->GetXaxis()->SetTitleOffset(1.0);

	{
		int icent = 2;
		for (int iarm=0; iarm<narm; iarm++){
			gr_pAl_sys[icent][iarm]->Draw("2");
			gr_pAl[icent][iarm]->Draw("p");
		}

		{
			TLegend *leg = new TLegend(0.05,0.72,0.45,0.93);
			leg->SetFillStyle(0);
			leg->SetBorderSize(0);
			leg->SetTextSize(24);
			le = leg->AddEntry("","Inclusive J/#psi","h");
			le = leg->AddEntry("","#sqrt{s_{NN}}=200 GeV","h");
			le = leg->AddEntry("","PHENIX","h");
			leg->Draw();

			TLine *line = new TLine(0, 1, 8, 1);
			line->SetLineStyle(2);
			line->Draw();

			float global_sys = sqrt(Ncoll_pAl_sys[icent]*Ncoll_pAl_sys[icent] + BiasF_pAl_sys[icent]*BiasF_pAl_sys[icent] + 0.101*0.101);
			TBox *box = new TBox(7.7,1-global_sys,7.9,1+global_sys);
			box->SetFillStyle(1000);
			box->SetFillColorAlpha(1,0.5);
			box->Draw();
		}

		{
			TLegend *leg = new TLegend(0.6,0.72,0.9,0.93);
			leg->SetFillStyle(0);
			leg->SetBorderSize(0);
			leg->SetTextSize(24);
			le = leg->AddEntry("",Form("%d%c-%d%c, p+Al",cent_per_pAl_min[icent],'%',cent_per_pAl_max[icent],'%'),"h");
			le = leg->AddEntry(gr_pAu[icent][0],"-2.2<y<-1.2","p");
			le = leg->AddEntry(gr_pAu[icent][1],"1.2<y<2.2","p");
			leg->Draw();
		}

		{
			TLatex *tex = new TLatex(7.2, 1.5, Form("(%c)",97+icent));
			tex->SetTextFont(43);
			tex->SetTextSize(24);
			tex->Draw();
		}
	}


	//return;

	TCanvas *c02 = new TCanvas("c02","c02",1.3*3*300,1*300);
	c02->Divide(3,1);

	TCanvas *c002[ncentbin_pAl];

	for (int icent=0; icent<ncentbin_HeAu; icent++){
		c02->cd(icent+1);
		SetPadStyle();
		gPad->SetRightMargin(0.00);
		gPad->SetLeftMargin(0.14);
		gPad->SetBottomMargin(0.16);
		htmp = (TH1F*)gPad->DrawFrame(0,0,4.8,2.5);
		SetHistoStyle("p_{T} (GeV/c)","R_{AB}","",20,18);
		htmp->GetYaxis()->SetTitleOffset(0.9);
		htmp->GetXaxis()->SetTitleOffset(1.0);

		{
			TLegend *leg = new TLegend(0.15,0.7,0.6,0.9);
			leg->SetFillStyle(0);
			leg->SetBorderSize(0);
			le = leg->AddEntry("","^{3}He+Au #sqrt{s_{NN}}=200 GeV","h");
			le = leg->AddEntry("","Inclusive J/#psi","h");
			le = leg->AddEntry("",Form("%d%c-%d%c",cent_per_HeAu_min[icent],'%',cent_per_HeAu_max[icent],'%'),"h");
			leg->Draw();

			TLine *line = new TLine(0, 1, 9.8, 1);
			line->SetLineStyle(2);
			line->Draw();

			float global_sys = sqrt(Ncoll_HeAu_sys[icent]*Ncoll_HeAu_sys[icent] + BiasF_HeAu_sys[icent]*BiasF_HeAu_sys[icent] + 0.101*0.101);
			TBox *box = new TBox(9.5,1-global_sys,9.8,1+global_sys);
			box->SetFillStyle(1000);
			box->SetFillColorAlpha(1,0.5);
			box->Draw();
		}

		{
			TLegend *leg = new TLegend(0.65,0.75,0.95,0.9);
			leg->SetFillStyle(0);
			leg->SetBorderSize(0);
			leg->AddEntry(gr_HeAu[icent][0],"-2.2<y<-1.2","p");
			leg->AddEntry(gr_HeAu[icent][1],"1.2<y<2.2","p");
			leg->Draw();
		}

		for (int iarm=0; iarm<narm; iarm++){
			gr_HeAu_sys[icent][iarm]->Draw("2");
			gr_HeAu[icent][iarm]->Draw("p");
		}

		c002[icent] = new TCanvas(Form("c002_%d",icent),Form("c002_%d",icent),1.4*400,400);
		SetPadStyle();
		gPad->SetTopMargin(0.05);
		gPad->SetRightMargin(0.015);
		gPad->SetLeftMargin(0.14);
		gPad->SetBottomMargin(0.16);
		htmp = (TH1F*)gPad->DrawFrame(0,0,8,2.5);
		SetHistoStyle("p_{T} (GeV/c)","R_{AB}","",28,24);
		htmp->GetYaxis()->SetTitleOffset(0.8);
		htmp->GetXaxis()->SetTitleOffset(0.95);
		for (int iarm=0; iarm<narm; iarm++){
			gr_HeAu_sys[icent][iarm]->Draw("2");
			gr_HeAu[icent][iarm]->Draw("p");
		}

		{
			TLegend *leg = new TLegend(0.17,0.72,0.6,0.93);
			leg->SetFillStyle(0);
			leg->SetBorderSize(0);
			leg->SetTextSize(24);
			le = leg->AddEntry("","Inclusive J/#psi","h");
			le = leg->AddEntry("","#sqrt{s_{NN}}=200 GeV","h");
			le = leg->AddEntry("","PHENIX","h");
			leg->Draw();

			TLine *line = new TLine(0, 1, 8, 1);
			line->SetLineStyle(2);
			line->Draw();

			float global_sys = sqrt(Ncoll_HeAu_sys[icent]*Ncoll_HeAu_sys[icent] + BiasF_pAl_sys[icent]*BiasF_HeAu_sys[icent] + 0.101*0.101);
			TBox *box = new TBox(7.7,1-global_sys,8.0,1+global_sys);
			box->SetFillStyle(1000);
			box->SetFillColorAlpha(1,0.5);
			box->Draw();
		}

		{
			TLegend *leg = new TLegend(0.5,0.72,0.8,0.93);
			leg->SetFillStyle(0);
			leg->SetBorderSize(0);
			leg->SetTextSize(24);
			le = leg->AddEntry("",Form("%d%c-%d%c, ^{3}He+Au",cent_per_pAu_min[icent],'%',cent_per_pAu_max[icent],'%'),"h");
			le = leg->AddEntry(gr_pAu[icent][0],"-2.2<y<-1.2","p");
			le = leg->AddEntry(gr_pAu[icent][1],"1.2<y<2.2","p");
			leg->Draw();
		}

		{
			TLatex *tex = new TLatex(7.2, 1.5, Form("(%c)",97+icent));
			tex->SetTextFont(43);
			tex->SetTextSize(24);
			tex->Draw();
		}

	}


	TCanvas *c0001 = new TCanvas("c0001","c0001",1.3*3*400,400);

	pad = new TPad("c0001_pad0","c0001_pad0",0.0,0.0,0.35,1.0);
	pad->Draw();
	pad->cd();
	SetPadStyle();
	gPad->SetRightMargin(0.0);
	gPad->SetLeftMargin(0.13);
	gPad->SetBottomMargin(0.17);
	htmp = (TH1F*)gPad->DrawFrame(0,0,7.9,2.5);
	SetHistoStyle("p_{T} (GeV/c)","R_{AB}","",28,24);
	htmp->GetYaxis()->SetTitleOffset(0.8);
	htmp->GetXaxis()->SetTitleOffset(1.0);

	{
		int icent = 0;
		for (int iarm=0; iarm<narm; iarm++){
			gr_HeAu_sys[icent][iarm]->Draw("2");
			gr_HeAu[icent][iarm]->Draw("p");
		}

		{
			TLegend *leg = new TLegend(0.17,0.72,0.6,0.93);
			leg->SetFillStyle(0);
			leg->SetBorderSize(0);
			leg->SetTextSize(24);
			le = leg->AddEntry("","Inclusive J/#psi","h");
			le = leg->AddEntry("","#sqrt{s_{NN}}=200 GeV","h");
			le = leg->AddEntry("","PHENIX","h");
			leg->Draw();

			TLine *line = new TLine(0, 1, 8, 1);
			line->SetLineStyle(2);
			line->Draw();

			float global_sys = sqrt(Ncoll_HeAu_sys[icent]*Ncoll_HeAu_sys[icent] + BiasF_HeAu_sys[icent]*BiasF_HeAu_sys[icent] + 0.101*0.101);
			TBox *box = new TBox(7.7,1-global_sys,7.9,1+global_sys);
			box->SetFillStyle(1000);
			box->SetFillColorAlpha(1,0.5);
			box->Draw();
		}

		{
			TLegend *leg = new TLegend(0.5,0.72,0.8,0.93);
			leg->SetFillStyle(0);
			leg->SetBorderSize(0);
			leg->SetTextSize(24);
			le = leg->AddEntry("",Form("%d%c-%d%c, ^{3}He+Au",cent_per_HeAu_min[icent],'%',cent_per_HeAu_max[icent],'%'),"h");
			le = leg->AddEntry(gr_pAu[icent][0],"-2.2<y<-1.2","p");
			le = leg->AddEntry(gr_pAu[icent][1],"1.2<y<2.2","p");
			leg->Draw();
		}

		{
			TLatex *tex = new TLatex(7.2, 1.5, Form("(%c)",97+icent));
			tex->SetTextFont(43);
			tex->SetTextSize(24);
			tex->Draw();
		}
	}


	c0001->cd();
	pad = new TPad("c0001_pad1","c0001_pad1",0.35,0.0,0.67,1.0);
	pad->Draw();
	pad->cd();
	SetPadStyle();
	gPad->SetRightMargin(0.00);
	gPad->SetLeftMargin(0.0);
	gPad->SetBottomMargin(0.17);
	htmp = (TH1F*)gPad->DrawFrame(-0.1,0,7.9,2.5);
	SetHistoStyle("p_{T} (GeV/c)","R_{AB}","",28,24);
	htmp->GetYaxis()->SetTitleOffset(0.8);
	htmp->GetXaxis()->SetTitleOffset(1.0);

	{
		int icent = 1;
		for (int iarm=0; iarm<narm; iarm++){
			gr_HeAu_sys[icent][iarm]->Draw("2");
			gr_HeAu[icent][iarm]->Draw("p");
		}

		{
			TLegend *leg = new TLegend(0.05,0.72,0.45,0.93);
			leg->SetFillStyle(0);
			leg->SetBorderSize(0);
			leg->SetTextSize(24);
			le = leg->AddEntry("","Inclusive J/#psi","h");
			le = leg->AddEntry("","#sqrt{s_{NN}}=200 GeV","h");
			le = leg->AddEntry("","PHENIX","h");
			leg->Draw();

			TLine *line = new TLine(0, 1, 8, 1);
			line->SetLineStyle(2);
			line->Draw();

			float global_sys = sqrt(Ncoll_HeAu_sys[icent]*Ncoll_HeAu_sys[icent] + BiasF_HeAu_sys[icent]*BiasF_HeAu_sys[icent] + 0.101*0.101);
			TBox *box = new TBox(7.7,1-global_sys,7.9,1+global_sys);
			box->SetFillStyle(1000);
			box->SetFillColorAlpha(1,0.5);
			box->Draw();
		}

		{
			TLegend *leg = new TLegend(0.45,0.72,0.75,0.93);
			leg->SetFillStyle(0);
			leg->SetBorderSize(0);
			leg->SetTextSize(24);
			le = leg->AddEntry("",Form("%d%c-%d%c, ^{3}He+Au",cent_per_HeAu_min[icent],'%',cent_per_HeAu_max[icent],'%'),"h");
			le = leg->AddEntry(gr_pAu[icent][0],"-2.2<y<-1.2","p");
			le = leg->AddEntry(gr_pAu[icent][1],"1.2<y<2.2","p");
			leg->Draw();
		}

		{
			TLatex *tex = new TLatex(7.2, 1.5, Form("(%c)",97+icent));
			tex->SetTextFont(43);
			tex->SetTextSize(24);
			tex->Draw();
		}
	}

	c0001->cd();
	pad = new TPad("c0001_pad2","c0001_pad2",0.67,0.0,0.99,1.0);
	pad->Draw();
	pad->cd();
	SetPadStyle();
	gPad->SetRightMargin(0.00);
	gPad->SetLeftMargin(0.0);
	gPad->SetBottomMargin(0.17);
	htmp = (TH1F*)gPad->DrawFrame(-0.1,0,7.9,2.5);
	SetHistoStyle("p_{T} (GeV/c)","R_{AB}","",28,24);
	htmp->GetYaxis()->SetTitleOffset(0.8);
	htmp->GetXaxis()->SetTitleOffset(1.0);

	{
		int icent = 2;
		for (int iarm=0; iarm<narm; iarm++){
			gr_HeAu_sys[icent][iarm]->Draw("2");
			gr_HeAu[icent][iarm]->Draw("p");
		}

		{
			TLegend *leg = new TLegend(0.05,0.72,0.45,0.93);
			leg->SetFillStyle(0);
			leg->SetBorderSize(0);
			leg->SetTextSize(24);
			le = leg->AddEntry("","Inclusive J/#psi","h");
			le = leg->AddEntry("","#sqrt{s_{NN}}=200 GeV","h");
			le = leg->AddEntry("","PHENIX","h");
			leg->Draw();

			TLine *line = new TLine(0, 1, 8, 1);
			line->SetLineStyle(2);
			line->Draw();

			float global_sys = sqrt(Ncoll_HeAu_sys[icent]*Ncoll_HeAu_sys[icent] + BiasF_HeAu_sys[icent]*BiasF_HeAu_sys[icent] + 0.101*0.101);
			TBox *box = new TBox(7.7,1-global_sys,7.9,1+global_sys);
			box->SetFillStyle(1000);
			box->SetFillColorAlpha(1,0.5);
			box->Draw();
		}

		{
			TLegend *leg = new TLegend(0.45,0.72,0.75,0.93);
			leg->SetFillStyle(0);
			leg->SetBorderSize(0);
			leg->SetTextSize(24);
			le = leg->AddEntry("",Form("%d%c-%d%c, ^{3}He+Au",cent_per_HeAu_min[icent],'%',cent_per_HeAu_max[icent],'%'),"h");
			le = leg->AddEntry(gr_pAu[icent][0],"-2.2<y<-1.2","p");
			le = leg->AddEntry(gr_pAu[icent][1],"1.2<y<2.2","p");
			leg->Draw();
		}

		{
			TLatex *tex = new TLatex(7.2, 1.5, Form("(%c)",97+icent));
			tex->SetTextFont(43);
			tex->SetTextSize(24);
			tex->Draw();
		}
	}

	//return;

	TCanvas *c0002[narm];
	TCanvas *c0003[narm];
	TCanvas *c0004[narm];
	TCanvas *c1003[narm];

	for (int iarm=0; iarm<narm; iarm++){
		c0002[iarm] = new TCanvas(Form("c0002_%d",iarm),Form("c0002_%d",iarm),1.4*400,400);
		c0002[iarm]->cd(iarm+1);
		SetPadStyle();
		gPad->SetTopMargin(0.05);
		gPad->SetRightMargin(0.015);
		gPad->SetLeftMargin(0.12);
		gPad->SetBottomMargin(0.15);
		htmp = (TH1F*)gPad->DrawFrame(0,0,8,2.5);
		SetHistoStyle("p_{T} (GeV/c)","R_{AB}","",26,22);
		htmp->GetYaxis()->SetTitleOffset(0.8);
		htmp->GetXaxis()->SetTitleOffset(0.9);

		TLine *line = new TLine(0, 1, 8, 1);
		line->SetLineStyle(2);
		line->Draw();

		TGraphErrors *gr_pAu_sys_cp = new TGraphErrors(*gr_pAu_sys[3][iarm]);
		gr_pAu_sys_cp->SetName(Form("gr_pAu_sys_cp_arm%d",iarm));
		gr_pAu_sys_cp->SetMarkerStyle(20+iarm);
		gr_pAu_sys_cp->SetMarkerColor(kGreen+2);
		gr_pAu_sys_cp->SetLineColor(kGreen+2);

		TGraphErrors *gr_pAu_cp = new TGraphErrors(*gr_pAu[3][iarm]);
		gr_pAu_cp->SetName(Form("gr_pAu_cp_arm%d",iarm));
		gr_pAu_cp->SetMarkerStyle(20+iarm);
		gr_pAu_cp->SetMarkerColor(kGreen+2);
		gr_pAu_cp->SetLineColor(kGreen+2);

		TGraphErrors *gr_pAl_sys_cp = new TGraphErrors(*gr_pAl_sys[0][iarm]);
		gr_pAl_sys_cp->SetName(Form("gr_pAl_sys_cp_arm%d",iarm));
		gr_pAl_sys_cp->SetMarkerStyle(24+iarm);
		gr_pAl_sys_cp->SetMarkerColor(2);
		gr_pAl_sys_cp->SetLineColor(2);

		TGraphErrors *gr_pAl_cp = new TGraphErrors(*gr_pAl[0][iarm]);
		gr_pAl_cp->SetName(Form("gr_pAl_cp_arm%d",iarm));
		gr_pAl_cp->SetMarkerStyle(24+iarm);
		gr_pAl_cp->SetMarkerColor(2);
		gr_pAl_cp->SetLineColor(2);

		gr_pAl_sys_cp->Draw("2");
		gr_pAu_sys_cp->Draw("2");
		gr_pAl_cp->Draw("p");
		gr_pAu_cp->Draw("p");

		{
			TLegend *leg = new TLegend(0.15,0.71,0.6,0.92);
			leg->SetFillStyle(0);
			leg->SetBorderSize(0);
			leg->SetTextSize(22);
			le = leg->AddEntry("","Inclusive J/#psi","h");
			le = leg->AddEntry("","#sqrt{s_{NN}}=200 GeV","h");
			le = leg->AddEntry("","PHENIX","h");
			leg->Draw();
		}

		{
			float global_sys = sqrt(Ncoll_pAu_sys[3]*Ncoll_pAu_sys[3] + BiasF_pAu_sys[3]*BiasF_pAu_sys[3] + 0.101*0.101);
			TBox *box = new TBox(7.8,1-global_sys,8.0,1+global_sys);
			box->SetFillStyle(1000);
			box->SetFillColorAlpha(kGreen+2,0.5);
			box->Draw();
		}

		{
			float global_sys = sqrt(Ncoll_pAl_sys[0]*Ncoll_pAl_sys[0] + BiasF_pAl_sys[0]*BiasF_pAl_sys[0] + 0.101*0.101);
			TBox *box = new TBox(7.6,1-global_sys,7.8,1+global_sys);
			box->SetFillStyle(1000);
			box->SetFillColorAlpha(2,0.5);
			box->Draw();
		}

		{
			TLatex *tex = new TLatex(7.2,1.5,Form("(%c)",97+iarm));
			tex->SetTextSize(22);
			tex->SetTextFont(43);
			tex->Draw();
		}

		{
			TLegend *leg = new TLegend(0.6,0.71,0.8,0.92);
			leg->SetFillStyle(0);
			leg->SetBorderSize(0);
			leg->SetTextSize(24);
			if ( iarm==0 ){
				le = leg->AddEntry("","-2.2<y<-1.2","h");
			}else{
				le = leg->AddEntry("","1.2<y<2.2","h");
			}
			le = leg->AddEntry(gr_pAl_cp,"0%-20%, p+Al","p");
			le = leg->AddEntry(gr_pAu_cp,"0%-20%, p+Au","p");
			leg->Draw();
		}

	}//iarm

	for (int iarm=0; iarm<narm; iarm++){
		c0003[iarm] = new TCanvas(Form("c0003_%d",iarm),Form("c0003_%d",iarm),1.4*400,400);
		c0003[iarm]->cd(iarm+1);
		SetPadStyle();
		gPad->SetTopMargin(0.05);
		gPad->SetRightMargin(0.015);
		gPad->SetLeftMargin(0.12);
		gPad->SetBottomMargin(0.15);
		htmp = (TH1F*)gPad->DrawFrame(0,0,8,2.5);
		SetHistoStyle("p_{T} (GeV/c)","R_{AB}","",26,22);
		htmp->GetYaxis()->SetTitleOffset(0.8);
		htmp->GetXaxis()->SetTitleOffset(0.9);

		TLine *line = new TLine(0, 1, 8, 1);
		line->SetLineStyle(2);
		line->Draw();

		TGraphErrors *gr_pAu_sys_cp = new TGraphErrors(*gr_pAu_sys[3][iarm]);
		gr_pAu_sys_cp->SetName(Form("gr_pAu_sys_cp_arm%d",iarm));
		gr_pAu_sys_cp->SetMarkerStyle(20+iarm);
		gr_pAu_sys_cp->SetMarkerColor(kGreen+2);
		gr_pAu_sys_cp->SetLineColor(kGreen+2);

		TGraphErrors *gr_pAu_cp = new TGraphErrors(*gr_pAu[3][iarm]);
		gr_pAu_cp->SetName(Form("gr_pAu_cp_arm%d",iarm));
		gr_pAu_cp->SetMarkerStyle(20+iarm);
		gr_pAu_cp->SetMarkerColor(kGreen+2);
		gr_pAu_cp->SetLineColor(kGreen+2);

		TGraphErrors *gr_HeAu_sys_cp = new TGraphErrors(*gr_HeAu_sys[0][iarm]);
		gr_HeAu_sys_cp->SetName(Form("gr_HeAu_sys_cp_arm%d",iarm));
		gr_HeAu_sys_cp->SetMarkerStyle(24+iarm);
		gr_HeAu_sys_cp->SetMarkerColor(6);
		gr_HeAu_sys_cp->SetLineColor(6);

		TGraphErrors *gr_HeAu_cp = new TGraphErrors(*gr_HeAu[0][iarm]);
		gr_HeAu_cp->SetName(Form("gr_HeAu_cp_arm%d",iarm));
		gr_HeAu_cp->SetMarkerStyle(24+iarm);
		gr_HeAu_cp->SetMarkerColor(6);
		gr_HeAu_cp->SetLineColor(6);

		gr_HeAu_sys_cp->Draw("2");
		gr_pAu_sys_cp->Draw("2");
		gr_HeAu_cp->Draw("p");
		gr_pAu_cp->Draw("p");

		{
			TLegend *leg = new TLegend(0.15,0.71,0.6,0.92);
			leg->SetFillStyle(0);
			leg->SetBorderSize(0);
			leg->SetTextSize(22);
			le = leg->AddEntry("","Inclusive J/#psi","h");
			le = leg->AddEntry("","#sqrt{s_{NN}}=200 GeV","h");
			le = leg->AddEntry("","PHENIX","h");
			leg->Draw();
		}

		{
			float global_sys = sqrt(Ncoll_pAu_sys[3]*Ncoll_pAu_sys[3] + BiasF_pAu_sys[3]*BiasF_pAu_sys[3] + 0.101*0.101);
			TBox *box = new TBox(7.8,1-global_sys,8.0,1+global_sys);
			box->SetFillStyle(1000);
			box->SetFillColorAlpha(kGreen+2,0.5);
			box->Draw();
		}

		{
			float global_sys = sqrt(Ncoll_HeAu_sys[0]*Ncoll_HeAu_sys[0] + BiasF_HeAu_sys[0]*BiasF_HeAu_sys[0] + 0.101*0.101);
			TBox *box = new TBox(7.6,1-global_sys,7.8,1+global_sys);
			box->SetFillStyle(1000);
			box->SetFillColorAlpha(6,0.5);
			box->Draw();
		}

		{
			TLatex *tex = new TLatex(7.2,2.25,Form("(%c)",97+iarm));
			tex->SetTextSize(22);
			tex->SetTextFont(43);
			tex->Draw();
		}

		{
			TLegend *leg = new TLegend(0.6,0.71,0.8,0.92);
			leg->SetFillStyle(0);
			leg->SetBorderSize(0);
			leg->SetTextSize(24);
			if ( iarm==0 ){
				le = leg->AddEntry("","-2.2<y<-1.2","h");
			}else{
				le = leg->AddEntry("","1.2<y<2.2","h");
			}
			le = leg->AddEntry(gr_pAu_cp,"0%-20%, p+Au","p");
			le = leg->AddEntry(gr_HeAu_cp,"0%-20%, ^{3}He+Au","p");
			leg->Draw();
		}

	}//iarm

	//reading ratio
	TFile *infile_ratio = new TFile("RpAu_RHeAu_ratio_vs_pT.root","read");
	TH1F *pAu_HeAu_ratio_020[narm];
	TH1F *pAu_HeAu_ratio_020_sys[narm];
	pAu_HeAu_ratio_020[1] = (TH1F*)infile_ratio->Get("pAu_HeAu_ratio_020_N");
	pAu_HeAu_ratio_020[0] = (TH1F*)infile_ratio->Get("pAu_HeAu_ratio_020_S");
	pAu_HeAu_ratio_020_sys[1] = (TH1F*)infile_ratio->Get("pAu_HeAu_ratio_020_N_sys");
	pAu_HeAu_ratio_020_sys[0] = (TH1F*)infile_ratio->Get("pAu_HeAu_ratio_020_S_sys");

	TGraphErrors *gratio[narm];
	TGraphErrors *gratio_sys[narm];

	for (int iarm=0; iarm<narm; iarm++){
		c0004[iarm] = new TCanvas(Form("c0004_%d",iarm),Form("c0004_%d",iarm),1.4*400,600);
		c0004[iarm]->cd(iarm+1);

		TPad *pad = new TPad(Form("p0000_%d_0",iarm),Form("p0000_%d_0",iarm),0, 0.42, 1.0, 1.0);
		pad->Draw();

		pad->cd();
		SetPadStyle();
		gPad->SetTopMargin(0.05);
		gPad->SetRightMargin(0.015);
		gPad->SetLeftMargin(0.12);
		gPad->SetBottomMargin(0.001);
		htmp = (TH1F*)gPad->DrawFrame(0,-0.1,8,2.5);
		SetHistoStyle("p_{T} (GeV/c)","R_{AB}","",26,22);
		htmp->GetYaxis()->SetTitleOffset(1.2);
		htmp->GetXaxis()->SetTitleOffset(0.9);

		TLine *line = new TLine(0, 1, 8, 1);
		line->SetLineStyle(2);
		line->Draw();

		TGraphErrors *gr_pAu_sys_cp = new TGraphErrors(*gr_pAu_sys[3][iarm]);
		gr_pAu_sys_cp->SetName(Form("gr_pAu_sys_cp_arm%d",iarm));
		gr_pAu_sys_cp->SetMarkerStyle(20+iarm);
		gr_pAu_sys_cp->SetMarkerColor(kGreen+2);
		gr_pAu_sys_cp->SetLineColor(kGreen+2);

		TGraphErrors *gr_pAu_cp = new TGraphErrors(*gr_pAu[3][iarm]);
		gr_pAu_cp->SetName(Form("gr_pAu_cp_arm%d",iarm));
		gr_pAu_cp->SetMarkerStyle(20+iarm);
		gr_pAu_cp->SetMarkerColor(kGreen+2);
		gr_pAu_cp->SetLineColor(kGreen+2);

		TGraphErrors *gr_HeAu_sys_cp = new TGraphErrors(*gr_HeAu_sys[0][iarm]);
		gr_HeAu_sys_cp->SetName(Form("gr_HeAu_sys_cp_arm%d",iarm));
		gr_HeAu_sys_cp->SetMarkerStyle(24+iarm);
		gr_HeAu_sys_cp->SetMarkerColor(6);
		gr_HeAu_sys_cp->SetLineColor(6);

		TGraphErrors *gr_HeAu_cp = new TGraphErrors(*gr_HeAu[0][iarm]);
		gr_HeAu_cp->SetName(Form("gr_HeAu_cp_arm%d",iarm));
		gr_HeAu_cp->SetMarkerStyle(24+iarm);
		gr_HeAu_cp->SetMarkerColor(6);
		gr_HeAu_cp->SetLineColor(6);

		gr_HeAu_sys_cp->Draw("2");
		gr_pAu_sys_cp->Draw("2");
		gr_HeAu_cp->Draw("p");
		gr_pAu_cp->Draw("p");

		{
			TLegend *leg = new TLegend(0.15,0.71,0.6,0.92);
			leg->SetFillStyle(0);
			leg->SetBorderSize(0);
			leg->SetTextSize(22);
			le = leg->AddEntry("","Inclusive J/#psi","h");
			le = leg->AddEntry("","#sqrt{s_{NN}}=200 GeV","h");
			le = leg->AddEntry("","PHENIX","h");
			leg->Draw();
		}

		{
			float global_sys = sqrt(Ncoll_pAu_sys[3]*Ncoll_pAu_sys[3] + BiasF_pAu_sys[3]*BiasF_pAu_sys[3] + 0.101*0.101);
			TBox *box = new TBox(7.8,1-global_sys,8.0,1+global_sys);
			box->SetFillStyle(1000);
			box->SetFillColorAlpha(kGreen+2,0.5);
			box->Draw();
		}

		{
			float global_sys = sqrt(Ncoll_HeAu_sys[0]*Ncoll_HeAu_sys[0] + BiasF_HeAu_sys[0]*BiasF_HeAu_sys[0] + 0.101*0.101);
			TBox *box = new TBox(7.6,1-global_sys,7.8,1+global_sys);
			box->SetFillStyle(1000);
			box->SetFillColorAlpha(6,0.5);
			box->Draw();
		}

		{
			TLatex *tex = new TLatex(7.2,2.3,Form("(%c)",97+iarm));
			tex->SetTextSize(22);
			tex->SetTextFont(43);
			tex->Draw();
		}

		{
			TLegend *leg = new TLegend(0.6,0.71,0.8,0.92);
			leg->SetFillStyle(0);
			leg->SetBorderSize(0);
			leg->SetTextSize(24);
			if ( iarm==0 ){
				le = leg->AddEntry("","-2.2<y<-1.2","h");
			}else{
				le = leg->AddEntry("","1.2<y<2.2","h");
			}
			le = leg->AddEntry(gr_pAu_cp,"0%-20%, p+Au","p");
			le = leg->AddEntry(gr_HeAu_cp,"0%-20%, ^{3}He+Au","p");
			leg->Draw();
		}


		c0004[iarm]->cd();

		pad = new TPad(Form("p0000_%d_0",iarm),Form("p0000_%d_0",iarm),0, 0, 1.0, 0.42);
		pad->Draw();

		pad->cd();
		gPad->SetTopMargin(0.0);
		gPad->SetRightMargin(0.015);
		gPad->SetLeftMargin(0.12);
		gPad->SetBottomMargin(0.25);
		htmp = (TH1F*)gPad->DrawFrame(0,0.2,8,1.8);
		//SetHistoStyle("p_{T} (GeV/c)","R_{^{3}HeAu} / R_{pAu}","",26,22);
		SetHistoStyle("p_{T} (GeV/c)","^{3}He+Au / p+Au","",26,22);
		htmp->GetYaxis()->SetTitleOffset(1.2);
		htmp->GetYaxis()->CenterTitle();
		htmp->GetXaxis()->SetTitleOffset(2.3);
		htmp->GetYaxis()->SetNdivisions(7,5,0);

		gratio[iarm] = new TGraphErrors;
		gratio_sys[iarm] = new TGraphErrors;
		for (int ipt=0; ipt<pAu_HeAu_ratio_020[iarm]->GetNbinsX(); ipt++){
			float xx = pAu_HeAu_ratio_020[iarm]->GetBinCenter(ipt+1);
			float yy = pAu_HeAu_ratio_020[iarm]->GetBinContent(ipt+1);
			float yy_err = pAu_HeAu_ratio_020[iarm]->GetBinError(ipt+1);
			float yy_syserr = yy * pAu_HeAu_ratio_020_sys[iarm]->GetBinError(ipt+1);

			cout << xx << " " << yy << " " << yy_err << " " << yy_syserr << endl;

			gratio[iarm]->SetPoint(ipt, xx, 1./yy);
			gratio[iarm]->SetPointError(ipt, 0, 1./yy*yy_err/yy);

			gratio_sys[iarm]->SetPoint(ipt, xx, 1./yy);
			gratio_sys[iarm]->SetPointError(ipt, 0.125, 1./yy*yy_syserr/yy);
		}

		TF1 *f1 = new TF1("f1","[0]",0,7);

		if ( iarm==0 ){
			f1->SetParameter(0,0.885);
			TLatex *tex = new TLatex(3,1.5,"Fit: 0.89#pm0.03(stats.)#pm0.08(syst.)");
			tex->SetTextFont(43);
			tex->SetTextSize(20);
			tex->Draw();
		}else{
			f1->SetParameter(0,0.96);
			TLatex *tex = new TLatex(3,1.5,"Fit: 0.96#pm0.03(stats.)#pm0.05(syst.)");
			tex->SetTextFont(43);
			tex->SetTextSize(20);
			tex->Draw();
		}

		f1->SetLineColor(1);
		f1->SetLineWidth(3);
		f1->SetLineStyle(2);
		f1->Draw("same");

		gratio_sys[iarm]->SetMarkerStyle(20);
		gratio_sys[iarm]->SetMarkerColor(1);
		gratio_sys[iarm]->SetLineColor(1);
		gratio_sys[iarm]->SetFillStyle(0);
		gratio_sys[iarm]->Draw("2");

		gratio[iarm]->SetMarkerStyle(20);
		gratio[iarm]->SetMarkerColor(1);
		gratio[iarm]->Draw("p");


	}//iarm

	//return;

	// pAu with dAu
	for (int iarm=0; iarm<narm; iarm++){
		c1003[iarm] = new TCanvas(Form("c1003_%d",iarm),Form("c1003_%d",iarm),1.4*400,400);
		c1003[iarm]->cd(iarm+1);
		SetPadStyle();
		gPad->SetTopMargin(0.05);
		gPad->SetRightMargin(0.015);
		gPad->SetLeftMargin(0.12);
		gPad->SetBottomMargin(0.15);
		htmp = (TH1F*)gPad->DrawFrame(0,0,8.0,2.5);
		SetHistoStyle("p_{T} (GeV/c)","R_{AB}","",24,20);
		htmp->GetYaxis()->SetTitleOffset(0.8);
		htmp->GetXaxis()->SetTitleOffset(1.0);

		TLine *line = new TLine(0, 1, 8.0, 1);
		line->SetLineStyle(2);
		line->Draw();

		TGraphErrors *gr_pAu_sys_cp = new TGraphErrors(*gr_pAu_sys[3][iarm]);
		gr_pAu_sys_cp->SetName(Form("gr_pAu_sys_cp_arm%d",iarm));
		gr_pAu_sys_cp->SetMarkerStyle(20+iarm);
		gr_pAu_sys_cp->SetMarkerColor(kGreen+2);
		gr_pAu_sys_cp->SetLineColor(kGreen+2);

		TGraphErrors *gr_pAu_cp = new TGraphErrors(*gr_pAu[3][iarm]);
		gr_pAu_cp->SetName(Form("gr_pAu_cp_arm%d",iarm));
		gr_pAu_cp->SetMarkerStyle(20+iarm);
		gr_pAu_cp->SetMarkerColor(kGreen+2);
		gr_pAu_cp->SetLineColor(kGreen+2);

		TGraphErrors *gr_dAu_sys_cp = new TGraphErrors(*gr_dAu_sys[0][iarm]);
		gr_dAu_sys_cp->SetName(Form("gr_dAu_sys_cp_arm%d",iarm));
		gr_dAu_sys_cp->SetMarkerStyle(24+iarm);
		gr_dAu_sys_cp->SetMarkerColor(kBlue+2);
		gr_dAu_sys_cp->SetLineColor(kBlue+2);

		TGraphErrors *gr_dAu_cp = new TGraphErrors(*gr_dAu[0][iarm]);
		gr_dAu_cp->SetName(Form("gr_dAu_cp_arm%d",iarm));
		gr_dAu_cp->SetMarkerStyle(24+iarm);
		gr_dAu_cp->SetMarkerColor(kBlue+2);
		gr_dAu_cp->SetLineColor(kBlue+2);

		gr_pAu_sys_cp->Draw("2");
		gr_dAu_sys_cp->Draw("2");
		gr_pAu_cp->Draw("p");
		gr_dAu_cp->Draw("p");

		{
			TLegend *leg = new TLegend(0.15,0.71,0.6,0.92);
			leg->SetFillStyle(0);
			leg->SetBorderSize(0);
			leg->SetTextSize(22);
			le = leg->AddEntry("","Inclusive J/#psi","h");
			le = leg->AddEntry("","#sqrt{s_{NN}}=200 GeV","h");
			le = leg->AddEntry("","PHENIX","h");
			leg->Draw();
		}

		{
			float global_sys = sqrt(Ncoll_pAu_sys[3]*Ncoll_pAu_sys[3] + BiasF_pAu_sys[3]*BiasF_pAu_sys[3] + 0.101*0.101);
			TBox *box = new TBox(7.8,1-global_sys,8,1+global_sys);
			box->SetFillStyle(1000);
			box->SetFillColorAlpha(kGreen+2,0.5);
			box->Draw();
		}

		{
			float global_sys = sqrt(Ncoll_dAu_sys[0]*Ncoll_dAu_sys[0] + BiasF_dAu_sys[0]*BiasF_dAu_sys[0] + 0.101*0.101);
			TBox *box = new TBox(7.6,1-global_sys,7.8,1+global_sys);
			box->SetFillStyle(1000);
			box->SetFillColorAlpha(kBlue+2,0.5);
			box->Draw();
		}

		{
			TLatex *tex = new TLatex(7.2,1.5,Form("(%c)",97+iarm));
			tex->SetTextSize(22);
			tex->SetTextFont(43);
			tex->Draw();
		}

		{
			TLegend *leg;
			if ( iarm==1 ){
				leg = new TLegend(0.6,0.71,0.8,0.92);
			}else{
				leg = new TLegend(0.6,0.17,0.8,0.38);
			}
			leg->SetFillStyle(0);
			leg->SetBorderSize(0);
			leg->SetTextSize(24);
			if ( iarm==0 ){
				le = leg->AddEntry("","-2.2<y<-1.2","h");
			}else{
				le = leg->AddEntry("","1.2<y<2.2","h");
			}
			le = leg->AddEntry(gr_pAu_cp,"0%-20%, p+Au","p");
			le = leg->AddEntry(gr_dAu_cp,"0%-20%, d+Au","p");
			leg->Draw();
		}

	}//iarm

	TCanvas *c2003 = new TCanvas("c2003","c2003",1.3*2*400,400);
	pad = new TPad("c2003_p00","c2003_p00",0,0,0.53,1.0);
	pad->Draw();
	pad->cd();
	SetPadStyle();
	gPad->SetRightMargin(0.0);
	gPad->SetLeftMargin(0.14);
	gPad->SetBottomMargin(0.16);
	htmp = (TH1F*)gPad->DrawFrame(0,0,8.1,2.5);
	SetHistoStyle("p_{T} (GeV/c)","R_{AB}","",24,20);
	htmp->GetYaxis()->SetTitleOffset(0.9);
	htmp->GetXaxis()->SetTitleOffset(1.0);

	{
		int iarm = 0;

		TLine *line = new TLine(0, 1, 8.0, 1);
		line->SetLineStyle(2);
		line->Draw();

		TGraphErrors *gr_pAu_sys_cp = new TGraphErrors(*gr_pAu_sys[3][iarm]);
		gr_pAu_sys_cp->SetName(Form("gr_pAu_sys_cp_arm%d",iarm));
		gr_pAu_sys_cp->SetMarkerStyle(20+iarm);
		gr_pAu_sys_cp->SetMarkerColor(kGreen+2);
		gr_pAu_sys_cp->SetLineColor(kGreen+2);

		TGraphErrors *gr_pAu_cp = new TGraphErrors(*gr_pAu[3][iarm]);
		gr_pAu_cp->SetName(Form("gr_pAu_cp_arm%d",iarm));
		gr_pAu_cp->SetMarkerStyle(20+iarm);
		gr_pAu_cp->SetMarkerColor(kGreen+2);
		gr_pAu_cp->SetLineColor(kGreen+2);

		TGraphErrors *gr_dAu_sys_cp = new TGraphErrors(*gr_dAu_sys[0][iarm]);
		gr_dAu_sys_cp->SetName(Form("gr_dAu_sys_cp_arm%d",iarm));
		gr_dAu_sys_cp->SetMarkerStyle(24+iarm);
		gr_dAu_sys_cp->SetMarkerColor(kBlue+2);
		gr_dAu_sys_cp->SetLineColor(kBlue+2);

		TGraphErrors *gr_dAu_cp = new TGraphErrors(*gr_dAu[0][iarm]);
		gr_dAu_cp->SetName(Form("gr_dAu_cp_arm%d",iarm));
		gr_dAu_cp->SetMarkerStyle(24+iarm);
		gr_dAu_cp->SetMarkerColor(kBlue+2);
		gr_dAu_cp->SetLineColor(kBlue+2);

		gr_pAu_sys_cp->Draw("2");
		gr_dAu_sys_cp->Draw("2");
		gr_pAu_cp->Draw("p");
		gr_dAu_cp->Draw("p");

		{
			TLegend *leg = new TLegend(0.15,0.71,0.6,0.92);
			leg->SetFillStyle(0);
			leg->SetBorderSize(0);
			leg->SetTextSize(22);
			le = leg->AddEntry("","Inclusive J/#psi","h");
			le = leg->AddEntry("","#sqrt{s_{NN}}=200 GeV","h");
			le = leg->AddEntry("","PHENIX","h");
			leg->Draw();
		}

		{
			float global_sys = sqrt(Ncoll_pAu_sys[3]*Ncoll_pAu_sys[3] + BiasF_pAu_sys[3]*BiasF_pAu_sys[3] + 0.101*0.101);
			TBox *box = new TBox(7.9,1-global_sys,8.1,1+global_sys);
			box->SetFillStyle(1000);
			box->SetFillColorAlpha(kGreen+2,0.5);
			box->Draw();
		}

		{
			float global_sys = sqrt(Ncoll_dAu_sys[0]*Ncoll_dAu_sys[0] + BiasF_dAu_sys[0]*BiasF_dAu_sys[0] + 0.101*0.101);
			TBox *box = new TBox(7.7,1-global_sys,7.9,1+global_sys);
			box->SetFillStyle(1000);
			box->SetFillColorAlpha(kBlue+2,0.5);
			box->Draw();
		}

		{
			TLatex *tex = new TLatex(7.2,1.5,Form("(%c)",97+iarm));
			tex->SetTextSize(22);
			tex->SetTextFont(43);
			tex->Draw();
		}

		{
			TLegend *leg;
			if ( iarm==1 ){
				leg = new TLegend(0.6,0.71,0.8,0.92);
			}else{
				leg = new TLegend(0.6,0.17,0.8,0.38);
			}
			leg->SetFillStyle(0);
			leg->SetBorderSize(0);
			leg->SetTextSize(24);
			if ( iarm==0 ){
				le = leg->AddEntry("","-2.2<y<-1.2","h");
			}else{
				le = leg->AddEntry("","1.2<y<2.2","h");
			}
			le = leg->AddEntry(gr_pAu_cp,"0%-20%, p+Au","p");
			le = leg->AddEntry(gr_dAu_cp,"0%-20%, d+Au","p");
			leg->Draw();
		}
	}

	c2003->cd();
	pad = new TPad("c2003_p01","c2003_p01",0.53,0,1.0,1.0);
	pad->Draw();
	pad->cd();
	SetPadStyle();
	gPad->SetLeftMargin(0.0);
	gPad->SetBottomMargin(0.16);
	htmp = (TH1F*)gPad->DrawFrame(-0.1,0,8.1,2.5);
	SetHistoStyle("p_{T} (GeV/c)","R_{AB}","",24,20);
	htmp->GetYaxis()->SetTitleOffset(0.8);
	htmp->GetXaxis()->SetTitleOffset(1.0);

	{
		int iarm = 1;

		TLine *line = new TLine(0, 1, 8.0, 1);
		line->SetLineStyle(2);
		line->Draw();

		TGraphErrors *gr_pAu_sys_cp = new TGraphErrors(*gr_pAu_sys[3][iarm]);
		gr_pAu_sys_cp->SetName(Form("gr_pAu_sys_cp_arm%d",iarm));
		gr_pAu_sys_cp->SetMarkerStyle(20+iarm);
		gr_pAu_sys_cp->SetMarkerColor(kGreen+2);
		gr_pAu_sys_cp->SetLineColor(kGreen+2);

		TGraphErrors *gr_pAu_cp = new TGraphErrors(*gr_pAu[3][iarm]);
		gr_pAu_cp->SetName(Form("gr_pAu_cp_arm%d",iarm));
		gr_pAu_cp->SetMarkerStyle(20+iarm);
		gr_pAu_cp->SetMarkerColor(kGreen+2);
		gr_pAu_cp->SetLineColor(kGreen+2);

		TGraphErrors *gr_dAu_sys_cp = new TGraphErrors(*gr_dAu_sys[0][iarm]);
		gr_dAu_sys_cp->SetName(Form("gr_dAu_sys_cp_arm%d",iarm));
		gr_dAu_sys_cp->SetMarkerStyle(24+iarm);
		gr_dAu_sys_cp->SetMarkerColor(kBlue+2);
		gr_dAu_sys_cp->SetLineColor(kBlue+2);

		TGraphErrors *gr_dAu_cp = new TGraphErrors(*gr_dAu[0][iarm]);
		gr_dAu_cp->SetName(Form("gr_dAu_cp_arm%d",iarm));
		gr_dAu_cp->SetMarkerStyle(24+iarm);
		gr_dAu_cp->SetMarkerColor(kBlue+2);
		gr_dAu_cp->SetLineColor(kBlue+2);

		gr_pAu_sys_cp->Draw("2");
		gr_dAu_sys_cp->Draw("2");
		gr_pAu_cp->Draw("p");
		gr_dAu_cp->Draw("p");

		{
			TLegend *leg = new TLegend(0.01,0.71,0.45,0.92);
			leg->SetFillStyle(0);
			leg->SetBorderSize(0);
			leg->SetTextSize(22);
			le = leg->AddEntry("","Inclusive J/#psi","h");
			le = leg->AddEntry("","#sqrt{s_{NN}}=200 GeV","h");
			le = leg->AddEntry("","PHENIX","h");
			leg->Draw();
		}

		{
			float global_sys = sqrt(Ncoll_pAu_sys[3]*Ncoll_pAu_sys[3] + BiasF_pAu_sys[3]*BiasF_pAu_sys[3] + 0.101*0.101);
			TBox *box = new TBox(7.9,1-global_sys,8.1,1+global_sys);
			box->SetFillStyle(1000);
			box->SetFillColorAlpha(kGreen+2,0.5);
			box->Draw();
		}

		{
			float global_sys = sqrt(Ncoll_dAu_sys[0]*Ncoll_dAu_sys[0] + BiasF_dAu_sys[0]*BiasF_dAu_sys[0] + 0.101*0.101);
			TBox *box = new TBox(7.7,1-global_sys,7.9,1+global_sys);
			box->SetFillStyle(1000);
			box->SetFillColorAlpha(kBlue+2,0.5);
			box->Draw();
		}

		{
			TLatex *tex = new TLatex(7.2,1.5,Form("(%c)",97+iarm));
			tex->SetTextSize(22);
			tex->SetTextFont(43);
			tex->Draw();
		}

		{
			TLegend *leg;
			if ( iarm==1 ){
				leg = new TLegend(0.5,0.71,0.7,0.92);
			}else{
				leg = new TLegend(0.6,0.17,0.8,0.38);
			}
			leg->SetFillStyle(0);
			leg->SetBorderSize(0);
			leg->SetTextSize(24);
			if ( iarm==0 ){
				le = leg->AddEntry("","-2.2<y<-1.2","h");
			}else{
				le = leg->AddEntry("","1.2<y<2.2","h");
			}
			le = leg->AddEntry(gr_pAu_cp,"0%-20%, p+Au","p");
			le = leg->AddEntry(gr_dAu_cp,"0%-20%, d+Au","p");
			leg->Draw();
		}

	}


	TCanvas *c2002 = new TCanvas("c2002","c2002",1.3*2*400,400);
	pad = new TPad("c2002_p00","c2002_p00",0,0,0.53,1.0);
	pad->Draw();
	pad->cd();
	SetPadStyle();
	gPad->SetRightMargin(0.0);
	gPad->SetLeftMargin(0.14);
	gPad->SetBottomMargin(0.16);
	htmp = (TH1F*)gPad->DrawFrame(0,0,8.1,2.5);
	SetHistoStyle("p_{T} (GeV/c)","R_{AB}","",24,20);
	htmp->GetYaxis()->SetTitleOffset(0.9);
	htmp->GetXaxis()->SetTitleOffset(1.0);

	{
		int iarm = 0;

		TLine *line = new TLine(0, 1, 8, 1);
		line->SetLineStyle(2);
		line->Draw();

		TGraphErrors *gr_pAu_sys_cp = new TGraphErrors(*gr_pAu_sys[3][iarm]);
		gr_pAu_sys_cp->SetName(Form("gr_pAu_sys_cp_arm%d",iarm));
		gr_pAu_sys_cp->SetMarkerStyle(20+iarm);
		gr_pAu_sys_cp->SetMarkerColor(kGreen+2);
		gr_pAu_sys_cp->SetLineColor(kGreen+2);

		TGraphErrors *gr_pAu_cp = new TGraphErrors(*gr_pAu[3][iarm]);
		gr_pAu_cp->SetName(Form("gr_pAu_cp_arm%d",iarm));
		gr_pAu_cp->SetMarkerStyle(20+iarm);
		gr_pAu_cp->SetMarkerColor(kGreen+2);
		gr_pAu_cp->SetLineColor(kGreen+2);

		TGraphErrors *gr_pAl_sys_cp = new TGraphErrors(*gr_pAl_sys[0][iarm]);
		gr_pAl_sys_cp->SetName(Form("gr_pAl_sys_cp_arm%d",iarm));
		gr_pAl_sys_cp->SetMarkerStyle(24+iarm);
		gr_pAl_sys_cp->SetMarkerColor(2);
		gr_pAl_sys_cp->SetLineColor(2);

		TGraphErrors *gr_pAl_cp = new TGraphErrors(*gr_pAl[0][iarm]);
		gr_pAl_cp->SetName(Form("gr_pAl_cp_arm%d",iarm));
		gr_pAl_cp->SetMarkerStyle(24+iarm);
		gr_pAl_cp->SetMarkerColor(2);
		gr_pAl_cp->SetLineColor(2);

		gr_pAl_sys_cp->Draw("2");
		gr_pAu_sys_cp->Draw("2");
		gr_pAl_cp->Draw("p");
		gr_pAu_cp->Draw("p");

		{
			TLegend *leg = new TLegend(0.15,0.71,0.6,0.92);
			leg->SetFillStyle(0);
			leg->SetBorderSize(0);
			leg->SetTextSize(22);
			le = leg->AddEntry("","Inclusive J/#psi","h");
			le = leg->AddEntry("","#sqrt{s_{NN}}=200 GeV","h");
			le = leg->AddEntry("","PHENIX","h");
			leg->Draw();
		}

		{
			float global_sys = sqrt(Ncoll_pAu_sys[3]*Ncoll_pAu_sys[3] + BiasF_pAu_sys[3]*BiasF_pAu_sys[3] + 0.101*0.101);
			TBox *box = new TBox(7.9,1-global_sys,8.1,1+global_sys);
			box->SetFillStyle(1000);
			box->SetFillColorAlpha(kGreen+2,0.5);
			box->Draw();
		}

		{
			float global_sys = sqrt(Ncoll_pAl_sys[0]*Ncoll_pAl_sys[0] + BiasF_pAl_sys[0]*BiasF_pAl_sys[0] + 0.101*0.101);
			TBox *box = new TBox(7.7,1-global_sys,7.9,1+global_sys);
			box->SetFillStyle(1000);
			box->SetFillColorAlpha(2,0.5);
			box->Draw();
		}

		{
			TLatex *tex = new TLatex(7.2,1.5,Form("(%c)",97+iarm));
			tex->SetTextSize(22);
			tex->SetTextFont(43);
			tex->Draw();
		}

		{
			TLegend *leg = new TLegend(0.6,0.71,0.8,0.92);
			leg->SetFillStyle(0);
			leg->SetBorderSize(0);
			leg->SetTextSize(24);
			if ( iarm==0 ){
				le = leg->AddEntry("","-2.2<y<-1.2","h");
			}else{
				le = leg->AddEntry("","1.2<y<2.2","h");
			}
			le = leg->AddEntry(gr_pAl_cp,"0%-20%, p+Al","p");
			le = leg->AddEntry(gr_pAu_cp,"0%-20%, p+Au","p");
			leg->Draw();
		}
	}

	c2002->cd();
	pad = new TPad("c2002_p01","c2002_p01",0.53,0,1.0,1.0);
	pad->Draw();
	pad->cd();
	SetPadStyle();
	gPad->SetLeftMargin(0.0);
	gPad->SetBottomMargin(0.16);
	htmp = (TH1F*)gPad->DrawFrame(-0.1,0,8.1,2.5);
	SetHistoStyle("p_{T} (GeV/c)","R_{AB}","",24,20);
	htmp->GetYaxis()->SetTitleOffset(0.8);
	htmp->GetXaxis()->SetTitleOffset(1.0);

	{
		int iarm = 1;

		TLine *line = new TLine(0, 1, 8, 1);
		line->SetLineStyle(2);
		line->Draw();

		TGraphErrors *gr_pAu_sys_cp = new TGraphErrors(*gr_pAu_sys[3][iarm]);
		gr_pAu_sys_cp->SetName(Form("gr_pAu_sys_cp_arm%d",iarm));
		gr_pAu_sys_cp->SetMarkerStyle(20+iarm);
		gr_pAu_sys_cp->SetMarkerColor(kGreen+2);
		gr_pAu_sys_cp->SetLineColor(kGreen+2);

		TGraphErrors *gr_pAu_cp = new TGraphErrors(*gr_pAu[3][iarm]);
		gr_pAu_cp->SetName(Form("gr_pAu_cp_arm%d",iarm));
		gr_pAu_cp->SetMarkerStyle(20+iarm);
		gr_pAu_cp->SetMarkerColor(kGreen+2);
		gr_pAu_cp->SetLineColor(kGreen+2);

		TGraphErrors *gr_pAl_sys_cp = new TGraphErrors(*gr_pAl_sys[0][iarm]);
		gr_pAl_sys_cp->SetName(Form("gr_pAl_sys_cp_arm%d",iarm));
		gr_pAl_sys_cp->SetMarkerStyle(24+iarm);
		gr_pAl_sys_cp->SetMarkerColor(2);
		gr_pAl_sys_cp->SetLineColor(2);

		TGraphErrors *gr_pAl_cp = new TGraphErrors(*gr_pAl[0][iarm]);
		gr_pAl_cp->SetName(Form("gr_pAl_cp_arm%d",iarm));
		gr_pAl_cp->SetMarkerStyle(24+iarm);
		gr_pAl_cp->SetMarkerColor(2);
		gr_pAl_cp->SetLineColor(2);

		gr_pAl_sys_cp->Draw("2");
		gr_pAu_sys_cp->Draw("2");
		gr_pAl_cp->Draw("p");
		gr_pAu_cp->Draw("p");

		{
			TLegend *leg = new TLegend(0.02,0.71,0.48,0.92);
			leg->SetFillStyle(0);
			leg->SetBorderSize(0);
			leg->SetTextSize(22);
			le = leg->AddEntry("","Inclusive J/#psi","h");
			le = leg->AddEntry("","#sqrt{s_{NN}}=200 GeV","h");
			le = leg->AddEntry("","PHENIX","h");
			leg->Draw();
		}

		{
			float global_sys = sqrt(Ncoll_pAu_sys[3]*Ncoll_pAu_sys[3] + BiasF_pAu_sys[3]*BiasF_pAu_sys[3] + 0.101*0.101);
			TBox *box = new TBox(7.9,1-global_sys,8.1,1+global_sys);
			box->SetFillStyle(1000);
			box->SetFillColorAlpha(kGreen+2,0.5);
			box->Draw();
		}

		{
			float global_sys = sqrt(Ncoll_pAl_sys[0]*Ncoll_pAl_sys[0] + BiasF_pAl_sys[0]*BiasF_pAl_sys[0] + 0.101*0.101);
			TBox *box = new TBox(7.7,1-global_sys,7.9,1+global_sys);
			box->SetFillStyle(1000);
			box->SetFillColorAlpha(2,0.5);
			box->Draw();
		}

		{
			TLatex *tex = new TLatex(7.2,1.5,Form("(%c)",97+iarm));
			tex->SetTextSize(22);
			tex->SetTextFont(43);
			tex->Draw();
		}

		{
			TLegend *leg = new TLegend(0.5,0.71,0.7,0.92);
			leg->SetFillStyle(0);
			leg->SetBorderSize(0);
			leg->SetTextSize(24);
			if ( iarm==0 ){
				le = leg->AddEntry("","-2.2<y<-1.2","h");
			}else{
				le = leg->AddEntry("","1.2<y<2.2","h");
			}
			le = leg->AddEntry(gr_pAl_cp,"0%-20%, p+Al","p");
			le = leg->AddEntry(gr_pAu_cp,"0%-20%, p+Au","p");
			leg->Draw();
		}
	}

	TCanvas *c2004 = new TCanvas("c2004","c2004",1.3*2*400,600);
	pad = new TPad("c2004_p00","c2004_p00",0,0.44,0.53,1.0);
	pad->Draw();
	pad->cd();
	SetPadStyle();
	gPad->SetTopMargin(0.05);
	gPad->SetRightMargin(0.0);
	gPad->SetLeftMargin(0.12);
	gPad->SetBottomMargin(0.001);
	htmp = (TH1F*)gPad->DrawFrame(0,-0.1,8.1,2.5);
	SetHistoStyle("p_{T} (GeV/c)","R_{AB}","",24,20);
	htmp->GetYaxis()->SetTitleOffset(1.2);
	htmp->GetXaxis()->SetTitleOffset(1.0);

	{
		int iarm = 0;

		TLine *line = new TLine(0, 1, 8, 1);
		line->SetLineStyle(2);
		line->Draw();

		TGraphErrors *gr_pAu_sys_cp = new TGraphErrors(*gr_pAu_sys[3][iarm]);
		gr_pAu_sys_cp->SetName(Form("gr_pAu_sys_cp_arm%d",iarm));
		gr_pAu_sys_cp->SetMarkerStyle(20+iarm);
		gr_pAu_sys_cp->SetMarkerColor(kGreen+2);
		gr_pAu_sys_cp->SetLineColor(kGreen+2);

		TGraphErrors *gr_pAu_cp = new TGraphErrors(*gr_pAu[3][iarm]);
		gr_pAu_cp->SetName(Form("gr_pAu_cp_arm%d",iarm));
		gr_pAu_cp->SetMarkerStyle(20+iarm);
		gr_pAu_cp->SetMarkerColor(kGreen+2);
		gr_pAu_cp->SetLineColor(kGreen+2);

		TGraphErrors *gr_HeAu_sys_cp = new TGraphErrors(*gr_HeAu_sys[0][iarm]);
		gr_HeAu_sys_cp->SetName(Form("gr_HeAu_sys_cp_arm%d",iarm));
		gr_HeAu_sys_cp->SetMarkerStyle(24+iarm);
		gr_HeAu_sys_cp->SetMarkerColor(6);
		gr_HeAu_sys_cp->SetLineColor(6);

		TGraphErrors *gr_HeAu_cp = new TGraphErrors(*gr_HeAu[0][iarm]);
		gr_HeAu_cp->SetName(Form("gr_HeAu_cp_arm%d",iarm));
		gr_HeAu_cp->SetMarkerStyle(24+iarm);
		gr_HeAu_cp->SetMarkerColor(6);
		gr_HeAu_cp->SetLineColor(6);

		gr_HeAu_sys_cp->Draw("2");
		gr_pAu_sys_cp->Draw("2");
		gr_HeAu_cp->Draw("p");
		gr_pAu_cp->Draw("p");

		{
			TLegend *leg = new TLegend(0.15,0.71,0.6,0.92);
			leg->SetFillStyle(0);
			leg->SetBorderSize(0);
			leg->SetTextSize(22);
			le = leg->AddEntry("","Inclusive J/#psi","h");
			le = leg->AddEntry("","#sqrt{s_{NN}}=200 GeV","h");
			le = leg->AddEntry("","PHENIX","h");
			leg->Draw();
		}

		{
			float global_sys = sqrt(Ncoll_pAu_sys[3]*Ncoll_pAu_sys[3] + BiasF_pAu_sys[3]*BiasF_pAu_sys[3] + 0.101*0.101);
			TBox *box = new TBox(7.9,1-global_sys,8.1,1+global_sys);
			box->SetFillStyle(1000);
			box->SetFillColorAlpha(kGreen+2,0.5);
			box->Draw();
		}

		{
			float global_sys = sqrt(Ncoll_HeAu_sys[0]*Ncoll_HeAu_sys[0] + BiasF_HeAu_sys[0]*BiasF_HeAu_sys[0] + 0.101*0.101);
			TBox *box = new TBox(7.7,1-global_sys,7.9,1+global_sys);
			box->SetFillStyle(1000);
			box->SetFillColorAlpha(6,0.5);
			box->Draw();
		}

		{
			TLatex *tex = new TLatex(7.2,2.3,Form("(%c)",97+iarm));
			tex->SetTextSize(22);
			tex->SetTextFont(43);
			tex->Draw();
		}

		{
			TLegend *leg = new TLegend(0.6,0.71,0.8,0.92);
			leg->SetFillStyle(0);
			leg->SetBorderSize(0);
			leg->SetTextSize(24);
			if ( iarm==0 ){
				le = leg->AddEntry("","-2.2<y<-1.2","h");
			}else{
				le = leg->AddEntry("","1.2<y<2.2","h");
			}
			le = leg->AddEntry(gr_pAu_cp,"0%-20%, p+Au","p");
			le = leg->AddEntry(gr_HeAu_cp,"0%-20%, ^{3}He+Au","p");
			leg->Draw();
		}
	}

	c2004->cd();

	pad = new TPad(Form("c2004_p0000_%d_0",1),Form("c2004_p0000_%d_0",1),0, 0, 0.53, 0.441);
	pad->Draw();

	pad->cd();
	gPad->SetTopMargin(0.0);
	gPad->SetRightMargin(0.0);
	gPad->SetLeftMargin(0.12);
	gPad->SetBottomMargin(0.25);
	htmp = (TH1F*)gPad->DrawFrame(0,0.2,8.1,1.8);
	//SetHistoStyle("p_{T} (GeV/c)","R_{^{3}HeAu} / R_{pAu}","",26,22);
	SetHistoStyle("p_{T} (GeV/c)","^{3}He+Au / p+Au","",24,20);
	htmp->GetYaxis()->SetTitleOffset(1.2);
	htmp->GetYaxis()->CenterTitle();
	htmp->GetXaxis()->SetTitleOffset(2.3);
	htmp->GetYaxis()->SetNdivisions(7,5,0);

	{
		int iarm = 0;

		TF1 *f1 = new TF1("f1","[0]",0,7);

		if ( iarm==0 ){
			f1->SetParameter(0,0.885);
			TLatex *tex = new TLatex(3,1.5,"Fit: 0.89#pm0.03(stats.)#pm0.08(syst.)");
			tex->SetTextFont(43);
			tex->SetTextSize(20);
			tex->Draw();
		}else{
			f1->SetParameter(0,0.96);
			TLatex *tex = new TLatex(3,1.5,"Fit: 0.96#pm0.03(stats.)#pm0.05(syst.)");
			tex->SetTextFont(43);
			tex->SetTextSize(20);
			tex->Draw();
		}

		f1->SetLineColor(1);
		f1->SetLineWidth(3);
		f1->SetLineStyle(2);
		f1->Draw("same");

		gratio_sys[iarm]->SetMarkerStyle(20);
		gratio_sys[iarm]->SetMarkerColor(1);
		gratio_sys[iarm]->SetLineColor(1);
		gratio_sys[iarm]->SetFillStyle(0);
		gratio_sys[iarm]->Draw("2");

		gratio[iarm]->SetMarkerStyle(20);
		gratio[iarm]->SetMarkerColor(1);
		gratio[iarm]->Draw("p");
	}

	c2004->cd();
	pad = new TPad("c2004_p02","c2004_p02",0.53,0.44,1.0,1.0);
	pad->Draw();
	pad->cd();
	SetPadStyle();
	gPad->SetTopMargin(0.05);
	//gPad->SetRightMargin(0.015);
	gPad->SetLeftMargin(0.0);
	gPad->SetBottomMargin(0.001);
	htmp = (TH1F*)gPad->DrawFrame(-0.1,-0.1,8.1,2.5);
	SetHistoStyle("p_{T} (GeV/c)","R_{AB}","",24,20);
	htmp->GetYaxis()->SetTitleOffset(1.2);
	htmp->GetXaxis()->SetTitleOffset(1.0);

	{
		int iarm = 1;

		TLine *line = new TLine(0, 1, 8, 1);
		line->SetLineStyle(2);
		line->Draw();

		TGraphErrors *gr_pAu_sys_cp = new TGraphErrors(*gr_pAu_sys[3][iarm]);
		gr_pAu_sys_cp->SetName(Form("gr_pAu_sys_cp_arm%d",iarm));
		gr_pAu_sys_cp->SetMarkerStyle(20+iarm);
		gr_pAu_sys_cp->SetMarkerColor(kGreen+2);
		gr_pAu_sys_cp->SetLineColor(kGreen+2);

		TGraphErrors *gr_pAu_cp = new TGraphErrors(*gr_pAu[3][iarm]);
		gr_pAu_cp->SetName(Form("gr_pAu_cp_arm%d",iarm));
		gr_pAu_cp->SetMarkerStyle(20+iarm);
		gr_pAu_cp->SetMarkerColor(kGreen+2);
		gr_pAu_cp->SetLineColor(kGreen+2);

		TGraphErrors *gr_HeAu_sys_cp = new TGraphErrors(*gr_HeAu_sys[0][iarm]);
		gr_HeAu_sys_cp->SetName(Form("gr_HeAu_sys_cp_arm%d",iarm));
		gr_HeAu_sys_cp->SetMarkerStyle(24+iarm);
		gr_HeAu_sys_cp->SetMarkerColor(6);
		gr_HeAu_sys_cp->SetLineColor(6);

		TGraphErrors *gr_HeAu_cp = new TGraphErrors(*gr_HeAu[0][iarm]);
		gr_HeAu_cp->SetName(Form("gr_HeAu_cp_arm%d",iarm));
		gr_HeAu_cp->SetMarkerStyle(24+iarm);
		gr_HeAu_cp->SetMarkerColor(6);
		gr_HeAu_cp->SetLineColor(6);

		gr_HeAu_sys_cp->Draw("2");
		gr_pAu_sys_cp->Draw("2");
		gr_HeAu_cp->Draw("p");
		gr_pAu_cp->Draw("p");

		{
			TLegend *leg = new TLegend(0.03,0.71,0.48,0.92);
			leg->SetFillStyle(0);
			leg->SetBorderSize(0);
			leg->SetTextSize(22);
			le = leg->AddEntry("","Inclusive J/#psi","h");
			le = leg->AddEntry("","#sqrt{s_{NN}}=200 GeV","h");
			le = leg->AddEntry("","PHENIX","h");
			leg->Draw();
		}

		{
			float global_sys = sqrt(Ncoll_pAu_sys[3]*Ncoll_pAu_sys[3] + BiasF_pAu_sys[3]*BiasF_pAu_sys[3] + 0.101*0.101);
			TBox *box = new TBox(7.9,1-global_sys,8.1,1+global_sys);
			box->SetFillStyle(1000);
			box->SetFillColorAlpha(kGreen+2,0.5);
			box->Draw();
		}

		{
			float global_sys = sqrt(Ncoll_HeAu_sys[0]*Ncoll_HeAu_sys[0] + BiasF_HeAu_sys[0]*BiasF_HeAu_sys[0] + 0.101*0.101);
			TBox *box = new TBox(7.7,1-global_sys,7.9,1+global_sys);
			box->SetFillStyle(1000);
			box->SetFillColorAlpha(6,0.5);
			box->Draw();
		}

		{
			TLatex *tex = new TLatex(7.2,2.3,Form("(%c)",97+iarm));
			tex->SetTextSize(22);
			tex->SetTextFont(43);
			tex->Draw();
		}

		{
			TLegend *leg = new TLegend(0.5,0.71,0.7,0.92);
			leg->SetFillStyle(0);
			leg->SetBorderSize(0);
			leg->SetTextSize(24);
			if ( iarm==0 ){
				le = leg->AddEntry("","-2.2<y<-1.2","h");
			}else{
				le = leg->AddEntry("","1.2<y<2.2","h");
			}
			le = leg->AddEntry(gr_pAu_cp,"0%-20%, p+Au","p");
			le = leg->AddEntry(gr_HeAu_cp,"0%-20%, ^{3}He+Au","p");
			leg->Draw();
		}
	}


	c2004->cd();

	pad = new TPad(Form("c2004_p0003_%d_0",1),Form("c2004_p0003_%d_0",1),0.53, 0, 1.0, 0.441);
	pad->Draw();

	pad->cd();
	SetPadStyle();
	gPad->SetTopMargin(0.0);
	//gPad->SetRightMargin(0.015);
	gPad->SetLeftMargin(0.0);
	gPad->SetBottomMargin(0.25);
	htmp = (TH1F*)gPad->DrawFrame(-0.1,0.2,8.1,1.8);
	//SetHistoStyle("p_{T} (GeV/c)","R_{^{3}HeAu} / R_{pAu}","",26,22);
	SetHistoStyle("p_{T} (GeV/c)","^{3}He+Au / p+Au","",24,20);
	htmp->GetYaxis()->SetTitleOffset(1.2);
	htmp->GetYaxis()->CenterTitle();
	htmp->GetXaxis()->SetTitleOffset(2.3);
	htmp->GetYaxis()->SetNdivisions(7,5,0);

	{
		int iarm = 1;

		TF1 *f1 = new TF1("f1","[0]",0,7);

		if ( iarm==0 ){
			f1->SetParameter(0,0.885);
			TLatex *tex = new TLatex(3,1.5,"Fit: 0.89#pm0.03(stats.)#pm0.08(syst.)");
			tex->SetTextFont(43);
			tex->SetTextSize(20);
			tex->Draw();
		}else{
			f1->SetParameter(0,0.96);
			TLatex *tex = new TLatex(3,1.5,"Fit: 0.96#pm0.03(stats.)#pm0.05(syst.)");
			tex->SetTextFont(43);
			tex->SetTextSize(20);
			tex->Draw();
		}

		f1->SetLineColor(1);
		f1->SetLineWidth(3);
		f1->SetLineStyle(2);
		f1->Draw("same");

		gratio_sys[iarm]->SetMarkerStyle(20);
		gratio_sys[iarm]->SetMarkerColor(1);
		gratio_sys[iarm]->SetLineColor(1);
		gratio_sys[iarm]->SetFillStyle(0);
		gratio_sys[iarm]->Draw("2");

		gratio[iarm]->SetMarkerStyle(20);
		gratio[iarm]->SetMarkerColor(1);
		gratio[iarm]->Draw("p");
	}

	TFile *infile_th0_pAu = new TFile("RpAu_transport_cent.root","read");

	TGraphAsymmErrors *gth_transport_pAu[narm][ncentbin_pAu];
	gth_transport_pAu[0][0] = (TGraphAsymmErrors*)infile_th0_pAu->Get("RpAu_transport_010_bkwd");
	gth_transport_pAu[1][0] = (TGraphAsymmErrors*)infile_th0_pAu->Get("RpAu_transport_010_fwd");
	gth_transport_pAu[0][1] = (TGraphAsymmErrors*)infile_th0_pAu->Get("RpAu_transport_1020_bkwd");
	gth_transport_pAu[1][1] = (TGraphAsymmErrors*)infile_th0_pAu->Get("RpAu_transport_1020_fwd");
	gth_transport_pAu[0][2] = (TGraphAsymmErrors*)infile_th0_pAu->Get("RpAu_transport_2040_bkwd");
	gth_transport_pAu[1][2] = (TGraphAsymmErrors*)infile_th0_pAu->Get("RpAu_transport_2040_fwd");
	gth_transport_pAu[0][3] = (TGraphAsymmErrors*)infile_th0_pAu->Get("RpAu_transport_4060_bkwd");
	gth_transport_pAu[1][3] = (TGraphAsymmErrors*)infile_th0_pAu->Get("RpAu_transport_4060_fwd");
	gth_transport_pAu[0][4] = (TGraphAsymmErrors*)infile_th0_pAu->Get("RpAu_transport_6080_bkwd");
	gth_transport_pAu[1][4] = (TGraphAsymmErrors*)infile_th0_pAu->Get("RpAu_transport_6080_fwd");

	for (int iarm=0; iarm<narm; iarm++){
		for(int icent = 0 ; icent<5;icent++){
			gth_transport_pAu[0][icent]->SetFillColorAlpha(1,0.3);
			gth_transport_pAu[0][icent]->SetFillStyle(1001);
			gth_transport_pAu[0][icent]->SetLineColor(0);
			gth_transport_pAu[1][icent]->SetFillColorAlpha(2,0.3);
			gth_transport_pAu[1][icent]->SetFillStyle(1001);
			gth_transport_pAu[1][icent]->SetLineColor(0);

		}
	}

	TCanvas *c23 = new TCanvas("c23","c23",1.3*3*400,2*350);

	pad = new TPad("c23_pad0","c23_pad0",0.0,0.0,0.35,0.53);
	pad->Draw();
	pad->cd();
	SetPadStyle();
	gPad->SetTopMargin(0.00);
	gPad->SetRightMargin(0.0);
	gPad->SetLeftMargin(0.13);
	gPad->SetBottomMargin(0.17);
	htmp = (TH1F*)gPad->DrawFrame(0.0,0,7.8,2.6);
	SetHistoStyle("p_{T} (GeV/c) ","R_{AB}   ","",28,24);
	htmp->GetYaxis()->SetTitleOffset(1.5);
	htmp->GetXaxis()->SetTitleOffset(1.7);

	gth_transport_pAu[0][2]->Draw("3");
	{
		int icent = 4;
		gr_pAu_sys[icent][0]->Draw("2");
		gr_pAu[icent][0]->Draw("p");

		{
			TLegend *leg = new TLegend(0.17,0.72,0.6,0.93);
			leg->SetFillStyle(0);
			leg->SetBorderSize(0);
			leg->SetTextSize(24);
			le = leg->AddEntry("","Inclusive J/#psi","h");
			le = leg->AddEntry("","#sqrt{s_{NN}}=200 GeV","h");
			le = leg->AddEntry("","PHENIX","h");
			leg->Draw();

			TLine *line = new TLine(0, 1, 8, 1);
			line->SetLineStyle(2);
			line->Draw();

			float global_sys = sqrt(Ncoll_pAu_sys[icent]*Ncoll_pAu_sys[icent] + BiasF_pAu_sys[icent]*BiasF_pAu_sys[icent] + 0.101*0.101);
			TBox *box = new TBox(7.6,1-global_sys,7.8,1+global_sys);
			box->SetFillStyle(1000);
			box->SetFillColorAlpha(1,0.5);
			box->Draw();
		}

		{
			TLegend *leg = new TLegend(0.65,0.72,0.95,0.93);
			leg->SetFillStyle(0);
			leg->SetBorderSize(0);
			leg->SetTextSize(24);
			le = leg->AddEntry("",Form("%d%c-%d%c, p+Au",cent_per_pAu_min[icent],'%',cent_per_pAu_max[icent],'%'),"h");
			le = leg->AddEntry(gr_pAu[icent][0],"-2.2<y<-1.2","p");
			leg->AddEntry("","","");
			leg->Draw();
		}

		{
			TLatex *tex = new TLatex(7.2, 1.5, Form("(d)"));
			tex->SetTextFont(43);
			tex->SetTextSize(24);
			tex->Draw();
		}
		{
			TLegend *leg = new TLegend(0.15,0.2,0.65,0.3);
			leg->SetFillStyle(0);
			leg->SetBorderSize(0);
			leg->SetTextSize(22);
			le = leg->AddEntry(gth_transport_pAu[0][2],"EPS09NLO+Transport (Du & Rapp)","F");
			leg->Draw();
		}
	}

	c23->cd();
	pad = new TPad("c23_pad00","c23_pad00",0.0,0.53,0.35,1.0);
	pad->Draw();
	pad->cd();
	SetPadStyle();
	gPad->SetTopMargin(0.03);
	gPad->SetRightMargin(0.0);
	gPad->SetLeftMargin(0.13);
	gPad->SetBottomMargin(0.0);
	htmp = (TH1F*)gPad->DrawFrame(0.0,-0.1,7.8,2.5);
	SetHistoStyle("p_{T} (GeV/c) ","R_{AB}   ","",28,24);
	htmp->GetYaxis()->SetTitleOffset(1.2);
	htmp->GetXaxis()->SetTitleOffset(1.0);

	gth_transport_pAu[0][0]->Draw("3");
	{
		int icent = 0;
		gr_pAu_sys[icent][0]->Draw("2");
		gr_pAu[icent][0]->Draw("p");

		{
			TLegend *leg = new TLegend(0.17,0.7,0.6,0.93);
			leg->SetFillStyle(0);
			leg->SetBorderSize(0);
			leg->SetTextSize(24);
			le = leg->AddEntry("","Inclusive J/#psi","h");
			le = leg->AddEntry("","#sqrt{s_{NN}}=200 GeV","h");
			le = leg->AddEntry("","PHENIX","h");
			leg->Draw();

			TLine *line = new TLine(0, 1, 8, 1);
			line->SetLineStyle(2);
			line->Draw();

			float global_sys = sqrt(Ncoll_pAu_sys[icent]*Ncoll_pAu_sys[icent] + BiasF_pAu_sys[icent]*BiasF_pAu_sys[icent] + 0.101*0.101);
			TBox *box = new TBox(7.6,1-global_sys,7.8,1+global_sys);
			box->SetFillStyle(1000);
			box->SetFillColorAlpha(1,0.5);
			box->Draw();
		}

		{
			TLegend *leg = new TLegend(0.65,0.7,0.95,0.93);
			leg->SetFillStyle(0);
			leg->SetBorderSize(0);
			leg->SetTextSize(24);
			le = leg->AddEntry("",Form("%d%c-%d%c, p+Au",cent_per_pAu_min[icent],'%',cent_per_pAu_max[icent],'%'),"h");
			le = leg->AddEntry(gr_pAu[icent][0],"-2.2<y<-1.2","p");
			leg->AddEntry("","","");
			leg->Draw();
		}

		{
			TLatex *tex = new TLatex(7.2, 1.5, Form("(a)"));
			tex->SetTextFont(43);
			tex->SetTextSize(24);
			tex->Draw();
		}

		{
			TLegend *leg = new TLegend(0.15,0.05,0.65,0.165);
			leg->SetFillStyle(0);
			leg->SetBorderSize(0);
			leg->SetTextSize(22);
			le = leg->AddEntry(gth_transport_pAu[0][2],"EPS09NLO+Transport (Du & Rapp)","F");
			leg->Draw();
		}
	}

	c23->cd();
	pad = new TPad("c23_pad1","c23_pad1",0.35,0.0,0.67,0.53);
	pad->Draw();
	pad->cd();
	SetPadStyle();
	gPad->SetTopMargin(0.00);
	gPad->SetRightMargin(0.00);
	gPad->SetLeftMargin(0.0);
	gPad->SetBottomMargin(0.17);
	htmp = (TH1F*)gPad->DrawFrame(-0.1,0,7.8,2.6);
	SetHistoStyle("p_{T} (GeV/c) ","R_{AB}   ","",28,24);
	htmp->GetYaxis()->SetTitleOffset(1.2);
	htmp->GetXaxis()->SetTitleOffset(1.7);

	gth_transport_pAu[0][3]->Draw("3");
	{
		int icent = 5;
		gr_pAu_sys[icent][0]->Draw("2");
		gr_pAu[icent][0]->Draw("p");

		{
			TLegend *leg = new TLegend(0.05,0.72,0.45,0.93);
			leg->SetFillStyle(0);
			leg->SetBorderSize(0);
			leg->SetTextSize(24);
			le = leg->AddEntry("","Inclusive J/#psi","h");
			le = leg->AddEntry("","#sqrt{s_{NN}}=200 GeV","h");
			le = leg->AddEntry("","PHENIX","h");
			leg->Draw();

			TLine *line = new TLine(0, 1, 8, 1);
			line->SetLineStyle(2);
			line->Draw();

			float global_sys = sqrt(Ncoll_pAu_sys[icent]*Ncoll_pAu_sys[icent] + BiasF_pAu_sys[icent]*BiasF_pAu_sys[icent] + 0.101*0.101);
			TBox *box = new TBox(7.6,1-global_sys,7.8,1+global_sys);
			box->SetFillStyle(1000);
			box->SetFillColorAlpha(1,0.5);
			box->Draw();
		}

		{
			TLegend *leg = new TLegend(0.6,0.72,0.9,0.93);
			leg->SetFillStyle(0);
			leg->SetBorderSize(0);
			leg->SetTextSize(24);
			le = leg->AddEntry("",Form("%d%c-%d%c, p+Au",cent_per_pAu_min[icent],'%',cent_per_pAu_max[icent],'%'),"h");
			le = leg->AddEntry(gr_pAu[icent][0],"-2.2<y<-1.2","p");
			leg->AddEntry("","","");
			leg->Draw();
		}

		{
			TLatex *tex = new TLatex(7.2, 1.5, Form("(e)"));
			tex->SetTextFont(43);
			tex->SetTextSize(24);
			tex->Draw();
		}

		{
			TLegend *leg = new TLegend(0.05,0.2,0.55,0.3);
			leg->SetFillStyle(0);
			leg->SetBorderSize(0);
			leg->SetTextSize(22);
			le = leg->AddEntry(gth_transport_pAu[0][2],"EPS09NLO+Transport (Du & Rapp)","F");
			leg->Draw();
		}
	}


	c23->cd();
	pad = new TPad("c23_pad11","c23_pad11",0.35,0.53,0.67,1.0);
	pad->Draw();
	pad->cd();
	SetPadStyle();
	gPad->SetTopMargin(0.03);
	gPad->SetRightMargin(0.00);
	gPad->SetLeftMargin(0.0);
	gPad->SetBottomMargin(0.0);
	htmp = (TH1F*)gPad->DrawFrame(-0.1,-0.1,7.8,2.5);
	SetHistoStyle("p_{T} (GeV/c) ","R_{AB}   ","",28,24);
	htmp->GetYaxis()->SetTitleOffset(1.2);
	htmp->GetXaxis()->SetTitleOffset(1.0);

	gth_transport_pAu[0][0]->Draw("3");
	{
		int icent = 1;
		gr_pAu_sys[icent][0]->Draw("2");
		gr_pAu[icent][0]->Draw("p");

		{
			TLegend *leg = new TLegend(0.05,0.7,0.45,0.93);
			leg->SetFillStyle(0);
			leg->SetBorderSize(0);
			leg->SetTextSize(24);
			le = leg->AddEntry("","Inclusive J/#psi","h");
			le = leg->AddEntry("","#sqrt{s_{NN}}=200 GeV","h");
			le = leg->AddEntry("","PHENIX","h");
			leg->Draw();

			TLine *line = new TLine(0, 1, 8, 1);
			line->SetLineStyle(2);
			line->Draw();

			float global_sys = sqrt(Ncoll_pAu_sys[icent]*Ncoll_pAu_sys[icent] + BiasF_pAu_sys[icent]*BiasF_pAu_sys[icent] + 0.101*0.101);
			TBox *box = new TBox(7.6,1-global_sys,7.8,1+global_sys);
			box->SetFillStyle(1000);
			box->SetFillColorAlpha(1,0.5);
			box->Draw();
		}

		{
			TLegend *leg = new TLegend(0.6,0.7,0.9,0.93);
			leg->SetFillStyle(0);
			leg->SetBorderSize(0);
			leg->SetTextSize(24);
			le = leg->AddEntry("",Form("%d%c-%d%c, p+Au",cent_per_pAu_min[icent],'%',cent_per_pAu_max[icent],'%'),"h");
			le = leg->AddEntry(gr_pAu[icent][0],"-2.2<y<-1.2","p");
			leg->AddEntry("","","");
			leg->Draw();
		}

		{
			TLatex *tex = new TLatex(7.2, 1.5, Form("(b)"));
			tex->SetTextFont(43);
			tex->SetTextSize(24);
			tex->Draw();
		}

		{
			TLegend *leg = new TLegend(0.05,0.05,0.55,0.165);
			leg->SetFillStyle(0);
			leg->SetBorderSize(0);
			leg->SetTextSize(22);
			le = leg->AddEntry(gth_transport_pAu[0][2],"EPS09NLO+Transport (Du & Rapp)","F");
			leg->Draw();
		}
	}

	c23->cd();
	pad = new TPad("c23_pad2","c23_pad2",0.67,0.0,0.99,0.53);
	pad->Draw();
	pad->cd();
	SetPadStyle();
	gPad->SetTopMargin(0.00);
	gPad->SetRightMargin(0.00);
	gPad->SetLeftMargin(0.0);
	gPad->SetBottomMargin(0.17);
	htmp = (TH1F*)gPad->DrawFrame(-0.1,0,7.8,2.6);
	SetHistoStyle("p_{T} (GeV/c) ","R_{AB}   ","",28,24);
	htmp->GetYaxis()->SetTitleOffset(1.2);
	htmp->GetXaxis()->SetTitleOffset(1.7);

	gth_transport_pAu[0][4]->Draw("3");
	{
		int icent = 6;
		gr_pAu_sys[icent][0]->Draw("2");
		gr_pAu[icent][0]->Draw("p");

		{
			TLegend *leg = new TLegend(0.05,0.72,0.45,0.93);
			leg->SetFillStyle(0);
			leg->SetBorderSize(0);
			leg->SetTextSize(24);
			le = leg->AddEntry("","Inclusive J/#psi","h");
			le = leg->AddEntry("","#sqrt{s_{NN}}=200 GeV","h");
			le = leg->AddEntry("","PHENIX","h");
			leg->Draw();

			TLine *line = new TLine(0, 1, 8, 1);
			line->SetLineStyle(2);
			line->Draw();

			float global_sys = sqrt(Ncoll_pAu_sys[icent]*Ncoll_pAu_sys[icent] + BiasF_pAu_sys[icent]*BiasF_pAu_sys[icent] + 0.101*0.101);
			TBox *box = new TBox(7.6,1-global_sys,7.8,1+global_sys);
			box->SetFillStyle(1000);
			box->SetFillColorAlpha(1,0.5);
			box->Draw();
		}

		{
			TLegend *leg = new TLegend(0.6,0.72,0.9,0.93);
			leg->SetFillStyle(0);
			leg->SetBorderSize(0);
			leg->SetTextSize(24);
			le = leg->AddEntry("",Form("%d%c-%d%c, p+Au",cent_per_pAu_min[icent],'%',cent_per_pAu_max[icent],'%'),"h");
			le = leg->AddEntry(gr_pAu[icent][0],"-2.2<y<-1.2","p");
			leg->AddEntry("","","");
			leg->Draw();
		}

		{
			TLatex *tex = new TLatex(7.2, 1.5, Form("(f)"));
			tex->SetTextFont(43);
			tex->SetTextSize(24);
			tex->Draw();
		}

		{
			TLegend *leg = new TLegend(0.05,0.2,0.55,0.3);
			leg->SetFillStyle(0);
			leg->SetBorderSize(0);
			leg->SetTextSize(22);
			le = leg->AddEntry(gth_transport_pAu[0][2],"EPS09NLO+Transport (Du & Rapp)","F");
			leg->Draw();
		}
	}

	c23->cd();
	pad = new TPad("c23_pad22","c23_pad22",0.67,0.53,0.99,1.0);
	pad->Draw();
	pad->cd();
	SetPadStyle();
	gPad->SetTopMargin(0.03);
	gPad->SetRightMargin(0.00);
	gPad->SetLeftMargin(0.0);
	gPad->SetBottomMargin(0.0);
	htmp = (TH1F*)gPad->DrawFrame(-0.1,-0.1,7.8,2.5);
	SetHistoStyle("p_{T} (GeV/c)   ","R_{AB}   ","",28,24);
	htmp->GetYaxis()->SetTitleOffset(1.2);
	htmp->GetXaxis()->SetTitleOffset(1.0);

	gth_transport_pAu[0][1]->Draw("3");
	{
		int icent = 2;
		gr_pAu_sys[icent][0]->Draw("2");
		gr_pAu[icent][0]->Draw("p");

		{
			TLegend *leg = new TLegend(0.05,0.7,0.45,0.93);
			leg->SetFillStyle(0);
			leg->SetBorderSize(0);
			leg->SetTextSize(24);
			le = leg->AddEntry("","Inclusive J/#psi","h");
			le = leg->AddEntry("","#sqrt{s_{NN}}=200 GeV","h");
			le = leg->AddEntry("","PHENIX","h");
			leg->Draw();

			TLine *line = new TLine(0, 1, 8, 1);
			line->SetLineStyle(2);
			line->Draw();

			float global_sys = sqrt(Ncoll_pAu_sys[icent]*Ncoll_pAu_sys[icent] + BiasF_pAu_sys[icent]*BiasF_pAu_sys[icent] + 0.101*0.101);
			TBox *box = new TBox(7.6,1-global_sys,7.8,1+global_sys);
			box->SetFillStyle(1000);
			box->SetFillColorAlpha(1,0.5);
			box->Draw();
		}

		{
			TLegend *leg = new TLegend(0.6,0.7,0.9,0.93);
			leg->SetFillStyle(0);
			leg->SetBorderSize(0);
			leg->SetTextSize(24);
			le = leg->AddEntry("",Form("%d%c-%d%c, p+Au",cent_per_pAu_min[icent],'%',cent_per_pAu_max[icent],'%'),"h");
			le = leg->AddEntry(gr_pAu[icent][0],"-2.2<y<-1.2","p");
			leg->AddEntry("","","");
			leg->Draw();
		}

		{
			TLatex *tex = new TLatex(7.2, 1.5, Form("(c)"));
			tex->SetTextFont(43);
			tex->SetTextSize(24);
			tex->Draw();
		}

		{
			TLegend *leg = new TLegend(0.05,0.05,0.55,0.165);
			leg->SetFillStyle(0);
			leg->SetBorderSize(0);
			leg->SetTextSize(22);
			le = leg->AddEntry(gth_transport_pAu[0][2],"EPS09NLO+Transport (Du & Rapp)","F");
			leg->Draw();
		}
	}

	TCanvas *c33 = new TCanvas("c33","c33",1.3*3*400,2*350);

	pad = new TPad("c33_pad0","c33_pad0",0.0,0.0,0.35,0.53);
	pad->Draw();
	pad->cd();
	SetPadStyle();
	gPad->SetTopMargin(0.00);
	gPad->SetRightMargin(0.0);
	gPad->SetLeftMargin(0.13);
	gPad->SetBottomMargin(0.17);
	htmp = (TH1F*)gPad->DrawFrame(0.0,0,7.8,2.6);
	SetHistoStyle("p_{T} (GeV/c) ","R_{AB}   ","",28,24);
	htmp->GetYaxis()->SetTitleOffset(1.5);
	htmp->GetXaxis()->SetTitleOffset(1.7);

	gth_transport_pAu[1][2]->Draw("3");
	{
		int icent = 4;
		gr_pAu_sys[icent][1]->Draw("2");
		gr_pAu[icent][1]->Draw("p");

		{
			TLegend *leg = new TLegend(0.17,0.72,0.6,0.93);
			leg->SetFillStyle(0);
			leg->SetBorderSize(0);
			leg->SetTextSize(24);
			le = leg->AddEntry("","Inclusive J/#psi","h");
			le = leg->AddEntry("","#sqrt{s_{NN}}=200 GeV","h");
			le = leg->AddEntry("","PHENIX","h");
			leg->Draw();

			TLine *line = new TLine(0, 1, 8, 1);
			line->SetLineStyle(2);
			line->Draw();

			float global_sys = sqrt(Ncoll_pAu_sys[icent]*Ncoll_pAu_sys[icent] + BiasF_pAu_sys[icent]*BiasF_pAu_sys[icent] + 0.101*0.101);
			TBox *box = new TBox(7.6,1-global_sys,7.8,1+global_sys);
			box->SetFillStyle(1000);
			box->SetFillColorAlpha(1,0.5);
			box->Draw();
		}

		{
			TLegend *leg = new TLegend(0.65,0.72,0.95,0.93);
			leg->SetFillStyle(0);
			leg->SetBorderSize(0);
			leg->SetTextSize(24);
			le = leg->AddEntry("",Form("%d%c-%d%c, p+Au",cent_per_pAu_min[icent],'%',cent_per_pAu_max[icent],'%'),"h");
			le = leg->AddEntry(gr_pAu[icent][1],"1.2<y<2.2","p");
			leg->AddEntry("","","");
			leg->Draw();
		}

		{
			TLatex *tex = new TLatex(7.2, 1.5, Form("(d)"));
			tex->SetTextFont(43);
			tex->SetTextSize(24);
			tex->Draw();
		}

		{
			TLegend *leg = new TLegend(0.15,0.2,0.65,0.3);
			leg->SetFillStyle(0);
			leg->SetBorderSize(0);
			leg->SetTextSize(22);
			le = leg->AddEntry(gth_transport_pAu[1][2],"EPS09NLO+Transport (Du & Rapp)","F");
			leg->Draw();
		}
	}

	c33->cd();
	pad = new TPad("c33_pad00","c33_pad00",0.0,0.53,0.35,1.0);
	pad->Draw();
	pad->cd();
	SetPadStyle();
	gPad->SetTopMargin(0.03);
	gPad->SetRightMargin(0.0);
	gPad->SetLeftMargin(0.13);
	gPad->SetBottomMargin(0.0);
	htmp = (TH1F*)gPad->DrawFrame(0.0,-0.1,7.8,2.5);
	SetHistoStyle("p_{T} (GeV/c) ","R_{AB}   ","",28,24);
	htmp->GetYaxis()->SetTitleOffset(1.2);
	htmp->GetXaxis()->SetTitleOffset(1.0);

	gth_transport_pAu[1][0]->Draw("3");
	{
		int icent = 0;
		gr_pAu_sys[icent][1]->Draw("2");
		gr_pAu[icent][1]->Draw("p");

		{
			TLegend *leg = new TLegend(0.17,0.7,0.6,0.93);
			leg->SetFillStyle(0);
			leg->SetBorderSize(0);
			leg->SetTextSize(24);
			le = leg->AddEntry("","Inclusive J/#psi","h");
			le = leg->AddEntry("","#sqrt{s_{NN}}=200 GeV","h");
			le = leg->AddEntry("","PHENIX","h");
			leg->Draw();

			TLine *line = new TLine(0, 1, 8, 1);
			line->SetLineStyle(2);
			line->Draw();

			float global_sys = sqrt(Ncoll_pAu_sys[icent]*Ncoll_pAu_sys[icent] + BiasF_pAu_sys[icent]*BiasF_pAu_sys[icent] + 0.101*0.101);
			TBox *box = new TBox(7.6,1-global_sys,7.8,1+global_sys);
			box->SetFillStyle(1000);
			box->SetFillColorAlpha(1,0.5);
			box->Draw();
		}

		{
			TLegend *leg = new TLegend(0.65,0.7,0.95,0.93);
			leg->SetFillStyle(0);
			leg->SetBorderSize(0);
			leg->SetTextSize(24);
			le = leg->AddEntry("",Form("%d%c-%d%c, p+Au",cent_per_pAu_min[icent],'%',cent_per_pAu_max[icent],'%'),"h");
			le = leg->AddEntry(gr_pAu[icent][1],"1.2<y<2.2","p");
			leg->AddEntry("","","");
			leg->Draw();
		}

		{
			TLatex *tex = new TLatex(7.2, 1.5, Form("(a)"));
			tex->SetTextFont(43);
			tex->SetTextSize(24);
			tex->Draw();
		}

		{
			TLegend *leg = new TLegend(0.15,0.05,0.65,0.165);
			leg->SetFillStyle(0);
			leg->SetBorderSize(0);
			leg->SetTextSize(22);
			le = leg->AddEntry(gth_transport_pAu[1][2],"EPS09NLO+Transport (Du & Rapp)","F");
			leg->Draw();
		}
	}

	c33->cd();
	pad = new TPad("c33_pad1","c33_pad1",0.35,0.0,0.67,0.53);
	pad->Draw();
	pad->cd();
	SetPadStyle();
	gPad->SetTopMargin(0.00);
	gPad->SetRightMargin(0.00);
	gPad->SetLeftMargin(0.0);
	gPad->SetBottomMargin(0.17);
	htmp = (TH1F*)gPad->DrawFrame(-0.1,0,7.8,2.5);
	SetHistoStyle("p_{T} (GeV/c) ","R_{AB}   ","",28,24);
	htmp->GetYaxis()->SetTitleOffset(1.2);
	htmp->GetXaxis()->SetTitleOffset(1.7);

	gth_transport_pAu[1][3]->Draw("3");
	{
		int icent = 5;
		gr_pAu_sys[icent][1]->Draw("2");
		gr_pAu[icent][1]->Draw("p");

		{
			TLegend *leg = new TLegend(0.05,0.72,0.45,0.93);
			leg->SetFillStyle(0);
			leg->SetBorderSize(0);
			leg->SetTextSize(24);
			le = leg->AddEntry("","Inclusive J/#psi","h");
			le = leg->AddEntry("","#sqrt{s_{NN}}=200 GeV","h");
			le = leg->AddEntry("","PHENIX","h");
			leg->Draw();

			TLine *line = new TLine(0, 1, 8, 1);
			line->SetLineStyle(2);
			line->Draw();

			float global_sys = sqrt(Ncoll_pAu_sys[icent]*Ncoll_pAu_sys[icent] + BiasF_pAu_sys[icent]*BiasF_pAu_sys[icent] + 0.101*0.101);
			TBox *box = new TBox(7.6,1-global_sys,7.8,1+global_sys);
			box->SetFillStyle(1000);
			box->SetFillColorAlpha(1,0.5);
			box->Draw();
		}

		{
			TLegend *leg = new TLegend(0.6,0.72,0.9,0.93);
			leg->SetFillStyle(0);
			leg->SetBorderSize(0);
			leg->SetTextSize(24);
			le = leg->AddEntry("",Form("%d%c-%d%c, p+Au",cent_per_pAu_min[icent],'%',cent_per_pAu_max[icent],'%'),"h");
			le = leg->AddEntry(gr_pAu[icent][1],"1.2<y<2.2","p");
			leg->AddEntry("","","");
			leg->Draw();
		}

		{
			TLatex *tex = new TLatex(7.2, 1.5, Form("(e)"));
			tex->SetTextFont(43);
			tex->SetTextSize(24);
			tex->Draw();
		}

		{
			TLegend *leg = new TLegend(0.05,0.2,0.55,0.3);
			leg->SetFillStyle(0);
			leg->SetBorderSize(0);
			leg->SetTextSize(22);
			le = leg->AddEntry(gth_transport_pAu[1][2],"EPS09NLO+Transport (Du & Rapp)","F");
			leg->Draw();
		}
	}

	c33->cd();
	pad = new TPad("c33_pad11","c33_pad11",0.35,0.53,0.67,1.0);
	pad->Draw();
	pad->cd();
	SetPadStyle();
	gPad->SetTopMargin(0.03);
	gPad->SetRightMargin(0.00);
	gPad->SetLeftMargin(0.0);
	gPad->SetBottomMargin(0.0);
	htmp = (TH1F*)gPad->DrawFrame(-0.1,-0.1,7.8,2.5);
	SetHistoStyle("p_{T} (GeV/c) ","R_{AB}   ","",28,24);
	htmp->GetYaxis()->SetTitleOffset(1.2);
	htmp->GetXaxis()->SetTitleOffset(1.0);

	gth_transport_pAu[1][0]->Draw("3");
	{
		int icent = 1;
		gr_pAu_sys[icent][1]->Draw("2");
		gr_pAu[icent][1]->Draw("p");

		{
			TLegend *leg = new TLegend(0.05,0.7,0.45,0.93);
			leg->SetFillStyle(0);
			leg->SetBorderSize(0);
			leg->SetTextSize(24);
			le = leg->AddEntry("","Inclusive J/#psi","h");
			le = leg->AddEntry("","#sqrt{s_{NN}}=200 GeV","h");
			le = leg->AddEntry("","PHENIX","h");
			leg->Draw();

			TLine *line = new TLine(0, 1, 8, 1);
			line->SetLineStyle(2);
			line->Draw();

			float global_sys = sqrt(Ncoll_pAu_sys[icent]*Ncoll_pAu_sys[icent] + BiasF_pAu_sys[icent]*BiasF_pAu_sys[icent] + 0.101*0.101);
			TBox *box = new TBox(7.6,1-global_sys,7.8,1+global_sys);
			box->SetFillStyle(1000);
			box->SetFillColorAlpha(1,0.5);
			box->Draw();
		}

		{
			TLegend *leg = new TLegend(0.6,0.7,0.9,0.93);
			leg->SetFillStyle(0);
			leg->SetBorderSize(0);
			leg->SetTextSize(24);
			le = leg->AddEntry("",Form("%d%c-%d%c, p+Au",cent_per_pAu_min[icent],'%',cent_per_pAu_max[icent],'%'),"h");
			le = leg->AddEntry(gr_pAu[icent][1],"1.2<y<2.2","p");
			leg->AddEntry("","","");
			leg->Draw();
		}

		{
			TLatex *tex = new TLatex(7.2, 1.5, Form("(b)"));
			tex->SetTextFont(43);
			tex->SetTextSize(24);
			tex->Draw();
		}

		{
			TLegend *leg = new TLegend(0.05,0.05,0.55,0.165);
			leg->SetFillStyle(0);
			leg->SetBorderSize(0);
			leg->SetTextSize(22);
			le = leg->AddEntry(gth_transport_pAu[1][2],"EPS09NLO+Transport (Du & Rapp)","F");
			leg->Draw();
		}
	}

	c33->cd();
	pad = new TPad("c33_pad2","c33_pad2",0.67,0.0,0.99,0.53);
	pad->Draw();
	pad->cd();
	SetPadStyle();
	gPad->SetTopMargin(0.00);
	gPad->SetRightMargin(0.00);
	gPad->SetLeftMargin(0.0);
	gPad->SetBottomMargin(0.17);
	htmp = (TH1F*)gPad->DrawFrame(-0.1,0,7.8,2.5);
	SetHistoStyle("p_{T} (GeV/c) ","R_{AB}   ","",28,24);
	htmp->GetYaxis()->SetTitleOffset(1.2);
	htmp->GetXaxis()->SetTitleOffset(1.7);

	gth_transport_pAu[1][4]->Draw("3");
	{
		int icent = 6;
		gr_pAu_sys[icent][1]->Draw("2");
		gr_pAu[icent][1]->Draw("p");

		{
			TLegend *leg = new TLegend(0.05,0.72,0.45,0.93);
			leg->SetFillStyle(0);
			leg->SetBorderSize(0);
			leg->SetTextSize(24);
			le = leg->AddEntry("","Inclusive J/#psi","h");
			le = leg->AddEntry("","#sqrt{s_{NN}}=200 GeV","h");
			le = leg->AddEntry("","PHENIX","h");
			leg->Draw();

			TLine *line = new TLine(0, 1, 8, 1);
			line->SetLineStyle(2);
			line->Draw();

			float global_sys = sqrt(Ncoll_pAu_sys[icent]*Ncoll_pAu_sys[icent] + BiasF_pAu_sys[icent]*BiasF_pAu_sys[icent] + 0.101*0.101);
			TBox *box = new TBox(7.6,1-global_sys,7.8,1+global_sys);
			box->SetFillStyle(1000);
			box->SetFillColorAlpha(1,0.5);
			box->Draw();
		}

		{
			TLegend *leg = new TLegend(0.6,0.72,0.9,0.93);
			leg->SetFillStyle(0);
			leg->SetBorderSize(0);
			leg->SetTextSize(24);
			le = leg->AddEntry("",Form("%d%c-%d%c, p+Au",cent_per_pAu_min[icent],'%',cent_per_pAu_max[icent],'%'),"h");
			le = leg->AddEntry(gr_pAu[icent][1],"1.2<y<2.2","p");
			leg->AddEntry("","","");
			leg->Draw();
		}

		{
			TLatex *tex = new TLatex(7.2, 1.5, Form("(f)"));
			tex->SetTextFont(43);
			tex->SetTextSize(24);
			tex->Draw();
		}

		{
			TLegend *leg = new TLegend(0.05,0.2,0.55,0.3);
			leg->SetFillStyle(0);
			leg->SetBorderSize(0);
			leg->SetTextSize(22);
			le = leg->AddEntry(gth_transport_pAu[1][2],"EPS09NLO+Transport (Du & Rapp)","F");
			leg->Draw();
		}
	}

	c33->cd();
	pad = new TPad("c33_pad22","c33_pad22",0.67,0.53,0.99,1.0);
	pad->Draw();
	pad->cd();
	SetPadStyle();
	gPad->SetTopMargin(0.03);
	gPad->SetRightMargin(0.00);
	gPad->SetLeftMargin(0.0);
	gPad->SetBottomMargin(0.0);
	htmp = (TH1F*)gPad->DrawFrame(-0.1,-0.1,7.8,2.5);
	SetHistoStyle("p_{T} (GeV/c)   ","R_{AB}   ","",28,24);
	htmp->GetYaxis()->SetTitleOffset(1.2);
	htmp->GetXaxis()->SetTitleOffset(1.0);

	gth_transport_pAu[1][1]->Draw("3");
	{
		int icent = 2;
		gr_pAu_sys[icent][1]->Draw("2");
		gr_pAu[icent][1]->Draw("p");

		{
			TLegend *leg = new TLegend(0.05,0.7,0.45,0.93);
			leg->SetFillStyle(0);
			leg->SetBorderSize(0);
			leg->SetTextSize(24);
			le = leg->AddEntry("","Inclusive J/#psi","h");
			le = leg->AddEntry("","#sqrt{s_{NN}}=200 GeV","h");
			le = leg->AddEntry("","PHENIX","h");
			leg->Draw();

			TLine *line = new TLine(0, 1, 8, 1);
			line->SetLineStyle(2);
			line->Draw();

			float global_sys = sqrt(Ncoll_pAu_sys[icent]*Ncoll_pAu_sys[icent] + BiasF_pAu_sys[icent]*BiasF_pAu_sys[icent] + 0.101*0.101);
			TBox *box = new TBox(7.6,1-global_sys,7.8,1+global_sys);
			box->SetFillStyle(1000);
			box->SetFillColorAlpha(1,0.5);
			box->Draw();
		}

		{
			TLegend *leg = new TLegend(0.6,0.7,0.9,0.93);
			leg->SetFillStyle(0);
			leg->SetBorderSize(0);
			leg->SetTextSize(24);
			le = leg->AddEntry("",Form("%d%c-%d%c, p+Au",cent_per_pAu_min[icent],'%',cent_per_pAu_max[icent],'%'),"h");
			le = leg->AddEntry(gr_pAu[icent][1],"1.2<y<2.2","p");
			leg->AddEntry("","","");
			leg->Draw();
		}

		{
			TLatex *tex = new TLatex(7.2, 1.5, Form("(c)"));
			tex->SetTextFont(43);
			tex->SetTextSize(24);
			tex->Draw();
		}

		{
			TLegend *leg = new TLegend(0.05,0.05,0.55,0.165);
			leg->SetFillStyle(0);
			leg->SetBorderSize(0);
			leg->SetTextSize(22);
			le = leg->AddEntry(gth_transport_pAu[1][2],"EPS09NLO+Transport (Du & Rapp)","F");
			leg->Draw();
		}
	}

	//return;

	if ( bSAVE ){
		c00->cd();
		c00->SaveAs("pdf/fig_RAB_pT_pAu.pdf");

		for (int icent=0; icent<ncentbin_pAu; icent++){
			if ( icent==3 ) continue;
			c000[icent]->cd();
			c000[icent]->SaveAs(Form("pdf/fig_RAB_pT_pAu_centbin%d.pdf",icent));
		}

		c01->cd();
		c01->SaveAs("pdf/fig_RAB_pT_pAl.pdf");

		for (int icent=0; icent<ncentbin_pAl; icent++){
			c001[icent]->cd();
			c001[icent]->SaveAs(Form("pdf/fig_RAB_pT_pAl_centbin%d.pdf",icent));
		}

		c02->cd();
		c02->SaveAs("pdf/fig_RAB_pT_HeAu.pdf");

		for (int icent=0; icent<ncentbin_HeAu; icent++){
			c002[icent]->cd();
			c002[icent]->SaveAs(Form("pdf/fig_RAB_pT_HeAu_centbin%d.pdf",icent));
		}

		for (int iarm=0; iarm<narm; iarm++){
			c0002[iarm]->cd();
			c0002[iarm]->SaveAs(Form("pdf/fig_RAB_pT_pAl_pAu_0020_arm%d.pdf",iarm));

			c0003[iarm]->cd();
			c0003[iarm]->SaveAs(Form("pdf/fig_RAB_pT_pAu_HeAu_0020_arm%d.pdf",iarm));

			c0004[iarm]->cd();
			c0004[iarm]->SaveAs(Form("pdf/fig_RAB_pT_pAu_HeAu_0020_arm%d_ratio.pdf",iarm));

			c1003[iarm]->cd();
			c1003[iarm]->SaveAs(Form("pdf/fig_RAB_pT_pAu_dAu_0020_arm%d.pdf",iarm));
		}//iarm

		c2002->cd();
		c2002->SaveAs(Form("pdf/fig_RAB_pT_pAl_pAu_0020_combined_ratio.pdf"));

		c2004->cd();
		c2004->SaveAs(Form("pdf/fig_RAB_pT_pAu_HeAu_0020_combined_ratio.pdf"));

		c2003->cd();
		c2003->SaveAs(Form("pdf/fig_RAB_pT_pAu_dAu_0020_combined_ratio.pdf"));

		c1002->cd();
		c1002->SaveAs("pdf/fig_RAB_pT_pAl_combined.pdf");

		c0001->cd();
		c0001->SaveAs("pdf/fig_RAB_pT_HeAu_combined.pdf");

		c23->cd();
		c23->SaveAs("pdf/fig_RAB_pT_pAu_arm0_combined.pdf");

		c33->cd();
		c33->SaveAs("pdf/fig_RAB_pT_pAu_arm1_combined.pdf");
	}


}



