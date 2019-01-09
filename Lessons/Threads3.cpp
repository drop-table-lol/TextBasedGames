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
#include <cassert>
using std::vector;
using std::string;
using std::sort;
using std::cout;
using std::endl;
using std::thread;

void eatMyThread(int i) {
  cout << "Hi from worker!" << i << "\n";
}


int main() {

  cout << "Hello world\n" << endl;

  vector<thread> workers;
  for (int i=0; i<8; i++) {
    auto th = thread(&eatMyThread, i);
    workers.push_back(move(th));
    assert(!th.joinable());
  }
  for_each(workers.begin(), workers.end(), [](thread & th) {
           assert(th.joinable());
           th.join();
  });

return 0;
}
