#include <iostream>
#include <vector>

#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
template <typename T>
int find_nMax(T array, int n, bool isFirst) {
    int order = n;
    int count = 0;
    int proceed = 1;
    while (true) {
        if (proceed == order) {
            break;
        }
        if (array[count] < array[count + 1]) {
            count += 1;
        } else if (array[count] == array[count + 1]) {
            int tmp = array[count];
            while (array[count] == tmp) {
                count += 1;
            }
        }
        proceed += 1;
    }

    return count;
}
int main(int argc, char* argv[]) {
    FILE* fp;
    if ((fp = fopen(argv[1], "r")) == NULL) {
        cout << "not exist inputfile" << endl;
        exit(-1);
    }
    vector<int> infectionData;
    int inputdata;
    while (fscanf(fp, "%d:", &inputdata) != EOF) {
        infectionData.push_back(inputdata);
    }
    // rep(i, infectionData.size()) { cout << infectionData[i] << endl; }

    sort(infectionData.begin(), infectionData.end());
    int order = 10;
    int count = 0;
    int proceed = 1;
    while (true) {
        if (proceed == order) {
            break;
        }
        if (infectionData[count] < infectionData[count + 1]) {
            count += 1;
        } else if (infectionData[count] == infectionData[count + 1]) {
            int tmp = infectionData[count];
            while (infectionData[count] == tmp) {
                count += 1;
            }
        }
        proceed += 1;
    }
    find_nMax(infectionData.data(), 10, true);
    // cout << proceed << endl;
    cout << infectionData[count] << endl;
    return 0;
}