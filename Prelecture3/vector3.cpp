// PL3/vector3.cpp
// Demonstration of the vector container and the use of iterators
// Source: Prof. Niels Walet's code repository
#include<iostream>
#include<vector>
int main() 
{
  std::vector<double> vector_double;
  vector_double.push_back(4.5);
  vector_double.push_back(1.5);
  vector_double.push_back(3.0); 
  std::vector<double>::iterator vector_begin{vector_double.begin()};
  std::vector<double>::iterator vector_end{vector_double.end()};
  std::vector<double>::iterator vector_iterator;
  for(vector_iterator=vector_begin;
    vector_iterator<vector_end;
    ++vector_iterator)
    std::cout<<*vector_iterator<<std::endl;
  return 0;
}

