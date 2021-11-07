#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;


//------------------------------------------------------------------------------

int* createArray(int sizeOfArray);
void enterArray(int& sizeOfArray);											// ARRAY
void fillArray(int* array, int sizeOfArray);
void displayArray(int* array, int sizeOfArray);


int medianArray(int* array, int sizeOfArray);
int deleteRepetitiveElements(int* array, int &sizeOfArray);		

int** createMatrix(int sizeStrings, int sizeColumn);
void enterMatrix(int& sizeStrings, int& sizeColumn);
void fillMatrix(int** matrix, int sizeStrings, int sizeColumn);				// MATRIX
void displayMatrix(int** matrix, int sizeStrings, int sizeColumn);
void deleteMatrix(int** matrix, int sizeStrings);

int** multiply(int** matrixForMultiply1, int** matrixForMultiply2, int** resultMatrix, int sizeOfMatrixForMultiplyStrings1, int sizeOfMatrixForMultiplyColumn2, int sizeOfMatrixForMultiplyColumn1);
int sumOfElements(int** matrix, int sizeStrings, int sizeColumn);
int meanValue(int** matrix, int sizeStrings, int sizeColumn);
int medianMatrix(int** matrix, int sizeStrings, int sizeColumn);
int max(int** matrix, int sizeStrings, int sizeColumn);
int min(int** matrix, int sizeStrings, int sizeColumn);
void sortMatrix(int** matrix, int sizeStrings, int sizeColumn);

int random();

//---------------------------------------------------------------------------------------------------

int main() {
	srand(time(NULL));

	int sizeStrings, sizeColumn;
	enterMatrix(sizeStrings, sizeColumn);														// 1

	int** matrix;
	matrix = createMatrix(sizeStrings, sizeColumn);

	fillMatrix(matrix, sizeStrings, sizeColumn);

	displayMatrix(matrix, sizeStrings, sizeColumn);
	

	//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

	cout << "Sum of elements = " << sumOfElements(matrix, sizeStrings, sizeColumn) << endl;		//    2
	cout << "Mean value of elements = " << meanValue(matrix, sizeStrings, sizeColumn) << endl;

	deleteMatrix(matrix, sizeStrings);
	//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

	int** matrixForMultiply1;
	int** matrixForMultiply2;
	int** resultMatrix;
	int sizeOfMatrixForMultiplyStrings1, sizeOfMatrixForMultiplyColumn1;
	int sizeOfMatrixForMultiplyStrings2, sizeOfMatrixForMultiplyColumn2;

	enterMatrix(sizeOfMatrixForMultiplyStrings1, sizeOfMatrixForMultiplyColumn1);
	matrixForMultiply1 = createMatrix(sizeOfMatrixForMultiplyStrings1, sizeOfMatrixForMultiplyColumn1);
	fillMatrix(matrixForMultiply1, sizeOfMatrixForMultiplyStrings1, sizeOfMatrixForMultiplyColumn1);

	enterMatrix(sizeOfMatrixForMultiplyStrings2, sizeOfMatrixForMultiplyColumn2);
	matrixForMultiply2 = createMatrix(sizeOfMatrixForMultiplyStrings2, sizeOfMatrixForMultiplyColumn2);						// 3
	fillMatrix(matrixForMultiply2, sizeOfMatrixForMultiplyStrings2, sizeOfMatrixForMultiplyColumn2);

	resultMatrix = createMatrix(sizeOfMatrixForMultiplyStrings1, sizeOfMatrixForMultiplyColumn2);
	resultMatrix = multiply(matrixForMultiply1, matrixForMultiply2, resultMatrix, sizeOfMatrixForMultiplyStrings1, sizeOfMatrixForMultiplyColumn2, sizeOfMatrixForMultiplyColumn1);

	cout << "The first matrix" << endl; displayMatrix(matrixForMultiply1, sizeOfMatrixForMultiplyStrings1, sizeOfMatrixForMultiplyColumn1);
	cout << "The second matrix" << endl; displayMatrix(matrixForMultiply2, sizeOfMatrixForMultiplyStrings2, sizeOfMatrixForMultiplyColumn2);
	cout << "Matrix after multiplying" << endl; displayMatrix(resultMatrix, sizeOfMatrixForMultiplyStrings1, sizeOfMatrixForMultiplyColumn2);

	
	deleteMatrix(resultMatrix, sizeOfMatrixForMultiplyStrings1);
	deleteMatrix(matrixForMultiply1, sizeOfMatrixForMultiplyStrings1);
	deleteMatrix(matrixForMultiply2, sizeOfMatrixForMultiplyColumn1);
	//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

	int* array;
	int sizeOfArray;
	enterArray(sizeOfArray);
	array = createArray(sizeOfArray);
	fillArray(array, sizeOfArray);
	sort(array, array + sizeOfArray);
	displayArray(array, sizeOfArray);																			// 4

	sizeOfArray = deleteRepetitiveElements(array, sizeOfArray);

	displayArray(array, sizeOfArray);
	cout << "median = " << medianArray(array, sizeOfArray) << endl;
	delete[] array;

	//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


	int sizeStringsTask5, sizeColumnTask5;
	enterMatrix(sizeStringsTask5, sizeColumnTask5);

	int** matrixTask5;
	matrixTask5 = createMatrix(sizeStringsTask5, sizeColumnTask5);

	fillMatrix(matrixTask5, sizeStringsTask5, sizeColumnTask5);

	sortMatrix(matrixTask5,sizeStringsTask5, sizeColumnTask5);    

	displayMatrix(matrixTask5, sizeStringsTask5, sizeColumnTask5);																//5

	cout << "matrix median = " << medianMatrix(matrixTask5, sizeStringsTask5, sizeColumnTask5) << endl;
	cout << "matrix max number = " << max(matrixTask5, sizeStringsTask5, sizeColumnTask5) << endl;
	cout << "matrix min number = " << min(matrixTask5, sizeStringsTask5, sizeColumnTask5) << endl;
	deleteMatrix(matrixTask5, sizeStringsTask5);
}

//---------------------------------------------------------------------------------------------------

int max(int** matrix, int sizeStrings, int sizeColumn) {
	int max = matrix[0][0];
	for (int i = 0; i < sizeStrings; i++) {
		for (int j = 0; j < sizeColumn; j++) {
			if (max < matrix[i][j]) {
				max = matrix[i][j];
			}
		}
	}
	return max;
}

int min(int** matrix, int sizeStrings, int sizeColumn) {
	int min = matrix[0][0];
	for (int i = 0; i < sizeStrings; i++) {
		for (int j = 0; j < sizeColumn; j++) {
			if (min > matrix[i][j]) {
				min = matrix[i][j];
			}
		}
	}
	return min;
}

void sortMatrix(int** matrix, int sizeStrings, int sizeColumn) {
	int sort;
	for (int g = 0; g < sizeStrings; g++) {
		for (int i = 0; i < sizeStrings; i++) {
			for (int j = 0; j < sizeColumn - 1; j++) {
				if (matrix[i][j] > matrix[i][j + 1]) {

					sort = matrix[i][j];
					matrix[i][j] = matrix[i][j + 1];
					matrix[i][j + 1] = sort;
				}
			}
		}
	}
}

int medianMatrix(int** matrix, int sizeStrings, int sizeColumn) {
	int middleMatrix = 0;
	int middleC = sizeColumn / 2;
	int middleS = sizeStrings / 2;
	int* array = createArray(sizeStrings);
	for (int i = 0;i < sizeStrings ;i++) {
		if (sizeColumn % 2 == 1) {
			array[i] = matrix[i][middleC];
		}
		else {
			array[i] = (matrix[i][middleC] + matrix[i][middleC - 1]) / 2;
		}
	}
	if (sizeStrings % 2 == 1) {
		middleMatrix = array[middleS];
	}
	else {
		middleMatrix = (array[middleS] + array[middleS - 1]) / 2;
	}
	delete[] array;
	return middleMatrix;
}

int medianArray(int* array, int sizeOfArray) {
	int middle = sizeOfArray / 2;
	if (sizeOfArray % 2 == 1) {
		return array[middle];
	} else {
		return (array[middle] + array[middle - 1]) / 2;
	}
}

int deleteRepetitiveElements(int* array, int &sizeOfArray) {
	for (int i = 0; i < sizeOfArray; i++) {
		for (int j = i + 1; j < sizeOfArray; j++) {
			if (array[i] == array[j]) {
				for (int k = j; k < sizeOfArray - 1; k++) {
					array[k] = array[k + 1];
				}
				sizeOfArray--;
				if (array[i] == array[j]) {
					j--;
				}
			}
		}
	}
	return sizeOfArray;
}

void enterArray(int &sizeOfArray) {
	cout << "Enter the size of array = "; cin >> sizeOfArray;
}

int** multiply(int** matrixForMultiply1, int** matrixForMultiply2, int** resultMatrix, int sizeOfMatrixForMultiplyStrings1, int sizeOfMatrixForMultiplyColumn2, int sizeOfMatrixForMultiplyColumn1) {
	for (int i = 0; i < sizeOfMatrixForMultiplyStrings1; i++)
	{
		for (int j = 0; j < sizeOfMatrixForMultiplyColumn2; j++)
		{
			for (int k = 0; k < sizeOfMatrixForMultiplyColumn1; k++)
				resultMatrix[i][j] = matrixForMultiply1[i][k] * matrixForMultiply2[k][j];
		}
	}
	return resultMatrix;
}

void enterMatrix(int &sizeStrings, int &sizeColumn) {

	cout << "Enter the sizes of matrix \nstrings = "; cin >> sizeStrings; cout << "column = ";  cin >> sizeColumn;
}

int sumOfElements(int** matrix, int sizeStrings, int sizeColumn) {
	int sum = 0;
	for (int i = 0; i < sizeStrings; i++) {
		for (int j = 0; j < sizeColumn; j++) {
			sum += matrix[i][j];
		}
	}
	return sum;
}

int meanValue(int** matrix, int sizeStrings, int sizeColumn) {
	return sumOfElements(matrix, sizeStrings, sizeColumn) / (sizeStrings * sizeColumn);
}

void displayMatrix(int** matrix, int sizeStrings, int sizeColumn)
{
	for (int i = 0; i < sizeStrings; i++) {
		for (int j = 0; j < sizeColumn; j++) {
			cout << setw(3) << matrix[i][j] << ' ';
		}
		cout << endl;
	}
}

void displayArray(int* array, int sizeOfArray)
{
	for (int i = 0; i < sizeOfArray; i++) {
		cout << setw(3) << array[i] << ' ';
	}
	cout << endl;
}

int random() {
	return rand() % 20 -10;
}

void fillMatrix(int** matrix, int sizeStrings, int sizeColumn) {
	for (int i = 0; i < sizeStrings; i++) {
		for (int j = 0; j < sizeColumn; j++) {
			matrix[i][j] = random();
		}
	}
}

void fillArray(int* array, int sizeOfArray) {
	for (int i = 0; i < sizeOfArray; i++) {
		array[i] = random();
	}
}
int** createMatrix(int sizeStrings, int sizeColumn) {
	int** matrix;
	matrix = new int* [sizeStrings];
	for (int i = 0; i < sizeStrings; i++) {
		matrix[i] = new int[sizeColumn];
	}
	return matrix;
}

int* createArray(int sizeOfArray) {
	int* array = new int [sizeOfArray];
	return array;
}

void deleteMatrix(int** matrix, int sizeStrings) {
	for (int i = 0; i < sizeStrings; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
}
