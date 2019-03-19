#include <iostream>

int main()
{
  int *ptr;
  
  ptr = new int;
  // *ptr = 100;

  std::cout << *ptr << std::endl;

  return 0;
}