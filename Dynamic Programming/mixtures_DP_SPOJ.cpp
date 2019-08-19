#include<iostream>
#include<climits>
using namespace std;

#define ll long long

ll arr[1000];
ll dp[1001][1001];

ll cum_sum(ll be, ll en){
    ll csum=0;
    for(ll i=be; i<=en; i++){
        csum += arr[i];
        csum %= 100;
    }
    return csum;
}

ll min_smoke_mixture(ll i, ll j){
    //base case
    if(i >= j){
        return 0;
    }

    //if the answer is already there
    //i.e, the case of overlapping subproblems
    if(dp[i][j] != -1){
        return dp[i][j];
    }

    //we need to break our expression at every possible k
    dp[i][j] = INT_MAX;
    for(ll k=i; k<=j; k++){
        dp[i][j] = min(dp[i][j], min_smoke_mixture(i, k) + min_smoke_mixture(k+1, j) + cum_sum(i, k)*cum_sum(k+1, j));
    }
    return dp[i][j];
}

int main(){
    int n;

    while((scanf("%d", &n)) != EOF){
        //read n integers
        for(ll i=0; i<n; i++)
            cin>>arr[i];

        //init dp with -1
        for(ll i=0; i<=n; i++)
            for(ll j=0; j<=n; j++)
                dp[i][j] = -1;

        cout<<min_smoke_mixture(0, n-1)<<endl;

    }

    return 0;
}
