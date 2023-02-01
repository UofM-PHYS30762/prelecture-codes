// PL2/byreference2.cpp
// Use of a reference variable
// Source: Prof. Niels Walet's code repository
#include<iostream>
int main() 
{ 
  int number{4}; 
  int& reference{number};
  std::cout<<number<<" "<<reference<<std::endl; 
  number++; 
  std::cout<<number<<" "<<reference<<std::endl; 
  return 0;
}

