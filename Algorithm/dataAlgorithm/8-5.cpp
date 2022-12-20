#include <iostream>
#include <vector>

#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

vector<int> Pre;
vector<int> In;

/*typedef struct Node {
    int id;
    Node* parent;
    Node* left;
    Node* right;
} Node;
Node node[200];*/
int position = 0;

void showVector(vector<int> array) {
    rep(i, array.size()) { cout << array[i] << " "; }
    cout << endl;
}
void reconstruction(int root, vector<int> group) {
    vector<int> left;
    vector<int> right;
    int rootIndex;
    rep(i, group.size()) {
        if (root == group[i]) {
            rootIndex = i;
        }
    }
    // cout << "rootIndex " << rootIndex << endl;
    rep(i, rootIndex) { left.push_back(group[i]); }
    for (int i = rootIndex + 1; i < group.size(); i++) {
        right.push_back(group[i]);
    }
    /*cout << "root: " << root << endl;
    showVector(left);
    showVector(right);*/

    if (left.size() != 0) {
        position += 1;
        int nextRoot = Pre[position];
        reconstruction(nextRoot, left);
    }

    if (right.size() != 0) {
        position += 1;
        int nextRoot = Pre[position];
        reconstruction(nextRoot, right);
    }

    if (root == Pre[0]) {
        cout << root << endl;
    } else {
        cout << root << " ";
    }
}
int main() {
    // input
    int n = 0;
    cin >> n;
    rep(i, n) {
        int tmp;
        cin >> tmp;
        Pre.push_back(tmp);
    }
    rep(i, n) {
        int tmp;
        cin >> tmp;
        In.push_back(tmp);
    }

    // solve
    int root = Pre[0];
    reconstruction(root, In);

    return 0;
}