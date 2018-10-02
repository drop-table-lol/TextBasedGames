#include <iostream>
using std::cin;
using std::cout;
using std::endl;

class HealthDecrementer {
  public:
	  int DecrementHealth(int health) {
		  --health;
		  return health;
	}
};

class HealthPrinter {
  public:
	  void PrintHealth(int health) {
		  cout << health << " health left!" << endl;
		  return;
	  }
};


int main() {
	HealthDecrementer HD;
	HealthPrinter HP;
	int health = 100;
	char input_str[5];

	while(true) {
		health = HD.DecrementHealth(health);
		HP.PrintHealth(health);
		cin >> input_str;
	}
}

//TODO -> inputstr needs to be changed in all HealthDecrement files to input_str or input_string
//to adhere to google c++ standard...
