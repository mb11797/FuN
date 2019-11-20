#include<iostream>
#include<cstring>
using namespace std;

int main(){
    char no[50];
    cin>>no;

    for(int i=0; i<strlen(no); i++){
        int digit = no[i] - '0';
        if(digit>=5){
            if(i==0 && digit==9){
                continue;
            }
            digit = 9 - digit;
            no[i] = '0' + digit;
        }
    }

    cout<<no;
    return 0;
}
