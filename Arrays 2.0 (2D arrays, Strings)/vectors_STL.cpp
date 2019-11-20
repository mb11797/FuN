#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(int a, int b){
    return a>b;
}

int main(){
    vector<int> v;
    v.reserve(100);
    cout<<v.size()<<endl;
    v.push_back(12);

    cout<<v[0]<<endl;
    cout<<"Current capacity: "<<v.capacity()<<endl;

    int n;
    cin>>n;
    int temp;
    cout<<endl;
    for(int i=0; i<n; i++){
        cin>>temp;
        v.push_back(temp);
        cout<<"Current capacity: "<<v.capacity()<<endl;

    }
    cout<<endl;
    v.pop_back();
//    v.clear();
    cout<<"Current capacity: "<<v.capacity()<<endl;

    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;

    sort(v.begin(), v.end(), compare);
    cout<<"Sorted: "<<endl;
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }

    cout<<endl;
    cout<<v.at(1)<<endl;
    cout<<v.max_size()<<endl;
    return 0;
}
