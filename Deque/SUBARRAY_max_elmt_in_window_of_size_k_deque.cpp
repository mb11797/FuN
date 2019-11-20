#include<iostream>
#include<deque>
using namespace std;

int main(){
    int arr[100000];
    int n;
    cin>>n;
    int k;
    cin>>k;

    for(int i=0; i<n; i++)
        cin>>arr[i];

    deque<int> Q(k);
    int i;
    for(i=0; i<k; i++){

        while(!Q.empty() and arr[Q.back()]<arr[i]){
            Q.pop_back();
        }
        Q.push_back(i);
    }

    for(; i<n; i++){
        cout<<arr[Q.front()]<<" ";
        while(!Q.empty() and Q.front()<=i-k){
            Q.pop_front();
        }
        while(!Q.empty() and arr[Q.back()]<=arr[i]){
            Q.pop_back();
        }
        Q.push_back(i);
    }
    cout<<arr[Q.front()]<<" "<<endl;
    return 0;
}
