#include<iostream>
using namespace std;

int searchIn(int*arr, int n, int key, char ch){
    int s = 0, e = n-1;
    int mid;
    int ans = -1;
    while(s<=e){
        mid = (s+e)/2;
        if(arr[mid]==key){
            ans = mid;
            if(ch == 'u')                   //upper bound
                s = mid + 1;
            else if(ch == 'l')              //lower bound
                e = mid - 1;
        }
        else if(arr[mid]<key)
            s = mid + 1;
        else if(arr[mid]>key)
            e = mid - 1;
    }
    return ans;
}

int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int tc;
    cin>>tc;

    while(tc--){
        int key;
        cin>>key;
        cout<<searchIn(arr, n, key, 'l')<<" "<<searchIn(arr, n, key, 'u')<<endl;
    }
    return 0;
}
