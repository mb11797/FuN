#include<iostream>
using namespace std;

void encode_kar(string str){
    int i=0;
    char trapped = str[0];
    cout<<trapped;
    int count=0;
    while(str[i]!='\0'){
        if(str[i]!=trapped){
            cout<<count;
            count = 0;
            trapped = str[i];
            count++;
            cout<<trapped;
        }
        else{
            count++;
        }
        i++;
    }
    cout<<count;
}

int main(){
    string str;
    cin>>str;

    encode_kar(str);

    return 0;
}
