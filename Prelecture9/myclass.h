// PL9/myclass.h
// header file for class definition; also defined namespace
// Niels Walet, Last modified 06/01/2022
#ifndef MY_CLASS_H // Will only be true the once!
#define MY_CLASS_H
namespace namespace1 {
  class my_class
  {
  private:
    int x;
  public:
    my_class() : x{} {} 
    my_class(int xx) : x{xx} {}
    ~my_class(){}
    void show();
  };
}
#endif
