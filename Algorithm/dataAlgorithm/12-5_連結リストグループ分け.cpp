#include <iostream>
#include <queue>
#include <vector>

#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
#define MAXNUM (100000)
vector<vector<int> > list;
int n;
int groupCounter = 0;
int vertexGroup[MAXNUM];

void bfs(int vertex) {
    if (vertexGroup[vertex] != -1) return;

    vertexGroup[vertex] = groupCounter;
    queue<int> q;
    q.push(vertex);

    while (!q.empty()) {
        vertex = q.front();
        q.pop();
        for (int i = 0; i < list[vertex].size(); i++) {
            // if (M[vertex][i] == 1) {
            /*bool existEdge = false;
            vector<int>::iterator it;
            for (it = list[vertex].begin(); it != list[vertex].end(); it++) {
                if (*it == i) {
                    existEdge = true;
                    break;
                }
            }*/

            int toVertex = list[vertex][i];
            if (vertexGroup[toVertex] == -1) {
                // cout << "M[vertex][i] " << M[vertex][i] << endl;
                // if (vertexGroup[i] == -1) {
                q.push(toVertex);
                vertexGroup[toVertex] = groupCounter;
                /*cout << "dis: " << vertexDistance[vertex] + 1 << " "
                     << vertex << " to " << i << endl;*/
                // }
            }
        }
    }

    groupCounter += 1;
}

int main() {
    // input
    cin >> n;
    rep(i, n) {
        vector<int> tmpVector;
        list.push_back(tmpVector);
        vertexGroup[i] = -1;
    }
    int m;
    cin >> m;
    rep(i, m) {
        int vertex, edge;
        cin >> vertex >> edge;
        list[vertex].push_back(edge);
        list[edge].push_back(vertex);
    }
    /*rep(i, n) {
        cout << "index: " << i << endl;
        rep(j, list[i].size()) { cout << list[i][j] << " " << endl; }
        cout << endl;
    }*/

    // solve
    rep(i, n) { bfs(i); }

    int numConfirm;
    cin >> numConfirm;
    rep(i, numConfirm) {
        int num0, num1;
        cin >> num0 >> num1;
        if (vertexGroup[num0] == vertexGroup[num1]) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }

    /*rep(i, n) { cout << vertexGroup[i] << " "; }
    cout << endl;*/

    return 0;
}