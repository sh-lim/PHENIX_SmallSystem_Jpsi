#include "Style.h"

void Draw_RAB_Ncoll(){

	const bool bSAVE = false;

	SetStyle();

	TFile *infile_pAu = new TFile("RAB_y_Ncoll_pAu200.root","read");
	TFile *infile_pAl = new TFile("RAB_y_Ncoll_pAl200.root","read");
	TFile *infile_HeAu = new TFile("RAB_y_Ncoll_HeAu200.root","read");

	const int narm = 2;

	TGraphErrors *hRAB_Ncoll_pAu[narm];
	TGraphErrors *hRAB_Ncoll_pAl[narm];
	TGraphErrors *hRAB_Ncoll_HeAu[narm];

	TGraphErrors *hRAB_Ncoll_pAu_sys[narm];
	TGraphErrors *hRAB_Ncoll_pAl_sys[narm];
	TGraphErrors *hRAB_Ncoll_HeAu_sys[narm];

	TGraphErrors *hRAB_Centrality_pAu[narm];
	TGraphErrors *hRAB_Centrality_pAl[narm];
	TGraphErrors *hRAB_Centrality_HeAu[narm];

	TGraphErrors *hRAB_Centrality_pAu_sys[narm];
	TGraphErrors *hRAB_Centrality_pAl_sys[narm];
	TGraphErrors *hRAB_Centrality_HeAu_sys[narm];

	float mean_cent_pAu[6] = {2.5, 7.5, 15.0, 30.0, 50.0, 72.0};
	float mean_cent_HeAu[3] = {10.0, 30.0, 56.0};

	for (int iarm=0; iarm<narm; iarm++){

		hRAB_Ncoll_pAu_sys[iarm] = (TGraphErrors*)infile_pAu->Get(Form("RAB_Ncoll_syserr_arm%d",iarm));
		hRAB_Ncoll_pAu[iarm] = (TGraphErrors*)infile_pAu->Get(Form("RAB_Ncoll_staerr_arm%d",iarm));
		hRAB_Ncoll_pAu_sys[iarm]->SetMarkerStyle(20);
		hRAB_Ncoll_pAu_sys[iarm]->SetMarkerColor(kGreen+2);
		hRAB_Ncoll_pAu_sys[iarm]->SetLineColor(kGreen+2);
		hRAB_Ncoll_pAu[iarm]->SetMarkerStyle(20);
		hRAB_Ncoll_pAu[iarm]->SetMarkerColor(kGreen+2);
		hRAB_Ncoll_pAu[iarm]->SetLineColor(kGreen+2);

		hRAB_Ncoll_pAl_sys[iarm] = (TGraphErrors*)infile_pAl->Get(Form("RAB_Ncoll_syserr_arm%d",iarm));
		hRAB_Ncoll_pAl[iarm] = (TGraphErrors*)infile_pAl->Get(Form("RAB_Ncoll_staerr_arm%d",iarm));
		hRAB_Ncoll_pAl_sys[iarm]->SetMarkerStyle(20);
		hRAB_Ncoll_pAl_sys[iarm]->SetMarkerColor(2);
		hRAB_Ncoll_pAl_sys[iarm]->SetLineColor(2);
		hRAB_Ncoll_pAl[iarm]->SetMarkerStyle(20);
		hRAB_Ncoll_pAl[iarm]->SetMarkerColor(2);
		hRAB_Ncoll_pAl[iarm]->SetLineColor(2);

		hRAB_Ncoll_HeAu_sys[iarm] = (TGraphErrors*)infile_HeAu->Get(Form("RAB_Ncoll_syserr_arm%d",iarm));
		hRAB_Ncoll_HeAu[iarm] = (TGraphErrors*)infile_HeAu->Get(Form("RAB_Ncoll_staerr_arm%d",iarm));
		hRAB_Ncoll_HeAu_sys[iarm]->SetMarkerStyle(20);
		hRAB_Ncoll_HeAu_sys[iarm]->SetMarkerColor(4);
		hRAB_Ncoll_HeAu_sys[iarm]->SetLineColor(6);
		hRAB_Ncoll_HeAu[iarm]->SetMarkerStyle(20);
		hRAB_Ncoll_HeAu[iarm]->SetMarkerColor(6);
		hRAB_Ncoll_HeAu[iarm]->SetLineColor(6);

		hRAB_Centrality_pAu_sys[iarm] = new TGraphErrors;
		hRAB_Centrality_pAu[iarm] = new TGraphErrors;

		hRAB_Centrality_pAu_sys[iarm]->SetMarkerStyle(20);
		hRAB_Centrality_pAu_sys[iarm]->SetMarkerColor(kGreen+2);
		hRAB_Centrality_pAu_sys[iarm]->SetLineColor(kGreen+2);
		hRAB_Centrality_pAu_sys[iarm]->SetFillStyle(0);
		hRAB_Centrality_pAu[iarm]->SetMarkerStyle(20);
		hRAB_Centrality_pAu[iarm]->SetMarkerColor(kGreen+2);
		hRAB_Centrality_pAu[iarm]->SetLineColor(kGreen+2);

		hRAB_Centrality_HeAu_sys[iarm] = new TGraphErrors;
		hRAB_Centrality_HeAu[iarm] = new TGraphErrors;

		hRAB_Centrality_HeAu_sys[iarm]->SetMarkerStyle(20);
		hRAB_Centrality_HeAu_sys[iarm]->SetMarkerColor(4);
		hRAB_Centrality_HeAu_sys[iarm]->SetLineColor(6);
		hRAB_Centrality_HeAu_sys[iarm]->SetFillStyle(0);
		hRAB_Centrality_HeAu[iarm]->SetMarkerStyle(20);
		hRAB_Centrality_HeAu[iarm]->SetMarkerColor(6);
		hRAB_Centrality_HeAu[iarm]->SetLineColor(6);

		for (int ip=0; ip<hRAB_Ncoll_pAu[iarm]->GetN(); ip++){

			double xx, yy, err, err_sys; 
			hRAB_Ncoll_pAu[iarm]->GetPoint(ip, xx, yy);
			err = hRAB_Ncoll_pAu[iarm]->GetErrorY(ip);
			err_sys = hRAB_Ncoll_pAu_sys[iarm]->GetErrorY(ip);

			cout << xx << " " << yy << endl;

			hRAB_Centrality_pAu[iarm]->SetPoint(ip, mean_cent_pAu[ip], yy);
			hRAB_Centrality_pAu[iarm]->SetPointError(ip, 0, err);
			hRAB_Centrality_pAu_sys[iarm]->SetPoint(ip, mean_cent_pAu[ip], yy);
			hRAB_Centrality_pAu_sys[iarm]->SetPointError(ip, 2, err_sys);

		}//ip

		for (int ip=0; ip<hRAB_Ncoll_HeAu[iarm]->GetN(); ip++){

			double xx, yy, err, err_sys; 
			hRAB_Ncoll_HeAu[iarm]->GetPoint(ip, xx, yy);
			err = hRAB_Ncoll_HeAu[iarm]->GetErrorY(ip);
			err_sys = hRAB_Ncoll_HeAu_sys[iarm]->GetErrorY(ip);

			cout << xx << " " << yy << endl;

			hRAB_Centrality_HeAu[iarm]->SetPoint(ip, mean_cent_HeAu[ip], yy);
			hRAB_Centrality_HeAu[iarm]->SetPointError(ip, 0, err);
			hRAB_Centrality_HeAu_sys[iarm]->SetPoint(ip, mean_cent_HeAu[ip], yy);
			hRAB_Centrality_HeAu_sys[iarm]->SetPointError(ip, 2, err_sys);

		}//ip

	}//iarm

	//return;

	TCanvas *c13[narm];
	TCanvas *c14[narm];
	for (int iarm=0; iarm<narm; iarm++){
		c13[iarm] = new TCanvas(Form("c13_arm%d",iarm),Form("c13_arm%d",iarm),1.4*1*400,400);
		SetPadStyle();
		gPad->SetRightMargin(0.03);
		gPad->SetLeftMargin(0.13);
		gPad->SetBottomMargin(0.17);
		htmp = (TH1F*)gPad->DrawFrame(0,0,25,2.0);
		SetHistoStyle("#LTN_{coll}#GT","R_{AB}","",28,24);
		htmp->GetYaxis()->SetTitleOffset(0.8);
		htmp->GetXaxis()->SetTitleOffset(1.0);

		{
			TLegend *leg = new TLegend(0.10,0.72,0.4,0.93);
			leg->SetFillStyle(0);
			leg->SetBorderSize(0);
			leg->SetTextSize(24);
			le = leg->AddEntry("","Inclusive J/#psi","");
			le = leg->AddEntry("","#sqrt{s_{NN}}=200 GeV","");
			le = leg->AddEntry("","PHENIX","");
			leg->Draw();

			TLine *line = new TLine(0, 1, 25, 1);
			line->SetLineStyle(2);
			line->Draw();

			TBox *box = new TBox(25*0.97,1-0.101,25,1+0.101);
			box->SetFillStyle(1000);
			box->SetFillColorAlpha(1,0.5);
			box->Draw();
		}
		{
			TLegend *leg = new TLegend(0.55,0.58,0.9,0.93);
			leg->SetFillStyle(0);
			leg->SetBorderSize(0);
			leg->SetTextSize(24);
			if ( iarm==0 ){
				le = leg->AddEntry("","-2.2<y<-1.2","");
				le = leg->AddEntry("","(Au/Al-going)","");
			}else{
				le = leg->AddEntry("","1.2<y<2.2","");
				le = leg->AddEntry("","(p/^{3}He-going)","");
			}
			le = leg->AddEntry(hRAB_Ncoll_pAl[iarm],"p+Al","P");
			le = leg->AddEntry(hRAB_Ncoll_pAu[iarm],"p+Au","P");
			le = leg->AddEntry(hRAB_Ncoll_HeAu[iarm],"^{3}He+Au","P");
			leg->Draw();
		}

		hRAB_Ncoll_pAu_sys[iarm]->Draw("2");
		hRAB_Ncoll_pAu[iarm]->Draw("P");

		hRAB_Ncoll_pAl_sys[iarm]->Draw("2");
		hRAB_Ncoll_pAl[iarm]->Draw("P");

		hRAB_Ncoll_HeAu_sys[iarm]->Draw("2");
		hRAB_Ncoll_HeAu[iarm]->Draw("P");

		{
			TLatex *tex = new TLatex(22.5,1.82,Form("(%c)",97+iarm));
			tex->SetTextFont(43);
			tex->SetTextSize(24);
			tex->Draw();
		}

		c14[iarm] = new TCanvas(Form("c14_arm%d",iarm),Form("c14_arm%d",iarm),1.4*1*400,400);
		SetPadStyle();
		gPad->SetRightMargin(0.04);
		gPad->SetLeftMargin(0.13);
		gPad->SetBottomMargin(0.17);
		htmp = (TH1F*)gPad->DrawFrame(0,0,100,2.0);
		SetHistoStyle("Centrality","R_{AB}","",28,24);
		htmp->GetYaxis()->SetTitleOffset(0.8);
		htmp->GetXaxis()->SetTitleOffset(1.0);

		{
			TLegend *leg = new TLegend(0.10,0.70,0.4,0.93);
			leg->SetFillStyle(0);
			leg->SetBorderSize(0);
			le = leg->AddEntry("","Inclusive J/#psi","");
			le->SetTextSize(24);
			le = leg->AddEntry("","#sqrt{s_{NN}}=200 GeV","");
			le->SetTextSize(24);
			if ( iarm==0 ){
				le = leg->AddEntry("","-2.2<y<-1.2, Au/Al-going","");
				le->SetTextSize(24);
			}else{
				le = leg->AddEntry("","1.2<y<2.2, p/^{3}He-going","");
				le->SetTextSize(24);
			}
			leg->Draw();

			TLine *line = new TLine(0, 1, 100, 1);
			line->SetLineStyle(2);
			line->Draw();

			TBox *box = new TBox(97.5,1-0.101,100,1+0.101);
			box->SetFillStyle(1000);
			box->SetFillColorAlpha(1,0.5);
			box->Draw();
		}
		{
			TLegend *leg = new TLegend(0.65,0.7,0.9,0.93);
			leg->SetFillStyle(0);
			leg->SetBorderSize(0);
			//le = leg->AddEntry(hRAB_Ncoll_pAl[iarm],"p+Al","P");
			//le->SetTextSize(24);
			le = leg->AddEntry(hRAB_Ncoll_pAu[iarm],"p+Au","P");
			le->SetTextSize(24);
			le = leg->AddEntry(hRAB_Ncoll_HeAu[iarm],"^{3}He+Au","P");
			le->SetTextSize(24);
			leg->Draw();
		}

		hRAB_Centrality_pAu_sys[iarm]->Draw("2");
		hRAB_Centrality_pAu[iarm]->Draw("P");

		hRAB_Centrality_HeAu_sys[iarm]->Draw("2");
		hRAB_Centrality_HeAu[iarm]->Draw("P");
	}

	if ( bSAVE ){
		for (int iarm=0; iarm<narm; iarm++){
			c13[iarm]->cd();
			c13[iarm]->SaveAs(Form("pdf/fig_RAB_Ncoll_arm%d.pdf",iarm));

			c14[iarm]->cd();
			c14[iarm]->SaveAs(Form("pdf/fig_RAB_Centrality_arm%d.pdf",iarm));
		}//iarm
	}


}
