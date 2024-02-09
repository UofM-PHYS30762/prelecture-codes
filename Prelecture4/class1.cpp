// PL4/class1.cpp
// An example using a class
// Niels Walet, last updated 04/12/2019
#include<iostream>
#include<string>
#include<cmath>
class particle
{
public:
  std::string type;
  double mass;
  double momentum;
  double energy;
};
void print_data(const particle &p)
{
  std::cout.precision(3); // 2 significant figures
  std::cout<<"Particle: [type,m,p,E] = ["<<p.type<<","<< p.mass
	   <<","<<p.momentum<<","<<p.energy<<"]"<<std::endl;
  return;
}
double gamma(const particle &p)
{
  return p.energy/p.mass;
}
int main()
{
  // Create 2 particles 
  particle p1;
  p1.type="electron";
  p1.mass=5.11e5;
  p1.momentum=1.e6;
  p1.energy=sqrt(p1.mass*p1.mass+p1.momentum*p1.momentum);
  particle p2;
  p2.type="proton";
  p2.mass=0.938e9;
  p2.momentum=3.e9;
  p2.energy=sqrt(p2.mass*p2.mass+p2.momentum*p2.momentum);
  // Print out details
  print_data(p1);
  print_data(p2);
  // Calculate Lorentz factors
  std::cout.precision(2);
  std::cout<<"Particle 1 has Lorentz factor gamma="
	   <<gamma(p1)<<std::endl;
  std::cout<<"Particle 2 has Lorentz factor gamma="
	   <<gamma(p2)<<std::endl;
  return 0;
}
