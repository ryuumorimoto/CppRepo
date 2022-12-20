#include <iostream>

#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
bool search(int* array, int len, int key) {
    int index = -1;
    int mid = len / 2;
    int minIndex = 0;
    int maxIndex = len - 1;
    if (array[mid] == key) return true;

    while (1) {
        if (array[mid] < key) {
            minIndex = mid;
            mid = (minIndex + maxIndex) / 2;
            /*if(prevMid > mid) {
                mid = (prevMid + mid) / 2;
            }else {
                mid = (mid + len) / 2;
            }*/
        } else if (array[mid] > key) {
            maxIndex = mid;
            mid = (minIndex + maxIndex) / 2;
            /*if(prevMid < mid) {
                mid = (prevMid + mid) / 2;
            }else {
                mid = mid / 2;
            }*/
        }
        if (array[mid] == key) return true;
        cout << "Index: " << minIndex << " " << maxIndex << endl;
        if (array[mid - 1] < key && key < array[mid + 1] || mid == 0 ||
            mid == len - 1) {
            return false;
        }
    }
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
            cout << "true" << endl;
        } else {
            cout << "false" << endl;
        }
    }

    cout << ans << endl;
    return 0;
}