#include<bits/stdc++.h>
using namespace std;

//    string X = "AGGT12";
//    string Y = "12TXAYB";
//    string Z = "12XBA";

int dp[100][100][100];

int lcsOf3(string X, int i, string Y, int j, string Z, int k)
{
    if(i==-1||j==-1||k==-1)
        return 0;
    if(dp[i][j][k]!=-1)
        return dp[i][j][k];

    if(X[i]==Y[j] && Y[j]==Z[k])
        return dp[i][j][k] = 1+lcsOf3(X, i-1, Y, j-1, Z, k-1);
    else
        return dp[i][j][k] = max(max(lcsOf3(X, i-1, Y, j, Z, k),
                            lcsOf3(X, i, Y, j-1, Z, k)),lcsOf3(X, i, Y, j, Z, k-1));
}

// Driver code
int main()
{
    string X, Y, Z;
    cin>>X>>Y>>Z;
    memset(dp, -1,sizeof(dp));
    int m = X.length();
    int n = Y.length();
    int o = Z.length();

    cout <<lcsOf3(X, m-1, Y, n-1, Z, o-1)<<endl;

    return 0;
}
