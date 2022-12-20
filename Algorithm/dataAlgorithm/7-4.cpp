#include <iostream>

#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

#define MAXNUM (10000)

void counttingSort(int* array, int n, int* dst) {
    int* CounterArray = new int[MAXNUM + 1];
    rep(i, MAXNUM + 1) { CounterArray[i] = 0; }

    rep(i, n) { CounterArray[array[i]] += 1; }

    rep(i, MAXNUM + 1) {
        if (i != 0) {
            CounterArray[i] = CounterArray[i - 1] + CounterArray[i];
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        int tmp = array[i];
        dst[CounterArray[tmp] - 1] = tmp;
        CounterArray[tmp] -= 1;
    }
}

int main() {
    int n;
    cin >> n;
    int* A = new int[n];
    int* ans = new int[n];
    rep(i, n) { cin >> A[i]; }

    counttingSort(A, n, ans);

    rep(i, n) {
        cout << ans[i];
        if (i == n - 1) {
            cout << endl;
        } else {
            cout << " ";
        }
    }
    delete[] ans;
    delete[] A;
    return 0;
}