#include <iostream>
#include <queue>
#include <vector>

#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

long long dic[256];

int main(int argc, char* argv[]) {
    rep(i, 256) { dic[i] = -1; }
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
    long long count = 0;
    long long prevIndex = -10;
    long long numContinuos = 0;
    vector<unsigned char> ans;
    queue<unsigned char> Q;
    while (fread(&tmp, sizeof(unsigned char), 1, fp) != 0) {
        // cout << (int)tmp << endl;
        if (dic[tmp] != -1) {
            if (numContinuos == 0) {
                prevIndex = dic[tmp];
                numContinuos = 1;
            } else {
                int nowIndex = dic[tmp];
                if (nowIndex == prevIndex + 1) {
                    numContinuos += 1;
                    prevIndex = nowIndex;
                } else {
                    if (numContinuos >= 4) {
                    }
                    prevIndex = dic[tmp];
                    numContinuos = 1;
                }
            }
        } else {
            ans.push_back(tmp);
        }

        int targetIndex = dic[tmp];
        if(targetIndex == prevIndex + 1) {
            // 連続している時            
        } else {

            if (4 <= Q.size()) {
                // 圧縮して書き込み
                ans.push_back(0);
            }else {
                // 圧縮せずに書き込み
                while (!Q.empty()) {
                    if(Q.front() == 0) {
                        ans.push_back(0);
                        ans.push_back(0);
                        ans.push_back(0);
                        Q.pop();
                    }else {
                        ans.push_back(Q.front());
                        Q.pop();
                    }
                }
            }
            prevIndex = targetIndex;
        }

        Q.push(tmp);        
        dic[tmp] = count;
        count += 1;
    }

    return 0;
}