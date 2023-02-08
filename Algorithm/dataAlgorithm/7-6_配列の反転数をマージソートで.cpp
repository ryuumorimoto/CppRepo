#include <iostream>

#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

long long cnt = 0;
int L[200000];
int R[200000];

void mergeSort(int *A, int n, int left, int right) {
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
        int counter = n1;
        for (int index = 0; index < n; index++) {
            if (L[i] <= R[j]) {
                A[left + index] = L[i++];
                counter -= 1;
            } else {
                /*cout << "L[i]: " << L[i] << "R[i]: " << R[j]
                     << "counter: " << counter << endl;*/
                cnt += counter;
                A[left + index] = R[j++];
            }
        }
    }
}
int main() {
    int n;
    cin >> n;
    int A[200000];
    rep(i, n) { cin >> A[i]; }

    mergeSort(A, n, 0, n);
    cout << cnt << endl;
    return 0;
}