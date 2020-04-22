#include <iostream>
#include <math.h>
using namespace std;

long long solve(long long p) {
    for (long long i = 2; i < sqrt(p); i++) {
        if (p % i == 0) {
            return solve(p/i);
        }
    }
    return p;
}

int main() {
    cout << solve(600851475143) << endl;

    return 0;
}

