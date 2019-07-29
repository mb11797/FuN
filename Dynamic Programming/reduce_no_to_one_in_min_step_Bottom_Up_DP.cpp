#include<iostream>
#include<algorithm>
using namespace std;
const int inf = (int) 1e9;

int memo[100000];

int reduce_no_Memoization(int n){
    if(n==1)
        return 0;

    if(memo[n] != -1)
        return memo[n];                         //because this has already been computed. No need for recomputation!

    int q1 = inf, q2 = inf, q3 = inf;

    if(n%3 == 0)
        q1 = 1 + reduce_no_Memoization(n/3);
    if(n%2 == 0)
        q2 = 1 + reduce_no_Memoization(n/2);
    q3 = 1 + reduce_no_Memoization(n-1);

    memo[n] = min(q1, min(q2, q3));             //MEMOIZE - has to be done
    return memo[n];
}

int reduce_no_Bottom_Up_DP(int n){
    int dp[10000];

    //setting the base cases
    dp[0] = 0;      dp[1] = 0;
    dp[2] = 1;      dp[3] = 1;

    //compute the ans for n
    for(int cur_num=4; cur_num<=n; cur_num++){
        int q1 = inf;
        int q2 = inf;
        int q3 = inf;

        if(cur_num%3 == 0)      q1 = 1 + dp[cur_num/3];
        if(cur_num%2 == 0)      q2 = 1 + dp[cur_num/2];
        q3 = 1 + dp[cur_num-1];

        dp[cur_num] = min(q1, min(q2, q3));
    }

    return dp[n];
}


int main(){
    int n;
    cin>>n;

    fill(memo, memo + n + 1, -1);               //or use for loop to initialize or fill memo[] with -1

    cout<<"Min steps: "<<reduce_no_Memoization(n)<<endl;
    cout<<"Min steps: "<<reduce_no_Bottom_Up_DP(n)<<endl;

    return 0;
}

