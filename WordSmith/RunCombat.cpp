#include "combat.h"
#include "Entity.h"
#include "Player.h"

#include <string>
#include <cstdlib>

using std::cout;
using std::cin;
using std::endl;


int main() {
  //cout << "Welcome to Wordsmith!" << endl;
  //cout << "Basically rock paper scissors for now" << endl;
  //cout << "Choose: 'quick' or 'heavy' or 'shield' " << endl;
  enum enum_of_entity_ {player, beast, undead, humanoid};

  Entity Hero(player);
  Entity Evil(beast);
  Entity Death(undead);
  Entity Who(humanoid);
  Player P(player);
  cout << Hero.ReturnName() << " has "  << Hero.GetHealth() << " health left!" << endl;
  cout << Evil.ReturnName() << " has "  << Evil.GetHealth() << " health left!" << endl;
  cout << Death.ReturnName() << " has "  << Death.GetHealth() << " health left!" <<endl;
  cout << Who.ReturnName() << " has "  << Who.GetHealth() << " health left!" << endl;
  cout << P.ReturnName() << " has " << P.GetHealth() << " health left!" << endl;

/*
  srand((int)time(0));
  string player_choice;
  string computer_choice;

  while(true) {
      player_choice = GetPlayerInput();
      computer_choice = GeneratePCInput();
      cout << "Player entered " << player_choice << "..." << endl;
      cout << "PC entered " << computer_choice << "..." << endl;
      DetermineWinner(player_choice, computer_choice);

  }

*/

return 0;
}
