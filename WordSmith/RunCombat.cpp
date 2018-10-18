#include "Entity.h"
#include "Player.h"
#include "WordDeck.h"
#include "Globals.h"
#include "combat.h"

#include <string>
#include <cstdlib>

using std::cout;
using std::cin;
using std::endl;
using namespace Globals;
extern const int low_bound;
extern const int high_bound;
extern const int deck_size;

void PrintInfo(Entity E1) {
  cout << E1.ReturnName() << endl;;
}

int main() {
  quick_strings.insert(quick_strings.begin(), "quick");
	heavy_strings.insert(heavy_strings.begin(), "heavy");
	shield_strings.insert(shield_strings.begin(), "block");
  dodge_strings.insert(dodge_strings.begin(), "dodge");

  cout << "Welcome to Wordsmith!" << endl;
  cout << "Basically rock paper scissors for now" << endl;
  cout << "Choose: 'quick' or 'heavy' or 'block' or 'dodge'" << endl;
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
  //cout << P.ReturnName() << " has " << P.GetHealth() << " health left!" << endl;
  cout << " Let's downcast" << endl;
  PrintInfo(Hero);
  cout << "Let's do it" << endl;
  PrintInfo(P);
/*
  string firedeck[deck_size] = {"firestrike", "fireball", "fireward"};
  Deck D("fire", firedeck);
  cout << D.GetWordsForPrint();
*/

  srand((int)time(0));
  string player_choice;
  string computer_choice;

  while(true) {
    player_choice = Hero.GetAction();//GetPlayerInput();
    computer_choice = Evil.GetAction();
    cout << "Player entered " << player_choice << "..." << endl;
    cout << "PC entered " << computer_choice << "..." << endl;
    DetermineWinner(player_choice, computer_choice);
  }
return 0;
}
