#include<iostream>
using namespace std;

int factorial(int n){
    int fact = 1;
    for(int i=1; i<=n; i++)
        fact *= i;
    return fact;
}

int nCr(int n, int r){
    return factorial(n)/(factorial(r)*factorial(n-r));
}

int main(){

    cout<<factorial(6)<<endl;
    cout<<nCr(5, 3)<<endl;
    return 0;
}
