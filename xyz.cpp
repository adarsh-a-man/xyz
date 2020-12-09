#include<bits/stdc++.h>
using namespace std;

bool zeroes(int N, int m){
    int maxm = -1; 
    int cnt = 0; 
  
    while (N) { 
        if (!(N & 1)) { 
            cnt++; 
            N >>= 1; 
            maxm = max(maxm, cnt); 
        } 
        else { 
  
            maxm = max(maxm, cnt); 
            cnt = 0; 
            N >>= 1; 
        }
        if(maxm>=m) return true;
    } 
    return false; 
}
int countOfBinaryNumber(int n, int m){
    int total, result = 0;
    total = pow(2, n-1);
    for(int i=total; i<2*total; i++){
        if(zeroes(i, m)){
            result++;
        }
    }
    return total-result;
}
int main(){
    int n, m;
    cin>>n>>m;
    cout<<countOfBinaryNumber(n, m);
}
