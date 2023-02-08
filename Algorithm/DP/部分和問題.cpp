#include <iostream>
#include <vector>

#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
#define N_MAX (100)
#define M_MAX (10000)
bool dp[N_MAX][M_MAX];

int main(int argc, char* argv[]) {
    // input
    int N, M;
    cin >> N >> M;
    vector<int> A;
    rep(i, N) {
        int tmp;
        cin >> tmp;
        A.push_back(tmp);
    }

    // solve
    rep(i, N + 1) {
        rep(j, M + 1) {
            if (j == 0) {
                dp[i][0] = true;
            } else {
                dp[i][j] = false;
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            // dp[i][j - A[i-1]]にすると、複数回使えることになる
            dp[i][j] = dp[i - 1][j] | dp[i - 1][j - A[i - 1]];
        }
    }

    if (dp[N][M]) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}