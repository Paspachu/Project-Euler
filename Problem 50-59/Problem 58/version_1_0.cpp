#include <iostream>
#include <math.h>
using namespace std;


bool check_prime(long long p) {
    for (long long i = 2; i <= sqrt(p); i++) {
        if (p % i == 0) {
            return false;
        }
    }

    return true;
}


long long solve(double b) {
    long long lr = 1;
    long long rl = 1;
    long long i = 1;
    long long l = 1;
    long long primes = 0;
    long long all = 1;

    while (true) {
        lr += 2*i;
        rl += 4*(((i-1)/2) + 1);

        if (check_prime(lr)) {
            primes++;
        }

        if (check_prime(rl)) {
            primes++;
        }

        all += 2;

        if (i % 2 == 0) {
            l += 2;

            if ((1.0 * primes / all) < b) {
                return l;
            }
        }

        i++;
    }

    return 0;
}


int main() {
    cout << solve(0.1) << endl;

    return 0;
}