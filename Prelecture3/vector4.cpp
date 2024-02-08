// PL3/vector4.cpp
// Demonstration of the vector container, iteratotrs, sort and reverse
// Source: Prof. Niels Walet's code repository
#include<iostream>
#include<string>
#include<algorithm> // sort and reverse
#include<vector>
int main() 
{
  std::vector<double> double_vector;   
  // Set values of vector by pushing
  double_vector.push_back(4.5);
  double_vector.push_back(1.5);
  double_vector.push_back(3.0);  
  std::vector<double>::iterator vector_begin{double_vector.begin()};
  std::vector<double>::iterator vector_end{double_vector.end()};
  // Sort data in ascending order
  sort(vector_begin, vector_end); 
  std::cout<<"Sorted data:"<<std::endl;
  std::vector<double>::iterator vector_iterator;
  for(vector_iterator=vector_begin; vector_iterator<vector_end; ++vector_iterator)
    std::cout<<*vector_iterator<<std::endl; 
  // Reverse order
  reverse(vector_begin, vector_end);
  std::cout<<"Reverse sorted data:"<<std::endl;
  for(vector_iterator=vector_begin; vector_iterator<vector_end; ++vector_iterator)
    std::cout<<*vector_iterator<<std::endl; 
  return 0;
}

