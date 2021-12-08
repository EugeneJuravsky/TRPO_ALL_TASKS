#include <iostream>
#include <fstream>

using namespace std;

struct flower {
	string NameOfFlower;
	int flowersNum;
	double growth;
	int budNum;
};

void SizeOfFile(string fileName);
flower* resizeArray(int& oldSize, int newSize, flower* flowers);
flower* readFlowersFromFile(string fileName, string fileName_2, int& size, char symbol);
int sizeOfFile(string fileName);

void writeFlowersInFile(string fileName, flower* flowers, int size, int opneMode);
int main() 
{
	int size = 1;
	char symbol = 'f';
	flower* flowers = readFlowersFromFile("flowers.txt", "flowersWithSymbol.txt", size, symbol);
	writeFlowersInFile("flowers.txt", flowers, size, ios_base::out);
	cout << sizeOfFile("flowers.txt");
}


flower* readFlowersFromFile(string fileName, string fileName_2, int& size, char symbol)
{
	ifstream file(fileName);

	if (!file.is_open()) {
		return nullptr;
	}

	size <= 0 ? size = 10 : size = size;
	flower* flowers = new flower[size];
	int numberOfLines = 0;

	while (!file.eof())
	{
		if (numberOfLines == size) {
			flowers = resizeArray(size, size + 1, flowers);
		}

		file >> flowers[numberOfLines].flowersNum;
		file >> flowers[numberOfLines].growth;
		file >> flowers[numberOfLines].budNum;
		file >> flowers[numberOfLines].NameOfFlower;

		if (flowers[numberOfLines].NameOfFlower.find(symbol) != -1) { // перенос строк с символом в другой файл
			ofstream file2(fileName_2, std::ios::app);
			file2 << flowers[numberOfLines].flowersNum << " "
				<< flowers[numberOfLines].growth << " "
				<< flowers[numberOfLines].budNum << " "
				<< flowers[numberOfLines].NameOfFlower << endl;
			file2.close();
		}
		numberOfLines++;
	}

	flowers = resizeArray(size, numberOfLines - 1, flowers);


	file.close();

	return flowers;
}

void writeFlowersInFile(string fileName, flower* flowers, int size, int openMode) 
{
	ofstream file(fileName, openMode);
	if (!file.is_open()) {
		return;
	}

	for (int i = size - 1; i >= 0; i--) {
		file << flowers[i].flowersNum << " "
			<< flowers[i].growth << " "
			<< flowers[i].budNum << " "
			<< flowers[i].NameOfFlower << endl;
	}
	file.close();
}

flower* resizeArray(int& oldSize, int newSize, flower* flowers) 
{
	if (oldSize == newSize) {
		return flowers;
	}
	flower* newArray = new flower[newSize];
	oldSize = newSize < oldSize ? newSize : oldSize;
	for (int i = 0; i < oldSize; i++) {
		newArray[i] = flowers[i];
	}
	oldSize = newSize;
	delete[] flowers;
	return newArray;
}

int sizeOfFile(string fileName) {
	ifstream file(fileName);
	int first = file.tellg();
	file.seekg(0, ios::end);
	int last = file.tellg();
	file.close();
	return (last - first);
}


