#include<iostream>
using namespace std;

void sum_2_arrays(int*a1, int n, int*a2, int m, int*sum){
    int carry = 0;
    int i, j, k;
    for(i=n-1, j=m-1, k=0; i>=0 || j>=0; i--, j--, k++){
        int dig_sum;
        if(i<0 && j>=0)
            dig_sum = a2[j] + carry;
        else if(j<0 && i>=0)
            dig_sum = a1[i] + carry;
        else
            dig_sum = a1[i] + a2[j] + carry;

        sum[k] = dig_sum%10;
        carry = dig_sum/10;
    }
    sum[k] = -1;
}

void print_reverse_arr(int arr[]){
    if(arr[0] == -1)
        return;
    print_reverse_arr(arr+1);
    cout<<arr[0]<<", ";
}

int main(){
    int n;
    cin>>n;
    int a1[n];
    for(int i=0; i<n; i++)
        cin>>a1[i];

    int m;
    cin>>m;
    int a2[m];
    for(int i=0; i<m; i++)
        cin>>a2[i];

    int sum[n+m];
    sum_2_arrays(a1, n, a2, m, sum);

    print_reverse_arr(sum);
    cout<<"END";
    return 0;
}
