#include <iostream>
#include <particle.h>

void particle::print_data()
{
    std::cout.precision(3);
    std::cout<<"Particle: [type, m, p, E]"<<type<<', '<<mass<<', '<<momentum<<', '<<energy<<std::endl;
    return;
}