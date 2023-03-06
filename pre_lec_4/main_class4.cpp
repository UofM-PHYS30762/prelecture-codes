#include <iostream>
#include <particle.h>
#include <cmath>
#include <string>

int main()
{
    particle electron("electron", 0.511, 1e6);
    particle positron("positron", 0.511, 1e6);
    particle proton("proton", 938.272, 1e6);

    electron.print_data();
    positron.print_data();
    proton.print_data();

    std::cout<<"gamma_i = "<<electron.gamma()<<std::endl;
    std::cout<<"gamma_j = "<<positron.gamma()<<std::endl;
    std::cout<<"gamma_k = "<<proton.gamma()<<std::endl;

    return 0;
}