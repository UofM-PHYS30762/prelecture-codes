// PL10/badalloc.cpp
// illustrates an exception thrown by new (allocating memory)
// Niels Walet. Last edited 03/12/2019
#include<iostream>
#include<memory>
int main() {
  double *my_array;
  try
    {
      my_array = new double[10000000000000000];
    }
  catch(std::bad_alloc memFail)
    {
      std::cerr<<"Memory allocation failure"<<std::endl;
      return(1);
    }
  delete[] my_array;
  return 0;
}
