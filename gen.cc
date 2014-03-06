#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <iomanip>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h> 
#include <cmath>

// PADE data to ROOT Tree converter

// author: Hengne Li @ UVa
//  date:  28 Feb. 2014


int main(int argc, char* argv[])
{
 
  if (argc<3)
  {
    std::cout << argv[0] << " <file_out.txt> <N>"
              << std::endl;
    return 0;
  }


  std::ofstream myfile_out(argv[1]);
  int N=atoi(argv[2]); 
  std::cout << N << std::endl;
 
  time_t timer;
  srand(time(&timer));

  int trig_number = 10;
  int time_stamp = 0;

  for (int i=0; i<N; i++)
  {

    time_stamp = time_stamp+500;
    trig_number = trig_number+1;
    for (int iboard=0; iboard<2; iboard++)
    {
      for (int ichan=0; ichan<8; ichan++)
      {
        myfile_out << time_stamp << " " << trig_number << " "
              << iboard << " " << ichan << " ";
        for (int ix=0; ix<20; ix++)
        {
          double norm = rand()%100;
          double x = 13.33333*(ix+0.1);
          double data = norm*x*exp(1.0-0.03*x);
          myfile_out << data << " ";
        }
        myfile_out << std::endl;
      }
    } 
  
  //time_stamp trig_number board_number chan_num data0 data1 ... data511

  }

  myfile_out.close();
  
  //TF1* fc = new TF1("fc", "[0]*(x)*exp(1-[1]*(x))", 0, 200);
  //fc->SetParameters(1,0.05); 

  //fc->Draw();
}
