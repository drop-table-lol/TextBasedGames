#include <iostream> //for write to console
using namespace std;
/* 	Health Decrement.cpp
**	Use with CheatEngine to practice finding values.
**	User has successfuly completed when they can set health to a different value than prev value -1
**	V1.0.1 uses simple ints.
*/

int decrementHealth(int);
void printHealth(int);

int main()
{

	int health = 100;
    char inputstr[5];

	while (true)
	{
		cin >> inputstr;					//wait for input (no sanitization) but we're the attacker in this anyway, using cheatEngine
		health = decrementHealth(health); 	                        //decrease value of health by 1
		printHealth(health);				                        //display value to user
	}
	return 0;
}

int decrementHealth(int h)
{
	return h-1;
}

void printHealth(int h)
{
	cout << h << " health left!" << endl;
	return;
}
