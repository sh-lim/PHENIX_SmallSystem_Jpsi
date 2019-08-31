#include "Style.h"

void Draw_RAB_pT_all()
{

	const bool bSAVE = false;

	SetStyle();
	gStyle->SetLegendTextSize(16);

  char name1[500];
  char name2[500];
  char name3[500];

	TFile *file_pAu;	  
	TFile *file_pAl;	  
	TFile *file_HeAu;	  

	const int narm = 2;
	const int nptbin_pAu = 19;
	const int nptbin_pAl = 16;
	const int nptbin_HeAu = 13;

	const int ncentbin_pAu = 7;
	const int ncentbin_pAl = 3;
	const int ncentbin_HeAu = 3;

	const int cent_per_pAu_min[ncentbin_pAu] = {0, 5, 10, 0, 20, 40, 60};
	const int cent_per_pAu_max[ncentbin_pAu] = {5, 10, 20, 20, 40, 60, 84};

	const int cent_per_pAl_min[ncentbin_pAl] = {0, 20, 40};
	const int cent_per_pAl_max[ncentbin_pAl] = {20, 40, 72};

	const int cent_per_HeAu_min[ncentbin_HeAu] = {0, 20, 40};
	const int cent_per_HeAu_max[ncentbin_HeAu] = {20, 40, 88};

	const char c_arm[narm] = {'S', 'N'};

	const double Ncoll_pAu_sys[ncentbin_pAu] = {0.6/9.7, 0.5/8.4, 0.5/7.4, 0.5/8.2, 0.4/6.1, 0.3/4.4, 0.2/2.6};
	const double BiasF_pAu_sys[ncentbin_pAu] = {0.01/0.86, 0.01/0.90, 0.01/0.94, 0.01/0.90, 0.01/0.98, 0.01/1.02, 0.06/1.00};

	const double Ncoll_pAl_sys[ncentbin_pAl] = {0.3/3.5, 0.1/2.3, 0.1/1.7};
	const double BiasF_pAl_sys[ncentbin_pAl] = {0.01/0.81, 0.02/0.90, 0.04/1.01};

	const double Ncoll_HeAu_sys[ncentbin_HeAu] = {0.076233184, 0.074324324, 0.080272996};
	const double BiasF_HeAu_sys[ncentbin_HeAu] = {0.010526316, 0.0099009901, 0.035018614};

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

	TGraphErrors *gr_pAu[ncentbin_pAu][narm];
	TGraphErrors *gr_pAl[ncentbin_pAl][narm];
	TGraphErrors *gr_HeAu[ncentbin_HeAu][narm];

	TGraphErrors *gr_pAu_sys[ncentbin_pAu][narm];
	TGraphErrors *gr_pAl_sys[ncentbin_pAl][narm];
	TGraphErrors *gr_HeAu_sys[ncentbin_HeAu][narm];

	//plot arrays
	double pt_array_pAu[nptbin_pAu] =  {0.125,0.375,0.625,0.875,1.125,1.375,1.625,1.875,2.125,2.375,2.625,2.875,3.125,3.375,3.625,3.875,4.25,4.75,6.0};
	double pt_array_pAl[nptbin_pAl] =  {0.125,0.375,0.625,0.875,1.125,1.375,1.625,1.875,2.125,2.375,2.625,2.875,3.125,3.375,3.625,3.875};
	double pt_array_HeAu[nptbin_HeAu] = {0.125,0.375,0.625,0.875,1.125,1.375,1.625,1.875,2.125,2.375,2.75,3.25,3.75};

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
		htmp = (TH1F*)gPad->DrawFrame(0,0,7.5,2.5);
		SetHistoStyle("p_{T} (GeV/c)","R_{AB}","",20,18);
		htmp->GetYaxis()->SetTitleOffset(2.0);
		htmp->GetXaxis()->SetTitleOffset(2.2);

		{
			TLegend *leg = new TLegend(0.20,0.73,0.6,0.93);
			leg->SetFillStyle(0);
			leg->SetBorderSize(0);
			le = leg->AddEntry("","p+Au #sqrt{s_{NN}}=200 GeV","h");
			le = leg->AddEntry("","Inclusive J/#psi","h");
			le = leg->AddEntry("",Form("%d%c-%d%c",cent_per_pAu_min[icent],'%',cent_per_pAu_max[icent],'%'),"h");
			leg->Draw();

			TLine *line = new TLine(0, 1, 9.8, 1);
			line->SetLineStyle(2);
			line->Draw();

			float global_sys = sqrt(Ncoll_pAu_sys[icent]*Ncoll_pAu_sys[icent] + BiasF_pAu_sys[icent]*BiasF_pAu_sys[icent] + 0.101*0.101);
			TBox *box = new TBox(9.5,1-global_sys,9.8,1+global_sys);
			box->SetFillStyle(1000);
			box->SetFillColorAlpha(1,0.5);
			box->Draw();
		}

		{
			TLegend *leg = new TLegend(0.65,0.78,0.95,0.93);
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
		htmp = (TH1F*)gPad->DrawFrame(0,0,7.5,2.5);
		SetHistoStyle("p_{T} (GeV/c)","R_{AB}","",28,24);
		htmp->GetYaxis()->SetTitleOffset(0.8);
		htmp->GetXaxis()->SetTitleOffset(0.95);
		for (int iarm=0; iarm<narm; iarm++){
			gr_pAu_sys[icent][iarm]->Draw("2");
			gr_pAu[icent][iarm]->Draw("p");
		}

		{
			TLegend *leg = new TLegend(0.17,0.68,0.6,0.93);
			leg->SetFillStyle(0);
			leg->SetBorderSize(0);
			le = leg->AddEntry("","p+Au #sqrt{s_{NN}}=200 GeV","h");
			le->SetTextSize(28);
			le = leg->AddEntry("","Inclusive J/#psi","h");
			le->SetTextSize(28);
			le = leg->AddEntry("",Form("%d%c-%d%c",cent_per_pAu_min[icent],'%',cent_per_pAu_max[icent],'%'),"h");
			le->SetTextSize(28);
			leg->Draw();

			TLine *line = new TLine(0, 1, 7.5, 1);
			line->SetLineStyle(2);
			line->Draw();

			float global_sys = sqrt(Ncoll_pAu_sys[icent]*Ncoll_pAu_sys[icent] + BiasF_pAu_sys[icent]*BiasF_pAu_sys[icent] + 0.101*0.101);
			TBox *box = new TBox(7.2,1-global_sys,7.5,1+global_sys);
			box->SetFillStyle(1000);
			box->SetFillColorAlpha(1,0.5);
			box->Draw();
		}

		{
			TLegend *leg = new TLegend(0.65,0.68,0.93,0.93);
			leg->SetFillStyle(0);
			leg->SetBorderSize(0);
			le = leg->AddEntry(gr_pAu[icent][0],"-2.2<y<-1.2","p");
			le->SetTextSize(28);
			le = leg->AddEntry(gr_pAu[icent][1],"1.2<y<2.2","p");
			le->SetTextSize(28);
			le = leg->AddEntry("","","");
			leg->Draw();
		}

		{
			TLatex *tex = new TLatex(6.8, 1.6, Form("(%c)",97+count));
			tex->SetTextFont(43);
			tex->SetTextSize(28);
			tex->Draw();
		}

		{
			TLatex *tex = new TLatex(5.7, 0.2, "PHENIX");
			tex->SetTextFont(43);
			tex->SetTextSize(28);
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
			TLegend *leg = new TLegend(0.20,0.73,0.6,0.93);
			leg->SetFillStyle(0);
			leg->SetBorderSize(0);
			le = leg->AddEntry("","p+Al #sqrt{s_{NN}}=200 GeV","h");
			le = leg->AddEntry("","Inclusive J/#psi","h");
			le = leg->AddEntry("",Form("%d%c-%d%c",cent_per_pAl_min[icent],'%',cent_per_pAl_max[icent],'%'),"h");
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
			TLegend *leg = new TLegend(0.65,0.78,0.95,0.93);
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

		c001[icent] = new TCanvas(Form("c001_%d",icent),Form("c001_%d",icent),1.4*400,400);
		SetPadStyle();
		gPad->SetTopMargin(0.05);
		gPad->SetRightMargin(0.015);
		gPad->SetLeftMargin(0.14);
		gPad->SetBottomMargin(0.16);
		htmp = (TH1F*)gPad->DrawFrame(0,0,5,2.5);
		SetHistoStyle("p_{T} (GeV/c)","R_{AB}","",28,24);
		htmp->GetYaxis()->SetTitleOffset(0.8);
		htmp->GetXaxis()->SetTitleOffset(0.95);
		for (int iarm=0; iarm<narm; iarm++){
			gr_pAl_sys[icent][iarm]->Draw("2");
			gr_pAl[icent][iarm]->Draw("p");
		}

		{
			TLegend *leg = new TLegend(0.17,0.68,0.6,0.93);
			leg->SetFillStyle(0);
			leg->SetBorderSize(0);
			le = leg->AddEntry("","p+Al #sqrt{s_{NN}}=200 GeV","h");
			le->SetTextSize(28);
			le = leg->AddEntry("","Inclusive J/#psi","h");
			le->SetTextSize(28);
			le = leg->AddEntry("",Form("%d%c-%d%c",cent_per_pAl_min[icent],'%',cent_per_pAl_max[icent],'%'),"h");
			le->SetTextSize(28);
			leg->Draw();

			TLine *line = new TLine(0, 1, 5, 1);
			line->SetLineStyle(2);
			line->Draw();

			float global_sys = sqrt(Ncoll_pAl_sys[icent]*Ncoll_pAl_sys[icent] + BiasF_pAl_sys[icent]*BiasF_pAl_sys[icent] + 0.101*0.101);
			TBox *box = new TBox(4.8,1-global_sys,5.0,1+global_sys);
			box->SetFillStyle(1000);
			box->SetFillColorAlpha(1,0.5);
			box->Draw();
		}

		{
			TLegend *leg = new TLegend(0.65,0.68,0.93,0.93);
			leg->SetFillStyle(0);
			leg->SetBorderSize(0);
			le = leg->AddEntry(gr_pAl[icent][0],"-2.2<y<-1.2","p");
			le->SetTextSize(28);
			le = leg->AddEntry(gr_pAl[icent][1],"1.2<y<2.2","p");
			le->SetTextSize(28);
			le = leg->AddEntry("","","");
			leg->Draw();
		}

		{
			TLatex *tex = new TLatex(4.5, 1.6, Form("(%c)",97+icent));
			tex->SetTextFont(43);
			tex->SetTextSize(28);
			tex->Draw();
		}

		{
			TLatex *tex = new TLatex(3.8, 0.2, "PHENIX");
			tex->SetTextFont(43);
			tex->SetTextSize(28);
			tex->Draw();
		}
	}


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
			TLegend *leg = new TLegend(0.20,0.73,0.6,0.93);
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
			TLegend *leg = new TLegend(0.65,0.78,0.95,0.93);
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
		htmp = (TH1F*)gPad->DrawFrame(0,0,5,2.5);
		SetHistoStyle("p_{T} (GeV/c)","R_{AB}","",28,24);
		htmp->GetYaxis()->SetTitleOffset(0.8);
		htmp->GetXaxis()->SetTitleOffset(0.95);
		for (int iarm=0; iarm<narm; iarm++){
			gr_HeAu_sys[icent][iarm]->Draw("2");
			gr_HeAu[icent][iarm]->Draw("p");
		}

		{
			TLegend *leg = new TLegend(0.17,0.68,0.6,0.93);
			leg->SetFillStyle(0);
			leg->SetBorderSize(0);
			le = leg->AddEntry("","^{3}He+Au #sqrt{s_{NN}}=200 GeV","h");
			le->SetTextSize(28);
			le = leg->AddEntry("","Inclusive J/#psi","h");
			le->SetTextSize(28);
			le = leg->AddEntry("",Form("%d%c-%d%c",cent_per_HeAu_min[icent],'%',cent_per_HeAu_max[icent],'%'),"h");
			le->SetTextSize(28);
			leg->Draw();

			TLine *line = new TLine(0, 1, 5, 1);
			line->SetLineStyle(2);
			line->Draw();

			float global_sys = sqrt(Ncoll_HeAu_sys[icent]*Ncoll_HeAu_sys[icent] + BiasF_pAl_sys[icent]*BiasF_HeAu_sys[icent] + 0.101*0.101);
			TBox *box = new TBox(4.8,1-global_sys,5.0,1+global_sys);
			box->SetFillStyle(1000);
			box->SetFillColorAlpha(1,0.5);
			box->Draw();
		}

		{
			TLegend *leg = new TLegend(0.65,0.68,0.93,0.93);
			leg->SetFillStyle(0);
			leg->SetBorderSize(0);
			le = leg->AddEntry(gr_pAl[icent][0],"-2.2<y<-1.2","p");
			le->SetTextSize(28);
			le = leg->AddEntry(gr_pAl[icent][1],"1.2<y<2.2","p");
			le->SetTextSize(28);
			le = leg->AddEntry("","","");
			leg->Draw();
		}

		{
			TLatex *tex = new TLatex(4.5, 1.6, Form("(%c)",97+icent));
			tex->SetTextFont(43);
			tex->SetTextSize(28);
			tex->Draw();
		}

		{
			TLatex *tex = new TLatex(3.8, 0.2, "PHENIX");
			tex->SetTextFont(43);
			tex->SetTextSize(28);
			tex->Draw();
		}
	}

	TCanvas *c0002[narm];
	TCanvas *c0003[narm];

	for (int iarm=0; iarm<narm; iarm++){
		c0002[iarm] = new TCanvas(Form("c0002_%d",iarm),Form("c0002_%d",iarm),1.4*400,400);
		c0002[iarm]->cd(iarm+1);
		SetPadStyle();
		gPad->SetTopMargin(0.05);
		gPad->SetRightMargin(0.015);
		gPad->SetLeftMargin(0.12);
		gPad->SetBottomMargin(0.15);
		htmp = (TH1F*)gPad->DrawFrame(0,0,7.5,2.5);
		SetHistoStyle("p_{T} (GeV/c)","R_{AB}","",24,20);
		htmp->GetYaxis()->SetTitleOffset(0.8);
		htmp->GetXaxis()->SetTitleOffset(1.0);

		TLine *line = new TLine(0, 1, 7.5, 1);
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
			TLegend *leg = new TLegend(0.15,0.68,0.6,0.92);
			leg->SetFillStyle(0);
			leg->SetBorderSize(0);
			le = leg->AddEntry("","Inclusive J/#psi","h");
			le->SetTextSize(20);
			if ( iarm==0 ){
				le = leg->AddEntry("","-2.2<y<-1.2","h");
			}else{
				le = leg->AddEntry("","1.2<y<2.2","h");
			}
			le->SetTextSize(20);
			le = leg->AddEntry("","#sqrt{s_{NN}}=200 GeV","h");
			le->SetTextSize(20);
			le = leg->AddEntry("","0%-20%","h");
			le->SetTextSize(20);
			leg->Draw();
		}

		{
			float global_sys = sqrt(Ncoll_pAu_sys[3]*Ncoll_pAu_sys[3] + BiasF_pAu_sys[3]*BiasF_pAu_sys[3] + 0.101*0.101);
			TBox *box = new TBox(7.3,1-global_sys,7.5,1+global_sys);
			box->SetFillStyle(1000);
			box->SetFillColorAlpha(kGreen+2,0.5);
			box->Draw();
		}

		{
			float global_sys = sqrt(Ncoll_pAl_sys[0]*Ncoll_pAl_sys[0] + BiasF_pAl_sys[0]*BiasF_pAl_sys[0] + 0.101*0.101);
			TBox *box = new TBox(7.1,1-global_sys,7.3,1+global_sys);
			box->SetFillStyle(1000);
			box->SetFillColorAlpha(2,0.5);
			box->Draw();
		}

		{
			TLatex *tex = new TLatex(7,2.25,Form("(%c)",97+iarm));
			tex->SetTextSize(20);
			tex->SetTextFont(43);
			tex->Draw();
		}

		{
			TLatex *tex = new TLatex(6,0.15,"PHENIX");
			tex->SetTextSize(20);
			tex->SetTextFont(43);
			tex->Draw();
		}

		{
			TLegend *leg = new TLegend(0.7,0.68,0.8,0.92);
			leg->SetFillStyle(0);
			leg->SetBorderSize(0);
			le = leg->AddEntry(gr_pAl_cp,"p+Al","p");
			le->SetTextSize(20);
			le = leg->AddEntry(gr_pAu_cp,"p+Au","p");
			le->SetTextSize(20);
			le = leg->AddEntry(""," ","");
			le = leg->AddEntry(""," ","");
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
		htmp = (TH1F*)gPad->DrawFrame(0,0,7.5,2.5);
		SetHistoStyle("p_{T} (GeV/c)","R_{AB}","",24,20);
		htmp->GetYaxis()->SetTitleOffset(0.8);
		htmp->GetXaxis()->SetTitleOffset(1.0);

		TLine *line = new TLine(0, 1, 7.5, 1);
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
			TLegend *leg = new TLegend(0.15,0.68,0.6,0.92);
			leg->SetFillStyle(0);
			leg->SetBorderSize(0);
			le = leg->AddEntry("","Inclusive J/#psi","h");
			le->SetTextSize(20);
			if ( iarm==0 ){
				le = leg->AddEntry("","-2.2<y<-1.2","h");
			}else{
				le = leg->AddEntry("","1.2<y<2.2","h");
			}
			le->SetTextSize(20);
			le = leg->AddEntry("","#sqrt{s_{NN}}=200 GeV","h");
			le->SetTextSize(20);
			le = leg->AddEntry("","0%-20%","h");
			le->SetTextSize(20);
			leg->Draw();
		}

		{
			float global_sys = sqrt(Ncoll_pAu_sys[3]*Ncoll_pAu_sys[3] + BiasF_pAu_sys[3]*BiasF_pAu_sys[3] + 0.101*0.101);
			TBox *box = new TBox(7.3,1-global_sys,7.5,1+global_sys);
			box->SetFillStyle(1000);
			box->SetFillColorAlpha(kGreen+2,0.5);
			box->Draw();
		}

		{
			float global_sys = sqrt(Ncoll_HeAu_sys[0]*Ncoll_HeAu_sys[0] + BiasF_HeAu_sys[0]*BiasF_HeAu_sys[0] + 0.101*0.101);
			TBox *box = new TBox(7.1,1-global_sys,7.3,1+global_sys);
			box->SetFillStyle(1000);
			box->SetFillColorAlpha(6,0.5);
			box->Draw();
		}

		{
			TLatex *tex = new TLatex(7,2.25,Form("(%c)",97+iarm));
			tex->SetTextSize(20);
			tex->SetTextFont(43);
			tex->Draw();
		}

		{
			TLatex *tex = new TLatex(6,0.15,"PHENIX");
			tex->SetTextSize(20);
			tex->SetTextFont(43);
			tex->Draw();
		}

		{
			TLegend *leg = new TLegend(0.7,0.68,0.8,0.92);
			leg->SetFillStyle(0);
			leg->SetBorderSize(0);
			le = leg->AddEntry(gr_pAu_cp,"p+Au","p");
			le->SetTextSize(20);
			le = leg->AddEntry(gr_HeAu_cp,"^{3}He+Au","p");
			le->SetTextSize(20);
			le = leg->AddEntry(""," ","");
			le = leg->AddEntry(""," ","");
			leg->Draw();
		}

	}//iarm

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
		}//iarm
	}

}



