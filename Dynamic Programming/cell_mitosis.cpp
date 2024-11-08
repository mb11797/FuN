#include<iostream>
using namespace std;

//x - doubling_cost
//y - increment_cost
//z - decrement_cost

long long solve_cell_mitosis(int n, int x, int y, int z){
    long long *dp = new long long[n+1];

    //Bottom Up DP
    dp[0] = 0;
    dp[1] = 0;

    for(int i=2; i<=n; i++){

        if(i%2 == 0){
            dp[i] = min(dp[i/2] + x, dp[i-1] + y);
        }
        else{
            dp[i] = min(dp[i-1] + y, dp[(i+1)/2] + x + z);
        }
    }

    return dp[n];
}


int main(){
    int n, x, y, z;

    cin>>x>>y>>z;
    cin>>n;

    cout<<solve_cell_mitosis(n, x, y, z)<<endl;

    return 0;
}
