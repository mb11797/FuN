#include<iostream>
using namespace std;

#define ll long long

int main(){
    ll a, b, c;
    cin>>a>>b>>c;

    int ans = 1;
    for(ll i=0; i<b; i++){
        ans = ans*a % c;
    }
    ans = ans % c;

    cout<<ans<<endl;
    return 0;
}
