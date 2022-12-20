#include <algorithm>
#include <climits>
#include <iostream>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

int main() {
    int N;
    int count = 0;
    cin >> N;
    int* A = new int[N];
    rep(i, N) { cin >> A[i]; }

    /*rep(i, N) {
        vector<int>::iterator iter = min_element(A.begin() + i, A.end());
        size_t index = distance(A.begin(), iter);
        if (i == index) {
            continue;
        } else {
            swap(A[i], A[index]);
            count += 1;
        }
    }*/
    int minA = INT_MAX;
    int minIndex = 0;
    rep(i, N) {
        minIndex = i;
        minA = INT_MAX;
        for (int j = i; j < N; j++) {
            if (A[j] < minA) {
                minA = A[j];
                minIndex = j;
            }
        }
        if (minIndex != i) {
            count += 1;
            swap(A[i], A[minIndex]);
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

    return 0;
}