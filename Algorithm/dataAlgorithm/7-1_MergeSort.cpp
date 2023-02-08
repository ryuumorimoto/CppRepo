#include <string.h>

#include <climits>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

#define MAX_ARRAY_NUM (600000)
int L[MAX_ARRAY_NUM / 2];
int R[MAX_ARRAY_NUM / 2];
int cnt = 0;

void mergeSort(int* A, int n, int left, int right) {
    if (n > 1) {
        int mid = (left + right) / 2;
        int n1 = mid - left;
        int n2 = right - mid;
        mergeSort(A, n1, left, mid);
        mergeSort(A, n2, mid, right);

        rep(i, n1) { L[i] = A[left + i]; }
        L[n1] = INT32_MAX;
        rep(i, n2) { R[i] = A[mid + i]; }
        R[n2] = INT32_MAX;
        int i = 0;
        int j = 0;
        for (int index = 0; index < n; index++) {
            cnt += 1;
            if (L[i] <= R[j]) {
                A[left + index] = L[i++];
            } else {
                A[left + index] = R[j++];
            }
        }
    }
}
int main() {
    int n;
    int A[MAX_ARRAY_NUM];
    cin >> n;
    rep(i, n) { cin >> A[i]; }

    mergeSort(A, n, 0, n);
    rep(i, n) {
        cout << A[i];
        if (i == n - 1) {
            cout << endl;
        } else {
            cout << " ";
        }
    }
    cout << cnt << endl;

    return 0;
}