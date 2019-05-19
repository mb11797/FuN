#include<iostream>
using namespace std;

#define ll long long

int main(){
    int tc;
    cin>>tc;
    while(tc--){
        string str1, str2;
        cin>>str1>>str2;
        ll n = str1.length();
        char final_key[1000000];
        //Method - 1
        for(ll i=0; i<n; i++){
            final_key[i] = (str1[i]^str2[i])+'0';
        }
        final_key[n] = '\0';
        cout<<final_key<<endl;
    }
    return 0;
}
