#include <iostream>
#include <string>

#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
int dp[1001][1001];
int getLCSNum(string X, string Y) {
    // cout << "getLSMNUM " << X << " " << Y << endl;

    int n_x = X.size();
    int n_y = Y.size();
    X = " " + X;
    Y = " " + Y;
    rep(i, n_x + 1) {
        rep(j, n_y + 1) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if (X[i] == Y[j]) {
                /*cout << "call: " << i << " " << j << X[i] << " " << Y[j]
                     << endl;*/
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[X.size() - 1][Y.size() - 1];
}
int main() {
    int n;
    string X, Y;
    cin >> n;

    rep(i, n) {
        cin >> X >> Y;
        cout << getLCSNum(X, Y) << endl;
    }

    return 0;
}