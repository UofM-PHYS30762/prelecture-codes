// PL5/aclassfull1.cpp
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
};
double dot_product(const vector3& v1, const vector3& v2)
{
  double result = 
    v1.get_x()*v2.get_x() + 
    v1.get_y()*v2.get_y() + 
    v1.get_z()*v2.get_z();
  return result;
}
int main()
{
  // Define 3 vectors
  vector3 a;
  vector3 b{1,2,3};
  vector3 c{-1,-2,-3};
  // Print vectors 
  a.show();
  b.show();
  c.show();
  // Add a scalar to each vector component
  double s{-1.5};
  b.add_scalar(s);
  b.show();
 // Dot product using normal function (passing two vectors)
  double dp=dot_product(b,c);
  std::cout<<"Dot product b.c = "<<dp<<std::endl;
  return 0;
}
