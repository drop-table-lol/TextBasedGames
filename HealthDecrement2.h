#include <iostream> //for write to console
using namespace std;
/* 	Health Decrement.cpp
**	Use with CheatEngine to practice finding values.
**	User has successfuly completed when they can set health to a different value than prev value -1
**	V1.0.1 uses simple ints.
*/

void decrementHealth(int *);
void printHealth (int *);


int main()
{

	int ihealth = 100;                  //set value pointed to health to 100
	int * health;                       //First level of obfuscation. Pointer dereferencing
	health = &ihealth;                  //address of ihealth stored in health

    char inputstr[5];
	while (true)
	{
		cin >> inputstr; 				//wait for input (buffer overflow anyone?)
		decrementHealth(health);    	//decrease value of health by 1, passing the pointer
		printHealth(health);		    //display value to user passing the pointer
	}
	return 0;

}

void decrementHealth(int * h)
{
    *h = *h-1;                          //interestingly, postdecrement did not work here... *h--; Is decrement higher precedence than pointer dereference?
    return;
}

void printHealth(int *h)
{
    cout << *h << " health left!"<< endl;
    return;
}
