#include <iostream>
using namespace std;


int gcd(int a, int b) {
    if (a % b == 0) {
        return b;
    }
    return gcd(b, a % b);
}


int solve(int n) {
    int answer = 1;
    int d;

    for (int i = 2; i <= n; i++) {
        if (answer > i) {
            d = gcd(answer, i);
        } else {
            d = gcd(i, answer);
        }
        answer *= (i/d);
    }

    return answer;
}


int main() {
    cout << solve(20) << endl;

    return 0;
}