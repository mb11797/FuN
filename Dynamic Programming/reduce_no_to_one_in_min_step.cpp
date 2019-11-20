#include<iostream>
using namespace std;
const int inf = (int) 1e9;

int reduce_no(int n){
    if(n==1)
        return 0;

    int q1=inf, q2=inf, q3=inf;

    if(n%3 == 0)    q1 = 1 + reduce_no(n/3);
    if(n%2 == 0)    q2 = 1 + reduce_no(n/2);
    q3 = 1 + reduce_no(n-1);
    return min(q1, min(q2, q3));
}

int main(){
    int n;
    cin>>n;

    int ans = reduce_no(n);
    cout<<"Min no of steps: "<<ans<<endl;
    return 0;
}
