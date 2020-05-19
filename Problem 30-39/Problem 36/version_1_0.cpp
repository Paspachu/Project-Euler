#include <iostream>
#include <vector>
using namespace std;


bool check_decimal_palindromic(int n) {
    vector<int> original;
    vector<int> reverse;

    while (n > 0) {
        original.insert(original.begin(), n % 10);
        reverse.push_back(n % 10);
        n = n / 10;
    }

    if (original == reverse) {
        return true;
    }

    return false;
}


bool check_binary_palindromic(int n) {
    vector<int> original;
    vector<int> reverse;

    while (n > 0) {
        original.insert(original.begin(), n % 2);
        reverse.push_back(n % 2);
        n = n / 2;
    }

    if (original == reverse) {
        return true;
    }

    return false;
}


int solve(int n) {
    int sum = 0;

    for (int i = 1; i < n; i++) {
        if (check_decimal_palindromic(i) && check_binary_palindromic(i)) {
            sum += i;
        }
    }

    return sum;
}


int main() {
    cout << solve(1000000) << endl;

    return 0;
}