/*Card.cpp*/
#include "Card.h"

#include <string>
using std::string;

Card::Card(int action_type, string action) {
	action_type_ = action_type;
	action_ = action;
}
int Card::GetActionType() {
	return action_type_;
}
string Card::GetAction() {
	return action_;
}
void Card::ModifyCard(int change) {
	modify_ = change;
}
int Card::GetModification() {
	return modify_;
}
/*Card.cpp*/ //END

