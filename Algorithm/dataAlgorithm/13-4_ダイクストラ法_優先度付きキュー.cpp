#include <iostream>
#include <queue>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
#define MAXNUM (10000)
#define MAXVALUE (1000000)

int main() {
    int n;
    vector<pair<int, int> > list[MAXNUM];
    int costArray[MAXNUM];
    bool isSelectedArray[MAXNUM];
    int distanceValue[MAXNUM];
    priority_queue<pair<int, int> > pq;
    // input and initialize
    cin >> n;
    rep(i, n) {
        costArray[i] = MAXVALUE;
        isSelectedArray[i] = false;
        rep(j, n) {
            /*vector<pair<int, int> > emptyVector;
            list.push_back(emptyVector);*/
        }
    }

    rep(i, n) {
        int nodeid, numEdge;
        cin >> nodeid >> numEdge;
        rep(j, numEdge) {
            int toNode, cost;
            cin >> toNode >> cost;
            list[nodeid].push_back(make_pair(toNode, cost));
        }
    }

    // solve
    // まず始点についての情報を整理する
    costArray[0] = 0;
    pq.push(make_pair(0, 0));
    while (!pq.empty()) {
        pair<int, int> tmp = pq.top();
        pq.pop();
        int willbeIncludedNode = tmp.second;
        int willlbeIncludedCost = -tmp.first;
        // これがなくても答えは一致するけど、最初の方に入れたコストが大きいもう追加されたものに対しても処理しちゃう
        if (isSelectedArray[willbeIncludedNode]) {
            continue;
        }
        distanceValue[willbeIncludedNode] = costArray[willbeIncludedNode];
        // costArray[willbeIncludedNode] = -1;
        isSelectedArray[willbeIncludedNode] = true;

        rep(i, list[willbeIncludedNode].size()) {
            int connectedNode = list[willbeIncludedNode][i].first;
            int connectedNodeCost = list[willbeIncludedNode][i].second;
            if (isSelectedArray[connectedNode]) {
                continue;
            } else {
                if (costArray[willbeIncludedNode] + connectedNodeCost <
                    costArray[connectedNode]) {
                    costArray[connectedNode] =
                        costArray[willbeIncludedNode] + connectedNodeCost;
                    pq.push(
                        make_pair(-costArray[connectedNode], connectedNode));
                }
            }
        }
    }

    rep(i, n) { cout << i << " " << distanceValue[i] << endl; }

    return 0;
}