#include<iostream>
#include<algorithm>
using namespace std;

#define ll long long

int find_no_of_distinct_integers(int arr[], int n){
    sort(arr, arr+n);
    int k = 1;
    for(int i=0; i<n; i++){
        if(arr[i]!=arr[i+1])
            k++;
    }
    return k;
}

int* hash_array(int A[], int n, int MAX)
{
    int* hash = new int[MAX]; //MAX is the maximum possible value of A[i]
    for(int i=0;i<=MAX;i++) hash[i]=-1; //initialize hash to -1.
    int count = 0;
    for(int i=0;i<n;i++) // Loop through elements of array
    {
        if(hash[A[i]] == -1) // A[i] was not assigned any hash before
        {
            hash[A[i]] = count; // Assigning hash to A[i]
            count++;
            continue;
        }
        for(int j = 0;j<i;j++)
        {
            if(hash[A[j]] > hash[A[i]]) // All the hashes greater than previous hash of A[i] are decremented.
                hash[A[j]]--;
        }
        hash[A[i]] = count - 1; // Assigning a new hash to A[i]
    }
    return hash;
}

int main(){
    int n;
    cin>>n;

    int arr[n];
    cin>>arr[0];

    int MAX=arr[0];

    for(int i=1; i<n; i++){
        cin>>arr[i];
        if(arr[i]>MAX)
            MAX=arr[i];
    }
    int*hash = hash_array(arr, n, MAX);

    int k = find_no_of_distinct_integers(arr, n);


    for(int i=1; i<=k; i++){
        for(int j=0; j<=MAX; j++){
            if(hash[j]==i-1)
                cout<<j<<endl;
        }
    }

    return 0;
}
