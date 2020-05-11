#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

vector<string> names;


int vector_read(vector<string> v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << endl;
    }

    return 0;
}


int read_input() {
    string line;
    ifstream file ("Problem 20-29\\Problem 22\\names.txt");
    
    if (file.is_open()) {
        while (getline(file, line, ',')) {
            line.erase(0, 1);
            line.pop_back();
            names.push_back(line);
        }
        file.close();
    }
    else cout << "Unable to open file";

    return 0;
}


vector<string> merge(vector<string> v1, vector<string> v2) {
    vector<string> v3;

    while (!v1.empty() && !v2.empty()) {
        if (v1[0] > v2[0]) {
            v3.push_back(v2[0]);
            v2.erase(v2.begin());
        } else {
            v3.push_back(v1[0]);
            v1.erase(v1.begin());
        }
    }

    while (!v1.empty()) {
        v3.push_back(v1[0]);
        v1.erase(v1.begin());
    }

    while (!v2.empty()) {
        v3.push_back(v2[0]);
        v2.erase(v2.begin());
    }

    return v3;
}


vector<string> merge_sort(vector<string> v) {
    if (v.size() == 1) {
        return v;
    }

    vector<string> v1, v2;

    for (int i = 0; i < (v.size()/2); i++) {
        v1.push_back(v[i]);
    }
    for (int i = (v.size()/2); i < v.size(); i++) {
        v2.push_back(v[i]);
    }

    v1 = merge_sort(v1);
    v2 = merge_sort(v2);

    return merge(v1, v2);
}


int name_score(string s, int p) {
    int score = 0;

    for (int i = 0; i < s.length(); i++) {
        score = score + ((int)s.at(i)-64);
    }

    score *= p;

    return score;
}


long long solve() {
    long long sum = 0;

    for (int i = 0; i < names.size(); i++) {
        sum += name_score(names[i], i+1);
    }

    return sum;
}


int main() {
    read_input();
    names = merge_sort(names);
    cout << solve() << endl;

    return 0;
}