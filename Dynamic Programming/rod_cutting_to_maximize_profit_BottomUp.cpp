#include<iostream>
#include<algorithm>
using namespace std;

int max_profit(int price_of_each_len[100], int total_len){
    int dp[100] = {};


    for(int len=1; len<=total_len; len++){
        int best=0;
        for(int cut=1; cut<=len; cut++){
            best = max(best, price_of_each_len[cut] + dp[len-cut]);
        }
        dp[len] = best;
    }
    return dp[total_len];
}

int main(){
    int price_of_each_len[100];
    int total_len;
    cin>>total_len;

    for(int piece=1; piece<=total_len; piece++)
        cin>>price_of_each_len[piece];

    cout<<max_profit(price_of_each_len, total_len);

    return 0;
}
