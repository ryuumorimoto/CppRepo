#include <iostream>
#include <map>
#include <string>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
string mozi = "abcdefghijklmnopqrstuvwxyz .";
int main(int argc, char* argv[]) {
    map<char, int> dic;
    rep(i, mozi.size()) { dic[mozi[i]] = 0; }
    char tmp[5000];
    while (scanf("%s", tmp) != EOF) {
        cout << tmp << endl;
        string target = tmp;
        rep(i, target.size()) { dic[target[i]] += 1; }
    }

    rep(i, mozi.size()) { cout << mozi[i] << " : " << dic[mozi[i]] << endl; }

    return 0;
}