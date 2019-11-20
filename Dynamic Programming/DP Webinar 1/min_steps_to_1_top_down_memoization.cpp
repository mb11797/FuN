#include<iostream>
#include<cstring>
using namespace std;

int memo[1000];

int min_steps_to_1(int n){
    if(n==1)
        return 0;

    if(memo[n] != -1)
        return memo[n];

    memo[n] = 1 + min_steps_to_1(n-1);

    //if n is a multiple of 2
    if(n%2 == 0){
        memo[n] = min(memo[n], 1 + min_steps_to_1(n/2));
    }
    if(n%3 == 0){
        memo[n] = min(memo[n], 1 + min_steps_to_1(n/3));
    }
    return memo[n];
}

int main(){
    int n;
    cin>>n;

    memset(memo, -1, sizeof(memo));

    cout<<min_steps_to_1(n)<<endl;

    return 0;
}
