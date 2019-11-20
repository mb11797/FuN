#include<iostream>
using namespace std;

int linear_search(int*arr, int n, int key, int i){
    if(i==n)
        return -1;
    if(arr[i]==key)
        return i;
    return linear_search(arr, n, key, i+1);
}

int main(){
    int arr[] = {1,3,2,5,6,9};
    int n = sizeof(arr)/sizeof(int);

    int key = 15;
    cout<<linear_search(arr, n, key, 0)<<endl;
    return 0;
}
