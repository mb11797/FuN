#include<iostream>
#include<queue>
#include<vector>
#include<functional>
using namespace std;

#define ll long long


typedef pair<ll, pair<ll, ll>> pr;

priority_queue<pr, vector<pr>, greater<pr>> pq;

void merge_k_sorted_arrays(ll arr[10][10], ll out[1000], ll k, ll n){

    for(ll i=0; i<k; i++){
        pq.push({arr[i][0], {i, 0}});
    }

    ll z=0;
    while(!pq.empty()){
        pr p = pq.top();
        pq.pop();

        out[z++] = p.first;
        ll i = p.second.first;
        ll j = p.second.second;

        if(j+1 < n)
            pq.push({arr[i][j+1], {i, j+1}});
    }
    return;
}


int main(){
    ll k;
    cin>>k;

    ll n;
    cin>>n;

    ll arr[10][10];
    ll out[1000];
    for(ll i=0; i<k; i++)
        for(ll j=0; j<n; j++)
            cin>>arr[i][j];

    merge_k_sorted_arrays(arr, out, k, n);

    for(ll i=0; i<k*n; i++)
        cout<<out[i]<<" ";

    return 0;
}
