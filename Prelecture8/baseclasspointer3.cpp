// PL8/baseclasspointer3.cpp
// Demonstrates the use of a baseclass pointer
// Niels Walet, Last modified 03/12/2019
#include<iostream>
using namespace std;
class particle
{
protected:
  double charge;
public:
  particle(double q) : charge{q}{} 
  virtual void info(){std::cout<<"particle: charge="<<charge<<"e"<<std::endl;}
};

class ion : public particle
{
private:
  int atomic_number;
public:
  ion(double q, int Z) : particle{q}, atomic_number{Z}{}
  void info(){
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
  particle *particle_pointer; // pointer to particle 
  particle_pointer=&particle_1; // point to particle_1
  particle_pointer->info(); 
  particle_pointer=&ion_1; // point to ion_1 (allowed!)
  particle_pointer->info();
  return 0;
}
