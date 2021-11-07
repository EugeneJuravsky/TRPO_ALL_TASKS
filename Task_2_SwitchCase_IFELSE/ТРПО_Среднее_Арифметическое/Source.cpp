#include <iostream>
using namespace std;

int main()
{
	short month;
	cout << "Введите номер месяца\n";
	cin >> month;
	switch (month)
	{
	case 1:
		cout << "Январь" << " Зима";
		break;
	case 2:
		cout << "Февраль" << " Зима";
		break;
	case 3:
		cout << "Март" << " Весна";
		break;
	case 4:
		cout << "Апрель" << " Весна";
		break;
	case 5:
		cout << "Май" << " Весна";
		break;
	case 6:
		cout << "Июнь" << " Лето";
		break;
	case 7:
		cout << "Июль" << " Лето";
		break;
	case 8:
		cout << "Август" << " Лето";
		break;
	case 9:
		cout << "Сентябрь" << " Осень";
		break;
	case 10:
		cout << "Октябрь" << " Осень";
		break;
	case 11:
		cout << "Ноябрь" << " Осень";
		break;
	case 12:
		cout << "Декабрь" << " Зима";
		break;

	default:
		cout << "Вы ввели некорректный символ\n";

	}
	cout << endl;
	system("pause");
	return 0;
}