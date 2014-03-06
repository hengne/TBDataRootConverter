#!/bin/sh

g++ -o gen.exe gen.cc
g++ -o convert.exe convert.cc `root-config --cflags` `root-config --libs`

