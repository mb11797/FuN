#include<iostream>
using namespace std;

void prime_sieve(int *p, int n){
    p[0] = p[1] = 0;
    p[2] = 1;

    //Mark all odd nos as prime(initialization)
    for(int i=3; i<n; i+=2){
        p[i] = 1;
    }

    //sieve logic to mark non-prime nos as 0
    //1. Optimization: Iterate only over odd nos
    for(int i=3; i<n; i+=2){
        if(p[i]){
            //Mark all multiples of that no as not prime
            //2. Optimization: Take a jump of 2i (instead of i) starting from i*i
            for(int j=i*i; j<n; j+=2*i)
                p[j] = 0;
        }
    }
    return;
}

int main(){
    int n;
    cin>>n;

    int p[n] = {0};
    prime_sieve(p, n);

    for(int i=0; i<n; i++){
        if(p[i])
            cout<<i<<" ";
    }
    return 0;
}
