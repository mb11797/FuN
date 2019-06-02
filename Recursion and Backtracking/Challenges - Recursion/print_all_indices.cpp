#include<iostream>
using namespace std;

#define ll long long

void print_all_indices(ll*arr, ll n, ll key, ll i, ll locn){
    if(i==n){
        if(locn == -1)
            cout<<locn<<" ";
        return;
    }

    if(arr[i]==key){
        locn = i;
        cout<<locn<<" ";
    }
    print_all_indices(arr, n, key, i+1, locn);
    return;
}

int main(){
    ll n;
    cin>>n;

    ll arr[n];
    for(ll i=0; i<n; i++)
        cin>>arr[i];

    ll key;
    cin>>key;

    print_all_indices(arr, n, key, 0, -1);

    return 0;
}
