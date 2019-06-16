#include<iostream>
#include<queue>
#include<vector>
#include<functional>
using namespace std;

typedef pair<int, pair<int, int>> pr;

priority_queue<pr, vector<pr>, greater<pr>> pq;

void merge_k_sorted_arrays(int arr[10][10], int out[1000], int k, int n){

    for(int i=0; i<k; i++){
        pq.push({arr[i][0], {i, 0}});
    }

    int z=0;
    while(!pq.empty()){
        pr p = pq.top();
        pq.pop();

        out[z++] = p.first;
        int i = p.second.first;
        int j = p.second.second;

        pq.push({arr[i][j+1], {i, j+1}});
    }
    return;
}


int main(){
    int k;
    cin>>k;

    int n;
    cin>>n;

    int arr[10][10];
    int out[1000];
    for(int i=0; i<k; i++)
        for(int j=0; j<n; j++)
            cin>>arr[i][j];

    merge_k_sorted_arrays(arr, out, k, n);

    for(int i=0; i<k*n; i++)
        cout<<out[i]<<" ";

    return 0;
}
