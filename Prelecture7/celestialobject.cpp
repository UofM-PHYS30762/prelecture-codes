// PL7/celestialobject.cpp
// The definition of outr basic celestial object class
// Source: Prof. Niels Walet's code repository
#include<iostream>
#include<string>
class celestial_object 
{
private:
  std::string name;
  double mass, distance, luminosity; // for compactness
public:
  celestial_object() : 
    name{"no-name"}, mass{}, distance{}, luminosity{} {}
  celestial_object(const std::string nm, const double l, const double m, const double d) :
    name{nm}, mass{m}, distance{d}, luminosity{l} {}
  ~celestial_object(){}
  std::string celestial_object_name() {return name;}
  friend std::ostream& operator<<(std::ostream&, const celestial_object& );
};
std::ostream& operator<<(std::ostream& o, const celestial_object& co)
{o <<" object "<<co.name <<": "<<std::endl
   <<" mass "<<co.mass <<" Msun,"
   <<" luminosity "<<co.luminosity <<" ,"
   <<" distance (z) "<<co.distance <<std::endl;
    return o;}
int main() {
  celestial_object LMC{"Large Magellanic Cloud",-1,2e10,0.000875};
  std::cout <<LMC;
  return 0;
}
