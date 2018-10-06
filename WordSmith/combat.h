#ifndef FIGHTFIGHTFIGH_H_
#define FIGHTFIGHTFIGH_H_ //combat is a boring name for now...
/*TODO
	Make strings ENUM
	Add timing element
	smarter AI
	enums of ROCK PAPER and SCISSORS, generalize winning logic
	Resolve ties to not be defaulted to player...
*/
#include <string>
#include <cstdlib>
#include <ctime>
#include <string>
#include <iostream>

using std::string;
using std::cin;
using std::cout;
using std::endl;


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
			return "shield";
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

string DetermineWinner(string playerchoice, string pcinput) { //no timing yet.
	if (playerchoice == "quick" && pcinput == "shield") {
		PlayerLoss();
	}
	else if (playerchoice == "shield" && pcinput == "heavy") {
		PlayerLoss();
	}
	else if (playerchoice == "heavy" && pcinput == "quick") {
		PlayerLoss();
	}
	else if (playerchoice == pcinput) {
    cout << "Blades clash, weapons are blunted, heros roar. Nothing happens..." << endl;
	}
	else if (playerchoice != "quick" && playerchoice != "shield" && playerchoice != "heavy") {
    PlayerLoss();
  }
	else {
		PlayerWin();
	}
}

#endif FIGHTFIGHTFIGH_H_
