#include<iostream>
using namespace std;

#define ll long long

void sum_2_arrays(ll*a1, ll n, ll*a2, ll m, ll*sum){
    ll carry = 0;
    ll i, j, k;
    for(i=n-1, j=m-1, k=0; i>=0 || j>=0; i--, j--, k++){
        ll dig_sum;
        if(i<0 && j>=0)
            dig_sum = a2[j] + carry;
        else if(j<0 && i>=0)
            dig_sum = a1[i] + carry;
        else
            dig_sum = a1[i] + a2[j] + carry;

        sum[k] = dig_sum%10;
        carry = dig_sum/10;
    }
    if(carry != 0)
        sum[k++] = carry;
    sum[k] = -1;
}

void print_reverse_arr(ll arr[]){
    if(arr[0] == -1)
        return;
    print_reverse_arr(arr+1);
    cout<<arr[0]<<", ";
}

int main(){
    ll n;
    cin>>n;
    ll a1[n];
    for(ll i=0; i<n; i++)
        cin>>a1[i];

    ll m;
    cin>>m;
    ll a2[m];
    for(ll i=0; i<m; i++)
        cin>>a2[i];

    ll sum[100000];
    sum_2_arrays(a1, n, a2, m, sum);

    print_reverse_arr(sum);
    cout<<"END";
    return 0;
}
