// PL10/listdemo.cpp
// Application of the list container class
// Niels Walet. Last edited 03/12/2019
#include<iostream>
#include<list>
void print_list(std::list<int> &list_in)
{
  std::cout<<"List contents: ";
  for(auto li=list_in.begin();li!=list_in.end();++li) 
    std::cout<<*li<<" ";
  std::cout<<std::endl;
}
int main()
{
  std::list<int> my_list;
  // Push some on the front
  my_list.push_front(1);
  my_list.push_front(2);
  // and some on the back
  my_list.push_back(3);
  my_list.push_back(4);
  print_list(my_list);
  // Use iterator to identify current position in list
  std::list<int>::iterator li;
  // Insert a new entry in middle of current list
  li=my_list.begin();
  for(int i{};i<2;i++) li++;
  my_list.insert(li,5);
  print_list(my_list);
  // Sort list
  my_list.sort();
  print_list(my_list);
  // Declare a second list
  std::list<int> my_list2;
  for(int i{};i<3;i++) my_list2.push_back(9-i);
  print_list(my_list2);
  // Merge two lists and re-sort
  my_list.merge(my_list2);
  my_list.sort();
  print_list(my_list);
  // Remove first and last entries
  my_list.pop_front();
  my_list.pop_back();
  print_list(my_list);
  return 0;
}
