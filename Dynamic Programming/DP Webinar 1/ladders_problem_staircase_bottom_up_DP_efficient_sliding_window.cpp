#include<iostream>
using namespace std;

int dp[1000];

int f(int n, int k){
    dp[0] = 1;
    dp[1] = 1;

    for(int i=2; i<=k; i++){
        dp[i] = 2*dp[i-1];                          //for 2<=i<=k => dp[i] = 2*dp[i-1]
    }

    for(int i=k+1; i<=n; i++){
        dp[i] = 2*dp[i-1] - dp[i-(k+1)];            //for k<i<=n => dp[i] = dp[i-1] - dp[i-(k+1)} + dp[i-1]
    }
    return dp[n];
}

int main(){
    int n, k;
    cin>>n>>k;


    cout<<f(n, k)<<endl;
    return 0;
}
