#include <cstdio>
#include <iostream>

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
Node* getNextInOrderNode(Node* target) {
    Node* next = target->right;
    while (next->left != NIL) {
        next = next->left;
    }
    return next;
}
Node* findNode(int key) {
    Node* target = root;
    while (target != NIL) {
        if (target->key == key) {
            return target;
        } else if (target->key < key) {
            target = target->right;
        } else {
            target = target->left;
        }
    }
    return NIL;
}

void deleteNode(Node* target) {
    Node* deleted = target;
    Node* child = NIL;
    if (deleted->left != NIL && deleted->right != NIL) {
        deleted = getNextInOrderNode(deleted);
    }

    if (deleted->left != NIL) {
        child = deleted->left;
    } else if (deleted->right != NIL) {
        child = deleted->right;
    }

    // childがいるときは親を更新
    if (child != NIL) {
        child->parent = deleted->parent;
    }

    // parentの子供を更新
    if (deleted->parent == NIL) {
        root = child;
    } else {
        if (deleted == deleted->parent->left) {
            deleted->parent->left = child;
        } else {
            deleted->parent->right = child;
        }
    }

    // keyの交換
    if (deleted != target) {
        target->key = deleted->key;
    }

    delete[] deleted;
}
void deleteKey(int key) {
    Node* target = root;
    while (target != NIL) {
        if (target->key == key) {
            cout << "delete key: " << target->key << endl;
            if (target->left == NIL && target->right == NIL) {
                // 子供なしの時
                if (target->parent->left == target) {
                    target->parent->left = NIL;
                } else {
                    target->parent->right = NIL;
                }
                delete[] target;
            } else if (target->left != NIL && target->right == NIL) {
                // leftに子供
                if (target->parent->left == target) {
                    target->parent->left = target->left;
                    target->left->parent = target->parent;
                } else {
                    target->parent->right = target->left;
                    target->left->parent = target->parent;
                }
                delete[] target;
            } else if (target->left == NIL && target->right != NIL) {
                // rightに子供
                if (target->parent->left == target) {
                    target->parent->left = target->right;
                    target->right->parent = target->parent;
                } else {
                    target->parent->right = target->right;
                    target->right->parent = target->parent;
                }
                delete[] target;
            } else {
                // 両方に子供
                cout << "here" << endl;
                Node* deleted = target->right;
                if (deleted->left == NIL) {
                    deleted->parent->right = deleted->right;
                } else {
                    deleted = getNextInOrderNode(deleted);
                    deleted->parent->left = deleted->right;
                }
                cout << "deleted key: " << deleted->key << endl;
                cout << "here2" << endl;
                target->key = deleted->key;
                cout << "here3" << endl;

                cout << "here4" << endl;
                if (deleted->right != NIL) {
                    deleted->right->parent = deleted->parent;
                }
                cout << "here5" << endl;
                delete[] deleted;
            }
            return;
        } else if (target->key < key) {
            target = target->right;
        } else {
            target = target->left;
        }
    }
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
            } else if (order[0] == 'f') {
                find(key);
            } else {
                deleteNode(findNode(key));
            }
        }
    }

    return 0;
}