#include <iostream>
#include <exception>

using namespace std;

int main() {
  try { 
    cout << "Starting Program..." << endl;

    throw runtime_error("Error");

    cout << "Continue..." << endl;
  } catch (exception& e) {
    cout << e.what() << endl;
  }

  return 0;
}