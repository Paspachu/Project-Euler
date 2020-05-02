#include <iostream>
using namespace std;


int solve() {
    int count = 0;
    int d = 1; //Tuesday

    for (int i = 1901; i <= 2000; i++) {
        for (int j = 1; j <= 12; j++) {
            if (j == 2) {
                if (i % 4 == 0) {
                    d = (d + 1) % 7; // 29 days
                }
            } else if (j == 4 || j == 6 || j == 9 || j == 11) {
                d = (d + 2) % 7; // 30 days
            } else {
                d = (d + 3) % 7; // 31 days
            }

            if (d == 6) {
                count++;
            }
        }
    }

    return count;
}


int main() {
    cout << solve() << endl;

    return 0;
}