#include <iostream>

#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
bool search(int* array, int len, int key) {
    int left = 0;
    int right = len;
    int mid;

    while (left < right) {
        mid = (right + left) / 2;
        int value = array[mid];
        if (value == key) {
            return true;
        } else if (value < key) {
            left = mid + 1;
        } else if (value > key) {
            right = mid;
        }
    }
    return false;
}

int main() {
    int n, q;
    int S[100000];
    int T[50000];

    cin >> n;
    rep(i, n) { cin >> S[i]; }
    cin >> q;
    rep(i, q) { cin >> T[i]; }
    int ans = 0;
    rep(i, q) {
        if (search(S, n, T[i])) {
            ans += 1;
            // cout << "true" << endl;
        } else {
            // cout << "false" << endl;
        }
    }

    cout << ans << endl;
    return 0;
}