#include<iostream>
#include<map>
using namespace std;

#define ll long long
ll arr[100];
map<int, int> count;
ll dp[10000001];

ll find_max_score(ll maxm){
    dp[0] = 0;
//    dp[1] = max(dp[0], count[1]*1 + 0);         //dp[1-2] = 0 since it is not defined

    for(ll i=1; i<=maxm; i++){
        if(count[i]){
            if(i-2 >= 0)
                dp[i] = max(dp[i-1], count[i]*i + dp[i-2]);
            else
                dp[i] = max(dp[i-1], count[i]*i);               //since dp[1-2] = 0 bcz it is not defined
        }
        else
            dp[i] = 0;
    }
    return dp[maxm];
}

int main(){
    ll n;
    cin>>n;


    ll maxm = INT_MIN;
    for(ll i=0; i<n; i++){
        cin>>arr[i];
        maxm = max(maxm, arr[i]);
        count[arr[i]]++;
    }

    cout<<find_max_score(maxm)<<endl;

    return 0;
}
