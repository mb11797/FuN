#include<iostream>
#include<cstring>
using namespace std;

#define ll long long

char a[2005], b[2005];
ll m, n, k;
ll memo[2005][2005][8];                 //m, n, k

ll k_LCS(ll i, ll j, ll k){
    if(i==m || j==n){
        //if any string is finished, ans is 0
        return 0;
    }

    //if current state has already been computed
    if(memo[i][j][k] != -1){
        return memo[i][j][k];
    }

    ll res = 0;
    if(a[i] == b[j]){
        res = 1 + k_LCS(i+1, j+1, k);
    }
    else{
        if(k>0){
            //we have converted a single char to match with jth char of string b
            res = 1 + k_LCS(i+1, j+1, k-1);
        }
        res = max(res, k_LCS(i, j+1, k));
        res = max(res, k_LCS(i+1, j, k));
    }

    memo[i][j][k] = res;
    return memo[i][j][k];
}

int main(){
    memset(memo, -1, sizeof(memo));

    cin>>m>>n>>k;

    for(int i=0; i<m; i++)
        cin>>a[i];

    for(int j=0; j<n; j++)
        cin>>b[j];

    ll ans = k_LCS(0, 0, k);
    cout<<ans<<endl;

    return 0;
}
