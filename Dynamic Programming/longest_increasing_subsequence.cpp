#include<iostream>
using namespace std;


int longest_inc_subseq(int*arr, int n){
    int dp[101];

    //base case
    for(int i=0; i<n; i++)
        dp[i] = 1;

    int longest_till_now = -1;
    for(int i=1; i<n; i++){
        for(int j=0; j<i; j++){
            if(arr[j] <= arr[i]){
                //jth element can be absorbed by ith element
                int cur_len = 1 + dp[j];
                dp[i] = max(cur_len, dp[i]);
            }
        }
        longest_till_now = max(longest_till_now, dp[i]);
    }

    for(int i=0; i<n; i++)
        cout<<dp[i]<<"  ";
    cout<<endl;
    return longest_till_now;
}

int main(){
    int n;
    cin>>n;

    int arr[100];
    for(int i=0; i<n; i++)
        cin>>arr[i];

    cout<<longest_inc_subseq(arr, n)<<endl;

    return 0;
}
