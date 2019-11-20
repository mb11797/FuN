#include<iostream>
using namespace std;

void decode_CamelCasing(string str){
    if(str[0]=='\0'){
        return;
    }
    cout<<str[0];
    if(str[1]>=65 && str[1]<=90){
        cout<<" ";
        decode_CamelCasing(str.substr(1));
    }
    else{
        decode_CamelCasing(str.substr(1));
    }
    return;
}

int main(){
    string str;
    cin>>str;

    decode_CamelCasing(str);
    return 0;
}
