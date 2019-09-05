#include<iostream>
using namespace std;

#define ll long long
ll wines[100];
ll dp[101][101] = {0};

ll max_profit(ll n){

    //for be<en  => dp[be][en] = 0
    //for be==en = i => dp[i][i] represents the cost of selling ith wine in the end => dp[i][i] = wines[i]*n
    for(ll i=0; i<n; i++){
        dp[i][i] = n*wines[i];
    }

    for(ll be=0; be<n-1; be++){
        ll yr=1;
        for(ll en=be+1; en<n; en++){
            dp[be][en] = max(wines[be]*yr + dp[be+1][en], wines[en]*yr + dp[be][en-1]);
            yr++;
        }
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
