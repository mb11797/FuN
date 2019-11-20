#include<iostream>
#include<cstring>
using namespace std;

#define ll long long
ll wines[100];
ll memo[101][101];

ll max_profit(ll be, ll en, ll yr){
    if(be > en){
        return 0;
    }
    if(be == en){
        return wines[be]*yr;
    }

    //overlapping subproblems case
    if(memo[be][en] != -1){
        return memo[be][en];
    }

    memo[be][en] = max(wines[be]*yr + max_profit(be+1, en, yr+1), wines[en]*yr + max_profit(be, en-1, yr+1));
    return memo[be][en];
}


int main(){
    memset(memo, -1, sizeof(memo));
    ll n;
    cin>>n;

    for(ll i=0; i<n; i++){
        cin>>wines[i];
    }

    cout<<max_profit(0, n-1, 1)<<endl;

    return 0;
}
