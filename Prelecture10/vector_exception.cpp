// PL10/vector_exception.cpp
// Example of out-of-bounds issues with vectors (crash vs exception)
// Caterina Doglioni, last updated 20/03/2023

#include<vector>
#include<iostream>

int main () 
{

   //C arrays don't know about exceptions, the code will fail with a segmentation fault (not nice) 
    int myArray[3];
    myArray[1]=1;
    myArray[1]=2;
    myArray[1]=3;
    std::cout << myArray[400000] << std::endl;

    //vector has exceptions built-in so it will throw a helpful error (nicer)
    std::vector<int> myVector;
    myVector.push_back(1);
    myVector.push_back(2);
    myVector.push_back(3);
    std::cout << myVector.at(400000) << std::endl;


    

}
