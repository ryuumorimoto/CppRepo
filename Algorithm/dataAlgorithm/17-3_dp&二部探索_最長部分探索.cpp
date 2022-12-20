#include <algorithm>
#include <iostream>

#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

#define MAX_N (100000)
#define MAX_VALUE (1000000000)

int dp[MAX_N];
int A[MAX_N];

int main() {
    // input and initialize
    int n;
    int ans = 0;
    cin >> n;
    rep(i, n) { cin >> A[i]; }

    // solve
    dp[0] = A[0];
    ans = 1;
    for (int i = 1; i < n; i++) {
        int target = A[i];
        if (dp[ans - 1] < target) {
            dp[ans] = target;
            ans += 1;
        } else if (target < dp[ans - 1]) {
            *lower_bound(dp, dp + ans, target) = target;
        }
    }

    // output
    cout << ans << endl;

    return 0;
}