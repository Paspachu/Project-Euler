#include <iostream>
using namespace std;


long long solve(long long n) {
    long long sum_of_squares = 0;
    long long square_of_sum = 0;

    for (long long i = 1; i <= n; i++) {
        sum_of_squares += i*i;
        square_of_sum += i;
    }
    square_of_sum *= square_of_sum;

    return (square_of_sum - sum_of_squares);
}


int main() {
    cout << solve(100) << endl;

    return 0;
}