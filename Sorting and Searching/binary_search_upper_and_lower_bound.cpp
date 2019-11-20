#include<iostream>
using namespace std;

//first occurence of key in the array
int first_occurence(int*arr, int n, int key){
    int s = 0, e = n-1;
    int mid;
    int ans = -1;
    while(s<=e){
        mid = (s+e)/2;
        if(arr[mid]==key){
            ans = mid;
            e = mid - 1;
        }
        else if(arr[mid]<key){
            s = mid + 1;
        }
        else{
            e = mid - 1;
        }
    }
    return ans;
}

//last occurence of key in the array
int last_occurence(int*arr, int n, int key){
    int s = 0, e = n-1;
    int mid;
    int ans = -1;
    while(s<=e){
        mid = (s+e)/2;
        if(arr[mid]==key){
            ans = mid;
            s = mid + 1;
        }
        else if(arr[mid]<key){
            s = mid + 1;
        }
        else{
            e = mid - 1;
        }
    }
    return ans;
}

int main(){
    int arr[] = {1,2,2,2,3,4,4,4,4};
    int n = sizeof(arr)/sizeof(int);

    int key;
    cin>>key;

    cout<<first_occurence(arr, n, key)<<endl;

    cout<<last_occurence(arr, n, key)<<endl;

    return 0;
}
