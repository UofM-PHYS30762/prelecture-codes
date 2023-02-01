// PL2/dynamic.cpp
// Example of program using dynamic memory allocation
// Source: Prof. Niels Walet's code repository
#include<iostream>
int main()
{
  int number_of_values;
  std::cout<<"Enter the number of values to enter: ";
  std::cin>>number_of_values;
  std::cout<<"You would like to enter "<<number_of_values<<" values"<<std::endl;
  double *values = new double[number_of_values];
  std::cout<<"Allocated memory for "<<number_of_values<<" doubles"<<std::endl;
  std::cout<<"Enter "<<number_of_values<<" doubles"<<std::endl;
  for(int i{};i<number_of_values;i++) {
    std::cin>>values[i];
    }
  std::cout<<"Here are your values: ";
  for(int i{};i<number_of_values;i++) {
    std::cout<<values[i]<<" ";
    }
  std::cout<<std::endl;
  // Free memory
  delete[] values;
  std::cout<<"Freed memory"<<std::endl;
  return 0;
}
