/*Threading! */
//value passing taken from Bartosz Milewski youtube examples
//https://www.youtube.com/watch?v=o0pCft99K74&list=PL1835A90FC78FF8BE&index=4

#include <thread>
#include <iostream>
#include <future> //passing values between threads
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::thread;
using std::promise;
using std::future;
using std::move;

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

void thFun(promise<string>&& promise) {
  string str("Hello from the future!");
  promise.set_value(str);
}


void thFun2(promise<string>&& promise) {
  //cout << promise << endl; //does this work? is it overloaded? No.
  /*string str = promise.get_future().get_value();
  str = str+ " Pluto";*/ //Promises are not meant to be in values. They are for the future
  string str2 = "Pluto!";
  promise.set_value(str2);
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


  //New code for passing between threads
  promise<string> argument_to_thread;
  future<string> return_from_thread = argument_to_thread.get_future();
  thread change_value(&thFun, move(argument_to_thread));
  cout << "\n\n\n\n";
  cout << "Hello from main!" << endl;
  string str = return_from_thread.get();
  cout << str << endl;
  change_value.join();
  //we gloss over a lot here, and tried to modify the code to use descriptive names.
  //However, the promise we pass to the thread is never initialized...
  promise<string> argument_to_thread2;
  //interestingly, if we argument_to_thread2.set_value("Pluto!"); then we run into problem
  future<string> return_from_thread2 = argument_to_thread2.get_future(); //on this line
  thread change_value2(&thFun2, move(argument_to_thread2));
  cout << "\n\n\n\n";
  cout << "Goofy!" << endl;
  string str2 = return_from_thread2.get();
  cout << str2 << endl;
  change_value2.join();

  return 0;
}
/*Note that the prints sometimes still end up on the same line.
And the newline is still on the next line. That's kinda cool. we're creating a race condition for the outstream?
Could have a key and lock for curr output if we cared (mutex? buzzword?)*/
