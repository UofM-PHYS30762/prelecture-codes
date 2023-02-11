// PL4/class4.cpp
// An example using a class 
// Niels Walet, last updated 04/12/2019
#include<iostream>
#include<string>
#include<cmath>
class particle
{
private:
  std::string type {"Ghost"};
  double mass {0.0};
  double momentum {0.0};
  double energy {0.0};
public:
// Default constructor
  particle() = default ;
// Parameterized constructor
  particle(std::string particle_type, double particle_mass, double particle_momentum) :
    type{particle_type}, mass{particle_mass}, momentum{particle_momentum}, 
    energy{sqrt(mass*mass+momentum*momentum)} 
  {}
  ~particle(){std::cout<<"Destroying "<<type<<std::endl;}  // Destructor
  double gamma() {return energy/mass;}
  void print_data();
};

void particle::print_data()
{
  std::cout.precision(3); // 2 significant figures
  std::cout<<"Particle: [type,m,p,E] = ["<<type<<","<< mass
	   <<","<<momentum<<","<<energy<<"]"<<std::endl;
  return;
}

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
