#include <iostream>

#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

int getGretestCommonDivisor(int num1, int num2) {
    if (num1 < num2) {
        swap(num1, num2);
    }
    int mod = -1;
    while (mod != 0) {
        mod = num1 % num2;
        num1 = num2;
        num2 = mod;
    }
    return num1;
}
int main() {
    int num1, num2;
    cin >> num1 >> num2;

    cout << getGretestCommonDivisor(num1, num2) << endl;
    return 0;
}