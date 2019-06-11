#include<iostream>
#include<algorithm>
#include<map>
using namespace std;

map<string, int> m;
map<string, int> :: iterator it;

void ans(int arr[], int i, int n, int out[], int j, int target){
    if(i>=n){
        int ts = 0;
        string s = "";
        for(int i=0; i<j; i++){
            ts += out[i];
            s += (char(out[i])-48);
        }
        if(ts==target && m.find(s)==m.end()){
            for(int i=0; i<j; i++){
                cout<<out[i]<<" ";
            }
            cout<<endl;
            m[s]++;
        }
        return;
    }
    out[j] = arr[i];
    ans(arr, i+1, n, out, j+1, target);
    ans(arr, i+1, n, out, j, target);
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    int out[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];

    int target;
    cin>>target;

    sort(arr, arr+n);

    ans(arr, 0, n-1, out, 0, target);
    return 0;
}
