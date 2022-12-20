#include <stdlib.h>

#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

int main() {
    char org[1000000];
    int stack[100];
    int index = -1;
    while (scanf("%s", org) != EOF) {
        if (org[0] == '+') {
            // cout << "+" << stack[index] << " " << stack[index - 1] << endl;
            int tmp = stack[index] + stack[index - 1];
            stack[index - 1] = tmp;
            index -= 1;
        } else if (org[0] == '-') {
            // cout << "-" << stack[index] << " " << stack[index - 1] << endl;
            int tmp = -stack[index] + stack[index - 1];
            stack[index - 1] = tmp;
            index -= 1;
        } else if (org[0] == '*') {
            // cout << "* " << stack[index] << " " << stack[index - 1] << endl;
            int tmp = stack[index] * stack[index - 1];
            stack[index - 1] = tmp;
            index -= 1;
        } else {
            int num = atoi(org);
            cout << num << endl;
            index += 1;
            stack[index] = num;
        }
    }

    cout << "answer " << stack[0] << endl;

    return 0;
}