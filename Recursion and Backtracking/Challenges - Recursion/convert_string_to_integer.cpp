#include<iostream>
using namespace std;

int string_to_integer(char*s, int temp){
    if(s[1]=='\0'){
        int digit = (int)s[0] - (int)'0';
        temp += digit;
        return temp;
    }
    int digit = (int)s[0] - (int)'0';
    temp += digit;
    temp *= 10;
    return string_to_integer(s+1, temp);
}

int main(){
    char s[100];
    cin>>s;

    cout<<string_to_integer(s, 0)<<endl;
    return 0;
}
