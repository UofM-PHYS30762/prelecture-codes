// PL4/class4.cpp
// An example using a class 
// Niels Walet, last updated 04/12/2019
#include<iostream>
#include<string>
#include<cmath>
#include "particle.h" 

int main()
{
  // Set values for the two particles
  particle electron("electron",5.11e5,1.e6);
  particle proton("proton",0.938e9,3.e9);
  // Print out details
  electron.print_data();
  proton.print_data();
  // Calculate Lorentz factors
  std::cout.precision(2);
  std::cout<<"Particle 1 has Lorentz factor gamma="
	   <<electron.gamma()<<std::endl;
  std::cout<<"Particle 2 has Lorentz factor gamma="
	   <<proton.gamma()<<std::endl;
  return 0;
}
