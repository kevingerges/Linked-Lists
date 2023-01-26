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
// first case when it's empty
if (empty()) {
	head_ = new Item;
	head_->prev = nullptr;
	head_->next = nullptr;
	tail_ = head_;
	head_->val[head_->last] = val;
	head_->last++;
	size_++;
} 
// regular adding the the back
else if (tail_->last < ARRSIZE) {
	tail_->val[tail_->last] = val;
	tail_->last++;
	size_++;
} 
// if the case where the array is full
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
	// first case when it's empty
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

		head_ -> val[ARRSIZE-1] = val;
		head_-> first = ARRSIZE-1;
		head_-> last = ARRSIZE;
		size_++;
	}
	// regular adding the the front
	else {
		head_ -> first--;
		head_ -> val [head_ -> first] = val;
		size_++;

	}
}
// fix head thingy, add to the right instead of left


void ULListStr::pop_back(){
	// if there is no elements
	if (size_ == 0){
		throw std::out_of_range("List is empty");
	}
	// if only first node and it's empty
	 if (head_ == tail_ && head_->last - head_ -> first == 1){
		Item* temp = head_;
		delete temp;
		head_ = nullptr;
		tail_ = nullptr;
		size_--;
	}
	// if node it's empty but not one node 
	else if (tail_->last  - tail_ -> first == 1) {
		Item* temp = tail_;
		tail_ = tail_->prev;
		tail_->next = nullptr;
		delete temp;
		size_--;
	}
	// regular popping 
	else {
		tail_->last--;
		size_--;
	}
}

void ULListStr::pop_front(){
	// if there is no elements
	if (size_ == 0){
		throw std::out_of_range("List is empty");
	}
	// if only first node and it's empty
	if (head_ == tail_ && head_->last - head_ -> first == 1){
		Item* temp = head_;
		delete temp;
		head_ = nullptr;
		tail_ = nullptr;
		size_--;
	}
	// if node it's empty but not one node 
	else if (head_->last - head_ -> first == 1) {
		Item* temp = head_;
		head_->prev = nullptr;
		head_ = head_->next;
		delete temp;
		size_--;
	}
	// regular popping 
	else {
		head_->first++;
		size_--;
	}
}


std::string const & ULListStr::back() const{
	// there is not element
	if (size_ == 0){
		throw std::out_of_range("back is empty.");
	}
	// accesing the back 
	else {
		return tail_ -> val[tail_->last -1];
	}
}

std::string const & ULListStr::front() const{
	// there is not element
	if (size_ == 0){
		throw std::out_of_range("front is empty.");
	}
	// accesing the front 
	else {
		return head_ -> val[head_->first];
	}
}
std::string* ULListStr::getValAtLoc(size_t loc) const{

    // make a pointer which will helps us traverse
    Item * ptr = head_;

    if ( loc >= size_){
        throw std::out_of_range("loc out of range");
    }

    if (ptr == nullptr){
        throw std::out_of_range("loc out of range");
    }

    // Traverse through each node
    while(ptr != nullptr){
        // grab the first and last indexs for the node
        size_t cur_first =  ptr->first;
        size_t cur_last =  ptr->last;
        
        // Loop through each value in the array
        for(size_t i=cur_first; i<cur_last; i++){

            // If loc become 0, thats the value
            if(loc == 0){
                return &(ptr->val[i]);
            }
            loc--;
        }

        ptr = ptr->next;
    } 
	return nullptr;

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