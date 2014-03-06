#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "TTree.h"
#include "TFile.h"


// PADE data to ROOT Tree converter

// author: Hengne Li @ UVa 
//  date:  28 Feb. 2014
 

int main(int argc, char* argv[])
{
 
  if (argc<3)
  {
    std::cout << argv[0] << " <data_file.txt> <rootfile_out.root>"
              << std::endl;
    return 0;
  }


  std::ifstream infile(argv[1]);
  TFile* fout = new TFile(argv[2], "recreate");

  int time_stamp, trig_number, board, channel, ndata;
  double data[600];

  TTree* tree = new TTree("tree", "tree");
  tree->Branch("time_stamp", &time_stamp, "time_stamp/I");
  tree->Branch("trig_number", &trig_number, "trig_number/I");
  tree->Branch("board", &board, "board/I");
  tree->Branch("channel", &channel, "channle/I");
  tree->Branch("ndata", &ndata, "ndata/I");
  tree->Branch("data", data, "data[ndata]/D");

  std::string line;

  if (infile.is_open())
  {
    while (getline(infile,line))
    {
      std::stringstream sline(line);
      sline >> time_stamp >> trig_number >> board >> channel;
      ndata=13;
      for (int idata=0; idata<ndata; idata++)
      {  
        sline >> data[idata];
      }

      tree->Fill();

    } 
    infile.close();
  }

  tree->Write();
  fout->Close();
 
}
