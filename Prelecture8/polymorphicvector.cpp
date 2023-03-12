// PL8/polymorphicvector.cpp
// Demonstrate how to use a vector of baseclass pointers to achieve polymorphism
// Niels Walet, Last modified 06/01/2022
#include<iostream>
#include<vector>
// Abstract base class (use as interface only)
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
  void info(){std::cout<<"electron: charge="<<charge<<"e"<<std::endl;}  
};
class ion : public particle
{
private:
  int charge,atomic_number;
public:
  // Note constructor short-hand!
  ion(double q, int Z) : charge(q),atomic_number(Z) {}
  ~ion() {std::cout<<"Ion destructor called"<<std::endl;}
  void info()
  {
    std::cout<<"ion: charge="<<charge
	     <<"e, atomic number="<<atomic_number<<std::endl;
  }
};
int main()
{
  std::vector<particle*> particles;
  particles.push_back(new ion{1,3});
  particles.push_back(new electron);
  particles[0]->info();
  particles[1]->info();
  std::cout<<"particles has size "<<particles.size()<<std::endl;
  for (auto particle_it=particles.begin();
       particle_it<particles.end();
       ++particle_it) delete *particle_it;
  particles.clear();
  std::cout<<"particle_vector now has size "<<particles.size()<<std::endl;
  return 0;
}

