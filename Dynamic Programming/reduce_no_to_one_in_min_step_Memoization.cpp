#include<iostream>
#include<algorithm>
using namespace std;
const int inf = (int) 1e9;

int memo[100000];

int reduce_no(int n){
    if(n==1)
        return 0;

    if(memo[n] != -1)
        return memo[n];                         //because this has already been computed. No need for recomputation!

    int q1 = inf, q2 = inf, q3 = inf;

    if(n%3 == 0)
        q1 = 1 + reduce_no(n/3);
    if(n%2 == 0)
        q2 = 1 + reduce_no(n/2);
    q3 = 1 + reduce_no(n-1);

    memo[n] = min(q1, min(q2, q3));             //MEMOIZE - has to be done
    return memo[n];
}


int main(){
    int n;
    cin>>n;

    fill(memo, memo + n + 1, -1);               //or use for loop to initialize or fill memo[] with -1

    cout<<"Min steps: "<<reduce_no(n)<<endl;
    return 0;
}
