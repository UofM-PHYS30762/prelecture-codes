// PL3/cstringsprintf.cpp
// Demonstration  a string stream in the "C" syntax
// Niels Walet, last updated 04/12/2019
#include<iostream>
#include<stdio.h>
#include<cstring>
using namespace std;
int main() 
{
  char output_filename[100];
  int file_index{123};
  sprintf(output_filename,"FileData.%d",file_index);
  std::cout<<output_filename<<std::endl;
  return 0;
}
