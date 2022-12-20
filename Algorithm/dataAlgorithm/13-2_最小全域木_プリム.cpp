#include <stdint.h>

#include <iostream>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
#define MAXNUM (100)
int M[MAXNUM][MAXNUM];
int costArray[MAXNUM];
int sumValue = 0;
vector<int> includedNode;
int n;

int main() {
    // input
    cin >> n;
    rep(i, n) {
        costArray[i] = INT32_MAX;
        rep(j, n) {
            int tmp;
            cin >> tmp;
            if (tmp == -1) {
                M[i][j] = INT32_MAX;
            } else {
                M[i][j] = tmp;
            }
        }
    }

    // solve
    costArray[0] = -1;
    includedNode.push_back(0);
    while (includedNode.size() < n) {
        int selectedIndex = -1;
        int selectedMinValue = INT32_MAX;

        // get cost array and min value in that

        // 選ばれているnodeからnode i までの距離が最小のものを見つける
        rep(i, n) {
            if (costArray[i] == -1) {
                continue;
            } else {
                int minValue = INT32_MAX;
                int selectedValue = INT32_MAX;
                rep(j, includedNode.size()) {
                    int node = includedNode[j];
                    minValue = min(minValue, M[node][i]);
                }
                costArray[i] = minValue;
            }
            if (costArray[i] < selectedMinValue) {
                selectedMinValue = costArray[i];
                selectedIndex = i;
            }
        }

        includedNode.push_back(selectedIndex);
        sumValue += costArray[selectedIndex];
        costArray[selectedIndex] = -1;
    }

    cout << sumValue << endl;
    return 0;
}