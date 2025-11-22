#include <iostream>
using namespace std;

int fib(int n) {
    if (n == 0) return 0;       // base case
    if (n == 1) return 1;       // base case
    return fib(n-1) + fib(n-2); // recursive call
}

int main() {
    int n;
    cout << "Enter number of terms: ";
    cin >> n;

    cout << "Fibonacci Series: ";
    for (int i = 0; i < n; i++) {
        cout << fib(i) << " ";
    }
    return 0;
}
