#include<iostream>
using namespace std;

int main(){
    int x = 10;
    //reference variable
    int &y = x;
    int &z = y;
//    y = z;

    y = y + 1;
    z = z + 1;
    cout<<x<<endl;
    cout<<y<<endl;
    cout<<z<<endl;
    return 0;
}


