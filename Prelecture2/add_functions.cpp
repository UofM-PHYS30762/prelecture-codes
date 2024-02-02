//PL2/add_functions.cpp
//Addition of two numbers (PHYS30762)
//Charanjit Kaur, 31/01/2024
#include<iostream>

int addition_int(int int1, int int2)
{
  return int1+int2;
}
double addition_double(double double1, double double2)
{
  return double1+double2;
}

int main()
{
  int integer1{3};
  int integer2{4};
  double real1{2.1};
  double real2{5.3};
  std::cout<<addition_int(integer1,integer2)<<std::endl;
  std::cout<<addition_double(real1,real2)<<std::endl;
  return 0;
}

