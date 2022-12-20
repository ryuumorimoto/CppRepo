#include <stdlib.h>

#include <algorithm>
#include <cstdio>
#include <iostream>
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
    process* p = new process[MAXSIZE];
    rep(i, N) {
        cin >> p[i].name;
        cin >> p[i].time;
    }
    // bool flag = true;
    int head = 0;
    int tail = N;
    int sumTime = 0;
    while (1) {
        process tmp = p[head];
        head += 1;
        tmp.time -= q;
        if (tmp.time <= 0) {
            sumTime += q + tmp.time;
            cout << tmp.name << " " << sumTime << endl;
            if (tail == head) {
                break;
            }
        } else {
            sumTime += q;
            p[tail] = tmp;
            tail += 1;
        }
    }

    delete[] p;
    return 0;
}