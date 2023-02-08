#include <iostream>
#include <regex>

#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

int main(int argc, char* argv[]) {
    string s1 = "1234";
    string s2 = "abc";

    regex re(R"(\d+)");
    // 完全一致
    cout << regex_match(s1, regex(".")) << endl;

    // 部分一致
    cout << regex_search("abc", regex(R"(\d)")) << endl;

    // 結果の参照
    string s3 = "123-4567";
    smatch m;
    if (regex_match(s3, m, regex(R"((\d+)-(\d+))"))) {
        cout << "match size is " << m.size() << endl;
        rep(i, m.size()) { cout << i << " : " << m[i].str() << endl; }
    }
    return 0;
}