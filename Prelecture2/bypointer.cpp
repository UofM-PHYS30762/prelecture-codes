// PL2/bypointer.cpp
// Call by value using pointer
// Source: Prof. Niels Walet's code repository
#include<iostream> 
void double_value(double *ptr_double) 
{
  (*ptr_double)*=2;
}
int main() 
{ 
  double number{4.}; 
  std::cout<<number<<std::endl; 
  double_value(&number); 
  std::cout<<number<<std::endl; 
  return 0; 
}
