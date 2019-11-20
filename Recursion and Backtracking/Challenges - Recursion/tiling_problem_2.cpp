#include<iostream>
using namespace std;

#define ll long long

ll tiling_ways(ll n, ll m){
    if(n<m)
        return 1;

    return tiling_ways(n-1, m) + tiling_ways(n-m, m);
}

int main(){
    ll tc;
    cin>>tc;
    while(tc--){
        ll n, m;
        cin>>n>>m;

        cout<<tiling_ways(n, m)<<endl;
    }
    return 0;
}
