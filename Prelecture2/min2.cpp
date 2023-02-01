// PL2/min2.cpp
//Finding minimum of two numbers
//Original Source: Prof. Niels Walet's code repository
//Last modified by Charanjit K. Khosa, 31.01.2023
#include<iostream>
int min_int(int int1, int int2)
{
  if(int1<int2) return int1; else return int2;
}
double min_double(double double1, double double2)
{
    if (double1<double2) return double1; else return double2;
}
int main()
{
  int integer1{3};
  int integer2{4};
  double real1{2.1};
  double real2{5.3};
  std::cout<<min_int(integer1,integer2)<<std::endl;
  std::cout<<min_double(real1,real2)<<std::endl;
  return 0;
}

