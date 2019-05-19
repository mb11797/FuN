#include<iostream>
using namespace std;

void insert_ascii_diff(string str, string osf){
    if(str[1]=='\0'){
        osf += str[0];
        cout<<osf<<endl;
        return;
    }
    int diff = str[1]-str[0];
    osf += str[0] + to_string(diff);
    insert_ascii_diff(str.substr(1), osf);
    return;
}

int main(){
    string s;
    cin>>s;

    insert_ascii_diff(s, "");
    return 0;
}

