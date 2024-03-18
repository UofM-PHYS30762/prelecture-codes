// PL8/mixedarray.cpp
// Demonstrate how to use a vector of baseclass pointers to achieve polymorphism
// Niels Walet, Last modified 03/12/2019
#include<iostream>
#include<memory>

class particle
{
protected:
  double charge;
public:
  particle(double q) : charge{q} {} 
  virtual void info() const {std::cout<<"particle: charge="<<charge<<"e"<<std::endl;}
  virtual ~particle(){};
};

class ion : public particle
{
private:
  int atomic_number;
public:
  ion(double q, int Z) : particle{q},atomic_number{Z} {}
  void info() const
  {
    std::cout<<"ion: charge="<<charge
	     <<"e, atomic number="<<atomic_number<<std::endl;
  }
  ~ion(){};
};

//Try: this would not work (passing by value would make a copy of a unique pointer, not allowed)
//void prettyParticlePrinter (std::unique_ptr<particle> theParticle) {
//so, in this case you can pass the raw pointer instead (use also const as you're not modifying it, 
//bad things will happen if you do)
//for more advanced and fun reading: https://herbsutter.com/2013/06/05/gotw-91-solution-smart-pointer-parameters/
void prettyParticlePrinter (const particle* theParticle) {
   //add some ascii art
   std::cout << "_U__U__U__U__U__U__U__U__U__U__U__U__U_" << std::endl;
   //then call the function 
   theParticle->info();

}

int main()
{
  // Array of base and derived objects, one particle and one ion 
  std::unique_ptr<particle> particle_array[2];
  particle_array[0] = std::make_unique<particle>(2); // He 
  particle_array[1] = std::make_unique<ion>(1,2);    // He+
  //note below: get() does not change who owns the pointer, 
  //so the smart pointer will still be responsible for returning the memory (deleting) as usual 
  prettyParticlePrinter(particle_array[0].get());
  prettyParticlePrinter(particle_array[1].get()); 
  //no need for delete, memory management is done for you by the smart pointer!
  return 0;
}
