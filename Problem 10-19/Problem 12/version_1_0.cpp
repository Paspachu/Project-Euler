#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;


int num_divisors(int n) {
    vector<int> divisors;

    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
           if (find(divisors.begin(), divisors.end(), i) == divisors.end()) {
               divisors.push_back(i);
           }
           if (find(divisors.begin(), divisors.end(), n/i) == divisors.end()) {
               divisors.push_back(n/i);
           }
        }
    }

    return divisors.size();
}


int solve(int d) {
    int triangle_number = 1;
    int i = 2;

    while (num_divisors(triangle_number) < d) {
        triangle_number += i;
        i++;
    }

    return triangle_number;
}


int main() {
    cout << solve(500) << endl;

    return 0;
}