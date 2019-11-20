#include<iostream>
using namespace std;

int dp[1001][1001];             //(n_eggs, n_floors)

int min_trials_in_worst_case(int nf, int ne){
    //dp[ne+1][nf+1]

    //0 eggs and 1 egg case
    for(int i=0; i<nf; i++){
        dp[0][i] = 0;
        dp[1][i] = i;               //we always need i trials for 1 egg and i floors
    }

    //0 floor and 1 floor case
    for(int i=1; i<ne; i++){
        dp[i][0] = 0;
        dp[i][1] = 1;
    }

    int res;
    //fill rest of the entries using optimal substructure
    for(int i=2; i<=ne; i++){
        for(int j=2; j<=nf; j++){
            dp[i][j] = INT_MAX;
            for(int x=1; x<=j; x++){
                dp[i][j] = min(dp[i][j], 1 + max(dp[i-1][x-1], dp[i][j-x]));              //max(if egg breaks, if egg does not break)
            }
        }
    }
    return dp[ne][nf];
}


int main(){
    int nf, ne;
    cin>>nf>>ne;

    cout<<min_trials_in_worst_case(nf, ne)<<endl;

    return 0;
}
