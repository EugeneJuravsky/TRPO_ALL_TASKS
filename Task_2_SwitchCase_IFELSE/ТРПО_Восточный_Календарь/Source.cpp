#include <iostream>
using namespace std;

int main()
{
	int year, dooze;

	cout <<"Введите год\n";
	cin >> year;

	if (year >= 1900)
	{
		year = year - 1900;
	}
	else
	{
		while (year < 1900)
		{
			year = year + 12;
		}
		year = year - 1900;
	}

		dooze = year % 12;

	switch (dooze)
	{
	case 0: 
		cout << "Крысы";
		break;
	case 1:
		cout << "Бык";
		break;
	case 2:
		cout << "Тигр";
		break;
	case 3:
		cout << "Кот";
		break;
	case 4:
		cout << "Дракон";
		break;
	case 5:
		cout << "Змея";
		break;
	case 6:
		cout << "Лошадь";
		break;
	case 7:
		cout << "Коза";
		break;
	case 8:
		cout << "Обезьяна";
		break;
	case 9:
		cout << "Петух";
		break;
	case 10:
		cout << "Собака";
		break;
	case 11:
		cout << "Свинья";
		break;
	}
	
	
	cout << endl;
	system("pause");
	return 0;
}