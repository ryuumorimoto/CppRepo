#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

int main()
{
    int N,M;
    cin >> N >> M;
    int *U = new int[M];
    int *V = new int[M];
    rep(i,M){
        cin >> U[i] >> V[i];
    }

    int count = 0;
    rep(i,M){
        int low = U[i];
        int high = V[i];
        int tmp;        

        for(int j=i+1;j<M;j++){
            bool flag = false;
            int tmpindex = -1;

            if(U[j] == low){
                
            }
            
        }


    }
    
    return 0;
}
