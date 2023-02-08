#include <iostream>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

vector<unsigned char> ans;

int main(int argc, char* argv[]) {
    FILE* fp;
    if ((fp = fopen("problem.in", "rb")) == NULL) {
        exit(-1);
        cout << "not exist problem.in" << endl;
    }

    /*unsigned char tmpArray[] = {
        41, 42, 43, 44, 45, 46, 47, 00, 06, 05, 48,
    };
    fwrite(tmpArray, sizeof(tmpArray), 1, fp);*/
    unsigned char tmp;
    while (fread(&tmp, sizeof(unsigned char), 1, fp) != 0) {
        // cout << (int)tmp << endl;
        if ((int)tmp == 0) {
            unsigned char d, p;
            fread(&p, sizeof(unsigned char), 1, fp);
            fread(&d, sizeof(unsigned char), 1, fp);
            if (d == 0) {
                ans.push_back(0);
            } else {
                int ansSize = ans.size();
                for (int i = p; p - d + 1 <= i; i--) {
                    ans.push_back(ans[ansSize - i]);
                }
            }
        } else {
            ans.push_back(tmp);
        }
    }

    rep(i, ans.size()) { cout << (int)ans[i] << endl; }

    return 0;
}