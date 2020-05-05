#include <iostream>
#include <math.h>
using namespace std;


int proper_divisors_sum(int n) {
    int sum = 1;

    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            sum += i;
            sum += (n / i);
        }
    }

    return sum;
}


int solve(int n) {
    int sum = 0;
    int p;

    for (int i = 2; i < n; i++) {
        p = proper_divisors_sum(i);
        if (p != i && proper_divisors_sum(p) == i) {
            sum += i;
        }
    }

    return sum;
}


int main() {
    cout << solve(10000) << endl;

    return 0;
}