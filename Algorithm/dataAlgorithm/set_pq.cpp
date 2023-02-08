#include <iostream>
#include <queue>
#include <set>
#include <vector>

#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
struct Compare : public binary_function<int, int, bool> {
    bool operator()(const int& first, const int& second) const {
        return first > second;
    }
};
bool lessX(int& first, int& second) { return first > second; }
struct cmp {
    bool operator()(int a, int b) const { return a > b; }
};

int main() {
    set<int, Compare> S;
    S.insert(0);
    S.insert(2);
    S.insert(40);
    S.insert(1);
    // S.erase(2);
    set<int>::iterator it = S.find(2);
    cout << distance(S.begin(), it) << endl;
    cout << *it << endl;
    S.insert(-1);

    for (set<int>::iterator i = S.begin(); i != S.end(); i++) {
        cout << *i << " ";
    }
    cout << endl;

    vector<int> v = {3, 4, 5, 1, 2, 3};
    sort(v.begin(), v.end(), lessX);
    for (vector<int>::iterator i = v.begin(); i != v.end(); i++) {
        cout << *i << " ";
    }
    return 0;
}