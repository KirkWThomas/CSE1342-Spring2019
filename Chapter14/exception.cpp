#include <iostream>
#include <exception>

using namespace std;

int main() {
  try { 
    cout << "Starting Program..." << endl;

    throw 1;

    cout << "Continue..." << endl;
  } catch (exception& e) {
    cout << e.what() << endl;
  } catch (int &error) {
    cout << "Error Code: " << error << endl;
  } catch (...) {
    cout << "An Error Occured" << endl;
  }

  return 0;
}