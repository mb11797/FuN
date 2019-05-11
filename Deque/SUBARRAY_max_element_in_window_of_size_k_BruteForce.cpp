#include<iostream>
using namespace std;

int max_element_k_subarr(int*arr, int n, int k, int*maxElmts){
    int count=0;
    for(int i=0; i<n-k+1; i++){
        maxElmts[count] = arr[i];
        for(int j=i; j<i+k; j++){
            maxElmts[count] = (maxElmts[count]<arr[j]) ? arr[j] : maxElmts[count];
        }
        count++;
    }
    return count;
}

int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int k;
    cin>>k;

    int maxElmts[n];
    int count = max_element_k_subarr(arr, n, k, maxElmts);
    cout<<count<<endl;
    for(int i=0; i<count; i++){
        cout<<maxElmts[i]<<" ";
    }
    return 0;
}
