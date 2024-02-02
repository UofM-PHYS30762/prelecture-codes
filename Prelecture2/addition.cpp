// PL2/addition.cpp
//Addition of integers (PHYS30762)
//Charanjit Kaur, 31/01/2024
#include<iostream>

int addition(int int1, int int2)
{
  return int1+int2;
}

int main()
{
  int integer1{3};
  int integer2{6};
  std::cout<<addition(integer1,integer2)<<std::endl;
  int integer3{2};
  int integer4{8};
  std::cout<<addition(integer3,integer4)<<std::endl;
  return 0;
}

