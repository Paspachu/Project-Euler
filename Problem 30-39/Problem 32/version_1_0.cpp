#include <iostream>
#include <vector>
using namespace std;


bool check_contains(vector<int> v, int n) {
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == n) {
            return true;
        }
    }

    return false;
}


bool check_pandigital(int a, int b, int c) {
    vector<int> taken;

    while (a > 0) {
        if (check_contains(taken, a % 10) || a % 10 == 0) {
            return false;
        }
        taken.push_back(a % 10);

        a = a / 10;
    }

    while (b > 0) {
        if (check_contains(taken, b % 10) || b % 10 == 0) {
            return false;
        }
        taken.push_back(b % 10);

        b = b / 10;
    }

    while (c > 0) {
        if (check_contains(taken, c % 10) || c % 10 == 0) {
            return false;
        }
        taken.push_back(c % 10);

        c = c / 10;
    }

    return true;
}


int vector_sum(vector<int> v) {
    int sum = 0;

    for (int i = 0; i < v.size(); i++) {
        sum += v[i];
    }

    return sum;
}


int solve() {
    vector<int> answers;

    for (int i = 1; i < 10; i++) {
        for (int j = 1000; j < 10000; j++) {
            if (i*j >= 10000) {
                break;
            }
            if (check_pandigital(i, j, i*j) && !check_contains(answers, i*j)) {
                answers.push_back(i*j);
            }
        }
    }

    for (int i = 10; i < 100; i++) {
        for (int j = 100; j < 1000; j++) {
            if (i*j >= 10000) {
                break;
            }
            if (check_pandigital(i, j, i*j) && !check_contains(answers, i*j)) {
                answers.push_back(i*j);
            }
        }
    }

    return vector_sum(answers);
}


int main() {
    cout << solve() << endl;

    return 0;
}