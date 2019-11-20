#include<iostream>
using namespace std;

int find_unique_no(int*arr, int n){
    int cnt[64] = {0};
    //Extract bits of every number and update the count array
    for(int i=0; i<n; i++){
        int j=0;
        int no = arr[i];
        while(no>0){
            cnt[j] += (no&1);
            j++;
            no = (no>>1);
        }
    }

    //Take mod of cnt array with 3
    int p=1;
    int u_no=0;
    for(int j=0; j<64; j++){
        cnt[j] = cnt[j] % 3;
        u_no += cnt[j]*p;
        p = (p<<1);
    }
    return u_no;
}

int main(){
    int arr[] = {7,7,3,4,12,6,6,6,3,3,7,4,4,12,8,12};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<find_unique_no(arr, n);
    return 0;
}
