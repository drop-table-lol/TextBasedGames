/*Fibonacci Threading! */
//LISTEN UP BOYOS AND GIRLOS
/*this is a hard fought implementation of multithreading
(lol, not really concurrent)
solution to the fibonacci sequence.
While a horrible choice for recursive threading
(is there such a thing as good recursive threading?!)
It shows off some cool stuff...*/

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


int fib(int n)
{
   if (n <= 1)
      return n;
   return fib(n-1) + fib(n-2);
}


void Fib(int current_value, promise<int>&& prom) {
  //base case if curr_val == 1 or 0
  if (current_value < 2) {
    prom.set_value(current_value);
    return;
  }
  else if (current_value>=2){
    promise<int> arg_to_thread;
    future<int> ret_from_thread = arg_to_thread.get_future();
    promise<int> arg_to_thread2;
    future<int> ret_from_thread2 = arg_to_thread2.get_future();
    thread do_fib(&Fib, current_value-1, move(arg_to_thread));
    thread do_fib2(&Fib, current_value-2, move(arg_to_thread2));
    do_fib.join();
    do_fib2.join();
    prom.set_value(ret_from_thread.get() + ret_from_thread2.get());
    return;
  }
}





int main() {

  promise<int> arg_to_thread;
  future<int> ret_from_thread = arg_to_thread.get_future();
  int fib_to_find = 9;
  thread top(&Fib, fib_to_find, move(arg_to_thread));
  top.join();
  cout << ret_from_thread.get() << endl;
  int actual = fib(fib_to_find);
  cout << actual << endl;

}
