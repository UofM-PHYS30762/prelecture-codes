// PL2/addition.cpp
//Addition of integers
//Source: Charanjit K. Khosa, University of Manchester
//Last modified: 31.01.2023
#include<iostream>
//Defining a function for addition of two integers
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

