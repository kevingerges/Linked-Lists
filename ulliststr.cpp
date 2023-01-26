
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
void ULListStr::push_back(const std::string& val) {
if (empty()) {
	head_ = new Item;
	head_->prev = nullptr;
	head_->next = nullptr;
	tail_ = head_;
	head_->val[head_->last] = val;
	head_->last++;
	size_++;
} 
else if (tail_->last < ARRSIZE) {
	tail_->val[tail_->last] = val;
	tail_->last++;
	size_++;
} 
else {
	Item* new_tail = new Item;
	new_tail->prev = tail_;
	tail_->next = new_tail;
	new_tail->next = nullptr;
	tail_ = new_tail;
	tail_->val[tail_->last] = val;
	tail_->last++;
	size_++;
}
}

void ULListStr::push_front(const std::string& val)
{
	if(empty()){
				head_ = new Item;
				head_->prev = nullptr;
				head_->next = nullptr;
				tail_ = head_;
				head_ -> val[head_ -> first] = val;
				size_++;
				head_ -> last++;
		}
	// in case of head being full 
	else if (head_ -> first == 0 ){

		Item* new_head = new Item;
		new_head -> prev = nullptr;
		new_head->next = head_;
		head_-> prev = new_head;
		head_ = new_head;

		// head_ -> last++;
		head_ -> val[ARRSIZE-1] = val;
		head_-> first = ARRSIZE-1;
		head_-> last = ARRSIZE;
		size_++;
	}
	else {
		head_ -> first--;
		head_ -> val [head_ -> first] = val;
		size_++;

	}
}
// fix head thingy, add to the right instead of left


void ULListStr::pop_back(){
	if (size_ == 0){
		throw std::out_of_range("List is empty");
	}
	 if (head_ == tail_ && head_->last - head_ -> first == 1){
		Item* temp = head_;
		delete temp;
		head_ = nullptr;
		tail_ = nullptr;
		size_--;
	}
	else if (tail_->last  - tail_ -> first == 1) {
		Item* temp = tail_;
		tail_ = tail_->prev;
		tail_->next = nullptr;
		delete temp;
		size_--;
	}
	else {
		tail_->last--;
		size_--;
	}
}

void ULListStr::pop_front(){
	if (size_ == 0){
		throw std::out_of_range("List is empty");
	}
	if (head_ == tail_ && head_->last - head_ -> first == 1){
		Item* temp = head_;
		delete temp;
		head_ = nullptr;
		tail_ = nullptr;
		size_--;
	}
	else if (head_->last - head_ -> first == 1) {
		Item* temp = head_;
		head_->prev = nullptr;
		head_ = head_->next;
		delete temp;
		size_--;
	}
	else {
		head_->first++;
		size_--;
	}
}


std::string const & ULListStr::back() const{
	if (size_ == 0){
		throw std::out_of_range("back is empty.");
	}
	else {
		return tail_ -> val[tail_->last -1];
	}
}

std::string const & ULListStr::front() const{
	if (size_ == 0){
		throw std::out_of_range("front is empty.");
	}
	else {
		return head_ -> val[head_->first];
	}
}

std::string* ULListStr::getValAtLoc(size_t loc) const{

// make a pointer which will helps us traverse
Item * ptr_rtr = head_;

if ( loc >= size_){
throw std::out_of_range("bad loc");
}

if (ptr_rtr == nullptr){
 throw std::out_of_range("bad loc");
}

while (loc >= (ptr_rtr->last - ptr_rtr->first)) {
	if(ptr_rtr->next == nullptr){
		throw std::out_of_range("bad loc");
	}
	loc -= (ptr_rtr->last - ptr_rtr->first);
	ptr_rtr = ptr_rtr->next;
}
return &(ptr_rtr->val[ptr_rtr->first + loc]);
}



// std::string* ULListStr::getValAtLoc(size_t loc) const{
   
//   // make a pointer which will helps us traverse    
//    Item * ptr_rtr = head_;

//    if ( loc >= size_){
//     throw std::out_of_range("bad loc");
//    }

//     if (ptr_rtr == nullptr){
//      throw std::out_of_range("bad loc");
//     }
//   // loop through each array element inside the node
//     for (int i =0; i < ARRSIZE; i++){
//       // if found then return 
//       if (ptr_rtr-> first + i == loc && ptr_rtr->val[i].empty() == false)
//       {
//         if (ptr_rtr -> first + i > ptr_rtr-> last || loc >= ptr_rtr -> last - ptr_rtr->first){
//           break;
//         }
//         // return  &ptr_rtr->val[loc - ptr_rtr->first];
//         return  &(ptr_rtr->val[loc -ptr_rtr->first]);

//     }      
     
//     else {
//       // else move on to the next node
//       ptr_rtr = ptr_rtr -> next;
//     }
    
//    }

// }


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