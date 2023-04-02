// PL10/smart1.cpp
// Example of use of smart pointers (RAII)
// Niels Walet, last updated 06/01/2022
#include <iostream>
#include <memory>
using namespace std;
class my_class
{ 
public:
  my_class() { cout << "my_class c'tor\n"; }
  my_class(const my_class&) { cout << "my_class copy c'tor\n"; }
  my_class(my_class&&) { cout << "my_class move c'tor\n"; }
  ~my_class() { cout << "~my_class d'tor\n"; }
};
class deleter 
{
public:
  deleter() {};
  deleter(const deleter&) { cout << "deleter copy ctor\n"; }
  deleter(deleter&) { cout << "deleter non-const copy ctor\n";}
  deleter(deleter&&) { cout << "deleter move ctor \n"; }
  void operator()(my_class* p) const {
    cout << "deleter is deleting a my_class\n";
    delete p;
  };
};
 
int main()
{
  cout << "Example constructor(1)...\n";
  unique_ptr<my_class> up1;  // up1 is empty
  unique_ptr<my_class> up1b(nullptr);  // up1b is empty
  cout << "Example constructor(2)...\n";
  {
    unique_ptr<my_class> up2(new my_class); //up2 now owns a my_class
  } // my_class deleted
  cout << "Example constructor(3)...\n";
  deleter d;
  {  // deleter type is not a reference
    unique_ptr<my_class, deleter> up3(new my_class, d); // deleter copied
  }
  {  // deleter type is a reference 
    unique_ptr<my_class, deleter&> up3b(new my_class, d); // up3b holds a reference to d
  }
  cout << "Example constructor(4)...\n";
  {  // deleter is not a reference 
    unique_ptr<my_class, deleter> up4(new my_class, deleter()); // deleter moved
  }
  cout << "Example constructor(5)...\n";
  {
    unique_ptr<my_class> up5a(new my_class);
    unique_ptr<my_class> up5b(move(up5a)); // ownership transfer
  }
  cout << "Example constructor(6)...\n";
  {
    unique_ptr<my_class, deleter> up6a(new my_class, d); // deleter is copied
    unique_ptr<my_class, deleter> up6b(move(up6a)); // deleter is moved
 
    unique_ptr<my_class, deleter&> up6c(new my_class, d); // deleter is a reference
    unique_ptr<my_class, deleter> up6d(move(up6c)); // deleter is copied
  }
  cout << "Example constructor(7)...\n";
  {
    unique_ptr<my_class> up7a(new my_class);
    unique_ptr<my_class> up7b(move(up7a)); // ownership transfer
  }
}
