#include <stdlib.h>
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <queue>
#include <string>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

#define MAXSIZE (1000000)

typedef struct process {
    char name[10];
    int time;
} process;

int main() {
    int N, q;
    cin >> N;
    cin >> q;
    process p;
    queue<process> que;
    rep(i, N) {
        cin >> p.name;
        cin >> p.time;

        que.push(p);
    }

    // bool flag = true;
    int head = 0;
    int tail = N;
    int sumTime = 0;
    while (1) {
        process tmp = que.front();
        que.pop();
        tmp.time -= q;
        if (tmp.time <= 0) {
            sumTime += q + tmp.time;
            cout << tmp.name << " " << sumTime << endl;
            if (que.empty()) {
                break;
            }
        } else {
            sumTime += q;
            que.push(tmp);
        }
    }
    return 0;
}