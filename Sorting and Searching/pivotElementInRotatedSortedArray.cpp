//Given a sorted and rotated array.
//Find out the Highest Element(Pivot) in the array using binary search
//e.g, a[] = {5,6,7,1,2,3,4} - pivot element index = 2

#include<iostream>
using namespace std;

int main(){
//    int arr[] = {6,7,1,2,3,4,5};
//    int arr[] = {4,5,6,7,8,1,2,3};
    int arr[] = {1,2,3,4,5,6,7,8};
    int n = sizeof(arr)/sizeof(arr[0]);
    int s = 0, e = n-1;

    int mid;

    while(s<=e){
        mid = (s+e)/2;

        if(mid>s && arr[mid]<arr[mid-1]){
            cout<<mid-1<<" is the pivot index."<<endl;
            break;
        }
        if(mid<e && arr[mid]>arr[mid+1]){
            cout<<mid<<" is the pivot index"<<endl;
            break;
        }
        //when above both conditions do not satisfy(arr[mid-1]<=arr[mid]<=arr[mid+1]), then we become confused which side to go on
        //(hint only one of the side is sorted)

        //if left part(first line) in the graph is sorted then search for pivot in the right part
        if(arr[s]<=arr[mid]){
            s = mid + 1;
        }

        //if right part(second line) in the graph is sorted then search for pivot in the left part
        if(arr[mid]<=arr[e]){
            e = mid - 1;
        }

    }
    if(s>e)
        cout<<"There is no pivot.";

    return 0;
}
