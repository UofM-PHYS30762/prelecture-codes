// PL3/cstringstream.cpp
// Demonstration  a string stream in the "C" syntax
// Source: Prof. Niels Walet's code repository
// Last updated: Charanjit Kaur, 07/02/24
#include<iostream>
#include<cstring>
#include<cstdio>
int main() 
{
  char output_filename[100];
  int file_index{123};
  sprintf(output_filename,"FileData.%d",file_index);
  std::cout<<output_filename<<std::endl;
  return 0;
}
