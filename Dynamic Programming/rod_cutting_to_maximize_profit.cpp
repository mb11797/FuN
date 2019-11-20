#include<iostream>
using namespace std;

int max_profit(int price_of_each_len[100], int total_len){
    if(total_len==0)
        return 0;

    int best=0;
    for(int len=1; len<=total_len; len++){
        int net_profit = price_of_each_len[len] + max_profit(price_of_each_len, total_len-len);
        best = max(best, net_profit);
    }
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
