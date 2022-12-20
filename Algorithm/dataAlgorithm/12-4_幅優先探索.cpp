#include <iostream>
#include <queue>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

#define MAXNUM (100)
#define NOT_VISITED (-1000)
#define VISITED (-10)
#define COMPLETED (-1)

int n, M[MAXNUM + 1][MAXNUM + 1];
int vertexDistance[MAXNUM + 1];
int vertexStates[MAXNUM + 1];

void bfs(int vertex) {
    queue<int> q;
    q.push(vertex);
    vertexStates[vertex] = VISITED;
    vertexDistance[vertex] = 0;

    while (!q.empty()) {
        vertex = q.front();
        q.pop();
        for (int i = 1; i <= n; i++) {
            if (M[vertex][i] == 1) {
                //cout << "M[vertex][i] " << M[vertex][i] << endl;
                if (vertexStates[i] == NOT_VISITED) {
                    q.push(i);
                    vertexStates[i] = VISITED;
                    vertexDistance[i] = vertexDistance[vertex] + 1;
                    /*cout << "dis: " << vertexDistance[vertex] + 1 << " "
                         << vertex << " to " << i << endl;*/
                }
            }
        }
    }
}
int main() {
    // initialize
    for (int i = 1; i <= MAXNUM; i++) {
        vertexStates[i] = NOT_VISITED;
        for (int j = 1; j <= MAXNUM; j++) {
            M[i][j] = 0;
        }
    }

    // input
    cin >> n;
    rep(i, n) {
        int nodeId, edgeNum;
        cin >> nodeId >> edgeNum;
        rep(j, edgeNum) {
            int edge;
            cin >> edge;
            M[nodeId][edge] = 1;
        }
    }

    // solve
    bfs(1);

    // output
    for (int i = 1; i <= n; i++) {
        if (vertexStates[i] == VISITED) {
            cout << i << " " << vertexDistance[i] << endl;
        } else {
            cout << i << " " << -1 << endl;
        }
    }
    return 0;
}