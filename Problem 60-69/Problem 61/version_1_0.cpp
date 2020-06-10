#include <iostream>
#include <vector>
using namespace std;

vector<int> triangle;
vector<int> square;
vector<int> pentagon;
vector<int> hexagon;
vector<int> heptagon;
vector<int> octagon;
vector<int> all;


void vector_print(vector<int> v) {
    for (int i = 0; i < v.size() ; i++) {
        cout << v[i] << " ";
    }

    cout << endl;
}


bool check_contains(vector<int> v, int n) {
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == n) {
            return true;
        }
    }

    return false;
}


int vector_sum(vector<int> v) {
    int sum = 0;

    for (int i = 0; i < v.size(); i++){
        sum += v[i];
    }

    return sum;
}


void create_triangle() {    
    int p = 0;
    int n = 1;

    while (p < 10000) {
        p = n * (n + 1) / 2;

        if (p > 999 && p < 10000) {
            triangle.push_back(p);
        }

        n++;
    }
}


void create_square() {    
    int p = 0;
    int n = 1;

    while (p < 10000) {
        p = n * n;

        if (p > 999 && p < 10000) {
            square.push_back(p);
        }

        n++;
    }
}


void create_pentagon() {    
    int p = 0;
    int n = 1;

    while (p < 10000) {
        p = n * (3*n - 1) / 2;

        if (p > 999 && p < 10000) {
            pentagon.push_back(p);
        }

        n++;
    }
}


void create_hexagon() {    
    int p = 0;
    int n = 1;

    while (p < 10000) {
        p = n * (2*n - 1);

        if (p > 999 && p < 10000) {
            hexagon.push_back(p);
        }

        n++;
    }
}


void create_heptagon() {    
    int p = 0;
    int n = 1;

    while (p < 10000) {
        p = n * (5*n - 3) / 2;

        if (p > 999 && p < 10000) {
            heptagon.push_back(p);
        }

        n++;
    }
}


void create_octagon() {    
    int p = 0;
    int n = 1;

    while (p < 10000) {
        p = n * (3*n - 2);

        if (p > 999 && p < 10000) {
            octagon.push_back(p);
        }

        n++;
    }
}


void create_all() {
    int p = 0;
    int n = 1;

    while (true) {
        p = n * (n + 1) / 2;

        if (p > 10000) {
            break;
        }

        if (p > 1000 && !check_contains(all, p)) {
            all.push_back(p);
        }

        p = n * n;
        if (p > 1000 && p < 10000 && !check_contains(all, p)) {
            all.push_back(p);
        }

        p = n * (3*n - 1) / 2;
        if (p > 1000 && p < 10000 && !check_contains(all, p)) {
            all.push_back(p);
        }

        p = n * (2*n - 1);
        if (p > 1000 && p < 10000 && !check_contains(all, p)) {
            all.push_back(p);
        }

        p = n * (5*n - 3) / 2;
        if (p > 1000 && p < 10000 && !check_contains(all, p)) {
            all.push_back(p);
        }

        p = n * (3*n - 2);
        if (p > 1000 && p < 10000 && !check_contains(all, p)) {
            all.push_back(p);
        }

        n++;
    }
}


bool check_distinct(vector<int> v) {
    vector<int> c = {0, 0, 0, 0, 0, 0};

    for (int i = 0; i < v.size(); i++) {
        if (check_contains(triangle, v[i])) {
            c[0]++;
        }

        if (check_contains(square, v[i])) {
            c[1]++;
        }

        if (check_contains(pentagon, v[i])) {
            c[2]++;
        }

        if (check_contains(hexagon, v[i])) {
            c[3]++;
        }

        if (check_contains(heptagon, v[i])) {
            c[4]++;
        }

        if (check_contains(octagon, v[i])) {
            c[5]++;
        }
    }

    for (int i = 1; i < c.size(); i++) {
        if (c[i] != 1) {
            return false;
        }
    }

    return true;
}


vector<int> possibles(int n) {
    vector<int> p;

    n *= 100;

    for (int i = 0; i < all.size(); i++) {
        if (all[i] > n && all[i] < (n + 100)) {
            p.push_back(all[i]);   
        }
    }

    return p;
}


vector<int> solve() {
    vector<int> t1, t2, t3, t4, t5, t6, answer;

    for (int a = all.size()-1; a >= 0; a--) {
        answer.push_back(all[a]);

        t1 = possibles(all[a] % 100);

        if (t1.size() < 1) {
            answer.pop_back();
            continue;
        }

        for (int b = 0; b < t1.size(); b++) {
            answer.push_back(t1[b]);

            t2 = possibles(t1[b] % 100);

            if (t2.size() < 1) {
                answer.pop_back();
                continue;
            }

            for (int c = 0; c < t2.size(); c++) {
                answer.push_back(t2[c]);

                t3 = possibles(t2[c] % 100);

                if (t3.size() < 1) {
                    answer.pop_back();
                    continue;
                }

                for (int d = 0; d < t3.size(); d++) {
                    answer.push_back(t3[d]);

                    t4 = possibles(t3[d] % 100);

                    if (t4.size() < 1) {
                        answer.pop_back();
                        continue;
                    }

                    for (int e = 0; e < t4.size(); e++) {
                        answer.push_back(t4[e]);

                        t5 = possibles(t4[e] % 100);

                        if (t5.size() < 1) {
                            answer.pop_back();
                            continue;
                        }

                        for (int f = 0; f < t5.size(); f++) {
                            answer.push_back(t5[f]);

                            t6 = possibles(t5[f] % 100);

                            if (t6.size() < 1) {
                                answer.pop_back();
                                continue;
                            }

                            for (int g = 0; g < t6.size(); g++) {
                                if (t6[g] == answer[0] && check_distinct(answer)) {
                                    return answer;
                                }
                            }

                            answer.pop_back();
                        }

                        answer.pop_back();
                    }

                    answer.pop_back();
                }

                answer.pop_back();
            }

            answer.pop_back();
        }

        answer.pop_back();
    }

    return {};
}


int main() {
    create_triangle();
    create_square();
    create_pentagon();
    create_hexagon();
    create_heptagon();
    create_octagon();
    create_all();
    
    vector<int> v = solve();
    vector_print(v);
    cout << vector_sum(v) << endl;

    return 0;
}

