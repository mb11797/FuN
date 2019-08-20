#include<iostream>
#include<cstring>
using namespace std;

#define ll long long
#define mod 1000003

ll n, k;
ll memo[105][3][105];

ll f(ll i, ll prev, ll count){
    if(i == n){
        if(count == k)
            return 1;

        return 0;
    }

    //Top-down DP - Memoization
    if(memo[i][prev][count] != -1){
        return memo[i][prev][count];
    }

    ll ans=0;
    if(prev == 1){
        ans = ans + f(i+1, 1, count+1);
    }
    else{
        ans = ans + f(i+1, 1, count);
    }
    ans %= mod;

    //when current element we put is 0
    ans = ans + f(i+1, 0, count);
    ans %= mod;

    memo[i][prev][count] = ans;
    return memo[i][prev][count];
}

int main(){
    int tc;
    cin>>tc;
    memset(memo, -1, sizeof(memo));
    while(tc--){
        memset(memo, -1, sizeof(memo));
        cin>>n>>k;
        cout<<(f(1, 0, 0) + f(1, 1, 0))%mod<<endl;                  //start by both choices, i.e, with first value either 0 or 1
    }

    return 0;
}
