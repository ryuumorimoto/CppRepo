#include <iostream>
#include <stack>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

#define MAX_HW (1400)
int dp[MAX_HW + 1][MAX_HW + 1];

int getMaxRectangleFromHistogram(int *histogram, int len) {
    stack<pair<int, int> > st;
    int maxValue = 0;
    histogram[len] = 0;
    rep(i, len + 1) {
        if (st.empty() || st.top().first < histogram[i]) {
            // cout << "push: " << i << " " << histogram[i] << endl;
            st.push(make_pair(histogram[i], i));
        } else if (histogram[i] < st.top().first) {
            int position;
            while (!st.empty() && histogram[i] < st.top().first) {
                int height = st.top().first;
                int left = st.top().second;
                st.pop();
                maxValue = max(maxValue, height * (i - left));
                // cout << "pop: " << left << " " << height * (i - left) <<
                // endl;
                position = left;
            }
            st.push(make_pair(histogram[i], position));
        }
    }
    // cout << maxValue << endl;
    return maxValue;
}
int main() {
    // input and initialize
    int c[MAX_HW][MAX_HW];
    int H, W;
    cin >> H >> W;
    rep(i, H) {
        rep(j, W) { cin >> c[i][j]; }
    }

    // solve
    // make dp table
    int ans = 0;
    rep(i, H) {
        rep(j, W) {
            if (i == 0) {
                dp[i][j] = c[i][j] ? 0 : 1;
            } else {
                dp[i][j] = c[i][j] ? 0 : dp[i - 1][j] + 1;
            }
        }
    }
    rep(i, H) {
        ans = max(ans, getMaxRectangleFromHistogram(dp[i], W));
        // cout << i << " endl" << endl;
    }

    // debug
    /*for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cout << " (" << dp[i][j] << ")| ";
        }
        cout << endl;
    }*/
    cout << ans << endl;
    return 0;
}