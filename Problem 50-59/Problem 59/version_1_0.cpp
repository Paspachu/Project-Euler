#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

vector<int> numbers;
vector<int> valid = {32, 34, 39, 40, 41, 43, 44, 46, 47, 58, 59, 91, 93};


void initialize_valid() {
    for (int i = 48; i <= 57; i++) {
        valid.push_back(i);
    }

    for (int i = 65; i <= 90; i++) {
        valid.push_back(i);
    }

    for (int i = 97; i <= 122; i++) {
        valid.push_back(i);
    }
}


bool check_contains(int n) {
    for (int i = 0; i < valid.size(); i++) {
        if (valid[i] == n) {
            return true;
        }
    }

    return false;
}


int read_input() {
    int x;
    ifstream file ("Problem 50-59\\Problem 59\\cipher.txt");
    
    if (file.is_open()) {
        while (file >> x  && file.ignore()) {
            numbers.push_back(x);
        }

        file.close();
    }
    else cout << "Unable to open file";

    return 0;
}


vector<int> find_key() {
    vector<int> key;
    int flag;

    for (int i = 0; i < 3; i++){
        for (int j = 97; j <= 122; j++) {
            flag = 0;

            for (int k = 0; k < numbers.size(); k++) {
                if (k % 3 == i && !check_contains(numbers[k]^j)) {
                    flag = 1;
                    break;
                }
            }

            if (flag == 0) {
                key.push_back(j);
                break;
            }
        }
    }

    return key;
}


int solve() {
    int sum = 0;
    vector<int> key = find_key();

    for (int i = 0; i < numbers.size(); i++) {
        sum += numbers[i]^key[i%3];
    }

    return sum;
}


int main() {
    read_input();
    initialize_valid();
    cout << solve() << endl;

    return 0;
}