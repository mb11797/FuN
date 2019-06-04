#include<iostream>
using namespace std;

void remove_duplicates(char*str, string osf, bool token){
    if(str[0]=='\0'){
        cout<<osf<<endl;
        return;
    }

    if(str[0]==str[1]){
        if(token==false){
            remove_duplicates(str+2, osf+str[0], true);
        }
        else{
            remove_duplicates(str+1, osf, true);
        }
    }
    else{
        token = false;
        if(str[1]==str[2])
            token = true;
        remove_duplicates(str+1, osf+str[0], token);
    }
    return;
}

int main(){
    char str[1000];
    cin>>str;

    bool token;
    if(str[0]==str[1])
        token = true;
    else
        token = false;

    remove_duplicates(str, "", token);

    return 0;
}
