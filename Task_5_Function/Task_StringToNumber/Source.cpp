#include <iostream>
#include <cmath>
#include <string>

using namespace std;

string сorrectionOfFrac(int);
string toString(int number);
string toString(float number);
string toString(double number);
string toString(int number, int count);
int numberOfMeetings(int size, int number);
int numberOfMeetings(string str, int number);

int main()
{

	int number = 113802;// random number for test														// Task 1 and 2
	int amountOfDigit = 6;
	cout << "My "<< toString(number, amountOfDigit) << " " << "to string " << to_string(number) << endl;

	int size = 5;
	int digit = 6;
	cout << "\nAmount of numeral in array = " << numberOfMeetings(size, digit) << endl;					// Task 3


}

int numberOfMeetings(int size, int number) {
	srand(time(NULL));
	int amount = 0;
	int* arr = new int[size];

	for (int i = 0; i < size; i++) {
		arr[i] = rand() % 10;
		cout << arr[i];
		if (arr[i] == number) amount++;
	}
	delete[] arr;

	return amount;
}

int numberOfMeetings(string str, int number) {
	int amount = 0;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == number) amount++;
	}
	return amount;
}

string сorrectionOfFrac(int number)
{
	if (number == 0)
	{
		return "";
	}

	int zeros = 0;
	while (number < 100000)
	{
		number *= 10;
		zeros++;
	}

	string correction;
	for (int i = 0; i < zeros; i++)
	{
		correction += "0";
	}

	return correction;
}

string toString(int number)
{
	if (number < 0)
	{
		return string("-") + toString(- number);
	}
	if (number < 10)
	{
		return string(1, number + '0');
	}
	return toString(number / 10) + toString(number % 10);
}


string toString(float number)
{
	if (number < 0)
	{
		return string("-") + toString(- number);
	}
	float wholeTemp;
	float fracTemp = modf(number, &wholeTemp);
	int whole = wholeTemp;
	int frac = int(fracTemp * 1000000);
	return toString(whole) + "." + сorrectionOfFrac(frac) + toString(frac);
}

string toString(double number)
{
	if (number < 0)
	{
		return string("-") + toString(-number);
	}
	double wholeTemp;
	double fracTemp = modf(number, &wholeTemp);
	int whole = wholeTemp;
	int frac = int(fracTemp * 1000000);
	return toString(whole) + "." + сorrectionOfFrac(frac) + toString(frac);
}

string toString(int number, int count)
{
	string fullNumber = toString(number);
	string reducedNumber;
	for (int i = 0; i < count; i++)
	{
		reducedNumber += fullNumber[i];
	}

	return reducedNumber;
}


