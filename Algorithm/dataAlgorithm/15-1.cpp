#include <iostream>

#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
long long MAXVALUE = 1LL << 32;
long long A[100][100];

int main() {
    // ipnut and initialize
    int V, E;
    cin >> V >> E;
    rep(i, V) {
        rep(j, V) {
            if (i == j) {
                A[i][j] = 0;
            } else {
                A[i][j] = MAXVALUE;
            }
        }
    }
    rep(i, E) {
        int s, t, cost;
        cin >> s >> t >> cost;
        A[s][t] = cost;
    }

    // solve
    for (int k = 0; k < V; k++) {
        rep(i, V) {
            if (A[i][k] == MAXVALUE) {
                continue;
            }
            rep(j, V) {
                if (A[k][j] == MAXVALUE) {
                    continue;
                }
                A[i][j] = min(A[i][j], A[i][k] + A[k][j]);
            }
        }
    }

    bool isNegative = false;
    rep(i, V) {
        if (A[i][i] < 0) {
            isNegative = true;
        }
    }

    // output
    if (isNegative) {
        cout << "NEGATIVE CYCLE" << endl;
    } else {
        rep(i, V) {
            rep(j, V) {
                long long value = A[i][j];
                if (value == MAXVALUE) {
                    cout << "INF";
                } else {
                    cout << A[i][j];
                }

                if (j == V - 1) {
                    cout << endl;
                } else {
                    cout << " ";
                }
            }
        }
    }
    return 0;
}