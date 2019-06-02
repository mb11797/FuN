#include<iostream>
using namespace std;

int*merge(int*arr_1, int n1, int*arr_2, int n2, int*merged_arr, int k){
    if(n1==0)
        return arr_2;

    if(n2==0)
        return arr_1;

    if(arr_1[0]<arr_2[0]){
        merged_arr[k] = arr_1[0];
        merged_arr = merge(arr_1 + 1, n1-1, arr_2, n2, merged_arr, k+1);
    }
    else{
        merged_arr[k] = arr_2[0];
        merged_arr = merge(arr_1, n1, arr_2 + 1, n2-1, merged_arr, k+1);
    }
    return merged_arr;
}

int* merge_sort(int*arr, int n){
    if(n==1)
        return arr[0];

    int*arr_1 = merge_sort(arr, n/2);
    int*arr_2 = merge_sort(arr+n/2, n/2);

    int merged_arr[n];
    arr = merge(arr_1, n/2, arr_2, n/2, merged_arr, 0);

    return arr;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];

    int*sorted_arr = merge_sort(arr, n);

    for(int i=0; i<n; i++)
        cout<<sorted_arr[i]<<" ";

    return 0;
}
