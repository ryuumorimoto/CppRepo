#include <iostream>
#include <vector>

#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

int main(int argc, char* argv[]) {
    // input
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
    fclose(fp);

    // solve
    double maxAve = (double)INT32_MIN;
    double minAve = (double)INT32_MAX;
    double sumAve = 0;
    for (int i = 3; i <= infectionData.size() - 4; i++) {
        int tmpsum = 0;
        for (int j = i - 3; j <= i + 3; j++) {
            tmpsum += infectionData[j];
        }
        double ave = (double)tmpsum / (double)7.0;
        sumAve += ave;
        minAve = min(minAve, ave);
        maxAve = max(maxAve, ave);
    }

    printf("max: %.4lf\n, min: %.4lf\n, sum: %.4lf\n", maxAve, minAve, sumAve);

    return 0;
}