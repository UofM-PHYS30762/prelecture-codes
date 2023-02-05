// PL3/vector4.cpp
// Demonstration of the vector container, iteratotrs, sort and reverse
// Niels Walet, last updated 04/12/2019
#include<iostream>
#include<string>
#include<algorithm> // sort and reverse
#include<vector>
using namespace std;
int main() 
{
  vector<double> double_vector;   
  // Set values of vector by pushing
  double_vector.push_back(4.5);
  double_vector.push_back(1.5);
  double_vector.push_back(3.0);  
  vector<double>::iterator vector_begin{double_vector.begin()};
  vector<double>::iterator vector_end{double_vector.end()};
  // Sort data in ascending order
  sort(vector_begin, vector_end); 
  cout<<"Sorted data:"<<endl;
  vector<double>::iterator vector_iterator;
  for(vector_iterator=vector_begin;vector_iterator<vector_end;++vector_iterator)
    cout<<*vector_iterator<<endl; 
  // Reverse order
  reverse(vector_begin, vector_end);
  cout<<"Reverse sorted data:"<<endl;
  for(vector_iterator=vector_begin;vector_iterator<vector_end;++vector_iterator)
    cout<<*vector_iterator<<endl; 
  return 0;
}

