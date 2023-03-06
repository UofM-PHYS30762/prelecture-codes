//PL5/aclass.cpp
// Populated class for 3 vectors

#include <iostream>

class vector3
{
private:
    double x{};
    double y{};
    double z{};
public:
    //Constructor
    vector3() = default;
    vector3(double x_in, double y_in, double z_in) : x{x_in}, y{y_in}, z{z_in} {};
    ~vector3() {std::cout<<"Destroying vector3"<<std::endl;}

    //access func to set and get vector components

    void set_x(const double x_in) {x = x_in;}
    void set_y(const double y_in) {y = y_in;}
    void set_z(const double z_in) {z = z_in;}

    double get_x() const {return x;}
    double get_y() const {return y;}
    double get_z() const {return z;}

    //func to print out vector
    void show() const {std::cout<<"("<<x<<" , "<<y<<" , "<<z<<")"<<std::endl;}
    //func to add a scalar component to each vector component
    void add_scalar(const double scalar_in) {x += scalar_in; y += scalar_in; z += scalar_in;}
    double dot_pridct (const vector3&v) const
    {
        double result = x*v.get_x() + y*v.get_y() + z*v.get_z();
        return result;}

};

double dot_product(const vector3 &v1, const vector3 &v2)
{
    double result = v1.get_x()*v2.get_x() + v1.get_y()*v2.get_y() + v1.get_z()*v2.get_z();
    return result;
}

int main()
{
    vector3 a;
    vector3 b{1,2,3};
    vector3 c{4,5,6};

    //print vectors
    a.show();
    b.show();
    c.show();

    //add a sclaar to each comp
    double s{1.5};
    b.add_scalar(s);
    b.show();

    //dot product using normal func 

    double dp=dot_product(b,c);
    std::cout<<"Dot product = "<<dp<<std::endl;
    return 0;
}