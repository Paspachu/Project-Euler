#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

vector<string> hands;


int read_input() {
    string s;
    ifstream file ("Problem 50-59\\Problem 54\\poker.txt");
    
    if (file.is_open()) {
        while (file >> s) {
            hands.push_back(s);
        }
        file.close();
    }
    else cout << "Unable to open file";

    return 0;
}


vector<vector<int>> evaluate_hand(vector<string> h) {
    vector<vector<int>> v;
    vector<int> t;
    char c;

    for (int i = 0; i < 13; i++) {
        t.push_back(0);
    }
    
    v.push_back(t);
    t.clear();

    for (int i = 0; i < 4; i++) {
        t.push_back(0);
    }

    v.push_back(t);
    t.clear();

    for (int i = 0; i < h.size(); i++) {
        c = h[i].at(0);

        if ((int)c-50 > 7) {
            if (c == 'T') {
                v[0][8]++;
            } else if (c == 'J') {
                v[0][9]++;
            } else if (c == 'Q') {
                v[0][10]++;
            } else if (c == 'K') {
                v[0][11]++;
            } else {
                v[0][12]++;
            }
        } else {
            v[0][(int)c-50]++;
        }

        c = h[i].at(1);

        if (c == 'D') {
            v[1][0]++;
        } else if (c == 'H') {
            v[1][1]++;
        } else if (c == 'C') {
            v[1][2]++;
        } else {
            v[1][3]++;
        }
    }

    return v;
}


vector<int> check_royal_flush(vector<vector<int>> v) {
    for (int i = 12; i > 7; i--) {
        if (v[0][i] != 1) {
            return {};
        }
    }

    int flag = 0;

    for (int i = 0; i < 4; i++) {
        if (v[1][i] == 5) {
            flag = 1;
        }
    }

    if (flag == 0) {
        return {};
    }

    return {1};
}


vector<int> check_straight_flush(vector<vector<int>> v) {
    int flag = 0;

    for (int i = 0; i < 4; i++) {
        if (v[1][i] == 5) {
            flag = 1;
        }
    }

    if (flag == 0) {
        return {};
    }

    for (int i = 0; i < 9; i++) {
        if (v[0][i] == 0) {
            continue;
        }

        for (int j = 0; j < 5; j++) {
            if (v[0][i+j] != 1) {
                return {};
            }
        }

        return {i+4};
    }

    return {};
}


vector<int> check_four_of_a_kind(vector<vector<int>> v) {
    vector<int> u;

    for (int i = 0; i < 13; i++) {
        if (v[0][i] == 4) {
            u.push_back(i);
            
            for (int j = 0; j < 13; j++) {
                if (v[0][j] == 1) {
                    u.push_back(j);
                }
            }

            return u;
        }
    }

    return {};
}


vector<int> check_full_house(vector<vector<int>> v) {
    int f2 = 0;
    int f3 = 0;
    vector<int> u;
    
    for (int i = 0; i < 13; i++) {
        if (v[0][i] == 2) {
            f2 = 1;
            u.push_back(i);
        }

        if (v[0][i] == 3) {
            f3 = 1;
            u.insert(u.begin(), i);
        }
    }

    if (f2 == 1 && f3 == 1) {
        return u;
    }

    return {};
} 


vector<int> check_flush(vector<vector<int>> v) {
    vector<int> u;

    for (int i = 0; i < 4; i++) {
        if (v[1][i] == 5) {
            for (int j = 12; j >= 0; j--) {
                if (v[0][j] == 1) {
                    u.push_back(j);
                }
            }

            return u; 
        }
    }

    return {};
}


vector<int> check_straight(vector<vector<int>> v) {
    for (int i = 0; i < 9; i++) {
        if (v[0][i] == 0) {
            continue;
        }

        for (int j = 0; j < 5; j++) {
            if (v[0][i+j] != 1) {
                return {};
            }
        }

        return {i+4};
    }

    return {};
}


vector<int> check_three_of_a_kind(vector<vector<int>> v) {
    vector<int> u;

    for (int i = 0; i < 13; i++) {
        if (v[0][i] == 3) {
            u.push_back(i);
            
            for (int j = 12; j >= 0; j--) {
                if (v[0][j] == 1) {
                    u.push_back(j);
                }
            }

            return u;
        }
    }

    return {};
}


vector<int> check_two_pairs(vector<vector<int>> v) {
    vector<int> u;
    int flag = 0;

    for (int i = 12; i >= 0; i--) {
        if (v[0][i] == 2) {
            u.push_back(i);
            flag++;
        }
    }

    if (flag == 2) {
        for (int i = 12; i >= 0; i--) {
            if (v[0][i] == 1) {
                u.push_back(i);
            }
        }

        return u;
    }

    return {};
}


vector<int> check_one_pair(vector<vector<int>> v) {
    vector<int> u;

    for (int i = 0; i < 13; i++) {
        if (v[0][i] == 2) {
            u.push_back(i);

            for (int i = 12; i >= 0; i--) {
                if (v[0][i] == 1) {
                    u.push_back(i);
                }
            }

            return u;
        }
    }

    return {};
}


vector<int> check_high_card(vector<vector<int>> v) {
    vector<int> u;

    for (int i = 12; i >= 0; i--) {
        if (v[0][i] == 1) {
            u.push_back(i);
        }
    }

    return u;
}


vector<int> hand_rank(vector<vector<int>> h) {
    vector<int> r;

    r = check_royal_flush(h);
    if (r.size() > 0) {
        r.insert(r.begin(), 10);
        return r;
    }

    r = check_straight_flush(h);
    if (r.size() > 0) {
        r.insert(r.begin(), 9);
        return r;
    }

    r = check_four_of_a_kind(h);
    if (r.size() > 0) {
        r.insert(r.begin(), 8);
        return r;
    }

    r = check_full_house(h);
    if (r.size() > 0) {
        r.insert(r.begin(), 7);
        return r;
    }

    r = check_flush(h);
    if (r.size() > 0) {
        r.insert(r.begin(), 6);
        return r;
    }

    r = check_straight(h);
    if (r.size() > 0) {
        r.insert(r.begin(), 5);
        return r;
    }

    r = check_three_of_a_kind(h);
    if (r.size() > 0) {
        r.insert(r.begin(), 4);
        return r;
    }

    r = check_two_pairs(h);
    if (r.size() > 0) {
        r.insert(r.begin(), 3);
        return r;
    }

    r = check_one_pair(h);
    if (r.size() > 0) {
        r.insert(r.begin(), 2);
        return r;
    }

    r = check_high_card(h);
    if (r.size() > 0) {
        r.insert(r.begin(), 1);
        return r;
    }

    return {};
}


int winner(vector<string> line) {
    vector<string> player1(line.begin(), line.begin()+5);
    vector<string> player2(line.begin()+5, line.end());

    vector<vector<int>> p1 = evaluate_hand(player1);
    vector<vector<int>> p2 = evaluate_hand(player2);

    vector<int> r1 = hand_rank(p1);
    vector<int> r2 = hand_rank(p2);

    int i = 0;

    while (true) {
        if (r1[i] > r2[i]) {
            return 1;
        } else if (r1[i] < r2[i]) {
            return 2;
        } else {
            i++;
        }
    }

    return 0;
}



int solve() {
    int i = 0;
    int count = 0;

    while (i < hands.size()) {
        vector<string> t(hands.begin()+i, hands.begin()+i+10);

        if (winner(t) == 1) {
            count++;
        }

        i += 10;
    }

    return count;
}


int main() {
    read_input();

    cout << solve() << endl;

    return 0;
}