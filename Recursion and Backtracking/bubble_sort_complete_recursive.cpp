#include<iostream>
using namespace std;

void bubble_sort_rec(int arr[], int n, int j){
    if(n==1)
        return;
    if(j==n-1){
        bubble_sort_rec(arr, n-1, 0);
        return;
    }

    if(arr[j]>arr[j+1])
        swap(arr[j], arr[j+1]);
    bubble_sort_rec(arr, n, j+1);
    return;
}

int main(){
    int arr[] = {5,4,3,2,1};
    int n = sizeof(arr)/sizeof(int);

    bubble_sort_rec(arr, n, 0);

    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
    return 0;
}
