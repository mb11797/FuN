#include<iostream>
using namespace std;

void generate_subsets(int arr[], int n){
    for(int i=0; i<(1<<n); i++){
        cout<<"{";
        for(int j=0; j<n; j++){
            if((i & (1<<j)) > 0){
                cout<<" "<<arr[j]<<" ";
            }
        }
        cout<<"}, ";
    }
    return;
}

int main(){
    int arr[100];
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>arr[i];

    generate_subsets(arr, n);

    return 0;
}
