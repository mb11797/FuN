#include<iostream>
using namespace std;

void check_case(char ch){
    int ascii = ch;
    if(ascii>=97 && ascii<=122)
        cout<<"lowercase"<<endl;
    else if(ascii>=65 && ascii<=90)
        cout<<"UPPERCASE"<<endl;
    else
        cout<<"Invalid"<<endl;
}

int main(){
    char ch;
    cin>>ch;

    check_case(ch);

    return 0;
}
