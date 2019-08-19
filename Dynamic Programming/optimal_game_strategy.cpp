//Memoization

#include<iostream>
using namespace std;

#define ll long long
ll coins[1000], n;
ll memo[1001][1001];

ll winner_score(ll i, ll j){
    if(i > j){
        return 0;
    }

    if(memo[i][j] != -1){
        return memo[i][j];
    }

}

int main(){
    //always even
    cin>>n;

    for(ll i=0; i<n; i++)
        cin>>arr[i];

    cout<<winner_score(0, n-1)<<endl;
    return 0;
}
