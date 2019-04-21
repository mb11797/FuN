#include<iostream>
using namespace std;

#define ll long long

void prime_sieve(int p[], ll n){
    p[0] = p[1] = 0;
    p[2] = 1;

    for(ll i=3; i<100000; i+=2){
        p[i] = 1;
    }

    for(ll i=3; i<100000; i++){
        if(p[i]){
            for(ll j=i*i; j<100000; j+=2*i){
                p[j] = 0;
            }
        }
    }
}

int main(){
    ll n;
    cin>>n;

    int p[100000] = {0};

    prime_sieve(p, n);

    ll j=0;
//    for(int i=0; i<5000; i++)
//        if(p[i]){
//            j++;
//            cout<<i<<" ";
//            if(j==n){
//                break;
//            }
//        }
//
//    cout<<endl<<endl;
//
//    j=0;
    for(ll i=0; i<100000; i++)
        if(p[i]){
            j++;
            if(j==n){
                cout<<i<<endl;
                break;
            }
        }

    return 0;
}
