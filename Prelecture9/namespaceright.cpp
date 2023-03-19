// PL9/namespaceright.cpp
// User defined namespaces and resolution
// Niels Walet, Last modified 06/01/2022
#include<iostream>
namespace namespace1 {
  const double ab{1.5};
  class my_class
  {
  private:
    int x;
  public:
    my_class() : x{} {} 
    my_class(int xx) : x{xx} {}
    ~my_class(){}
    void show(){std::cout<<"x="<<x<<std::endl;}
  };
}
namespace namespace2
{
  const double ab{2.5};
  class my_class
  {
  private:
    int x,y;
  public:
    my_class() : x{},y{} {} // shorter method!
    my_class(int xx, int yy) : x{xx},y{yy} {}
    ~my_class(){}
    void show(){std::cout<<"x="<<x<<", y="<<y<<std::endl;}
  };
}
int main()
{
  namespace1::my_class c1{1}; // utilizes my_class from namespace1
  c1.show();
  namespace2::my_class c2{1,2}; // now different my_class from namespace2
  c2.show();
  return 0;
}
