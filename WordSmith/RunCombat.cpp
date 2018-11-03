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
using Globals::low_bound;
using Globals::high_bound;
using Globals::deck_size;

void PrintInfo(Entity E1) {
  cout << E1.ReturnName() << endl;;
}



void PlayCombat(Player P, Entity Enemy) {
  int win; //declare out of loop to save mem
  string player_choice;
  string computer_choice;
  while(P.GetHealth()>0 && Enemy.GetHealth()>0) {
    player_choice = P.GetAction();//GetPlayerInput();
    computer_choice = Enemy.GetAction();
    cout << "Player entered " << player_choice << "..." << endl;
    cout << "PC entered " << computer_choice << "..." << endl;
    win = DetermineWinner(player_choice, computer_choice);
    if (win == -1) { //NEED TO ENUM THESE
      cout << "the battle continues" << endl;
    }
    if (win == 0) {
      cout << "The hero is hurt!" << endl;
      P.TakeDamage(1);
    }
    if (win == 1) {
      cout << "The hero strikes a blow!" << endl; //against whom? We have these fields in our objects...
      Enemy.TakeDamage(1);
    }
  }
  cout << "The battle concludes..." << endl;
  cout << "Only the ";
  if (P.GetHealth()> 0) {cout << P.ReturnName();}
  else if (Enemy.GetHealth() > 0) {cout << Enemy.ReturnName();}
  cout << " still stands." << endl;
}

int main() {
  quick_strings.insert(quick_strings.begin(), "quick");
	heavy_strings.insert(heavy_strings.begin(), "heavy");
	shield_strings.insert(shield_strings.begin(), "block");
  dodge_strings.insert(dodge_strings.begin(), "dodge");

  cout << "Welcome to Wordsmith!" << endl;
  cout << "Medieval Rock, paper, scissors, gunpowder..." << endl;
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


  PlayCombat(P, Evil);
  //P.setHealth=10
  PlayCombat(P, Death);
  //P.setHealth=10
  PlayCombat(P, Who);
return 0;
}


