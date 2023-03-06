#ifndef PARTICLE_H
#define PARTICLE_H

#include <iostream>
#include <string>
#include <cmath>

class particle
{
private:
    std::string type {"Ghost"};
    double mass {0.0};
    double momentum {0.0};
    double energy {0.0};

public:
    particle() = default;
    particle(std::string particle_type, double particle_mass, double particle_momentum) :
        type{particle_type}, mass{particle_mass}, momentum{particle_momentum}, 
        energy{sqrt(mass*mass+momentum*momentum)} 
    {};
    ~particle(){std::cout<<"Destroying "<<type<<std::endl;}  // Destructor (in-line)
    double gamma() {return energy/mass;} // One-line functions are OK in-line
    void print_data();
}




#endif