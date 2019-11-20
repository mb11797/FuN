#include<iostream>
#include<string.h>
using namespace std;

void print_permutations(char*str, int k){
    if(str[k] == '\0'){
        cout<<str<<endl;
        return;
    }

    for(int i=k; str[i]!='\0'; i++){
        swap(str[k], str[i]);
        print_permutations(str, k+1);
        swap(str[k], str[i]);
    }
    return;
}

int main(){
    char str[100];
    cin>>str;

    print_permutations(str, 0);
    return 0;
}

