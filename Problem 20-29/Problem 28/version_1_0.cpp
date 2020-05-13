#include <iostream>
using namespace std;


int solve(int n) {
    int answer = 1;
    int lr = 1;
    int rl = 1;

    for (int i = 1; i < n; i++) {
        lr += 2*i;
        rl += 4*(((i-1)/2) + 1);

        answer += lr + rl; 
    }

    return answer;
}


int main() {
    cout << solve(1001) << endl;

    return 0;
}

