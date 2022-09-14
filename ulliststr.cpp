#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE
void ULListStr::push_back(const std::string& val){
	if(empty()){
    Item* node = new Item(); 
    node -> val[0] = val; 
    node -> first = 0; 
    node -> last = 1; 
		node -> prev = head_; 
		head_ = node;  
		node -> next = tail_; 
		tail_ = node;   
	}
	else if(tail_->last < ARRSIZE){
    tail_->val[tail_->last] = val;  
		tail_ -> last++; 
	}
  else{
    Item* node = new Item();
		node -> next = NULL; 
		tail_ -> next = node; 
		node -> prev = tail_; 
    node -> val[0] = val; 
    node -> first = 0; 
    node -> last = 1; 
		tail_ = node; 
  }
	size_++; 
}
void ULListStr::push_front(const std::string& val){
	if(empty()){
    Item* node = new Item(); 
    node -> val[9] = val; 
    node -> first = 0; 
    node -> last = 1; 
		node -> prev = head_; 
		head_ = node;  
		node -> next = tail_; 
		tail_ = node;   
	}
	else if(head_->first > ARRSIZE){
    head_->val[head_->first-1] = val;  
		head_ -> first--; 
	}
  else{
    Item* node = new Item();
		node -> prev = NULL; 
		head_ -> prev = node; 
		node -> next = head_; 
    node -> val[ARRSIZE-1] = val; 
    node -> first = ARRSIZE-1; 
    node -> last = ARRSIZE; 
		head_ = node; 
  }
	size_++; 
}
void ULListStr::pop_back(){
	//for no vals 
	if(empty()){
		return; 
	}
	//if there is only one val 
	if(tail_->last-tail_->first==1){
		Item* temp = tail_; 
		tail_=tail_->prev; 
		delete temp; 
	}
	//more than one val 
	else{
		tail_->last--; 
	}
	size_--;
}
void ULListStr::pop_front(){
	//for no vals
	if(empty()){
		return; 
	}
	//if there is only one val
	if(head_->last-head_->first==1){
		Item* temp = head_; 
		head_=head_->next; 
		delete temp; 
	}
	//more than one val
	else{
		head_->first++; 
	}
	size_--; 
}
std::string const & ULListStr::back() const{
	return tail_->val[tail_->last-1]; 
}
std::string const & ULListStr::front() const{
	return head_->val[head_->first]; 
}
std::string* ULListStr::getValAtLoc(size_t loc) const{
	Item* spot = head_; 
	if(loc > size_ || size_ == 0){
		return NULL; 
	}
	else{
		while(loc >= spot->last - spot->first){
			loc -= spot->last-spot->first; 
			if(spot->next == NULL){
				return NULL; 
			}
			spot = spot->next; 
		}
	}
	return &spot->val[spot->first+loc]; 
}
void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}