#include <string.h>

#include <iostream>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
#define NIL (-1)

typedef struct Node {
    int id;
    int parent;
    int depth;
    vector<int> child;
    char type[20];

    void print() {
        cout << "node " << id << ": parent = " << parent
             << ", depth = " << depth << ", " << type << ", ";

        cout << "[";
        for (vector<int>::iterator it = child.begin(); it != child.end();
             it++) {
            if (it != child.begin()) {
                cout << ", ";
            }
            cout << *it;
        }
        cout << "]" << endl;
    }

} Node;

void setDepth(Node* node, int root, int depth) {
    node[root].depth = depth;
    for (vector<int>::iterator it = node[root].child.begin();
         it != node[root].child.end(); it++) {
        setDepth(node, *it, depth + 1);
    }
}

int main() {
    int n;
    cin >> n;
    Node* node = new Node[n];

    rep(i, n) {
        node[i].depth = 0;
        node[i].parent = -1;
    }
    rep(i, n) {
        int id;
        int numNode;
        cin >> id;
        cin >> numNode;
        node[id].id = id;

        if (numNode == 0) {
            strcpy(node[id].type, "leaf");
        } else {
            strcpy(node[id].type, "internal node");
            rep(j, numNode) {
                int tmpNode;
                cin >> tmpNode;
                node[id].child.push_back(tmpNode);
                node[tmpNode].parent = id;
            }
        }

        /*if (id == 0) {
            strcpy(node[id].type, "root");
            node[id].parent = -1;
            node[id].depth = 0;

            rep(j, numNode) {
                int tmpNode;
                cin >> tmpNode;
                node[id].child.push_back(tmpNode);
                node[tmpNode].parent = id;
            }

        } else {
            node[id].depth = node[node[id].parent].depth + 1;
            if (numNode == 0) {
                strcpy(node[id].type, "leaf");
            } else {
                strcpy(node[id].type, "internal node");
                rep(j, numNode) {
                    int tmpNode;
                    cin >> tmpNode;
                    node[id].child.push_back(tmpNode);
                    node[tmpNode].parent = id;
                }
            }
        }*/
    }
    // depthを求める
    {
        // rootを求める
        int root;
        rep(i, n) {
            if (node[i].parent == NIL) {
                root = i;
                strcpy(node[i].type, "root");
            }
        }

        // depthを求める
        setDepth(node, root, 0);
    }

    rep(i, n) {
        node[i].print();
        /*cout << "node " << node[i].id << ": parent = " << node[i].parent
             << ", depth = " << node[i].depth << ", " << node[i].type << ",
        ";

        cout << "[";
        vector<int>::iterator it = node[i].child.begin();
        rep(j, node[i].child.size()) {
            cout << *it;
            it++;
            if (j != node[i].child.size() - 1) {
                cout << ", ";
            }
        }
        cout << "]" << endl;*/
    }
    return 0;
}