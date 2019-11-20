//given an integer say n,
//print all nos from 1 to n in
//-increasing order
//-decreasing order

#include<iostream>
using namespace std;

void print_inc(int n){
    if(n==0)
        return;

    print_inc(n-1);
    cout<<n<<" ";
    return;
}

void print_dec(int n){
    if(n==0)
        return;

    cout<<n<<" ";
    print_dec(n-1);
    return;
}


int main(){
    int n;
    cin>>n;

    print_inc(n);
    cout<<endl;
    print_dec(n);
    cout<<endl;

    return 0;
}
