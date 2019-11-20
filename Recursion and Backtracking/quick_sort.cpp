#include<iostream>
using namespace std;

int partition(int arr[], int s, int e){
    int i = s-1;
    int j = s;
    int pivot = arr[e];

    for(; j<e; j++){
        if(arr[j]<=pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    //Bring the pivot element to its sorted position
    swap(arr[i+1], arr[e]);
    return i+1;
}

void quick_sort(int*arr, int s, int e){
    if(s>=e)
        return;

    int p = partition(arr, s, e);
    quick_sort(arr, s, p-1);
    quick_sort(arr, p+1, e);
    return;
}

int main(){
    int arr[] = {2,1,5,6,7,5,8};
    int n = sizeof(arr)/sizeof(int);
    quick_sort(arr, 0, n-1);

    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";


    return 0;
}
