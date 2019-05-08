#include<iostream>
using namespace std;

#define ll long long

void primeSeive(ll*prime_seive){
    prime_seive[0] = prime_seive[1] = 0;
    prime_seive[2] = 1;
    for(ll i=3; i<=100000; i+=2){
        prime_seive[i] = 1;
    }
    for(ll i=3; i<=100000; i+=2){
        if(prime_seive[i]){
            for(ll j=i*i; j<=100000; j+=2*i){
                prime_seive[j] = 0;
            }
        }
    }
    return;
}
//
//ll count_prime_visits(ll a, ll b){
//    ll prime_seive[10000] = {0};
//    primeSeive(prime_seive, 10000);
//    ll count = 0;
////    for(ll i=0; i<=20; i++){
////        cout<<prime_seive[i]<<" ";
////    }
////    cout<<endl;
//    for(ll i=a; i<=b; i++){
//        if(prime_seive[i]){
//            count++;
//        }
//    }
//    return count;
//}


int main(){
    int tc;
    cin>>tc;

    ll prime_seive[100000] = {0};
    primeSeive(prime_seive);

    int a, b;

    while(tc--){
        cin>>a>>b;
//        cout<<count_prime_visits(a, b)<<endl;
        ll count = 0;
    //    for(ll i=0; i<=20; i++){
    //        cout<<prime_seive[i]<<" ";
    //    }
    //    cout<<endl;
        for(ll i=a; i<=b; i++){
            if(prime_seive[i]){
                count++;
            }
        }
        cout<<count<<endl;
    }



    return 0;
}
