#include "Style.h"

void Draw_fit(){

	const bool bSAVE = true;

	SetStyle();

	TFile *infile_pp = new TFile("pp_MB_S_fit_hist_fx.root","read");
	TFile *infile_pAu = new TFile("pAu_MB_S_fit_hist_fx.root","read");

	TH1D *h1_pp_ul = (TH1D*)infile_pp->Get("pp_pT_S_MB_jpsi");
	TH1D *h1_pp_ls = (TH1D*)infile_pp->Get("pp_pT_S_MB_combg");
	TF1 *f1_pp_ls = (TF1*)infile_pp->Get("combg_fit");
	TF1 *f1_pp_corr = (TF1*)infile_pp->Get("corrbg_fit");
	TF1 *f1_pp_1s = (TF1*)infile_pp->Get("jpsi_fit");
	TF1 *f1_pp_2s = (TF1*)infile_pp->Get("psi2s_fit");
	TF1 *f1_pp_tot = (TF1*)infile_pp->Get("total_fitLL");

	TH1D *h1_pAu_ul = (TH1D*)infile_pAu->Get("pAu_pT_S_MB_jpsi");
	TH1D *h1_pAu_ls = (TH1D*)infile_pAu->Get("pAu_pT_S_MB_combg");
	TF1 *f1_pAu_ls = (TF1*)infile_pAu->Get("combg_fit");
	TF1 *f1_pAu_corr = (TF1*)infile_pAu->Get("corrbg_fit");
	TF1 *f1_pAu_1s = (TF1*)infile_pAu->Get("jpsi_fit");
	TF1 *f1_pAu_2s = (TF1*)infile_pAu->Get("psi2s_fit");
	TF1 *f1_pAu_tot = (TF1*)infile_pAu->Get("total_fitLL");

	TCanvas *cpp = new TCanvas("cpp","cpp",1.4*400,400);
	SetPadStyle();
	gPad->SetLogy();
	gPad->SetRightMargin(0.03);
	gPad->SetLeftMargin(0.13);
	gPad->SetBottomMargin(0.15);

	htmp = (TH1D*)gPad->DrawFrame(2,5,5,10.0*h1_pp_ul->GetMaximum());
	SetHistoStyle("m_{#mu#mu} (GeV/c^{2})","N_{#mu#mu}/(0.05 GeV/c^{2})","",26,22);
	htmp->GetYaxis()->SetTitleOffset(0.8);
	htmp->GetXaxis()->SetTitleOffset(0.9);

	h1_pp_ul->SetMarkerStyle(20);
	h1_pp_ul->SetLineColor(1);
	h1_pp_ul->SetLineWidth(1);
	h1_pp_ul->Draw("p same");

	h1_pp_ls->SetMarkerStyle(24);
	h1_pp_ls->SetLineColor(1);
	h1_pp_ls->SetLineWidth(1);
	h1_pp_ls->Draw("p same");

	f1_pp_ls->SetLineColor(1);
	f1_pp_ls->SetLineWidth(2);
	f1_pp_ls->SetLineStyle(7);
	f1_pp_ls->Draw("same");

	f1_pp_corr->SetLineColor(kGreen+2);
	f1_pp_corr->SetLineWidth(2);
	f1_pp_corr->SetLineStyle(10);
	f1_pp_corr->Draw("same");

	f1_pp_tot->SetLineColor(2);
	f1_pp_tot->SetLineWidth(2);
	f1_pp_tot->SetLineStyle(1);
	f1_pp_tot->Draw("same");

	f1_pp_1s->SetLineColor(4);
	f1_pp_1s->SetLineWidth(2);
	f1_pp_1s->SetLineStyle(6);
	f1_pp_1s->Draw("same");

	f1_pp_2s->SetLineColor(4);
	f1_pp_2s->SetLineWidth(2);
	f1_pp_2s->SetLineStyle(6);
	f1_pp_2s->Draw("same");

	{
		TLegend *leg = new TLegend(0.10,0.63,0.4,0.93);
		leg->SetFillStyle(0);
		leg->SetBorderSize(0);
		le = leg->AddEntry("","p+p 200 GeV","");
		le->SetTextSize(22);
		le = leg->AddEntry("","-2.2<y<-1.2","");
		le->SetTextSize(22);
		le = leg->AddEntry("","Integrated p_{T}","");
		le->SetTextSize(22);
		le = leg->AddEntry("","","");
		le->SetTextSize(22);
		le = leg->AddEntry("","PHENIX","");
		le->SetTextSize(22);
		leg->Draw();
	}

	{
		TLegend *leg = new TLegend(0.55,0.53,0.85,0.93);
		leg->SetMargin(0.5);
		leg->SetFillStyle(0);
		leg->SetBorderSize(0);
		le = leg->AddEntry(h1_pp_ul,"Unlike-sign   (a)","P");
		le->SetTextSize(22);
		le = leg->AddEntry(h1_pp_ls,"Like-sign","P");
		le->SetTextSize(22);
		le = leg->AddEntry(f1_pp_corr,"Corr. bkg.","L");
		le->SetTextSize(22);
		le = leg->AddEntry(f1_pp_ls,"Comb. bkg.","L");
		le->SetTextSize(22);
		le = leg->AddEntry(f1_pp_1s,"Signal","L");
		le->SetTextSize(22);
		le = leg->AddEntry(f1_pp_tot,"Total fit","L");
		le->SetTextSize(22);
		leg->Draw();
		cout << leg->GetMargin() << endl;
	}

	TCanvas *cpAu = new TCanvas("cpAu","cpAu",1.4*400,400);
	SetPadStyle();
	gPad->SetLogy();
	gPad->SetRightMargin(0.03);
	gPad->SetLeftMargin(0.13);
	gPad->SetBottomMargin(0.15);

	htmp = (TH1D*)gPad->DrawFrame(2,5,5,10.0*h1_pAu_ul->GetMaximum());
	SetHistoStyle("m_{#mu#mu} (GeV/c^{2})","N_{#mu#mu}/(0.05 GeV/c^{2})","",26,22);
	htmp->GetYaxis()->SetTitleOffset(0.8);
	htmp->GetXaxis()->SetTitleOffset(0.9);

	h1_pAu_ul->SetMarkerStyle(20);
	h1_pAu_ul->SetLineColor(1);
	h1_pAu_ul->SetLineWidth(1);
	h1_pAu_ul->Draw("p same");

	h1_pAu_ls->SetMarkerStyle(24);
	h1_pAu_ls->SetLineColor(1);
	h1_pAu_ls->SetLineWidth(1);
	h1_pAu_ls->Draw("p same");

	f1_pAu_ls->SetLineColor(1);
	f1_pAu_ls->SetLineWidth(2);
	f1_pAu_ls->SetLineStyle(7);
	f1_pAu_ls->Draw("same");

	f1_pAu_corr->SetLineColor(kGreen+2);
	f1_pAu_corr->SetLineWidth(2);
	f1_pAu_corr->SetLineStyle(10);
	f1_pAu_corr->Draw("same");

	f1_pAu_tot->SetLineColor(2);
	f1_pAu_tot->SetLineWidth(2);
	f1_pAu_tot->SetLineStyle(1);
	f1_pAu_tot->Draw("same");

	f1_pAu_1s->SetLineColor(4);
	f1_pAu_1s->SetLineWidth(2);
	f1_pAu_1s->SetLineStyle(6);
	f1_pAu_1s->Draw("same");

	f1_pAu_2s->SetLineColor(4);
	f1_pAu_2s->SetLineWidth(2);
	f1_pAu_2s->SetLineStyle(6);
	f1_pAu_2s->Draw("same");

	{
		TLegend *leg = new TLegend(0.10,0.63,0.4,0.93);
		leg->SetFillStyle(0);
		leg->SetBorderSize(0);
		le = leg->AddEntry("","p+Au 200 GeV","");
		le->SetTextSize(22);
		le = leg->AddEntry("","-2.2<y<-1.2","");
		le->SetTextSize(22);
		le = leg->AddEntry("","Integrated p_{T}","");
		le->SetTextSize(22);
		le = leg->AddEntry("","","");
		le->SetTextSize(22);
		le = leg->AddEntry("","PHENIX","");
		le->SetTextSize(22);
		leg->Draw();
	}

	{
		TLegend *leg = new TLegend(0.55,0.53,0.85,0.93);
		leg->SetMargin(0.5);
		leg->SetFillStyle(0);
		leg->SetBorderSize(0);
		le = leg->AddEntry(h1_pAu_ul,"Unlike-sign   (b)","P");
		le->SetTextSize(22);
		le = leg->AddEntry(h1_pAu_ls,"Like-sign","P");
		le->SetTextSize(22);
		le = leg->AddEntry(f1_pAu_corr,"Corr. bkg.","L");
		le->SetTextSize(22);
		le = leg->AddEntry(f1_pAu_ls,"Comb. bkg.","L");
		le->SetTextSize(22);
		le = leg->AddEntry(f1_pAu_1s,"Signal","L");
		le->SetTextSize(22);
		le = leg->AddEntry(f1_pAu_tot,"Total fit","L");
		le->SetTextSize(22);
		leg->Draw();
		cout << leg->GetMargin() << endl;
	}

	if ( bSAVE ){

		cpp->cd();
		cpp->SaveAs("pdf/fit_fit_pp_arm0.pdf");

		cpAu->cd();
		cpAu->SaveAs("pdf/fit_fit_pAu_arm0.pdf");

	}

}
