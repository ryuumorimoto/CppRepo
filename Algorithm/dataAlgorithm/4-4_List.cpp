#include <stdlib.h>
#include <string.h>

#include <algorithm>
#include <cstdio>
#include <iostream>
#include <list>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

int main() {
    int N;
    cin >> N;
    char order[20];
    list<int> lt;
    /*List content[MAXORDER];
    int index = 0;*/
    rep(i, N) {
        int tmp;
        scanf("%s", order);
        // cout << tmp << " " << order << strcmp(order, "insert") << endl;

        if (strcmp(order, "insert") == 0) {
            scanf("%d", &tmp);
            lt.push_front(tmp);
        } else if (strcmp(order, "delete") == 0) {
            scanf("%d", &tmp);
            for (list<int>::iterator it = lt.begin(); it != lt.end(); it++) {
                if (*it == tmp) {
                    lt.erase(it);
                    break;
                }
            }
        } else if (strcmp(order, "deleteFirst") == 0) {
            lt.pop_front();
        } else if (strcmp(order, "deleteLast") == 0) {
            lt.pop_back();
        }
    }

    for (list<int>::iterator it = lt.begin(); it != lt.end(); it++) {
        cout << *it;
        if (it == (--lt.end())) {
            cout << endl;
        } else {
            cout << " ";
        }
    }

    return 0;
}