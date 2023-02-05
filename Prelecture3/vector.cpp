// PL3/vector.cpp
// Demonstration of the vector container
// Niels Walet, last updated 04/12/2019
#include<iostream>
#include<vector>
#include<string>
//using namespace std; //could have used that here to help readability
int main() 
{
    const size_t n_a{5};
    std::vector<double> a(n_a); //length 5 vector of type double
    std::vector<double> b;  // empty vector (stores doubles)
    std::vector<int> c(3,1); //length 3 vector of integers, with all elements 1
    std::vector<std::string> names(3); //vector with 3 strings
    std::vector<std::vector<double> > dd(3); //vector containing 3 empty double vectors
    dd[0]=a;// set the first element of dd to the vector a
}

