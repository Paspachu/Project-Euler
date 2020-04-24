#include <iostream>
#include <math.h>
using namespace std;


bool check_prime(int p) {
    for (int i = 2; i <= sqrt(p); i++) {
        if (p % i == 0) {
            return false;
        }
    }

    return true;
}


long long solve(int n) {
    long long sum = 0;

    for (int i = 2; i < n; i++) {
        if (check_prime(i) == true) {
            sum += i;
        }
    }

    return sum;
}


int main() {
    cout << solve(2000000) << endl;

    return 0;
}