#include <string.h>

#include <cmath>
#include <cstdio>
#include <iostream>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

#define PRIME 1000003
//#define PRIME 1000

int getCode(char* key, int len) {
    int code = 0;
    for (int i = 0; i < len; i++) {
        int base = pow(5, i);
        if (key[i] == 'A') {
            code += base * 1;
        } else if (key[i] == 'C') {
            code += base * 2;
        } else if (key[i] == 'G') {
            code += base * 3;
        } else {
            code += base * 4;
        }
    }
    return code;
}
int getHash(int code, int ite) {
    return ((code % PRIME) + (1 + (code % (PRIME - 1)))) % PRIME;
}
char content[PRIME][15];

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < PRIME; i++) {
        content[i][0] = '\0';
    }

    char order[100];
    char dic[100];
    rep(i, n) {
        scanf("%s %s", order, dic);
        // cout << "input as: " << order << " " << dic << " " << i << " " << n
        //<< endl;
        if (order[0] == 'i') {
            int code = getCode(dic, strlen(dic));
            int count = 0;
            while (true) {
                if (content[getHash(code, count)][0] == '\0') {
                    strcpy(content[getHash(code, count)], dic);
                    break;
                } else if (strcmp(content[getHash(code, count)], dic) == 0) {
                    break;
                }
                count += 1;
            }
        } else {
            int code = getCode(dic, strlen(dic));
            int count = 0;
            // cout << "Code: " << code << endl;
            while (true) {
                // cout << "Hash " << getHash(code, count) << endl;
                if (strcmp(content[getHash(code, count)], dic) == 0) {
                    cout << "yes" << endl;
                    break;
                } else if (content[getHash(code, count)][0] == '\0') {
                    cout << "no" << endl;
                    break;
                }
                count += 1;
            }
        }
    }

    return 0;
}