#include <iostream>
using namespace std;

int n[20][20];


void read_input() {
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            cin >> n[i][j];
        }
    }
}


int solve() {
    int answer;
    int temp;

    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            if (j < 17) {
                temp = n[i][j] * n[i][j+1] * n[i][j+2] * n[i][j+3];
                if (temp >= answer) {
                    answer = temp;
                }
            }

            if (i < 17) {
                temp = n[i][j] * n[i+1][j] * n[i+2][j] * n[i+3][j];
                if (temp >= answer) {
                    answer = temp;
                }
            }

            if (i < 17 && j < 17) {
                temp = n[i][j] * n[i+1][j+1] * n[i+2][j+2] * n[i+3][j+3];
                if (temp >= answer) {
                    answer = temp;
                }
            }

            if (i < 17  && j > 2) {
                temp = n[i][j] * n[i+1][j-1] * n[i+2][j-2] * n[i+3][j-3];
                if (temp >= answer) {
                    answer = temp;
                }
            }
        }
    }
    
    return answer;
}


int main() {
    read_input();
    cout << solve() << endl;

    return 0;
}