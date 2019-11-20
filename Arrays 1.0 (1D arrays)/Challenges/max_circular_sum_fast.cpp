#include<iostream>
using namespace std;

int kadane(int *arr, int n){
    int curr_sum = 0;
    int max_sum = 0;

    for(int i=0; i<n; i++){
        curr_sum += arr[i];
        if(curr_sum<0)
            curr_sum = 0;
        if(curr_sum>max_sum)
            max_sum = curr_sum;
    }
    return max_sum;
}

int max_subarr_sum_circ_arr(int arr[], int n){
    int max_kadane = kadane(arr, n);

    int max_circ_sum = 0;
    for(int i=0; i<n; i++){
        max_circ_sum += arr[i];
        arr[i] = -arr[i];
    }

    max_circ_sum = max_circ_sum + kadane(arr, n);

    return (max_circ_sum>max_kadane)? max_circ_sum : max_kadane;
}

int main(){
    int tc;
    cin>>tc;

    while(tc--){
        int n;
        cin>>n;

        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];

        cout<<max_subarr_sum_circ_arr(arr, n)<<endl;

    }

}
