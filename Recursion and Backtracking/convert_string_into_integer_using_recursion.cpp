#include<iostream>
using namespace std;

int to_integer(char*s, int temp){
    if(s[0]=='\0')
        return temp/10;
    int digit = (int)s[0] - (int)'0';
    temp += digit;
    temp *= 10;
    return to_integer(s+1, temp);
}

int main(){
    char s[100];
    cin>>s;

    cout<<to_integer(s, 0)<<endl;
    return 0;
}
