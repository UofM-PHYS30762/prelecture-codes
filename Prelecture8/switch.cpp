// PL8/enum.cpp
// Demonstrate use of switch
// Caterina Doglioni, Last modified 14/03/2024
// taken from HSF C++ course, B. Gruber and S. Hageboeck
// https://indico.cern.ch/event/1266661/attachments/2711308/4694049/Essentials.pdf

#include<iostream>
#include<vector>
#include<string>

int main () {

  // the reason why I use CamelCase here is that 
  // there is also an enum class (out of the scope of this course)
  // so I identify an enum more with a class than with variable
  enum LanguageType {
        ENGLISH = 0, //note the comma, not the semicolon
        GERMAN = 1, //the ints here can be anything you choose
        FRENCH = 2,
  };

  int language = GERMAN;

  switch (language) {
    case ENGLISH:
      std::cout << "Good morning" << std::endl;
      break;
    case GERMAN:
      std::cout << "Guten Tag" << std::endl;
      break;
    case FRENCH:
      std::cout << "Bonjour" << std::endl;
    break;
    default:
      std::cout << "I do not speak your language";
  }

}