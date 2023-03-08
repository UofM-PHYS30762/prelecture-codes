// PL7/neutronstar.cpp
// Use inheritance on a star object to define a neutron star
// inheritance: celestial_object->star->neutron_star
// Source: Prof. Niels Walet's code repository
#include<iostream>
#include<string>
class celestial_object
{
protected:
  std::string name {"no_name"};
  double mass {};
  double distance {};
  double luminosity {};
public:
  celestial_object() = default; 
  celestial_object(const std::string nm, const double l, const double m, const double d) :
    name{nm}, mass{m}, distance{d}, luminosity{l} {}
  ~celestial_object(){}
  std::string get_name() const {return name;} 
  friend std::ostream& operator<<(std::ostream& , const celestial_object& );
};
class star: public celestial_object 
{
protected:
  std::string spectral_class {"None"};
public:
  star() : 
    celestial_object{},spectral_class{"None"} {}
  star(const std::string nm, const double l, const double m, const double d,
	 const std::string sc) :
    celestial_object{nm,l,m,d}, spectral_class{sc}{}
  ~star(){}
  friend std::ostream& operator<<(std::ostream&, const star& );
};
class neutron_star: public star 
{
protected:
  double radius ; // radius in km
public:
  neutron_star() : 
    star{}, radius{} {spectral_class="pulsar";}
  neutron_star(const std::string nm, const double l, const double m, const double d,
	       const double r) :
    star{nm, l, m, d, "pulsar"}, radius{r} {}
  ~neutron_star(){}
  friend std::ostream& operator<<(std::ostream& , const neutron_star& );
};
std::ostream& operator<<(std::ostream& o, const neutron_star& st)
{
  o <<" neutron star "<<st.name <<": "<<std::endl
    <<" radius "<<st.radius<<" Rsun" <<std::endl;
  o << static_cast<star>(st);
  return o;
}
std::ostream& operator<<(std::ostream& o, const star& st) 
{
  o <<" spectral class "<<st.spectral_class<<std::endl;
  o << static_cast<celestial_object>(st);
  return o;
}
std::ostream& operator<<(std::ostream& o, const celestial_object& co)
{
  o <<" mass "<<co.mass <<" Msun,"
   <<" luminosity "<<co.luminosity <<" ,"
   <<" distance (z) "<<co.distance <<std::endl;
  return o;
}
double parsectoz(const double dist) {return 2.37E-10*dist;}
int main()
{
  neutron_star crab ("crab",  0, 1.4, parsectoz(2200),1.437815e-5) ;
  std::cout << crab;
  return 0;
}
