#include<iostream>
#include<unordered_map>
using namespace std;

void print_zero_sum_pairs(int*arr, int n){
    unordered_map<int, int> um;

    for(int i=0; i<n; i++){
        if(arr[i]==0){
            um[0] = 0;
            continue;
        }
        um[arr[i]] = -arr[i];
    }

    for(auto i: um){
//        cout<<i.first<<"->"<<i.second<<endl;
        if(um.count(i.second)==1){
            if(i.second == 0){
                cout<<"(0, 0)"<<endl;
//                um.erase(i.second);
                continue;
            }
            cout<<"("<<i.first<<", "<<i.second<<")"<<endl;
            um.erase(i.second);
        }
    }
    return;
}

int main(){
    int arr[100];
    int n;
    cin>>n;

    for(int i=0; i<n; i++)
        cin>>arr[i];

    print_zero_sum_pairs(arr, n);

    return 0;
}
