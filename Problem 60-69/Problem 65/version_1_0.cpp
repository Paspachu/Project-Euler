#include <iostream>
#include <vector>
#include "vector_int.h"
using namespace std;

vector<vector<int>> eseq;

struct fraction {
    vector<int> num;
    vector<int> den;
};


void create_eseq(int n) {
    vector<int> k = {2};
    vector<int> vtwo = {2};
    eseq.push_back(k);

    for (int i = 1; i < n; i++) {
        if (i % 3 == 2) {
            eseq.push_back(k);
            k = k + vtwo;
        } else {
            eseq.push_back(vone);
        }
    }
}


void print_vector(vector<int> v) {
    for (int i = v.size()-1; i >= 0; i--) {
        cout << v[i];
    }
}


void print_2dvector(vector<vector<int>> v) {
    for (int i = 0; i < v.size(); i++) {
        for (int j = v[i].size()-1; j >= 0; j--) {
            cout << v[i][j];
        }

        cout << " ";
    }

    cout << endl;
}


void print_fraction(fraction f) {
    print_vector(f.num);
    cout << " / ";
    print_vector(f.den);
}


vector<int> gcd(vector<int> a, vector<int> b) {
    if (a % b == vzero) {
        return b;
    }

    return gcd(b, a % b);
}


vector<int> lcm(vector<int> a, vector<int> b) {
    vector<int> c = gcd(a, b);
    return a * b / c;
}


fraction simplify(fraction f) {
    fraction g;
    vector<int> c = gcd(f.num, f.den);

    g.num = f.num / c;
    g.den = f.den / c;

    return g;
}


fraction add_fraction(fraction a, fraction b) {
    fraction c;
    vector<int> l = lcm(a.den, b.den);

    c.den = l;
    c.num = a.num * (l / a.den) + b.num * (l / b.den);

    return simplify(c);
}


fraction flip(fraction f) {
    fraction g;
    
    g.num = f.den;
    g.den = f.num;

    return g;
}


fraction e_const(int n) {
    fraction f, t;

    if (n == 1) {
        f.num = eseq[0];
        f.den = vone;
        return f;
    }

    f.num = eseq[n-1];
    f.den = vone;

    for (int i = n-1; i >= 1; i--) {
        f = flip(f);
        t.num = eseq[i-1];
        t.den = vone;
        f = add_fraction(t, f);
    }

    return f;
}


int sum_of_digits(vector<int> v) {
    int sum = 0;

    for (int i = 0; i < v.size(); i++) {
        sum += v[i];
    }

    return sum;
}


int solve(int n) {
    create_eseq(n);
    fraction f = e_const(n);

    return sum_of_digits(f.num);
}


int main() {
    cout << solve(100) << endl;

    return 0;
}