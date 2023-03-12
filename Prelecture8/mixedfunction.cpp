// PL8/mixedarray.cpp
// Demonstrate how to use a vector of baseclass pointers to achieve polymorphism
// Niels Walet, Last modified 03/12/2019
#include<iostream>
class particle
{
protected:
  double charge;
public:
  particle(double q) : charge{q} {} 
  virtual void info(){std::cout<<"particle: charge="<<charge<<"e"<<std::endl;}
  virtual ~particle(){};
};

class ion : public particle
{
private:
  int atomic_number;
public:
  ion(double q, int Z) : particle{q},atomic_number{Z} {}
  void info()
  {
    std::cout<<"ion: charge="<<charge
	     <<"e, atomic number="<<atomic_number<<std::endl;
  }
  ~ion(){};
};

void prettyParticlePrinter (particle* theParticle) {

   //add some ascii art
   std::cout << "_U__U__U__U__U__U__U__U__U__U__U__U__U_" << std::endl;
   //then call the function 
   theParticle->info();

}

int main()
{
  // Array of base and derived objects, one particle and one ion 
  particle *particle_array[2];
  particle_array[0] = new particle{2}; // He 
  particle_array[1] = new ion{1,2};    // He+

  prettyParticlePrinter(particle_array[0]);
  prettyParticlePrinter(particle_array[1]);
  
  delete particle_array[0]; particle_array[0]=0;
  delete particle_array[1]; particle_array[1]=0;
  return 0;
}
