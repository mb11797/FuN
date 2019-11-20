#include<iostream>
using namespace std;

int max_profit(int*bottle_prices, int beg, int endd, int year){
    if(beg > endd)
        return 0;

    int ans1 = bottle_prices[beg]*year + max_profit(bottle_prices, beg+1, endd, year+1);
    int ans2 = bottle_prices[endd]*year + max_profit(bottle_prices, beg, endd-1, year+1);

    return max(ans1, ans2);
}


int main(){
    int n;
    cin>>n;

    int bottle_prices[n];             //no of bottles kept on table
    for(int i=0; i<n; i++)
        cin>>bottle_prices[i];        //prices of bottles

    cout<<max_profit(bottle_prices, 0, n-1, 1)<<endl;

    return 0;
}
