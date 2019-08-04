#include<iostream>
using namespace std;
int memo[100];


int max_profit(int price_of_each_len[100], int total_len){
    if(total_len==0)
        return 0;

    if(memo[total_len] != -1)
        return memo[total_len];

    int best=0;
    for(int len=1; len<=total_len; len++){
        int net_profit = price_of_each_len[len] + max_profit(price_of_each_len, total_len-len);
        best = max(best, net_profit);
    }
    memo[total_len] = best;
    return best;
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
