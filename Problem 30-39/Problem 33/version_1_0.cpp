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


int curious_possible(int a, int b) {
    vector<int> share;

    while (a > 0) {
        share.push_back(a % 10);
        a = a / 10;
    }

    while (b > 0) {
        if (check_contains(share, b % 10)) {
            return b % 10;
        }

        b = b / 10;
    }

    return -1;
}


int get_curious_numerator(int n, int c) {
    int curious_n;

    if (n % 10 == c) {
        curious_n = n / 10;
    } else {
        curious_n = n % 10;
    }

    return curious_n;
}


int get_curious_denominator(int d, int c) {
    int curious_d;

    if (d % 10 == c) {
        curious_d = d / 10;
    } else {
        curious_d = d % 10;
    }

    return curious_d;
}


int gcd(int a, int b) {
    if (a % b == 0) {
        return b;
    }
    return gcd(b, a % b);
}


vector<int> lowest_fraction(int a, int b) {
    vector<int> f;
    int g = gcd(a, b);

    f.push_back(a/g);
    f.push_back(b/g);

    return f;
}


int solve() {
    int c, curious_i, curious_j;
    int n = 1;
    int d = 1;

    for (int i = 10; i < 100; i++) {
        for (int j = i+1; j < 100; j++) {
            if (i % 10 == 0 || j % 10 == 0) {
                continue;
            }

            c = curious_possible(i, j);
            if (c < 0) {
                continue;
            }

            curious_i = get_curious_numerator(i, c);
            curious_j = get_curious_numerator(j, c);

            if (lowest_fraction(i, j) != lowest_fraction(curious_i, curious_j)) {
                continue;
            } else {
                n *= lowest_fraction(i, j)[0];
                d *= lowest_fraction(i, j)[1];
            }
        }
    }

    return lowest_fraction(n, d)[1];
}


int main() {
    cout << solve() << endl;

    return 0;
}