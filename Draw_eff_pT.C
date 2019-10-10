#include "Style.h"

void Draw_eff_pT(){

	const bool bSAVE = false;

	SetStyle();
	//gStyle->SetLegendTextSize(20);

	const int narm = 2;
	const int nset = 3;

	TFile *infile[nset];
	infile[0] = new TFile("eff_files/Run15pp200_acceff_pT_InclusiveJpsi_EMBED_C.root","read");
	infile[1] = new TFile("eff_files/Run15pAu200_CENT6084_acceff_pT_InclusiveJpsi_EMBED_C.root","read");
	infile[2] = new TFile("eff_files/Run15pAu200_CENT0005_acceff_pT_InclusiveJpsi_EMBED_C.root","read");

	TFile *infile_trig[nset];
	infile_trig[0] = new TFile("eff_files/Run15pp200_trigeff_MUID2D_pT_output_EMBED_C.root","read");
	infile_trig[1] = new TFile("eff_files/Run15pAu200_CENT6084_trigeff_MUID2D_pT_output_EMBED_C.root","read");
	infile_trig[2] = new TFile("eff_files/Run15pAu200_CENT0005_trigeff_MUID2D_pT_output_EMBED_C.root","read");

	TF1 *feff[nset][narm];
	TF1 *ftrigeff[nset][narm];

	for (int iset=0; iset<nset; iset++){
		for (int iarm=0; iarm<narm; iarm++){

			if ( iset==0 ){
				feff[iset][iarm] = (TF1*)infile[iset]->Get(Form("frecoeff_pT_pp_arm%d",iarm));
				ftrigeff[iset][iarm] = (TF1*)infile_trig[iset]->Get(Form("ftrigeff_pT_pp_arm%d",iarm));
			}else{
				feff[iset][iarm] = (TF1*)infile[iset]->Get(Form("frecoeff_pT_pAu_arm%d",iarm));
				ftrigeff[iset][iarm] = (TF1*)infile_trig[iset]->Get(Form("ftrigeff_pT_dAu_arm%d",iarm));
			}

		}
	}

	TCanvas *c00[narm];
	TCanvas *c01[narm];
	
	for (int iarm=0; iarm<narm; iarm++){

		c00[iarm] = new TCanvas(Form("c00_arm%d",iarm),Form("c00_arm%d",iarm),1.3*400,400);
		SetPadStyle();

		gPad->SetRightMargin(0.02);
		gPad->SetLeftMargin(0.14);
		gPad->SetBottomMargin(0.15);
		htmp = (TH1F*)gPad->DrawFrame(0,0,7.0,0.12);
		SetHistoStyle("p_{T} (GeV/c)","Acceptance and efficiency","",24,20);
		htmp->GetYaxis()->SetTitleOffset(1.0);
		htmp->GetXaxis()->SetTitleOffset(1.0);

		feff[0][iarm]->SetLineColor(1);
		feff[0][iarm]->SetLineStyle(1);
		feff[0][iarm]->SetLineWidth(3);
		feff[0][iarm]->Draw("p same");

		feff[1][iarm]->SetLineColor(2);
		feff[1][iarm]->SetLineStyle(2);
		feff[1][iarm]->SetLineWidth(3);
		feff[1][iarm]->Draw("p same");

		feff[2][iarm]->SetLineColor(4);
		feff[2][iarm]->SetLineStyle(9);
		feff[2][iarm]->SetLineWidth(3);
		feff[2][iarm]->Draw("p same");

		{
			TLatex *tex = new TLatex(0.3,0.005,"PHENIX simulation");
			tex->SetTextFont(43);
			tex->SetTextSize(20);
			tex->Draw();
		}

		{
			TLatex *tex = new TLatex(6.5,0.11,Form("(%c)",97+iarm));
			tex->SetTextFont(43);
			tex->SetTextSize(20);
			tex->Draw();
		}

		{
			TLegend *leg = new TLegend(0.15,0.7,0.7,0.9);
			leg->SetFillStyle(0);
			leg->SetBorderSize(0);
			if ( iarm==0 ){
				le = leg->AddEntry("","-2.2<y<-1.2","");
			}else{
				le = leg->AddEntry("","1.2<y<2.2","");
			}
			le->SetTextFont(43);
			le->SetTextSize(20);
			le = leg->AddEntry(feff[0][iarm],"p+p","L");
			le->SetTextFont(43);
			le->SetTextSize(20);
			le = leg->AddEntry(feff[1][iarm],"60%-84% p+Au","L");
			le->SetTextFont(43);
			le->SetTextSize(20);
			le = leg->AddEntry(feff[2][iarm],"0%-5% p+Au","L");
			le->SetTextFont(43);
			le->SetTextSize(20);
			leg->Draw();
		}
	}

	for (int iarm=0; iarm<narm; iarm++){

		c01[iarm] = new TCanvas(Form("c01_arm%d",iarm),Form("c01_arm%d",iarm),1.3*400,400);
		SetPadStyle();

		gPad->SetRightMargin(0.02);
		gPad->SetLeftMargin(0.14);
		gPad->SetBottomMargin(0.15);
		htmp = (TH1F*)gPad->DrawFrame(0,0,7.0,1.0);
		SetHistoStyle("p_{T} (GeV/c)","Trigger efficiency","",24,20);
		htmp->GetYaxis()->SetTitleOffset(1.0);
		htmp->GetXaxis()->SetTitleOffset(1.0);

		ftrigeff[0][iarm]->SetLineColor(1);
		ftrigeff[0][iarm]->SetLineStyle(1);
		ftrigeff[0][iarm]->SetLineWidth(3);
		ftrigeff[0][iarm]->Draw("p same");

		ftrigeff[1][iarm]->SetLineColor(2);
		ftrigeff[1][iarm]->SetLineStyle(2);
		ftrigeff[1][iarm]->SetLineWidth(3);
		ftrigeff[1][iarm]->Draw("p same");

		ftrigeff[2][iarm]->SetLineColor(4);
		ftrigeff[2][iarm]->SetLineStyle(9);
		ftrigeff[2][iarm]->SetLineWidth(3);
		ftrigeff[2][iarm]->Draw("p same");

		{
			TLatex *tex = new TLatex(0.3,0.05,"PHENIX simulation");
			tex->SetTextFont(43);
			tex->SetTextSize(20);
			tex->Draw();
		}

		{
			TLatex *tex = new TLatex(6.5,0.11,Form("(%c)",97+iarm));
			tex->SetTextFont(43);
			tex->SetTextSize(20);
			tex->Draw();
		}

	}//

	if ( bSAVE ){
		for (int iarm=0; iarm<2; iarm++){
			c00[iarm]->cd();
			c00[iarm]->SaveAs(Form("pdf/acceff_pT_arm%d.pdf",iarm));
		}
	}


}
