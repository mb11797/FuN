#include<iostream>
#include<math.h>
using namespace std;

#define ll long long

int main(){
    ll a, b, c;
    cin>>a>>b>>c;

    ll ans = pow(a, b);
    ans %= c;
    cout<<ans<<endl;

    return 0;
}
