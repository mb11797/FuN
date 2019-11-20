#include<iostream>
#include<algorithm>
using namespace std;

int binary_search_rec(int*arr, int s, int e, int key){
    if(s>e)
        return -1;

    int mid = (s+e)/2;
    if(key==arr[mid])
        return mid;
    if(key<arr[mid])
        return binary_search_rec(arr, 0, mid-1, key);
    if(key>arr[mid])
        return binary_search_rec(arr, mid+1, e, key);
}

int main(){
    int arr[] = {1,3,5,10,12,15,17};
    int n = sizeof(arr)/sizeof(arr[0]);

    int key;

    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    cin>>key;
    cout<<binary_search_rec(arr, 0, n-1, key)<<endl;

    return 0;
}
