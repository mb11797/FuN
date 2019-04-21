#include<iostream>
using namespace std;

void print_unique_nos(int*arr, int n){
    int res=0;
    for(int i=0; i<n; i++){
        res^=arr[i];
    }

    //find the first set bit position from right
    int i=0;
    int temp = res;
    while(temp>0){
        if((temp&1)!=0){
            break;
        }
        i++;
        temp = (temp>>1);
    }
    cout<<"First set bit position in res: "<<i<<endl;

    //divide the array elements into 2 parts - first one have the set bit in the same posn as res and other ones do not
    int mask = (1<<i);
    int firstNo = 0;
    for(int i=0; i<n; i++){
        if((arr[i]&mask) != 0){
            firstNo ^= arr[i];
        }
    }
    int secondNo = res^firstNo;

    cout<<firstNo<<endl<<secondNo<<endl;
}

int main(){
    int n;
//    int arr[] = {1, 3, 5, 6, 3, 2, 1, 2};
//    int arr[] = {1, 3, 5, 4, 3, 2, 1, 2};
    int arr[] = {1, 3, 5, 7, 3, 2, 1, 2};
    n = sizeof(arr)/sizeof(arr[0]);
//    for(int i=0; i<n; i++){
//        cin>>arr[i];
//    }
    print_unique_nos(arr, n);
    return 0;
}
