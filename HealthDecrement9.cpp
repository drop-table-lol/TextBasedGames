/*Recursive HealthDecrement.cpp
**Uses a default argument on a recusive function
**which obfuscates finding the value. Also allowing
** us to see how default values initialize.
** As always, player has won when they increment health
** instead of decrement. Code is written (mostly)compliant to google c++ style
*/
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

char input_str[5];
void RecurseOnDefaultHealth(int health = 100){
	cout << "Ouch! " << health << " health left!" << endl;
	cin >> input_str;
	if (health > 0){
		RecurseOnDefaultHealth(--health);
	}
	else {
		return;
	}
}



int main(){
  RecurseOnDefaultHealth();
	return 0;
}

