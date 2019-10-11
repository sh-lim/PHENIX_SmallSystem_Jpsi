
#include <TF1.h>
#include <TMath.h>
#include <Math/MinimizerOptions.h>
#include <TVirtualFitter.h>
#include <TMatrixDSym.h>
#include <TFile.h>
#include <TCanvas.h>
#include <TH1D.h>
#include <TGraph.h>
#include <TLegend.h>
#include <TStyle.h>
#include <TROOT.h>
#include <TLatex.h>
#include <TChain.h>
#include <TCanvas.h>
#include <TH1.h>
#include <TFitResult.h>
#include <TH1F.h>
#include <TH2D.h>
#include <TH2F.h>
#include <TF1.h>
#include <TLine.h>
#include <TRandom1.h>
#include <TPolyLine.h>
#include <TRandom3.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <cstring>
#include <TGraphErrors.h>
#include <TMultiGraph.h>
#include <TObjArray.h>
#include <TNtuple.h>

using namespace std;

void pAu_HeAu_ratio()
{

  TFile *file_pp;
  TFile *file_pAu;	  
  TFile *file_HeAu;	  
  
  // Ypp array
  double Ypp_array[2][26] = {0};
  
 // RAB arrays
  double RpAu_020_array[2][19] = {0};
  double RHeAu_020_array[2][15] = {0};

  double YpAu_020_array[2][19] = {0};
  double YHeAu_020_array[2][15] = {0};

  double YpAu_020_ERR_array[2][19] = {0};
  double YHeAu_020_ERR_array[2][15] = {0};
  
  double RpAu_020_sys_frac_array[2][19] = {0};
  double RHeAu_020_sys_frac_array[2][15] = {0};
 
  // Type A x error arrays for TGraphs
  double x_errors[19] = {0};
  double width[19] = {0};

  // Ratio arrays
  double ratio_020[2][15] = {0};
  double ratio_020_err[2][15] = {0};
  double ratio_020_sys_frac_err[2][15] = {0};
  double ratio_020_sys_err[2][15] = {0};
  
  // recalculated modified systematic error
  double HeAu_sys_frac_err_modified[2][15] = {
    {0.0729325, 0.0726472, 0.0723786, 0.0721387, 0.0719454, 0.0718148, 0.0717538, 0.0717626, 0.0718281, 0.071922, 0.072071, 0.0722479, 0.0723595, 0.0802155, 0.081682},
    {0.0333082, 0.0333092, 0.0333097, 0.0333094, 0.0333077, 0.0333035, 0.0332975, 0.0332925, 0.033291, 0.0332939, 0.0333029, 0.0333115, 0.033312, 0.037124, 0.0377038}};
  
  double pAu_sys_frac_err_modified[2][15] = {
    {0.0558255, 0.0557713, 0.0557469, 0.0558367, 0.0561404, 0.0566581, 0.0573065, 0.0580259, 0.0588026, 0.0596341, 0.0609256, 0.0624595, 0.0634491, 0.0642703, 0.0633949},
    {0.0345118, 0.0342197, 0.0338556, 0.0333968, 0.0328876, 0.0323953, 0.0319555, 0.0315676, 0.0312221, 0.0309151, 0.0305405, 0.0302366, 0.0301388, 0.0302095, 0.0349505}};
  
  // Ypp

  TH1F *Ypp_N = new TH1F("Ypp_N","Ypp_N",26, 0, 7);
  TH1F *Ypp_S = new TH1F("Ypp_S","Ypp_S",26, 0, 7);

// RAB 
  //////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  TH1F *RpAu_N_020 = new TH1F("RpAu_N_020","RpAu_N_020",19, 0, 7);
  TH1F *RpAu_S_020 = new TH1F("RpAu_S_020","RpAu_S_020",19, 0, 7);

  TH1F *RHeAu_N_020 = new TH1F("HeAu_020_N","HeAu_020_N",15, 0, 7);
  TH1F *RHeAu_S_020 = new TH1F("HeAu_020_S","HeAu_020_S",15, 0, 7);

// RAB error
  //////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  TH1F *YpAu_N_020 = new TH1F("YpAu_N_020","YpAu_N_020",19, 0, 7);
  TH1F *YpAu_S_020 = new TH1F("YpAu_S_020","YpAu_S_020",19, 0, 7);

  TH1F *YHeAu_N_020 = new TH1F("YHeAu_020_N","YHeAu_020_N",15, 0, 7);
  TH1F *YHeAu_S_020 = new TH1F("YHeAu_020_S","YHeAu_020_S",15, 0, 7);
  
  // RAB Fractional Systematic Error
  //////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  TH1F *RpAu_020_N_SYS_FRAC_ERR = new TH1F("pAu_020_N_sys","pAu_020_N_sys",19, 0, 7);
  TH1F *RpAu_020_S_SYS_FRAC_ERR = new TH1F("pAu_020_S_sys","pAu_020_S_sys",19, 0, 7);
  
  TH1F *RHeAu_020_N_SYS_FRAC_ERR = new TH1F("HeAu_020_N_sys","HeAu_020_N_sys",19, 0, 7);
  TH1F *RHeAu_020_S_SYS_FRAC_ERR = new TH1F("HeAu_020_S_sys","HeAu_020_S_sys",19, 0, 7);

  //Ratio errors to Write to root file
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  TH1F *pAu_HeAu_pT_ratio_020_N = new TH1F("pAu_HeAu_ratio_020_N","pAu_HeAu_ratio_020_N",15, 0, 7);  
  TH1F *pAu_HeAu_pT_ratio_020_S = new TH1F("pAu_HeAu_ratio_020_S","pAu_HeAu_ratio_020_S",15, 0, 7);  
  
  TH1F *pAu_HeAu_pT_ratio_020_N_SYS_FRAC_ERR = new TH1F("pAu_HeAu_ratio_020_N_sys","pAu_HeAu_ratio_020_N_sys",15, 0, 7);  
  TH1F *pAu_HeAu_pT_ratio_020_S_SYS_FRAC_ERR = new TH1F("pAu_HeAu_ratio_020_S_sys","pAu_HeAu_ratio_020_S_sys",15, 0, 7);

 ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  file_pp = TFile::Open("Ypp_vs_pT.root");
  
  // YpAp
  file_pp->GetObject("Ypp_vs_pT_S",Ypp_S); // for weighted average of RpAu bins to match RHeAu binning
  file_pp->GetObject("Ypp_vs_pT_N",Ypp_N); 

  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  file_pAu = TFile::Open("RpAu_YpAu_vs_pT_cent.root");
  
    // RpAu
  file_pAu->GetObject("RpAu_vs_pT_S_020",RpAu_S_020);
  file_pAu->GetObject("RpAu_vs_pT_N_020",RpAu_N_020);

    // YpAu
  file_pAu->GetObject("YpAu_vs_pT_S_020",YpAu_S_020); // for type A erros
  file_pAu->GetObject("YpAu_vs_pT_N_020",YpAu_N_020); // for type A erros

  // RpAu sys err
  file_pAu->GetObject("RpAu_vs_pT_S_020_sys_frac",RpAu_020_S_SYS_FRAC_ERR);
  file_pAu->GetObject("RpAu_vs_pT_N_020_sys_frac",RpAu_020_N_SYS_FRAC_ERR);

//////////////////////////////////////////////////////////////////////////////
 
  file_HeAu = TFile::Open("RHeAu_YHeAu_vs_pT_cent.root");
 
  // RHeAu
  file_HeAu->GetObject("RHeAu_vs_pT_S_020",RHeAu_S_020);
  file_HeAu->GetObject("RHeAu_vs_pT_N_020",RHeAu_N_020);

  file_HeAu->GetObject("YHeAu_vs_pT_N_020",YHeAu_N_020); // for type A erros
  file_HeAu->GetObject("YHeAu_vs_pT_S_020",YHeAu_S_020); // for Type A errors

  // RHeAu sys err
  file_HeAu->GetObject("RHeAu_vs_pT_S_020_sys_frac",RHeAu_020_S_SYS_FRAC_ERR);
  file_HeAu->GetObject("RHeAu_vs_pT_N_020_sys_frac",RHeAu_020_N_SYS_FRAC_ERR);
  
//////////////////////////////////////////////////////////////////////////////

  double temp_typeA_err[2][2][19] = {0};
  double temp_typeA_frac_err[2][2][19] = {0};
 
  for(int arm = 0; arm < 2; arm++)
    {
      for(int i = 0; i < 15; i++)
	{
	  if(arm == 0)
	    {
	      RHeAu_020_array[arm][i] = RHeAu_S_020->GetBinContent(i+1);

	      YHeAu_020_array[arm][i] = YHeAu_S_020->GetBinContent(i+1);
	      temp_typeA_err[0][arm][i] = YHeAu_S_020->GetBinError(i+1);
	      temp_typeA_frac_err[0][arm][i] = temp_typeA_err[0][arm][i] / YHeAu_020_array[arm][i];  // convert to fraction

	      YHeAu_020_ERR_array[arm][i] =  temp_typeA_frac_err[0][arm][i] * RHeAu_020_array[arm][i];
	      RHeAu_020_sys_frac_array[arm][i] = RHeAu_020_S_SYS_FRAC_ERR ->GetBinError(i+1);
	    }
	  if(arm == 1)
	    {
	      RHeAu_020_array[arm][i] = RHeAu_N_020->GetBinContent(i+1);

	      YHeAu_020_array[arm][i] = YHeAu_N_020->GetBinContent(i+1);
	      temp_typeA_err[0][arm][i] = YHeAu_N_020->GetBinError(i+1);
	      temp_typeA_frac_err[0][arm][i] = temp_typeA_err[0][arm][i] / YHeAu_020_array[arm][i];  // convert to fraction

	      YHeAu_020_ERR_array[arm][i] =  temp_typeA_frac_err[0][arm][i] * RHeAu_020_array[arm][i];
	      RHeAu_020_sys_frac_array[arm][i] = RHeAu_020_N_SYS_FRAC_ERR ->GetBinError(i+1);
	    }
	  width[i] = 0.125;
	}
    }

 for(int arm = 0; arm < 2; arm++)
    {
      for(int i = 0; i < 10; i++)
	{
	  if(arm == 0)
	    {
	      RpAu_020_array[arm][i] = RpAu_S_020->GetBinContent(i+1);

	      YpAu_020_array[arm][i] = YpAu_S_020->GetBinContent(i+1);
	      temp_typeA_err[1][arm][i] = YpAu_S_020->GetBinError(i+1);
	      temp_typeA_frac_err[0][arm][i] = temp_typeA_err[1][arm][i] / YpAu_020_array[arm][i];  // convert to fraction

	      YpAu_020_ERR_array[arm][i] =  temp_typeA_frac_err[1][arm][i] * RpAu_020_array[arm][i];
	      RpAu_020_sys_frac_array[arm][i] = RpAu_020_S_SYS_FRAC_ERR ->GetBinError(i+1);
	    }
	  if(arm == 1)
	    {
	      RpAu_020_array[arm][i] = RpAu_N_020->GetBinContent(i+1);

	      YpAu_020_array[arm][i] = YpAu_N_020->GetBinContent(i+1);
	      temp_typeA_err[1][arm][i] = YpAu_N_020->GetBinError(i+1);
	      temp_typeA_frac_err[0][arm][i] = temp_typeA_err[1][arm][i] / YpAu_020_array[arm][i];  // convert to fraction

	      YpAu_020_ERR_array[arm][i] =  temp_typeA_frac_err[1][arm][i] * RpAu_020_array[arm][i];
	      RpAu_020_sys_frac_array[arm][i] = RpAu_020_N_SYS_FRAC_ERR ->GetBinError(i+1);
	    }
	}
    }


 // take weighted average of RpAu using pp inv yield
for(int arm = 0; arm < 2; arm++)
    {
      if(arm == 0)
	{
	  RpAu_020_array[arm][10] = ( Ypp_S->GetBinContent(11) * RpAu_S_020->GetBinContent(11) ) + ( Ypp_S->GetBinContent(12) * RpAu_S_020->GetBinContent(12) );
	  RpAu_020_array[arm][11] = ( Ypp_S->GetBinContent(13) * RpAu_S_020->GetBinContent(13) ) + ( Ypp_S->GetBinContent(14) * RpAu_S_020->GetBinContent(14) );
	  RpAu_020_array[arm][12] = ( Ypp_S->GetBinContent(15) * RpAu_S_020->GetBinContent(15) ) + ( Ypp_S->GetBinContent(16) * RpAu_S_020->GetBinContent(16) );
	  RpAu_020_array[arm][13] = ( Ypp_S->GetBinContent(17) * RpAu_S_020->GetBinContent(17) ) + ( Ypp_S->GetBinContent(18) * RpAu_S_020->GetBinContent(18) ) + ( Ypp_S->GetBinContent(19) * RpAu_S_020->GetBinContent(19) ) + ( Ypp_S->GetBinContent(20) * RpAu_S_020->GetBinContent(20) ); 
	}
      if(arm == 1)
	{
	  RpAu_020_array[arm][10] = ( Ypp_N->GetBinContent(11) * RpAu_N_020->GetBinContent(11) ) + ( Ypp_N->GetBinContent(12) * RpAu_N_020->GetBinContent(12) );
	  RpAu_020_array[arm][11] = ( Ypp_N->GetBinContent(13) * RpAu_N_020->GetBinContent(13) ) + ( Ypp_N->GetBinContent(14) * RpAu_N_020->GetBinContent(14) );
	  RpAu_020_array[arm][12] = ( Ypp_N->GetBinContent(15) * RpAu_N_020->GetBinContent(15) ) + ( Ypp_N->GetBinContent(16) * RpAu_N_020->GetBinContent(16) );
	  RpAu_020_array[arm][13] = ( Ypp_N->GetBinContent(17) * RpAu_N_020->GetBinContent(17) ) + ( Ypp_N->GetBinContent(18) * RpAu_N_020->GetBinContent(18) ) + ( Ypp_N->GetBinContent(19) * RpAu_N_020->GetBinContent(19) ) + ( Ypp_N->GetBinContent(20) * RpAu_N_020->GetBinContent(20) ); 
	}
     }
 
 // divide by sum of weight 
for(int arm = 0; arm < 2; arm++)
    {
      if(arm == 0)
	{
	  RpAu_020_array[arm][10] /= ( Ypp_S->GetBinContent(11) + Ypp_S->GetBinContent(12) );
	  RpAu_020_array[arm][11] /= ( Ypp_S->GetBinContent(13) + Ypp_S->GetBinContent(14) );
	  RpAu_020_array[arm][12] /= ( Ypp_S->GetBinContent(15) + Ypp_S->GetBinContent(16) );
	  RpAu_020_array[arm][13] /= ( Ypp_S->GetBinContent(17) + Ypp_S->GetBinContent(18) + Ypp_S->GetBinContent(19) + Ypp_S->GetBinContent(20) );
	  RpAu_020_array[arm][14] = RpAu_S_020->GetBinContent(19); // bin 19 in pAu == 5.0 - 7.0 GeV (binning matches HeAu here, so no weighted average)
	}
      if(arm == 1)
	{
	  RpAu_020_array[arm][10] /= ( Ypp_S->GetBinContent(11) + Ypp_S->GetBinContent(12) );
	  RpAu_020_array[arm][11] /= ( Ypp_S->GetBinContent(13) + Ypp_S->GetBinContent(14) );
	  RpAu_020_array[arm][12] /= ( Ypp_S->GetBinContent(15) + Ypp_S->GetBinContent(16) );
	  RpAu_020_array[arm][13] /= ( Ypp_S->GetBinContent(17) + Ypp_S->GetBinContent(18) + Ypp_S->GetBinContent(19) + Ypp_S->GetBinContent(20) );
	  RpAu_020_array[arm][14] = RpAu_N_020->GetBinContent(19); // bin 19 in pAu == 5.0 - 7.0 GeV (binning matches HeAu here, so no weighted average)
	}
    }

 // fill ratio arrays
 for(int arm = 0; arm < 2; arm++)
    {
      for(int i = 0; i < 15; i++)
	{
	  ratio_020[arm][i] = RpAu_020_array[arm][i] /  RHeAu_020_array[arm][i]; 
	  ratio_020_err[arm][i] = sqrt(  ( (YpAu_020_ERR_array[arm][i]/RpAu_020_array[arm][i]) * (YpAu_020_ERR_array[arm][i]/RpAu_020_array[arm][i]) ) + ( (YHeAu_020_ERR_array[arm][i] / RHeAu_020_array[arm][i]) * (YHeAu_020_ERR_array[arm][i]/RHeAu_020_array[arm][i]) ) ) * ratio_020[arm][i];
       	  ratio_020_sys_frac_err[arm][i] = sqrt( (pAu_sys_frac_err_modified[arm][i] * pAu_sys_frac_err_modified[arm][i]) + (HeAu_sys_frac_err_modified[arm][i] * HeAu_sys_frac_err_modified[arm][i]) );
	  ratio_020_sys_err[arm][i] = ratio_020_sys_frac_err[arm][i] * ratio_020[arm][i];

	}
    }

 int bins = 15;
 double y_errors[15] = {0};
 
 double pt_array_ratio[15] =  {0.125,0.375,0.625,0.875,1.125,1.375,1.625,1.875,2.125,2.375,2.75,3.25,3.75,4.50,6.00};
 
  TGraphErrors *grN; 
  TGraphErrors *grN_sys;

  TGraphErrors *grS; 
  TGraphErrors *grS_sys;
 
  grN = new TGraphErrors(bins,pt_array_ratio,ratio_020[1],x_errors,ratio_020_err[1]);
  grN_sys = new TGraphErrors(bins,pt_array_ratio,ratio_020[1],width,ratio_020_sys_err[1]);
  
  grS = new TGraphErrors(bins, pt_array_ratio,ratio_020[0],x_errors,ratio_020_err[0]);
  grS_sys = new TGraphErrors(bins, pt_array_ratio,ratio_020[0],width,ratio_020_sys_err[0]);
  
  TCanvas *c1 = new TCanvas("c1","North R_{pAu/HeAu}",200,10,700,500);
  c1->SetGrid();
   
  // NORTH RpAu measurement
  grN->SetTitle("R_{pAu/HeAu} vs. p_{T}, North");
  grN->GetXaxis()->SetTitle("Transverse Momentum (GeV/c)");
  grN->SetMarkerStyle(20);
  grN->SetMarkerColor(kBlue);
  grN->SetMarkerSize(1.0);
  grN->GetYaxis()->SetRangeUser(0,2.5);
  grN->GetXaxis()->SetLimits(0,8);
  grN->Draw("AP");

  //NORTH systematic error
  grN_sys->SetLineColor(kBlack);
  grN_sys->SetFillStyle(0);
  grN_sys->Draw("e2same");

  TCanvas *c2 = new TCanvas("c2","South R_{pAu/HeAu}",200,10,700,500);
  c2->SetGrid();
   
 // SOUTH RpAu measurement
  grS->SetTitle("R_{pAu/HeAu} vs. p_{T}");
  grS->GetXaxis()->SetTitle("Transverse Momentum (GeV/c)");
  grS->SetMarkerStyle(20);
  grS->SetMarkerColor(kRed);
  grS->SetMarkerSize(1.0);
  grS->GetYaxis()->SetRangeUser(0,2.5);
  grS->GetXaxis()->SetLimits(0,8);
  grS->Draw("AP");

  //SOUTH systematic error
  grS_sys->SetLineColor(kBlack);
  grS_sys->SetFillStyle(0);
  grS_sys->Draw("e2same");
  
  TF1 *linear_fit;
  linear_fit = new TF1("linear_fit","[0]",0,7);
 
  linear_fit->SetParameter(0, 1);
  linear_fit->SetLineColor(kBlue);
  linear_fit->SetLineStyle(5);
  linear_fit->SetLineWidth(2);

  TF1 *linear_fit_2;
  linear_fit_2 = new TF1("linear_fit_2","[0]",0,7);
 
  linear_fit_2->SetParameter(0, 1);
  linear_fit_2->SetLineColor(kRed);
  linear_fit_2->SetLineStyle(5);
  linear_fit_2->SetLineWidth(2);
 
  grN->Fit(linear_fit,"R");
  grS->Fit(linear_fit_2,"R");
 
  // Fill THF1
  for(int i = 0; i < 15; i++)
    {
      pAu_HeAu_pT_ratio_020_S->SetBinContent(i+1, ratio_020[0][i]); 
      pAu_HeAu_pT_ratio_020_S->SetBinError(i+1, ratio_020_err[0][i]);

      pAu_HeAu_pT_ratio_020_N->SetBinContent(i+1, ratio_020[1][i]); 
      pAu_HeAu_pT_ratio_020_N->SetBinError(i+1, ratio_020_err[1][i]);

      pAu_HeAu_pT_ratio_020_N_SYS_FRAC_ERR->SetBinError(i+1, ratio_020_sys_frac_err[1][i]);
      pAu_HeAu_pT_ratio_020_S_SYS_FRAC_ERR->SetBinError(i+1, ratio_020_sys_frac_err[0][i]);
    }

  TFile *h = new TFile("RpAu_RHeAu_ratio_vs_pT.root", "RECREATE");
  h->cd();
   
  pAu_HeAu_pT_ratio_020_N->Write();
  pAu_HeAu_pT_ratio_020_S->Write();

  pAu_HeAu_pT_ratio_020_N_SYS_FRAC_ERR->Write();
  pAu_HeAu_pT_ratio_020_S_SYS_FRAC_ERR->Write();


} // void end
