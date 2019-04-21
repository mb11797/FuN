#include<iostream>
using namespace std;

void sort_array(int arr[], int n){
    int s=0, m=0, e=n-1;

    while(m<=e){
        if(arr[m]==0){
            swap(arr[s], arr[m]);
            s++;
            m++;
        }
        else if(arr[m]==1){
            m++;
        }
        else if(arr[m]==2){
            swap(arr[m], arr[e]);
            e--;
        }
    }
}

int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    sort_array(arr, n);

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}
