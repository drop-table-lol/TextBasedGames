/*Exploring the fact that template functions aren't instantiated by the
compiler until a copy is found with types, what happens if we nest
templates where the first is gotten from IO?
Horrible security? Yes. Maximum breakage? Yes. Learning? Yes. */
#include <iostream>
using namespace std;

template <class T> //also tried to use a second template that wasn't input, but that fails as well. Probably creates funciton prototype with types T and T1... Tn to avoid this sort of issue?
T GetIO(T notused) { //originally tried this without parameters, as I guess that wouldn't make much sense, templates must have params, otherwise no matching funciton is found.
  T in;
  cin >> in; //does this work? No. it doesn't
  return in;
}

template <class T>
void PrintIO(T out) {
	cout << out << endl; //this works, right? <</iostream is templatized
}

template <class T>
T DoubleIt(T in) { //a regular template function to test against.
  return in*in;
}

int main() {
	auto ivar = GetIO(1); //this is still assigning type int.
	auto cvar = GetIO('a'); //this assigns type char
	PrintIO(GetIO(ivar));
	PrintIO(GetIO(cvar));
	/*Does it work for built in types? And fail for user types that don't overload "<<" and ">>" operators?
	Does it fail before that since this function isn't actually using a type
	and the compiler doesn't actually instantiate it?*/

	/*however, it would be interesting to dissasmble this portion of code. My guess is the innermost function
	is compiled first, figuring out its type and propogating upward.*/
}


/*Pair template*/
/*
template <T>
class Pair {

	private:
		T p1;
		T p2;
	public:
		Pair(const T& x,const T& y) : p1(x), p2(y) {
		}
};
*/
