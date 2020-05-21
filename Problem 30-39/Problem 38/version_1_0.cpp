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


bool check_pandigital(int a, int b) {
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

    return true;
}


long long solve() {
    long long answer = 0;
    long long temp;

    for (int i = 9999; i >= 9000; i--) {
        temp = i * 100000 + i*2;
        if (check_pandigital(i, i*2) && temp >= answer) {
            answer = temp;
        }
    }

    return answer;
}


int main() {
    cout << solve() << endl;

    return 0;
}