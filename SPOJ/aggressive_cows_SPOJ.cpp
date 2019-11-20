#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;

#define ll long long

bool is_this_gap_possible(ll*arr, ll n, ll cows, ll ans){

    int temp=0;

    while(--cows){
        int srch = arr[temp] + ans;
        int found = lower_bound(arr+temp+1, arr+n, srch) - arr;
        if(found == n){
            return false;
        }
        temp = found;
    }

//    ll cows_placed=1;
//    ll prev = arr[0];
//    for(ll i=1; i<n; i++){
//        if(arr[i]-prev>=ans){
//            prev = arr[i];
//            cows_placed++;
//            if(cows_placed==cows)
//                return true;
//        }
//    }
//    if(cows_placed<cows)
//        return false;
    return true;
}

int main(){
    ll tc;
    cin>>tc;

    ll n, c;
    while(tc--){
        cin>>n>>c;

        ll arr[n];
        for(ll i=0; i<n; i++)
            cin>>arr[i];

        sort(arr, arr+n);


        ll min = INT_MAX;
        for(ll i=0; i<n-1; i++){
            if(min>arr[i+1]-arr[i])
                min = arr[i+1] - arr[i];
        }
        ll max = arr[n-1] - arr[0];
        ll s=min, e = max;

        ll ans;
        while(s<=e){
            ll mid = (s+e)/2;
            if(is_this_gap_possible(arr, n, c, mid)){
                ans = mid;
                s = mid+1;
            }
            else{
                e = mid-1;
            }
        }

        cout<<ans<<endl;
    }
    return 0;
}
