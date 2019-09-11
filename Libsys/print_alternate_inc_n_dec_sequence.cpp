/*
1
3   2
4   5   6
10  9   8   7
11  12  13  14  15
*/

#include<iostream>
using namespace std;

int main(){
//    int arr[15];
//    for(int i=0; i<15; i++){
//        arr[i] = i+1;
//    }
//
//    int n = 5;
//
    int n;
    cin>>n;

    //(n+1)C2 = ((n+1)*n)/2
    int n_elmts = (n*(n+1))/2;
    int arr[n_elmts];

    for(int i=0; i<n_elmts; i++){
        arr[i] = i+1;
    }

    int flag=0;
    int k=0;
    for(int i=0; i<n; i++){
        if(flag==0){
            int r=k;
            for(int j=0; j<=i; j++){
                cout<<arr[r]<<"\t";
                r++;
            }
            cout<<endl;
            flag = 1;
            k = r + i + 1;
        }
        else if(flag==1){
            int r=k;
            for(int j=0; j<=i; j++){
                cout<<arr[r]<<"\t";
                r--;
            }
            cout<<endl;
            flag = 0;
            k = k+1;
        }
    }
    return 0;
}
