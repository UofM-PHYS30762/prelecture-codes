// PL9/usingheader.cpp
// Example of including a header file
// Niels Walet, Last modified 06/01/2022
#include<iostream>
#include "myclass.h"

using namespace namespace1;
using namespace std;
void my_class::show()
{
  cout<<"x="<<x<<endl;
}
int main()
{
  my_class c1{1};
  c1.show();
  return 0;
}
