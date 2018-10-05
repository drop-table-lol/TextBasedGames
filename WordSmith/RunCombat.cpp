#include "combat.h"

#include <string>
#include <cstdlib>

using std::cout;
using std::cin;
using std::endl;


int main() {
  cout << "Welcome to Wordsmith!" << endl;
  cout << "Basically rock paper scissors for now" << endl;
  cout << "Choose: 'quick' or 'heavy' or 'shield' " << endl;

  srand((int)time(0));
  string player_choice;
  string computer_choice;

  while(true) {
      player_choice = GetPlayerInput();
      computer_choice = GeneratePCInput();
      cout << "Player entered " << player_choice << "..." << endl;
      cout << "PC entered " << computer_choice << "..." << endl;
      DetermineWinner("quick", computer_choice);

  }



return 0;
}
