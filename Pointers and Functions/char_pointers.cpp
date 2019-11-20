#include<iostream>
using namespace std;

int main(){
    char ch='A';
    cout<<ch<<endl;
    cout<<&ch<<endl;
    cout<<(void*)&ch<<endl;

//    int*ptr = &ch;
    int*ptr = (int*)&ch;
    cout<<ptr<<endl;
    return 0;
}
