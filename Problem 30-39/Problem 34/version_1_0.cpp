#include <iostream>
using namespace std;


int factorial(int n) {
    int product = 1;

    for (int i = 2; i <= n; i++) {
        product *= i;
    }

    return product;
}


int sum_of_factorials(int n) {
    int sum = 0;

    while (n > 0) {
        sum += factorial(n % 10);
        n = n / 10;
    }

    return sum;
}


int solve() {
    int sum = 0;

    for  (int i = 10; i <= 2540160; i++) {
        if (sum_of_factorials(i) == i) {
            sum += i;
        }
    }

    return sum;
}


int main() {
    cout << solve() << endl;

    return 0;
}