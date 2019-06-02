#include<iostream>
using namespace std;

#define ll long long
#define c 1000000007

//Iterative/Tabulation method in DP - Bottom Up Approach
ll tiling_ways_fast(ll n, ll m){
    if(n<m)
        return 1;

    ll count[n+1];
    count[0] = 0;

    for(ll i=1; i<=n; i++){
        //base case
        if(i<m)
            count[i] = 1;
        //recurrence relation
        else if(i>m)
            count[i] = (count[i-1] + count[i-m])%c;
        //i==m
        else
            count[i] = 2;
    }
    return count[n]%c;
}

int main(){
    ll tc;
    cin>>tc;

    while(tc--){
        ll n, m;
        cin>>n>>m;

        cout<<tiling_ways_fast(n, m)<<endl;
    }
    return 0;
}
