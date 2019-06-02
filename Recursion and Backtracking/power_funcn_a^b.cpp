#include<iostream>
using namespace std;

int power(int a, int b){
    if(b==0)
        return 1;
    return a*power(a, b-1);
}

int fast_power(int a, int b){
    if(b==0)
        return 1;

    int smallAns = fast_power(a, b/2);
    smallAns *= smallAns;

    if(b&1)
        return a*smallAns;
    return smallAns;
}

int main(){
    int a, b;
    cin>>a>>b;

    cout<<power(a, b)<<endl;

    cout<<fast_power(a, b)<<endl;
    return 0;
}
