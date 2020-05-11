#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

vector<int> abundants;
vector<int> sota;


void print_vector(vector<int> v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << endl;
    }
}


int vector_sum (vector<int> v) {
    int sum = 0;

    for (int i = 0; i < v.size(); i++) {
        sum += v[i];
    }

    return sum;
}


int sum_divisors(int n) {
    int sum = 1;
    
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            sum += i;
            if ((n/i) != i) {
                sum += (n/i);
            }
        }
    }

    return sum;
}


bool check_abundant(int n) {
    return n < sum_divisors(n);
}


void create_abundants() {
    for (int i = 1; i <= 28111; i++) {
        if (check_abundant(i)) {
            abundants.push_back(i);
        }
    }
}


bool check_contains(vector<int> v, int n) {
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == n) {
            return true;
        }
    }

    return false;
}


void create_sum_of_two_abundants() {
    int sum = 0;

    for (int i = 0; i < abundants.size(); i++) {
        for (int j = i; j < abundants.size(); j++) {
            sum = abundants[i] + abundants[j];
            if (sum > 28123) {
                break;
            }

            if (!check_contains(sota, sum)) {
                sota.push_back(sum);
            }
        }
    }
}


int solve() {
    int sum = 0;

    for (int i = 1; i <= 28123; i++) {
        sum += i;
    }

    sum = sum - vector_sum(sota);

    return sum;
}


int main() {
    create_abundants();
    create_sum_of_two_abundants();
    cout << solve() << endl;

    return 0;
}