// PL10/lambda1.cpp
// Application of lambda closure
// Adapted  from https://msdn.microsoft.com/en-us/library/dd293608.aspx
// Niels Walet. Last edited 06/01/2022
#include<algorithm>
#include<iostream>
#include<vector>
int main() 
{
  std::vector<int> v;
  for (int i{}; i < 10; i++) v.push_back(i+1);
  // Count the number of even numbers in the vector 
  int even_count = 0;
  std::for_each(v.begin(), v.end(), 
		[&even_count] (int n) 
		{std::cout << n;
		  if (n % 2 == 0) {
		    std::cout << " is even " << std::endl;
		    ++even_count;
		  } else { 
		    std::cout << " is odd " << std::endl; 
		  }
		});
  // Print the count of even numbers to the console.
  std::cout << "There are " << even_count 
  			<< " even numbers in the vector." << std::endl;
}
