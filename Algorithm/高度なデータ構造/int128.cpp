#include <iostream>

#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

std::ostream &operator<<(std::ostream &dest, __int128_t value) {
    std::ostream::sentry s(dest);
    if (s) {
        __uint128_t tmp = value < 0 ? -value : value;
        char buffer[128];
        char *d = std::end(buffer);
        do {
            --d;
            *d = "0123456789"[tmp % 10];
            tmp /= 10;
        } while (tmp != 0);
        if (value < 0) {
            --d;
            *d = '-';
        }
        int len = std::end(buffer) - d;
        if (dest.rdbuf()->sputn(d, len) != len) {
            dest.setstate(std::ios_base::badbit);
        }
    }
    return dest;
}

__int128 parse(string &s) {
    __int128 ret = 0;
    for (int i = 0; i < s.length(); i++)
        if ('0' <= s[i] && s[i] <= '9') ret = 10 * ret + s[i] - '0';
    return ret;
}

/*  最大値：　2^127  = 1.7014118e+38
    mod : %で使用可能    
 */
int main(int argc, char *argv[]) {
    __int128_t s = 3;
    string num = "551263368336670859257571";
    s = parse(num);
    cout << s << endl;
    return 0;
}