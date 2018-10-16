//WordDeck.h
//keep it simple for now. Add randomness and dynamic allocation later.

#ifndef WORDDECK_H_
#define WORDDECK_H_
#include "Globals.h"

#include <string>

using std::string;
using Globals::deck_size;

class Deck{
  private:
	string available_words_[deck_size];
	string power_word_;

  public:
	Deck(string power_word, string deck[deck_size]);
	void SetWords(string power_word, string deck[deck_size]);
	void SetWordAt(string word_to_set, int at_location);
	void SetPowerWord(string power_word);
	string GetWord(int which_word);
	string GetWordsForPrint();
};


#endif WORDDECK_H_
