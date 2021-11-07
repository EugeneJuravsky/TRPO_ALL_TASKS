#include <iostream>

using namespace std;

string binary(long long number) {
    string binarNumber = "0";
    while (number) {
        binarNumber += (number % 2) + '0';
        number /= 2;
    }
    reverse(binarNumber.begin(), binarNumber.end());
    return binarNumber;
}

int main() {

    long long number;
    cout << "введите число: "; cin >> number;

    cout << binary(number) << '\n';
}