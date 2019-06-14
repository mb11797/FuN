#include<iostream>
#include<algorithm>
using namespace std;

void print_dictionary_smaller(string s, char*str, int i){
    if(str[i]=='\0'){
        if(str<s)
            cout<<str<<endl;
        return;
    }
    for(int j=i; str[j]!='\0'; j++){
        swap(str[i], str[j]);
        print_dictionary_smaller(s, str, i+1);
        //backtracking
        swap(str[i], str[j]);
    }
    return;
}

int main(){
    char str[1000];
    cin>>str;

    string s = str;

    int k = 0;
    string temp[10000];
    print_dictionary_smaller(s, str, 0);

    return 0;
}
