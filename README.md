TBDataRootConverter
===================


  Instructions about how to use:

  You can find the following 3 files in the attachments:

    compile.sh
    gen.cc
    convert.cc

   You must have a ROOT installation somewhere in your system, and you have the ROOT environment setup already before continue here.

  Now, run the following line to compile it:

     source compile.sh
 
   You will then have another two executable created:

     gen.exe
     convert.exe

   Generate the fake data:

     ./gen.exe <fake data file name>  <number of events>

   for example:

     ./gen.exe  fakedata.dat 1000

   This generate a fake data file named "fakedata.dat" contains 1000 evnets.


   Convert to ROOT file:

     ./convert.exe  <input data file> <output root file>

e.g.

     ./convert.exe fakedata.dat  fakedata.root

Now you will have the "fakedata.root" converted from the "fakedata.dat" file.

Then, just run ROOT as you want to look at this fakedata.root file.

E.g.

     root -l fakedata.root


you will see something like:

     #########
     Welcome to the ROOT tutorials
     Type ".x demos.C" to get a toolbar from which to execute the demos
     Type ".x demoshelp.C" to see the help window
        
     ==> Many tutorials use the file hsimple.root produced by hsimple.C 
     ==> It is recommended to execute hsimple.C before any other script
       
     root [0]
     Attaching file fakedata.root as _file0...
     
     root [1] tree->Show(0)
     
     ======> EVENT:0
     
      time_stamp      = 500
      trig_number     = 11
      board           = 0
      channle         = 0
      ndata           = 13
      data            = 132.234,
                       402.126, 1820.59, 668.576, 753.425, 43.1818,
                       318.209, 40.7478, 102.098, 51.2425, 43.146,
                       16.9679, 8.25775
     root [2]
      
     ##################
