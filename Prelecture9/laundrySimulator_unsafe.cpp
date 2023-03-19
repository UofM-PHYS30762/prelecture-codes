// PL9/laundrysimulator.cpp
// Example using static data members
// Caterina Doglioni, Last modified 16/03/2023
#include<iostream>
#include<string>

class laundry_appliance
{
private:
  static bool is_appliance_running; 

public:
  //HEALTH WARNING: NEVER HAVE PUBLIC DATA MEMBERS! This goes against the encapsulation principle
  laundry_appliance() {} // starts turned off
  virtual ~laundry_appliance() {is_appliance_running = 0;} // turns appliance off 
  virtual void start_cycle() = 0;
  virtual void stop_cycle() = 0;
  
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

   std::string check_if_running() {

    std::string outputStr;

    //here we're using a conditional operator to try new things out
    //Exp1 ? Exp2 : Exp3; 
    //the question mark wonders whether Exp1 is true, Exp2 is used if it's true, Exp3 is if it's false
    outputStr =  is_appliance_running ? "Washing machine is running." : "Washing machine is not running.";
    return outputStr;

   }
  
};

class dryer : public laundry_appliance
{
private: 
  //nothing here, we inherit from the base class
public:
  virtual void start_cycle() 
  {
    std::cout << "Dryer is now drying, low whirrrrrrrr."  << std::endl;
    is_appliance_running = 1; //
  } 

  virtual void stop_cycle() 
  {
    std::cout << "Stopping the dryer, fading low whirrrrrrrr." << std::endl;
    is_appliance_running = 0; //

  }
  
  
};

//I can access static variables outside the class!
void smarthome_app_check_if_running() 
{

    std::string outputStr;
    outputStr =  laundry_appliance::is_appliance_running ? "An appliance is running." : "No appliance is running.";
    std::cout << outputStr << std::endl;

}

int main()
{
  laundry_appliance* my_washer = new washing_machine();
  my_washer->start_cycle();
  smarthome_app_check_if_running();
  my_washer->stop_cycle();
  smarthome_app_check_if_running();
  laundry_appliance* my_dryer = new dryer();
  my_dryer->start_cycle();
  smarthome_app_check_if_running();
  my_dryer->stop_cycle();
  smarthome_app_check_if_running();

  //now the appliances get deleted
  delete my_washer;
  delete my_dryer;
 
  smarthome_app_check_if_running();

  //let's build a launderette! 

  return 0;
}
