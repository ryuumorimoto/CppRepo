#include <iostream>
#include <cstdio>

#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef struct Node {
    int key;
    Node* parent;
    Node* left;
    Node* right;

} Node;
Node *root, *NIL;

void printPreOrder(Node* root) {
    cout << " " << root->key;

    if (root->left != NIL) {
        printPreOrder(root->left);
    }
    if (root->right != NIL) {
        printPreOrder(root->right);
    }
}
void printInOrder(Node* root) {
    if (root->left != NIL) {
        printInOrder(root->left);
    }
    cout << " ";
    cout << root->key;
    if (root->right != NIL) {
        printInOrder(root->right);
    }
}
void insert(int key) {
    Node* parent = root;
    Node* newElement = new Node[1];
    newElement->key = key;
    newElement->left = NIL;
    newElement->right = NIL;
    if (root != NIL) {
        while (true) {
            if (key < parent->key) {
                if (parent->left == NIL) {
                    parent->left = newElement;
                    break;
                }
                parent = parent->left;

            } else if (parent->key < key) {
                if (parent->right == NIL) {
                    parent->right = newElement;
                    break;
                }
                parent = parent->right;
            }
        }
        newElement->parent = parent;
    } else {
        root = newElement;
    }
}
void find(int key) {
    Node* parent = root;
    while (parent != NIL) {
        if (parent->key == key) {
            cout << "yes" << endl;
            return;
        } else if (parent->key < key) {
            parent = parent->right;
        } else {
            parent = parent->left;
        }
    }
    cout << "no" << endl;
}
int main() {
    int n;
    char order[20];
    int key;
    root = NIL;
    cin >> n;
    rep(i, n) {
        scanf("%s", order);
        if (order[0] == 'p') {
            printInOrder(root);
            cout << endl;
            printPreOrder(root);
            cout << endl;
        } else {
            scanf("%d", &key);
            if (order[0] == 'i') {
                insert(key);
            } else {
                find(key);
            }
        }
    }

    return 0;
}