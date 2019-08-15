// to change colors of data points, change the TGRaph Error definitions for RpAu_bkwd group and RpAu_fwrd group at lines 300 and 767 
  

void Draw_ptsq()
{
  
  int i_cent = 0; // 0 = 0-20 (or for pT squared plot), 1 = 20-40,2 = 40-60 (or 40-88), 3 = 60-84 
 

  bool draw_pAu = 0;
  bool draw_dAu = 0;
  bool draw_HeAu = 0;
  bool draw_pAl = 0;
  bool draw_NS = 0;
  bool pt_squared = 1;


  double ncoll_pAu[7] = {9.7, 8.4, 7.4, 8.2, 6.1, 4.4, 2.6};
  double ncoll_HeAu[3] = {22.3,14.8,5.4833};
  double ncoll_pAl[3] = {3.35, 2.3, 1.7};
 
  //For pt squared plots -previosu values (for preliminary)
  double pAu_N_ncoll[7] = { 3.57363, 3.53415, 3.55327, 3.54771, 3.48693, 3.3936, 3.25398};
  double pAu_S_ncoll[7] = {3.60433, 3.30734, 3.3847, 3.52066, 3.42589, 3.33675, 3.38347};

  double pAu_N_stat[7] = {0.212155, 0.212712, 0.157712, 0.123424, 0.124755, 0.134495, 0.147847};
  double pAu_S_stat[7] = {0.241367, 0.226709, 0.184654, 0.131978, 0.148624, 0.197885, 0.234599};

  double pAu_N_sys_up[7] = {0.234261, 0.235853, 0.23978, 0.239401, 0.226316, 0.233597, 0.224206};
  double pAu_S_sys_up[7] = {0.239434, 0.224555, 0.244746, 0.241754, 0.242928, 0.22707, 0.246628};

  double pAu_N_sys_down[7] = {0.309948, 0.311179, 0.316446, 0.315486, 0.297948, 0.3056, 0.290851};
  double pAu_S_sys_down[7] = {0.324666, 0.299797, 0.32719, 0.32471, 0.323413, 0.302212, 0.327299};

  double HeAu_N_ncoll[3] = {3.48699, 3.31614, 3.33336};
  double HeAu_S_ncoll[3] = { 3.52125, 3.45499, 3.40047};

  double HeAu_N_stat[3] = {0.217861, 0.238833, 0.244705};
  double HeAu_S_stat[3] = {0.193704, 0.24534, 0.241158};

  double HeAu_N_sys_up[3] = {0.264157, 0.254954, 0.244728};
  double HeAu_S_sys_up[3] = {0.254302, 0.262157, 0.263699};

  double HeAu_N_sys_down[3] = {0.360241, 0.344067, 0.331603};
  double HeAu_S_sys_down[3] = {0.353651, 0.361043, 0.362704};


  double pAl_N_ncoll[3] = {3.22431, 3.32582, 3.07016};
  double pAl_S_ncoll[3] = {3.12468, 2.96197, 3.12653};

  double pAl_N_stat[3] = {0.129216, 0.139618, 0.132623};
  double pAl_S_stat[3] = {0.161672, 0.169745, 0.171909};

  double pAl_N_sys_up[3] = {0.23819, 0.238708, 0.221};
  double pAl_S_sys_up[3] = {0.224095, 0.214787, 0.238387};

  double pAl_N_sys_down[3] = {0.314817, 0.317681, 0.29006};
  double pAl_S_sys_down[3] = {0.295753, 0.280596, 0.313873};

  double HeAu_xlow[3] = {0};
  double HeAu_xhigh[3] = {0};
  double pAl_xlow[3] = {0};
  double pAl_xhigh[3] = {0};
  double pAu_xlow[7] = {0};
  double pAu_xhigh[7] = {0};
  double HeAu_ylow[3] = {0};
  double HeAu_yhigh[3] = {0};
  double pAu_ylow[7] = {0};
  double pAu_yhigh[7] = {0};
  double pAl_ylow[3] = {0};
  double pAl_yhigh[3] = {0};

  double width = 0.5;

  for(int i = 0; i < 3; i++)
    {
      HeAu_xlow[i] = width;
      HeAu_xhigh[i] = width;
      HeAu_ylow[i] = HeAu_S_sys_down[i];
      HeAu_yhigh[i] = HeAu_S_sys_up[i] ;
      cout << HeAu_xlow[i] << "," << HeAu_xhigh[i] << "," << HeAu_ylow[i] << "," << HeAu_yhigh[i] << endl;
    }
  for(int i = 0; i < 3; i++)
    {
      pAl_xlow[i] = width;
      pAl_xhigh[i] = width;
      pAl_ylow[i] = pAl_S_sys_down[i];
      pAl_yhigh[i] = pAl_S_sys_up[i] ;
      cout << pAl_xlow[i] << "," << pAl_xhigh[i] << "," << pAl_ylow[i] << "," << pAl_yhigh[i] << endl;
    }

  for(int i = 0; i < 7; i++)
    {
      pAu_xlow[i] = width;
      pAu_xhigh[i] = width;
      pAu_ylow[i] = pAu_S_sys_down[i];
      pAu_yhigh[i] = pAu_S_sys_up[i];
    }


 

  double pt_dAu[24] = {0.125,0.375,0.625,0.875,1.125,1.375,1.625,1.875,2.125,2.375,2.625,2.875,3.125,3.375,3.625,3.875,4.125,4.375,4.625,4.875,5.25,5.75,6.50,7.5}; 

  double pt_pAu[19] = {0.125, 0.375, 0.625, 0.875, 1.125, 1.375, 1.625, 1.875, 2.125, 2.375, 2.625, 2.875, 3.125, 3.375, 3.625, 3.875, 4.25, 4.75, 6}; // for R_HeAu

  double pt_pAl[20] = {0.125, 0.375, 0.625, 0.875, 1.125, 1.375, 1.625, 1.875, 2.125, 2.375, 2.625, 2.875, 3.125, 3.375, 3.625, 3.875, 4.25, 4.75, 5.5, 6.5}; // for R_pAl

  double pt_HeAu[13] = {0.125, 0.375, 0.625, 0.875, 1.125, 1.375, 1.625, 1.875, 2.125, 2.375, 2.75, 3.25, 3.75};


  TCanvas *c1_bkwd = new TCanvas(); c1_bkwd->SetLeftMargin(10); c1_bkwd->cd();
  int pt_max = 7;

  //TH1 *hframe = new TH2F("hframe","",100,0,pt_max,100,0,2.25);
  TH1 *hframe = new TH2F("hframe","",100,0,25,100,1,6);

  hframe->SetDirectory(0);
  hframe->SetStats(0);
  hframe->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  if(pt_squared)
     hframe->GetXaxis()->SetTitle("N_{coll}");
  hframe->GetXaxis()->SetMoreLogLabels();
  hframe->GetXaxis()->SetLabelOffset(0.009);
  hframe->GetXaxis()->SetLabelSize(0.06);
  hframe->GetXaxis()->SetTitleOffset(1.2);
  hframe->GetXaxis()->SetTitleSize(0.06);

  if(draw_pAu && draw_NS)
    hframe->GetYaxis()->SetTitle("R_{p+A} ");  
  if(draw_pAu && draw_dAu)
    hframe->GetYaxis()->SetTitle("R_{p/d+A} ");
  if(draw_HeAu && draw_NS)
    hframe->GetYaxis()->SetTitle("R_{^{3}He+A} ");
  if(draw_HeAu && draw_pAu)
    hframe->GetYaxis()->SetTitle("R_{p/^{3}He+A} ");
  if(draw_HeAu && draw_dAu && draw_pAu)
    hframe->GetYaxis()->SetTitle("R_{p/d/^{3}He+A} ");
  if(pt_squared)
    hframe->GetYaxis()->SetTitle("#LT p_{T}^{2} #GT ");

  hframe->GetYaxis()->SetLabelSize(0.06);
  hframe->GetYaxis()->SetTitleSize(0.07);
  hframe->GetYaxis()->SetTitleOffset(0.8); //0.6
  hframe->GetZaxis()->SetLabelSize(0.05);
  
  hframe->GetYaxis()->SetNdivisions(404);
  hframe->GetXaxis()->SetNdivisions(404);
 
  gPad->SetLeftMargin(0.13);
  gPad->SetBottomMargin(0.15);
  hframe->Draw("");
  if(!pt_squared)
    double width = 0.25; //width of sys error box  

  TLine *one_line = new TLine(0,1,pt_max,1);
  one_line->SetLineStyle(2);
  one_line->Draw(); 

  double adj = 1.44;
  double dx = -2;




  TGraphErrors *leg_al = new TGraphErrors(1);
  leg_al->SetName("Graph");
  leg_al->SetTitle("Graph");
  leg_al->SetFillColor(kRed);
  leg_al->SetLineWidth(2);
  leg_al->SetLineColor(kRed);
  leg_al->SetMarkerColor(kRed);
  leg_al->SetMarkerStyle(20);
  leg_al->SetMarkerSize(1.5);
  
  //south arm, p+Al
  if(!pt_squared)
    {
      leg_al->SetPoint(0,-1.5-dx,2.0-adj-0.15);
      leg_al->SetPointError(0,0,0.04);
    }
  if(draw_pAl) leg_al->Draw("psame");

  TLatex lal;
  lal.SetTextColor(kRed);
  if(draw_pAl) 
   lal.DrawLatex(-1.4-dx,1.975-adj-0.15," p+Al");
  if(draw_pAl && draw_NS) 
    lal.DrawLatex(-1.4-dx,1.925-adj," p+Al, Al-going"); 

  if(pt_squared)
    {

      leg_al->SetFillColor(kBlack);
      leg_al->SetLineColor(kBlack);
      leg_al->SetMarkerColor(kBlack);
      leg_al->SetPoint(0,-1.1-dx,3.6-adj);
      lal.SetTextColor(kBlack);
      lal.DrawLatex(-1.0-dx,3.6-adj, "  p+Al");
      leg_al->Draw("psame");
    }
      


  TGraphErrors *leg_au = new TGraphErrors(1);
  leg_au->SetName("Graph");
  leg_au->SetTitle("Graph");
  leg_au->SetLineWidth(2);
  leg_au->SetMarkerStyle(20);
  leg_au->SetMarkerSize(1.5);
  leg_au->SetFillColor(kRed);
  leg_au->SetLineColor(kRed);
  leg_au->SetMarkerColor(kRed);

  
  //south arm, p+Au
  leg_au->SetPoint(0,-1.5-dx,1.75-adj);
 if(pt_squared)
   leg_au->SetPoint(0,-1.1-dx,3.15-adj);
 leg_au->SetPointError(0,0,0.04);
   if(draw_pAu || pt_squared) 
     leg_au->Draw("psame"); // draws legend data point

  TLatex lau;
  lau->SetTextColor(kRed);
  if(pt_squared) 
     lau.DrawLatex(-1.0-dx,3.125-adj,"  p+Au");

   if(draw_pAu) 
     lau.DrawLatex(-1.4-dx,1.725-adj," p+Au"); // draws legend text description
   if(draw_pAu && draw_NS) 
     lau.DrawLatex(-1.4-dx,1.725-adj," p+Au, Au-going");


  //central arm data point
  TGraphErrors *gre = new TGraphErrors(1);
  gre->SetName("Graph");
  gre->SetTitle("Graph");
  gre->SetFillColor(2);
  gre->SetLineWidth(2);
  gre->SetMarkerStyle(20);
  gre->SetMarkerSize(1.5);
  gre->SetLineColor(2);
  gre->SetMarkerColor(2);

  
  //central arm
  //gre->SetPoint(0,-1.5-dx,1.25-adj+0.3);
  gre->SetPoint(0,-1.5-dx,1.5-adj+0.15);

  gre->SetPointError(0,0,0.04);

   if(draw_dAu) gre->Draw("psame");
  TLatex lda;
  // lda.DrawLatex(-1.1-dx,1.225-adj+0.3,"d+Au");
   if(draw_dAu) 
     lda.DrawLatex(-1.4-dx,1.425-adj+.15," d+Au, Phys. Rev. C 87, 034904");

  ////legend points
  TGraphErrors *leg_he = new TGraphErrors(1);
  leg_he->SetName("Graph");
  leg_he->SetTitle("Graph");
  leg_he->SetFillColor(kBlue);
  leg_he->SetLineWidth(2);
  leg_he->SetLineColor(kBlue);
  leg_he->SetMarkerColor(kBlue);
  leg_he->SetMarkerStyle(20);
  leg_he->SetMarkerSize(1.5);
  
  //south arm, He+Au
  leg_he->SetPoint(0,-1.5-dx,1.25-adj+0.3);

  if(pt_squared)
  leg_he->SetPoint(0,-1.1-dx,2.35-adj+0.3);

  leg_he->SetPointError(0,0,0.04);
   if(draw_HeAu || pt_squared) 
     leg_he->Draw("psame");

  TLatex lhe;
  lhe.SetTextColor(kBlue);
if(pt_squared)
   lhe.DrawLatex(-1.0-dx,2.325-adj+0.27," ^{3}He+Au");  
  if(draw_HeAu) 
    lhe.DrawLatex(-1.4-dx,1.225-adj+0.27,"^{3}He+Au");
  if(draw_HeAu && draw_NS) 
    lhe.DrawLatex(-1.4-dx,1.225-adj+0.27,"^{3}He+Au, Au-going");
  

 
  TLatex phnx; // south species  ********************************************************************************************


  if(!draw_NS && !pt_squared))
    phnx.DrawLatex(0.1,1.95,"#splitline{Inclusive J/#\psi #sqrt{s_{NN}} = 200 GeV}{-2.2<y<-1.2 (A-going)}");
  if(draw_NS)
    phnx.DrawLatex(0.1,1.95,"#splitline{Inclusive J/#\psi #sqrt{s_{NN}} = 200 GeV}{1.2<|y|<2.2}");
  if(i_cent == 0 && !pt_squared)  
    phnx.DrawLatex(0.22,1.65,"0-20%");
  if(i_cent == 1)  
    phnx.DrawLatex(0.22,1.65,"20-40%");
 if(i_cent == 2 && draw_pAu)  
     phnx.DrawLatex(0.22,1.65,"40-60%");
  if(i_cent == 3)  
     phnx.DrawLatex(0.22,1.65,"60-84%");
 if(pt_squared)
     {
       phnx.DrawLatex(0.22,4.75,"p_{T} < 4 GeV/c");
       phnx.DrawLatex(0.1,5.45,"#splitline{Inclusive J/#\psi #sqrt{s_{NN}} = 200 GeV}{-2.2<y<-1.2 (A-going)}");
     }


  // these are denoted pt
  // the other arrays later in the code are not pt dependent
  ///////////////////////////////////////////////// pAu SOUTH///////////////////////////////////////////////////////
  Double_t RpAu_pt_bkwd[4][19] = {
{0.655754, 0.799378, 0.77109, 0.816778, 0.968599, 0.858375, 1.02532, 1.05248, 1.17696, 1.17249, 1.34069, 1.06584, 1.17115, 1.25735, 1.42893, 1.22517, 1.5511, 1.68403, 1.01261},
  {0.69367, 0.832431, 0.737995, 0.915181, 1.11481, 0.943646, 1.0118, 0.894248, 1.06021, 0.934626, 1.1396, 1.13099, 1.24697, 1.53177, 1.193, 1.12424, 2.03035, 1.85966, 1.23644},
  {0.857463, 0.879539, 0.858762, 0.851599, 1.06214, 0.974822, 1.05676, 1.08839, 1.18935, 1.18439, 1.23699, 1.20187, 0.967291, 1.29903, 1.03442, 1.46514, 1.53042, 1.33616, 0.936062},
 {0.764332, 0.886179, 0.820115, 0.895519, 0.707987, 0.79463, 0.952945, 0.953294, 1.00399, 1.09747, 1.10494, 1.18616, 1.1165, 0.913715, 1.17396, 1.18286, 1.33503, 1.59771, 0.827511} }; 

  double dRpAu_pt_bkwd_stat[4][19] = {  {0.101518, 0.0672862, 0.0510978, 0.0553808, 0.0552492, 0.0575192, 0.0637386, 0.0706501, 0.0943633, 0.0929811, 0.109292, 0.107017, 0.116445, 0.154012, 0.176218, 0.178882, 0.192586, 0.275252, 0.140565},
  {0.107265, 0.0736991, 0.0705832, 0.0596514, 0.061352, 0.0690799, 0.0722959, 0.0785303, 0.0934924, 0.100672, 0.118697, 0.13239, 0.147929, 0.185099, 0.197031, 0.210761, 0.248215, 0.324591, 0.18851},
  {0.151253, 0.106005, 0.0777384, 0.0717275, 0.0748406, 0.0855182, 0.0890275, 0.0953964, 0.11933, 0.11854, 0.144307, 0.148164, 0.151441, 0.205561, 0.214159, 0.290574, 0.261073, 0.329604, 0.258275},
  {0.18182, 0.10116, 0.0917769, 0.0812453, 0.0696062, 0.0808387, 0.0893317, 0.105589, 0.121692, 0.136469, 0.145705, 0.202464, 0.183587, 0.207635, 0.211929, 0.277891, 0.294066, 0.354381, 0.190557} };

double pAu_sys_frac_S[4][19] = { 
{0.0913268, 0.0913459, 0.0914098, 0.0915607, 0.0918262, 0.0922129, 0.0927126, 0.093314, 0.0940046, 0.0947589, 0.0956316, 0.0965536, 0.0973275, 0.09751, 0.0979655, 0.0983016, 0.098625, 0.0990355, 0.100272}, // 0-20
  {0.0878714, 0.0879733, 0.0881181, 0.0883345, 0.0886382, 0.0890433, 0.0895625, 0.0901976, 0.0909285, 0.091712, 0.0926026, 0.0935522, 0.0943832, 0.094641, 0.0951927, 0.0956063, 0.0959775, 0.0963928, 0.0975306}, // 20-40
  {0.0910697, 0.0911139, 0.0912075, 0.0913861, 0.0916697, 0.0920644, 0.0925673, 0.0931713, 0.09386, 0.0946032, 0.0954632, 0.0963865, 0.0971769, 0.0973773, 0.0978488, 0.0982162, 0.0986577, 0.0992582, 0.100602}, // 40-60
{0.0892475, 0.0893081, 0.0894047, 0.0895693, 0.0898244, 0.090182, 0.0906458, 0.091215, 0.0918852, 0.0926401, 0.0934332, 0.0942026, 0.0949065, 0.0955304, 0.0960716, 0.0965321, 0.0970608, 0.0975109, 0.0981706} }; //60-84

 double dRpAu_pt_bkwd_sys[4][19] = {0};

 for(int i=0; i<19; i++)
   { 
     dRpAu_pt_bkwd_sys[i_cent][i] = pAu_sys_frac_S[i_cent][i]*RpAu_pt_bkwd[i_cent][i];
   }

 ///////////////////////////////////////////////// pAu SOUTH ///////////////////////////////////////////////////////

 ///////////////////////////////////////////////// dAu SOUTH///////////////////////////////////////////////////////
  Double_t RdAu_pt_bkwd[4][28] = {
 {0.702,0.760,0.840,0.894,0.954,1.008,1.000,1.058,1.058,1.252,1.240,1.249,1.230,1.088,1.406,1.131,1.244,1.209,1.824,1.508,1.182,1.171,1.848,2.079,0.0,0.0,0.0,0.0},
  {0.706,0.739,0.815,0.925,0.984,0.874,1.021,1.008,1.067,1.169,1.103,1.137,1.160,1.099,1.234,0.957,1.376,1.077,1.401,1.028,1.481,1.188,0.793,0.996,0.0,0.0,0.0,0.0},
  {0.953,0.865,0.995,0.920,0.976,0.929,0.979,1.018,1.015,1.159,1.227,1.036,1.046,1.114,1.152,1.124,1.313,1.427,1.080,1.365,0.985,1.354,1.297,4.130,0.0,0.0,0.0,0.0},
  {0.829,0.823,0.922,0.965,0.947,0.965,0.990,0.888,1.097,1.073,1.047,1.175,1.132,0.908,0.926,0.804,1.277,0.642,1.827,0.700,1.193,3.141,1.122,0.443,0.0,0.0,0.0,0.0} };

  double dRdAu_pt_bkwd_stat[4][28] = {
 {0.121,0.104,0.105,0.076,0.059,0.066,0.061,0.066,0.062,0.072,0.076,0.083,0.095,0.093,0.13,0.124,0.165,0.186,0.314,0.329,0.33,0.522,0.83,1.364,0.0,0.0,0.0,0.0},
  {0.123,0.108,0.113,0.069,0.051,0.059,0.054,0.054,0.06,0.072,0.073,0.084,0.101,0.102,0.131,0.121,0.195,0.19,0.28,0.266,0.496,0.641,0.469,0.836,0.0,0.0,0.0,0.0},
  {0.103,0.104,0.094,0.06,0.055,0.056,0.067,0.06,0.074,0.091,0.086,0.088,0.101,0.114,0.14,0.153,0.212,0.253,0.263,0.356,0.345,0.796,0.671,2.905,0.0,0.0,0.0,0.0},
  {0.14,0.091,0.074,0.068,0.057,0.059,0.058,0.059,0.077,0.084,0.09,0.107,0.122,0.115,0.138,0.136,0.234,0.187,0.401,0.251,0.42,1.737,0.714,0.0,0.0,0.0,0.0,0.0} };

double dAu_frac_sys_S[4][28] = {
 {0.049,0.053,0.058,0.062,0.065,0.069,0.069,0.073,0.073,0.086,0.085,0.086,0.085,0.075,0.097,0.078,0.086,0.084,0.127,0.106,0.082,0.082,0.128,0.146,0.0,0.0,0.0,0.0},
  {0.049,0.042,0.057,0.064,0.068,0.060,0.07,0.069,0.073,0.08,0.076,0.078,0.08,0.076,0.085,0.066,0.095,0.075,0.097,0.072,0.103,0.083,0.055,0.07,0.0,0.0,0.0,0.0},
  {0.066,0.061,0.069,0.063,0.067,0.064,0.067,0.07,0.07,0.08,0.085,0.071,0.072,0.077,0.08,0.078,0.091,0.099,0.075,0.096,0.069,0.094,0.09,0.291,0.0,0.0,0.0,0.0},
  {0.057,0.058,0.064,0.066,0.065,0.066,0.068,0.061,0.075,0.074,0.072,0.081,0.078,0.063,0.064,0.056,0.088,0.044,0.127,0.049,0.083,0.219,0.078,0.031,0.0,0.0,0.0,0.0} }; 

 double dRdAu_pt_bkwd_sys[4][28] = {0};

 for(int i=0; i<24; i++)
   { 
     dRdAu_pt_bkwd_sys[i_cent][i] = dAu_frac_sys_S[i_cent][i]*RdAu_pt_bkwd[i_cent][i];
   }
///////////////////////////////////////////////// dAu ///////////////////////////////////////////////////////

///////////////////////////////////////////////// HeAu ///////////////////////////////////////////////////////
 Double_t RHeAu_pt_bkwd[4][13] = {
   {0.44159, 0.718149, 0.638686, 0.856909, 0.865392, 0.849869, 0.955161, 1.20291, 1.02394, 1.28835, 1.11648, 1.04496, 1.34516},
   {0.76629, 0.941895, 0.817208, 0.87862, 1.0035, 0.92386, 1.0518, 1.07635, 1.09929, 1.17637, 1.40049, 1.1567, 1.21402},
   {0.993558, 0.838601, 0.920383, 1.03002, 1.05933, 1.17557, 1.25093, 1.10716, 1.12614, 0.958332, 1.47215, 1.33667, 1.5816} };
 
 double dRHeAu_pt_bkwd_stat[4][13] = {
 {0.0991923, 0.099972, 0.0740888, 0.0832933, 0.0801708, 0.0773154, 0.0897676, 0.110542, 0.121498, 0.134909, 0.115071, 0.125903, 0.194056},
 {0.18726, 0.135171, 0.110059, 0.108134, 0.0946617, 0.103842, 0.133847, 0.178245, 0.14444, 0.174889, 0.152544, 0.163797, 0.230658},
 {0.224998, 0.128565, 0.130694, 0.112835, 0.103714, 0.118817, 0.132849, 0.149591, 0.193963, 0.155062, 0.175487, 0.188671, 0.278614} };
 
 double HeAu_sys_frac_S[4][13] = {
   {0.0932511, 0.093123, 0.0929943, 0.0928733, 0.0927894, 0.0927814, 0.0928652, 0.0930268, 0.0932505, 0.093521, 0.0939473, 0.0944402, 0.0947945}, 
   {0.0905923, 0.09045, 0.0903044, 0.0901634, 0.0900595, 0.090036, 0.0901178, 0.0903049, 0.0905756, 0.0908863, 0.0913259, 0.0917927, 0.0921147},
   {0.0923577, 0.0922179, 0.09209, 0.091957, 0.0918646, 0.0918068, 0.0918907, 0.092079, 0.0923294, 0.0926421, 0.0930806, 0.0935333, 0.0938813} }; 
 
 double dRHeAu_pt_bkwd_sys[4][13] = {0};
 
 for(int i=0; i<13; i++)
   { 
     dRHeAu_pt_bkwd_sys[i_cent][i] = HeAu_sys_frac_S[i_cent][i]*RHeAu_pt_bkwd[i_cent][i];
   }
 
 ///////////////////////////////////////////////// HeAu ///////////////////////////////////////////////////////
 
 ///////////////////////////////////////////////// pAl ///////////////////////////////////////////////////////
 Double_t RpAl_pt_bkwd[20] = {0.973648, 1.05773, 1.07703, 0.991247, 0.962321, 1.21348, 1.10315, 1.15779, 1.14102, 1.07516, 1.22817, 1.11176, 1.23598, 1.20754, 1.03226, 0.994679, 1.11114, 0.773681, 1.07259, 0.62213};
 double dRpAl_pt_bkwd_stat[20] = {0.117259, 0.100543, 0.0654229, 0.0575966, 0.0487535, 0.0882102, 0.068738, 0.0749383, 0.0979209, 0.0936964, 0.105263, 0.113219, 0.129959, 0.147026, 0.14912, 0.159073, 0.168462, 0.189033, 0.216808, 0.309688};
 double pAl_sys_frac_S[20] = {0.078,0.078,0.078,0.078,0.078,0.078,0.079,0.079,0.081,0.082,0.084,0.084,0.085,0.086,0.087,0.087,0.087,0.088,0.089,0.090};
 double dRpAl_pt_bkwd_sys[20] = {0};
  for(int i=0; i<20; i++)
    {
      dRpAl_pt_bkwd_sys[i] = pAl_sys_frac_S[i]*RpAl_pt_bkwd[i];
    }
 ///////////////////////////////////////////////// pAl ///////////////////////////////////////////////////////

  
 //  TGraphErrors *gRdAu_pt_bkwd_sys = new TGraphErrors(24);     TGraphErrors *gRdAu_pt_bkwd = new TGraphErrors(24);

 //  gRdAu_pt_bkwd_sys->SetMarkerColor(2);                         gRdAu_pt_bkwd->SetMarkerColor(2);
 //  gRdAu_pt_bkwd_sys->SetLineColor(2);                           gRdAu_pt_bkwd->SetLineColor(2);
 //  gRdAu_pt_bkwd_sys->SetFillColor(2);                           gRdAu_pt_bkwd->SetFillColor(2); 
 //  gRdAu_pt_bkwd_sys->SetLineWidth(2);                           gRdAu_pt_bkwd->SetLineWidth(2);
 //  gRdAu_pt_bkwd_sys->SetMarkerStyle(20);                        gRdAu_pt_bkwd->SetMarkerStyle(20);
 //  gRdAu_pt_bkwd_sys->SetMarkerSize(1.5);                        gRdAu_pt_bkwd->SetMarkerSize(1.);
 //  gRdAu_pt_bkwd_sys->SetFillStyle(0);

  
 // TGraphErrors *gRpAu_pt_bkwd_sys = new TGraphErrors(19);     TGraphErrors *gRpAu_pt_bkwd = new TGraphErrors(19);

  
 //  gRpAu_pt_bkwd_sys->SetFillColor(1);                           gRpAu_pt_bkwd->SetFillColor(1);
 //  gRpAu_pt_bkwd_sys->SetLineWidth(2);                           gRpAu_pt_bkwd->SetLineWidth(2);
 //  gRpAu_pt_bkwd_sys->SetMarkerStyle(20);                        gRpAu_pt_bkwd->SetMarkerStyle(20);
 //  gRpAu_pt_bkwd_sys->SetMarkerSize(1.5);                        gRpAu_pt_bkwd->SetMarkerSize(1.);
 //  gRpAu_pt_bkwd_sys->SetFillStyle(0);
  


  TGraphErrors *gRpAu_pt_bkwd_sys = new TGraphErrors(19);     TGraphErrors *gRpAu_pt_bkwd = new TGraphErrors(19);
  
  gRpAu_pt_bkwd_sys->SetMarkerColor(kRed);                         gRpAu_pt_bkwd->SetMarkerColor(kRed);  // 4 is kBlue
  gRpAu_pt_bkwd_sys->SetLineColor(kRed);                           gRpAu_pt_bkwd->SetLineColor(kRed);
  gRpAu_pt_bkwd_sys->SetFillColor(kRed);                           gRpAu_pt_bkwd->SetFillColor(kRed); 
  gRpAu_pt_bkwd_sys->SetLineWidth(2);                           gRpAu_pt_bkwd->SetLineWidth(2);
  gRpAu_pt_bkwd_sys->SetMarkerStyle(20);                        gRpAu_pt_bkwd->SetMarkerStyle(20);
  gRpAu_pt_bkwd_sys->SetMarkerSize(1.5);                        gRpAu_pt_bkwd->SetMarkerSize(1.);
  gRpAu_pt_bkwd_sys->SetFillStyle(0);



  TGraphErrors *gRdAu_pt_bkwd_sys = new TGraphErrors(24);     TGraphErrors *gRdAu_pt_bkwd = new TGraphErrors(24);
  
  gRdAu_pt_bkwd_sys->SetMarkerColor(2);                         gRdAu_pt_bkwd->SetMarkerColor(2);  // 2 is kRed
  gRdAu_pt_bkwd_sys->SetLineColor(2);                           gRdAu_pt_bkwd->SetLineColor(2);
  gRdAu_pt_bkwd_sys->SetFillColor(2);                           gRdAu_pt_bkwd->SetFillColor(2); 
  gRdAu_pt_bkwd_sys->SetLineWidth(2);                           gRdAu_pt_bkwd->SetLineWidth(2);
  gRdAu_pt_bkwd_sys->SetMarkerStyle(20);                        gRdAu_pt_bkwd->SetMarkerStyle(20);
  gRdAu_pt_bkwd_sys->SetMarkerSize(1.5);                        gRdAu_pt_bkwd->SetMarkerSize(1.);
  gRdAu_pt_bkwd_sys->SetFillStyle(0);


  TGraphErrors *gRpAl_pt_bkwd_sys = new TGraphErrors(24);     TGraphErrors *gRpAl_pt_bkwd = new TGraphErrors(24);

  
  gRpAl_pt_bkwd_sys->SetFillColor(1);                           gRpAl_pt_bkwd->SetFillColor(1);
  gRpAl_pt_bkwd_sys->SetLineWidth(2);                           gRpAl_pt_bkwd->SetLineWidth(2);
  gRpAl_pt_bkwd_sys->SetMarkerStyle(20);                        gRpAl_pt_bkwd->SetMarkerStyle(24);
  gRpAl_pt_bkwd_sys->SetMarkerSize(1.5);                        gRpAl_pt_bkwd->SetMarkerSize(1.);
  gRpAl_pt_bkwd_sys->SetFillStyle(0);

  TGraphErrors *gRHeAu_pt_bkwd_sys = new TGraphErrors(13);     TGraphErrors *gRHeAu_pt_bkwd = new TGraphErrors(13);
  
  gRHeAu_pt_bkwd_sys->SetMarkerColor(1);                         gRHeAu_pt_bkwd->SetMarkerColor(1);
  gRHeAu_pt_bkwd_sys->SetLineColor(1);                           gRHeAu_pt_bkwd->SetLineColor(1);
  gRHeAu_pt_bkwd_sys->SetFillColor(1);                           gRHeAu_pt_bkwd->SetFillColor(1); 
  gRHeAu_pt_bkwd_sys->SetLineWidth(2);                           gRHeAu_pt_bkwd->SetLineWidth(2);
  gRHeAu_pt_bkwd_sys->SetMarkerStyle(20);                        gRHeAu_pt_bkwd->SetMarkerStyle(20);
  gRHeAu_pt_bkwd_sys->SetMarkerSize(1.5);                        gRHeAu_pt_bkwd->SetMarkerSize(1.);
  gRHeAu_pt_bkwd_sys->SetFillStyle(0);

  //////////////////////////////////////////////////////////
// ncoll_HeAu,pAu_S_ncoll,HeAu_xlow,HeAu_xhigh,HeAu_ylow,HeAu_yhigh);
TGraphAsymmErrors *Ncoll_HeAu_S_sys = new TGraphAsymmErrors(3,ncoll_HeAu,HeAu_S_ncoll,HeAu_xlow,HeAu_xhigh,HeAu_S_sys_down,HeAu_S_sys_up);    TGraphErrors *Ncoll_HeAu_S = new TGraphErrors(3);
  
  Ncoll_HeAu_S_sys->SetMarkerColor(kBlue);                         Ncoll_HeAu_S->SetMarkerColor(kBlue);
  Ncoll_HeAu_S_sys->SetLineColor(kBlue);                           Ncoll_HeAu_S->SetLineColor(kBlue);
  Ncoll_HeAu_S_sys->SetFillColor(kBlue);                           Ncoll_HeAu_S->SetFillColor(kBlue); 
  Ncoll_HeAu_S_sys->SetLineWidth(2);                           Ncoll_HeAu_S->SetLineWidth(2);
  Ncoll_HeAu_S_sys->SetMarkerStyle(20);                        Ncoll_HeAu_S->SetMarkerStyle(20);
  Ncoll_HeAu_S_sys->SetMarkerSize(1.5);                        Ncoll_HeAu_S->SetMarkerSize(1.);
  Ncoll_HeAu_S_sys->SetFillStyle(0);

TGraphAsymmErrors *Ncoll_pAl_S_sys = new TGraphAsymmErrors(3,ncoll_pAl,pAl_S_ncoll,pAl_xlow,pAl_xhigh,pAl_S_sys_down,pAl_S_sys_up);    TGraphErrors *Ncoll_pAl_S = new TGraphErrors(3);
  
  Ncoll_pAl_S_sys->SetMarkerColor(kBlack);                         Ncoll_pAl_S->SetMarkerColor(kBlack);
  Ncoll_pAl_S_sys->SetLineColor(kBlack);                           Ncoll_pAl_S->SetLineColor(kBlack);
  Ncoll_pAl_S_sys->SetFillColor(kBlack);                           Ncoll_pAl_S->SetFillColor(kBlack); 
  Ncoll_pAl_S_sys->SetLineWidth(2);                           Ncoll_pAl_S->SetLineWidth(2);
  Ncoll_pAl_S_sys->SetMarkerStyle(20);                        Ncoll_pAl_S->SetMarkerStyle(20);
  Ncoll_pAl_S_sys->SetMarkerSize(1.5);                        Ncoll_pAl_S->SetMarkerSize(1.);
  Ncoll_pAl_S_sys->SetFillStyle(0);
  
TGraphAsymmErrors *Ncoll_pAu_S_sys = new TGraphAsymmErrors(7,ncoll_pAu,pAu_S_ncoll,pAu_xlow,pAu_xhigh,pAu_S_sys_down,pAu_S_sys_up);     TGraphErrors *Ncoll_pAu_S = new TGraphErrors(7);
  
  Ncoll_pAu_S_sys->SetMarkerColor(kRed);                         Ncoll_pAu_S->SetMarkerColor(kRed);
  Ncoll_pAu_S_sys->SetLineColor(kRed);                           Ncoll_pAu_S->SetLineColor(kRed);
  Ncoll_pAu_S_sys->SetFillColor(kRed);                           Ncoll_pAu_S->SetFillColor(kRed); 
  Ncoll_pAu_S_sys->SetLineWidth(2);                           Ncoll_pAu_S->SetLineWidth(2);
  Ncoll_pAu_S_sys->SetMarkerStyle(20);                        Ncoll_pAu_S->SetMarkerStyle(20);
  Ncoll_pAu_S_sys->SetMarkerSize(1.5);                        Ncoll_pAu_S->SetMarkerSize(1.);
  Ncoll_pAu_S_sys->SetFillStyle(0);

  ////////////////////////////////////////////////////////////////



for(int i = 0; i < 7; i++)
  {
    Ncoll_pAu_S->SetPoint(i,ncoll_pAu[i],pAu_S_ncoll[i]);  
    Ncoll_pAu_S->SetPointError(i,0,pAu_S_stat[i]); 
    // Ncoll_pAu_S_sys->SetPoint(i,ncoll_pAu[i],pAu_S_ncoll[i]);  
    // Ncoll_pAu_S_sys->SetPointError(i,width,pAu_S_sys_down[i]);
    
    if(i < 3)
      {
	Ncoll_HeAu_S->SetPoint(i,ncoll_HeAu[i],pAu_S_ncoll[i]); 
	Ncoll_HeAu_S->SetPointError(i,0,HeAu_S_stat[i]); 
	Ncoll_pAl_S->SetPoint(i,ncoll_pAl[i],pAl_S_ncoll[i]); 
	Ncoll_pAl_S->SetPointError(i,0,pAl_S_stat[i]); 

	//	Ncoll_HeAu_S_sys->SetPoint(i,ncoll_HeAu[i],HeAu_S_ncoll[i]);  
	//	Ncoll_HeAu_S_sys->SetPointError(i,width,HeAu_S_sys_down[i]);
	//	Ncoll_HeAu_S_sys->SetPointError(i,HeAu_xlow[i],HeAu_xhigh[i],HeAu_ylow[i],HeAu_yhigh[i]);
  
      }
  }



  for(int i=0; i<24;i++)
    {
      width = 0.125;
      
        if(i<24)
	{
	  gRdAu_pt_bkwd->SetPoint(i,pt_dAu[i],RdAu_pt_bkwd[i_cent][i]);
	  gRdAu_pt_bkwd->SetPointError(i,0,dRdAu_pt_bkwd_stat[i_cent][i]);
	  gRdAu_pt_bkwd_sys->SetPoint(i,pt_dAu[i],RdAu_pt_bkwd[i_cent][i]);
	  gRdAu_pt_bkwd_sys->SetPointError(i,width,dRdAu_pt_bkwd_sys[i_cent][i]);
	}
      if(i<19)
	{
 
      gRpAu_pt_bkwd->SetPoint(i,pt_pAu[i],RpAu_pt_bkwd[i_cent][i]);
      gRpAu_pt_bkwd->SetPointError(i,0,dRpAu_pt_bkwd_stat[i_cent][i]);
      gRpAu_pt_bkwd_sys->SetPoint(i,pt_pAu[i],RpAu_pt_bkwd[i_cent][i]);
      gRpAu_pt_bkwd_sys->SetPointError(i,width,dRpAu_pt_bkwd_sys[i_cent][i]);
 	}
      if(i<13)
	{
	 	 
	  gRHeAu_pt_bkwd->SetPoint(i,pt_HeAu[i],RHeAu_pt_bkwd[i_cent][i]);
	  gRHeAu_pt_bkwd->SetPointError(i,0,dRHeAu_pt_bkwd_stat[i_cent][i]);
	  gRHeAu_pt_bkwd_sys->SetPoint(i,pt_HeAu[i],RHeAu_pt_bkwd[i_cent][i]);
	  gRHeAu_pt_bkwd_sys->SetPointError(i,width,dRHeAu_pt_bkwd_sys[i_cent][i]);
	}
      if(i<13)
	{
	  gRpAl_pt_bkwd->SetPoint(i,pt_pAl[i],RpAl_pt_bkwd[i]);
	  gRpAl_pt_bkwd->SetPointError(i,0,dRpAl_pt_bkwd_stat[i]);
	  gRpAl_pt_bkwd_sys->SetPoint(i,pt_pAl[i],RpAl_pt_bkwd[i]);
	  gRpAl_pt_bkwd_sys->SetPointError(i,width,dRpAl_pt_bkwd_sys[i]);
	}
    }
  
  if(draw_pAl) gRpAl_pt_bkwd_sys->Draw("e2same");
  if(draw_pAl) gRpAl_pt_bkwd->Draw("Psame");
  
  if(draw_pAu) gRpAu_pt_bkwd_sys->Draw("e2same");
  if(draw_pAu) gRpAu_pt_bkwd->Draw("Psame");

  if(draw_dAu) gRdAu_pt_bkwd_sys->Draw("e2same");
  if(draw_dAu) gRdAu_pt_bkwd->Draw("Psame");

  if(draw_HeAu) gRHeAu_pt_bkwd_sys->Draw("e2same");
  if(draw_HeAu) gRHeAu_pt_bkwd->Draw("Psame");
  

 if(pt_squared)
   {
     Ncoll_pAu_S->Draw("Psame");
     Ncoll_pAu_S_sys->Draw("e2same");
   }

 if(pt_squared)
   {
     Ncoll_HeAu_S->Draw("Psame");
     Ncoll_HeAu_S_sys->Draw("e2same");
   }
if(pt_squared)
   {
     Ncoll_pAl_S->Draw("Psame");
     Ncoll_pAl_S_sys->Draw("e2same");
   }
 
  
  // pAu
  double err_pAu_C[4] = {11.8,12.0,12.1,14.0};
  // HeAu
 double err_HeAu_C[4] = {12.6,12.5,13.3,0};
 // dAu
 double err_dAu_C[4] = {9.0,8.6,9.1,10.7}; 
 
 double err_C = 0;
 
 ///boxes for global systematic aorund one:

 if(draw_pAu)
   {
     err_C = (err_pAu_C[i_cent])*0.01;
      TBox* box_bkd = new TBox(6.9,1-err_C,6.99,1+err_C); // pAu North Arm Type C error
      box_bkd->SetFillColor(kBlack);
      box_bkd->Draw("same");
   }
      
 if(draw_HeAu)
   {
   err_C = (err_HeAu_C[i_cent])*0.01;
   
   TBox* box_bkd_2 = new TBox(6.8,1-err_C,6.89,1+err_C); // HeAu North Arm Type C error
   box_bkd_2->SetFillColor(kBlue);
   box_bkd_2->Draw("same");
   }

 if(draw_dAu)
   {
     err_C = (err_dAu_C[i_cent])*0.01;
     
     TBox* box_fwd_3 = new TBox(6.8,1-err_C,6.89,1+err_C); // dAu North Arm Type C error
     box_fwd_3->SetFillColor(kRed);
     box_fwd_3->Draw("same");
   }


  
 // if(draw_dAu)
 //   err_C = (err_HeAu_C[i_cent])*0.01;

 // TBox* box_bkd_3 = new TBox(6.9,1-0.1,7,1+0.1); // represents 10% error by x_0 +/- 0.1
 //  box_bkd_3->SetFillColor(kRed);
 //  box_bkd_3->Draw("same");
 

 if(draw_HeAu && draw_NS)
   pt_max = 4.0;

  ///////////////////////////////////////////////////////////////////draw forward rapidity/////////////////////////////////////////////////////////////////////////////////////////////////////
  TCanvas *c1_fwd = new TCanvas(); c1_fwd->SetLeftMargin(20); c1_fwd->cd();
 
  //TH1 *hframe = new TH2F("hframe","",100,0,pt_max,100,0,2.25);
  TH1 *hframe = new TH2F("hframe","",100,0,25,100,1,6);

  hframe->SetDirectory(0);
  hframe->SetStats(0);
  hframe->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  if(pt_squared)
    hframe->GetXaxis()->SetTitle("N_{coll}");
  hframe->GetXaxis()->SetMoreLogLabels();
  hframe->GetXaxis()->SetLabelOffset(0.009);
  hframe->GetXaxis()->SetLabelSize(0.06);
  hframe->GetXaxis()->SetTitleOffset(1.2);
  hframe->GetXaxis()->SetTitleSize(0.06);

  if(draw_pAu && draw_NS)
    hframe->GetYaxis()->SetTitle("R_{p+A} ");  
  if(draw_pAu && draw_dAu)
    hframe->GetYaxis()->SetTitle("R_{p/d+A} ");
  if(draw_HeAu && draw_NS)
    hframe->GetYaxis()->SetTitle("R_{^{3}He+A} ");
  if(draw_HeAu && draw_pAu)
    hframe->GetYaxis()->SetTitle("R_{p/^{3}He+A} ");
  if(draw_HeAu && draw_dAu && draw_pAu)
    hframe->GetYaxis()->SetTitle("R_{p/d/^{3}He+A} ");
  if(pt_squared)
    hframe->GetYaxis()->SetTitle("#LT p_{T}^{2} #GT ");    
 
  hframe->GetYaxis()->SetLabelSize(0.06);
  hframe->GetYaxis()->SetTitleSize(0.07);
  hframe->GetYaxis()->SetTitleOffset(0.8); //0.6
  hframe->GetZaxis()->SetLabelSize(0.05);
  
  hframe->GetYaxis()->SetNdivisions(404);
  hframe->GetXaxis()->SetNdivisions(404);
 
  gPad->SetLeftMargin(0.13); //0.1
  gPad->SetBottomMargin(0.15); //0.15
  hframe->Draw("");
  double width = 0.25; //width of sys error box  

  TLine *one_line = new TLine(0,1,pt_max,1);
  one_line->SetLineStyle(2);
  one_line->Draw(); 


for(int i = 0; i < 3; i++)
  {
    width = 0.5;
    HeAu_xlow[i] = width;
    HeAu_xhigh[i] = width;
    HeAu_ylow[i] = HeAu_N_sys_down[i];
    HeAu_yhigh[i] = HeAu_N_sys_up[i] ;
    cout << HeAu_xlow[i] << "," << HeAu_xhigh[i] << "," << HeAu_ylow[i] << "," << HeAu_yhigh[i] << endl;
  }

for(int i = 0; i < 7; i++)
  {
    width = 0.5;
    pAu_xlow[i] = width;
    pAu_xhigh[i] = width;
    pAu_ylow[i] = pAu_N_sys_down[i];
    pAu_yhigh[i] = pAu_N_sys_up[i];
  }

for(int i = 0; i < 3; i++)
  {
    width = 0.5;
    pAl_xlow[i] = width;
    pAl_xhigh[i] = width;
    pAl_ylow[i] = pAl_N_sys_down[i];
    pAl_yhigh[i] = pAl_N_sys_up[i];
  }



   
  double adj = 1.44;
  double dx = -2;

  // need unique names for North and South legends in order to use them both on the same graph
  TGraphErrors *leg_al_N = new TGraphErrors(1);
  leg_al_N->SetName("Graph");
  leg_al_N->SetTitle("Graph");
  leg_al_N->SetFillColor(kRed);
  leg_al_N->SetLineWidth(2);
  leg_al_N->SetLineColor(kRed);
  leg_al_N->SetMarkerColor(kRed);
  leg_al_N->SetMarkerStyle(20);
  leg_al_N->SetMarkerSize(1.5);

  //south arm, p+Al
  //leg_al_N->SetPoint(0,-1.5-dx,1.5-adj+0.15-1.5-dx,2.0-adj-0.15);
  leg_al_N->SetPoint(0,-1.5-dx,2.0-adj-0.15);
  leg_al_N->SetPointError(0,0,0.04);
  if(draw_pAl) leg_al_N->Draw("psame");



  TLatex lal;
  lal.SetTextColor(kRed);
  // lal.DrawLatex(-1.4-dx,1.475-adj+.15 -1.4-dx,1.975-adj-0.15," p+Al");
 if(draw_pAl) lal.DrawLatex(-1.4-dx,1.975-adj-0.15," p+Al");



  if(pt_squared)
    {

      leg_al_N->SetFillColor(kBlack);
      leg_al_N->SetLineColor(kBlack);
      leg_al_N->SetMarkerColor(kBlack);
      leg_al_N->SetPoint(0,-1.1-dx,3.6-adj);
      lal.SetTextColor(kBlack);
      lal.DrawLatex(-1.0-dx,3.6-adj, "  p+Al");
      leg_al_N->Draw("psame");
    }




  TGraphErrors *leg_au_N = new TGraphErrors(1);
  leg_au_N->SetName("Graph");
  leg_au_N->SetTitle("Graph");
  leg_au_N->SetFillColor(4);
  leg_au_N->SetLineWidth(2);
  leg_au_N->SetMarkerStyle(20);
  leg_au_N->SetMarkerSize(1.5);
  leg_au_N->SetLineColor(kRed);
  leg_au_N->SetMarkerColor(kRed);

 
  
leg_au->SetPoint(0,-1.5-dx,1.75-adj);

if(pt_squared)
  leg_au->SetPoint(0,-1.1-dx,3.15-adj);

  leg_au->SetPointError(0,0,0.04);
   if(draw_pAu || pt_squared) 
     leg_au->Draw("psame");

  TLatex lau;
lau->SetTextColor(kRed);
   if(draw_pAu) 
     lau.DrawLatex(-1.4-dx,1.725-adj," p+Au");
if(pt_squared) 
     lau.DrawLatex(-1.0-dx,3.125-adj,"  p+Au");

   if(draw_pAu && draw_NS) 
     lau.DrawLatex(-1.4-dx,1.725-adj," p+Au, Au-going");


  //central arm data point
  TGraphErrors *gre_N = new TGraphErrors(1);
  gre_N->SetName("Graph");
  gre_N->SetTitle("Graph");
  gre_N->SetFillColor(2);
  gre_N->SetLineWidth(2);
  gre_N->SetMarkerStyle(20);
  gre_N->SetMarkerSize(1.5);
  gre_N->SetLineColor(2);
  gre_N->SetMarkerColor(2);

  gre->SetPoint(0,-1.5-dx,1.5-adj+0.15);

  gre->SetPointError(0,0,0.04);

   if(draw_dAu) 
     gre->Draw("psame");
   TLatex lda;
   
   if(draw_dAu) 
     lda.DrawLatex(-1.4-dx,1.425-adj+.15," d+Au, Phys. Rev. C 87, 034904");
  

  ////legend points
  TGraphErrors *leg_he_N = new TGraphErrors(1);
  leg_he_N->SetName("Graph");
  leg_he_N->SetTitle("Graph");
  leg_he_N->SetFillColor(kBlue);
  leg_he_N->SetLineWidth(2);
  leg_he_N->SetLineColor(kBlue);
  leg_he_N->SetMarkerColor(kBlue);
  leg_he_N->SetMarkerStyle(20);
  leg_he_N->SetMarkerSize(1.5);
  
  
  leg_he_N->SetPoint(0,-1.5-dx,1.25-adj+0.3);
if(pt_squared)
  leg_he_N->SetPoint(0,-1.1-dx,2.35-adj+0.3);

  leg_he_N->SetPointError(0,0,0.04);
  if(draw_HeAu || pt_squared)
    leg_he_N->Draw("psame");

  TLatex lhe;
  lhe.SetTextColor(kBlue);
  if(draw_HeAu)
    lhe.DrawLatex(-1.4-dx,1.225-adj+0.27,"^{3}He+Au");  
 if(pt_squared)
   lhe.DrawLatex(-1.0-dx,2.325-adj+0.27," ^{3}He+Au");  

  if(draw_HeAu && draw_NS)
    lhe.DrawLatex(-1.4-dx,1.225-adj+0.27,"^{3}He+Au, ^{3}He-going");   // South legend

  
  // for South arm extra legend entry on N/S plots - works for any system
  //$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

  TGraphErrors *leg2 = new TGraphErrors(1);
  leg2->SetName("Graph");
  leg2->SetTitle("Graph");
  leg2->SetLineWidth(2);
  leg2->SetMarkerStyle(20);
  leg2->SetMarkerSize(1.5);
  if(draw_pAu && !pt_squared)
    {
      leg2->SetFillColor(kBlue);
      leg2->SetLineColor(kBlue);
      leg2->SetMarkerColor(kBlue);
      leg2->SetPoint(0,-1.5-dx,1.25-adj+0.3);
    }
  if(draw_HeAu)
    {
      leg2->SetFillColor(kBlack);
      leg2->SetLineColor(kBlack);
      leg2->SetMarkerColor(kBlack);
      leg2->SetPoint(0,-1.5-dx,1.75-adj);
    }

 
  leg2->SetPointError(0,0,0.04);
   if(draw_NS) 
     leg2->Draw("psame");

  TLatex latex2;
  if(draw_HeAu && draw_NS) 
    latex2.DrawLatex(-1.5-dx,1.725-adj,"^{3}He+Au, Au-going"); 
  if(draw_pAu && draw_NS) 
   //latex2.DrawLatex(-1.4-dx,1.725-adj," p+Au, Au-going");
    latex2.DrawLatex(-1.33-dx,1.275-adj+0.25,"p+Au, p-going"); // labels are independent of data arrays
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

















  TLatex phnx;  // ********************************************************************************************


  //  phnx.DrawLatex(0.1,1.75,"#splitline{Inclusive J/#\psi #sqrt{s_{NN}} = 200 GeV}{1.2<y<2.2 (p-going)}");
  // // phnx.DrawLatex(0.1,1.75,"#splitline{Inclusive J/#\psi #sqrt{s_{NN}} = 200 GeV}{1.2<y<2.2 (^{3}He-going)}");
  // // phnx.DrawLatex(0.1,1.75,"#splitline{Inclusive J/#\psi #sqrt{s_{NN}} = 200 GeV}{1.2<y<2.2 (p/d-going)}");
  // // phnx.DrawLatex(0.1,1.75,"#splitline{Inclusive J/#\psi #sqrt{s_{NN}} = 200 GeV}{1.2<y<2.2 (p/^{3}He-going)}");
  // // phnx.DrawLatex(0.1,1.75,"#splitline{Inclusive J/#\psi #sqrt{s_{NN}} = 200 GeV}{1.2<y<2.2 (p/d/^{3}He-going)}");
  //  if(i_cent == 0)  
  //    phnx.DrawLatex(0.22,1.49,"0-20%");
  //  if(i_cent == 1)  
  //    phnx.DrawLatex(0.22,1.49,"20-40%");
  //  if(i_cent == 3)  
  //    phnx.DrawLatex(0.22,1.49,"60-84%");
   
  if(!draw_NS && !pt_squared)
    // phnx.DrawLatex(0.1,1.95,"#splitline{Inclusive J/#\psi #sqrt{s_{NN}} = 200 GeV}{2.2<y<1.2 (p-going)}");
    phnx.DrawLatex(0.1,1.95,"#splitline{Inclusive J/#\psi #sqrt{s_{NN}} = 200 GeV}{1.2<y<2.2 (p/^{3}He-going)}");
  // phnx.DrawLatex(0.1,1.95,"#splitline{Inclusive J/#\psi #sqrt{s_{NN}} = 200 GeV}{1.2<y<2.2 (p/d-going)}");
  if(draw_NS)
    phnx.DrawLatex(0.1,1.95,"#splitline{Inclusive J/#\psi #sqrt{s_{NN}} = 200 GeV}{1.2<|y|<2.2}");
  if(i_cent == 0 && !pt_squared)  
    phnx.DrawLatex(0.22,1.65,"0-20%");
  if(i_cent == 1)  
    phnx.DrawLatex(0.22,1.65,"20-40%");
  if(i_cent == 2 && draw_pAu)  
     phnx.DrawLatex(0.22,1.65,"40-60%");
   if(i_cent == 3)  
     phnx.DrawLatex(0.22,1.65,"60-84%");
   if(i_cent == 2 && draw_HeAu)  
     phnx.DrawLatex(0.22,1.65,"40-88%");
   if(pt_squared)
     {
       phnx.DrawLatex(0.22,4.75,"p_{T} < 4 GeV/c");
       phnx.DrawLatex(0.1,5.45,"#splitline{Inclusive J/#\psi #sqrt{s_{NN}} = 200 GeV}{1.2<y<2.2 (p/^{3}He-going)}");
     }

   
   

///////////////////////////////////////////////////////////pAu NORTH/////////////////////////////////////////////////////////////.q


  Double_t RpAu_pt_fwd[4][19] = {
    {0.659532, 0.603942, 0.650376, 0.655697, 0.706699, 0.728709, 0.777059, 0.802861, 0.887932, 0.812456, 0.919754, 0.994269, 0.999384, 1.19766, 1.00704, 1.23359, 1.12067, 1.59003, 1.54726},
    {0.746076, 0.793613, 0.812172, 0.794669, 0.901342, 0.895492, 1.03326, 1.00107, 1.07249, 1.13438, 1.14289, 1.12759, 1.17089, 1.09564, 1.24439, 1.36197, 1.51401, 1.25937, 1.6665},
    {0.977507, 0.98774, 0.88964, 0.98411, 1.00165, 1.06771, 1.21448, 0.879396, 1.16456, 1.06111, 1.16666, 1.26445, 1.34268, 1.17355, 1.63973, 1.35697, 1.4699, 2.01948, 1.74903},
    {1.17933, 1.05958, 1.19497, 1.15981, 0.925399, 1.07338, 1.0803, 1.07241, 1.16506, 1.28145, 1.29186, 1.21447, 1.36607, 1.76937, 0.964448, 1.13698, 1.43487, 1.6908, 1.60613} };
  
  double dRpAu_pt_fwd_stat[4][19] = {
    {0.0775144, 0.0462454, 0.0707686, 0.0483433, 0.0364703, 0.0433088, 0.042967, 0.0493313, 0.0545553, 0.0741399, 0.0796658, 0.0833996, 0.0902868, 0.0991887, 0.111705, 0.145552, 0.118968, 0.190146, 0.1754},
    {0.0936055, 0.0681026, 0.0544179, 0.0635149, 0.0464798, 0.0487708, 0.0583742, 0.0625373, 0.0696164, 0.0792254, 0.0900232, 0.0987973, 0.109788, 0.116517, 0.137596, 0.171353, 0.167095, 0.202783, 0.185827},
    {0.119831, 0.0783717, 0.0745921, 0.0644498, 0.0638417, 0.0694354, 0.0765584, 0.0698989, 0.0833279, 0.0823586, 0.109635, 0.114439, 0.133657, 0.138349, 0.195092, 0.213803, 0.185816, 0.313757, 0.254023},
    {0.152329, 0.0951952, 0.0890805, 0.082801, 0.065564, 0.0814843, 0.0808015, 0.0817716, 0.0995593, 0.112013, 0.1319, 0.132751, 0.166423, 0.194119, 0.161556, 0.192563, 0.218444, 0.320387, 0.276375} };
  
  double pAu_sys_frac_N[4][19] = {
    {0.062695, 0.0624828, 0.0622449, 0.0619746, 0.0617027, 0.0614793, 0.0613346, 0.0612644, 0.0612453, 0.0612552, 0.0613501, 0.0614752, 0.0615454, 0.061406, 0.0614518, 0.0615007, 0.061577, 0.0616538, 0.0617302}, // 0-20
    {0.0628323, 0.0626191, 0.0623866, 0.0621286, 0.061869, 0.0616497, 0.0615004, 0.0614249, 0.0614065, 0.0614192, 0.0615131, 0.0616333, 0.0616986, 0.0615577, 0.0616044, 0.0616548, 0.0617303, 0.0618119, 0.0619101}, //20-40
    {0.0633612, 0.063185, 0.0629784, 0.0627316, 0.0624701, 0.0622416, 0.0620826, 0.0620011, 0.0619814, 0.0619973, 0.0620973, 0.0622238, 0.0622932, 0.0621554, 0.0622019, 0.0622515, 0.0623225, 0.0623878, 0.0624992}, // 40-60
    {0.0614786, 0.0612569, 0.0610165, 0.0607511, 0.0604849, 0.0602597, 0.0601032, 0.0600179, 0.0599902, 0.0599988, 0.0600261, 0.0600638, 0.0601077, 0.060154, 0.0602013, 0.0602504, 0.0603227, 0.0604002, 0.0604811} }; // 60-84
  
  double dRpAu_pt_fwd_sys[4][19] = {0};
  
  for(int i=0; i<19; i++)
    {
      dRpAu_pt_fwd_sys[i_cent][i] = pAu_sys_frac_N[i_cent][i]*RpAu_pt_fwd[i_cent][i];
    }
  
  ///////////////////////////////////////////////////////////pAu NORTH/////////////////////////////////////////////////////////////
  
  ///////////////////////////////////////////////////////////dAu NORTH/////////////////////////////////////////////////////////////
  
  Double_t RdAu_pt_fwd[4][28] =  {
{0.566,0.557,0.557,0.563,0.559,0.594,0.634,0.587,0.698,0.691,0.691,0.713,0.812,0.631,0.708,0.772,0.922,0.834,0.953,0.922,0.735,0.997,0.971,0.989,0.0,0.0,0.0,0.0},
  {0.649,0.735,0.680,0.697,0.661,0.653,0.712,0.701,0.716,0.818,0.831,0.831,0.844,0.728,0.752,0.819,1.191,1.252,1.276,1.206,0.859,0.960,1.111,1.519,0.0,0.0,0.0,0.0},
  {0.897,0.731,0.816,0.778,0.802,0.862,0.916,0.865,0.859,0.854,0.781,0.933,0.907,0.807,0.878,0.868,1.109,0.911,1.082,1.246,1.114,1.417,1.268,0.747,0.0,0.0,0.0,0.0},
  {1.038,1.100,0.961,0.873,0.859,0.800,1.028,0.963,0.864,0.939,0.966,1.146,0.999,0.886,0.897,0.741,0.985,1.228,1.477,0.906,0.913,1.622,1.381,1.527,0.0,0.0,0.0,0.0}};

  double dRdAu_pt_fwd_stat[4][28] = {
  {0.054,0.046,0.034,0.031,0.029,0.029,0.031,0.029,0.034,0.037,0.041,0.047,0.056,0.052,0.064,0.081,0.112,0.124,0.163,0.183,0.192,0.396,0.378,0.739,0.0,0.0,0.0,0.0},
  {0.076,0.066,0.065,0.05,0.042,0.035,0.037,0.037,0.039, 0.047,0.052,0.057,0.065,0.066,0.075,0.095,0.148,0.192,0.223,0.247,0.237,0.356,0.448,1.038,0.0,0.0,0.0,0.0},
  {0.098,0.087,0.093,0.046,0.042,0.046,0.045,0.047,0.051,0.056,0.057,0.072,0.079,0.081,0.096,0.115,0.161,0.167,0.23,0.281,0.343,0.632,0.55,0.0,0.0,0.0,0.0,0.0},
  {0.123,0.089,0.064,0.065,0.05,0.051,0.054,0.058,0.062,0.068,0.076,0.094,0.097,0.097,0.112,0.116,0.169,0.227,0.305,0.257,0.309,0.816,0.628,1.12,0.0,0.0,0.0,0.0}};

 double dAu_frac_sys_N[4][28] = {
   {0.042,0.042,0.042,0.042,0.042,0.044,0.047,0.044,0.052,0.051,0.052,0.053,0.061,0.047,0.053,0.058,0.069,0.062,0.071,0.07,0.055,0.075,0.073,0.075,0.0,0.0,0.0,0.0},
   {0.049,0.056,0.051,0.052,0.049,0.048,0.053,0.052,0.053,0.061,0.062,0.062,0.063,0.054,0.056,0.061,0.089,0.094,0.096,0.091,0.065,0.072,0.083,0.115,0.0,0.0,0.0,0.0},
   {0.067,0.055,0.061,0.058,0.06,0.064,0.068,0.064,0.064,0.064,0.058,0.069,0.068,0.06,0.066,0.065,0.083,0.068,0.081,0.094,0.084,0.107,0.095,0.057,0.0,0.0,0.0,0.0},
   {0.078,0.083,0.072,0.065,0.064,0.059,0.076,0.072,0.064,0.07,0.072,0.085,0.075,0.066,0.067,0.055,0.074,0.092,0.111,0.068,0.069,0.122,0.103,0.116,0.0,0.0,0.0,0.0} };
 
 double dRdAu_pt_fwd_sys[4][28] = {0};
 
 for(int i=0; i<24; i++)
   {
     dRdAu_pt_fwd_sys[i_cent][i] = dAu_frac_sys_N[i_cent][i]*RdAu_pt_fwd[i_cent][i];
   }
 
 ///////////////////////////////////////////////////////////dAu NORTH/////////////////////////////////////////////////////////////
 
 
 ///////////////////////////////////////////////////////////HeAU NORTH/////////////////////////////////////////////////////////////
 
 Double_t RHeAu_pt_fwd[4][13] =  {
   {0.584314, 0.578939, 0.641548, 0.598724, 0.670261, 0.68092, 0.826898, 0.699587, 0.747729, 0.733897, 0.812093, 1.00525, 1.0482},
   {0.798152, 0.995637, 0.919872, 0.624518, 0.882709, 0.843838, 0.827393, 0.987271, 0.892196, 0.914591, 1.18621, 0.807213, 1.12859},
   {0.853577, 0.613516, 1.10445, 0.973137, 0.803304, 1.12166, 1.11103, 1.10708, 1.1764, 0.793703, 1.11439, 1.15059, 1.38833} };
 
 double dRHeAu_pt_fwd_stat[4][13] = {
   {0.119964, 0.0734235, 0.0711619, 0.0572545, 0.0584498, 0.0657212, 0.0754633, 0.0789804, 0.0888746, 0.0911987, 0.0825836, 0.116727, 0.148386},
   {0.186411, 0.124006, 0.101995, 0.0820424, 0.0903205, 0.0880928, 0.091227, 0.111319, 0.120372, 0.140101, 0.123707, 0.135927, 0.197366},
   {0.184017, 0.120346, 0.123892, 0.096477, 0.0873617, 0.101598, 0.116857, 0.125543, 0.143632, 0.190087, 0.132468, 0.166174, 0.233979} };
 
 double HeAu_sys_frac_N[4][13] =  {
   {0.0619366, 0.0619305, 0.0619277, 0.0619295, 0.0619425, 0.0619821, 0.0620612, 0.0621819, 0.0623342, 0.0624992, 0.0627264, 0.0629547, 0.0630944},
   {0.0620875, 0.0620822, 0.0620803, 0.0620824, 0.0620954, 0.0621351, 0.0622141, 0.0623342, 0.0624861, 0.0626511, 0.0628779, 0.0631035, 0.0632423}, 
   {0.0615662, 0.061557, 0.0615525, 0.0615571, 0.0615732, 0.0616118, 0.06169, 0.0618107, 0.0619641, 0.0621316, 0.062362, 0.0625858, 0.0627283} };
 
 double dRHeAu_pt_fwd_sys[4][13] = {0};
 
 for(int i=0; i<13; i++)
   {
     dRHeAu_pt_fwd_sys[i_cent][i] = HeAu_sys_frac_N[i_cent][i]*RHeAu_pt_fwd[i_cent][i];
   }
 
 ///////////////////////////////////////////////////////////HeAU NORTH/////////////////////////////////////////////////////////////
 
///////////////////////////////////////////////////////////pAl NORTH/////////////////////////////////////////////////////////////
  Double_t RpAl_pt_fwd[20] =  {0.746038, 0.987155, 1.00522, 0.948295, 0.924622, 1.04565, 1.00678, 1.03543, 1.09356, 1.04505, 1.08603, 1.13306, 1.22892, 1.14518, 1.25919, 1.06012, 1.3241, 1.2702, 1.36065, 1.16492};
  double dRpAl_pt_fwd_stat[20] = {0.069976, 0.0738122, 0.0488019, 0.0420511, 0.0512258, 0.0450953, 0.047429, 0.0513849, 0.0762434, 0.0707596, 0.0817015, 0.083544, 0.0935913, 0.0957935, 0.119251, 0.239884, 0.131049, 0.171131, 0.163157, 0.380679};
  double pAl_sys_frac_N[20] = {0.076,0.076,0.076,0.077,0.077,0.077,0.077,0.077,0.077,0.077,0.078,0.078,0.078,0.078,0.079,0.079,0.079,0.079,0.079,0.079};
  double dRpAl_pt_fwd_sys[20];
  for(int i=0; i<20; i++){ dRpAl_pt_fwd_sys[i] = pAl_sys_frac_N[i]*RpAl_pt_fwd[i];}
///////////////////////////////////////////////////////////pAl NORTH/////////////////////////////////////////////////////////////

  
  TGraphErrors *gRpAl_pt_fwd_sys = new TGraphErrors(20);     TGraphErrors *gRpAl_pt_fwd = new TGraphErrors(20);

  gRpAl_pt_fwd_sys->SetMarkerColor(2);                         gRpAl_pt_fwd->SetMarkerColor(2);
  gRpAl_pt_fwd_sys->SetLineColor(2);                           gRpAl_pt_fwd->SetLineColor(2);
  gRpAl_pt_fwd_sys->SetFillColor(2);                           gRpAl_pt_fwd->SetFillColor(2); 
  gRpAl_pt_fwd_sys->SetLineWidth(2);                           gRpAl_pt_fwd->SetLineWidth(2);
  gRpAl_pt_fwd_sys->SetMarkerStyle(20);                        gRpAl_pt_fwd->SetMarkerStyle(20);
  gRpAl_pt_fwd_sys->SetMarkerSize(1.5);                        gRpAl_pt_fwd->SetMarkerSize(1.);
  gRpAl_pt_fwd_sys->SetFillStyle(0);

  
// TGraphErrors *gRpAu_pt_fwd_sys = new TGraphErrors(19);     TGraphErrors *gRpAu_pt_fwd = new TGraphErrors(19);

  
//   gRpAu_pt_fwd_sys->SetFillColor(1);                           gRpAu_pt_fwd->SetFillColor(1);
//   gRpAu_pt_fwd_sys->SetLineWidth(2);                           gRpAu_pt_fwd->SetLineWidth(2);
//   gRpAu_pt_fwd_sys->SetMarkerStyle(20);                        gRpAu_pt_fwd->SetMarkerStyle(20);
//   gRpAu_pt_fwd_sys->SetMarkerSize(1.5);                        gRpAu_pt_fwd->SetMarkerSize(1.);
//   gRpAu_pt_fwd_sys->SetFillStyle(0);
 

//   TGraphErrors *gRdAu_pt_fwd_sys = new TGraphErrors(24);     TGraphErrors *gRdAu_pt_fwd = new TGraphErrors(24);

  
//   gRdAu_pt_fwd_sys->SetFillColor(1);                           gRdAu_pt_fwd->SetFillColor(1);
//   gRdAu_pt_fwd_sys->SetLineWidth(2);                           gRdAu_pt_fwd->SetLineWidth(2);
//   gRdAu_pt_fwd_sys->SetMarkerStyle(20);                        gRdAu_pt_fwd->SetMarkerStyle(24);
//   gRdAu_pt_fwd_sys->SetMarkerSize(1.5);                        gRdAu_pt_fwd->SetMarkerSize(1.);
//   gRdAu_pt_fwd_sys->SetFillStyle(0);

 



  TGraphErrors *gRpAu_pt_fwd_sys = new TGraphErrors(19);     TGraphErrors *gRpAu_pt_fwd = new TGraphErrors(19);
  
  gRpAu_pt_fwd_sys->SetMarkerColor(kBlue);                         gRpAu_pt_fwd->SetMarkerColor(kBlue);  // 4 is kBlue
  gRpAu_pt_fwd_sys->SetLineColor(kBlue);                           gRpAu_pt_fwd->SetLineColor(kBlue);
  gRpAu_pt_fwd_sys->SetFillColor(kBlue);                           gRpAu_pt_fwd->SetFillColor(kBlue); 
  gRpAu_pt_fwd_sys->SetLineWidth(2);                           gRpAu_pt_fwd->SetLineWidth(2);
  gRpAu_pt_fwd_sys->SetMarkerStyle(20);                        gRpAu_pt_fwd->SetMarkerStyle(20);
  gRpAu_pt_fwd_sys->SetMarkerSize(1.5);                        gRpAu_pt_fwd->SetMarkerSize(1.);
  gRpAu_pt_fwd_sys->SetFillStyle(0);



  TGraphErrors *gRdAu_pt_fwd_sys = new TGraphErrors(24);     TGraphErrors *gRdAu_pt_fwd = new TGraphErrors(24);
  
  gRdAu_pt_fwd_sys->SetMarkerColor(2);                         gRdAu_pt_fwd->SetMarkerColor(2);  // 2 is kRed
  gRdAu_pt_fwd_sys->SetLineColor(2);                           gRdAu_pt_fwd->SetLineColor(2);
  gRdAu_pt_fwd_sys->SetFillColor(2);                           gRdAu_pt_fwd->SetFillColor(2); 
  gRdAu_pt_fwd_sys->SetLineWidth(2);                           gRdAu_pt_fwd->SetLineWidth(2);
  gRdAu_pt_fwd_sys->SetMarkerStyle(20);                        gRdAu_pt_fwd->SetMarkerStyle(20);
  gRdAu_pt_fwd_sys->SetMarkerSize(1.5);                        gRdAu_pt_fwd->SetMarkerSize(1.);
  gRdAu_pt_fwd_sys->SetFillStyle(0);

  TGraphErrors *gRHeAu_pt_fwd_sys = new TGraphErrors(13);     TGraphErrors *gRHeAu_pt_fwd = new TGraphErrors(13);
  
  gRHeAu_pt_fwd_sys->SetMarkerColor(4);                         gRHeAu_pt_fwd->SetMarkerColor(4);
  gRHeAu_pt_fwd_sys->SetLineColor(4);                           gRHeAu_pt_fwd->SetLineColor(4);
  gRHeAu_pt_fwd_sys->SetFillColor(4);                           gRHeAu_pt_fwd->SetFillColor(4); 
  gRHeAu_pt_fwd_sys->SetLineWidth(2);                           gRHeAu_pt_fwd->SetLineWidth(2);
  gRHeAu_pt_fwd_sys->SetMarkerStyle(20);                        gRHeAu_pt_fwd->SetMarkerStyle(20);
  gRHeAu_pt_fwd_sys->SetMarkerSize(1.5);                        gRHeAu_pt_fwd->SetMarkerSize(1.);
  gRHeAu_pt_fwd_sys->SetFillStyle(0);

////////////////////////////////////////////////////////////////

 TGraphAsymmErrors *Ncoll_HeAu_N_sys = new TGraphAsymmErrors(3,ncoll_HeAu,HeAu_N_ncoll,HeAu_xlow,HeAu_xhigh,HeAu_N_sys_down,HeAu_N_sys_up);     TGraphErrors *Ncoll_HeAu_N = new TGraphErrors(3);
  
  Ncoll_HeAu_N_sys->SetMarkerColor(kBlue);                         Ncoll_HeAu_N->SetMarkerColor(kBlue);
  Ncoll_HeAu_N_sys->SetLineColor(kBlue);                           Ncoll_HeAu_N->SetLineColor(kBlue);
  Ncoll_HeAu_N_sys->SetFillColor(kBlue);                           Ncoll_HeAu_N->SetFillColor(kBlue); 
  Ncoll_HeAu_N_sys->SetLineWidth(2);                           Ncoll_HeAu_N->SetLineWidth(2);
  Ncoll_HeAu_N_sys->SetMarkerStyle(20);                        Ncoll_HeAu_N->SetMarkerStyle(20);
  Ncoll_HeAu_N_sys->SetMarkerSize(1.5);                        Ncoll_HeAu_N->SetMarkerSize(1.);
  Ncoll_HeAu_N_sys->SetFillStyle(0);

TGraphAsymmErrors *Ncoll_pAl_N_sys = new TGraphAsymmErrors(3,ncoll_pAl,pAl_N_ncoll,pAl_xlow,pAl_xhigh,pAl_N_sys_down,pAl_N_sys_up);     TGraphErrors *Ncoll_pAl_N = new TGraphErrors(3);
  
  Ncoll_pAl_N_sys->SetMarkerColor(kBlack);                         Ncoll_pAl_N->SetMarkerColor(kBlack);
  Ncoll_pAl_N_sys->SetLineColor(kBlack);                           Ncoll_pAl_N->SetLineColor(kBlack);
  Ncoll_pAl_N_sys->SetFillColor(kBlack);                           Ncoll_pAl_N->SetFillColor(kBlack); 
  Ncoll_pAl_N_sys->SetLineWidth(2);                           Ncoll_pAl_N->SetLineWidth(2);
  Ncoll_pAl_N_sys->SetMarkerStyle(20);                        Ncoll_pAl_N->SetMarkerStyle(20);
  Ncoll_pAl_N_sys->SetMarkerSize(1.5);                        Ncoll_pAl_N->SetMarkerSize(1.);
  Ncoll_pAl_N_sys->SetFillStyle(0);
  
TGraphAsymmErrors *Ncoll_pAu_N_sys = new TGraphAsymmErrors(7,ncoll_pAu,pAu_N_ncoll,pAu_xlow,pAu_xhigh,pAu_N_sys_down,pAu_N_sys_up);     TGraphErrors *Ncoll_pAu_N = new TGraphErrors(7);
  
  Ncoll_pAu_N_sys->SetMarkerColor(kRed);                         Ncoll_pAu_N->SetMarkerColor(kRed);
  Ncoll_pAu_N_sys->SetLineColor(kRed);                           Ncoll_pAu_N->SetLineColor(kRed);
  Ncoll_pAu_N_sys->SetFillColor(kRed);                           Ncoll_pAu_N->SetFillColor(kRed); 
  Ncoll_pAu_N_sys->SetLineWidth(2);                           Ncoll_pAu_N->SetLineWidth(2);
  Ncoll_pAu_N_sys->SetMarkerStyle(20);                        Ncoll_pAu_N->SetMarkerStyle(20);
  Ncoll_pAu_N_sys->SetMarkerSize(1.5);                        Ncoll_pAu_N->SetMarkerSize(1.);
  Ncoll_pAu_N_sys->SetFillStyle(0);

  ////////////////////////////////////////////////////////////////


  for(int i = 0; i < 7; i++)
    {
           
	// symmetric tgraph
      Ncoll_pAu_N->SetPoint(i,ncoll_pAu[i],pAu_N_ncoll[i]);  // this appears correct.
      Ncoll_pAu_N->SetPointError(i,0,pAu_N_stat[i]); // TGraph with symemtric Type A errors
      // Ncoll_pAu_N_sys->SetPoint(i,ncoll_pAu[i],pAu_N_ncoll[i]);  
      // Ncoll_pAu_N_sys->SetPointError(i,width,pAu_N_sys_down[i]);
  

      if(i < 3)
	{
	  Ncoll_HeAu_N->SetPoint(i,ncoll_HeAu[i],HeAu_N_ncoll[i]); 
	  Ncoll_HeAu_N->SetPointError(i,0,HeAu_N_stat[i]); 
	  Ncoll_pAl_N->SetPoint(i,ncoll_pAl[i],pAl_N_ncoll[i]); 
	  Ncoll_pAl_N->SetPointError(i,0,pAl_N_stat[i]); 
	
	  // Ncoll_HeAu_N_sys->SetPoint(i,ncoll_HeAu[i],HeAu_N_ncoll[i]);  
	  // Ncoll_HeAu_N_sys->SetPointError(i,width,HeAu_N_sys_down[i]);
	  
	}
      // need this section of code but wait to add boxes

      // // asymmetric tgraph
      // Ncoll_pAu_N_sys->SetPoint(i,ncoll_pAu[i],pAu_N_ncoll[i]); // TGraph with Asymmetric Type B errors (he said only Type B is asymmetric)
      // Ncoll_pAu_N_sys->SetPointError(i,width, pAu_N_stat[i] + pAu_N_sys_up[i] );
      // Ncoll_HeAu_N_sys->SetPoint(i,ncoll_HeAu[i],HeAu_N_ncoll[i]);
      // Ncoll_HeAu_N_sys->SetPointError(i,width,HeAu_N_stat[i] + HeAu_N_sys_up[i]);

     
    }



for(int i=0; i<24;i++)
  {
    width = 0.125;
        
    if(i<24)
      {
	gRdAu_pt_fwd->SetPoint(i,pt_dAu[i],RdAu_pt_fwd[i_cent][i]);
	gRdAu_pt_fwd->SetPointError(i,0,dRdAu_pt_fwd_stat[i_cent][i]);
	gRdAu_pt_fwd_sys->SetPoint(i,pt_dAu[i],RdAu_pt_fwd[i_cent][i]);
	gRdAu_pt_fwd_sys->SetPointError(i,width,dRdAu_pt_fwd_sys[i_cent][i]);
      }
    if(i<19)
      {
	gRpAu_pt_fwd->SetPoint(i,pt_pAu[i],RpAu_pt_fwd[i_cent][i]);
	gRpAu_pt_fwd->SetPointError(i,0,dRpAu_pt_fwd_stat[i_cent][i]);
	gRpAu_pt_fwd_sys->SetPoint(i,pt_pAu[i],RpAu_pt_fwd[i_cent][i]);
	gRpAu_pt_fwd_sys->SetPointError(i,width,dRpAu_pt_fwd_sys[i_cent][i]);
      }
    if(i<13)
      {
	gRHeAu_pt_fwd->SetPoint(i,pt_HeAu[i],RHeAu_pt_fwd[i_cent][i]);
	gRHeAu_pt_fwd->SetPointError(i,0,dRHeAu_pt_fwd_stat[i_cent][i]);
	gRHeAu_pt_fwd_sys->SetPoint(i,pt_HeAu[i],RHeAu_pt_fwd[i_cent][i]);
	gRHeAu_pt_fwd_sys->SetPointError(i,width,dRHeAu_pt_fwd_sys[i_cent][i]);
      }
    if(i<20)
      {
	gRpAl_pt_fwd->SetPoint(i,pt_pAl[i],RpAl_pt_fwd[i]);
	gRpAl_pt_fwd->SetPointError(i,0,dRpAl_pt_fwd_stat[i]);
	gRpAl_pt_fwd_sys->SetPoint(i,pt_pAl[i],RpAl_pt_fwd[i]);
	gRpAl_pt_fwd_sys->SetPointError(i,width,dRpAl_pt_fwd_sys[i]);
      }
  }



if(draw_pAl)  gRpAl_pt_fwd_sys->Draw("e2same");
if(draw_pAl)  gRpAl_pt_fwd->Draw("Psame");

if(draw_pAu)  gRpAu_pt_fwd_sys->Draw("e2same");
if(draw_pAu)  gRpAu_pt_fwd->Draw("Psame");

if(draw_dAu)  gRdAu_pt_fwd_sys->Draw("e2same");
if(draw_dAu)  gRdAu_pt_fwd->Draw("Psame");

if(draw_HeAu)  gRHeAu_pt_fwd_sys->Draw("e2same");
if(draw_HeAu)  gRHeAu_pt_fwd->Draw("Psame");

if(draw_HeAu && draw_NS) gRHeAu_pt_bkwd_sys->Draw("e2same");
if(draw_HeAu && draw_NS) gRHeAu_pt_bkwd->Draw("Psame");

if(pt_squared)
  {
    Ncoll_pAu_N->Draw("Psame");
    Ncoll_pAu_N_sys->Draw("e2same");
  }

if(pt_squared)
  {
    Ncoll_HeAu_N->Draw("Psame");
    Ncoll_HeAu_N_sys->Draw("e2same");
  }
if(pt_squared)
  {
    Ncoll_pAl_N->Draw("Psame");
    Ncoll_pAl_N_sys->Draw("e2same");
  }
 
   
 
 // can overwrite earlier assignments of color for the South arm data points here
  if(draw_pAu && draw_NS)  
    { 
      gRpAu_pt_bkwd->SetMarkerColor(kRed);
      gRpAu_pt_bkwd_sys->SetLineColor(kRed);
      gRpAu_pt_bkwd->Draw("Psame");
      gRpAu_pt_bkwd_sys->Draw("e2same");
    }
  

 if(draw_HeAu && draw_NS) 
   {
     gRHeAu_pt_bkwd->SetMarkerColor(kBlack);
     gRHeAu_pt_bkwd_sys->SetLineColor(kBlack);
     gRHeAu_pt_bkwd->Draw("Psame");
     gRHeAu_pt_bkwd_sys->Draw("e2same");
    }

 
//pAu
 double err_pAu_c[8] = {11.8,12.0,12.1,14.0};
 //HeAu
 double err_HeAu_c[4] = {12.6,12.5,13.3,0};
 // for dAu
 double err_dAu_c[4] = {9.0,8.5,9.1,10.6}; 

 double err_c = 0;

 if(draw_pAu)
   {
   err_c = (err_pAu_c[i_cent] )*0.01; 
   
   TBox* box_fwd = new TBox(6.9,1-err_c,6.99,1+err_c); // pAu South Arm Type C error
   box_fwd->SetFillColor(kBlue);
   box_fwd->Draw("same");
   }

 if(draw_HeAu && !draw_NS)
   {
     err_C = (err_HeAu_c[i_cent])*0.01;
     
     TBox* box_fwd_2 = new TBox(3.9,1-err_C,3.99,1+err_C); // HeAu South Arm Type C error 0-7 GeV/c
     box_fwd_2->SetFillColor(kBlue);
     box_fwd_2->Draw("same");
   }

 if(draw_HeAu && draw_NS)
   {
     err_C = (err_HeAu_c[i_cent])*0.01;
     TBox* box_fwd_3 = new TBox(3.9,1-err_C,3.99,1+err_C); // HeAu South Arm Type C error 0-4 GeV/c
     box_fwd_3->SetFillColor(kBlack);
     box_fwd_3->Draw("same");
   }

 if(draw_dAu)
  {
     err_C = (err_dAu_c[i_cent])*0.01;
     TBox* box_fwd_4 = new TBox(6.8,1-err_C,6.89,1+err_C); // HeAu South Arm Type C error 0-4 GeV/c
     box_fwd_4->SetFillColor(kRed);
     box_fwd_4->Draw("same");
   }

  
  // ///boxes for global systematic aorund one:

// for(int i = 0; i < 3; i++)
//   {
//     TBox* box_HeAu = new TBox(HeAu_xlow[i],HeAu_xhigh[i],HeAu_ylow[i],HeAu_yhigh[i]);
//     box_HeAu->SetFillColor(0);
//     box_HeAu->SetLineColor(kBlue);
//     box_HeAu->Draw("same");
//   }

//   TBox* box_mid = new TBox(0.1,1-0.16,0.05,1+0.16);
//   box_mid->SetFillStyle(0); box_mid->SetLineColor(kBlack);
//   box_mid->Draw("same");
 
}

