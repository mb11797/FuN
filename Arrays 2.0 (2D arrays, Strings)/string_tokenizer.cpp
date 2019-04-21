#include<iostream>
#include<cstring>
using namespace std;

int main(){
    char str[] = "Hi, i am an excellent coder";

    char*ptr;

    ptr = strtok(str, " ");
//    cout<<ptr<<endl;

//    ptr = strtok(NULL, " ");
//    cout<<ptr<<endl;
//
//    ptr = strtok(NULL, " ");
//    cout<<ptr<<endl;

    while(ptr!=NULL){
        cout<<ptr<<endl;
        ptr = strtok(NULL, " ");
    }

    return 0;
}
