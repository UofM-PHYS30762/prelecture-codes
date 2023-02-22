// PL5/aclassfull3.cpp
// A populated class for 3 vectors, with demonstration code
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
  // Access functions to set and get vector components
  void set_x(const double x_in) {x=x_in;} 
  void set_y(const double y_in) {y=y_in;}
  void set_z(const double z_in) {z=z_in;}
  double get_x() const {return x;}
  double get_y() const {return y;}
  double get_z() const {return z;}
  // Function to print out vector
  void show() const {std::cout<<"("<<x<<","<<y<<","<<z<<")"<<std::endl;}
  // Function to add a scalar to each vector component
  void add_scalar(const double s) {x+=s; y+=s; z+=s;}
  // Function to calculate dot product of two vectors
  double dot_product(const vector3 &v) const
  {
    return (x*v.x+y*v.y+z*v.z);
  }
  // Add two vectors together and return a new vector
  vector3 plus(const vector3 &v) const
  {
    vector3 temp;
    temp.set_x(x+v.x);
    temp.set_y(y+v.y);
    temp.set_z(z+v.z);
    return temp;
  }
}; 
int main()
{
  vector3 b{1,2,3};
  vector3 c{-1,-2,-3};
  // Print vectors 
  b.show();
  c.show();
  vector3 d=b.plus(c);
  std::cout<<"sum of b and c is ";
  d.show();
  return 0;
}
