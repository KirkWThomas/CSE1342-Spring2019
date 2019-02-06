#include <iostream>
#include <string>
using namespace std;

/** Fix the following **/

void callPrintGreeting() {
  printGreeting();
}

// -- move above callPrintGreeting
void printGreeting() {
  cout << "Greeting" << endl;
}

int main() {
  
  callPrintGreeting();

  return 0;
}