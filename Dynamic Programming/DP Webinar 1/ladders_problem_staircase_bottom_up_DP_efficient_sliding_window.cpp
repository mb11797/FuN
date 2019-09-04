#include<iostream>
using namespace std;

int dp[1000];

int f(int n, int k){
    dp[0] = 1;
    dp[1] = 1;

    for(int i=2; i<=n; i++){
        dp[i] = 2*dp[i-1] - dp[i-(k+1)];
    }

}

int main(){
    int n, k;
    cin>>n>>k;


    cout<<f(n, k)<<endl;
    return 0;
}
