#include<iostream>
#include<cstring>
using namespace std;

int main(){
    char a[20];
    cin>>a;

    int len = strlen(a);
    int ans = 0;

    ans = (1<<len) - 2;
    //Iterate over the nos from units place and add the contribution of 7
    for(int i=len-1, pos=0; i>=0; i--, pos++){
        if(a[i]=='7'){
            ans += (1<<pos);
        }
    }
    cout<<ans+1<<endl;

    return 0;
}
