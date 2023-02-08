#include <iostream>
#include <vector>

#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

#define PUZZLE_SIZE (16)
#define PUZZLE_EGGE (4)
class Puzzle33 {
   public:
    int array[PUZZLE_SIZE];
    int spaceIndex;
    enum moving { upper = 0, lower, left, right, notMoved };
    vector<moving> trace;
    int costArray[PUZZLE_SIZE][PUZZLE_SIZE];
    Puzzle33() {}
    Puzzle33(int* state) {
        rep(i, PUZZLE_SIZE) {
            array[i] = state[i];
            if (state[i] == 0) {
                spaceIndex = i;
            }
        }
    }

    Puzzle33(Puzzle33* puzzle, Puzzle33::moving move) {
        switch (move) {
            case left:
                rep(i, PUZZLE_SIZE) { array[i] = puzzle->array[i]; }
                swap(array[puzzle->spaceIndex], array[puzzle->spaceIndex - 1]);
                spaceIndex = puzzle->spaceIndex - 1;
                break;
            case right:
                rep(i, PUZZLE_SIZE) { array[i] = puzzle->array[i]; }
                swap(array[puzzle->spaceIndex], array[puzzle->spaceIndex + 1]);
                spaceIndex = puzzle->spaceIndex + 1;
                break;
            case upper:
                rep(i, PUZZLE_SIZE) { array[i] = puzzle->array[i]; }
                swap(array[puzzle->spaceIndex],
                     array[puzzle->spaceIndex - PUZZLE_EGGE]);
                spaceIndex = puzzle->spaceIndex - PUZZLE_EGGE;
                break;
            case lower:
                rep(i, PUZZLE_SIZE) { array[i] = puzzle->array[i]; }
                swap(array[puzzle->spaceIndex],
                     array[puzzle->spaceIndex + PUZZLE_EGGE]);
                spaceIndex = puzzle->spaceIndex + PUZZLE_EGGE;
                break;
            default:
                break;
        }

        rep(i, puzzle->trace.size()) { trace.push_back(puzzle->trace[i]); }
        trace.push_back(move);
        // print();
    }
    void moveTo(Puzzle33::moving direction) {
        switch (direction) {
            case left:
                swap(array[spaceIndex], array[spaceIndex - 1]);
                spaceIndex = spaceIndex - 1;
                break;
            case right:
                swap(array[spaceIndex], array[spaceIndex + 1]);
                spaceIndex = spaceIndex + 1;
                break;
            case upper:
                swap(array[spaceIndex], array[spaceIndex - PUZZLE_EGGE]);
                spaceIndex = spaceIndex - PUZZLE_EGGE;
                break;
            case lower:
                swap(array[spaceIndex], array[spaceIndex + PUZZLE_EGGE]);
                spaceIndex = spaceIndex + PUZZLE_EGGE;
                break;
            default:
                break;
        }
        trace.push_back(direction);
    }
    bool operator<(const Puzzle33& another) const {
        rep(i, PUZZLE_SIZE) {
            if (array[i] == another.array[i]) {
                continue;
            } else {
                return array[i] < another.array[i];
            }
        }
        return false;
    }
    void print() {
        rep(i, PUZZLE_SIZE) {
            if (i != 0 && i % PUZZLE_EGGE == 0) {
                cout << endl;
            }
            cout << array[i] << " ";
        }
        cout << endl;
        cout << "space: " << spaceIndex << "heuristic: " << getHeuristic()
             << endl;
    }
    void setCostArray() {
        for (int i = 1; i < PUZZLE_SIZE; i++) {
            rep(j, PUZZLE_SIZE) {
                int positionX = (i - 1) % 4;
                int positionY = (i - 1) / 4;
                int targetX = j % 4;
                int targetY = j / 4;
                costArray[i][j] =
                    abs(positionX - targetX) + abs(positionY - targetY);
                // cout << costArray[i][j] << " ";
            }
            // cout << endl;
        }
    }
    bool canMoveLeft() {
        if (spaceIndex % PUZZLE_EGGE == 0) {
            return false;
        } else {
            return true;
        }
    }
    bool canMoveRight() {
        if (spaceIndex % 4 == 3) {
            return false;
        } else {
            return true;
        }
    }
    bool canMoveUp() {
        if (PUZZLE_EGGE <= spaceIndex) {
            return true;
        } else {
            return false;
        }
    }
    bool canMoveDown() {
        if (spaceIndex < PUZZLE_SIZE - PUZZLE_EGGE) {
            return true;
        } else {
            return false;
        }
    }
    int getHeuristic() const {
        int sum = 0;
        rep(i, PUZZLE_SIZE) {
            if (array[i] == 0) {
                continue;
            } else {
                sum += costArray[array[i]][i];
            }
        }
        return sum;
    }
    bool isTarget() {
        // rep(i, PUZZLE_SIZE) { cout << array[i] << " "; }
        // cout << endl;
        rep(i, PUZZLE_SIZE) {
            if (i == PUZZLE_SIZE - 1) {
                if (array[i] != 0) {
                    return false;
                }
            } else {
                if (array[i] != i + 1) {
                    return false;
                }
            }
        }
        return true;
    }

   private:
};

Puzzle33 state;
#define MAX_LIMIT (100)
int limitDepth;

bool dfs(int depth, Puzzle33::moving prev) {
    // cout << "dfs " << depth << endl;
    if (state.isTarget()) {
        return true;
    }
    /*state.print();
    cout << "depth: " << depth << endl;*/

    if (limitDepth < state.getHeuristic() + depth) {
        return false;
    } else {
        Puzzle33 tmp = state;
        if (state.canMoveDown() && prev != Puzzle33::upper) {
            state.moveTo(Puzzle33::lower);
            if (dfs(depth + 1, Puzzle33::lower)) {
                return true;
            }
        }
        state = tmp;
        if (state.canMoveRight() && prev != Puzzle33::left) {
            state.moveTo(Puzzle33::right);
            if (dfs(depth + 1, Puzzle33::right)) {
                return true;
            }
        }
        state = tmp;
        if (state.canMoveUp() && prev != Puzzle33::lower) {
            state.moveTo(Puzzle33::upper);
            if (dfs(depth + 1, Puzzle33::upper)) {
                return true;
            }
        }
        state = tmp;
        if (state.canMoveLeft() && prev != Puzzle33::right) {
            state.moveTo(Puzzle33::left);
            if (dfs(depth + 1, Puzzle33::left)) {
                return true;
            }
        }
        state = tmp;
    }

    return false;
}

int main() {
    int inputArray[PUZZLE_SIZE];
    rep(i, PUZZLE_SIZE) { cin >> inputArray[i]; }
    state = Puzzle33(inputArray);
    state.setCostArray();
    // cout << state.getHeuristic() << endl;
    for (int i = state.getHeuristic(); i < MAX_LIMIT; i++) {
        limitDepth = i;
        if (dfs(0, Puzzle33::notMoved)) {
            cout << state.trace.size() << endl;
            break;
        }
    }

    return 0;
}