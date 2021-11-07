#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	int num, decade, hundred, unit;
	cout << "Введите целое трёхзначное число = ";
	cin >> num;
	if (num % 2 == 0)
	{
		cout << endl <<"Число чётное"<< endl;
		hundred = num / 100;
		decade = (num / 10) % 10;
		unit = num % 10;

		cout << (hundred + decade + unit) / 3.;
	} else {
		cout << "Вы ввели нечётное число";
	
	}


	return 0;
}