// PL8/polymorphicvarray.cpp
// Demonstrate how to use an array of baseclass pointers to achieve polymorphism
// Niels Walet, Last modified 06/01/2022
#include<iostream>
class particle
{
public:
  virtual ~particle(){} // Need this!
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
  void info()
  {
    std::cout<<"ion: charge="<<charge
	     <<"e, atomic number="<<atomic_number<<std::endl;
  }
};

int main()
{
  // Array of 2 base class pointers, done with raw pointers to exemplify how ** works...
  // To do this in a more sensible way (std::vector and smart pointers) see polymorphicvector.cpp
  particle **particle_array = new particle*[2];
  particle_array[0] = new ion{1,2};
  particle_array[1] = new electron; 
  particle_array[0]->info(); // print info for electron
  particle_array[1]->info(); // print info for ion
  // clean-up
  delete particle_array[0]; 
  delete particle_array[1]; 
  delete[] particle_array;

  return 0;
}

