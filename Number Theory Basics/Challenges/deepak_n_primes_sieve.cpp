#include<iostream>
using namespace std;

#define ll long long

void prime_sieve(ll p[], ll n){
    p[0] = p[1] = 0;
    p[2] = 1;

    for(ll i=3; i<5000; i+=2){
        p[i] = 1;
    }

    for(ll i=3; i<5000; i++){
        if(p[i]){
            for(ll j=i*i; j<5000; j+=2*i){
                p[j] = 0;
            }
        }
    }

    ll prime_arr[n];
    prime_arr[0] = 2;
    int j=1;
    for(ll i=3; i<5000; i+=2){
        if(p[i]){
            prime_arr[j] = i;
            j++;
        }
    }
    cout<<prime_arr[n-1]<<endl;
}

int main(){
    ll n;
    cin>>n;

    ll p[5000] = {0};

    prime_sieve(p, n);
    return 0;
}
