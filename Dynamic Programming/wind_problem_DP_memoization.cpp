#include<iostream>
#include<algorithm>
using namespace std;
int cnt = 0;
int memo[1000];

int max_profit(int*bottle_prices, int be, int en, int year){
    if(be>en)
        return 0;

    if(memo[be][en] != -1)
        return memo[be][en];

    return 0;
}

int main(){
    int n;
    cin>>n;

    int bottle_prices[n];
    for(int i=0; i<n; i++)
        cin>>bottle_prices[i];

    fill(memo, memo+n, -1);

    cout<<max_profit(bottle_prices, 0, n-1, 1)<<endl;
    cout<<cnt<<endl;

    return 0;
}
