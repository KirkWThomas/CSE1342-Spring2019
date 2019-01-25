#include <iostream>

using namespace std;

int main() {
  int tacos = 10;
  int people = 4;
  int quotient = tacos / people;
  cout << "Tacos / Person w/o casting: " << quotient << endl;

  double doubleQuotient = (double)tacos / (double)people;
  cout << "Tacos / Person w/ casting: " << doubleQuotient << endl;

  return 0;
}