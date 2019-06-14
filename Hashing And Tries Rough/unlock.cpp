#include <iostream>
using namespace std;
int find(int *a,int n,int j){
    int max=0,index=-1;

    for(int i=j; i<n;i++){
        if(a[i]>max){
        max=a[i];
        index=i;
        }
    }
    //cout<<"ai "<<a[j]<<" aindex "<<a[index]<<endl;
    if(a[j]==a[index] && j!=n-1){
      return find(a,n,j+1);

     }
    swap(a[j],a[index]);
   // cout<<"aj"<<a[j];
    return j+1;
}
int main() {
    int n,k,j=0;
    cin>>n>>k;
    int a[1000000];
    for(int i=0;i<n;i++)cin>>a[i];
    while(k--){
        j=find(a,n,j);
    }
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
}
