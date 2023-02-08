#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>

#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

#define PUZZLE_SIZE (9)
#define PUZZLE_EGGE (3)
class Puzzle33 {
   public:
    int array[PUZZLE_SIZE];
    int spaceIndex;
    enum moving { upper = 0, lower, left, right };
    vector<moving> trace;
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
                swap(array[puzzle->spaceIndex], array[puzzle->spaceIndex - 3]);
                spaceIndex = puzzle->spaceIndex - 3;
                break;
            case lower:
                rep(i, PUZZLE_SIZE) { array[i] = puzzle->array[i]; }
                swap(array[puzzle->spaceIndex], array[puzzle->spaceIndex + 3]);
                spaceIndex = puzzle->spaceIndex + 3;
                break;
            default:
                break;
        }

        rep(i, puzzle->trace.size()) { trace.push_back(puzzle->trace[i]); }
        trace.push_back(move);
        // print();
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
            if (i != 0 && i % 3 == 0) {
                cout << endl;
            }
            cout << array[i] << " ";
        }
        cout << endl;
        cout << "space: " << spaceIndex << endl;
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

int main() {
    int inputArray[PUZZLE_SIZE];
    rep(i, PUZZLE_SIZE) { cin >> inputArray[i]; }
    Puzzle33 initialPuzzle = Puzzle33(inputArray);
    queue<Puzzle33> Q;
    map<Puzzle33, bool> dic;
    Q.push(initialPuzzle);
    dic[initialPuzzle] = true;

    Puzzle33 target, tmp;
    int count = 0;
    while (!Q.empty()) {
        target = Q.front();
        Q.pop();
        if (target.isTarget()) {
            break;
        }
        // cout << "space: " << target.spaceIndex << endl;
        //  2, 5, 8ではない
        if (target.spaceIndex % 3 != 2) {
            Puzzle33 tmp = Puzzle33(&target, Puzzle33::right);
            if (!dic[tmp]) {
                Q.push(tmp);
                dic[tmp] = true;
            }
        }
        // 0, 3, 6ではない
        if (target.spaceIndex % 3 != 0) {
            tmp = Puzzle33(&target, Puzzle33::left);
            if (!dic[tmp]) {
                Q.push(tmp);
                dic[tmp] = true;
            }
        }
        // 0, 1, 2ではない
        if (3 <= target.spaceIndex) {
            tmp = Puzzle33(&target, Puzzle33::upper);
            if (!dic[tmp]) {
                Q.push(tmp);
                dic[tmp] = true;
            }
        }
        // 6, 7, 8ではない
        if (target.spaceIndex < 6) {
            tmp = Puzzle33(&target, Puzzle33::lower);
            if (!dic[tmp]) {
                Q.push(tmp);
                dic[tmp] = true;
            }
        }
        /*count += 1;
        if (count < 20) {
            cout << "count" << count << endl;
            target.print();
            cout << "how Q " << Q.size() << endl;
        }*/
    }

    cout << target.trace.size() << endl;

    return 0;
}