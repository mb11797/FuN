#include<iostream>
using namespace std;

int main(){
    int x = 10;
    int *xptr;
    xptr = &x;


    cout<<1<<" "<<&x<<endl;
    cout<<1.1<<" "<<(int)&x<<endl;
    cout<<2<<" "<<xptr<<endl;
    cout<<2.1<<" "<<(int)xptr<<endl;

    cout<<3<<" "<<*(&x)<<endl;
    cout<<4<<" "<<*(xptr)<<endl;

    cout<<5<<" "<<*(&xptr)<<endl;
    cout<<5.1<<" "<<(int)*(&xptr)<<endl;
    cout<<6<<" "<<&(*xptr)<<endl;
    cout<<6.1<<" "<<(int)&(*xptr)<<endl;

    cout<<7<<" "<<&xptr<<endl;
    cout<<7.1<<" "<<(int)&xptr<<endl;
    //Double Pointer
    int **xxptr = &xptr;
    cout<<8<<" "<<&xxptr<<endl;
    cout<<8.1<<" "<<(int)&xxptr<<endl;
    cout<<9<<" "<<*xxptr<<endl;
    cout<<9.1<<" "<<(int)*xxptr<<endl;
    cout<<10<<" "<<&(*xxptr)<<endl;
    cout<<10.1<<" "<<(int)&(*xxptr)<<endl;
    cout<<11<<" "<<*(&xxptr)<<endl;
    cout<<11.1<<" "<<(int)*(&xxptr)<<endl;
    cout<<12<<" "<<**xxptr<<endl;
    return 0;
}
