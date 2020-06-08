#include <iostream>
#include <vector>
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


vector<long long> create_primes(int n) {
    vector<long long> p;

    for (long long i = 2; i <= n; i++) {
        if (check_prime(i)) {
            p.push_back(i);
        }
    }

    return p;
}


bool check_pair_primes(long long x, long long y) {
    long long a, b, c, m;

    a = x; b = y; c = 0; m = 1;

    while (a > 0) {
        c += m * (a % 10);
        a = a / 10;
        m *= 10;
    }

    while (b > 0) {
        c+= m * (b % 10);
        b = b / 10;
        m *= 10;
    }

    if (!check_prime(c)) {
        return false;
    }

    a = x; b = y; c = 0; m = 1;

    while (b > 0) {
        c+= m * (b % 10);
        b = b / 10;
        m *= 10;
    }

    while (a > 0) {
        c += m * (a % 10);
        a = a / 10;
        m *= 10;
    }

    if (!check_prime(c)) {
        return false;
    }

    return true;
}


long long solve() {
    vector<long long> p = create_primes(10000);
    
    for (int i = 0; i < p.size(); i++) {
        for (int j = i+1; j < p.size(); j++) {
            if (!check_pair_primes(p[i], p[j])) {
                continue;
            }

            for (int k = j+1; k < p.size(); k++) {
                if (!check_pair_primes(p[i], p[k]) || !check_pair_primes(p[j], p[k])) {
                    continue;
                }

                for (int l = k+1; l < p.size(); l++) {
                    if (!check_pair_primes(p[i], p[l]) || !check_pair_primes(p[j], p[l]) || !check_pair_primes(p[k], p[l])) {
                        continue;
                    }

                    for (int m = l+1; m < p.size(); m++) {
                        if (check_pair_primes(p[i], p[m]) && check_pair_primes(p[j], p[m]) && check_pair_primes(p[k], p[m]) && check_pair_primes(p[l], p[m])) {
                            cout << p[i] << " " << p[j] << " " << p[k] << " " << p[l] << " " << p[m] << endl;
                            return p[i] + p[j] + p[k] + p[l] + p[m];
                        }
                    }
                }
            }
        }
    }

    return 0;
}



int main() {
    cout << solve() << endl;

    return 0;
}