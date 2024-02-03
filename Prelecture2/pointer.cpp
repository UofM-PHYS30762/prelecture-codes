//PL2/pointer.cpp
//Pointer variable (PHYS30762)
//Charanjit Kaur, 31/01/2024
#include<iostream>
int main()
{
  int a{3}; //a is an ordinary int variable, initialised to 3
  int* ptr; //ptr is declared as pointer to int
  ptr = &a; //ptr points to a 

  std::cout<<"Value of a is "<<a<<std::endl;

  //ptr contains address of a
  std::cout<<"address of a "<<ptr<<std::endl;

  //derefrencing ptr (will provide value of a)
  std::cout<<"Value of a (*ptr) "<<*ptr<<std::endl;

  return 0;
}


