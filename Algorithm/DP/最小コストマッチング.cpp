#include <limits.h>

#include <iostream>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
#define N_MAX (100)
#define M_MAX (100)
int costArray[N_MAX + 1][M_MAX + 1];
int dp[N_MAX + 1][M_MAX + 1];

int main() {
    int n, m;
    cin >> n >> m;
    rep(i, n) {
        rep(j, m) { cin >> costArray[i + 1][j + 1]; }
    }
    rep(i, n + 1) {
        rep(j, m + 1) {
            if (i == 0 && j == 0) {
                dp[i][j] = 0;
            } else if (i == 0 || j == 0) {
                dp[i][j] = INT32_MAX;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = min(dp[i][j - 1], min(dp[i - 1][j - 1], dp[i - 1][j])) +
                       costArray[i][j];
        }
    }
    cout << dp[n][m] << endl;

    return 0;
}