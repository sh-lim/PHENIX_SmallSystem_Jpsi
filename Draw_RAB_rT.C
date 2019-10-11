#include "Style.h"

void Draw_RAB_rT(){

	const bool bSAVE = true;

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


	TGraphErrors *hRAB_thick_pAu[narm];
	TGraphErrors *hRAB_thick_pAl[narm];
	TGraphErrors *hRAB_thick_HeAu[narm];

	TGraphErrors *hRAB_thick_pAu_sys[narm];
	TGraphErrors *hRAB_thick_pAl_sys[narm];
	TGraphErrors *hRAB_thick_HeAu_sys[narm];

	double rt_pal[3] = {2.37, 2.89, 3.32};
	double rt_pau[6] = {3.21, 3.52, 3.88, 4.39, 5.02, 6.56};
	double rt_heau[3] = {};

	double thick_pal[3] = {0.568, 0.448, 0.353};
	double thick_pau[6] = {1.750, 1.661, 1.538, 1.361, 1.123, 0.617};
	double thick_heau[3] = {1.657, 1.307, 0.800};


	for (int iarm=0; iarm<narm; iarm++){

		// pAu
		hRAB_Ncoll_pAu_sys[iarm] = (TGraphErrors*)infile_pAu->Get(Form("RAB_Ncoll_syserr_arm%d",iarm));
		hRAB_Ncoll_pAu[iarm] = (TGraphErrors*)infile_pAu->Get(Form("RAB_Ncoll_staerr_arm%d",iarm));

		int NPTS =  hRAB_Ncoll_pAu[iarm]->GetN();
		//cout << "The pAu TGraph vs Ncoll has " << NPTS << " entries" << endl;

		hRAB_thick_pAu[iarm] = new TGraphErrors();
		hRAB_thick_pAu_sys[iarm] = new TGraphErrors();;

		for(int ipt = 0; ipt < NPTS; ++ipt)
		{
			double x = 0.0; double ex = 0.0;
			double y = 0.0; double ey = 0.0;

			hRAB_Ncoll_pAu[iarm]->GetPoint(ipt, x, y);
			ex = 0.0;
			ey = hRAB_Ncoll_pAu[iarm]->GetErrorY(ipt);
			hRAB_thick_pAu[iarm]->SetPoint(ipt, thick_pau[ipt] , y);
			hRAB_thick_pAu[iarm]->SetPointError(ipt, ex, ey );
			//cout << "pAu:  ipt " << ipt << " x " << x << " y " << y << " ex " << ex << " ey " << ey << endl; 

			hRAB_Ncoll_pAu_sys[iarm] ->GetPoint(ipt, x, y);
			ex = thick_pau[NPTS-1]/20.0;
			ey = hRAB_Ncoll_pAu_sys[iarm]->GetErrorY(ipt);
			hRAB_thick_pAu_sys[iarm]->SetPoint(ipt, thick_pau[ipt] , y);
			hRAB_thick_pAu_sys[iarm]->SetPointError(ipt, ex, ey );
			//cout << " sys: ipt " << ipt << " x " << x << " y " << y << " ex " << ex << " ey " << ey << endl; 
		}


		hRAB_thick_pAu_sys[iarm]->SetMarkerStyle(20);
		hRAB_thick_pAu_sys[iarm]->SetMarkerColor(kGreen+2);
		hRAB_thick_pAu_sys[iarm]->SetLineColor(kGreen+2);
		hRAB_thick_pAu_sys[iarm]->SetLineWidth(1);
		hRAB_thick_pAu_sys[iarm]->SetFillStyle(0);

		hRAB_thick_pAu[iarm]->SetMarkerStyle(20);
		hRAB_thick_pAu[iarm]->SetMarkerColor(kGreen+2);
		hRAB_thick_pAu[iarm]->SetLineColor(kGreen+2);

		// pAl

		hRAB_Ncoll_pAl_sys[iarm] = (TGraphErrors*)infile_pAl->Get(Form("RAB_Ncoll_syserr_arm%d",iarm));
		hRAB_Ncoll_pAl[iarm] = (TGraphErrors*)infile_pAl->Get(Form("RAB_Ncoll_staerr_arm%d",iarm));

		NPTS =  hRAB_Ncoll_pAl[iarm]->GetN();
		//cout << "The pAl TGraph vs Ncoll has " << NPTS << " entries" << endl;

		hRAB_thick_pAl[iarm] = new TGraphErrors();
		hRAB_thick_pAl_sys[iarm] = new TGraphErrors();;

		for(int ipt = 0; ipt < NPTS; ++ipt)
		{
			double x = 0.0; double ex = 0.0;
			double y = 0.0; double ey = 0.0;

			hRAB_Ncoll_pAl[iarm]->GetPoint(ipt, x, y);
			ex = 0.0;
			ey = hRAB_Ncoll_pAl[iarm]->GetErrorY(ipt);
			hRAB_thick_pAl[iarm]->SetPoint(ipt, thick_pal[ipt] , y);
			hRAB_thick_pAl[iarm]->SetPointError(ipt, ex, ey );
			//cout << "pAl:  ipt " << ipt << " x " << x << " y " << y << " ex " << ex << " ey " << ey << endl; 

			hRAB_Ncoll_pAl_sys[iarm] ->GetPoint(ipt, x, y);
			ex = thick_heau[NPTS-1] / 20.0;
			ey = hRAB_Ncoll_pAl_sys[iarm]->GetErrorY(ipt);
			hRAB_thick_pAl_sys[iarm]->SetPoint(ipt, thick_pal[ipt] , y);
			hRAB_thick_pAl_sys[iarm]->SetPointError(ipt, ex, ey );
			//cout << " sys: ipt " << ipt << " x " << x << " y " << y << " ex " << ex << " ey " << ey << endl; 
		}

		hRAB_thick_pAl_sys[iarm]->SetMarkerStyle(20);
		hRAB_thick_pAl_sys[iarm]->SetMarkerColor(2);
		hRAB_thick_pAl_sys[iarm]->SetLineColor(2);
		hRAB_thick_pAl_sys[iarm]->SetLineWidth(1);
		hRAB_thick_pAl_sys[iarm]->SetFillStyle(0);

		hRAB_thick_pAl[iarm]->SetMarkerStyle(20);
		hRAB_thick_pAl[iarm]->SetMarkerColor(2);
		hRAB_thick_pAl[iarm]->SetLineColor(2);

		// HeAu

		hRAB_Ncoll_HeAu_sys[iarm] = (TGraphErrors*)infile_HeAu->Get(Form("RAB_Ncoll_syserr_arm%d",iarm));
		hRAB_Ncoll_HeAu[iarm] = (TGraphErrors*)infile_HeAu->Get(Form("RAB_Ncoll_staerr_arm%d",iarm));

		NPTS =  hRAB_Ncoll_HeAu[iarm]->GetN();
		//cout << "The HeAu TGraph vs Ncoll has " << NPTS << " entries" << endl;

		hRAB_thick_HeAu[iarm] = new TGraphErrors();
		hRAB_thick_HeAu_sys[iarm] = new TGraphErrors();;

		for(int ipt = 0; ipt < NPTS; ++ipt)
		{
			double x = 0.0; double ex = 0.0;
			double y = 0.0; double ey = 0.0;

			hRAB_Ncoll_HeAu[iarm]->GetPoint(ipt, x, y);
			ex = 0.0;
			ey = hRAB_Ncoll_HeAu[iarm]->GetErrorY(ipt);
			hRAB_thick_HeAu[iarm]->SetPoint(ipt, thick_heau[ipt] , y);
			hRAB_thick_HeAu[iarm]->SetPointError(ipt, ex, ey );
			//cout << "HeAu:  ipt " << ipt << " x " << x << " y " << y << " ex " << ex << " ey " << ey << endl; 

			hRAB_Ncoll_HeAu_sys[iarm] ->GetPoint(ipt, x, y);
			ex = thick_heau[NPTS-1]/20.0;
			ey = hRAB_Ncoll_HeAu_sys[iarm]->GetErrorY(ipt);
			hRAB_thick_HeAu_sys[iarm]->SetPoint(ipt, thick_heau[ipt] , y);
			hRAB_thick_HeAu_sys[iarm]->SetPointError(ipt, ex, ey );
			//cout << " sys: ipt " << ipt << " x " << x << " y " << y << " ex " << ex << " ey " << ey << endl; 
		}

		hRAB_thick_HeAu_sys[iarm]->SetMarkerStyle(20);
		hRAB_thick_HeAu_sys[iarm]->SetMarkerColor(4);
		hRAB_thick_HeAu_sys[iarm]->SetLineColor(6);
		hRAB_thick_HeAu_sys[iarm]->SetLineWidth(1);
		hRAB_thick_HeAu_sys[iarm]->SetFillStyle(0);

		hRAB_thick_HeAu[iarm]->SetMarkerStyle(20);
		hRAB_thick_HeAu[iarm]->SetMarkerColor(6);
		hRAB_thick_HeAu[iarm]->SetLineColor(6);


	}//iarm


	TCanvas *c13[narm];
	for (int iarm=0; iarm<narm; iarm++){
		c13[iarm] = new TCanvas(Form("c13_arm%d",iarm),Form("c13_arm%d",iarm),1.4*1*400,400);
		SetPadStyle();
		gPad->SetRightMargin(0.03);
		gPad->SetLeftMargin(0.13);
		gPad->SetBottomMargin(0.17);
		htmp = (TH1F*)gPad->DrawFrame(0,0,2.0,2.0);
		SetHistoStyle("#LTT_{A}#GT","R_{AB}","",28,24);
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

			TLine *line = new TLine(0, 1, 2, 1);
			line->SetLineStyle(2);
			line->Draw();

			TBox *box = new TBox(2*0.97,1-0.101,2,1+0.101);
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
			le = leg->AddEntry(hRAB_thick_pAl[iarm],"p+Al","P");
			le = leg->AddEntry(hRAB_thick_pAu[iarm],"p+Au","P");
			le = leg->AddEntry(hRAB_thick_HeAu[iarm],"^{3}He+Au","P");
			leg->Draw();
		}

		hRAB_thick_pAu_sys[iarm]->Draw("2");
		hRAB_thick_pAu[iarm]->Draw("P");

		hRAB_thick_pAl_sys[iarm]->Draw("2");
		hRAB_thick_pAl[iarm]->Draw("P");

		hRAB_thick_HeAu_sys[iarm]->Draw("2");
		hRAB_thick_HeAu[iarm]->Draw("P");

		{
			TLatex *tex = new TLatex(22.5,1.82,Form("(%c)",97+iarm));
			tex->SetTextFont(43);
			tex->SetTextSize(24);
			tex->Draw();
		}

	}

	if ( bSAVE ){
		for (int iarm=0; iarm<narm; iarm++){
			c13[iarm]->cd();
			c13[iarm]->SaveAs(Form("pdf/fig_RAB_thick_arm%d.pdf",iarm));
		}//iarm
	}

}
