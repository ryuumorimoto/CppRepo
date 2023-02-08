#include <iostream>
#include <vector>

#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

class Card {
   public:
    char mark;
    char num;
    Card(char _mark, char _num) {
        mark = _mark;
        num = _num;
    }
    void show() { cout << mark << num << endl; }
};

int main(int argc, char* argv[]) {
    FILE* fp;
    if ((fp = fopen("./test/d1.txt", "r")) == NULL) {
        cout << "not exist d1.txt" << endl;
        exit(-1);
    }
    char tmp1, tmp2;
    vector<Card> card;
    while (fscanf(fp, "%c%c", &tmp1, &tmp2) != EOF) {
        card.push_back(Card(tmp1, tmp2));
    }
    fclose(fp);
    // output
    card[47 - 1].show();

    // debug
    /*cout << "debug" << endl;
    rep(i, card.size()) {
        cout << i << " : ";
        card[i].show();
    }*/
    return 0;
}