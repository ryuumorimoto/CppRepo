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
    int inputdata;
    while (fscanf(fp, "%d:", &inputdata) != EOF) {
        x.push_back(inputdata);
    }
    fclose(fp);

    // solve
    int n = x.size();
    int sum_i = 0;
    int sum_x = 0;
    int sum_i2 = 0;
    int sum_ix = 0;
    rep(i, n) {
        sum_i += i;
        sum_i2 += i * i;
        sum_x += x[i];
        sum_ix += i * x[i];
    }
    double a =
        (((double)n * (double)sum_ix) - ((double)sum_i * (double)sum_x)) /
        ((double)n * (double)sum_i2 - (double)sum_i * (double)sum_i);
    double k =
        ((double)sum_i2 * (double)sum_x - (double)sum_ix * (double)sum_i) /
        ((double)n * (double)sum_i2 - (double)sum_i * (double)sum_i);

    printf("%.4lf %.4lf\n", a, k);
    return 0;
}