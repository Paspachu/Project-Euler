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


bool check_composite(int c) {
    for (int i = 2; i <= sqrt(c); i++) {
        if (c % i == 0) {
            return true;
        }
    }

    return false;
}


bool check_goldbach(int n) {
    int i = 1;

    while (2*i*i < n) {
        if (check_prime(n-2*i*i)) {
            return true;
        }

        i++;
    }

    return false;
}


int solve() {
    int i = 9;
    while (true) {
        if (!check_composite(i)) {
            i += 2;
            continue;
        }

        if (!check_goldbach(i)) {
            return i;
        }

        i += 2;
    }

    return 0;
}


int main() {
    cout << solve() << endl;

    return 0;
}