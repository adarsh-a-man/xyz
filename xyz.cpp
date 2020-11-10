#include<bits/stdc++.h>
using namespace std;
int count1 = 0;
void funUtil(int n, char prev){
    if(n == 1){
        if(prev!='a') count1++;
        return;
    }
    if(prev=='a'){
        funUtil(n-1, 'b');
        funUtil(n-1, 'c');
    }
    else if(prev=='b'){
        funUtil(n-1, 'a');
        funUtil(n-1, 'c');
    }
    else if(prev=='c'){
        funUtil(n-1, 'b');
        funUtil(n-1, 'a');
    }
    return;
}
int fun(int n){
    if(n==0 || n==1) return 0;
    funUtil(n, 'a');
    return count1;
}
int main(){
    int n;
    cin>>n;
    cout<<fun(n);
    return 0;
}
