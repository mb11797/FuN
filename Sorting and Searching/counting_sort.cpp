#include<iostream>
using namespace std;

void counting_sort(int*arr, int n){
    int mx = arr[0];
    for(int i=1; i<n; i++){
        if(arr[i]>mx){
            mx = arr[i];
        }
    }

    int freq[mx+1] = {0};

    for(int i=0; i<n; i++){
        freq[arr[i]]++;
    }

    for(int i=0; i<mx+1; i++){
        while(freq[i]){
            cout<<i<<" ";
            freq[i]--;
        }
    }
    return;
}

int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    counting_sort(arr, n);

    return 0;
}
