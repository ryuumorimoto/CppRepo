#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

int main()
{

    int N;
    cin >> N;
    int *a = new int[N];
    rep(i, N)
    {
        cin >> a[i];
    }

    long long count = 0;
    int sameindex = 0;
    rep(i, N)
    {
        if (a[i] == i + 1)
        {
            sameindex += 1;
        }
    }

    rep(i, N)
    {
        int now = a[i];
        if (now == i + 1)
        {
            sameindex -= 1;
            count += (long long)sameindex;
        }
        else
        {
            if (a[now - 1] == i + 1 && now - 1 > i)
            {
                count += 1;
            }
        }
    }
    cout << count << endl;
    delete[] a;
    return 0;
}
