// PL6/shallow.cpp
// An example of defining an assignment operator
// Source: Prof. Niels Walet's code repository
#include<iostream>
class dynamic_array
{
private:
  size_t size {};
  double *array {nullptr};
public:
  dynamic_array()
     {std::cout<<"Default constructor called"<<std::endl;}
  dynamic_array(size_t s);
  ~dynamic_array(){std::cout<<"Destructor called"<<std::endl;}
  size_t length() const {return size;}
  double & operator[](size_t i);
};
// Parameterized constructor implementation
dynamic_array::dynamic_array(size_t s)
{
  std::cout<<"Parameterized constructor called"<<std::endl;
  if(s<1) {
    std::cerr<<"Error: trying to declare an array with size < 1"<<std::endl;
    throw("size not positive");
  }
  size = s;
  array = new double[size];
  for(size_t i{}; i<size; i++) array[i] = 0;
}
// Overloaded element [] operator implementation
double & dynamic_array::operator[](size_t i)
{
  if(i<0 || i>=size) {
    std::cerr<<"Error: trying to access array element out of bounds"<<std::endl;
    throw("Out of Bounds error");
  }
  return array[i];
}  
int main()
{
  std::cout<<"Declaring array a1 with parameterized constructor"<<std::endl;
  dynamic_array a1{2};
  std::cout<<"Length of a1 = "<<a1.length()<<std::endl;
  a1[0] = 0.5;
  a1[1] = 1.0;
  std::cout<<"a1[0] = "<<a1[0]<<std::endl;
  std::cout<<"a1[1] = "<<a1[1]<<std::endl;
  std::cout<<std::endl;
  std::cout<<"Declaring array a2 with default constructor"<<std::endl;
  dynamic_array a2;
  std::cout<<"Length of a2 = "<<a2.length()<<std::endl;
  std::cout<<"Now copy values from a1 by assignment"<<std::endl;
  a2=a1;
  std::cout<<"Length of a2 = "<<a2.length()<<std::endl;
  std::cout<<"a2[0] = "<<a2[0]<<std::endl;
  std::cout<<"a2[1] = "<<a2[1]<<std::endl;
  std::cout<<std::endl;
  return 0;
}
