//WordDeck.cpp
//keeping it simple. Add fancy things later.
//TODO enum of rock/paper/scissors for later. ->combat

#include "WordDeck.h"
#include "Globals.h"
#include <string>
using std::string;
using Globals::deck_size;
using Globals::low_bound;
using Globals::high_bound;

Deck::Deck(string power_word, string new_deck[deck_size]){
	SetWords(power_word, new_deck);
	return;
}

void Deck::SetWords(string power_word, string new_deck[deck_size]) {
	SetPowerWord(power_word);
	for(int i=low_bound; i<deck_size; i++) {
		available_words_[i] = new_deck[i];
  }
}

void Deck::SetWordAt(string word_to_set, int at_location) { //TODO not fail silently, also, not hard code bounds
	if (at_location >= low_bound && at_location <=high_bound) {
		available_words_[at_location] = word_to_set;
	}
}

void Deck::SetPowerWord(string power_word){
	power_word_ = power_word;
}

string Deck::GetWord(int which_word) {
	if (which_word >= low_bound && which_word <=high_bound) {
		return available_words_[which_word];
	}
}
string Deck::GetWordsForPrint(){
	string deck = power_word_;
	for(int i=low_bound; i<deck_size; i++) {
		deck = deck + " " + available_words_[i];
	}
	return deck;
}
