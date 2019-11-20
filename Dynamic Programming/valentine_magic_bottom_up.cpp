#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

#define ll long long

/*
Sample Input:
2 5
4 5
1 2 3 4 5
*/

ll n_boys, n_girls, boys[5005], girls[5005];
ll memo[5005][5005];

ll make_best_possible_pairs(ll i, ll j){
    //base case
    if(i == n_boys){
        //we have paired all the boys
        return 0;
    }

    if(j == n_girls){
        //we have rejected lots of girls, and no girl is available for the boys now - unexpected case
        return INT_MAX;
    }

    if(memo[i][j] != -1){
        return memo[i][j];
    }

    ll op1 = abs(boys[i]-girls[j]) + make_best_possible_pairs(i+1, j+1);               //by accepting the jth girl
    ll op2 = make_best_possible_pairs(i, j+1);                                         //by rejecting the jth girl

    return memo[i][j] = min(op1, op2);
}


int main(){
    memset(memo, -1, sizeof(memo));
    cin>>n_boys>>n_girls;

    //chocolates (boys)
    for(ll i=0; i<n_boys; i++)
        cin>>boys[i];

    //candies (girls)
    for(ll i=0; i<n_girls; i++)
        cin>>girls[i];


    sort(boys, boys+n_boys);
    sort(girls, girls+n_girls);

    //top-down DP - Memoization
    cout<<make_best_possible_pairs(0, 0)<<endl;

    return 0;
}
