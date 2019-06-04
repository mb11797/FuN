#include<iostream>
using namespace std;

void duplicate_char_formatting(char*str, string osf){
    if(str[0]=='\0'){
        cout<<osf<<endl;
        return;
    }

    if(str[0]==str[1]){
        duplicate_char_formatting(str+1, osf+str[0]+'*');
    }
    else{
        duplicate_char_formatting(str+1, osf+str[0]);
    }
    return;
}

int main(){
    char str[1000];
    cin>>str;

    duplicate_char_formatting(str, "");

    return 0;
}
