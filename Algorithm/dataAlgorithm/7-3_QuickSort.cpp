#include <iostream>
#include <string>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

#define MAX_ARRAY_NUM (100000)

typedef struct Card {
    int num;
    char mark;
    void show() { cout << mark << " " << num << endl; }
} Card;

Card L[MAX_ARRAY_NUM];
Card R[MAX_ARRAY_NUM];
int partition(Card *array, int left, int right) {
    int len = right - left;
    int base = array[right - 1].num;
    int i = 0, j = 0;
    rep(index, len - 1) {
        if (array[left + index].num <= base) {
            swap(array[left + i], array[left + index]);
            j += 1;
            i += 1;
        } else {
            j += 1;
        }
    }
    swap(array[left + i], array[right - 1]);
    return i;
}
void quickSort(Card *array, int left, int right) {
    int len = right - left;
    if (len != 1) {
        // cout << "left: " << left << "right: " << right << endl;
        int index = partition(array, left, right);
        quickSort(array, left, left + index);
        quickSort(array, left + index, right);
    }
}
void mergeSort(Card *A, int n, int left, int right) {
    if (n > 1) {
        int mid = (left + right) / 2;
        int n1 = mid - left;
        int n2 = right - mid;
        mergeSort(A, n1, left, mid);
        mergeSort(A, n2, mid, right);

        rep(i, n1) {
            L[i].num = A[left + i].num;
            L[i].mark = A[left + i].mark;
        }
        L[n1].num = INT32_MAX;
        rep(i, n2) {
            R[i].num = A[mid + i].num;
            R[i].mark = A[mid + i].mark;
        }
        R[n2].num = INT32_MAX;
        int i = 0;
        int j = 0;
        for (int index = 0; index < n; index++) {
            if (L[i].num <= R[j].num) {
                A[left + index].num = L[i].num;
                A[left + index].mark = L[i++].mark;
            } else {
                A[left + index].num = R[j].num;
                A[left + index].mark = R[j++].mark;
            }
        }
    }
}
int main() {
    int n;
    cin >> n;
    Card card[MAX_ARRAY_NUM];
    Card card2[MAX_ARRAY_NUM];
    rep(i, n) {
        // cout << "scan" << i << endl;
        scanf("%s %d", &card[i].mark, &card[i].num);
        card2[i].mark = card[i].mark;
        card2[i].num = card[i].num;
        // scanf("%d", &card[i].num);
    }

    quickSort(card, 0, n);
    mergeSort(card2, n, 0, n);
    bool isStable = true;
    rep(i, n) {
        if (card[i].mark != card2[i].mark) {
            isStable = false;
        }
    }
    if (isStable) {
        cout << "Stable" << endl;
    } else {
        cout << "Not stable" << endl;
    }
    rep(i, n) { card[i].show(); }

    // rep(i, n) { card2[i].show(); }
    return 0;
}