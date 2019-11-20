#include<iostream>
using namespace std;

int main(){
    //Create and initialize
    int a[10];
//    int a[10] = {1,2,3};

    cout<<"Enter no of elements : ";
    int n;
    cin>>n;

    cout<<endl;
//    Input elements of array
    cout<<"Enter elements : ";
    for(int i=0; i<n; i++)
        cin>>a[i];

    cout<<endl;
    //Print
    for(int i=0; i<n; i++)
        cout<<a[i]<<" ";

    cout<<endl<<"Reverse Order : ";
    //Reverse order print
    for(int i=n-1; i>=0; i--)
        cout<<a[i]<<" ";

    cout<<endl;
    cout<<"Enter key : ";
    int key;
    cin>>key;

    cout<<endl;
    //Linear search
    int i;
    for(i=0; i<n; i++){
        if(key==a[i]){
            cout<<"Found at index "<<i<<endl;
            break;
        }
    }
    //Two ways -- Either loop terminates or we hit the break

    if(i==n)
        cout<<key<<" is not present!!";

    return 0;
}
