#include <iostream>
#include <vector>

#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
#define N_MAX (1000000)
int cnt_sort = 0;
void insert_sort(int* array, int n, int g) {
    for (int i = g; i < n; i++) {
        int target = array[i];
        int index = i - g;
        while (target < array[index]) {
            cnt_sort += 1;
            swap(array[index + g], array[index]);
            index -= g;
            if (index < 0) {
                break;
            }
        }
    }
}
void shell_sort(int* array, int* G, int n, int m) {
    rep(i, m) { insert_sort(array, n, G[m - 1 - i]); }
}

int main() {
    // input
    int n;
    int A[N_MAX];
    vector<int> G;
    cin >> n;
    rep(i, n) { cin >> A[i]; }

    // solve
    // prepare G
    int g = 0;
    int g_count = 0;
    while (true) {
        int gm1 = 3 * g + 1;
        if (gm1 > n) {
            break;
        } else {
            G.push_back(gm1);
            g_count += 1;
        }
        g = gm1;
    }
    // solve
    shell_sort(A, G.data(), n, g_count);

    // output
    cout << g_count << endl;
    rep(i, g_count) {
        cout << G[g_count - 1 - i];
        if (i == g_count - 1) {
            cout << endl;
        } else {
            cout << " ";
        }
    }
    cout << cnt_sort << endl;
    rep(i, n) { cout << A[i] << endl; }

    return 0;
}