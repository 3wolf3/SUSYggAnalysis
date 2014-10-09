#include <TString.h>
#include <TFile.h>
#include <TTree.h>
#include <TCanvas.h>
#include <vector>
#include <TH1F.h>
#include <TH2F.h>
#include <TMath.h>
#include <TString.h>
#include <iostream>
#include "EventTree.h"

void SUSYggAnalyzer(TString fdat){

	gROOT->Reset();

	//TFile *f = TFile::Open("../../../CSA14MCSamples/job_spring14_gjet_pt20to40_20bx25.root")
	TFile *f = new TFile(fdat);
	TTree * tree = (TTree*)f->Get("ggNtuplizer");
	
	gROOT->LoadMacro("EventTree.C");
	
	EventTree * t = new EventTree(tree);

	TH1F *numEle = new TH1F("numEle", "Number of Electrons", 5,0,10);

	for( Int_t i = 0; i < 100000; i++){
		t->GetEntry(i);
		numEle->Fill(t.nEle);
		//cout << t.nEle << endl;		
	}


	TCanvas *c1=new TCanvas("c1","recoAnayzer",1600,800);
	numEle->Draw();

}


