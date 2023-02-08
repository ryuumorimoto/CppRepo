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
    vector<int> x;
    vector<int> y;
    int inputdata;
    while (fscanf(fp, "%d:", &inputdata) != EOF) {
        x.push_back(inputdata);
    }
    fclose(fp);
    if ((fp = fopen(argv[2], "r")) == NULL) {
        cout << "not exist inputfile" << endl;
        exit(-1);
    }
    while (fscanf(fp, "%d:", &inputdata) != EOF) {
        y.push_back(inputdata);
    }
    fclose(fp);
    int m = x.size();
    int n = y.size();



    // solve
    int S;
    string x_file;
    string y_file;
    for(int i=0;i<=m-n;i++) {
        int sum = 0;
        for(int k=0;k<= n-1;k++) {
            sum += (x[k + i] - y[k]) * (x[k + i] - y[k]);
        }
        if(S == sum) {

        }else if(sum < S) {
            S = sum;
        }
        S = min(S, sum);
    }

    cout << -S << endl;






    /*double maxAve = (double)INT32_MIN;
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

    printf("max: %.4lf\n, min: %.4lf\n, sum: %.4lf\n", maxAve, minAve, sumAve);*/

    return 0;
}