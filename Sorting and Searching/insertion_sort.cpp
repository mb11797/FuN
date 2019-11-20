#include<iostream>
using namespace std;

void insertion_sort(int a[], int n){

    for(int i=1; i<n; i++){
        int no = a[i];
        int j = i-1;
        while(j>=0 and a[j]>no){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = no;
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

    insertion_sort(arr, n);

    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";

    return 0;
}
