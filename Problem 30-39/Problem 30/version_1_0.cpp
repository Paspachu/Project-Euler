#include <iostream>
#include <math.h>
using namespace std;


int sum_digit_fifth_power(int n, int p) {
    int sum = 0;

    while (n > 0) {
        sum += pow((n % 10), p);
        n = n / 10;
    }

    return sum;
}


int solve (int p) {
    int sum = 0;

    for  (int i = 10; i <= 354294; i++) {
        if (sum_digit_fifth_power(i, p) == i) {
            sum += i;
        }
    }

    return sum;
}


int main() {
    cout << solve(5) << endl;

    return 0;
}