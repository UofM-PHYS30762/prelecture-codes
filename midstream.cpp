// PL1/midstream.cpp
// An example of decaring variables "just in time"
// Niels Walet, last updated 04/12/2019
#include<iostream>
int main()
{
  const int current_year{2022}; 
  std::cout<<"C++ is the best programming language in "
	   <<current_year<<"!"<<std::endl;
  const double solar_mass_in_kg{1.989e30}; // I only need to declare this here! 
  std::cout<<"Did you know that the mass of the sun is "
	   <<solar_mass_in_kg<<" kg?"<<std::endl;
  return 0;
}
