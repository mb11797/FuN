#include<iostream>
using namespace std;

int max_circ_sum(int*arr, int n){
    int max_sum = INT_MIN;
    for(int i=0; i<n; i++){
        int count=0;
        int sum=0;
        while(count<n){
            if(i+count<n){
                sum = sum + arr[i+count];
                if(sum>max_sum){
                    max_sum = sum;
                }
            }
            else if(i+count>=n){
                i=0;
                while(count<n){
                    sum = sum + arr[i++];
                    if(sum>max_sum){
                        max_sum = sum;
                    }
                    count++;
                }
                break;
            }
            count++;
        }


    }
    return max_sum;
}

int main(){
    int tc;
    cin>>tc;
    int n;
    while(tc--){
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];

        cout<<max_circ_sum(arr, n)<<endl;
    }
    return 0;
}
