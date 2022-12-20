#include <iostream>
#include <vector>

#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

class Node {
   public:
    Node() {}
    Node *left, *right;
    int x, y, id;

    bool operator<(const Node &another) const { return id < another.id; }
};
bool lessX(const Node &node0, const Node &node1) { return node0.x < node1.x; }
bool lessY(const Node &node0, const Node &node1) { return node0.y < node1.y; }
bool lessNode(Node *node0, const Node *node1) { return node0->id < node1->id; }
Node node[500000];
Node *NIL, *root;
vector<Node *> answerV;

Node *make2DTree(int left, int right, int depth) {
    if (!(left < right)) {
        return NIL;
    }

    int mid = (left + right) / 2;
    if (depth % 2 == 0) {
        sort(node + left, node + right, lessX);
    } else {
        sort(node + left, node + right, lessY);
    }
    node[mid].left = make2DTree(left, mid, depth + 1);
    node[mid].right = make2DTree(mid + 1, right, depth + 1);
    return &node[mid];
}

void find(Node *target, int x0, int x1, int y0, int y1, int depth) {
    if (x0 <= target->x && target->x <= x1 && y0 <= target->y &&
        target->y <= y1) {
        answerV.push_back(target);
    }

    if (depth % 2 == 0) {
        if (x0 <= target->x && target->left != NIL) {
            find(target->left, x0, x1, y0, y1, depth + 1);
        }
        if (target->x <= x1 && target->right != NIL) {
            find(target->right, x0, x1, y0, y1, depth + 1);
        }
    } else {
        if (y0 <= target->y && target->left != NIL) {
            find(target->left, x0, x1, y0, y1, depth + 1);
        }
        if (target->y <= y1 && target->right != NIL) {
            find(target->right, x0, x1, y0, y1, depth + 1);
        }
    }
}

int main() {
    // input
    int n, q;
    scanf("%d", &n);
    rep(i, n) {
        int x, y;
        scanf("%d %d", &x, &y);
        node[i].id = i;
        node[i].x = x;
        node[i].y = y;
        node[i].left = node[i].right = NIL;
    }

    root = make2DTree(0, n, 0);

    scanf("%d", &q);
    rep(i, q) {
        int x0, x1, y0, y1;
        scanf("%d %d %d %d", &x0, &x1, &y0, &y1);
        answerV.clear();
        find(root, x0, x1, y0, y1, 0);
        /*cout << "sort: " << answerV.size() << endl;
        rep(i, n) { cout << answerV[i] << endl; }*/
        sort(answerV.begin(), answerV.end(), lessNode);
        rep(i, answerV.size()) { printf("%d\n", answerV[i]->id); }
        printf("\n");
    }
    return 0;
}