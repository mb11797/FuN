#include<iostream>
using namespace std;

#define ll long long

int main(){
    ll tc;
    cin>>tc;

    while(tc--){
        ll n, k;
        cin>>n>>k;

        //1st candidate will always have uniform distribution in each box
        //we need to check only for second as follows:
        if((n/k)%k==0)
            cout<<"NO"<<endl;
        else
            cout<<"YES"<<endl;

    }
    return 0;
}
