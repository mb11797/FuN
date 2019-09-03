#include<iostream>
#include<cstring>
using namespace std;

int memo[1000];

int fib(int n){
    if(n==0 || n==1){
        return n;
    }

    if(memo[n] != -1)
        return memo[n];

    int ans = fib(n-1) + fib(n-2);

    return memo[n] = ans;
}

int main(){
    memset(memo, -1, sizeof(memo));
    int n;
    cin>>n;

    cout<<fib(n)<<endl;
    return 0;
}
