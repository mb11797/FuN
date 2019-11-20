#include<iostream>
#include<algorithm>
using namespace std;

bool myCompare(int a, int b){
    return a>b;
}

int main(){
    int arr[] = {5,4,3,2,1,6,7};
    int n = sizeof(arr)/sizeof(int);

//    sort(arr, arr+n);
//    sort(arr, arr+4);
//    sort(arr, arr+3);

    sort(arr, arr+n, myCompare);

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
