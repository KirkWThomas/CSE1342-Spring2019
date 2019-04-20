#include <iostream>
#include <cstring>

using namespace std;

int stringLength(char word[]) {
  int i = 0;
  while (word[i] != '\0') {
    i++;
  }

  return i;
}

int main() {
  char word[] = "hello";

  cout << "Our String Length: " << stringLength(word) << endl;
  cout << "strlen: " << strlen(word) << endl;

  return 0;
}