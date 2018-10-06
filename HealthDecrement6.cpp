#include <iostream> //for write to console
using std::cin;
using std::cout;
using std::endl;
/* 	Health Decrement5.cpp
**	Use with CheatEngine to practice finding values.
**	User has successfuly completed when they can increment health rather than decrease it
**	V1.0.1 decrements an int via inline function, it's your job to know which is the player.
**  A rather tricky version, uses a doubled value of health and prints within the function.
*/

int ConvertToHealth(int health);

int main() {
int doublehealth = 200;
char inputstr[5];
  //we'll do strings later, requires extra logic

  while (true) {
  doublehealth = ConvertToHealth(doublehealth);
  cin >> inputstr;  //wait for input (no sanitization) but we're the attacker in this anyway, using cheatEngine
  }
    return 0;
}


int ConvertToHealth(int health) { //converts the doublehealth value to singlehealth value after subtracting 2
  health -=2;
  cout << "Ouch! " <<health/2 << " hero health left!" << endl;
  return health;
}

