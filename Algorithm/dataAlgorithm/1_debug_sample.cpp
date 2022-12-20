#include <iostream>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

int main() {
    vector<int> v;
    int n;
    cin >> n;
    rep(i, n) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }

    cout << "output" << endl;
    rep(i, n) { cout << v[i] << endl; }

    return 0;
}