#include<iostream>
using namespace std;

int dp[1000];

int f(int n, int k){
    dp[0] = 1;
    dp[1] = 1;

    for(int i=2; i<=n; i++){
        dp[i] = 0;
        for(int j=1; j<=k && j<=i; j++){
            dp[i] += dp[i-j];
        }
    }
    return dp[n];
}

int main(){
    int n, k;
    cin>>n>>k;

    cout<<f(n, k)<<endl;
    return 0;
}
