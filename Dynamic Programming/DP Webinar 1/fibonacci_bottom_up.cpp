#include<iostream>
#include<cstring>
using namespace std;

int dp[1000];

int fib(int n){
    dp[0] = 0;
    dp[1] = 1;

    for(int i=2; i<=n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}



int main(){
    memset(dp, -1, sizeof(dp));
    int n;
    cin>>n;
    cout<<fib(n)<<endl;
    return 0;
}
