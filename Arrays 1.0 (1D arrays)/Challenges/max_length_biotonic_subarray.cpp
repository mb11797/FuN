#include<iostream>
using namespace std;

//  12  4   78  90  45  23

int max_len_biotonic(int arr[], int n){
    int max_len = 0;
    int flag = 0;
    int len;
    for(int i=0; i<n; i++){
        flag = 1;
        len = 1;
        max_len = (max_len < len? len : max_len);
        for(int j=i; j<n-1; j++){
            if(arr[j]>arr[j+1] && len==1){
                break;
            }
            else if(arr[j]<arr[j+1] && flag==1){
                len++;
                max_len = (max_len < len) ? len : max_len;
            }
            else if(arr[j]<arr[j+1] && flag==0){
                break;
            }
            else if(arr[j]>arr[j+1]){
                flag = 0;
                len++;
                max_len = (max_len < len) ? len : max_len;
            }
        }
    }
    return len;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];

    cout<<max_len_biotonic(arr, n);
    return 0;
}
