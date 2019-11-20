#include<iostream>
using namespace std;

void print_strings_after_removing_wildcard_char(string str, string osf){
    if(str[0]=='\0'){
        cout<<osf<<endl;
        return;
    }
    if(str[0] == '?'){
        print_strings_after_removing_wildcard_char(str.substr(1), osf+'0');
        print_strings_after_removing_wildcard_char(str.substr(1), osf+'1');
    }else{
        print_strings_after_removing_wildcard_char(str.substr(1), osf+str[0]);
    }
    return;
}

int main(){
    string str;
    cin>>str;

    print_strings_after_removing_wildcard_char(str, "");

    return 0;
}
