//PL2/array.cpp
//Showing relationship between arrays and pointers (PHYS30762)
//Charanjit Kaur, 31/01/2024
#include<iostream> 

int main() 
{ 
  const int size{4};
  int array[size]={11,22,33,44}; 

  //displays the address
  std::cout<<"array "<<array<<std::endl;
  
  //displays first entry
  std::cout<<"array - first entry "<<array[0]<<std::endl;

  //also displays first entry
  std::cout<<"array - first entry "<<*array<<std::endl;
  return 0; 
}


