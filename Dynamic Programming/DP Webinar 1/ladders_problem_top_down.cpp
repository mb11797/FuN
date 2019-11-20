#include<iostream>
#include<cstring>
using namespace std;

int memo[1000];

int f(int n, int k){
    if(n==0){
        return 1;
    }

    if(n<0){
        return 0;
    }

    if(memo[n] != -1){
        return memo[n];
    }

    int ans = 0;
    for(int i=1; i<=k; i++){
        ans += f(n-i, k);
    }
    return memo[n] = ans;
}

int main(){
    memset(memo, -1, sizeof(memo));
    int n, k;
    cin>>n>>k;

    cout<<f(n, k)<<endl;
    return 0;
}
