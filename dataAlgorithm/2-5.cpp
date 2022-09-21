#include <iostream>
#include <climits>
#include <algorithm>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

int main()
{

    int N;
    cin >> N;
    int *Rt = new int[N];
    rep(i, N)
    {
        cin >> Rt[i];
    }

    int Rt_min = INT_MAX;
    int tmp = INT_MIN;
    bool upflag = false;

    rep(i, N)
    {
        if (i == 0)
        {
            Rt_min = Rt[0];
            continue;
        }
        /*
        if ((Rt[i] - Rt_min) > tmp)
        {
            tmp = Rt[i] - Rt_min;
        }
        if (Rt_min > Rt[i])
        {
            Rt_min = Rt[i];
        }*/
        tmp = max(tmp, Rt[i] - Rt_min);
        Rt_min = min(Rt_min, Rt[i]);
    }

    cout << tmp << endl;

    return 0;
}
