// PL4/class5.cpp
// An example using a vector of objects
// Niels Walet, last updated 04/12/2019
#include<iostream>
#include<string>
#include<vector>
#include<cmath>
using namespace std;
class particle
{
private:
  string type;
  double mass;
  double momentum;
  double energy;
public:
// Default constructor
  particle() : type{"Ghost"}, mass{}, momentum{}, energy{}  {}
// Parameterized constructor
  particle(string particleType, double particleMass, double particleMomentum) :
    type{particleType}, mass{particleMass}, momentum{particleMomentum}, 
    energy{sqrt(particleMass*particleMass+particleMomentum*particleMomentum)} 
  {}
  ~particle(){cout<<"Destroying "<<type<<endl;}  // Destructor
  double gamma() {return energy/mass;}
  void print_data();
};

void particle::print_data()
{
  cout.precision(3); // 2 significant figures
  cout<<"Particle: [type,m,p,E] = ["<<type<<","<< mass
	   <<","<<momentum<<","<<energy<<"]"<<endl;
  return;
}

int main()
{
  vector<particle> particle_data;
  particle_data.push_back(particle("electron",5.11e5,1.e6));
  particle_data.push_back(particle("proton",0.938e9,3.e9));
  //vector<particle>::iterator particle_it; 
  for(auto particle_it=particle_data.begin();
      particle_it<particle_data.end();
      ++particle_it){
    particle_it->print_data();
    cout<<"has Lorentz factor gamma="<<particle_it->gamma()<<endl;
  }
  return 0;
}
