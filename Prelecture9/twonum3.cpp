// PL9/twonum3.cpp
// Define a class template to hold a pair of numbers (header file)
// Niels Walet, Last modified 03/12/2019
#include<iostream>
#include"twonum3.h"
using namespace two_num;
int main()
{
  int x{1},y{2};
  double a{-1.5},b{-2.5};
  // Use class template for object representing pair of integers
  pair_of_numbers<int> ip(x,y);
  std::cout<<"x+y="<<ip.add()<<std::endl;
  std::cout<<"x-y="<<ip.sub()<<std::endl;
  // Now for  a pair of doubles
  pair_of_numbers<double> dp(a,b);
  std::cout<<"a+b="<<dp.add()<<std::endl;
  std::cout<<"a-b="<<dp.sub()<<std::endl;
  return 0;
}
