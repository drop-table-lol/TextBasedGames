#include <iostream> //for write to console
using namespace std; //TODO refactor to use local namespace
/* 	Health Decrement4.cpp
**	Use with CheatEngine to practice finding values.
**	User has successfuly completed when they can increment health rather than decrease it
**	V1.0.1 increments within the loop. No function calls.
**  However, it uses several different variable types for health.
*/


int main() {
  int health = 101;
  short short_health = 100;
  float float_health = 99.9;
  char inputstr[5];
  //we'll do strings later, requires extra logic

  while (true) {
  --health;  //arguably an iterated value, could use post-decrement, but it's not really, so according to style guide use pre
  --short_health;  //can you decrement a short? Shorts are ints, right?
  float_health -= 1.0;
  cout << "Ouch! " << health << " left!" << endl;
  cout << "Ouch! " << short_health << " left!" << endl;
  cout << "Ouch! " << float_health << " left!" << endl;
  cin >> inputstr;  //wait for input (no sanitization) but we're the attacker in this anyway, using cheatEngine
  }
    return 0;
}

