#include<iostream>
using namespace std;

int last_index(int arr[], int n, int v_idx, int key){
    if(v_idx == n)
        return -1;

    int rr = last_index(arr, n, v_idx+1, key);
    if(rr == -1 && arr[v_idx] == key)
        return v_idx;
    return rr;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];

    int key;
    cin>>key;

    cout<<last_index(arr, n, 0, key)<<endl;

    return 0;
}
