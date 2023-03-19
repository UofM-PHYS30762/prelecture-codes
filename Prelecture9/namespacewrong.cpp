#include<iostream>
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
int main() 
{  
  return 0; 
}
