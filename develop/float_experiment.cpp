#include <iostream>
#include <vector>

#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
string getBit(int target) {
    string ans;
    for (int i = sizeof(target) * 8 - 1; 0 <= i; i--) {
        int tmp = 1 << i;
        if (tmp & target) {
            ans.push_back('1');
        } else {
            ans.push_back('0');
        }
    }
    return ans;
}
string getBit(float target) {
    typedef union {
        float value;
        int bit;
    } float_bit;

    float_bit tmp;
    tmp.value = target;
    return getBit(tmp.bit);
}

int main(int argc, char* argv[]) {
    double tmp = 1;
    rep(i, 1080) {
        tmp = tmp / 2;
        cout << "i: " << i << " value: " << tmp << endl;
    }

    int a = INT32_MAX;
    cout << a << endl;
    cout << getBit(a) << endl;
    cout << a + 1 << endl;
    cout << getBit(a + 1) << endl;

    float b = -1;
    cout << getBit(b) << endl;
    return 0;
}