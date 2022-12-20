#include <string.h>

#include <algorithm>
#include <iostream>

using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)

typedef struct Card {
    int num;
    char art;
} Card;

Card* bable;
Card* sele;

void bablesort(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (bable[j].num > bable[j + 1].num) {
                swap(bable[j].num, bable[j + 1].num);
                swap(bable[j].art, bable[j + 1].art);
            }
        }
    }
}
void selectioSort(int n) {
    for (int i = 0; i < n; i++) {
        int maxarray = sele[0].num;
        char art_withindex = sele[0].art;
        int index = 0;

        for (int j = 1; j < n - i; j++) {
            if (sele[j].num > maxarray) {
                maxarray = sele[j].num;
                art_withindex = sele[j].art;
                index = j;
            }
        }

        if (index != n - i - 1) {
            swap(sele[n - i - 1], sele[index]);
        }
    }
}
void printCard(Card* array, int N) {
    for (int i = 0; i < N; i++) {
        if (i != N - 1) {
            cout << array[i].art << array[i].num << " ";
        } else {
            cout << array[i].art << array[i].num << endl;
        }
    }
}
bool isStable(int n) {
    for (int i = 0; i < n; i++) {
        if (bable[i].art != sele[i].art || bable[i].num != sele[i].num) {
            return false;
        }
    }
    return true;
}

int main() {
    int N;
    Card* Cards = new Card[N];
    cin >> N;
    rep(i, N) { cin >> Cards[i].art >> Cards[i].num; }

    bable = new Card[N];
    sele = new Card[N];
    memcpy(bable, Cards, sizeof(Card) * N);
    memcpy(sele, Cards, sizeof(Card) * N);
    bablesort(N);
    selectioSort(N);
    printCard(bable, N);
    cout << "Stable" << endl;
    printCard(sele, N);
    if (isStable(N)) {
        cout << "Stable" << endl;
    } else {
        cout << "Not stable" << endl;
    }
    return 0;
}