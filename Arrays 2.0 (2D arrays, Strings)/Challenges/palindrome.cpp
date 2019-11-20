#include<iostream>
using namespace std;

bool palindromeHai(int arr[], int n){
    for(int i=0, j=n-1; i<=j; i++, j--){
        if(arr[i]!=arr[j])
            return 0;
    }
    return 1;
}

int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];

    if(palindromeHai(arr, n))
        cout<<"True"<<endl;
    else
        cout<<"False"<<endl;
    return 0;
}
