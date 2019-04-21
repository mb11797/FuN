#include<iostream>
using namespace std;

//slow -> O(no of bits)
int countBits(int n){
    int count = 0;
    while(n>0){
        count+=(n&1);
        n = n>>1;
    }
    return count;
}

//fast -> O(no of setbits)
int countBitsFast(int n){
    int count=0;
    while(n){
        n = n & (n-1);
        count++;
    }
    return count;
}

int main(){
    int n;
    cin>>n;
    cout<<countBits(n)<<endl;
    cout<<countBitsFast(n)<<endl;
    return 0;
}
