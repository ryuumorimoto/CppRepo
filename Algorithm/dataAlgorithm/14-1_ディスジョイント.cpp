#include <iostream>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

class DisjointSet {
   public:
    DisjointSet() {}
    DisjointSet(int n) {
        p.resize(n, 0);
        rank.resize(n, 0);
        rep(i, n) { makeset(i); }
    }
    void unite(int x, int y) {
        int groupX = find(x);
        int groupY = find(y);
        if (rank[groupX] < rank[groupY]) {
            p[groupX] = groupY;
        } else if (rank[groupX] == rank[groupY]) {
            p[groupX] = groupY;
            rank[groupY] += 1;
        } else {
            p[groupY] = groupX;
            rank[groupX] += 1;
        }
    }
    bool isSame(int x, int y) { return find(x) == find(y); }
    void makeset(int x) {
        p[x] = x;
        rank[x] = 0;
    }

   private:
    int find(int x) {
        int tmp = x;
        while (tmp != p[tmp]) {
            tmp = p[tmp];
        }
        // cout << "find " << tmp << endl;
        return tmp;
    }
    vector<int> p;
    vector<int> rank;
};
int main() {
    int n, numOrder;
    cin >> n >> numOrder;
    DisjointSet ds = DisjointSet(n);

    rep(i, numOrder) {
        int order, x, y;
        cin >> order >> x >> y;
        if (order == 0) {
            ds.unite(x, y);
        } else {
            if (ds.isSame(x, y)) {
                cout << 1 << endl;
            } else {
                cout << 0 << endl;
            }
        }
    }

    return 0;
}