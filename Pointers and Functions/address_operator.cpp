#include<iostream>
using namespace std;

int main(){
    int x = 10;
    int y1 = 20;
    cout<<&x<<endl;

    float y = 11.2;
    cout<<&y<<endl;

    //doesn't work for character variables
    char ch = 'A';
    cout<<&ch<<endl;
    //explicit typecasting from char* to void*
    cout<<(void*)&ch<<endl;

    //Pointers
    int *xptr;
    //store the address of a variable
    xptr = &x;
    cout<<&x<<endl;
    cout<<xptr<<endl;

    //Reassign another address to the variable
    xptr = &y1;
    cout<<&y1<<endl;
    cout<<xptr<<endl;

    return 0;
}
