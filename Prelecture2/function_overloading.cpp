//PL2/function_overloading.cpp
//Example of function overloading (PHYS30762)
//Charanjit Kaur, 31/01/2024
#include<iostream>

int addition(int number1, int number2)
{
  return number1+number2;
}
double addition(double number1, double number2)
{
  return number1+number2;
}

int main()
{
  int integer1{3};
  int integer2{4};
  double real1{2.1};
  double real2{5.3};
  std::cout<<addition(integer1, integer2)<<std::endl;
  std::cout<<addition(real1, real2)<<std::endl;
  return 0;
}

