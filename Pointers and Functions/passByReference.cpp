#include<iostream>
using namespace std;

//pass by value
void increment_byVal(int a){
    a = a+1;
    cout<<"Inside Function : "<<a<<endl;
}

//Pass by reference
void increment_byRef(int *aptr){
    *aptr = *aptr+1;
    cout<<"Inside Function : "<<*aptr<<endl;
}

int main(){
    int a=10;
    increment_byVal(a);
    cout<<"Inside Main : "<<a<<endl;

    increment_byRef(&a);
    cout<<"Inside Main : "<<a<<endl;
    return 0;
}
