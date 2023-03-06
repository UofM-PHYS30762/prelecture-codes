#include <iostream>
#include <string>
#include<cmath>

class particle
{
public:
    std::string type;
    double mass;
    double momentum;
    double energy;
};

void print_data(const struct particle &p)

{
    std::cout.precision(3);
    std::cout<<"Particle: [type, m, p, E]"<<p.type<<', '<<p.mass<<', '<<p.momentum<<', '<<p.energy<<std::endl;
    return;
}

double gamma(const struct particle &p)
{
    return p.energy/p.mass;
}

int main()
{
    //create 2 particles
    particle pi;
    pi.type = "electron";
    pi.mass = 0.511;
    pi.momentum = 1e6;
    pi.energy = sqrt(pi.mass*pi.mass + pi.momentum*pi.momentum);

    particle pj;
    pj.type = "positron";
    pj.mass = 0.511;
    pj.momentum = 1e6;
    pj.energy = sqrt(pj.mass*pj.mass + pj.momentum*pj.momentum);

    print_data(pi);
    print_data(pj);

    //calculate the Lorentz facttors

    double gamma_i = gamma(pi);
    double gamma_j = gamma(pj);

    std::cout<<"gamma_i = "<<gamma_i<<std::endl;
    std::cout<<"gamma_j = "<<gamma_j<<std::endl;

    return 0;
}