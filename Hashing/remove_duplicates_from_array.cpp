#include<iostream>
#include<map>
using namespace std;

void remove_duplicates(int*arr, int n){
    map<int, int> my_map;

    for(int i=0; i<n; i++){
        my_map[arr[i]] = arr[i];
    }

    for(auto node: my_map){
        cout<<node.first<<" ";
    }
    cout<<endl;
    return;
}

int main(){
    int n;
    cin>>n;

    int arr[100];
    for(int i=0; i<n; i++)
        cin>>arr[i];

    remove_duplicates(arr, n);

    return 0;
}
