#include <iostream>
#include <queue>
#include <vector>

#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
#define MAXNUM (10000)
#define MAXVALUE (1000000001)

vector<pair<int, int> > list[MAXNUM];
bool vertexState[MAXNUM];
int costArray[MAXNUM];
priority_queue<pair<int, int> > pq;
int distanceValue = 0;

int main() {
    // input and initialize
    int V, E;
    cin >> V >> E;
    rep(i, V) {
        costArray[i] = MAXVALUE;
        vertexState[i] = false;
    }
    rep(i, E) {
        int s, t, cost;
        cin >> s >> t >> cost;
        list[s].push_back(make_pair(t, cost));
        list[t].push_back(make_pair(s, cost));
    }

    // solve
    costArray[0] = 0;
    pq.push(make_pair(0, 0));
    while (!pq.empty()) {
        pair<int, int> tmp = pq.top();
        pq.pop();
        int willbeIncludedNode = tmp.second;
        int willbeIncludedNodeCost = -tmp.first;
        if (vertexState[willbeIncludedNode]) {
            continue;
        }
        vertexState[willbeIncludedNode] = true;
        distanceValue += willbeIncludedNodeCost;
        // cout << "add: " << willbeIncludedNode << endl;

        rep(i, list[willbeIncludedNode].size()) {
            int connectedNode = list[willbeIncludedNode][i].first;
            int connectedNodeCost = list[willbeIncludedNode][i].second;
            if (vertexState[connectedNode]) {
                continue;
            } else {
                if (connectedNodeCost < costArray[connectedNode]) {
                    costArray[connectedNode] = connectedNodeCost;
                    pq.push(
                        make_pair(-costArray[connectedNode], connectedNode));
                    // cout << "push: " << connectedNode << endl;
                }
            }
        }
    }

    // output
    cout << distanceValue << endl;
    return 0;
}