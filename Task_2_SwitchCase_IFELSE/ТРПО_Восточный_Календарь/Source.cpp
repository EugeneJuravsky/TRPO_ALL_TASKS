#include <iostream>
using namespace std;
void Years(int& year);
void InputTheYear(int& year);
void ToDooze(int& dooze, int year);
void OutputTheAnimal(string animal);
string AnimalOfYear(int dooze);
int main()
{
	int year, dooze;

	InputTheYear(year);
	Years(year);
	ToDooze(dooze, year);
	OutputTheAnimal( AnimalOfYear(dooze) );
}

void OutputTheAnimal(string animal) {
	cout << animal;
}

void InputTheYear(int& year){
	cout << "Введите год\n";
	cin >> year;
}

void Years(int& year) {

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

}

void ToDooze(int& dooze, int year) {
	dooze = year % 12;
}

string AnimalOfYear(int dooze) {

	switch (dooze)
	{
	case 0:
		return "Крысы";
		break;
	case 1:
		return  "Бык";
		break;
	case 2:
		return "Тигр";
		break;
	case 3:
		return "Кот";
		break;
	case 4:
		return "Дракон";
		break;
	case 5:
		return "Змея";
		break;
	case 6:
		return "Лошадь";
		break;
	case 7:
		return "Коза";
		break;
	case 8:
		return "Обезьяна";
		break;
	case 9:
		return "Петух";
		break;
	case 10:
		return "Собака";
		break;
	case 11:
		return "Свинья";
		break;
	}

}

