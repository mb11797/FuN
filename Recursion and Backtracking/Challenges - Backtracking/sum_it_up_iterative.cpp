#include<iostream>
#include<vector>
using namespace std;

void print_the_combinations(int*arr, int n, int target){

    vector<int> v;
    for(int i=0; i<n; i++){
        int sum = 0;
        sum += arr[i];
        v.push_back(arr[i]);
        for(int j=i+1; j<n; j++){

            if(target>sum+arr[j]){
                sum = sum + arr[j];
                v.push_back(arr[j]);
            }
            else if(target==sum+arr[j]){
                v.push_back(arr[j]);
                for(int k=0; k<v.size(); k++){
                    cout<<v[k]<<" ";
                }
                cout<<endl;
                v.pop_back();
            }
        }
        v.clear();
    }
}

int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];

    int target;
    cin>>target;

    print_the_combinations(arr, n, target);

    return 0;
}
