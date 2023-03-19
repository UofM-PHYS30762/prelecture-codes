// PL9/staticdata.cpp
// Example using static data members
// Niels Walet, Last modified 03/02/2020
#include<iostream>
class my_class
{
private:
  int x{};
  static int n_objects; 
public:
  my_class() : x{} {n_objects++;}
  my_class(int x_in) : x{x_in} {n_objects++;}
  ~my_class() {n_objects--;}
  void show() {std::cout<<"x="<<x<<", n_objects="<<n_objects<<std::endl;}
};
int my_class::n_objects{}; // define static data member outside class!
void test() 
{
  my_class a3{3};
  a3.show();
}
int main()
{
  my_class a1{1};
  a1.show();
  my_class a2{2};
  a2.show();
  test();
  a1.show();
  return 0;
}
