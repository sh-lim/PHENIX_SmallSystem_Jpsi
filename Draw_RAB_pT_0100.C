#include "Style.h"

void Draw_RAB_pT_0100()
{

	const bool bSAVE = true;

	SetStyle();
	gStyle->SetLegendTextSize(18);

  char name1[500];
  char name2[500];
  char name3[500];

	TFile *file_pAu;	  
	TFile *file_pAl;	  
	TFile *file_HeAu;	  

	const int narm = 2;
	const int nptbin_pAu = 26;
	const int nptbin_pAl = 20;
	const int nptbin_HeAu = 19;

	const int ncentbin_pAu = 1;
	const int ncentbin_pAl = 1;
	const int ncentbin_HeAu = 1;

	const int cent_per_pAu_min[ncentbin_pAu] = {0};
	const int cent_per_pAu_max[ncentbin_pAu] = {100};

	const int cent_per_pAl_min[ncentbin_pAl] = {0};
	const int cent_per_pAl_max[ncentbin_pAl] = {100};

	const int cent_per_HeAu_min[ncentbin_HeAu] = {0};
	const int cent_per_HeAu_max[ncentbin_HeAu] = {100};

	const char c_arm[narm] = {'S', 'N'};

	const double Ncoll_pAu_sys[ncentbin_pAu] = {0.3/4.7};
	const double BiasF_pAu_sys[ncentbin_pAu] = {0.014/0.858};

	const double Ncoll_pAl_sys[ncentbin_pAl] = {0.1/2.1};
	  const double BiasF_pAl_sys[ncentbin_pAl] = {0.02/0.80};

	  const double Ncoll_HeAu_sys[ncentbin_HeAu] = {0.7/10.4};
	  const double BiasF_HeAu_sys[ncentbin_HeAu] = {0.01/0.89};

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

	file_pAu = new TFile("RpAu_YpAu_vs_pT_0100.root","read");
	file_pAl = new TFile("RpAl_YpAl_vs_pT_0100.root","read");
	file_HeAu = new TFile("RHeAu_YHeAu_vs_pT_0100.root","read");

	for (int iarm=0; iarm<narm; iarm++){
		for (int icent=0; icent<ncentbin_pAu; icent++){
			RpAu[icent][iarm] = (TH1F*)file_pAu->Get(Form("RpAu_vs_pT_%c_%d%d",c_arm[iarm],cent_per_pAu_min[icent],cent_per_pAu_max[icent]));
			RpAu_SYS_FRAC_ERR[icent][iarm] = (TH1F*)file_pAu->Get(Form("RpAu_vs_pT_%c_%d%d_sys_frac",c_arm[iarm],cent_per_pAu_min[icent],cent_per_pAu_max[icent]));
		}
		RpAl[0][iarm] = (TH1F*)file_pAl->Get(Form("RpAl_vs_pT_%c_0100",c_arm[iarm]));
	
		RpAl_SYS_FRAC_ERR[0][iarm] = (TH1F*)file_pAl->Get(Form("RpAl_vs_pT_%c_0100_sys_frac",c_arm[iarm]));
	
		RHeAu[0][iarm] = (TH1F*)file_HeAu->Get(Form("RHeAu_vs_pT_%c_0100",c_arm[iarm]));
	
		RHeAu_SYS_FRAC_ERR[0][iarm] = (TH1F*)file_HeAu->Get(Form("RHeAu_vs_pT_%c_0100_sys_frac",c_arm[iarm]));
	}

	//Theory
	TFile *infile_th0_HeAu = new TFile("RHeAu_MB_predictions.root","read");
	TFile *infile_th0_pAu = new TFile("RpAu_MB_predictions.root","read");
	TFile *infile_th0_pAl = new TFile("RpAl_MB_predictions.root","read");

	TGraphAsymmErrors *gth_epps_HeAu[narm];
	TGraphAsymmErrors *gth_ncteq_HeAu[narm];
	gth_epps_HeAu[0] = (TGraphAsymmErrors*)infile_th0_HeAu->Get("RHeAu_epps_MB_predictions_bkwd");
	gth_epps_HeAu[1] = (TGraphAsymmErrors*)infile_th0_HeAu->Get("RHeAu_epps_MB_predictions_fwd");
	gth_ncteq_HeAu[0] = (TGraphAsymmErrors*)infile_th0_HeAu->Get("RHeAu_ncteq_MB_predictions_bkwd");
	gth_ncteq_HeAu[1] = (TGraphAsymmErrors*)infile_th0_HeAu->Get("RHeAu_ncteq_MB_predictions_fwd");

	TGraphAsymmErrors *gth_epps_pAu[narm];
	TGraphAsymmErrors *gth_ncteq_pAu[narm];
	gth_epps_pAu[0] = (TGraphAsymmErrors*)infile_th0_pAu->Get("RpAu_epps_MB_predictions_bkwd");
	gth_epps_pAu[1] = (TGraphAsymmErrors*)infile_th0_pAu->Get("RpAu_epps_MB_predictions_fwd");
	gth_ncteq_pAu[0] = (TGraphAsymmErrors*)infile_th0_pAu->Get("RpAu_ncteq_MB_predictions_bkwd");
	gth_ncteq_pAu[1] = (TGraphAsymmErrors*)infile_th0_pAu->Get("RpAu_ncteq_MB_predictions_fwd");

	TGraphAsymmErrors *gth_epps_pAl[narm];
	TGraphAsymmErrors *gth_ncteq_pAl[narm];
	gth_epps_pAl[0] = (TGraphAsymmErrors*)infile_th0_pAl->Get("RpAl_epps_MB_predictions_bkwd");
	gth_epps_pAl[1] = (TGraphAsymmErrors*)infile_th0_pAl->Get("RpAl_epps_MB_predictions_fwd");
	gth_ncteq_pAl[0] = (TGraphAsymmErrors*)infile_th0_pAl->Get("RpAl_ncteq_MB_predictions_bkwd");
	gth_ncteq_pAl[1] = (TGraphAsymmErrors*)infile_th0_pAl->Get("RpAl_ncteq_MB_predictions_fwd");

	for (int iarm=0; iarm<narm; iarm++){
		gth_epps_HeAu[iarm]->SetFillColorAlpha(4,0.3);
		gth_epps_HeAu[iarm]->SetLineColor(0);
		gth_ncteq_HeAu[iarm]->SetFillColorAlpha(1,0.3);
		gth_ncteq_HeAu[iarm]->SetFillStyle(3344);
		gth_ncteq_HeAu[iarm]->SetLineColor(0);

		gth_epps_pAu[iarm]->SetFillColorAlpha(4,0.3);
		gth_epps_pAu[iarm]->SetLineColor(0);
		gth_ncteq_pAu[iarm]->SetFillColorAlpha(1,0.3);
		gth_ncteq_pAu[iarm]->SetFillStyle(3344);
		gth_ncteq_pAu[iarm]->SetLineColor(0);

		gth_epps_pAl[iarm]->SetFillColorAlpha(4,0.3);
		gth_epps_pAl[iarm]->SetLineColor(0);
		gth_ncteq_pAl[iarm]->SetFillColorAlpha(1,0.3);
		gth_ncteq_pAl[iarm]->SetFillStyle(3344);
		gth_ncteq_pAl[iarm]->SetLineColor(0);
	}

	TGraphErrors *gr_pAu[ncentbin_pAu][narm];
	TGraphErrors *gr_pAl[ncentbin_pAl][narm];
	TGraphErrors *gr_HeAu[ncentbin_HeAu][narm];

	TGraphErrors *gr_pAu_sys[ncentbin_pAu][narm];
	TGraphErrors *gr_pAl_sys[ncentbin_pAl][narm];
	TGraphErrors *gr_HeAu_sys[ncentbin_HeAu][narm];

	//plot arrays
	double pt_array_pAu[nptbin_pAu] =  {0.125,0.375,0.625,0.875,1.125,1.375,1.625,1.875,2.125,2.375,2.625,2.875,3.125,3.375,3.625,3.875,4.125,4.375,4.625,4.875,5.125,5.375,5.625,5.875,6.25,6.75};
	double pt_array_pAl[nptbin_pAl] =  {0.125,0.375,0.625,0.875,1.125,1.375,1.625,1.875,2.125,2.375,2.625,2.875,3.125,3.375,3.625,3.875,4.25,4.75,5.5,6.5};
	double pt_array_HeAu[nptbin_HeAu] = {0.125,0.375,0.625,0.875,1.125,1.375,1.625,1.875,2.125,2.375,2.625, 2.875,3.125,3.375,3.625,3.875,4.25,4.75,6.0};

       
       
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

	TCanvas *c00 = new TCanvas("c00","c00",1.3*400,1*400);
	TCanvas *c000[narm];

	for (int icent=0; icent<ncentbin_pAu; icent++){
		SetPadStyle();
		gPad->SetRightMargin(0.02);
		gPad->SetLeftMargin(0.14);
		gPad->SetBottomMargin(0.15);
		htmp = (TH1F*)gPad->DrawFrame(0,0,8.0,2.5);
		SetHistoStyle("p_{T} (GeV/c)","R_{AB}","",24,20);
		htmp->GetYaxis()->SetTitleOffset(1.0);
		htmp->GetXaxis()->SetTitleOffset(1.0);

		{
			TLegend *leg = new TLegend(0.20,0.73,0.6,0.93);
			leg->SetFillStyle(0);
			leg->SetBorderSize(0);
			le = leg->AddEntry("","p+Au #sqrt{s_{NN}}=200 GeV","h");
			le = leg->AddEntry("","Inclusive J/#psi","h");
			le = leg->AddEntry("",Form("%d%c-%d%c",cent_per_pAu_min[icent],'%',cent_per_pAu_max[icent],'%'),"h");
			leg->Draw();

			TLine *line = new TLine(0, 1, 8.0, 1);
			line->SetLineStyle(2);
			line->Draw();

			float global_sys = sqrt(Ncoll_pAu_sys[icent]*Ncoll_pAu_sys[icent] + BiasF_pAu_sys[icent]*BiasF_pAu_sys[icent] + 0.101*0.101);
			TBox *box = new TBox(7.7,1-global_sys,8.0,1+global_sys);
			box->SetFillStyle(1000);
			box->SetFillColorAlpha(1,0.5);
			box->Draw();
		}

		{
			TLegend *leg = new TLegend(0.15,0.6,0.5,0.7);
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
	}

	for (int iarm=0; iarm<narm; iarm++){
		c000[iarm] = new TCanvas(Form("c000_arm%d",iarm),Form("c000_arm%d",iarm),1.3*400,1*400);

		for (int icent=0; icent<ncentbin_pAu; icent++){
			SetPadStyle();
			gPad->SetRightMargin(0.02);
			gPad->SetLeftMargin(0.14);
			gPad->SetBottomMargin(0.15);
			htmp = (TH1F*)gPad->DrawFrame(0,0,8.0,2.5);
			SetHistoStyle("p_{T} (GeV/c)","R_{AB}","",24,20);
			htmp->GetYaxis()->SetTitleOffset(1.0);
			htmp->GetXaxis()->SetTitleOffset(1.0);

			{
				TLegend *leg = new TLegend(0.20,0.65,0.6,0.9);
				leg->SetFillStyle(0);
				leg->SetBorderSize(0);
				le = leg->AddEntry("","p+Au #sqrt{s_{NN}}=200 GeV","h");
				le->SetTextSize(20);
				le = leg->AddEntry("",Form("%d%c-%d%c",cent_per_pAu_min[icent],'%',cent_per_pAu_max[icent],'%'),"h");
				le->SetTextSize(20);
				le = leg->AddEntry("","Inclusive J/#psi","h");
				le->SetTextSize(20);
				if ( iarm==0 ){
					le = leg->AddEntry("","-2.2<y<-1.2","h");
				}else{
					le = leg->AddEntry("","1.2<y<2.2","h");
				}
				le->SetTextSize(20);
				leg->Draw();

				TLine *line = new TLine(0, 1, 8.0, 1);
				line->SetLineStyle(2);
				line->Draw();

				float global_sys = sqrt(Ncoll_pAu_sys[icent]*Ncoll_pAu_sys[icent] + BiasF_pAu_sys[icent]*BiasF_pAu_sys[icent] + 0.101*0.101);
				TBox *box = new TBox(7.7,1-global_sys,8.0,1+global_sys);
				box->SetFillStyle(1000);
				box->SetFillColorAlpha(1,0.5);
				box->Draw();
			}

			{
				TLatex *tex = new TLatex(0.5,0.15,"PHENIX");
				tex->SetTextSize(20);
				tex->SetTextFont(43);
				tex->Draw();
			}

			{
				TLatex *tex = new TLatex(7.2,2.25,"(b)");
				tex->SetTextSize(20);
				tex->SetTextFont(43);
				tex->Draw();
			}

			gth_epps_pAu[iarm]->Draw("3");
			gth_ncteq_pAu[iarm]->Draw("3");

			gr_pAu_sys[icent][iarm]->Draw("2");
			gr_pAu[icent][iarm]->Draw("p");

			{
				TLegend *leg = new TLegend(0.7,0.18,0.9,0.3);
				leg->SetFillStyle(0);
				le = leg->AddEntry(gth_epps_pAu[iarm],"EPPS16","f");
				le->SetTextSize(20);
				le = leg->AddEntry(gth_ncteq_pAu[iarm],"nCTEQ15","f");
				le->SetTextSize(20);
				leg->Draw();
			}
		}
	}

	//return;

	TCanvas *c01 = new TCanvas("c01","c01",1.3*400,1*400);
	TCanvas *c001[narm];

	for (int icent=0; icent<ncentbin_pAl; icent++){
		SetPadStyle();
		gPad->SetRightMargin(0.02);
		gPad->SetLeftMargin(0.14);
		gPad->SetBottomMargin(0.15);
		htmp = (TH1F*)gPad->DrawFrame(0,0,8,2.5);
		SetHistoStyle("p_{T} (GeV/c)","R_{AB}","",24,20);
		htmp->GetYaxis()->SetTitleOffset(1.0);
		htmp->GetXaxis()->SetTitleOffset(1.0);

		{
			TLegend *leg = new TLegend(0.20,0.73,0.6,0.93);
			leg->SetFillStyle(0);
			leg->SetBorderSize(0);
			le = leg->AddEntry("","p+Al #sqrt{s_{NN}}=200 GeV","h");
			le = leg->AddEntry("","Inclusive J/#psi","h");
			le = leg->AddEntry("",Form("%d%c-%d%c",cent_per_pAl_min[icent],'%',cent_per_pAl_max[icent],'%'),"h");
			leg->Draw();

			TLine *line = new TLine(0, 1, 8.0, 1);
			line->SetLineStyle(2);
			line->Draw();

			float global_sys = sqrt(Ncoll_pAl_sys[icent]*Ncoll_pAl_sys[icent] + BiasF_pAl_sys[icent]*BiasF_pAl_sys[icent] + 0.101*0.101);
			TBox *box = new TBox(7.7,1-global_sys,8.0,1+global_sys);
			box->SetFillStyle(1000);
			box->SetFillColorAlpha(1,0.5);
			box->Draw();
		}

		{
			TLegend *leg = new TLegend(0.15,0.6,0.5,0.7);
			leg->SetFillStyle(0);
			leg->SetBorderSize(0);
			leg->AddEntry(gr_pAl[icent][0],"-2.2<y<-1.2","p");
			leg->AddEntry(gr_pAl[icent][1],"1.2<y<2.2","p");
			leg->Draw();
		}

		for (int iarm=0; iarm<narm; iarm++){
			gr_pAl_sys[icent][iarm]->Draw("2");
			gr_pAl[icent][iarm]->Draw("p");
		}
	}

	for (int iarm=0; iarm<narm; iarm++){
		c001[iarm] = new TCanvas(Form("c001_arm%d",iarm),Form("c001_arm%d",iarm),1.3*400,1*400);

		for (int icent=0; icent<ncentbin_pAu; icent++){
			SetPadStyle();
			gPad->SetRightMargin(0.02);
			gPad->SetLeftMargin(0.14);
			gPad->SetBottomMargin(0.15);
			htmp = (TH1F*)gPad->DrawFrame(0,0,8.0,2.5);
			SetHistoStyle("p_{T} (GeV/c)","R_{AB}","",24,20);
			htmp->GetYaxis()->SetTitleOffset(1.0);
			htmp->GetXaxis()->SetTitleOffset(1.0);

			{
				TLegend *leg = new TLegend(0.20,0.65,0.6,0.9);
				leg->SetFillStyle(0);
				leg->SetBorderSize(0);
				le = leg->AddEntry("","p+Al #sqrt{s_{NN}}=200 GeV","h");
				le->SetTextSize(20);
				le = leg->AddEntry("",Form("%d%c-%d%c",cent_per_pAu_min[icent],'%',cent_per_pAu_max[icent],'%'),"h");
				le->SetTextSize(20);
				le = leg->AddEntry("","Inclusive J/#psi","h");
				le->SetTextSize(20);
				if ( iarm==0 ){
					le = leg->AddEntry("","-2.2<y<-1.2","h");
				}else{
					le = leg->AddEntry("","1.2<y<2.2","h");
				}
				le->SetTextSize(20);
				leg->Draw();

				TLine *line = new TLine(0, 1, 8.0, 1);
				line->SetLineStyle(2);
				line->Draw();

				float global_sys = sqrt(Ncoll_pAl_sys[icent]*Ncoll_pAl_sys[icent] + BiasF_pAl_sys[icent]*BiasF_pAl_sys[icent] + 0.101*0.101);
				TBox *box = new TBox(7.7,1-global_sys,8.0,1+global_sys);
				box->SetFillStyle(1000);
				box->SetFillColorAlpha(1,0.5);
				box->Draw();
			}

			{
				TLatex *tex = new TLatex(0.5,0.15,"PHENIX");
				tex->SetTextSize(20);
				tex->SetTextFont(43);
				tex->Draw();
			}

			{
				TLatex *tex = new TLatex(7.2,2.25,"(a)");
				tex->SetTextSize(20);
				tex->SetTextFont(43);
				tex->Draw();
			}

			gth_epps_pAl[iarm]->Draw("3");
			gth_ncteq_pAl[iarm]->Draw("3");

			gr_pAl_sys[icent][iarm]->Draw("2");
			gr_pAl[icent][iarm]->Draw("p");

			{
				TLegend *leg = new TLegend(0.7,0.18,0.9,0.3);
				leg->SetFillStyle(0);
				le = leg->AddEntry(gth_epps_pAu[iarm],"EPPS16","f");
				le->SetTextSize(20);
				le = leg->AddEntry(gth_ncteq_pAu[iarm],"nCTEQ15","f");
				le->SetTextSize(20);
				leg->Draw();
			}
		}
	}


	TCanvas *c02 = new TCanvas("c02","c02",1.3*400,1*400);
	TCanvas *c002[narm];

	for (int icent=0; icent<ncentbin_HeAu; icent++){
		SetPadStyle();
		gPad->SetRightMargin(0.02);
		gPad->SetLeftMargin(0.14);
		gPad->SetBottomMargin(0.15);
		htmp = (TH1F*)gPad->DrawFrame(0,0,8,2.5);
		SetHistoStyle("p_{T} (GeV/c)","R_{AB}","",24,20);
		htmp->GetYaxis()->SetTitleOffset(1.0);
		htmp->GetXaxis()->SetTitleOffset(1.0);

		{
			TLegend *leg = new TLegend(0.20,0.73,0.6,0.93);
			leg->SetFillStyle(0);
			leg->SetBorderSize(0);
			le = leg->AddEntry("","^{3}He+Au #sqrt{s_{NN}}=200 GeV","h");
			le = leg->AddEntry("","Inclusive J/#psi","h");
			le = leg->AddEntry("",Form("%d%c-%d%c",cent_per_HeAu_min[icent],'%',cent_per_HeAu_max[icent],'%'),"h");
			leg->Draw();

			TLine *line = new TLine(0, 1, 8, 1);
			line->SetLineStyle(2);
			line->Draw();

			float global_sys = sqrt(Ncoll_HeAu_sys[icent]*Ncoll_HeAu_sys[icent] + BiasF_HeAu_sys[icent]*BiasF_HeAu_sys[icent] + 0.101*0.101);
			TBox *box = new TBox(7.7,1-global_sys,8,1+global_sys);
			box->SetFillStyle(1000);
			box->SetFillColorAlpha(1,0.5);
			box->Draw();
		}

		{
			TLegend *leg = new TLegend(0.15,0.6,0.5,0.7);
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
	}

	for (int iarm=0; iarm<narm; iarm++){
		c002[iarm] = new TCanvas(Form("c002_arm%d",iarm),Form("c002_arm%d",iarm),1.3*400,1*400);

		for (int icent=0; icent<ncentbin_HeAu; icent++){
			SetPadStyle();
			gPad->SetRightMargin(0.02);
			gPad->SetLeftMargin(0.14);
			gPad->SetBottomMargin(0.15);
			htmp = (TH1F*)gPad->DrawFrame(0,0,8.0,2.5);
			SetHistoStyle("p_{T} (GeV/c)","R_{AB}","",24,20);
			htmp->GetYaxis()->SetTitleOffset(1.0);
			htmp->GetXaxis()->SetTitleOffset(1.0);

			{
				TLegend *leg = new TLegend(0.20,0.65,0.6,0.9);
				leg->SetFillStyle(0);
				leg->SetBorderSize(0);
				le = leg->AddEntry("","^{3}He+Au #sqrt{s_{NN}}=200 GeV","h");
				le->SetTextSize(20);
				le = leg->AddEntry("",Form("%d%c-%d%c",cent_per_pAu_min[icent],'%',cent_per_pAu_max[icent],'%'),"h");
				le->SetTextSize(20);
				le = leg->AddEntry("","Inclusive J/#psi","h");
				le->SetTextSize(20);
				if ( iarm==0 ){
					le = leg->AddEntry("","-2.2<y<-1.2","h");
				}else{
					le = leg->AddEntry("","1.2<y<2.2","h");
				}
				le->SetTextSize(20);
				leg->Draw();

				TLine *line = new TLine(0, 1, 8.0, 1);
				line->SetLineStyle(2);
				line->Draw();

				float global_sys = sqrt(Ncoll_HeAu_sys[icent]*Ncoll_HeAu_sys[icent] + BiasF_HeAu_sys[icent]*BiasF_HeAu_sys[icent] + 0.101*0.101);
				TBox *box = new TBox(7.7,1-global_sys,8.0,1+global_sys);
				box->SetFillStyle(1000);
				box->SetFillColorAlpha(1,0.5);
				box->Draw();
			}

			{
				TLatex *tex = new TLatex(0.5,0.15,"PHENIX");
				tex->SetTextSize(20);
				tex->SetTextFont(43);
				tex->Draw();
			}

			{
				TLatex *tex = new TLatex(7.2,2.25,"(d)");
				tex->SetTextSize(20);
				tex->SetTextFont(43);
				tex->Draw();
			}

			gth_epps_HeAu[iarm]->Draw("3");
			gth_ncteq_HeAu[iarm]->Draw("3");

			gr_HeAu_sys[icent][iarm]->Draw("2");
			gr_HeAu[icent][iarm]->Draw("p");

			{
				TLegend *leg = new TLegend(0.7,0.18,0.9,0.3);
				leg->SetFillStyle(0);
				le = leg->AddEntry(gth_epps_HeAu[iarm],"EPPS16","f");
				le->SetTextSize(20);
				le = leg->AddEntry(gth_ncteq_HeAu[iarm],"nCTEQ15","f");
				le->SetTextSize(20);
				leg->Draw();
			}
		}
	}

       
	if ( bSAVE ){

		for (int iarm=0; iarm<narm; iarm++){
			c000[iarm]->cd();
			c000[iarm]->SaveAs(Form("pdf/fig_RAB_pT_MB_pAu_arm%d.pdf",iarm));

			c001[iarm]->cd();
			c001[iarm]->SaveAs(Form("pdf/fig_RAB_pT_MB_pAl_arm%d.pdf",iarm));

			c002[iarm]->cd();
			c002[iarm]->SaveAs(Form("pdf/fig_RAB_pT_MB_HeAu_arm%d.pdf",iarm));

		}
	}


}



