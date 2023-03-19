// PL9/myproject.cpp
// Using class with namespace defined in header
// Niels Walet, Last modified 03/12/2019
#include<iostream>
#include "myclass.h"
int main()
{
  namespace1::my_class c1(1);
  c1.show();
  return 0;
}
