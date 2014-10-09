void RunAnalyzer() {

  gROOT->LoadMacro("EventTree.C");

  EventTree t;

  t.Loop();

  TFile * fIn = new TFile("Analysis.root", "READ");
  TH1D * h = (TH1D*)fIn->Get("numEle");
  h->Draw();


}
