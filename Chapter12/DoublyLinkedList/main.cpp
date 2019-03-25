#include <iostream>
#include "LinkedList.h"

using namespace std;

int main() {
  LinkedList *list = new LinkedList();

  list->pushBack(10);
  list->pushBack(15);
  list->prepend(20);

  list->print();
  cout << endl;
  list->printReverse();

  return 0;
}