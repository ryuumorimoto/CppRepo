#include <iostream>
#include <map>
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
    bool operator<(const Card& other) const {
        return mark != other.mark ? mark < other.mark : num < other.num;
    }
};
bool getIncludedCard(Card* array, int n) {
    int checkTable[4][13];
    rep(i, 4) {
        rep(j, 13) { checkTable[i][j] = 0; }
    }
    rep(i, n) {
        int mark = array[i].getMarknum();
        int num = array[i].getnum() - 1;
        /*array[i].show();
        cout << mark << " " << num << endl;*/
        checkTable[mark][num] += 1;
    }

    bool isAll = true;
    vector<Card> notIncluded;
    vector<Card> over2;
    rep(i, 4) {
        rep(j, 13) {
            if (checkTable[i][j] == 0) {
                notIncluded.push_back(Card(i, j + 1));
                isAll = false;
            } else if (checkTable[i][j] > 1) {
                over2.push_back(Card(i, j + 1));
                isAll = false;
            }
        }
    }
    cout << "not Included card below" << endl;
    rep(i, notIncluded.size()) { notIncluded[i].show(); }
    cout << "Over 2 card below" << endl;
    rep(i, over2.size()) { over2[i].show(); }
    return isAll;
}
bool isSameOrder(Card* a, Card* b, int begin, int end) {
    for (int i = begin; i < end; i++) {
        if (!(a[i] == b[i])) {
            return false;
        }
    }
    return true;
}
class Card5 {
   public:
    Card5(Card* _cards) { cards = _cards; }
    Card5() {}
    Card* cards;
    int getSum() {
        int sum = 0;
        rep(i, 5) { sum += cards[i].getnum(); }
        return sum;
    }
    bool isDoubleCard() {
        vector<int> nums;
        int numVarious = 0;
        rep(i, 5) {
            int target = cards[i].getnum();
            bool isIncluded = false;
            rep(j, nums.size()) {
                if (nums[j] == target) {
                    isIncluded = true;
                }
            }

            if (!isIncluded) {
                nums.push_back(target);
            }
        }

        return nums.size() == 3;
    }
};
int main(int argc, char* argv[]) {
    vector<Card> s1;
    FILE* fp;
    if ((fp = fopen(argv[1], "r")) == NULL) {
        cout << "not exist s2*.txt" << endl;
        exit(-1);
    }
    char tmp1, tmp2;
    while (fscanf(fp, "%c%c", &tmp1, &tmp2) != EOF) {
        s1.push_back(Card(tmp1, tmp2));
    }
    fclose(fp);

    cout << "s1 size is: " << s1.size() << endl;
    Card5 A;
    int count = 0;
    rep(i, s1.size() - 4) {
        A.cards = &s1[i];
        if (A.isDoubleCard()) {
            cout << "Double Card at i: " << i + 1 << endl;
        }
    }
    /*for (int i = 17; i < 22; i++) {
        s1[i].show();
    }*/
    /*getIncludedCard(a.data(), a.size());
    getIncludedCard(b.data(), b.size());*/

    // debug
    /*cout << "debug" << endl;
    rep(i, card.size()) {
        cout << i << " : ";
        card[i].show();
    }*/
    return 0;
}