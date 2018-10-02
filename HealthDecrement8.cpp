#include <iostream>
using std::cin;
using std::cout;
using std::endl;

namespace Healthy{ //local anonymous namespace -> as per google c++ standard

class HealthDecrement {
	private:
		int health = 100;
	public:
		int GetHealth() {
		  return health;
		}
		void SetHealth() {
		  --health;
	  }
}; //end HealthDecrement

}//end namespace Healthy

int main() {
	char input_str[5];
	Healthy::HealthDecrement HD;
	while (true) {
		cin >> input_str;
		HD.SetHealth();
		cout << "Ouch! " << HD.GetHealth() << " health left!" << endl;
	} //end while
}//end main


