#ifndef CARD_H_
#define CARD_H_
/*Card.h*/

#include <string>
using std::string;

class Card {
	private:
		int action_type_;
		string action_;
		int modify_;

	public:
		Card(int action_type, string action);
		int GetActionType();
		string GetAction();
		void ModifyCard(int change);
		int GetModification();
};

#endif// CARD_H_
