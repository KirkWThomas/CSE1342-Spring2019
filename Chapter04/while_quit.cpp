#include <iostream>

using namespace std;

int main() {
  char input;

  cout << "Enter a number: ";
  cin >> input;

  while (input != 'q') {
    cout << input << endl;

    cout << "Enter a number: ";
    cin >> input;
  }
   

  return 0;
}