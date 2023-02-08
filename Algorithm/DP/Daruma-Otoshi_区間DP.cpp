#include <cmath>
#include <iostream>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

#define N_MAX (300)
int W[N_MAX + 1];
int dp[N_MAX + 1][N_MAX + 1];

int getCountofDaruma(int n) {
    rep(i, n + 1) {
        rep(j, n + 1) { dp[i][j] = 0; }
    }
    for (int dr = 1; dr <= n - 1; dr++) {
        for (int l = 1; l + dr <= n; l++) {
            int r = l + dr;
            if (abs(W[l] - W[r]) <= 1 && dp[l + 1][r - 1] == (r - l - 1)) {
                dp[l][r] = r - l - 1 + 2;
            } else {
                for (int mid = l; mid <= r; mid++) {
                    dp[l][r] = max(dp[l][r], dp[l][mid] + dp[mid + 1][r]);
                }
            }
        }
    }
    return dp[1][n];
}

int main() {
    int n;
    while (true) {
        cin >> n;
        if (n == 0) {
            break;
        } else {
            rep(i, n) { cin >> W[i + 1]; }
            cout << getCountofDaruma(n) << endl;
        }
    }
    return 0;
}