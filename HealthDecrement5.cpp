#include <iostream> //for write to console
using std::cin;
using std::cout;
using std::endl;
/* 	Health Decrement5.cpp
**	Use with CheatEngine to practice finding values.
**	User has successfuly completed when they can increment health rather than decrease it
**  However, there is a monster health value too, which we don't want to increase.
**	V1.0.1 decrements an array of ints, it's your job to know which is the player.
*/

const int hero = 0;
const int monster = 1;
const int checksum = 2;

int main() {
  int health_array[3] = {100, 100, 100};
  char inputstr[5];
  //we'll do strings later, requires extra logic

  while (true) {
  health_array[hero]--;
  health_array[monster]--;
  health_array[checksum]--;
  cout << "Ouch! " << health_array[hero] << " hero health left!" << endl;
  cout << "Ouch! " << health_array[monster] << " monster health left!" << endl;
  if(health_array[monster] > health_array[checksum]) { //player increased wrong health pool
    cout << "Monster has grown too powerful!";
    break;
  }
  cin >> inputstr;  //wait for input (no sanitization) but we're the attacker in this anyway, using cheatEngine
  }
    return 0;
}

