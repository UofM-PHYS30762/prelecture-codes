// PL5/classfull.cpp
// A fully functioning class for 3-vectors
// Source: Prof. Niels Walet's code repository
#include<iostream>
#include<string>
class vector3
{
  friend vector3 operator+(double scalar, const vector3 &v);
  friend std::ostream & operator<<(std::ostream &os, const vector3 &v);
private:
  double x,y,z; 
public:
  vector3() : x{}, y{}, z{} {}
  vector3(double xin, double yin, double zin) : x{xin}, y{yin}, z{zin} {} 
  ~vector3(){std::cout<<"Destroying vector"<<std::endl;} 
  // Access functions to set and get vector components
  void set_x(double xin) {x=xin;} 
  void set_y(double yin) {y=yin;}
  void set_z(double zin) {z=zin;}
  double get_x() const {return x;}
  double get_y() const {return y;}
  double get_z() const {return z;}
  // Function to calculate dot product of two vectors
  double dot_product(const vector3& v) const
  {
    return (x*v.x+y*v.y+z*v.z);
  }
  // Function to overload + operator (addition of two vectors)
  vector3 operator+(const vector3 &v) const
  {
    vector3 temp{x+v.x,y+v.y,z+v.z};
    return temp;
  }
  // Another one for (right) adding a scalar
  vector3 operator+(const double scalar) const
  {
    vector3 temp{x+scalar,y+scalar,z+scalar};
    return temp;
  }
  void operator+=(const double scalar) 
  {
    x+=scalar; y+=scalar; z+=scalar;
  }
  void operator+=(const vector3 &v) 
  {
    x+=v.x; y+=v.y; z+=v.z;
  }
}; // End of class
// Friend functions (not members but have access to member data)
// Non-member function to left-add scalar to vector
vector3 operator+(double scalar, const vector3& v)
{
  vector3 temp{scalar+v.x,scalar+v.y,scalar+v.z};
  return temp;
}
// Non-member function to overload ostream (e.g., cout) for vector3
std::ostream & operator<<(std::ostream& os, const vector3& v)
  {
    os<<"("<<v.x<<","<<v.y<<","<<v.z<<")";
    return os;
  }
// Main program
int main()
{
  vector3 a;
  vector3 b{1,2,3};
  vector3 c{-1,-2,-3};
  // Print vectors 
  std::cout <<a<<" "<<b<<" "<<c<<std::endl;
  // Add a scalar to each vector component
  double s{-1.5};
  b+=s;
  std::cout << b <<std::endl;
  // Dot product using member function of vector3
  double dp=b.dot_product(c);
  std::cout<<"Dot product b.c = "<<dp<<std::endl;
  // Demonstrate vector addition, d=b+c 
  vector3 e=b+c;
  std::cout << e<<std::endl;
  b+=c;
  std::cout << b<<std::endl;
  return 0;
}
