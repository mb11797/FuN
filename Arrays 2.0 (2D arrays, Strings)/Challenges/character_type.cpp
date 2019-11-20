#include<iostream>
using namespace std;

char character_type_check(char ch){
    int ascii = ch;

    if(ascii>=65 && ascii<=90)
        return 'U';
    else if(ascii>=97 && ascii<=122)
        return 'L';
    else
        return 'I';
}

int main(){
    char ch;
    cin>>ch;

    cout<<character_type_check(ch)<<endl;
    return 0;
}
