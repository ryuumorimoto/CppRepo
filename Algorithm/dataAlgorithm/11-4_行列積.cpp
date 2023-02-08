#include <stdint.h>

#include <iostream>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
#define MAXNUM (100)
int P[MAXNUM + 1];
long long dp[MAXNUM + 1][MAXNUM + 1];

int main() {
    // input
    int n;
    cin >> n;
    rep(i, n) {
        int vertical, horizontal;
        cin >> vertical >> horizontal;
        if (i == 0) {
            P[i] = vertical;
            P[i + 1] = horizontal;
        } else {
            P[i + 1] = horizontal;
        }
    }

    // initialize
    rep(i, MAXNUM + 1) {
        rep(j, MAXNUM + 1) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } else {
                dp[i][j] = INT64_MAX;
            }
        }
    }

    // solve
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n - i + 1; j++) {
            int left = j;
            int right = j + i - 1;
            if (left == right) {
                dp[left][right] = 0;
            } else {
                for (int k = left; k < right; k++) {
                    dp[left][right] =
                        min(dp[left][right], dp[left][k] + dp[k + 1][right] +
                                                 P[left - 1] * P[k] * P[right]);
                }
            }
        }
    }
    cout << dp[1][n] << endl;

    return 0;
}