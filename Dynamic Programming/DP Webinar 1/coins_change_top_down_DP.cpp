#include<iostream>
#include<cstring>
using namespace std;

#define ll long long

ll coins[100];
ll memo[100];

ll min_no_of_coins_in_change(ll n, ll n_coins){
//    cout<<n<<"      ";
    //base case
    if(n <= 0){
        return 0;
    }

    if(memo[n] != -1){
        return memo[n];
    }

    ll ans = INT_MAX;
    for(ll i=0; i<n_coins; i++){
        if(n >= coins[i]){
            ans = min(ans, 1 + min_no_of_coins_in_change(n-coins[i], n_coins));
        }
    }
    return memo[n] = ans;
}

int main(){
    memset(memo, -1, sizeof(memo));
    coins[0] = 1;
    coins[1] = 7;
    coins[2] = 10;

    ll n;
    cin>>n;

    cout<<min_no_of_coins_in_change(n, 3)<<endl;

    return 0;
}
