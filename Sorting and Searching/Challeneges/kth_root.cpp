#include<iostream>
#include<math.h>
using namespace std;

#define ll long long int

ll kth_root(ll n, ll k){
    ll s = 0;
    ll e = n;

    ll mid;
    ll ans;
    while(s<=e){
        mid = (s+e)/2;

        if(pow(mid, k) <= n){
            ans = mid;
            s = mid+1;
        }
        else{
            e = mid-1;
        }
    }
    return ans;
}

int main(){
    int tc;
    cin>>tc;

    ll n;
    ll k;

    while(tc--){
        cin>>n>>k;
        cout<<kth_root(n, k)<<endl;
    }
    return 0;
}
