#include<iostream>
using namespace std;

bool search_it_baby(int arr[][30], int n, int m, int key, int i, int j){
    if(i>n or j>m){
        return 0;
    }
    if(arr[i][j]==key){
        return 1;
    }
    return search_it_baby(arr, n, m, key, i+1, j) or search_it_baby(arr, n, m, key, i, j+1);
}


int main(){
    int tc;
    cin>>tc;
    while(tc--){
        int n, m;
        cin>>n>>m;

        int arr[30][30];
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin>>arr[i][j];
            }
        }

        int key;
        cin>>key;

        cout<<search_it_baby(arr, n, m, key, 0, 0);
    }
    return 0;
}
