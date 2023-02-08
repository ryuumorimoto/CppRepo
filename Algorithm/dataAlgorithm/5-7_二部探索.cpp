#include <iostream>

#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

int lower_search(int* array, int len, int key) {
    int ng = -1;
    int ok = len;
    while (abs(ok - ng) > 1) {
        int mid = (ok + ng) / 2;
        if (key <= array[mid]) {
            ok = mid;
        } else {
            ng = mid;
        }
    }
    return ok;
}
int main() {
    int array[] = {1, 3, 3, 3, 4, 5, 6, 7, 8, 9};
    cout << lower_search(array, 9, 3) << endl;
    return 0;
}