#include <algorithm>
#include <iostream>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

int main() {
    int N;
    cin >> N;
    int count = 0;
    int *A = new int[N];
    rep(i, N) { cin >> A[i]; }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N - i; j++) {
            if (j == N - i - 1) continue;
            if (A[j] > A[j + 1]) {
                /*int tmp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = tmp;*/
                swap(A[j], A[j + 1]);
                count += 1;
            }
        }
    }

    rep(i, N) {
        if (i == N - 1) {
            cout << A[i] << endl;
        } else {
            cout << A[i] << " ";
        }
    }
    cout << count << endl;

    delete[] A;
}