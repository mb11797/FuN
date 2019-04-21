#include<iostream>
using namespace std;

int main(){
    int arr[] = {1,2,3,4,5};
    int *arr1 = arr;

    char arr2[] = {'a', '1', 'b', '2', 'c', '3'};
    char *arr3 = arr2;

    char arr4[] = "absfcs";
    char*ptr = "absfcs";

    int arr5[10];
    int* ptr1;

    ptr1=arr5;                          //legal
//    arr5=ptr1;                          //illegal

    cout<<sizeof(arr)<<endl;            // 20
    cout<<sizeof(arr1)<<endl;           //4

    cout<<sizeof(arr2)<<endl;
    cout<<sizeof(arr3)<<endl;

    cout<<arr4<<endl;
    cout<<ptr<<endl;

//    cout<<&arr4<<endl;
//    cout<<&ptr<<endl;
//    cout<<arr++<<endl;                  //illegal
    cout<<arr1++<<endl;
    cout<<*(arr1++)<<endl;

    cout<<arr<<endl;
    cout<<arr1<<endl;

    return 0;
}
