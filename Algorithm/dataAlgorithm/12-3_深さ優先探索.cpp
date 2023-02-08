#include <iostream>
#include <stack>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

#define MAXNUM (100)
#define NOT_VISITED (-100)
#define VISITED (-10)
#define COMPLETED (-1)

int n, M[MAXNUM + 1][MAXNUM + 1];
int timeFirstVisitStamp[MAXNUM + 1];
int timeCompleteStamp[MAXNUM + 1];
int vertexStates[MAXNUM + 1];
int vertexVisitedNum[MAXNUM + 1];
int timeStamp = 0;

int getNextVertex(int vertex) {
    int lastVisitedNum = vertexVisitedNum[vertex];
    for (int i = lastVisitedNum + 1; i <= n; i++) {
        if (M[vertex][i] == 1) {
            if (vertexStates[i] == NOT_VISITED) {
                vertexVisitedNum[vertex] = i;
                return i;
            }
        }
    }
    return -1;
}
void dfs(int vertex) {
    stack<int> S;
    S.push(vertex);
    timeFirstVisitStamp[vertex] = ++timeStamp;
    vertexStates[vertex] = VISITED;

    int nextVertex;
    while (!S.empty()) {
        vertex = S.top();
        int nextVertex = getNextVertex(vertex);
        if (nextVertex == -1) {
            S.pop();
            vertexStates[vertex] = COMPLETED;
            timeCompleteStamp[vertex] = ++timeStamp;
        } else {
            S.push(nextVertex);
            timeFirstVisitStamp[nextVertex] = ++timeStamp;
            vertexStates[nextVertex] = VISITED;
        }
    }
}


int main() {
    // initialize
    rep(i, MAXNUM + 1) {
        vertexStates[i + 1] = NOT_VISITED;
        vertexVisitedNum[i + 1] = 0;
        rep(j, MAXNUM + 1) { M[i + 1][j + 1] = 0; }
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
    for (int i = 1; i <= n; i++) {
        if (vertexStates[i] == NOT_VISITED) {
            dfs(i);
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << i << " " << timeFirstVisitStamp[i] << " "
             << timeCompleteStamp[i] << endl;
    }

    return 0;
}