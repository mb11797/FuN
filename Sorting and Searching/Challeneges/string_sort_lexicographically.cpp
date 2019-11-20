#include<iostream>
#include<algorithm>
using namespace std;

bool myCompare(string str1, string str2){
    if(str1[0]==str2[0]){
        if(str1.length()==str2.length())
            for(int i=0; i<str1.length(); i++){
                if(str1[i]<str2[i])
                    return true;
            }
        return str1.length()>str2.length();
    }
    return str1<str2;
}

int main(){
    int n;
    cin>>n;

    string str[n];
    for(int i=0; i<n; i++){
        cin>>str[i];
    }

    sort(str, str+n, myCompare);

    for(int i=0; i<n; i++)
        cout<<str[i]<<" ";
    return 0;
}
