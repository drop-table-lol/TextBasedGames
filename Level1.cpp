#include "level1.h"
#include <iostream>
using std::cin;


int main() {
	int villian_health = 100;
	int hero_health = villian_health;
	char input_string[5];

	while(!IS_GAME_OVER) {
		LogicChecks(hero_health, villian_health);
		--hero_health;
		++villian_health;
		PrintHealthInfo(hero_health, villian_health);
		cin >> input_string;
	}
}
