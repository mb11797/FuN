#include<iostream>
using namespace std;

int arr[100];

bool is_sorted(int be, int en){
    for(int i=be; i<en; i++){
        if(arr[i] > arr[i+1]){
            return false;
        }
    }
    return true;
}

int max_sorted_array_thanos_sort(int be, int en){
    if(be == en){
        return 1;
    }
    if(is_sorted(be, en)){
        return en - be + 1;
    }
    int mid = (be+en)/2;

    int op1 = max_sorted_array_thanos_sort(be, mid);
    int op2 = max_sorted_array_thanos_sort(mid+1, en);
    return max(op1, op2);
}

int main(){

    //n - guaranteed to be some power of 2
    int n;
    cin>>n;

    for(int i=0; i<n; i++)
        cin>>arr[i];

    cout<<max_sorted_array_thanos_sort(0, n-1)<<endl;

    return 0;
}
