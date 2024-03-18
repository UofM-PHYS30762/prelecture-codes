// PL8/enum.cpp
// Demonstrate use of enum
// Caterina Doglioni, Last modified 14/03/2024
#include<iostream>
#include<vector>
#include<string>

int main () {

    enum particleType {
        ELECTRON = 0, //note the comma, not the semicolon
        PROTON = 1, //the ints here can be anything you choose
        MUON = 2,
    };

    //simple example: assume that you will always want particles in this order, 
    //and want a short-hand for indices that is not numbers
    std::vector<std::string> vector_of_particle_names(3);
    vector_of_particle_names[ELECTRON] = "Electron";
    vector_of_particle_names[PROTON] = "Proton";
    vector_of_particle_names[MUON] = "Muon";

    std::cout << "The index of vector_of_particle_names[ELECTRON] is " << ELECTRON << std::endl;
    std::cout << "Its content is: " << vector_of_particle_names[ELECTRON] << std::endl;

}