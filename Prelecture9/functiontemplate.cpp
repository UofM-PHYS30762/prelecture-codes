// PL9/functiontemplate.cpp
// Demonstration of function templates
// Niels Walet, Last modified 04/12/2019
#include<iostream>
template <class c_type> c_type maxval(c_type a, c_type b)
{
  return (a > b) ? a : b;
}
int main()
{
  double x1{1}; double x2{1.5};
  std::cout<<"Maximum value (doubles) = "<< maxval<double>(x1,x2)<<std::endl;
  int i1{1}; int i2{-1};
  std::cout<<"Maximum value (ints) = "<< maxval<int>(i1,i2)<<std::endl;
  return 0;
}
