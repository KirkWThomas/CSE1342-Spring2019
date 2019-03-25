#include <iostream>
#include "LinkedList.h"

void LinkedList::print(){
    Node* temp = this->head;
    
    while(temp){
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

void LinkedList::prepend(int data) {
  Node *newNode = new Node();
  newNode->data = data;

  if (this->head == nullptr) { // list empty
      this->head = newNode;
      this->tail = newNode;
   }
   else {
      newNode->next = this->head;
      this->head->prev = newNode;
      this->head = newNode;
   }
}

void LinkedList::pushBack(int data) {
  Node *newNode = new Node();
  newNode->data = data;

  if (this->head == nullptr) { // list empty
      this->head = newNode;
      this->tail = newNode;
   }
   else {
      this->tail->next = newNode;
      newNode->prev = this->tail;
      this->tail = newNode;
   }
}

void LinkedList::printReverse() {
  Node *curr = this->tail;

  while (curr != nullptr) {
    std::cout << curr->data << " ";
    curr = curr->prev;
  }
  std::cout << std::endl;
}