#include <iostream>
#include <queue>
#include <vector>

#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
#define MAXNUM (10000)
#define NOT_VISITED (-1000)
#define VISITED (-10)
#define COMPLETED (-1)

int InDegree[MAXNUM];
int vertexStates[MAXNUM];
vector<int> list[MAXNUM];
vector<int> AnswerV;

void bfs(int vertex) {
    queue<int> q;
    q.push(vertex);
    vertexStates[vertex] = VISITED;

    while (!q.empty()) {
        vertex = q.front();
        q.pop();
        AnswerV.push_back(vertex);
        for (int i = 0; i < list[vertex].size(); i++) {
            int connectedVertex = list[vertex][i];
            InDegree[connectedVertex] -= 1;
            if (vertexStates[connectedVertex] == NOT_VISITED &&
                InDegree[connectedVertex] == 0) {
                q.push(connectedVertex);
                vertexStates[connectedVertex] = VISITED;
            }
        }
    }
}
int main() {
    // input and initialize
    int V, E;
    cin >> V >> E;
    rep(i, V) {
        InDegree[i] = 0;
        vertexStates[i] = NOT_VISITED;
    }
    rep(i, E) {
        int s, t;
        cin >> s >> t;
        list[s].push_back(t);
        InDegree[t] += 1;
    }    
    // solve
    rep(i, V) {
        if (InDegree[i] == 0 && vertexStates[i] == NOT_VISITED) {
            bfs(i);
        }
    }
    rep(i, V) { cout << AnswerV[i] << endl; }

    return 0;
}