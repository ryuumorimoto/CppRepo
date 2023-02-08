#include <iostream>
#include <vector>

#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
class Segment {
   public:
    Segment(int _left, int _right, int _sum) {
        left = _left;
        right = _right;
        sum = _sum;
    }
    int getPeriod() { return right - left; }
    int left;
    int right;
    int sum;
};

int main(int argc, char* argv[]) {
    /*FILE* fp;
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
    }*/
    int n;
    cin >> n;
    vector<int> diffDatas;
    rep(i, n) {
        int tmp;
        cin >> tmp;
        diffDatas.push_back(tmp);
    }
    //
    int right = 0;
    int left = 0;
    vector<Segment> ans;
    int best = INT32_MIN;
    int sum = 0;
    for (int i = 0; i < diffDatas.size(); ++i) {
        if (sum + diffDatas[i] <= diffDatas[i]) {
            left = i;
            right = i;
            sum = diffDatas[i];
        } else {
            sum = sum + diffDatas[i];
            right += 1;
        }

        if (best < sum) {
            ans.clear();
            best = sum;
            ans.push_back(Segment(left, right, best));
        } else if (best == sum) {
            Segment tmp = Segment(left, right, best);
            if (tmp.getPeriod() < ans[0].getPeriod()) {
                ans.clear();
                ans.push_back(tmp);
            } else if (tmp.getPeriod() == ans[0].getPeriod()) {
                ans.push_back(tmp);
            }
        }
    }
    rep(i, ans.size()) {
        cout << ans[i].left << " " << ans[i].right << " " << ans[i].sum << endl;
    }
    /*if ((fp = fopen("diff.txt", "w")) == NULL) {
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
    fclose(fp);*/

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