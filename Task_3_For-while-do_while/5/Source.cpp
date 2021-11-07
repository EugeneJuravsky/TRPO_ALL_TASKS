#include <iostream>
#include <iomanip>
using namespace std;


long long random(long long mod) {
     return rand() % mod;
}


void enterGraph(long long mod, long long arr[]) {
    cout << "Distribution graph\n";
    cout << setw(10) << "number" << setw(10) << "count\n";
    for (long long i = 0; i < mod; i++) {
        cout << setw(10) << i << setw(10) << arr[i] << '\n';
    }
}


void distribute(long long mod, long long count, long long arr[]) {
    while (count--) {
        arr[random(mod)]++;
    }
}


void fillArray(long long mod, long long arr[]) {
    for (long long i = 0; i < mod; i++) {
        arr[i] = 0;
    }
}


int main() {
    
        srand(time(NULL));

        cout << "enter the numbers \n";

        long long mod;
        cout << "mod = "; cin >> mod;
        mod = abs(mod);
        
        long long count;
        cout << "amount of numbers = "; cin >> count;
        count = abs(count);
        
        long long* arr = new long long[mod];

        fillArray(mod, arr);

        distribute(mod, count ,arr);
        enterGraph(mod, arr);

        delete[] arr;
}