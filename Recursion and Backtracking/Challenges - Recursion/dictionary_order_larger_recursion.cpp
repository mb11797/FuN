#include <iostream>
#include<cstring>
#include<algorithm>
using namespace std;
string output[1000000];
int x=0;
bool myCompare(string a,string b){
    return a<b;
}
bool check(string output[],int x,char a[]){
    for(int i=0;i<x;i++){
        if(output[i]==a){
            return false;
        }
    }
    return true;
}

void sub(string s, char a[],int n,int i=0){
    if(i==n){
        //cout<<a<<endl;
//        if(check(output,x,a)){
//            output[x]=a;
//            x++;
//        }
        if(a<s)
            cout<<a<<endl;
        return;
    }
    for(int j=i;j<=n;j++){
        swap(a[i],a[j]);
        sub(s, a, n, i+1);
        swap(a[i],a[j]);
    }
}

int main() {
    char a[1000];
    cin>>a;
    string s = a;
    //cout<<a<<endl;
    sub(s, a,strlen(a)-1);
    return 0;
}
