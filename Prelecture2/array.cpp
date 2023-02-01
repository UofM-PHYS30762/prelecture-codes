// PL2/array.cpp
// Arrays vs. pointers
// Source: Prof. Niels Walet's code repository
#include<iostream> 
void print_array(const int array_entries, int *array) 
{
  // show that array[i] is equivalent to *(array+i) 
  for(int i{};i<array_entries;i++) 
    std::cout<<array[i]<<" "<<*(array+i)<<std::endl;
  return; 
}
int main() 
{ 
  const int array_entries{3}; 
  int array[array_entries]; 
  for(int i{};i<array_entries;i++) array[i]=i; 
  print_array( array_entries,array); 
  return 0; 
}
