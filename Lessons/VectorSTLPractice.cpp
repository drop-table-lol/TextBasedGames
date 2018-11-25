/*VectorExp
Just playing around with vectors, sorts,
STL functionality
*/

#include <iostream>
#include <vector>
#include <algorithm>
using std::vector;
using std::string;
using std::sort;
using std::cout;
using std::endl;



int main () {

  vector<string> deck;
  deck.push_back("Aardvark");
  deck.push_back("Zoologist");
  deck.push_back("Mumford");
  deck.push_back("X");

  for (auto element : deck) {//c++11 loop
    cout << element << endl;
  }

  std::sort(deck.begin(), deck.end());

  for (auto element : deck) {//c++11 loop
    cout << element << endl;
  }

}
