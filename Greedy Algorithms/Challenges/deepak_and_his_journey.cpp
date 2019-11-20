#include<iostream>
using namespace std;

#define ll long long

ll find_min_cost(ll c[], ll L[], ll n){

    ll good_pp = 0;
    ll total_fuel = L[good_pp];
    ll total_cost = 0;

    for(ll i=1; i<n; i++){
        if(c[good_pp]<c[i]){
            total_fuel += L[i];
        }
        else{
            total_cost += total_fuel * c[good_pp];
            good_pp = i;
            total_fuel = L[i];
        }
        if(i==n-1){
            total_cost += total_fuel * c[good_pp];
        }
    }
    return total_cost;
}


int main(){
    ll tc;
    cin>>tc;

    while(tc--){
        ll n_chkpts;
        cin>>n_chkpts;

        ll cost[n_chkpts];
        for(ll i=0; i<n_chkpts; i++)
            cin>>cost[i];


        ll litres[n_chkpts];

        for(ll i=0; i<n_chkpts; i++)
            cin>>litres[i];

        cout<<find_min_cost(cost, litres, n_chkpts)<<endl;
    }

    return 0;
}
