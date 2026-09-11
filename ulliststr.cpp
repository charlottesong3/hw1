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
    Item* newItem = new Item;
    head_ = newItem;
    tail_ = newItem;
    //no array, so make one, only one space so make both pointers
    // point to same place
  }
  else{
    if(tail_-> last == ARRSIZE){ //checking if tail's next element is in capacity
      Item* newString = new Item;
      tail_ -> next = newString;
      newString -> prev = tail_;
      tail_ = newString;
      
    }
  }
  tail_ -> val[tail_ -> last] = val;
  tail_ -> last++;
  

  size_++;
}

void ULListStr::push_front(const std::string& val){
  if(empty()){ //basically just copying push_back but flipped
    Item* newI = new Item;
    head_ = newI;
    tail_ = newI;

    head_->first = ARRSIZE;
    head_->last = ARRSIZE;
  }

  else if(head_->first == 0){
    Item* newI = new Item;
    newI->first = ARRSIZE;
    newI->last = ARRSIZE;

    newI -> next = head_;
    head_->prev = newI;
    head_ = newI;
  }

  head_->first--; //new head so need to move 
  head_->val[head_->first] = val;

  size_++; //increment
}

void ULListStr::pop_back(){
  if (empty()){
    return;
  }

  tail_->last--;
  size_--;

  // Delete the node if it is now empty.
  if(tail_->first == tail_->last){
    Item* oldTail = tail_;
    tail_ = tail_->prev;
    delete oldTail;

    if(tail_ == NULL){
      head_ = NULL;
    }
    else{
      tail_->next = NULL;
    }
  }

}

void ULListStr::pop_front(){
  if(empty()){
    return;
  }

  head_-> first++;
  size_--;

  // now empty so bye node 
  if(head_ -> first == head_ -> last){
    Item* oldHead = head_;
    head_ = head_->next;
    delete oldHead;

    if(head_ == NULL){
      tail_ = NULL;
    }


    else{
      head_->prev = NULL;
    }
  }
}

std::string* ULListStr::getValAtLoc(size_t loc) const{
  if(loc >= size_){ 
    //check if location is within size (aka if its even possible to find)
    return NULL;
  }

  Item* current = head_;

  while(current != NULL){
    size_t valuesInNode = current->last - current->first;

    if(loc < valuesInNode){
      return &(current->val[current->first + loc]);
    }

    loc -= valuesInNode;
    current = current->next;
  }

  return NULL;
}

std::string const& ULListStr::back() const
{
  // last is exclusive, so the final value is at last - 1.
  return tail_->val[tail_->last - 1];
}

std::string const& ULListStr::front() const
{
  return head_->val[head_->first];
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


