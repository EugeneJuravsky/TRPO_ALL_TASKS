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
	int Age;
	Sex sex;
};

void inputStudents(student* students);
void outputStudents(student* students);
void outputStudents(student* students, bool FULL);
void countAge(student* students, tm presentTime);
void findMostCommonName(student* students, bool& isExist, string& mostCommonName);
void SortBySex(student* students);
int middleAge(student* students);
tm findOutTime();

const int AMOUNT_OF_STUDENTS = 3; // Число студентов

int main() {
	student *students = new student [AMOUNT_OF_STUDENTS];
	bool isExist = false;
	string mostCommonName;

	inputStudents(students);// Ввод студентов

	outputStudents(students);// Вывод студентов

	tm presentTime = findOutTime();// Рассчёт возроста
	countAge(students, presentTime);

	findMostCommonName(students, isExist, mostCommonName);// Самое распространённое имя
	if (isExist) cout << "the most common name is " << mostCommonName << endl;
	else cout << "there no common names\n\n";

	SortBySex(students);// Сортировка по полу

	outputStudents(students, 1);// Вывод всей инфы о студентах

	cout << "Middle age of students is " <<  middleAge(students) << " years";// Средний возрост студентов
}


void outputStudents(student* students) { // Вывод студентов
	for (int i = 0; i < AMOUNT_OF_STUDENTS; i++) {
		cout << "[" << i + 1 << "] "
			<< students[i].name.secondName
			<< " " << students[i].name.firstName
			<< " " << students[i].name.patronymic << endl;
	}
	cout << endl;
}

void outputStudents(student* students, bool FULL) { // Вывод студентов
	for (int i = 0; i < AMOUNT_OF_STUDENTS; i++) {
		cout << "---------------Student[" << i + 1 << "]---------------\n";
		cout << students[i].name.secondName << " ";
		cout << students[i].name.firstName << " ";
		cout << students[i].name.patronymic << " ";
		cout << students[i].birth.year << ".";
		cout << students[i].birth.month << ".";
		cout << students[i].birth.day << " ";
		cout << "Age is " << students[i].Age << " years ";

		if (students[i].sex == male) cout << "Male ";
		else cout << "Female ";

		cout << "\n";
	}
	cout << endl;
}
void inputStudents(student* students)   // Ввод студентов
{ 
	char sex = ' ';
	for (int i = 0; i < AMOUNT_OF_STUDENTS; i++) {
		cout << "Student[" << i + 1 << "]" << endl;
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

tm  findOutTime()
{
	struct tm newTime;
	time_t now = time(0);
	localtime_s(&newTime, &now);
	newTime.tm_year = newTime.tm_year + 1900; // Правильный год
	newTime.tm_mon = newTime.tm_mon + 1; // Правильный месяц
	//newTime.tm_mday;
	return newTime;
}

void countAge(student* students, tm presentTime)
{
	int age;
	for (int i = 0; i < AMOUNT_OF_STUDENTS; i++)
	{
		age = presentTime.tm_year - students[i].birth.year;

		if (students[i].birth.month <= presentTime.tm_mon && students[i].birth.day <= presentTime.tm_mday)
			age++;

		students[i].Age = age;
	}
}

void findMostCommonName(student* students, bool& isExist, string& mostCommonName) // Самое распространённое имя
{
	int allRepetitions = 0;
	int Name = 0;
	for (int i = 0; i < AMOUNT_OF_STUDENTS; i++)
	{
		int repetitionsOfOne = 0;
		for (int j = 0; j < AMOUNT_OF_STUDENTS; j++)
		{
			if (students[i].name.firstName == students[j].name.firstName)
			{
				repetitionsOfOne++;
			}

		}
		if (repetitionsOfOne > allRepetitions)
		{
			allRepetitions = repetitionsOfOne;
			Name = i;
		}
	}
	if (allRepetitions > 1)
	{
		isExist = true;
		mostCommonName = students[Name].name.firstName;
	}
}

void SortBySex(student* students) // Сортировка по полу
{
	cout << "-------------------MALE-----------\n";
	for(int i = 0; i < AMOUNT_OF_STUDENTS; i++)
	{
		if(students[i].sex == male)
		{
			cout << students[i].name.secondName
				 << " " << students[i].name.firstName
				 << " " << students[i].name.patronymic << endl;
		}
	}

	cout << "------------------FEMALE----------\n";
	for (int i = 0; i < AMOUNT_OF_STUDENTS; i++)
	{
		if (students[i].sex == female)
		{
			cout << students[i].name.secondName
				 << " " << students[i].name.firstName
				 << " " << students[i].name.patronymic << endl;
		}
	}
	cout << endl;
}

int middleAge(student* students) 
{
	int age = 0;

	for (int i = 0; i < AMOUNT_OF_STUDENTS; i++)
	{
		age += students[i].Age;
	}
	age /= AMOUNT_OF_STUDENTS;

	return age;
}