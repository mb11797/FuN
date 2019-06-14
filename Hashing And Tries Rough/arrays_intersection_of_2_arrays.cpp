#include<unordered_map>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    vector<int> v;
    cin>>n;
    int *arr1=new int[n];
    int *arr2=new int[n];
    unordered_map<int, int> m;

    for(int i=0;i<n;i++){
        cin>>arr1[i];
        m[arr1[i]]++;
    }
    for(int i=0;i<n;i++){
        cin>>arr2[i];
        if(m.count(arr2[i])){
        if(m[arr2[i]]>0)
        v.push_back(arr2[i]);
        m[arr2[i]]--;
        }
    }
    sort(v.begin(), v.end());
    cout<<"["<<v.front();
    for(int i=1;i<v.size();i++)
        cout<<", "<<v[i];
    cout<<"]";
    return 0;
}

