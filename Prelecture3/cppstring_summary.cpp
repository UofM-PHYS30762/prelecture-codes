// PL3/cppstring.cpp
// Demonstration of strings using the modern syntax
// Niels Walet, Caterina Doglioni, last updated 24/01/2023
#include<iostream>
#include<string>
using std::string;
int main() 
{
  string my_first_string{"Hello, world!"};
  std::cout<<my_first_string<<std::endl;
 
  //length
  std::cout << "Length of string = "<<my_first_string.length()<<std::endl;
  //individual character
  std::cout<<"2nd character in string is "<<my_first_string[1]<<std::endl;
 
  //input
  string input_string;
  std::cout<<"Enter a phrase and I will ignore it: "; 
  std::cin>>input_string;  
  std::cin.ignore();
  std::cout<<"Enter a phrase and I will remember it: "; 
  getline(std::cin,input_string);
  std::cout<<"What you entered: " << input_string << std::endl; 
  
  // try matching (but fail)
  string my_second_string{" C++ rocks!"};
  // match
  if(my_first_string == my_second_string) 
    std::cout<<"Strings match!"<<std::endl;

  //join
  string joined_string{my_first_string + my_second_string};
  std::cout<<"Joined string: "<<joined_string<<std::endl;
  
  //append
  my_first_string +=  my_second_string;
  std::cout<<"Appended string: "<<my_first_string<<std::endl;
  
  // extract
  const size_t first{18};
  const size_t last{22};
  string a_word = joined_string.substr(first,last-first+1);
  std::cout<<"Extracting characters "<<first<<"-"<<last<<" from joined string: "<<a_word<<std::endl;
  
  return 0;
}
