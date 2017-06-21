/*This is a simple practice program to show the difference between
reference parameters and value parameters to void functions.
It highlights the difference between the two, using simple data types
It also uses function overloading.
(Classes and arrays to come)
*/


#include <iostream>
using namespace std;

void addNum(int& a, int b);
void squareNum(int& a,int b);


int main()
{

    int a = 10;
    int b = 11;

    cout << "Var a = " << a << " and var b = " << b << endl;
    cout << "Adding the number to itself yields" << endl;
    addNum(a, b);
    cout << "Var a = " << a << " and b is " << b << endl;
    cout << "Squaring the number yields " << endl;
    squareNum(a, b);
    cout << "Var a = " << a << " and b is " << b << endl;

    cout << "Var a changes, as it is passed by reference. The memory location." << endl;
    cout << "Var b remains the same, as it is passed by value, and therefore only it's copy is changed within the function" << endl;




}

void addNum(int& a, int b)
{
    a = a+a;
    b = b+b;
}


void squareNum(int& a, int b)
{
    a = a*a;
    b = b*b;
}
