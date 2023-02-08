#include <iostream>

#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

int main(int argc, char* argv[]) {
    FILE* fp;
    if ((fp = fopen("problem.in", "r")) == NULL) {
        cout << "not exist file" << endl;
        exit(-1);
    }
    int num;
    char separator[100];
    while (fgets(separator, 100, fp)) {
        //cout << separator << endl;
        char* p;
        p = strchr(separator, '\n');  // 改行文字を探す
        if (p) {
            *p = '\0';
        }
        cout << separator << endl;
    }

    return 0;
}