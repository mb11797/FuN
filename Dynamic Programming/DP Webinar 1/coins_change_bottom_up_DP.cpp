#include<iostream>
using namespace std;

#define ll long long
#define INT_MAX 9999999
ll coins[10000];
ll n_coins;
ll dp[10001];


ll min_no_of_coins_for_change(ll n){
    dp[0] = 0;

    //if change not possible, then INT_MAX will be filled
    for(ll i=1; i<=n; i++){
        dp[i] = INT_MAX;
        for(ll j=0; j<n_coins; j++){
            if(i - coins[j] >= 0){
                dp[i] = min(dp[i], 1 + dp[i-coins[j]]);
            }
        }
    }
    return dp[n];
}

int main(){
    coins[0] = 1;
    coins[1] = 7;
    coins[2] = 10;
    n_coins = 3;

    ll n;
    cin>>n;

    ll ans = min_no_of_coins_for_change(n);
    if(ans == INT_MAX)
        cout<<"Change not possible!!!"<<endl;
    else
        cout<<ans<<endl;

    return 0;
}
