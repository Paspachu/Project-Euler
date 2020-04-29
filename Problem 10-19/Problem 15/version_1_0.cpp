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


long long solve(int n) {
    return choose(2*n, n);
}


int main() {
    cout << solve(20) << endl;

    return 0;
}