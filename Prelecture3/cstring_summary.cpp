// PL3/cstring_summary.cpp
// Demonstration of various functionalities of c strings
// Niels Walet and Caterina Doglioni, last updated 04/12/2019

#include<iostream>
#include<cstring>
int main()
{
  const size_t no_char{100}; // Size of array
  char string1[no_char]; //fixed length array to store string
  // Or we can do it this way
  char *string2;
  string2 = new char[no_char];
  // Or we can initialize our array at the same time
  char string3[] = "This is string3";
  // fill arrays with characters by calling strcpy
  strcpy(string1,"This is string1");
  strcpy(string2,"This is string2");
  // Print out strings
  std::cout<<string1<<std::endl;
  std::cout<<string2<<std::endl;
  std::cout<<string3<<std::endl;
  //comparisons
  std::cout<<"comparing string1 and string2: ";
  if(strcmp(string1,string2))
    std::cout<<"strings are not equal"<<std::endl;
  else
    std::cout<<"strings are equal"<<std::endl;
  std::cout<<"comparing string1 with itself :";
  if(strcmp(string1,string1))
    std::cout<<"strings are not equal"<<std::endl;
  else
    std::cout<<"strings are equal"<<std::endl;
  // joining
  strcat(string1,string2);
  std::cout<<"Joined string: "<<string1<<std::endl;
  //copying
  strcpy(string2,string1);
  std::cout<<"Copied string: "<<string2<<std::endl;
  //length
  std::cout<<"Length of string2 = "<<strlen(string2)<<" "<<strlen("")<<std::endl;
  return 0;
}