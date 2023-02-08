#include <iostream>

#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

bool isPrime(int num) {
    if (num <= 1) {
        return false;
    } else if (num == 2) {
        return true;
    }

    if (num % 2 == 0) {
        return false;
    } else {
        for (int i = 3; i * i <= num; i += 2) {
            if (num % i == 0) {
                return false;
            }
        }
        return true;
    }
    return false;
}
int main() {
    int n, ans = 0;
    cin >> n;
    rep(i, n) {
        int tmp;
        cin >> tmp;
        if (isPrime(tmp)) {
            ans += 1;
        }
    }

    cout << ans << endl;
    return 0;
}