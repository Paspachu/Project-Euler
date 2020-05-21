#include <iostream>
#include <vector>
using namespace std;


vector<int> add_int_to_fraction(vector<int> v, int i) {
    vector<int> t;

    while (i > 0) {
        t.insert(t.begin(), i % 10);
        i = i / 10;
    }

    v.insert(v.end(), t.begin(), t.end());

    return v;
}


vector<int> create_fraction(int n) {
    vector<int> f;
    int i = 1;

    while (f.size() <= n) {
        f = add_int_to_fraction(f, i);
        i++;
    }

    return f;
}


int solve(int n) {
    int answer = 1;
    int i = 1;
    vector<int> v = create_fraction(n);

    while (i <= n) {
        answer *= v[i-1];
        i *= 10;
    }
    cout << endl;

    return answer;
}


int main() {
    cout << solve(1000000) << endl;
    
    return 0;
}