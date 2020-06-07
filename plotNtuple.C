// ROOT macro file for plotting example B4 ntuple
// 
// Can be run from ROOT session:
// root[0] .x plotNtuple.C

{
  gROOT->Reset();
  gROOT->SetStyle("Plain");
  
  // Draw histos filled by Geant4 simulation 
  //   

  // Open file filled by Geant4 simulation 
  TFile f("B4.root");

  // Create a canvas and divide it into 2x2 pads
  TCanvas* c1 = new TCanvas("c1", "", 30, 20, 1500, 1000);
  c1->Divide(3,2);
  
  // Get ntuple
  TNtuple* ntuple = (TNtuple*)f.Get("B4");

  // Draw Eabs histogram in the pad 1
  c1->cd(1);
  B4->Draw("Eabs >> test1(2048,0.1,25)");
  
  // Draw Labs histogram in the pad 2
  c1->cd(4);
  B4->Draw("Labs >> test2(2048,0.1,25)");
  
  // Draw Egap histogram in the pad 3
  // with logaritmic scale for y  ?? how to do this?
  c1->cd(2);
  //gPad->SetLogy(1);
  B4->Draw("Egap >> test3(2048,0.1,50)");
  
  // Draw Lgap histogram in the pad 4
  // with logaritmic scale for y  ?? how to do this?
  c1->cd(5);
  //gPad->SetLogy(1);
  B4->Draw("Lgap >> test4(2048,0.1,350)");


  c1->cd(3);
  B4->Draw("EVETO >> test5(2048,0.1,20)");
  

  c1->cd(6);
  B4->Draw("LVETO >> test6(2048,0.1,20)");
}  
