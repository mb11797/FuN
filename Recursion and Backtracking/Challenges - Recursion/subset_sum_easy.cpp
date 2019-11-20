#include<iostream>
using namespace std;

bool check_zero_sum_subset(int arr[], int n, int i, int sum, int count){
    if(i==n){
        if(count>0 && sum==0)
            return true;
        else
            return false;
    }

    bool ans = check_zero_sum_subset(arr, n, i+1, sum+arr[i], count+1) || check_zero_sum_subset(arr, n, i+1, sum, count);

    return ans;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];

    int sum = 0;
    if(check_zero_sum_subset(arr, n, 0, sum, 0))
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
    return 0;
}
