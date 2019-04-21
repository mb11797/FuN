#include<iostream>
using namespace std;

void selection_sort(int a[], int n){
    for(int i=0; i<n-1; i++){
        //assume the current ith is min
        int min_idx = i;
        //min element in rem. part
        for(int j=i+1; j<n; j++){
            if(a[j]<a[min_idx])
                min_idx = j;
        }
        //swap current position element with minIdx element
        swap(a[i], a[min_idx]);
    }
    return;
}

int main(){
    int arr[5] = {51,1,36,24,2};

    selection_sort(arr, 5);

    for(int i=0; i<5; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}
