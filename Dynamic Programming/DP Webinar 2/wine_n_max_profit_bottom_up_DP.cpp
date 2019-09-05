#include<iostream>
using namespace std;

#define ll long long
ll wines[100];
ll dp[101][101] = {0};

ll max_profit(ll n){
    ll yr = n;
    //for be<en  => dp[be][en] = 0
    //for be==en = i => dp[i][i] represents the cost of selling ith wine in the end => dp[i][i] = wines[i]*n
    for(ll i=0; i<n; i++){
        dp[i][i] = wines[i]*yr;
    }

    yr--;

    for(ll len=2; len<=n; len++){
        ll start = 0;
        ll end = n - len;
        while(start<=end){
            ll end_window = start + len - 1;
            dp[start][end_window] = max(wines[start]*yr + dp[start+1][end_window], wines[end_window]*yr + dp[start][end_window-1]);
            start++;
        }
        yr--;
    }
    return dp[0][n-1];
}

int main(){
    ll n;
    cin>>n;

    for(ll i=0; i<n; i++)
        cin>>wines[i];

    cout<<max_profit(n)<<endl;

    return 0;
}
