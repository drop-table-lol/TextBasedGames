#include <iostream> //for write to console
using namespace std;  //TODO implement empty namespace -> Google standard
/* 	Health Decrement.cpp
**	Use with CheatEngine to practice finding values.
**	User has successfuly completed when the Hero's health increments rather than decrements.
**	V1.0.1 uses int pointers and pass by reference
*/

void decrementHealth(int * h) {
  *h = *h-1;  //interestingly, postdecrement did not work here... *h--; Is decrement higher precedence than pointer dereference?
  return;
}

void printHealth(int *h) {
  cout << *h << " health left!"<< endl;
  return;
}


int main() {
  int ihealth = 100;  //set value pointed to health to 100
  int * health;  //First level of obfuscation. Pointer dereferencing
  health = &ihealth;  //address of ihealth stored in health
  char inputstr[5];
  while (true){
    cin >> inputstr;  //wait for input (buffer overflow anyone?)
    decrementHealth(health);  //decrease value of health by 1, passing the pointer
    printHealth(health);  //display value to user passing the pointer
  }
  return 0;
}


