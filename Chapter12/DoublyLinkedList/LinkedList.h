#include "Node.h"

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

class LinkedList {
  public: 
    int length;
    Node *head;
    Node *tail;

    void print();
    void prepend(int data);
    void pushBack(int data);
    void printReverse();
};

#endif