//Globals.h
#ifndef GLOBALS_H_
#define GLOBALS_H_

#include <vector>
#include <string>
using std::string;
using std::vector;

namespace Globals{
	const int low_bound = 0;
	const int high_bound = 2;
	const int deck_size = 3;
	enum action_categories {quick, heavy, shield, dodge};
	enum action_stats {strength, dexterity, wordsmith};
	vector<string> quick_strings;
	vector<string> heavy_strings;
	vector<string> block_strings;
	vector<string> dodge_strings;
}; //namespace global


#endif // GLOBALS_H_
