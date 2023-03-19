// PL9/laundrysimulator.cpp
// Example using static data members
// Caterina Doglioni, Last modified 16/03/2023
#include<iostream>
#include<string>
#include <random>

class laundry_appliance
{
protected:
  static bool is_appliance_running; 
public:
  laundry_appliance() {} // starts turned off
  virtual ~laundry_appliance() {is_appliance_running = 0;} // turns appliance off 
  virtual void start_cycle() = 0;
  virtual void stop_cycle() = 0;
  static const bool check_if_appliance_running() 
  {
    return is_appliance_running;
  }
  
};

bool laundry_appliance::is_appliance_running{}; // define static data member outside class!

class washing_machine : public laundry_appliance
{
private: 
  //nothing here, we inherit from the base class
public:
  void start_cycle() 
  {
    std::cout << "Washing machine is now washing, swooooooosh." << std::endl;
    is_appliance_running = 1; //
  } 

  void stop_cycle() 
  {
    is_appliance_running = 0; //
    std::cout << "Stopping the washing machine, fading swooooooosh." << std::endl;

  }
  
};

class dryer : public laundry_appliance
{
private: 
  //nothing here, we inherit from the base class
public:
  virtual void start_cycle() 
  {
    std::cout << "Dryer is now drying, low whurrrrrrrr."  << std::endl;
    is_appliance_running = 1; //
  } 

  virtual void stop_cycle() 
  {
    std::cout << "Stopping the dryer, fading low whurrrrrrrr." << std::endl;
    is_appliance_running = 0; //

  }
  
  
};

//I can access static functions that access static variables outside the class
//and independently of the existence of any class objects!
bool smarthome_app_check_if_appliance_running() 
{

  //Let's try something new - ternary operator
  //...but don't abuse it (readability is important)
  // https://isocpp.org/wiki/faq/coding-standards#ternary-op
    std::string outputStr;
    outputStr =  laundry_appliance::check_if_appliance_running() ? "An appliance is running." : "No appliance is running.";
    std::cout << outputStr << std::endl;
    return laundry_appliance::check_if_appliance_running();

}

int main()
{
  laundry_appliance* my_washer = new washing_machine();
  my_washer->start_cycle();
  smarthome_app_check_if_appliance_running();
  my_washer->stop_cycle();
  smarthome_app_check_if_appliance_running();

  laundry_appliance* my_dryer = new dryer();
  my_dryer->start_cycle();
  smarthome_app_check_if_appliance_running();
  my_dryer->stop_cycle();
  smarthome_app_check_if_appliance_running();

  //now the appliances get deleted as we are done
  delete my_washer;
  delete my_dryer;


  //is it savings hour? From the energy supplier's website
  // "We can say that the Sessions will usually take place during the busiest times of day, 
  // because that's when the grid generally needs more help balancing. 
  // The ‘peak’ time is usually between 4-7pm...""
  // So let's use a random number generator to tell us what time it is
  // Using example from https://en.cppreference.com/w/cpp/numeric/random
  std::random_device rd;  // Will be used to obtain a seed for the random number engine
  std::mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
  std::uniform_int_distribution<> what_is_the_time_in_hours(0, 24); // This is a templated class, so see next video! 
  int time_in_hours = what_is_the_time_in_hours(gen);
  if (time_in_hours >= 4  && time_in_hours < 7) 
  {
    std::cout << "It's " << time_in_hours << ":00 so it's savings hour." << std::endl;
    if (smarthome_app_check_if_appliance_running()) 
    {
      std::cout << "Your appliances are running! Go home and turn them off!" << std::endl;
    }
    else 
    {
      std::cout << "Your appliances are not running, you're doing a good job with saving hour." << std::endl;
    }
  }
  else 
  {
    std::cout << "It's " << time_in_hours << ":00 so it's not saving hour. Keep doing laundry, if you wish. " << std::endl;
  }

  smarthome_app_check_if_appliance_running();
  
  //let's build a launderette! 

  return 0;
}
