#include<iostream>
using namespace std;

void bubble_sort(int*arr, int n){
    if(n==1)
        return;

    //sort 1 element and call for remaining n-1 elements
    for(int j=0; j<=n-2; j++){
        if(arr[j]>arr[j+1]){
            swap(arr[j], arr[j+1]);
        }
    }
    bubble_sort(arr, n-1);
    return;
}

int main(){
    int arr[] = {5,4,3,2,1};
    int n = sizeof(arr)/sizeof(int);

    bubble_sort(arr, n);

    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
    return 0;
}
