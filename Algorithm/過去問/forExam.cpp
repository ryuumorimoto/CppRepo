#include <iostream>
#include <vector>

#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

class Combination {
   public:
    Combination(int start, int end) {
        vector<string> array;
        for (int i = start; i <= end; i++) {
            array.push_back(to_string(i));
        }
        rep(i, array.size()) {
            for (int j = i + 1; j < array.size(); j++) {
                combi.push_back(make_pair(fileName + array[i] + extName,
                                          fileName + array[j] + extName));
            }
        }
    }
    Combination() {
        // int array[] = {2,4,6,8,10};
        vector<string> array{"a", "b", "c", "d"};
        rep(i, array.size()) {
            for (int j = i + 1; j < array.size(); j++) {
                combi.push_back(make_pair(fileName + array[i] + extName,
                                          fileName + array[j] + extName));
            }
        }
    }
    string fileName = "file";
    string extName = ".txt";
    vector<pair<string, string> > combi;

    void show() {
        rep(i, combi.size()) {
            cout << combi[i].first << " & " << combi[i].second << endl;
        }
        cout << "size is " << combi.size() << endl;
    }
};
int main(int argc, char* argv[]) {
    Combination C = Combination();
    C.show();
    cout << "----------------" << endl;
    Combination C1 = Combination(2, 9);
    C1.show();
    return 0;
}