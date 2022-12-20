#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;

int main(){
    /*int N;
    cin >> N;
    string S[N];
    int C[N];
    for(int i=0;i<N;i++){
        cin >> S[i];
        C[i] = 0;
    }

    for(int i=0;i<N;i++){
        int count = 0;
        for(int j=i-1;j >= 0;j--){
            //cout << i << " , "<<j << endl;
            if(S[j] == S[i]){   
                cout << "call break" << endl;
                count = C[j] +1;  

                break;                
            }
            
        }

        if(count == 0){
            cout << S[i] << endl;            
        }else{
            cout << S[i] + "(" + to_string(count) + ")" << endl;            
        }
        C[i] = count;
    }    */

    int N;
    cin >> N;
    string S[N];
    rep(i,N){
        cin >> S[i];
    }
    map<string,int>mymap;
    rep(i,N){
        //cout << mymap[S[i]] << endl;
        if(mymap[S[i]] == 0){
            cout << S[i] << endl;
            mymap[S[i]] = 1;
        }else{
            cout <<S[i]<< "(" << mymap[S[i]] << ")" << endl;
            mymap[S[i]]++;
        }
    }




    return 0;
}