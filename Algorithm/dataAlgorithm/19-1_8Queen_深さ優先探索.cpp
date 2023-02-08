#include <iostream>

#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

#define N (8)
bool designatedColumn[N];
int ans[N];
bool attackedRow[N];
bool attackedColumn[N];
bool attackedRightDia[2 * N - 1];
bool attackedLeftDia[2 * N - 1];

void attackRow(int row, bool isAttack) { attackedRow[row] = isAttack; }
void attackColumn(int column, bool isAttack) {
    attackedColumn[column] = isAttack;
}
void attackLeftDia(int column, int row, bool isAttack) {
    attackedLeftDia[column - row + N - 1] = isAttack;
}
void attackRightDia(int column, int row, bool isAttack) {
    attackedRightDia[column + row] = isAttack;
}
void attack(int column, int row, bool isAttack) {
    attackRow(row, isAttack);
    attackColumn(column, isAttack);
    attackLeftDia(column, row, isAttack);
    attackRightDia(column, row, isAttack);
}
// 左斜めの攻撃がcolumn, rowに対して入っているかを返す
bool getLeftDia(int column, int row) {
    if (N <= column || N <= row) {
        return false;
    } else {
        return attackedLeftDia[column - row + N - 1];
    }
}
// 右斜めの攻撃がcolumn, rowに対して入っているかを返す
bool getRightDia(int column, int row) {
    if (N <= column || N <= row) {
        return false;
    } else {
        return attackedRightDia[column + row];
    }
}
// column の行の位置を見つける
void QueenSolve(int column) {
    if (N <= column) {
        return;
    }
    // 指定済みの時
    if (designatedColumn[column]) {
        QueenSolve(column + 1);
    } else {
        int nextRow = 0;
        // 一度決めたcolumnだが、そのさきで破綻して戻ってきた時
        if (attackedColumn[column]) {
            attack(column, ans[column], false);
            nextRow = ans[column] + 1;
        }
        // このwhileで場所が決まる
        while (attackedRow[nextRow] || getLeftDia(column, nextRow) ||
               getRightDia(column, nextRow)) {
            nextRow += 1;
        }
        // columnにおける適切な場所がない場合、つまりひとつ前のcolumnをやり直す
        if (N <= nextRow) {
            int nextColumn = column - 1;
            while (designatedColumn[nextColumn]) {
                nextColumn -= 1;
            }
            QueenSolve(nextColumn);
        } else {
            // このcolumnにおける場所が決定、次にいく
            attack(column, nextRow, true);
            ans[column] = nextRow;
            QueenSolve(column + 1);
        }
    }
}
int main() {
    // input and initialize
    int n, solvedNum;
    cin >> n;
    solvedNum = n;
    rep(i, 2 * N - 1) {
        if (i < N) {
            attackedRow[i] = false;
            attackedColumn[i] = false;
            designatedColumn[i] = false;
        }
        attackedLeftDia[i] = false;
        attackedRightDia[i] = false;
    }
    rep(i, n) {
        int column, row;
        cin >> column >> row;
        ans[column] = row;
        designatedColumn[column] = true;
        attack(column, row, true);
    }

    // solve
    QueenSolve(0);
    // output
    rep(i, N) {
        int QueenRow = ans[i];
        rep(j, N) {
            if (j == QueenRow) {
                cout << "Q";
            } else {
                cout << ".";
            }
        }
        cout << endl;
    }
    return 0;
}