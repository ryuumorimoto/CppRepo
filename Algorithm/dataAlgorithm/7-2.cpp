#include <iostream>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

#define MAX_ARRAY_NUM (100000)
int A[MAX_ARRAY_NUM];

int main() {
    int n;
    cin >> n;
    rep(i, n) { cin >> A[i]; }

    int base = A[n - 1];
    int i = 0, j = 0;
    rep(index, n - 1) {
        if (A[index] <= base) {
            swap(A[i], A[index]);
            j += 1;
            i += 1;
        } else {
            j += 1;
        }
    }
    swap(A[i], A[n - 1]);

    rep(index, n) {
        // cout << A[index] << " ";
        if (index == i) {
            cout << "[";
        }
        cout << A[index];
        if (index == i) {
            cout << "]";
        }
        if (index == n - 1) {
            cout << endl;
        } else {
            cout << " ";
        }
    }
    // cout << endl;
    return 0;
}