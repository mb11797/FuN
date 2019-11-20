#include<iostream>
using namespace std;

int main(){
    int a[100];
    cout<<"Enter n : ";
    int n;
    cin>>n;

    int cs = 0;
    int ms = 0;

    for(int i=0; i<n; i++)
        cin>>a[i];

    for(int i=0; i<n; i++){
        cs = cs + a[i];
        if(cs<0)
            cs = 0;

        ms = max(cs, ms);

    }

    cout<<"Maximum Sum : "<<ms;

    return 0;
}
