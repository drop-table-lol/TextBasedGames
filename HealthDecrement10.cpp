/* C program to Subtract two numbers
** without using arithmetic operators
** taken and modified from stackoverflow,
** this impossible version uses bitshifts 
** within a single function. 
*/
#include<iostream>
using std::cout;
using std::cin;
using std::endl;

int subtract(int x, int y) {
  // Iterate till there
  // is no carry
  while (y != 0) {
    // borrow contains common
    // set bits of y and unset
    // bits of x
    int borrow = (~x) & y;
    // Subtraction of bits of x
    // and y where at least one
    // of the bits is not set
    x = x ^ y;
    // Borrow is shifted by one
    // so that subtracting it from
    // x gives the required sum
    y = borrow << 1;
  }
  return x;
}

// Driver Code
int main()
{
  int health = 100;
  int sub = 1;
  char input_str[5];
  while(health > 0) {
    health = subtract(health, sub);
    cout << "Ouch! " << health << " health left." << endl;
    cin >> input_str;
  }

  return 0;
}
