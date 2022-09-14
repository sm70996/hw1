#include <iostream>
#include <cstddef>
#include "split.h"

using namespace std; 

int main(){
	
	Node z(7, nullptr); 
	Node y(6, &z);
	Node x(4, &y);
	Node w(1, &x); 
	 
	Node* in = &w; 
	Node* odds = nullptr; 
	Node* evens = nullptr; 

	split(in, odds, evens); 

	cout << "Odd Linked List: "; 
	while(odds != nullptr){
		cout << odds->value << " ";
		odds = odds->next;  
	}
	cout << endl; 

	cout << "Even Linked List: "; 
	while(evens != nullptr){
		cout << evens->value << " "; 
		evens = evens->next;  
	}
	cout << endl; 
	
	return 0; 
}