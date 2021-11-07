#include <iostream>
#include <math.h>

using namespace std;

int to_gcd(long long a, long long b) {
    int f;
    while (a > 0) {
        f = a;
        a = b % a;
        b = f;
    }
    return b;
}

bool prime(long long number) {
    for (long long i = 2; i * i <= number; i++)
        if (number % i == 0) {
            return false;
        }
    return true;
}
void isPrime(long long number) {
    if (prime(number)) {
        cout << endl << number << " is prime";
    }
    else {
        cout << endl << number << " is not prime";
    }
}

int main() {
        long long numberFirst, numberSecond;

        cout << "the first number = "; cin >> numberFirst;
        cout << "the second number = ";cin >> numberSecond;

        long long gcd = to_gcd(numberFirst, numberSecond);

        cout << "Greatest common division(" << numberFirst << " ; " << numberSecond << ") = " << gcd << '\n';
     
        isPrime(numberFirst);
        isPrime(numberSecond);

        
    }

 