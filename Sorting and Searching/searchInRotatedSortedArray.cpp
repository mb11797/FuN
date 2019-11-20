#include<iostream>
using namespace std;

int searchIn(int a[], int s, int e, int key){
    if(s>e){
        return -1;
    }

    //Recursive case
    int mid = (s+e)/2;

    if(key==a[mid])
        return mid;

    //if mid lies on the first line (left line of graph)
    if(a[s]<=a[mid]){
        if(key>=a[s] && key<=a[mid])
            return searchIn(a, s, mid-1, key);
        else
            return searchIn(a, mid+1, e, key);
    }
    //if mid lies on the second line (right line of graph)
    if(key>=a[mid] && key<=a[e])
        return searchIn(a, mid+1, e, key);

    return searchIn(a, s, mid-1, key);
}

int main(){
    int arr[] = {6,7,1,2,3,4,5};
    int key;
    cin>>key;

    cout<<key<<" is present at index "<<searchIn(arr, 0, 6, key)<<endl;

    return 0;
}
