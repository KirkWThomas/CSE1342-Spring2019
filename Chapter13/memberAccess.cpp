#include <iostream>
#include <string>

using namespace std;

class Base {
  private: 
    int date;
  public: 
    string data;
};

class PublicInheritance: public Base {
  public: 
    PublicInheritance() {
      data = 100;
    }
};

class ProtectedInheritance: protected Base {
  public: 
    ProtectedInheritance() {
      data = 100;
    }
};

class PrivateInheritance: private Base {
  public: 
    PrivateInheritance() {
      data = 100;
    }
};


int main() {
  PublicInheritance c1;
  ProtectedInheritance c2;
  PrivateInheritance c3;

  c1.data;
  // c2.data;
  // c3.data;

  return 0;
}