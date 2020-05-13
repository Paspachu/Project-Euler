#include <iostream>
#include <vector>
using namespace std;


int check_contains(vector<int> v, int n) {
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == n) {
            return i;
        }
    }

    return -1;
}


int cycle_length(int d) {
    vector<int> taken;
    int remainder = 1;
    int digit;

    while (check_contains(taken, remainder) < 0) {
        if ((remainder * 10) % d == 0) {
            return 0;
        }

        taken.push_back(remainder);
        remainder = (remainder * 10) % d;
    }

    return taken.size() - check_contains(taken, remainder);
}


int solve(int n) {
    int longest = 0;
    int answer = -1;
    
    for (int i = 2; i < n; i++) {
        if (cycle_length(i) >= longest) {
            longest = cycle_length(i);
            answer = i;
        }
    }

    return answer;
}


int main() {
    cout << solve(1000) << endl;

    return 0;
}