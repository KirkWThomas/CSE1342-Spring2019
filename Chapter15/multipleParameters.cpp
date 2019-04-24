#include <iostream>

using namespace std;

template<typename T1, typename T2>
void print(T1 val1, T2 val2) {
  cout << "Val 1: " << val1 << endl;
  cout << "Val 2: " << val2 << endl;
}

int main() {
  print(1, "hello");
  
  return 0; 
}