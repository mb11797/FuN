#include<iostream>
using namespace std;

#define ll long long

void merge(ll arr[], ll s, ll e){
    ll mid = (s+e)/2;

    ll i = s;
    ll j = mid+1;
    ll k = s;

    ll temp[100000];

    while(i<=mid && j<=e){
        if(arr[i]<arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while(i<=mid)
        temp[k++] = arr[i++];

    while(j<=e)
        temp[k++] = arr[j++];

    //Now we need to copy all elements from temp array to original array
    for(ll i=s; i<=e; i++)
        arr[i] = temp[i];

}


void merge_sort(ll arr[], ll s, ll e){
    if(s>=e)
        return;

    //follow 3 steps:
    //1st: Divide
    ll mid = (s+e)/2;

    //2nd: Recursively sort the arrays - s->mid and mid+1->e
    merge_sort(arr, s, mid);
    merge_sort(arr, mid+1, e);

    //3rd: Merge the two parts
    merge(arr, s, e);

}

int main(){
    ll n;
    cin>>n;
    ll arr[100000];
    for(ll i=0; i<n; i++)
        cin>>arr[i];

    merge_sort(arr, 0, n-1);

    for(ll i=0; i<n; i++)
        cout<<arr[i]<<" ";

    return 0;
}
