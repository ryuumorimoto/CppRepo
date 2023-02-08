#include <iostream>

#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
#define MAXNUM (45)
int dp[MAXNUM];
int fib(int n) {
    if (dp[n] != -1) {
        return dp[n];
    } else {
        dp[n] = fib(n - 1) + fib(n - 2);
        return dp[n];
    }
}
int main() {
    int n;
    cin >> n;
    rep(i, MAXNUM) { dp[i] = -1; }
    dp[0] = 1;
    dp[1] = 1;

    cout << fib(n) << endl;

    return 0;
}