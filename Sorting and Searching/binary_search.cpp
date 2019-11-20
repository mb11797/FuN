#include<iostream>
using namespace std;

int binary_search(int arr[], int n, int key){
    int s = 0, e = n-1;
    int mid;

    while(s<=e){
        mid = (s+e)/2;
        if(arr[mid]==key){
            return mid;
        }
        else if(arr[mid]>key){
            e = mid-1;
        }
        else{
            s = mid+1;
        }
    }
    return -1;

}

int main(){
    int arr[] = {1,3,5,10,12,15,17};
    int n = sizeof(arr)/sizeof(int);

    int key;
    cin>>key;

    int search_idx = binary_search(arr, n, key);

    if(search_idx==-1){
        cout<<key<<" is not present!"<<endl;
    }
    else{
        cout<<key<<" is present at index "<<search_idx<<endl;
    }
    return 0;
}
