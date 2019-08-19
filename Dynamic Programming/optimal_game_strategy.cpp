//Memoization

#include<iostream>
#include<cstring>
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

    int beg_choice = coins[i] + min(winner_score(i+2, j), winner_score(i+1, j-1));
    int end_choice = coins[j] + min(winner_score(i, j-2), winner_score(i+1, j-1));

    memo[i][j] = max(beg_choice, end_choice);

    return memo[i][j];
}

int main(){
    //always even
    cin>>n;

    memset(memo, -1, sizeof(memo));

    for(ll i=0; i<n; i++)
        cin>>coins[i];

    cout<<winner_score(0, n-1)<<endl;
    return 0;
}
