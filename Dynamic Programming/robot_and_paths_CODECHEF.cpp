#include<iostream>
#include<cstring>
using namespace std;

#define ll long long
#define MOD 1000000007

ll dp[1000][1000];

ll no_of_ways(ll m, ll n){
    //base case
    if(dp[0][0] == -1){
        return 0;
    }

    //compute the no of ways for first row
    for(int j=0; j<n; j++){
        if(dp[0][j] == -1)
            break;
        dp[0][j] = 1;
    }

    //compute the no of ways for first column
    for(int i=0; i<m; i++){
        if(dp[i][0] == -1)
            break;
        dp[i][0] = 1;
    }

    //bottom up approach for the rest of the matrix
    for(int r=1; r<m; r++){
        for(int c=1; c<n; c++){
            //if cell is blocked, leave it
            if(dp[r][c] == -1)
                continue;

            dp[r][c] = 0;

            if(dp[r][c-1] != -1){
                dp[r][c] = (dp[r][c] + dp[r][c-1])%MOD;
            }

            if(dp[r-1][c] != -1){
                dp[r][c] = (dp[r][c] + dp[r-1][c])%MOD;
            }

        }
    }

    //check for the final cell
    if(dp[m-1][n-1] == -1){
        return 0;
    }

    //print the dp table
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cout<<dp[i][j]<<"  ";
        }
        cout<<endl;
    }

    return dp[m-1][n-1];
}

int main(){
    memset(dp, 0, sizeof(dp));
    ll m, n, p;                 //nRows, nCols, nObstacles
    cin>>m>>n>>p;

    for(int i=0; i<p; i++){
        int X, Y;
        cin>>X>>Y;
        //mark all the blocked cells as -1
        dp[X-1][Y-1] = -1;
    }

    cout<<no_of_ways(m, n)<<endl;

    return 0;
}
