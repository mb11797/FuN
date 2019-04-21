#include<iostream>
using namespace std;

int main(){
    char a[50];
    cout<<"Enter number : ";
    cin>>a;

    int i=0;
    if(a[0]=='9')
        i++;

    //Iterate over the remaining chars
    for(; a[i]!='\0'; i++){

        int digit = a[i] - '0';         //convert current character into an int digit
        if(digit>=5){
            digit = 9 - digit;
            a[i] = digit + '0';
        }
    }
    cout<<a<<endl;


    return 0;
}
