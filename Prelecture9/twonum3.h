// PL9/twonum3.h
// Header file to define a class template to hold a pair of numbers
// Niels Walet, Last modified 03/12/2019
#ifndef TWO_NUM_H // Will only be true the once!
#define TWO_NUM_H
namespace two_num
{
  template <class c_type> class pair_of_numbers {
  private:
    c_type x;
    c_type y;
  public:
  pair_of_numbers() : x{},y{} {};
  pair_of_numbers(const c_type xx, const c_type yy) : x{xx},y{yy} {};
    c_type add();
    c_type sub();
  };
}
using namespace two_num;
template<class c_type> c_type pair_of_numbers<c_type>::add() {return x+y;};
template<class c_type> c_type pair_of_numbers<c_type>::sub() {return x-y;};
#endif
