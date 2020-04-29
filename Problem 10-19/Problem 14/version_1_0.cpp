#include <iostream>
using namespace std;


int terms(long long n) {
    int count = 1;

    while (n > 1) {
        if (n % 2 == 1) {
            n = 3*n+1;
        } else {
            n = n/2;
        }

        count++;
    }

    return count;
}


int solve(int n) {
    int answer;
    int longest = 0;

    for (int i = 1; i < n; i++) {
        if (terms(i) >= longest) {
            longest = terms(i);
            answer = i;
        }
    }

    return answer; 
}


int main() {
    cout << solve(1000000) << endl;

    return 0;
}