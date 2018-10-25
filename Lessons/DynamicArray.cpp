#include <iostream>
#include <string>
using std::string;
using std::cin;
using std::cout;
using std::endl;



int GetHowMany();
void FillArr(string arr[], int length);
void SortArr(string arr[], int length);
void PrintArr(string arr[], int length);


int main() {

	int length;
	length = GetHowMany();
	string *arr = new string[length]();
	FillArr(arr, length);
	//SortARR(arr, length);
	PrintArr(arr, length);
	delete[] arr;

}
int GetHowMany() {
	cout << "Enter how many names you'd like to enter." <<endl;
	int myint;
	cin >> myint;
	return myint;
}

void FillArr(string arr[], int length) {

	for (int i=0; i<length; i++) {
		cout << "Enter name please: ";
		cin >> arr[i];
	}
}

void SortArr(string arr[], int length) {
//sort code
}

void PrintArr(string arr[], int length) {
	for (int i=0; i<length; i++) {
		cout << arr[i] << endl;
	}
}
