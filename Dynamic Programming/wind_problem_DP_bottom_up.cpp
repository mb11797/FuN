#include<iostream>
#include<cstring>
using namespace std;
int memo[100][100];
int cnt1 = 0;
int cnt2 = 0;


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

int max_profit_BottomUp(int*bottle_prices, int n){
    int dp[100][100] = {};

    int year = n;

    for(int i=0; i<n; i++)
        dp[i][i] = bottle_prices[i]*year;

    year--;

    for(int len=2; len<=n; len++){
        int strt = 0;
        int end = n-len;

        while(strt<=end){
            int endWindow = strt+len-1;
            dp[strt][endWindow] = max(bottle_prices[strt]*year + dp[strt+1][endWindow], bottle_prices[endWindow]*year + dp[strt][endWindow-1]);
            strt++;
        }
        year--;
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
            cout<<dp[i][j]<<"\t";
        cout<<endl;
    }

    return dp[0][n-1];
}

int main(){
    int n;
    cin>>n;

    int bottle_prices[n];

    memset(memo, -1, sizeof(memo));

    for(int i=0; i<n; i++)
        cin>>bottle_prices[i];

    cout<<max_profit_BottomUp(bottle_prices, n)<<endl;

    return 0;
}
