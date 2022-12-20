#include <string.h>

#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

bool canDivide(int* W, int n, int P, int k) {
    int tmp = 0;
    int num = 0;
    rep(i, n) {
        if (tmp + W[i] <= P) {
            tmp += W[i];
        } else {
            num += 1;
            if (num == k) {
                return false;
            }
            tmp = W[i];
            if (tmp > P) {
                return false;
            }
        }
    }
    return true;
}
int main() {
    int n, k;
    cin >> n;
    cin >> k;
    int W[100000];
    int sum = 0;
    rep(i, n) {
        cin >> W[i];
        sum += W[i];
    }

    int P;
    int left = 0;
    int right = sum;
    while (left <= right) {
        P = (left + right) / 2;
        if (canDivide(W, n, P, k)) {
            // cout << "can divide at: ";
            right = P;
            if (left == right) {
                break;
            }
        } else {
            // cout << "can't divide at: ";
            left = P + 1;
        }
        // cout << P << endl;
    }

    cout << P << endl;
    return 0;
}