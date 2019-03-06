#include <iostream>
#include <string>

using namespace std;

class Employee {
  public:
    // TODO: Declare Default Constructor

    void Print();
    
  private:
    int employeeNum;
    string name;
};

// TODO: Implement Default Constructor

void Employee::Print() {
  cout << name << " - " << employeeNum << endl;
}

int main() {
  Employee accountant;
  accountant.Print();

  return 0;
}