#include <iostream>
#include <map>
#include <queue>
#include <vector>

#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

#define PUZZLE_SIZE (16)
#define PUZZLE_EGGE (4)

int costArray[PUZZLE_SIZE][PUZZLE_SIZE];
class Puzzle33 {
   public:
    int array[PUZZLE_SIZE];
    int spaceIndex;
    int depth;
    int heuristic;
    enum moving { upper = 0, lower, left, right, notMoved };
    moving prev;
    // vector<moving> trace;
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
        /*rep(i, puzzle->trace.size()) { trace.push_back(puzzle->trace[i]); }
        trace.push_back(move);*/
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
        prev = direction;
        // trace.push_back(direction);
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
    static bool lessHeuristic(const Puzzle33& first, const Puzzle33& second) {
        return -(first.getHeuristic() + first.depth) <
               -(second.getHeuristic() + second.depth);
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
            if (prev == right) {
                return false;
            }
            return true;
        }
    }
    bool canMoveRight() {
        if (spaceIndex % 4 == 3) {
            return false;
        } else {
            if (prev == left) {
                return false;
            }
            return true;
        }
    }
    bool canMoveUp() {
        if (PUZZLE_EGGE <= spaceIndex) {
            if (prev == lower) {
                return false;
            }
            return true;
        } else {
            return false;
        }
    }
    bool canMoveDown() {
        if (spaceIndex < PUZZLE_SIZE - PUZZLE_EGGE) {
            if (prev == upper) {
                return false;
            }
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

struct Compare : public binary_function<Puzzle33, Puzzle33, bool> {
    bool operator()(const Puzzle33& first, const Puzzle33& second) {
        return -(first.getHeuristic() + first.depth) <
               -(second.getHeuristic() + second.depth);
    }
};
int main() {
    int inputArray[PUZZLE_SIZE];
    rep(i, PUZZLE_SIZE) { cin >> inputArray[i]; }
    Puzzle33 target = Puzzle33(inputArray);
    target.depth = 0;
    target.prev = Puzzle33::notMoved;
    target.setCostArray();

    // solve
    priority_queue<Puzzle33, vector<Puzzle33>, Compare> pq;
    map<Puzzle33, bool> dic;
    pq.push(target);
    // dic[target] = true;
    while (!pq.empty()) {
        target = pq.top();
        // cout << target.depth << endl;
        pq.pop();
        dic[target] = true;
        if (target.isTarget()) {
            break;
        }
        if (target.canMoveRight()) {
            Puzzle33 moved = target;
            moved.moveTo(Puzzle33::right);
            if (!dic[moved]) {
                // dic[moved] = true;
                moved.depth += 1;
                pq.push(moved);
            }
        }
        if (target.canMoveDown()) {
            Puzzle33 moved = target;
            moved.moveTo(Puzzle33::lower);
            if (!dic[moved]) {
                // dic[moved] = true;
                moved.depth += 1;
                pq.push(moved);
            }
        }
        if (target.canMoveLeft()) {
            Puzzle33 moved = target;
            moved.moveTo(Puzzle33::left);
            if (!dic[moved]) {
                // dic[moved] = true;
                moved.depth += 1;
                pq.push(moved);
            }
        }
        if (target.canMoveUp()) {
            Puzzle33 moved = target;
            moved.moveTo(Puzzle33::upper);
            if (!dic[moved]) {
                // dic[moved] = true;
                moved.depth += 1;
                pq.push(moved);
            }
        }
    }
    //cout << pq.size() << " " << dic.size() << endl;
    // cout << target.trace.size() << endl;
    cout << target.depth << endl;

    return 0;
}