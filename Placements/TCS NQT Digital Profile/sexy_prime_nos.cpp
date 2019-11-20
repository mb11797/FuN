#include<iostream>
using namespace std;
#define ll long long

ll prime[100000000]={};

void prime_seive_banao(){
    for(ll i=3; i<100000000; i+=2){
        prime[i] = 1;
    }

    prime[2]=1;

    for(ll i=3; i<100000000; i+=2){
        if(prime[i]){
            for(ll j=i*i; j<100000000; j+=2*i){
                prime[j]=0;
            }
        }
    }
    return;
}

ll sexy_prime_nos(ll m, ll n){
    int count=0;

    for(int s=m; s<=n-6; s++){
        if(prime[s]==1 && prime[s+6]==1){
//            cout<<s<<" "<<s+6<<" "<<count<<endl;
            count++;
        }
    }
    return count;
}


int main(){
    prime_seive_banao();
//    for(ll i=0; i<1000000; i++)
//        cout<<prime[i]<<"\t";

//    cout<<endl;

    ll m, n;
    cin>>m>>n;

    cout<<sexy_prime_nos(m, n)<<endl;

    return 0;
}
