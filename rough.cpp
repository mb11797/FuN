#include <bits/stdc++.h>
using namespace std;
map<string,int>m;
map<string,int>:: iterator it;

void Ans(int a[],int be,int en,int out[],int j,int k){
    if(be>en){
        int ts=0;
        string s="";

        for(int i=0;i<j;i++){
            ts+=out[i];
            s+=(char(out[i])-48);
        }
//        if(out[0]==7 && out[1]==1)
//            cout<<"7 1 : "<<s<<endl<<endl;
//        if(out[0]==1 && out[1]==7)
//            cout<<"1 7 : "<<s<<endl<<endl;

        if(ts==k && m.find(s)==m.end()){
            for(int i=0;i<j;i++){
                cout<<out[i]<<" ";
            }
            m[s]++;
            cout<<endl;
        }
        return;
    }
    out[j]=a[be];
    Ans(a,be+1,en,out,j+1,k);
    Ans(a,be+1,en,out,j,k);
}
int main() {
    int n,a[100],out[100],k;cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);
    cin>>k;
    Ans(a,0,n-1,out,0,k);
    return 0;
}
