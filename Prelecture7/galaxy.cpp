// PL7/galaxy.cpp
// The definition of a galaxy on top of the celestial object class
// Source: Prof. Niels Walet's code repository
#include<iostream>
#include<string>
class celestial_object 
{
public:
  std::string name;
  double mass, distance, luminosity; //for compactness
public:
  celestial_object() : 
    name{"no-name"}, mass{}, distance{}, luminosity{} {}
  celestial_object(const std::string nm, const double l, const double m, const double d) :
    name{nm}, mass{m}, distance{d}, luminosity{l} {}
  ~celestial_object(){}
  std::string getname() const {return name;} 
  friend std::ostream& operator<<(std::ostream& , const celestial_object& );
};
class galaxy: public celestial_object {
private:
  std::string hubble_type;
public:
  galaxy() : 
    celestial_object{}, hubble_type{"Sc"} {}
  galaxy(const std::string nm, const double l, const double m, const double d,
	 const std::string ht) :
    celestial_object{nm,l,m,d}, hubble_type{ht} {}
  ~galaxy(){}
  friend std::ostream& operator<<(std::ostream& , const galaxy& );
};
std::ostream& operator<<(std::ostream& o, const galaxy& gx)
{o <<" galaxy "<<gx.getname() <<": "<<std::endl
   <<" Hubble type "<<gx.hubble_type<<std::endl;
    return o;
}
std::ostream& operator<<(std::ostream& o, const celestial_object& co)
{o <<" mass "<<co.mass <<" Msun,"
   <<" luminosity "<<co.luminosity <<" ,"
   <<" distance (z) "<<co.distance <<std::endl;
    return o;
}
int main() {
  galaxy LMC{"Large Magellanic Cloud",-1,2e10,0.000875,"SBm"};
  std::cout <<LMC;
  return 0;
}
