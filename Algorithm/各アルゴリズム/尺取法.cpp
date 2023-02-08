#include <iostream>
#include <vector>

#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

long long getWindowNum(int* array, int n, long long x) {
    int right = n - 1;
    long long sum = 0;
    long long ans = 0;
    for (int left = n - 1; 0 <= left; left--) {
        sum += array[left];
        while (left <= (right - 1) && sum > x) {
            sum = sum - array[right];
            right -= 1;
        }
        /*cout << "left: " << left << " right: " << right
             << " += " << right - left + 1 << endl;*/
        if (sum <= x) {
            ans += (right - left + 1);
        }
    }
    return ans;
}

long long getWindowNum_2(int* array, int n, long long x) {
    int right = 0;
    long long sum = 0;
    long long ans = 0;
    for (int left = 0; 0 < n; left++) {
        // ここでのrightは次を表している。
        while (right < n && sum + array[right] <= x) {
            sum = sum + array[right];
            right += 1;//rightを次に備えてあげておく
        }
        /*cout << "left: " << left << " right: " << right
             << " += " << right - left + 1 << endl;*/
        ans += (right - left);//rightが進んでおらすleftと同じならばleft = rightで条件に合わなかったということ
        if (right == left) {            
            right += 1;// leftとright両方をインクリメント
        } else {
            sum -= array[left];
        }
    }
    return ans;
}
int main(int argc, char* argv[]) {
    int N, Q;
    cin >> N >> Q;
    vector<int> A;
    rep(i, N) {
        int tmp;
        cin >> tmp;
        A.push_back(tmp);
    }

    rep(i, Q) {
        long long x;
        cin >> x;
        cout << getWindowNum(A.data(), N, x) << endl;
    }
    return 0;
}