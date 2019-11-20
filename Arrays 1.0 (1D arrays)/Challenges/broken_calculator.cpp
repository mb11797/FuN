#include<iostream>
using namespace std;

#define ll long long

void fact(ll n){
    ll arr[5000];
    arr[0] = 1;

    ll temp;
    ll j=0;
    for(; n>=2; n--){

        temp = 0;
        for(ll i=0; i<=j; i++){
            temp = arr[i] * n + temp;
            arr[i] = temp%10;
            temp /= 10;
        }
        while(temp>0){
            ++j;
            arr[j] = temp%10;
            temp /= 10;
        }
    }
    int count = 0;
    for(ll i=j; i>=0; i--){
        cout<<arr[i];
        count++;
    }
    cout<<endl<<count<<endl;
}

int main(){
    ll n;
    cin>>n;

    fact(n);
    return 0;
}

