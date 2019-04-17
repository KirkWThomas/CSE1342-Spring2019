#include <iostream>
#include <exception> // used for runtime_error and exception type

using namespace std;

int main() {
  int cost;
  int numItems;
  try {
    cout << "Enter the price of your item: $";
    cin >> cost;

    if (cost < 0) {
      throw runtime_error("Cost is < 0");
    }

    cout << "How many items did you purchase? ";
    cin >> numItems;

    if (numItems < 0) {
      throw runtime_error("Number of Items is < 0");
    }

    cout << "Total Cost: " << cost * numItems << endl;
  } catch (exception &e) {
    cout << e.what() << endl;
  }
  

  return 0;
}