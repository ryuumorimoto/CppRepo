#include <iostream>

#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

#define MAXNUM (10000)

int main() {
    int n;
    cin >> n;
    int W[1000];
    bool W_bool[1000];
    int ans = 0;
    int amin = MAXNUM;

    rep(i, n) {
        cin >> W[i];
        if (W[i] < amin) {
            amin = W[i];
        }
        W_bool[i] = false;
    }

    // ソート済み配列の各要素の場所を取得
    int CounterArray[MAXNUM + 1];
    rep(i, MAXNUM + 1) { CounterArray[i] = 0; }
    rep(i, n) { CounterArray[W[i]] += 1; }
    rep(i, MAXNUM + 1) {
        if (i != 0) {
            CounterArray[i] = CounterArray[i - 1] + CounterArray[i];
        }
    }

    // 各サイクルごとにコストを求める
    rep(i, n) {
        if (W_bool[i]) {
            continue;
        }

        int target = W[i];
        int index = i;
        // group内最小値
        int gmin = MAXNUM;
        // gruupの要素
        int ng = 0;
        // group内総和
        int sigmaW = 0;
        while (true) {
            W_bool[index] = true;
            index = CounterArray[target] - 1;
            target = W[index];
            ng += 1;
            sigmaW += target;
            gmin = min(gmin, target);
            if (W_bool[index]) {
                break;
            }
        }
        int internalCost = sigmaW + gmin * (ng - 2);
        int externalCost = sigmaW + gmin + amin * (ng + 1);
        ans += min(internalCost, externalCost);
    }

    cout << ans << endl;

    return 0;
}