#include<iostream>
#include<cstring>
using namespace std;

int memo[1001];

int ways_in_which_n_friends_can_go_to_party(int n){
    if(n==0 || n==1)
        return 1;

    //if this value is already calculated
    //overlapping subproblems case
    if(memo[n] != -1){
        return memo[n];
    }

    memo[n] = ways_in_which_n_friends_can_go_to_party(n-1) + (n-1) * ways_in_which_n_friends_can_go_to_party(n-2);
    return memo[n];
}

int main(){
    int n;
    cin>>n;

    memset(memo, -1, sizeof(memo));

    cout<<ways_in_which_n_friends_can_go_to_party(n)<<endl;
    return 0;
}
