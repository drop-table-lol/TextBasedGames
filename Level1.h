//Level1.h

#ifndef LEVEL1_H_
#define LEVEL1_H_
#include <iostream>
using std::cout;
using std::endl;

bool IS_GAME_OVER; //global check

void PrintGreeting() {
	cout << "Welcome to level 1 hero!" << endl;
	cout << "Things are quickly getting complicated..." << endl;
	cout << "For example, every time you beat up this monster, he gets stronger..." << endl;
	cout << "It's almost like he's cheating the system. He reversed the healthdecrement function!" <<endl;
	cout << "Quickly, set his health to something less than zero to make sure you destroy him!" << endl;
}

void PrintHealthInfo(int hero_health, int villian_health) {
	cout << "Ouch! The beasts claws sting our hero..." << endl;
	cout << "Hero health: " << hero_health << endl;
	cout << "Yikes! Looks like the ghastly beast grew stronger!" << endl;
	cout << "Villian health: " << villian_health << endl;
}

void LogicChecks(int hero_health, int villian_health) {
	if (hero_health <=0) {
		cout << "OH NO! Hero dies..." << endl;
		IS_GAME_OVER = true;
	}
	if (villian_health <=0) {
		cout << "Nice work! The beast is slain!" << endl;
		IS_GAME_OVER = true;
	}
}

#endif LEVEL1_H_
