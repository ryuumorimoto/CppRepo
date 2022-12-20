#include <iostream>
#include <vector>

#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
#define MAXNUM (100)
#define MAXVALUE (1000000)
int n;
int M[MAXNUM][MAXNUM];
int costArray[MAXNUM];
int distanceValue[MAXNUM];
vector<int> includedNode;

int main() {
    // input and initialize
    cin >> n;
    rep(i, n) {
        costArray[i] = MAXVALUE;
        rep(j, n) { M[i][j] = MAXVALUE; }
    }
    rep(i, n) {
        int nodeid, numEdge;
        cin >> nodeid >> numEdge;
        rep(j, numEdge) {
            int toNode, cost;
            cin >> toNode >> cost;
            M[nodeid][toNode] = cost;
        }
    }

    // solve
    // まず始点についての情報を整理する
    // includedNode.push_back(0);
    costArray[0] = 0;
    // distanceValue[0] = 0;
    // 始点からの距離を記録
    /*for (int i = 1; i < n; i++) {
        if (M[0][i] < costArray[i]) {
            costArray[i] = M[0][i];
        }
    }*/

    while (includedNode.size() < n) {
        // 選ばれていないノードへの距離を表すcostArrayの最小値を見つける
        int selectedIndex = -1;
        int selectedMinValue = MAXVALUE;
        rep(i, n) {
            if (costArray[i] == -1) {
                continue;
            } else {
                if (costArray[i] < selectedMinValue) {
                    selectedMinValue = costArray[i];
                    selectedIndex = i;
                }
            }
        }
        // 最小値をもとに、costArrayを更新する。更新方法は、新しく追加したnode経由での行き方が、短くなっているかで判定する
        includedNode.push_back(selectedIndex);
        distanceValue[selectedIndex] = selectedMinValue;
        rep(i, n) {
            if (costArray[i] == -1) {
                continue;
            } else {
                if (costArray[selectedIndex] + M[selectedIndex][i] <
                    costArray[i]) {
                    costArray[i] =
                        costArray[selectedIndex] + M[selectedIndex][i];
                }
            }
        }
        costArray[selectedIndex] = -1;
    }

    rep(i, n) { cout << i << " " << distanceValue[i] << endl; }

    return 0;
}