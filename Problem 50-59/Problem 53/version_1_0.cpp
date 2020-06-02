#include <iostream>
using namespace std;


long long choose(int n, int k) {
    if (k > n) {return 0;}
    if (k * 2 > n) {k = n-k;}
    if (k == 0) {return 1;}

    long long result = n;
    for (int i = 2; i <= k; ++i) {
        result *= (n-i+1);
        result /= i;
    }

    return result;
}


int solve(long long n) {
    int count = 0;

    for (int i = 1; i <= 100; i++) {
        for (int j = 0; j <= i; j++) {
            if (choose(i, j) > n) {
                count += (i - 2*j + 1);
                break;
            }
        }
    }

    return count;
}


int main() {
    cout << solve(1000000) << endl;

    return 0;
}