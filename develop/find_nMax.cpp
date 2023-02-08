#include <iostream>
#include <vector>

#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

template <typename T>
int find_nMax(T array, int n, bool isFirst) {
    int order = n;
    int count = 0;
    int proceed = 1;
    while (true) {
        if (proceed == order) {
            if (isFirst) {
                break;
            } else {
                int tmp = array[count];
                while (array[count + 1] == tmp) {
                    count += 1;
                }
                break;
            }
        }
        if (array[count] < array[count + 1]) {
            count += 1;
        } else if (array[count] == array[count + 1]) {
            int tmp = array[count];
            while (array[count] == tmp) {
                count += 1;
            }
        }
        proceed += 1;
    }

    return count;
}
int main(int argc, char* argv[]) {
    int n;
    vector<int> v;
    cin >> n;
    rep(i, n) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    cout << find_nMax(v.data(), 3, true) << endl;
    return 0;
}