#include<iostream>
using namespace std;

#define ll long long

ll find_last_occurence(ll*arr, ll n, ll key, ll locn, ll i){
    if(i==n)
        return locn;

    if(arr[i]==key)
        locn = i;
    return find_last_occurence(arr, n, key, locn, i+1);

}

int main(){
    ll n;
    cin>>n;

    ll arr[n];
    for(ll i=0; i<n; i++)
        cin>>arr[i];

    ll key;
    cin>>key;

    cout<<find_last_occurence(arr, n, key, -1, 0)<<endl;

    return 0;
}
