#include <iostream>

#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

#define MAX_N (100)
#define MAX_W (10000)
int dp[MAX_N + 1][MAX_W + 1];

int main() {
    // input and initialize
    int N, W;
    pair<int, int> vw[MAX_N];
    cin >> N >> W;
    rep(i, N) {
        int v, w;
        cin >> v >> w;
        vw[i] = make_pair(v, w);
    }
    rep(i, N + 1) { dp[i][0] = 0; }
    rep(i, W + 1) { dp[0][i] = 0; }

    // solve
    for (int i = 1; i <= N; i++) {
        int targetV = vw[i - 1].first;
        int targetW = vw[i - 1].second;
        for (int j = 1; j <= W; j++) {
            if (targetW <= j) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - targetW] + targetV);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    // debug
    /*rep(i, N + 1) {
        rep(j, W + 1) { cout << dp[i][j] << " "; }
        cout << endl;
    }*/

    // output
    cout << dp[N][W] << endl;
    return 0;
}