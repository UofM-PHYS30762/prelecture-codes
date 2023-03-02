// PL6/move.cpp
// An example of a move constructor
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
  dynamic_array(size_t s); // parametrised
  dynamic_array(dynamic_array&); // copy
  dynamic_array(dynamic_array&&); //move
  ~dynamic_array(){std::cout<<"Destructor called"<<std::endl;}
  dynamic_array& operator=(dynamic_array&); //copy assignment
  dynamic_array& operator=(dynamic_array&&); //move assignment
  size_t length() const {return size;}
  double & operator[](size_t i);
};
// Copy constructor for deep copying
dynamic_array::dynamic_array(dynamic_array &arr)
{
  // Copy size and declare new array
  std::cout <<"copy constructor\n";
  array=nullptr; size=arr.length();
  if(size>0) {
      array=new double[size];
      // Copy values into new array
      for(size_t i{};i<size;i++) array[i] = arr[i];
    }
}
// Move constructor
dynamic_array::dynamic_array(dynamic_array &&arr)
{ // steal the data
  std::cout <<"move constructor\n";
  size=arr.size;
  array=arr.array;
  arr.size=0;
  arr.array=nullptr;
}
// Assignment operator for deep copying
dynamic_array & dynamic_array::operator=(dynamic_array &arr)
{
  std::cout <<"copy assignment\n";
  if(&arr == this) return *this; // no self assignment
  // First delete this object's array
  delete[] array; array=nullptr; size=0;
  // Now copy size and declare new array
  size=arr.length();
  if(size>0){
      array=new double[size];
      // Copy values into new array
      for(size_t i{};i<size;i++) array[i] = arr[i];
    }
  return *this; // Special pointer!!!
}
// Move assignment operator
dynamic_array & dynamic_array::operator=(dynamic_array&& arr)
{
  std::cout <<"move assignment\n";
  std::swap(size,arr.size);
  std::swap(array,arr.array);
  return *this; // Special pointer!!!
}
// Parameterized constructor implementation
dynamic_array::dynamic_array(size_t s)
{
  std::cout<<"Parameterized constructor called"<<std::endl;
  if(s<1)
    {
      std::cout<<"Error: trying to declare an array with size < 1"<<std::endl;
      throw("size not positive");
    }
  size = s;
  array = new double[size];
  for(size_t i{}; i<size; i++) array[i] = 0;
}

// Overloaded element [] operator implementation
double & dynamic_array::operator[](size_t i)
{
  if(i<0 || i>=size)
    {
      std::cout<<"Error: trying to access array element out of bounds"<<std::endl;
      throw("Out of Bounds error");
    }
  return array[i];
}  
int main()
{
  std::cout<<"Declaring array a1 with parameterized constructor"<<std::endl;
  dynamic_array a1(2);
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
  std::cout<<"Length of a2 = "<<a2.length()<<" and of a1 ="<<a1.length()<<std::endl;
  std::cout<<"a2[0] = "<<a2[0]<<std::endl;
  std::cout<<"a2[1] = "<<a2[1]<<std::endl;
  std::cout<<std::endl;

  std::cout<<"Declaring array a3 with parameterized constructor"<<std::endl;
  dynamic_array a3(2);
  std::cout<<"Length of a3 = "<<a3.length()<<std::endl;
  a3[0] = 0.5;
  a3[1] = 1.0;
  std::cout<<"a3[0] = "<<a3[0]<<std::endl;
  std::cout<<"a3[1] = "<<a3[1]<<std::endl;
  std::cout<<std::endl;
  std::cout<<"Now move values from a1 by assignment"<<std::endl;
  dynamic_array a4;
  a4= std::move(a3);
  std::cout<<"Length of a4 = "<<a4.length()<<" and of a3 ="<<a3.length()<<std::endl;
  std::cout<<"a4[0] = "<<a4[0]<<std::endl;
  std::cout<<"a4[1] = "<<a4[1]<<std::endl;
  std::cout<<std::endl;
  return 0;
}
