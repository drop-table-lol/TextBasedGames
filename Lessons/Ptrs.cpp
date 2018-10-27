#include <iostream>
#include <string>
using std::string;
using std::cin;
using std::cout;
using std::endl;


 inline int DoubleVal(int x) {
   return x*x;
}

int main() {

  int x = 5;
  int *y = &x;
  cout << y << endl;//address of x?
  cout << &x << endl;//address of x?
  cout << &y<< endl;//address of y?
  cout << *y<< endl;//value of x
  cout << x << endl; //value of x
  *y = 1;
  cout << x <<endl;

  int *z = new int;
  cout << z << endl;
  delete z;
  z = &x;
  cout << z << endl;
  *z = 2;
  cout << x << endl;

  cout << "\narr stuff" << endl;
  int arr[5] = {0};
  z = arr; //degrades to ptr
  for (int i=0; i<5; ++i) {
      cout << z << endl;
      cout << &arr[i] << endl;
      //sizeof int scaling
      //we can also do values
      cout << *z << endl;
      cout << arr[i] << endl;
      z++;
  }


  cout << DoubleVal(x) << endl;
}

