#ifndef FIGHTFIGHTFIGH_H_
#define FIGHTFIGHTFIGH_H_ //combat is a boring name for now...
/*TODO
	Make strings ENUM
	Add timing element
	smarter AI
	enums of ROCK PAPER and SCISSORS, generalize winning logic
	Templa-tize logic for diff types/classes
*/
#include "Globals.h"

#include <string>
#include <cstdlib>
#include <ctime>
#include <iostream>

using std::string;
using std::cin;
using std::cout;
using std::endl;
using namespace Globals; //we use the whole thing...


string GetPlayerInput() {
	string input;
	cin >> input;
	return input;
}

string GeneratePCInput() {
	int choice;
	choice = (rand() % 3);
	switch(choice) {
		case(0):
			return "quick";
		case(1):
			return "block";
		case(2):
			return "heavy"; //no breaks since we're returning out of switch.
  }
}

string PlayerLoss() {
	cout << "You suck!" << endl;
}

string PlayerWin() {
	cout << "You rule!" << endl;
}

bool IsQuickChoice(string choice) {
  for(int i=0; i<quick_strings.size(); i++) {
    if (quick_strings[i] == choice) {
        return true;
    }
  }
  return false;
}

bool IsHeavyChoice(string choice) {
  for(int i=0; i<heavy_strings.size(); i++) {
    if (heavy_strings[i] == choice) {
        return true;
    }
  }
  return false;
}

bool IsBlockChoice(string choice) {
  for(int i=0; i<block_strings.size(); i++) {
    if (block_strings[i] == choice) {
        return true;
    }
  }
  return false;
}

bool IsDodgeChoice(string choice) {
  for(int i=0; i<dodge_strings.size(); i++) {
    if (dodge_strings[i] == choice) {
        return true;
    }
  }
  return false;
}




string DetermineWinner(string playerchoice, string pcinput) { //no timing yet.
	if (IsQuickChoice(playerchoice) && IsBlockChoice(pcinput)) {
		PlayerLoss();
	}
	else if (IsBlockChoice(playerchoice) && IsHeavyChoice(pcinput)) {
		PlayerLoss();
	}
	else if (IsHeavyChoice(playerchoice) && IsQuickChoice(pcinput)) {
		PlayerLoss();
	}
	else if (playerchoice == pcinput) {
    cout << "Blades clash, weapons are blunted, heros roar. Nothing happens..." << endl;
	}
	else if (!IsQuickChoice(playerchoice) && !IsHeavyChoice(playerchoice) && !IsBlockChoice(playerchoice)) {
    PlayerLoss();
  }
	else {
		PlayerWin();
	}
}



#endif FIGHTFIGHTFIGH_H_
