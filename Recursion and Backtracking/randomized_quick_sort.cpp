#include<iostream>
#include<ctime>
#include<algorithm>
using namespace std;


void shuffle(int arr[], int s, int e){
    srand(time(NULL));
    int i, j, temp;

    for(int i=e; i>0; i--){
        //create one random index
        j = rand()%(i+1);
        swap(arr[i], arr[j]);
    }
}

int partition(int arr[], int s, int e){
    int i = s-1;
    int j = s;
    int pivot = arr[e];

    for(; j<e; j++){
        if(arr[j]<=pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    //Bring the pivot element to its sorted position
    swap(arr[i+1], arr[e]);
    return i+1;
}

void quick_sort(int*arr, int s, int e){
    if(s>=e)
        return;

    int p = partition(arr, s, e);
    quick_sort(arr, s, p-1);
    quick_sort(arr, p+1, e);
    return;
}

int main(){
//    int arr[] = {2,1,5,6,7,5,8};
    int arr[] = {1,2,3,4,5,6,7};
    int n = sizeof(arr)/sizeof(int);

    shuffle(arr, 0, n-1);

    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";

    cout<<endl;

    quick_sort(arr, 0, n-1);

    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";


    return 0;
}

