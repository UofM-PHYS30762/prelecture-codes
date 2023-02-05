// PL3/cppstringstream.cpp
// Demonstration a string stream in the modern syntax
// Niels Walet, last updated 04/12/2019
#include<iostream>
#include<string>
#include<sstream> 
using namespace std;
int main() 
{
  int file_index{123};
  ostringstream output_stream;
  output_stream << "FileData." << file_index;
  string output_filename{output_stream.str()};
  std::cout<<output_filename<<std::endl;
  output_stream.str(""); //clear stream content
  return 0;
}
