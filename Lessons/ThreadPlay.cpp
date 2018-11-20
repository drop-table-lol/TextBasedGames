/*Threading! */

#include <thread>
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::thread;

/*set up a function to call via function ptr
we'll do a regular, then show how it works with threads
let's try it with a void first, then implement return values with a second function */
void CountToTen() {
  for (int i=1; i<11; i++) {
  cout << i << endl;
  }
}

void CountUpTenFromArg(int arg) {
  for (int i=arg+1; i<arg+11; i++) {
    cout << i << endl;
  }
}



int main() {
  //ignoring if parent/children are the right descriptors.... main might be preferred over parent
  cout << "Printing 10 in parent thread" << endl;
  CountToTen();
  cout << "Printing 10 up from 100 in parent thread" << endl;
  CountUpTenFromArg(100);
  cout << "Printing 10 in child thread" << endl; //since this is sequential, these should execute after 110
  thread cool_new_thread(CountToTen); //we're not waiting, so does execution continue?
  cout << "Printing 10 up from 100 in child thread" << endl; //does this execute at the same time? 2nd child thread?
  thread cool_new_thread2(CountUpTenFromArg, 100);
  //return 0; This was causing early termination, as we're not waiting for the child threads to finish...
  //actually, if execution ends regardless (since the compiler appends the return anyway, we get the error if we don't join
  cool_new_thread.join();
  cool_new_thread2.join();
  return 0;
}
/*Note that the prints sometimes still end up on the same line.
And the newline is still on the next line. That's kinda cool. we're creating a race condition for the outstream?
Could have a key and lock for curr output if we cared (mutex? buzzword?)*/
