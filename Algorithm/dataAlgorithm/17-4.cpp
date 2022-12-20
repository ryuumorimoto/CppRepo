#include <iostream>

#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

#define MAX_HW (1400)
pair<int, int> dp[MAX_HW + 1][MAX_HW + 1];

int main() {
    // input and initialize
    int c[MAX_HW][MAX_HW];
    int H, W;
    cin >> H >> W;
    rep(i, H) {
        rep(j, W) { cin >> c[i][j]; }
    }

    // solve
    int edgeLen = 0;
    for (int i = 0; i <= W; i++) {
        dp[0][i] = make_pair(0, 0);
    }
    for (int i = 1; i <= H; i++) {
        dp[i][0] = make_pair(0, 0);
    }
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            if (!c[i - 1][j - 1]) {
                /*if (edgeLen <= dp[i - 1][j - 1].first &&
                    edgeLen <= dp[i - 1][j - 1].second &&
                    edgeLen <= dp[i - 1][j].first &&
                    edgeLen <= dp[i][j - 1].second) {
                    dp[i][j] = make_pair(edgeLen, edgeLen);
                    edgeLen += 1;
                }*/
                if (dp[i - 1][j].first == 0 && dp[i - 1][j].second == 0) {
                    dp[i][j] = make_pair(1, dp[i][j - 1].second + 1);
                } else if (dp[i][j - 1].first == 0 &&
                           dp[i][j - 1].second == 0) {
                    dp[i][j] = make_pair(dp[i - 1][j].first + 1, 1);
                } else {
                    dp[i][j] = make_pair(
                        min(dp[i - 1][j - 1].first, dp[i - 1][j].first) + 1,
                        min(dp[i][j - 1].second, dp[i - 1][j - 1].second) + 1);
                }

                if (dp[i][j].first == dp[i][j].second &&
                    edgeLen < dp[i][j].first) {
                    edgeLen = dp[i][j].first;
                }

            } else {
                dp[i][j] = make_pair(0, 0);
            }
        }
    }
    // debug
    /*for (int i = 0; i <= H; i++) {
        for (int j = 0; j <= W; j++) {
            cout << " (" << dp[i][j].first << ", " << dp[i][j].second << ") |";
        }
        cout << endl;
    }*/
    cout << edgeLen * edgeLen << endl;
    return 0;
}