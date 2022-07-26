#include <bits/stdc++.h>

using namespace std;

int main(){
    int L1,R1,L2,R2;
    cin >> L1 >> R1 >> L2 >> R2;
    int ans;
    if(L1 <= L2 && L2 < R1){
        if(R2 > R1){
                ans = R1 - L2;    
        }else{
            ans = R2 - L2;
        }
    }else if(L1 < R2 && R2 <= R1){
        if(L2 < L1){
            ans = R2 - L1;
        }else{
            ans = R2 - L2;
        }
    }else if(L2 <= L1 && R1 <= R2){
        ans = R1 - L1;
    }else{
        ans = 0;
    }

    cout << ans << endl;

    return 0;
}