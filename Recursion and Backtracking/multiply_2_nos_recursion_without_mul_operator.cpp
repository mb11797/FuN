#include<iostream>
using namespace std;

int multiply_recursive(int a, int b){
    //0 multiplied with anything gives 0
    if(b==0)
        return 0;

    //add a one by one
    if(b>0)
        return a + multiply_recursive(a, b-1);

    //the case where b is negative
    if(b<0)
        return -multiply_recursive(a, -b);
}

int main(){
    int a, b;
    cin>>a>>b;

    cout<<multiply_recursive(a, b)<<endl;

    return 0;
}
