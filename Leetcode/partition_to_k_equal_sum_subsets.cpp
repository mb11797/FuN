#include<iostream>
#include<map>
#include<vector>
using namespace std;

bool canPartitionKSubsets(vector<int>& nums, int k) {
    map<int, int> m;

    int n = nums.size();
    int sum;
    for(int i=0; i<(1<<n); i++){
        sum=0;
        for(int j=0; j<n; j++){
            if(i&(1<<j)){
                sum += nums[j];
            }
        }
        m[sum]+=1;
    }

    for(auto i: m){
        if(i.second==k){
            return true;
        }
    }
    return false;
}

int main(){
    vector<int> arr;


    return 0;
}
