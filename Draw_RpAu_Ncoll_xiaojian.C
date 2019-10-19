#include "Style.h"

void Draw_RpAu_Ncoll_xiaojian(){

	const bool bSAVE = true;

	SetStyle();

	TFile *infile_pAu = new TFile("RAB_y_Ncoll_pAu200.root","read");

	const int narm = 2;

	TH1D *hRAB_Ncoll_pAu[narm];
	TH1D *hRAB_Ncoll_pAu_sys[narm];

	for (int iarm=0; iarm<narm; iarm++){

		hRAB_Ncoll_pAu_sys[iarm] = (TH1D*)infile_pAu->Get(Form("RAB_Ncoll_syserr_arm%d",iarm));
		hRAB_Ncoll_pAu[iarm] = (TH1D*)infile_pAu->Get(Form("RAB_Ncoll_staerr_arm%d",iarm));
		hRAB_Ncoll_pAu_sys[iarm]->SetMarkerStyle(20);
		hRAB_Ncoll_pAu_sys[iarm]->SetMarkerColor(kGreen+2);
		hRAB_Ncoll_pAu_sys[iarm]->SetLineColor(kGreen+2);
		hRAB_Ncoll_pAu[iarm]->SetMarkerStyle(20);
		hRAB_Ncoll_pAu[iarm]->SetMarkerColor(kGreen+2);
		hRAB_Ncoll_pAu[iarm]->SetLineColor(kGreen+2);

	}//iarm

	//Theory curves
	TFile *infile_th0_pAu = new TFile("RpAu_transport_ncoll.root","read");

	TGraphAsymmErrors *gth_transport_pAu[narm];
	TGraphErrors *gth_CNM_pAu[narm];

	gth_transport_pAu[0] = (TGraphAsymmErrors*)infile_th0_pAu->Get("RpAu_transport_bkwd");
	gth_transport_pAu[1] = (TGraphAsymmErrors*)infile_th0_pAu->Get("RpAu_transport_fwd");
	gth_CNM_pAu[0] = (TGraphErrors*)infile_th0_pAu->Get("RpAu_CNM_bkwd");
	gth_CNM_pAu[1] = (TGraphErrors*)infile_th0_pAu->Get("RpAu_CNM_fwd");

	for (int iarm=0; iarm<narm; iarm++){
	  gth_transport_pAu[0]->SetFillColorAlpha(kGreen+2,0.3);
	  gth_transport_pAu[0]->SetFillStyle(3344);
	  gth_transport_pAu[0]->SetLineColor(0);
	  gth_transport_pAu[1]->SetFillColorAlpha(kGreen+2,0.3);
	  gth_transport_pAu[1]->SetFillStyle(3344);
	  gth_transport_pAu[1]->SetLineColor(0);
	   
	  gth_CNM_pAu[0]->SetLineColor(kBlack);
	  gth_CNM_pAu[1]->SetLineColor(kBlack);
	  gth_CNM_pAu[0]->SetLineWidth(2);
	  gth_CNM_pAu[1]->SetLineWidth(2);
	  gth_CNM_pAu[0]->SetLineStyle(1);
	  gth_CNM_pAu[1]->SetLineStyle(1);
	}
    
	TCanvas *c13[narm];
	for (int iarm=0; iarm<narm; iarm++){
		c13[iarm] = new TCanvas(Form("c13_arm%d",iarm),Form("c13_arm%d",iarm),1.4*1*400,400);
		SetPadStyle();
		gPad->SetRightMargin(0.03);
		gPad->SetLeftMargin(0.13);
		gPad->SetBottomMargin(0.17);
		htmp = (TH1F*)gPad->DrawFrame(0,0,11,1.6);
		SetHistoStyle("#LTN_{coll}#GT","R_{AB}","",28,24);
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
				le = leg->AddEntry("","-2.2<y<-1.2, Au-going","");
				le->SetTextSize(24);
			}else{
				le = leg->AddEntry("","1.2<y<2.2, p-going","");
				le->SetTextSize(24);
			}
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
			TLegend *leg = new TLegend(0.65,0.7,0.9,0.93);
			leg->SetFillStyle(0);
			leg->SetBorderSize(0);
			le = leg->AddEntry(hRAB_Ncoll_pAu[iarm],"p+Au","P");
			le->SetTextSize(24);
			leg->Draw();
		}

		hRAB_Ncoll_pAu_sys[iarm]->Draw("2");
		hRAB_Ncoll_pAu[iarm]->Draw("P");

		gth_transport_pAu[iarm]->Draw("3");
		gth_CNM_pAu[iarm]->Draw("L");
		
		{
			TLatex *tex = new TLatex(22.5,1.82,Form("(%c)",97+iarm));
			tex->SetTextFont(43);
			tex->SetTextSize(24);
			tex->Draw();
		}

		{
			TLatex *tex = new TLatex(1,0.15,"PHENIX");
			tex->SetTextFont(43);
			tex->SetTextSize(24);
			tex->Draw();
		}

	}

	if ( bSAVE ){
		for (int iarm=0; iarm<narm; iarm++){
			c13[iarm]->cd();
			c13[iarm]->SaveAs(Form("pdf/fig_RAB_Ncoll_arm%d.pdf",iarm));
		}//iarm
	}


}
