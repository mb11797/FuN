//for 10^18 length nos

#include<iostream>
#include<map>
using namespace std;
#define ll long long
map<int, int> F;

ll f(ll n){
    if(F.count(n)){
        return F[n];
    }

    ll k = n/2;
    if(n%2==0){
        return F[n] = f(k)*f(k) + f(k-1)*f(k-1);
    }
    else{
        return F[n] = f(k)*f(k+1) + f(k-1)*f(k);
    }
}

int main(){
    F[0] = F[1] = 1;
    ll n;
    cin>>n;

    cout<<((n==0) ? 0 : f(n-1))<<endl;
    return 0;
}
