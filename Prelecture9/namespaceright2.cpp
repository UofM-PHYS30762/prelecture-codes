// PL9/namespaceright2.cpp
// User defined namespaces and resolution
// Niels Walet, Last modified 03/12/2019
#include<iostream>
namespace namespace1
{
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
    my_class() : x{},y{} {} 
    my_class(int xx, int yy) : x{xx},y{yy} {}
    ~my_class(){}
    void show(){std::cout<<"x="<<x<<", y="<<y<<std::endl;}
  };
}
int main()
{
  using namespace namespace1;
  my_class c1{1};  
  c1.show();
  return 0;
}
