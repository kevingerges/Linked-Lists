#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"
#include <iostream>

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
void ULListStr::push_back(const std::string& val)
{
  // if a node is full
  if (tail_->last == ARRSIZE){
    
    // making a new node and adjusting prev and next of both
    Item* new_tail = new Item;
    new_tail -> prev = tail_;
    tail_ -> next = new_tail;
    new_tail -> next = nullptr;
    tail_ =  new_tail;
    
    // adding the value to the array
    tail_ -> val[0] = val;
    tail_-> last = 1;
    size_++;
  }
  else 
  {
    // accesing the element at last index and adding the values
    tail_ -> val [tail_ -> last] =  val;
    tail_ -> last++;
    size_++;

  }
}

void ULListStr::push_front(const std::string& val)
{
  // in case of head being full 
  if (head_ -> last == ARRSIZE){

    Item* new_head = new Item;
    new_head -> prev = nullptr;
    head_ -> next = head_-> next;
    new_head->next = head_;
    head_-> prev = new_head;
    head_ = new_head;

    head_ -> val[0] = val;
    head_ -> last = 1;
    size_++;
  }

  else {

    head_ -> val [head_ -> last] = val;
    head_ -> last++;
    size_++;
    

  }


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


