#include<iostream>
using namespace std;

void primes(bool*p, int n){
    p[0] = p[1] = 0;
    p[2] = 1;

    for(int i=3; i<n; i+=2)
        p[i] = 1;

    for(int i=3; i<n; i+=2){
        if(p[i]){
            for(int j=i*i; j<n; j+=i){
                p[j] = 0;
            }
        }
    }
    return;
}

int main(){
    int n;
    cin>>n;
    bool p[n]={0};
    primes(p, n);
    for(int i=0; i<n; i++){
        if(p[i])
            cout<<i<<" ";
    }
    return 0;
}
