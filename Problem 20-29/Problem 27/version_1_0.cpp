#include <iostream>
#include <math.h>
using namespace std;


bool check_prime(int p) {
    if (p < 2) {
        return false;
    }

    for (int i = 2; i <= sqrt(p); i++) {
        if (p % i == 0) {
            return false;
        }
    }

    return true;
}


int number_of_primes(int a, int b) {
    int n = 0;
    
    while (check_prime(n*n + a*n + b)) {
        n++;
    }

    return n;
}


int solve(int n) {
    int highest = 0;
    int answer;
    int t;

    for (int a = -(n-1); a < n; a++) {
        for (int b = -n; b <= n; b++) {
            t = number_of_primes(a, b);
            if (t >= highest) {
                answer = a*b;
                highest = t;
            }
        }
    }
    
    return answer;
}


int main() {
    cout << solve(1000) << endl;

    return 0;
}