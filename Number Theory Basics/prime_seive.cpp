#include<iostream>
using namespace std;

int*primes(int*p){
    for(int i=2; i<10000; i++){
        p[i] = 1;
    }
    for(int i=2; i<10000; i++){
        if(p[i]){
            for(int j=2*i; j<10000; j+=i){
                p[j] = 0;
            }
        }
    }
    p[0] = 0;
    p[1] = 0;
    return p;
}

int main(){
    int n;
    cin>>n;

    int p[10000];
    int *p_seive = primes(p);
    int cnt=0;
    for(int i=0; i<n; i++)
        if(p_seive[i]){
            cout<<i<<" ";
            cnt++;
        }
    cout<<endl<<"Count = "<<cnt<<endl;
    return 0;
}
