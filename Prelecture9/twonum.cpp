// PL9/twonum.cpp
// Define a class to hold a pair of numbers
// Niels Walet, Last modified 03/12/2019
#include<iostream>
class pair_of_numbers
{
private:
  int x;
  int y;
public:
  pair_of_numbers() : x{},y{} {}
  pair_of_numbers(int xx, int yy) : x{xx},y{yy} {}
  int add() {return x+y;}
  int sub() {return x-y;}
};
int main()
{
  int x{1},y{2};
  pair_of_numbers ip{x,y};
  std::cout<<"x+y="<<ip.add()<<std::endl;
  std::cout<<"x-y="<<ip.sub()<<std::endl;
  return 0;
}
