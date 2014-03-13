TBDataRootConverter
===================
 Hengne Li @ UVa

  Instructions about how to use:

  You can find the following 3 files:

    compile.sh
    convert1.cc

   You must have a ROOT installation somewhere in your system, and you have the ROOT environment setup already before continue here.

  Now, run the following line to compile it:

     source compile.sh
 
   You will then have another two executable created:

     convert1.exe

   Convert to ROOT file:

     ./convert1.exe  <input data file> <output root file>

e.g.

     ./convert1.exe data.txt  data.root


Then, just run ROOT as you want to look at this fakedata.root file.

E.g.

     root -l data.root


 Data structure inside the Tree:

   root [3] tree->Show(1)
   ======> EVENT:1
    time_stamp      = 3/1/2014 5:32:55 PM
    event           = 2
    channel         = 17
    ndata           = 512
    data            = 98,
                    100, 101, 99, 99, 100, 103, 101, 101, 98, 100,
                  99, 101, 100, 101, 100, 100, 101, 101, 99

   
Some data files are available on AFS:

/afs/cern.ch/work/h/heli/public/TestBeam/

03032014_1.dat
03052014_2.dat

One can use to make a test. I contains some pulse shapes as the following file in this directory:

pulse.pdf

Also, you can find another .pdf file which is the PADE DAQ insturctions:

pCT_PADEinstructions.pdf









   
