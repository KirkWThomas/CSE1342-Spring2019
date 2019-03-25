#include <iostream>
#include "LinkedList.h"

using namespace std;

int main() {
  LinkedList *list = new LinkedList();

  list->pushBack(10);
  list->pushBack(15);

  list->print();

  // delete
  cout << "\nRemove" << endl;
  list->remove();
  list->print();

  return 0;
}