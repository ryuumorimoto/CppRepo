#include <iostream>

#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
#define MAXNUM 10000

int main() {
    int n;
    cin >> n;
    int W[1000];
    int CounterArray[MAXNUM + 1];
    int isExistArray[MAXNUM + 1];
    int whereArray[MAXNUM + 1];
    int ans = 0;

    rep(i, MAXNUM + 1) { isExistArray[i] = 0; }
    rep(i, n) { cin >> W[i]; }

    rep(i, n) {
        isExistArray[W[i]] += 1;
        whereArray[W[i]] = i;
    }
    rep(i, MAXNUM + 1) {
        if (i != 0) {
            CounterArray[i] = CounterArray[i - 1] + isExistArray[i];
        }
    }

    rep(i, MAXNUM + 1) {
        int target = MAXNUM - i;
        if (isExistArray[target] > 0) {
            if (target != W[CounterArray[target] - 1]) {
                int tmp = W[CounterArray[target] - 1];
                cout << target << " " << tmp << endl;
                ans += (target + tmp);
                swap(W[whereArray[target]], W[CounterArray[target] - 1]);
                swap(whereArray[target], whereArray[tmp]);
                rep(i, n) { cout << W[i] << " "; }
                cout << endl;
                // W[CounterArray[target] - 1] = target;
                /*if (W[CounterArray[tmp] - 1] == target) {
                    isExistArray[tmp] -= 1;
                }*/
            }
        }
    }

    cout << ans << endl;

    return 0;
}