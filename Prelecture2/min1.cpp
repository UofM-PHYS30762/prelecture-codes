// PL2/min1.cpp
//Finding minimum of two numbers
//Original Source: Prof. Niels Walet's code repository
//Last modified by Charanjit K. Khosa, 31.01.2023
#include<iostream>
int min_int(int int1, int int2)
{
  if (int1<int2) return int1; else return int2;
}
int main()
{
  int integer1{3};
  int integer2{4};
  std::cout<<min_int(integer1, integer2)<<std::endl;
  return 0;
}

