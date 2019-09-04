#include<iostream>
using namespace std;

int doubling_cost, inc_cost, dec_cost;
int dp[10000];


int min_steps_to_make_n_cells_from_1_cell(int n){
    dp[0] = 0;
    dp[1] = 0;

    for(int i=2; i<=n; i++){
        if(i%2 == 0){
            dp[i] = min(dp[i/2] + doubling_cost, dp[i-1] + inc_cost);
        }
        else{
            dp[i] = min(dp[(i+1)/2] + doubling_cost + dec_cost, dp[i-1] + inc_cost);
        }

    }
    return dp[n];
}


int main(){
    cin>>doubling_cost>>inc_cost>>dec_cost;

    int n;
    cin>>n;

    cout<<min_steps_to_make_n_cells_from_1_cell(n)<<endl;

    return 0;
}
