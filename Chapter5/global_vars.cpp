#include <iostream>
#include <string>
using namespace std;

const int var = 100;

void printVar() {
  int var = 50;
  cout << var << endl;
}

int main() {
  int var = 75;
  printVar();

  return 0;
}