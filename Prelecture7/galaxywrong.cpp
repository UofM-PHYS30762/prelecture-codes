// PL7/galaxywrong.cpp
// Use inheritance THE WRONG WAY. This does not compile
// inheritance: celestial_object->galaxy
// Source: Prof. Niels Walet's code repository
#include<iostream>
#include<string>
class celestial_object
{
private:
  std::string name;
  double mass;
  double distance;
  double luminosity;
public:
  celestial_object() : 
    name{"no-name"}, mass{}, distance{}, luminosity{} {}
  celestial_object(const std::string nm, const double l, const double m, const double d) :
    name{nm}, mass{m}, distance{d}, luminosity{l} {}
  ~celestial_object(){}
  std::string getname() const {return name;} 
  friend std::ostream& operator<<(std::ostream&, const celestial_object& );
};
class galaxy: public celestial_object
{
private:
  std::string hubble_type;
public:
  galaxy() : 
    hubble_type{"Sc"}
  {name="no-name"; luminosity=0; mass=1e12; distance=0;}
  galaxy(const std::string nm, const double l, const double m, const double d,
	 const std::string ht) :
    hubble_type{ht}
  {name=nm; luminosity=l; mass=m;distance=d;}
  ~galaxy(){}
  friend std::ostream& operator<<(std::ostream& , const galaxy& );
};
std::ostream& operator<<(std::ostream& o, const galaxy& gx)
{
  o <<" galaxy "<<gx.getname() <<": "<<std::endl
   <<" Hubble type "<<gx.hubble_type<<std::endl;
    return o;
}
std::ostream& operator<<(std::ostream& o, const celestial_object& co)
{
  o <<" mass "<<co.mass <<" Msun,"
   <<" luminosity "<<co.luminosity <<" ,"
   <<" distance (z) "<<co.distance <<std::endl;
    return o;
}
int main()
{
  galaxy LMC{"Large Magellanic Cloud",-1,2e10,0.000875,"SBm"};
  std::cout <<LMC;
  return 0;
}
