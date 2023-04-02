// PL10/mapdemo.cpp
// illustrates the use of the map containetr class
// Niels Walet. Last edited 03/12/2019
#include<iostream>
#include<string>
#include<utility>
#include<map>
// Use alias for our type of map
typedef std::map<int,std::string> international_dial_codes;
void search_database(international_dial_codes &dial_codes, int code_search)
{
  international_dial_codes::iterator dial_codes_iter;
  dial_codes_iter = dial_codes.find(code_search);
  if(dial_codes_iter != dial_codes.end()) 
    std::cout<<"Found country for dial code " 
	     <<code_search << " = "
	     <<dial_codes_iter->second<<std::endl;
  else
    std::cerr<<"Sorry, code " << code_search 
	     <<" is not in database"<<std::endl;
}
int main()
{ 
  // Using map associative container class 
  // (use key to access data)
  // Example: international dial codes
  international_dial_codes dial_codes;
  // New entries using []
  dial_codes[49] = "Germany";
  dial_codes[44] = "United Kingdom";
  // Can also insert a pair
  dial_codes.insert(std::pair<int,std::string>(672,"Christmas Island"));
  // How many entries so far?
  std::cout<<"Size of database = "<<dial_codes.size()<<std::endl;
  // Print out database - note sorted by codes!
  international_dial_codes::iterator dial_codes_iter;
  for(dial_codes_iter  = dial_codes.begin();
      dial_codes_iter != dial_codes.end();
      ++dial_codes_iter)
    std::cout<<"Dial code: " << dial_codes_iter->first  
	     <<", country: " << dial_codes_iter->second << std::endl;
  // What country has code 672? Let's find out (uses iterator)
  int code_search(672);
  search_database(dial_codes,code_search);
  // Again for a code not stored
  code_search = 673;
  search_database(dial_codes,code_search);
  return 0;
}

