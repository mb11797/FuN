#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int cnt1 = 0;
int cnt2 = 0;
int memo[100][100];

int max_profit(int*bottle_prices, int be, int en, int year){
    cnt1++;
    if(be>en)
        return 0;

    int ans1 = bottle_prices[be]*year + max_profit(bottle_prices, be+1, en, year+1);
    int ans2 = bottle_prices[en]*year + max_profit(bottle_prices, be, en-1, year+1);

    return max(ans1, ans2);
}

int max_profit_memoization(int*bottle_prices, int be, int en, int year){
    cnt2++;
    if(be>en)
        return 0;

    if(memo[be][en] != -1)
        return memo[be][en];

    int ans1 = bottle_prices[be]*year + max_profit_memoization(bottle_prices, be+1, en, year+1);
    int ans2 = bottle_prices[en]*year + max_profit_memoization(bottle_prices, be, en-1, year+1);

    memo[be][en] = max(ans1, ans2);

    return memo[be][en];
}

int main(){
    int n;
    cin>>n;

    int bottle_prices[n];
    for(int i=0; i<n; i++)
        cin>>bottle_prices[i];


//    for(int i=0; i<n; i++)
//        for(int j=0; j<n; j++)
//            memo[i][j] = -1;

    memset(memo, -1, sizeof(memo));

    cout<<max_profit(bottle_prices, 0, n-1, 1)<<endl;
    cout<<"Calls: "<<cnt1<<endl;
    cout<<max_profit_memoization(bottle_prices, 0, n-1, 1)<<endl;
    cout<<"Calls: "<<cnt2<<endl;

    return 0;
}
