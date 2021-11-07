#include <iostream>

using namespace std;

void fact(int number) {
	long long factNumber = 1;
	for (int counter = 1; counter < number + 1; counter++) {
		factNumber *= counter;
	}
	cout << endl << factNumber;
}

void enterFib(long long number) {
	long long sortNum1 = 0, sortNum2 = 1, sortNum3 = 1;

	for (int counter = 0; counter < number; counter++) {
		cout << " " << sortNum3;
		sortNum3 = sortNum1 + sortNum2;
		sortNum1 = sortNum2;
		sortNum2 = sortNum3;
	}
}
int main(){
	long long number;

	cout << "Enter the number = "; cin >> number;
	
	enterFib(number);

	fact(number);
}