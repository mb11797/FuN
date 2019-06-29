#include<iostream>
#include<algorithm>
using namespace std;

#define ll long long

ll find_no_of_distinct_integers(ll arr[], ll n){
    sort(arr, arr+n);
    ll k = 1;
    for(ll i=0; i<n; i++){
        if(arr[i]!=arr[i+1])
            k++;
    }
    return k;
}

ll* hash_array(ll A[], ll n, ll MAX)
{
    ll* hash = new ll[MAX]; //MAX is the maximum possible value of A[i]
    for(ll i=0;i<=MAX;i++) hash[i]=-1; //initialize hash to -1.
    ll count = 0;
    for(ll i=0;i<n;i++) // Loop through elements of array
    {
        if(hash[A[i]] == -1) // A[i] was not assigned any hash before
        {
            hash[A[i]] = count; // Assigning hash to A[i]
            count++;
            continue;
        }
        for(ll j = 0;j<i;j++)
        {
            if(hash[A[j]] > hash[A[i]]) // All the hashes greater than previous hash of A[i] are decremented.
                hash[A[j]]--;
        }
        hash[A[i]] = count - 1; // Assigning a new hash to A[i]
    }
    return hash;
}

int main(){
    ll n;
    cin>>n;

    ll arr[n];
    cin>>arr[0];

    ll MAX=arr[0];

    for(ll i=1; i<n; i++){
        cin>>arr[i];
        if(arr[i]>MAX)
            MAX=arr[i];
    }
    ll*hash = hash_array(arr, n, MAX);

    ll k = find_no_of_distinct_integers(arr, n);


    for(ll i=1; i<=k; i++){
        for(ll j=0; j<=MAX; j++){
            if(hash[j]==i-1)
                cout<<j<<endl;
        }
    }

    return 0;
}
