#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

vector<int> primes;


bool check_prime(int p) {
    for (int i = 2; i <= sqrt(p); i++) {
        if (p % i == 0) {
            return false;
        }
    }

    return true;
}


int create_primes(int n) {
    for (int i = 2; i <= n; i++) {
        if (check_prime(i)) {
            primes.push_back(i);
        }
    }

    return 0;
}


int solve(int n) {
    create_primes(n);

    int answer = 0;
    int longest = 0;
    int sum, j;

    for(int i = 0; i < primes.size(); i++) {
        sum = 0;
        j = 0;

        while (sum < n && i+j < primes.size()) {
            if (check_prime(sum) && sum >= answer && j >= longest) {
                answer = sum;
                longest = j;
            }

            sum += primes[i+j];
            j++;
        }
    }

    return answer;
}


int main() {
    cout << solve(1000000) << endl;

    return 0;
}