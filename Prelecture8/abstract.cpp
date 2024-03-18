// PL8/abstract.cpp
// The use of an abstract base class
// Niels Walet, last updated 06/01/2022
#include<iostream>
#include<memory>

class particle
{
public:
  //the print-out here is to show you that the destructor of the base class is called after that of the derived class
  virtual ~particle(){std::cout << "Particle destructor called" << std::endl;} // Need this!
  virtual void info()=0; // pure virtual function   
};
class electron : public particle
{
private:
  int charge;
public:
  electron() : charge{-1} {}
  ~electron() {std::cout<<"Electron destructor called"<<std::endl;}
  void info() {std::cout<<"electron: charge="<<charge<<"e"<<std::endl;}  
};
class ion : public particle
{
private:
  int charge,atomic_number;
public:
  // Note constructor short-hand!
  ion(int q, int Z) : charge{q},atomic_number{Z} {}
  ~ion() {std::cout<<"Ion destructor called"<<std::endl;}
  void info() {std::cout<<"ion: charge="<<charge
		       <<"e, atomic number="<<atomic_number<<std::endl;}
};

int main()
{
  // Creates a ion but with a pointer to the abstract base class 'particle'
  std::unique_ptr<particle> particle_pointer_for_ion = std::make_unique<ion>(1,2);
  particle_pointer_for_ion->info(); 
  //
  std::unique_ptr<particle> particle_pointer_for_electron = std::make_unique<electron>();
  particle_pointer_for_electron->info(); 
  //
  // Try to uncomment this line and see what kind of error you get...
  // You cannot instantiate an abstract class!
  //std::unique_ptr<particle> particle_pointer_for_electron = std::make_unique<particle>(-1);
 
  return 0;
}

