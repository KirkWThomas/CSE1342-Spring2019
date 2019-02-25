// Basic Euclidean Algorithm 
#include <iostream> 
using namespace std; 
  
// Function to return  
// gcd of a and b 
int gcd(int a, int b) { 
  if (a == 0 && b == 0) 
    return b; 
  return gcd(b % a, a); 
} 
  
int main() { 
  int a = 8, b = 10; 
  cout << "GCD(" << a << ", " << b << ") = " << gcd(a, b)  << endl;
  return 0; 
} 
  
