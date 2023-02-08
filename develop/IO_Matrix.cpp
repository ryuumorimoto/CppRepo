#include </Users/morimoto/Desktop/gitrepo/nana/NanaNewUISample/NASession/Effects/Filter/eigen/Eigen/Dense>
#include <iostream>

#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

int main(int argc, char* argv[]) {
    FILE* fp;
    if ((fp = fopen("problem.in", "r")) == NULL) {
        cout << "not exist file" << endl;
        exit(-1);
    }
    int num;
    char separator;
    while (fscanf(fp, "%d%c", &num, &separator) != EOF) {
        cout << num << " and " << separator << "desu" << endl;
    }    

    Eigen::MatrixXd m(2, 2);
    m(0, 0) = 3;
    m(1, 0) = 2.5;
    m(0, 1) = -1;
    m(1, 1) = m(1, 0) + m(0, 1);
    std::cout << m << std::endl;

    Eigen::MatrixXd m2(2, 1);
    m2(0,0) = 1;
    m2(1,0) = 2;
    cout << m*m2 << endl;
    return 0;
}