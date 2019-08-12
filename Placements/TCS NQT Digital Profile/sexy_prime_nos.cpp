#include<iostream>
using namespace std;
#define ll long long

ll prime[100000]={};

void prime_seive_banao(){
    for(ll i=3; i<100000; i+=2){
        prime[i] = 1;
    }

    prime[2]=1;

    for(ll i=3; i<100000; i+=2){
        if(prime[i]){
            for(ll j=i*i; j<100000; j+=2*i){
                prime[j]=0;
            }
        }
    }
    return;
}

ll sexy_nos(ll m, ll n){
    int count=0;

}


int main(){
    prime_seive_banao();
    for(ll i=0; i<1000; i++)
        cout<<prime[i]<<"\t";

    return 0;
}
