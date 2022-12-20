#include <string.h>

#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
int A[100];
int n;
bool solve(int i, int M) {
    // cout << "i: " << i << " M: " << M << endl;
    if (M == 0) return true;
    if (i >= n) return false;

    return solve(i + 1, M) || solve(i + 1, M - A[i]);
}

bool solve_bit(int M) {
    for (int bit = 0; bit < (1 << n); bit++) {
        int tmp = 0;
        for (int i = 0; i < n; i++) {
            if (bit & (1 << i)) {
                tmp += A[i];
            }
        }
        if (tmp == M) {
            return true;
        }
    }
    return false;
}

int main() {
    int q;
    int M[500];
    cin >> n;
    rep(i, n) { cin >> A[i]; }
    cin >> q;
    rep(i, q) { cin >> M[i]; }

    rep(i, q) {
        // if (solve(0, M[i])) {
        if (solve_bit(M[i])) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }

    return 0;
}