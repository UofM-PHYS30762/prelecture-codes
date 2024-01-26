// PL1/variables.cpp
// An example of const variables(PHYS30762)
// Niels Walet, last updated by Charanjit Kaur 23/01/2024
#include<iostream>
int main()
{
  const int course_year{2024}; 
  const double solar_mass_in_kg{1.989e30}; 
  std::cout<<"C++ is the best programming language in "
	   <<course_year<<"!"<<std::endl;
  std::cout<<"Did you know that the mass of the sun is "
	   <<solar_mass_in_kg<<" kg?"<<std::endl;
  return 0;
}


  


