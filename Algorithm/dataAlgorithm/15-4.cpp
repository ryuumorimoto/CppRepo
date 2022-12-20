#include <iostream>
#include <vector>

#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

#define MAXNUM (100000)

vector<pair<int, int> > list[MAXNUM];
bool vertexStates[MAXNUM];
int maxDistance = 0;
int maxDistanceIndex = -1;

void dfs(int vertex, int distanceValue) {
    vertexStates[vertex] = true;

    rep(i, list[vertex].size()) {
        int nextVertex = list[vertex][i].first;
        int nextVertexCost = list[vertex][i].second;
        if (vertexStates[nextVertex] == false) {
            int newDistance = distanceValue + nextVertexCost;
            if (maxDistance < newDistance) {
                maxDistance = newDistance;
                maxDistanceIndex = nextVertex;
            }
            dfs(nextVertex, newDistance);
        }
    }
}
int main() {
    // input and initialize
    int n;
    cin >> n;
    rep(i, n) { vertexStates[i] = false; }
    rep(i, n - 1) {
        int s, t, cost;
        cin >> s >> t >> cost;
        list[s].push_back(make_pair(t, cost));
        list[t].push_back(make_pair(s, cost));
    }

    // find the farest vertext from 0
    dfs(0, 0);
    // reset
    int mostFarVertex = maxDistanceIndex;
    maxDistance = 0;
    maxDistanceIndex = -1;
    rep(i, n) { vertexStates[i] = false; }
    // find the farest vertext from mostFarVertex
    dfs(mostFarVertex, 0);

    cout << maxDistance << endl;

    return 0;
}