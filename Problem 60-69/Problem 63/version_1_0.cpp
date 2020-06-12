#include <iostream>
#include <vector>
#include "vector_int.h"
using namespace std;


int solve(int b) {
    int count = 0;
    vector<int> n;
    vector<int> vone = {1};

    for (int i = 1; i < b; i++) {
        n = {1};

        while (pow(n, i) < pow({0, 1}, i)) {
            if (pow(n, i).size() == i) {
                print(pow(n, i));
                count++;
            }

            n = n + vone;
        }

        cout << endl;
    }

    return count;
}


int main() {
    cout << solve(22) << endl;

    return 0;
}