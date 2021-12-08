#include <iostream>
using namespace std;

enum Sex				// Пол
{
	female,
	male

};
struct fullName {       // ФИО
	string firstName;
	string secondName;
	string patronymic;
};

struct date {			// Дата рождения
	int day;
	int month;
	int year;
};

struct student {		// Студент
	fullName name;
	date birth;
	Sex sex;
};

void inputStudents(student* students, const int AMOUNT_OF_STUDENTS);
void outputStudents(student* students, const int AMOUNT_OF_STUDENTS);
tm presentTime();

const int AMOUNT_OF_STUDENTS = 10; // Число студентов




int main() {
	student students[AMOUNT_OF_STUDENTS];

	inputStudents(students, AMOUNT_OF_STUDENTS);

	outputStudents(students, AMOUNT_OF_STUDENTS);

	tm presentTime = findOutTime();

}


void outputStudents(student* students,const int AMOUNT_OF_STUDENTS) { // Вывод студентов
	for (int i = 0; i < AMOUNT_OF_STUDENTS; i++) {

	}
}

void inputStudents(student* students, const int AMOUNT_OF_STUDENTS) { // Ввод студентов
	char sex = ' ';
	for (int i = 0; i < AMOUNT_OF_STUDENTS; i++) {
		cout << "Student_" << i + 1<< endl;
		cout << "First Name = "; cin >> students[i].name.firstName;
		cout << "Second Name = "; cin >> students[i].name.secondName;
		cout << "Patronymic = "; cin >> students[i].name.patronymic;
		cout << "Birth(day)= "; cin >> students[i].birth.day;
		cout << "Birth(month)= "; cin >> students[i].birth.month;
		cout << "Birth(year)= "; cin >> students[i].birth.year;
		cout << "Sex( f / m) = "; cin >> sex;

		switch (sex)
		{
		case 'f': students[i].sex = female;
			break;
		case 'm': students[i].sex = male;
			break;
		}
		system("cls");
	}
}

tm  findOutTime() {
	struct tm newTime;
	time_t now = time(0);
	localtime_s(&newTime, &now);
	newTime.tm_year = newTime.tm_year + 1900; // Правильный год
	newTime.tm_mon = newTime.tm_mon + 1; // Правильный месяц
	//newTime.tm_mday;
	return newTime;
}