#include<bits/stdc++.h>
using namespace std;
int binarystrings(char *arr,int n,int i)
{
    if(i==n){
        arr[i]= '\0' ;
        return 1;
    }
    if(arr[0]== '\0'){
        arr[0]='0';
        int ans=binarystrings(arr,n,i+1);

        arr[0]='1';
        int ans1=binarystrings(arr,n,i+1);
        return ans+ans1;
    }
    if(arr[i-1]!='1')
    {
        arr[i]='0';
        int a=binarystrings(arr,n,i+1);
        arr[i]='1';
        int b=binarystrings(arr,n,i+1);
        return a+b;
    }
    else
    {
        arr[i]='0';

        int a=binarystrings(arr,n,i+1);
        return a;
    }

}
int main() {
    int t;
    cin>>t;
    int q=1;
    int n;
    while(q<=t)
    {
        cin>>n;
        char arr[n+1];
        arr[0]='\0';
        int ans=binarystrings(arr,n,0);
        cout<<ans<<endl;
        q++;

    }
    return 0;
}
