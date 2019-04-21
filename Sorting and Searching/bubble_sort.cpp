#include<iostream>
using namespace std;

void swap(int*a, int*b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

//increasing order sorting
void bubble_sort(int*a, int n){
    int i=0;
    while(i<n){
        int j=0;
        while(j<n-i-1){
            if(a[j]>a[j+1])
                swap(a[j], a[j+1]);
            j++;
        }
        i++;
    }
    return;
}


////decreasing order sorting
//void bubble_sort(int*a, int n){
//    int i=0;
//    while(i<n){
//        int j=0;
//        while(j<n-i-1){
//            if(a[j]<a[j+1])
//                swap(a[j], a[j+1]);
//            j++;
//        }
//        i++;
//    }
//    return;
//}

int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    bubble_sort(arr, n);

    cout<<"Sorted array: "<<endl;
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
