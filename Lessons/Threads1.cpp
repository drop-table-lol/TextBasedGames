/*VectorExp
Just playing around with vectors, sorts,
STL functionality
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <chrono>
#include <thread>
using std::vector;
using std::string;
using std::sort;
using std::cout;
using std::endl;
using std::thread;

void threadFunction(); //can take args
void threadFunction2();

int main() {

  thread th(&threadFunction); //threads take functions as args
  thread th2(&threadFunction2); //these may or may not execute in order.
  thread th3([]() {
             cout << "Hi from thread3!\n" << endl;
             });
  cout << "Hello world\n" << endl;
  th.join(); //wait for thread - we're idle, OS can take over and process other stuff.
  th2.join();
  th3.join();
return 0;
}


void threadFunction() {
  cout << "Hello from thread!\n" << endl;
}

void threadFunction2() {
  cout << "Hello from thread2\n" << endl;
}
