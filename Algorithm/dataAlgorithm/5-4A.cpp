#include <string.h>

#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

int main() {
    int n;
    cin >> n;
    char order[100];
    char dic[100];
    map<string, bool> mp;
    rep(i, n) {
        scanf("%s %s", order, dic);
        if (order[0] == 'i') {
            mp[dic] = true;
        } else {
            if (mp[dic] == true) {
                cout << "yes" << endl;
            } else {
                cout << "no" << endl;
            }
        }
    }
}