#include "/phenix/u/shlim/Style.h"

void Draw_eff_pAl(const char *embed="EMBED"){

	const int ncent = 3;
	const int narm = 2;
	const int arr_cent[ncent+1] = {0, 20, 40, 72}; 

	const int nColor[ncent] = {1, 2, 4};

	TFile *infile0[ncent];
	TFile *infile1[ncent];

	TH1D *hrecoeff[ncent][narm];
	TH1D *htrigeff[ncent][narm];

	for (int icent=0; icent<ncent; icent++){
		infile0[icent] = new TFile(Form("Run15pAl200_CENT%02d%02d_trigeff_MUID2D_pT_output_%s_C.root",arr_cent[icent],arr_cent[icent+1],embed),"read");
		infile1[icent] = new TFile(Form("Run15pAl200_CENT%02d%02d_acceff_pT_InclusiveJpsi_%s_C.root",arr_cent[icent],arr_cent[icent+1],embed),"read");

		for (int iarm=0; iarm<narm; iarm++){
			htrigeff[icent][iarm] = (TH1D*)infile0[icent]->Get(Form("htrigeff_pT_pAl_arm%d",iarm));
			hrecoeff[icent][iarm] = (TH1D*)infile1[icent]->Get(Form("hrecoeff_pT_pAl_arm%d",iarm));

			htrigeff[icent][iarm]->SetMarkerStyle(24+iarm);
			htrigeff[icent][iarm]->SetMarkerColor(nColor[icent]);
			htrigeff[icent][iarm]->SetLineColor(nColor[icent]);

			hrecoeff[icent][iarm]->SetMarkerStyle(24+iarm);
			hrecoeff[icent][iarm]->SetMarkerColor(nColor[icent]);
			hrecoeff[icent][iarm]->SetLineColor(nColor[icent]);
		}//
	}//

	TCanvas *c1 = new TCanvas("c1","c1",1.2*2*400,400);
	c1->Divide(2,1);

	c1->cd(1);
	SetPadStyle();
	htmp = (TH1D*)gPad->DrawFrame(0,0,8,1);
	SetHistoStyle();

	for (int icent=0; icent<ncent; icent++){
		for (int iarm=0; iarm<narm; iarm++){
			htrigeff[icent][iarm]->Draw("p same");
		}
	}

	
	c1->cd(2);
	SetPadStyle();
	htmp = (TH1D*)gPad->DrawFrame(0,0,8,0.1);
	SetHistoStyle();

	for (int icent=0; icent<ncent; icent++){
		for (int iarm=0; iarm<narm; iarm++){
			hrecoeff[icent][iarm]->Draw("p same");
		}
	}


}
