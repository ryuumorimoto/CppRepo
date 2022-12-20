#include <algorithm>
#include <iostream>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

void insertsort_each(int *array, int len) {
    int index = len - 1;
    int num = array[index];
    rep(i, len) {
        if (array[i] > num) {
            index = i;
            break;
        }
    }

    if (index != len - 1) {
        for (int i = (len - 1); i >= index; i--) {
            if (i == index)
                array[i] = num;
            else
                array[i] = array[i - 1];
        }
    }
}
int main() {
    int N;
    int *A = new int[N];
    cin >> N;
    rep(i, N) { cin >> A[i]; }

    rep(i, N) {
        if (i != 0) {
            insertsort_each(A, i + 1);
        }

        rep(j, N) {
            if (j == N - 1)
                cout << A[j] << endl;
            else
                cout << A[j] << " ";
        }
    }
    return 0;
}