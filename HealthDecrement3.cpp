#include <iostream> //for write to console
using namespace std;
/* 	Health Decrement3.cpp
**	Use with CheatEngine to practice finding values.
**	User has successfuly completed when they can increment health rather than decrease it
**	V1.0.1 uses simple ints, but layered call by value
*/

int decrementHealth(int);
void printHealth(int);
int wrapThisFunc(int);          //You'll notice this horrible naming convention.
void wrapThatOtherFunc(int);    //But I think it's funny, and I wrote the code... Consider it obfuscation by horrible practice

int main()
{

	int health = 100;
    char inputstr[5];

	while (true)
	{
		health = wrapThisFunc(health); 	        //decrease value of health by 1
		wrapThatOtherFunc(health);				//display value to user
		cin >> inputstr;                        //wait for input (no sanitization) but we're the attacker in this anyway, using cheatEngine
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

int wrapThisFunc(int h)
{
    return decrementHealth(h);
}

void wrapThatOtherFunc(int h)
{
    printHealth(h);
    return;
}
