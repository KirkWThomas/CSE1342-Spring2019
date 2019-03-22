#include <iostream>

using namespace std;

class MyClass {
  private:
    int* value;
  public: 
    MyClass();
    ~MyClass();
};

MyClass::MyClass() {
  value = new int(10);
}

MyClass::~MyClass() { 
  cout << "destructor called" << endl;
  delete value;
}

int main() {
  MyClass *newClass = new MyClass;

  delete newClass;

  return 0;
}