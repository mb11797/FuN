#include<iostream>
using namespace std;

int dp[10000];

int min_steps_to_1(int n){
    dp[0] = 0;
    dp[1] = 0;

    for(int i=2; i<=n; i++){
        dp[i] = 1 + dp[i-1];
        if(i%2 == 0){
            dp[i] = min(dp[i], 1 + dp[i/2]);
        }
        if(i%3 == 0){
            dp[i] = min(dp[i], 1 + dp[i/3]);
        }
    }
    return dp[n];
}

int main(){
    int n;
    cin>>n;

    cout<<min_steps_to_1(n)<<endl;
    return 0;
}
