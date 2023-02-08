/*
優先度付きキューをヒープで作る
-要素の取り出し
rootを取り出して最後尾をrootに持ってきてheapifyする
-要素の追加
親と比べ続けて、親より小さくなるところでストップする


*/

#include <string.h>

#include <cstdio>
#include <iostream>

#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

int *A;
int H = 0;
void maxHeap(int index) {
    int leftIndex, rightIndex, targetIndex, targetValue;
    leftIndex = 2 * index;
    rightIndex = leftIndex + 1;
    targetValue = A[index];
    targetIndex = index;
    if (leftIndex <= H && targetValue < A[leftIndex]) {
        targetIndex = leftIndex;
        targetValue = A[leftIndex];
    }
    if (rightIndex <= H && targetValue < A[rightIndex]) {
        targetIndex = rightIndex;
        targetValue = A[rightIndex];
    }

    if (targetIndex != index) {
        swap(A[index], A[targetIndex]);
        maxHeap(targetIndex);
    }
}
void show() {
    cout << "show: ";
    rep(i, H) { cout << A[i + 1] << " "; }
    cout << endl;
}
int parent(int key) { return key / 2; }
void insert(int key) {
    H += 1;
    A[H] = key;
    /*for (int i = H / 2; i >= 1; i--) {
        maxHeap(i);
    }*/
    int i = H;
    while (true) {
        if (parent(i) < 1) {
            break;
        }
        if (A[parent(i)] < A[i]) {
            swap(A[parent(i)], A[i]);
            i = parent(i);
        } else {
            break;
        }
    }
}
void extract() {
    int returnValue = A[1];
    A[1] = A[H];
    H -= 1;
    maxHeap(1);
    /*for (int i = H / 2; i >= 1; i--) {
        maxHeap(i);
    }*/

    cout << returnValue << endl;
}

int main() {
    char order[20];
    int key;
    A = new int[2000001];
    while (true) {
        scanf("%s", order);
        if (strcmp(order, "insert") == 0) {
            scanf("%d", &key);
            insert(key);
            // show();
        } else if (strcmp(order, "extract") == 0) {
            extract();
            // show();
        } else if (strcmp(order, "end") == 0) {
            break;
        }
    }

    return 0;
}