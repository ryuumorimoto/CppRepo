#include <algorithm>
#include <iostream>

#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

#define MAX_M (20)
#define MAX_N (50000)
#define MAX_VALUE (10000)
int dp[MAX_M + 1][MAX_N + 1];
int main() {
    // input and initialize
    int n, m;
    int coin[MAX_M];
    cin >> n >> m;
    rep(i, m) { cin >> coin[i]; }
    rep(i, m + 1) { dp[i][0] = 0; }
    for (int i = 1; i <= n; i++) {
        dp[0][i] = MAX_N + 1;
    }

    // solve
    sort(coin, coin + m);
    for (int i = 1; i <= m; i++) {
        int targetCoin = coin[i - 1];

        for (int j = 1; j <= n; j++) {
            /*int countK = j / targetCoin;
            int minValue = MAX_N + 1;
            for (int k = 0; k <= countK; k++) {
                minValue = min(minValue, dp[i - 1][j - targetCoin * k] + k);
            }
            dp[i][j] = minValue;*/
            if (targetCoin <= j) {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - targetCoin] + 1);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    // debug
    /*rep(i, m + 1) {
        rep(j, n + 1) { cout << dp[i][j] << " "; }
        cout << endl;
    }*/

    // output
    cout << dp[m][n] << endl;
    return 0;
}