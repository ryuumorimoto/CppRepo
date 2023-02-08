#include <iostream>
#include <vector>

#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

int main(int argc, char* argv[]) {
    FILE* fp;
    if ((fp = fopen("problem.in", "r")) == NULL) {
        cout << "not exist inputfile" << endl;
        exit(-1);
    }
    vector<int> infectionData;
    int inputdata;
    while (fscanf(fp, "%d:", &inputdata) != EOF) {
        infectionData.push_back(inputdata);
    }
    fclose(fp);
    // rep(i, infectionData.size()) { cout << infectionData[i] << endl; }
    vector<int> diffDatas;
    int initialData = 0;
    for (int i = 0; i < infectionData.size(); i++) {
        int diffData;
        if (i == 0) {
            diffData = infectionData[0] - initialData;
        } else {
            diffData = infectionData[i] - infectionData[i - 1];
        }
        diffDatas.push_back(diffData);
    }

    if ((fp = fopen("diff.txt", "w")) == NULL) {
        cout << "not exist outputfile" << endl;
        exit(-1);
    }
    rep(i, diffDatas.size()) {
        if (diffDatas[i] >= 0) {
            fprintf(fp, "+%d", diffDatas[i]);
        } else {
            fprintf(fp, "%d", diffDatas[i]);
        }
    }
    fclose(fp);

    /*sort(infectionData.begin(), infectionData.end());
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
    // cout << proceed << endl;
    cout << infectionData[count] << endl;*/
    return 0;
}