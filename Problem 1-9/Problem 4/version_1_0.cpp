#include <iostream>
#include <vector>
using namespace std;


bool check_palindromic(int n) {
    vector<int> original;
    vector<int> reverse;

    while (n > 0) {
        original.insert(original.begin(), n % 10);
        reverse.push_back(n % 10);
        n = n/10;
    }

    if (original == reverse) {
        return true;
    }

    return false;
}


int solve() {
    int answer = 0;
    for (int i = 999; i > 900; i --) {
        for (int j = i;  j > 900; j--) {
            if (check_palindromic(i*j) == true) {
                if (i*j > answer) {
                    answer = i*j;
                }
            }
        }
    }

    return answer;
}


int main() {
    cout << solve() << endl;

    return 0;
}