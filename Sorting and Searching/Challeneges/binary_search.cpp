#include<iostream>
using namespace std;

#define ll long long

ll binarySearch(ll*a, ll n, ll key){
    ll s = 0, e = n-1;
    ll mid;
    while(s<=e){
        mid = (s+e)/2;
        if(a[mid]==key){
            return mid;
        }
        else if(a[mid]<key){
            s = mid+1;
        }
        else{
            e = mid-1;
        }
    }
    return -1;
}

int main(){
    ll n;
    cin>>n;

    ll arr[10000];
    for(ll i=0; i<n; i++){
        cin>>arr[i];
    }

    ll key;
    cin>>key;

    cout<<binarySearch(arr, n, key)<<endl;

    return 0;
}
