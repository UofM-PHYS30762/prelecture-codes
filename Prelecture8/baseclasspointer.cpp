// PL8/baseclasspointer.cpp
// Demonstrates base class pointers
// Niels Walet, Last modified 03/12/2019
#include<iostream>
class particle
{
protected:
  double charge{};
public:
  particle(double q) : charge{q} {} 
  void info(){std::cout<<"particle: charge="<<charge<<"e"<<std::endl;}
};

class ion : public particle
{
private:
  int atomic_number;
public:
  ion(double q, int Z) : particle{q}, atomic_number{Z} {};
  void info()
  {
    std::cout<<"ion: charge="<<charge
	     <<"e, atomic number="<<atomic_number<<std::endl;
  }
};
int main()
{
  particle particle_1{1}; // proton
  ion ion_1{2,2}; // helium nucleus
  particle_1.info();
  ion_1.info();
  return 0;
}
