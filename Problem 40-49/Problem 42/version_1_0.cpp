#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

vector<string> words;
vector<int> numbers;


int vector_read(vector<string> v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << endl;
    }

    return 0;
}


int vector_print(vector<int> v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }

    cout << endl;

    return 0;
}


int read_input() {
    string line;
    ifstream file ("Problem 40-49\\Problem 42\\words.txt");
    
    if (file.is_open()) {
        while (getline(file, line, ',')) {
            line.erase(0, 1);
            line.pop_back();
            words.push_back(line);
        }
        file.close();
    }
    else cout << "Unable to open file";

    return 0;
}


int word_value(string s) {
    int value = 0;

    for (int i = 0; i < s.length(); i++) {
        value += ((int)s.at(i)-64);
    }

    return value;
}


int create_triangle_numbers() {
    numbers.push_back(1);

    for (int i = 2; i <= 100; i++) {
        numbers.push_back(i + numbers[i-2]);
    }

    return 0;
}


bool check_contains_tweaked(vector<int> v, int n) {
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == n) {
            return true;
        }

        if (v[i] > n) {
            return false;
        }
    }

    return false;
}


int solve() {
    int count = 0;
    int t;

    for (int i = 0; i < words.size(); i++) {
        t = word_value(words[i]);
        if (check_contains_tweaked(numbers, t)) {
            count++;
        }
    }

    return count;
}


int main() {
    read_input();
    create_triangle_numbers();

    cout << solve() << endl;

    return 0;
}
