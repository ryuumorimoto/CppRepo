#include <iostream>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef struct Node {
    int id;
    Node* parent;
    Node* left;
    Node* right;
} Node;
Node node[30];
//先行巡回
void printPreOrder(Node* root) {
    cout << " " << root->id;

    if (root->left != nullptr) {
        printPreOrder(root->left);
    }
    if (root->right != nullptr) {
        printPreOrder(root->right);
    }
}
// 中間巡回
void printInOrder(Node* root) {
    if (root->left != nullptr) {
        printInOrder(root->left);
    }
    cout << " ";
    cout << root->id;
    if (root->right != nullptr) {
        printInOrder(root->right);
    }
}
// 後行巡回
void printPostOrder(Node* root) {
    if (root->left != nullptr) {
        printPostOrder(root->left);
    }
    if (root->right != nullptr) {
        printPostOrder(root->right);
    }
    cout << " ";
    cout << root->id;
}

int main() {
    int n;
    cin >> n;

    rep(i, n) {
        node[i].parent = nullptr;
        node[i].left = nullptr;
        node[i].right = nullptr;
    }
    rep(i, n) {
        int root, left, right;
        cin >> root >> left >> right;
        node[root].id = root;
        if (left != -1) {
            node[root].left = &node[left];
            node[left].parent = &node[root];
        }
        if (right != -1) {
            node[root].right = &node[right];
            node[right].parent = &node[root];
        }
    }
    /*rep(i, n) {
        vector<Node*>::iterator it = node[i].child.begin();

        printf("index: %d, child: %p %p\n", i, *it++, *it);
    }*/

    // get root
    Node* root;
    rep(i, n) {
        if (node[i].parent == nullptr) {
            root = &node[i];
        }
    }

    // output
    cout << "Preorder" << endl;
    printPreOrder(root);
    cout << endl;

    cout << "Inorder" << endl;
    printInOrder(root);
    cout << endl;

    cout << "Postorder" << endl;
    printPostOrder(root);
    cout << endl;

    return 0;
}