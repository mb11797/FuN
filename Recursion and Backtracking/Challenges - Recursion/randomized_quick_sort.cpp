#include<iostream>
#include<ctime>
using namespace std;

void shuffle(int*arr, int s, int e){
    srand(time(NULL));

    for(int i=e; i>0; i--){
        int j = rand()%(i+1);
        swap(arr[i], arr[j]);
    }
}

int partition(int*arr, int s, int e){
    int i = s-1;
    int j = s;
    int pivot = arr[e];

    for(int j=s; j<e; j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[e]);
    return i+1;
}

void quick_sort(int arr[], int s, int e){
    if(s>=e)
        return;

    int p = partition(arr, s, e);
    quick_sort(arr, s, p-1);
    quick_sort(arr, p+1, e);

    return;
}

int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];

    shuffle(arr, 0, n-1);

    quick_sort(arr, 0, n-1);

    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;


    return 0;
}


