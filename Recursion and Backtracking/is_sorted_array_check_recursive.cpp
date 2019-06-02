#include<iostream>
using namespace std;

bool is_sorted(int*arr, int n){
    if(n==1)
        return true;

    if(arr[0]<arr[1] && is_sorted(arr+1, n-1))
        return true;

    return false;
}

int main(){
    int arr[] = {1,2,3,5,7};
    int n=5;

    if(is_sorted(arr, n))
        cout<<"Yeah bro, its Sorted <3"<<endl;
    else
        cout<<"Naah, its not Sorted bruh"<<endl;
    return 0;
}
