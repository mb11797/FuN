#include<iostream>
using namespace std;

int searchIn(int*a, int n, int key){
    int s = 0, e = n-1;
    int mid;

    while(s<=e){
        mid = (s+e)/2;
        if(a[mid]==key)
            return mid;
        if(a[s]<=a[mid]){                           //first part of graph is sorted and contains mid
            if(key>=a[s] && key<=a[mid])            //key is present in the sorted left part
                e = mid - 1;
            else                                    //key is present in the unsorted right part
                s = mid +1;
        }
        else if(a[e]>=a[mid]){                      //second part of graph is sorted and contains mid
            if(key>=a[mid] && key<=a[e])            //key is present in the unsorted left part
                s = mid + 1;
            else                                    //key is present in the sorted right part
                e = mid - 1;
        }
    }
    return -1;
}

int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int key;
    cin>>key;

    cout<<searchIn(arr, n, key);
    return 0;
}
