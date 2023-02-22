// PL5/aclass.cpp
// A populated class for 3 vectors
// Source: Prof. Niels Walet's code repository
#include<iostream>
class vector3
{
private:
  double x{};
  double y{};
  double z{}; 
public:
  // Constructors and destructor
  vector3() = default ;
  vector3(double x_in, double y_in, double z_in) : x{x_in}, y{y_in}, z{z_in} {} 
  ~vector3(){std::cout<<"Destroying vector"<<std::endl;} 











};
