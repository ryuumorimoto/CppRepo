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
    Card(int _mark, int _num) {
        switch (_mark) {
            case 0:
                mark = 'H';
                break;
            case 1:
                mark = 'S';
                break;
            case 2:
                mark = 'D';
                break;
            case 3:
                mark = 'C';
                break;

            default:
                cout << "error mark is not defined" << endl;
                break;
        }

        switch (_num) {
            case 1:
                num = '1';
                break;
            case 2:
                num = '2';
                break;
            case 3:
                num = '3';
                break;
            case 4:
                num = '4';
                break;
            case 5:
                num = '5';
                break;
            case 6:
                num = '6';
                break;
            case 7:
                num = '7';
                break;
            case 8:
                num = '8';
                break;
            case 9:
                num = '9';
                break;
            case 10:
                num = '0';
                break;
            case 11:
                num = 'J';
                break;
            case 12:
                num = 'Q';
                break;
            case 13:
                num = 'K';
                break;
            default:
                cout << "error num is not defined" << endl;
                break;
        }
    }
    int getMarknum() {
        switch (mark) {
            case 'H':
                return 0;
                break;
            case 'S':
                return 1;
                break;
            case 'D':
                return 2;
                break;
            case 'C':
                return 3;
                break;

            default:
                cout << "error mark is not defined" << endl;
                return -1;
                break;
        }
    }
    int getnum() {
        switch (num) {
            case '1':
                return 1;
                break;
            case '2':
                return 2;
                break;
            case '3':
                return 3;
                break;
            case '4':
                return 4;
                break;
            case '5':
                return 5;
                break;
            case '6':
                return 6;
                break;
            case '7':
                return 7;
                break;
            case '8':
                return 8;
                break;
            case '9':
                return 9;
                break;
            case '0':
                return 10;
                break;
            case 'J':
                return 11;
                break;
            case 'Q':
                return 12;
                break;
            case 'K':
                return 13;
                break;
            default:
                cout << "error num is not defined" << endl;
                return -1;
                break;
        }
    }

    void show() { cout << mark << num << endl; }
    bool operator==(const Card& other) const {
        return mark == other.mark && num == other.num;
    }
};
bool isSameOrder(Card* a, Card* b, int begin, int end) {
    bool ans = true;
    for (int i = begin; i < end; i++) {
        if (!(a[i] == b[i])) {
            return false;
        }
    }
    return true;
}

int main(int argc, char* argv[]) {
    vector<Card> a, b;
    FILE* fp;
    if ((fp = fopen("./test/d3a.txt", "r")) == NULL) {
        cout << "not exist d3a.txt" << endl;
        exit(-1);
    }
    char tmp1, tmp2;

    while (fscanf(fp, "%c%c", &tmp1, &tmp2) != EOF) {
        a.push_back(Card(tmp1, tmp2));
    }
    fclose(fp);
    if ((fp = fopen("./test/d3b.txt", "r")) == NULL) {
        cout << "not exist d3b.txt" << endl;
        exit(-1);
    }
    while (fscanf(fp, "%c%c", &tmp1, &tmp2) != EOF) {
        b.push_back(Card(tmp1, tmp2));
    }
    fclose(fp);
    cout << "d3a size is: " << a.size() << endl;
    cout << "d3b size is: " << b.size() << endl;
    rep(i, a.size()) {
        if (a[i] == b[i]) {
            cout << i + 1 << ": same card is ";
            a[i].show();
        }
    }

    // debug
    /*cout << "debug" << endl;
    rep(i, card.size()) {
        cout << i << " : ";
        card[i].show();
    }*/
    return 0;
}