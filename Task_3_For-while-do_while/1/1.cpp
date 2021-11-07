#include <iostream>

using namespace std;

void drawRectangle(long long x, long long y)
{
	for (long long i = 0; i < x; i++) {
		for (long long j = 0; j < y; j++) {
			cout << "*";

		}
		cout << endl;
	}
}

long long countSquare(long long sideCountFirst, long long sideCountSecond) {
	return sideCountFirst * sideCountSecond;
}

long long countPerimeter(long long sideCountFirst, long long sideCountSecond) {
	return sideCountFirst * 2 + sideCountSecond * 2;
}
int main() {

	long long sideFirst, sideSecond, square, perimeter;

	cout << "Enter the sides of rectangle: " << endl << "First side = "; cin >> sideFirst; cout << "Second side = "; cin >> sideSecond;

	cout << "Square = " << countSquare(sideFirst, sideSecond)<< endl << "Perimeter = " << countPerimeter(sideFirst, sideSecond) << endl;

	drawRectangle(sideFirst, sideSecond);
	
}