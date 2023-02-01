// PL2/min3.cpp
//Finding minimum of two numbers
//Original Source: Prof. Niels Walet's code repository
//Last modified by Charanjit K. Khosa, 31.01.2023
#include<iostream>
int min(int number1, int number2)
{
  if(number1<number2) return number1; else return number2;
}
double min(double number1, double number2)
{
  if(number1<number2) return number1; else return number2;
}
int main()
{
  int integer1{3};
  int integer2{4};
  double real1{2.1};
  double real2{5.3};
  std::cout<<min(integer1, integer2)<<std::endl;
  std::cout<<min(real1, real2)<<std::endl;
  return 0;
}

