/* Write your test code for the ULListStr in this file */

#include <iostream>
#include "ulliststr.h"

int main(int argc, char* argv[])
{
	//testing example given 
	ULListStr dat;
  dat.push_back("7");
  dat.push_front("8"); 
  dat.push_back("9"); 
  std::cout << dat.get(0) << " " << dat.get(1) << " " << dat.get(2) << std::endl; 
  std::cout << dat.size() << std::endl; 

  dat.clear(); 


  dat.push_back("1"); 
  std::cout << "Added 1 to the list and now front is " << dat.front() << std::endl;
  dat.pop_back();
  std::cout << "Removed item" << std::endl;
  dat.push_back("2");
  std::cout << "Added 2 to the list and now back is " << dat.back() << std::endl;
  dat.pop_back();
  std::cout << "Removed item" << std::endl;
	std::cout << "Current list size: " << dat.size() << std::endl; 
  
  //repopulate items in list 
	dat.push_back("7");
  dat.push_front("8"); 
  dat.push_back("9");
  dat.push_back("3");
  dat.push_front("1"); 
  dat.push_back("2");
  std::cout << "List size after adding elements is " << dat.size() << std::endl;
	int size = dat.size(); 
	for(int i = 0; i < size; i++){
		std::cout << "List contains items: " << dat.get(i) << std::endl;
	}
	//testing pop_front
  while(!dat.empty()){
    std::cout << "Popping front item = " << dat.front() << std::endl; 
    dat.pop_front(); 
  }
  std::cout << "Trying to pop an item that doesn't exist" << std::endl;
  dat.pop_front();
  
  std::cout << "Looking at values from front() and back() of empty list: ";
  std::cout << dat.front() << " " << dat.back() << std::endl;
  std::cout << "Repopulating list" << std::endl;
  dat.push_back("7");
  dat.push_front("8"); 
  dat.push_back("9");
  dat.push_back("3");
  dat.push_front("1"); 
  dat.push_back("2");
  
  //testing pop_back function 
	while(!dat.empty()){
    std::cout << "Popping back item = " << dat.back() << std::endl; 
    dat.pop_back(); 
  }
  std::cout << "Trying to pop an item that doesn't exist" << std::endl;
  dat.pop_back();

  //testing final item after using all functions
	dat.push_back("100");
  dat.push_front("101");
  std::cout << "List Size is " << dat.size() << std::endl; 
	std::cout << "Items: " << dat.get(0) << " " << dat.get(1) << std::endl; 
	std::cout << "Goodbye!" << std::endl;
  
  return 0;
}
