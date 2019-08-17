#include<iostream>
#include<cstring>
using namespace std;
#define ll long long

ll dp[2005][2005][8];
ll n, m, k, a[2005], b[2005];


ll k_ordered_lcs(ll i, ll j, ll k){
    if(i==m || j==n)                        // if any string is finished, ans is zero
        return 0;

    //if current state has already been computed
    if(dp[i][j][k] != -1){
        return dp[i][j][k];
    }

    ll res=0;

    if(a[i]==b[j]){
        res = 1 + k_ordered_lcs(i+1, j+1, k);
    }
    else{
        if(k>0){
            res = 1 + k_ordered_lcs(i+1, j+1, k-1);             // we have converted a single character to match with jth of string b
        }

        res = max(res, k_ordered_lcs(i, j+1, k));
        res = max(res, k_ordered_lcs(i+1, j, k));
    }
    return dp[i][j][k] = res;
}

int main(){
    memset(dp, -1, sizeof(dp));
    ll k;
    cin>>n>>m>>k;

    for(ll i=0; i<m; i++)
        cin>>a[i];

    for(ll j=0; j<n; j++)
        cin>>b[j];

    cout<<k_ordered_lcs(0, 0, k)<<endl;

    return 0;
}

