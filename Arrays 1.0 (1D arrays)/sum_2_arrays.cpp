#include<iostream>
using namespace std;

int*sum_arr(int n, int*arr1, int m, int*arr2){
    if(n>m){
        int*sum = new int[n];
        int carry=0;
        int i=n-1, j=m-1;
        while(i>=0){
            if(j>=0){
                sum[i] = arr1[i] + arr2[j] + carry;
                carry=0;
                if(sum[i]>=10){
                    carry = sum[i] / 10;
                    sum[i] = sum[i] % 10;
                }
                i--;
                j--;
            }
            if(j<0){
                sum[i] = arr1[i] + carry;
                carry=0;
                if(sum[i]>=10){
                    carry = sum[i] / 10;
                    sum[i] = sum[i] % 10;
                }
                i--;
            }
        }
        return sum;
    }
    else{
        int*sum = new int[m];
        int carry=0;
        int i=n-1, j=m-1;
        while(j>=0){
            if(i>=0){
                sum[j] = arr1[i] + arr2[j] + carry;
                carry=0;
                if(sum[j]>=10){
                    carry = sum[j] / 10;
                    sum[j] = sum[j] % 10;
                }
                i--;
                j--;
            }
            if(i<0){
                sum[j] = arr2[j] + carry;
                carry=0;
                if(sum[j]>=10){
                    carry = sum[j] / 10;
                    sum[j] = sum[j] % 10;
                }
                j--;
            }
        }
        return sum;
    }
}

int main(){
    int n;
    cin>>n;
    int arr1[n];
    for(int i=0; i<n; i++){
        cin>>arr1[i];
    }

    int m;
    cin>>m;
    int arr2[m];
    for(int i=0; i<m; i++){
        cin>>arr2[i];
    }

    int*arr = sum_arr(n, arr1, m, arr2);

    for(int i=0; i<max(n,m); i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}
