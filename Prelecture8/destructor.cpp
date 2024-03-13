// PL8/destructor.cpp
// Demonstrate where destructors are called
// Niels Walet, Last modified 03/12/2019
#include<iostream>
#include<string>
#include<memory>
class particle
{
protected:
  double charge;
public:
  particle(double q) : charge{q}{} 
  virtual ~particle(){std::cout<<"Calling base class destructor"<<std::endl;}
  virtual void info(){std::cout<<"particle: charge="<<charge<<"e"<<std::endl;}
};

class ion : public particle
{
private:
  int atomic_number;
public:
  ion(double q, int Z) : particle{q}, atomic_number{Z}{}
  ~ion(){std::cout<<"Calling derived class destructor"<<std::endl;}
  void info()
  {
    std::cout<<"ion: charge="<<charge
	     <<"e, atomic number="<<atomic_number<<std::endl;
  }
};
int main()
{
  // Array of base and derived objects, one particle and one ion 
  std::unique_ptr<particle> particle_array[2];
  particle_array[0] = std::make_unique<particle>(2); // He 
  particle_array[1] = std::make_unique<ion>(1,2);    // He+
  particle_array[0]->info(); // print info for particle
  particle_array[1]->info(); // print info for ion
  //no need for delete, memory management is done for you by the smart pointer!
  return 0;
}
