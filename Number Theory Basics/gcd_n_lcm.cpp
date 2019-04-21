#include<iostream>
using namespace std;

int gcd(int a, int b){
    //base case
    if(b==0)
        return a;
    //if(a==0)
    //    return b;

    //recursive case
    return gcd(b, a%b);
}

int lcm(int a, int b){
    return (a*b)/gcd(a, b);
}

int main(){
    cout<<gcd(10, 14)<<endl;
    cout<<gcd(14, 10)<<endl;
    cout<<gcd(0, 10)<<endl;
    cout<<gcd(15, 5)<<endl;

    cout<<endl;

    cout<<lcm(14, 10)<<endl;
    cout<<lcm(11, 9)<<endl;
    cout<<lcm(17, 15)<<endl;

    return 0;
}
