#include <bits/stdc++.h>

using namespace std;

int main(){
    int N;
    cin >> N;
    string A[N];
    string ans;
    const char * W = "W";
    const char *L= "L";
    const char *Dr = "D";
    
    for(int i=0;i<N;i++){
        cin >> A[i];        
    }      

    bool flag = false;
    for(int i= 0;i<N;i++){
        for(int j=i+1;j<N;j++){
        //for(int j=0;j<N;j++){
            if(i != j){

                if(A[i][j] == W[0]){
                    if(A[j][i] != L[0]){
                        flag = true;
                        //cout << i << j <<endl;
                        break;
                    }       

                }else if(A[i][j] == L[0]){
                    if(A[j][i] != W[0]){
                        flag = true;
                        //cout << i << j <<endl;
                        break;
                    } 
                
                }else if(A[i][j] == Dr[0]){
                    if(A[j][i] != Dr[0]){
                        flag = true;
                        //cout << i << j <<endl;
                        break;
                    } 
                }
            }
        }

        if(flag){
            break;
        }
    }

    if(flag){
        cout << "incorrect" << endl;
    }else{
        cout << "correct" << endl;
    }

    

    return 0;
}