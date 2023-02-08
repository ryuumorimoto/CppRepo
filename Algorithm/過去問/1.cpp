#include <string.h>

#include <iostream>
#include <vector>

#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

const char ID[] =
    "ABCDEFGHIJKLMNOPQRSTUVWSYZabcdefghijklmnopqrstuvwxyz0123456789@#";
const int IDSIZE = 64;
int main(int argc, char* argv[]) {
    char tmp;
    int count = 0;

    while (scanf("%c", &tmp) != EOF) {
        cout << tmp << endl;
        rep(i, IDSIZE) {
            if (ID[i] == tmp) {
                cout << tmp << " " << ID[i] << " " << i << endl;
            }
        }
        count += 6;
    }
    return 0;
}