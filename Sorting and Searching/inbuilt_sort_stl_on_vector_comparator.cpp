#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool myCompare(int a, int b){
    return a>b;
}

int main(){
    vector<int> v;
    v.reserve(100);

    int n;
    cin>>n;

    for(int i=0; i<n; i++){
        int temp;
        cin>>temp;
        v.push_back(temp);
    }

    cout<<v.capacity()<<endl;

    sort(v.begin(), v.end(), myCompare);

    for(int i=0; i<n; i++)
        cout<<v[i]<<" ";

    return 0;
}
