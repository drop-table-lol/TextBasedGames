/*VectorExp
Just playing around with vectors, sorts,
STL functionality
Using Lambda functions including args to threads.
Showcasing the non-determinism in concurrent programs.
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
void barrierThreads();

int main() {

  /*thread th(&threadFunction); //threads take functions as args
  thread th2(&threadFunction2); //these may or may not execute in order.
  thread th3([]() {
             cout << "Hi from thread3!\n" << endl;
             });
  */
  barrierThreads();
  cout << "Hello world\n" << endl;
/*  th.join(); //wait for thread - we're idle, OS can take over and process other stuff.
  th2.join();
  th3.join();
*/
return 0;
}


void threadFunction() {
  cout << "Hello from thread!\n" << endl;
}

void threadFunction2() {
  cout << "Hello from thread2\n" << endl;
}

void barrierThreads() {
  vector<thread> workers;
  for (int i=0; i<10; i++) {
    workers.push_back(thread([i]() { //lambda function (inline) with arg
              cout << "Hi from thread" << i << "\n!";
              }));
  }
  for_each(workers.begin(), workers.end(), [](thread & th)
           {
             th.join();
           });//in algorithm
}
