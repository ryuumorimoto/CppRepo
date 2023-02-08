#include <iostream>
#include <set>
#include <vector>

#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
#define MAXNUM (100000)
#define NOT_VISITED (false)
#define VISITED (true)

vector<int> list[MAXNUM];
bool vertexStates[MAXNUM];
int parent[MAXNUM];
int timerArray[MAXNUM];
int lowestArray[MAXNUM];
int counter = 1;

void dfs(int vertex, int prev) {
    timerArray[vertex] = counter;
    lowestArray[vertex] = counter;
    counter += 1;
    vertexStates[vertex] = VISITED;

    rep(i, list[vertex].size()) {
        int nextVertex = list[vertex][i];
        if (vertexStates[nextVertex] == NOT_VISITED) {
            parent[nextVertex] = vertex;

            dfs(nextVertex, vertex);
            lowestArray[vertex] =
                min(lowestArray[vertex], lowestArray[nextVertex]);
        } else if (nextVertex != prev) {
            lowestArray[vertex] =
                min(lowestArray[vertex], timerArray[nextVertex]);
        }
    }
}
int main() {
    // input and initialize
    int V, E;
    cin >> V >> E;
    rep(i, V) { vertexStates[i] = NOT_VISITED; }
    rep(i, E) {
        int s, t;
        cin >> s >> t;
        list[s].push_back(t);
        list[t].push_back(s);
    }

    // solve
    parent[0] = -1;
    dfs(0, -1);
    set<int> ans;
    int rootChildNum = 0;
    // rootの子供の数を調べる
    for (int i = 1; i < V; i++) {
        if (parent[i] == 0) {
            rootChildNum += 1;
        } else if (timerArray[parent[i]] <= lowestArray[i]) {
            ans.insert(parent[i]);
        }
    }
    if (rootChildNum >= 2) {
        ans.insert(0);
    }
cout << "parent" << endl;
    rep(i, V) { cout << parent[i] << endl; }
    cout << "timer" << endl;
    rep(i, V) { cout << timerArray[i] << endl; }
    cout << "lowest" << endl;
    rep(i, V) { cout << lowestArray[i] << endl; }
    cout << endl;

    // output
    for (set<int>::iterator it = ans.begin(); it != ans.end(); it++) {
        cout << *it << endl;
    }

    return 0;
}