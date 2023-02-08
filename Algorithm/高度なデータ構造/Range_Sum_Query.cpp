#include <iostream>
#include <vector>

#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

class SegmentTree {
   public:
    SegmentTree(vector<int> v) {
        n = 1;
        while (n < v.size()) {
            n *= 2;
        }
        node.resize(2 * n, 0);
        for (int i = 0; i < v.size(); i++) {
            node[n + i] = v[i];
        }
        for (int i = n - 1; 1 <= i; i--) {
            node[i] = node[2 * i] + node[2 * i + 1];
        }
    }
    vector<int> node;
    int n;
    void update(int index, int value) {
        int nodeIndex = n + index;
        if (index < n) {
            node[nodeIndex] += value;
        }
        nodeIndex = nodeIndex / 2;
        while (true) {
            if (nodeIndex == 0) {
                break;
            }
            node[nodeIndex] = node[nodeIndex * 2] + node[nodeIndex * 2 + 1];
            nodeIndex = nodeIndex / 2;
        }
    }
    // seekLeft, seekRightは探索範囲で、nodeIndexは探索するnode, left, rightは
    /* ○　○　○　○　○　○　○　○　がSegmentTreeではn(8) n+1, n+2 ... n+7で
    left, rightでは0, 1, 2, 3, ...., 7に対応している。
    */
    int find(int seekLeft, int seekRight, int nodeIndex = 1, int left = 0,
             int right = -1) {
        /*cout << "find " << seekLeft << " " << seekRight << " " << nodeIndex
             << " " << left << " " << right << endl;*/
        if (right == -1) {
            right = n - 1;
        }

        if (seekLeft <= left && right <= seekRight) {
            return node[nodeIndex];
        } else if (right < seekLeft || seekRight < left) {
            return 0;
        } else {
            return find(seekLeft, seekRight, nodeIndex * 2, left,
                        left + (right - left) / 2) +
                   find(seekLeft, seekRight, nodeIndex * 2 + 1,
                        left + (right - left) / 2 + 1, right);
        }
    }
};
int main() {
    int n, q;
    cin >> n >> q;
    vector<int> A;
    A.resize(n, 0);
    SegmentTree St = SegmentTree(A);
    rep(i, q) {
        int operation, x, y;
        cin >> operation >> x >> y;
        if (operation == 0) {
            // add
            St.update(x - 1, y);
        } else if (operation == 1) {
            // getSum
            cout << St.find(x - 1, y - 1) << endl;
        }
    }

    return 0;
}