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

  char date[100], time[100], ampm[10];
  char time_stamp[300];
  int event, channel, ndata; 
  int data[600];

  TTree* tree = new TTree("tree", "tree");
  tree->Branch("time_stamp", &time_stamp, "time_stamp/C");
  tree->Branch("event", &event, "event/I");
  //tree->Branch("trig_number", &trig_number, "trig_number/I");
  //tree->Branch("board", &board, "board/I");
  tree->Branch("channel", &channel, "channel/I");
  tree->Branch("ndata", &ndata, "ndata/I");
  tree->Branch("data", data, "data[ndata]/I");

  std::string line;
  
  if (infile.is_open())
  {
    event=0;
    while (getline(infile,line))
    {
      event++;
      std::stringstream sline(line);
      sline >> date >> time >> ampm >> channel;
      sprintf(time_stamp, "%s %s %s", date, time, ampm);
      ndata=0;
      int dd;
      while ( sline >> dd ) 
      {
        data[ndata] = dd;
        ndata++;
      }

      tree->Fill();

    } 
    infile.close();
  }

  tree->Write();
  fout->Close();
 
}
