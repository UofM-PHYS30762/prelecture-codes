#include<iostream>
#include<cmath>
#include<string>

class particle
{
private:
    std::string type {"Ghost"};
    double mass {0.0};
    double momentum {0.0};
    double energy {0.0};

public:

    //constructor
    particle() = default;

    //parameterized constructor

    particle(std::string particle_type, double particle_mass, double particle_momentum)
    {
        type = particle_type;
        mass = particle_mass;
        momentum = particle_momentum;
        energy = sqrt(mass*mass + momentum*momentum);
    }
    
    ~particle(){std::cout<<"Particle destroyed"<<std::endl;} //destructor so destroy the thing when we are done with it
    double gamma() const {return energy/mass;}
    void print_data();
};

void particle::print_data()
{
    std::cout.precision(3);
    std::cout<<"Particle: [type, m, p, E]"<<type<<', '<<mass<<', '<<momentum<<', '<<energy<<std::endl;
    return;
}


int main()
{
    //create 2 particles
    particle pi("electron", 0.511, 1e6);
    particle pj("positron", 0.511, 1e6);

    pi.print_data();
    pj.print_data();

    //calculate the Lorentz facttors

    double gamma_i = pi.gamma();
    double gamma_j = pj.gamma();

    std::cout<<"gamma_i = "<<gamma_i<<std::endl;
    std::cout<<"gamma_j = "<<gamma_j<<std::endl;

    return 0;
}