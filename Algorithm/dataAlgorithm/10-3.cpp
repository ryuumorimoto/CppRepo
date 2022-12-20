#include <iostream>

#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
int A[500001];
int n;
void maxHeap(int index) {
    int leftIndex, rightIndex, targetIndex, targetValue;
    leftIndex = 2 * index;
    rightIndex = leftIndex + 1;
    targetValue = A[index];
    targetIndex = index;
    if (leftIndex <= n && targetValue < A[leftIndex]) {
        targetIndex = leftIndex;
        targetValue = A[leftIndex];
    }
    if (rightIndex <= n && targetValue < A[rightIndex]) {
        targetIndex = rightIndex;
        targetValue = A[rightIndex];
    }

    if (targetIndex != index) {
        swap(A[index], A[targetIndex]);
        maxHeap(targetIndex);
    }
}
int main() {
    cin >> n;
    rep(i, n) { cin >> A[i + 1]; }

    for (int i = n / 2; i >= 1; i--) {
        maxHeap(i);
    }

    rep(i, n) { cout << " " << A[i + 1]; }
    cout << endl;

    return 0;
}