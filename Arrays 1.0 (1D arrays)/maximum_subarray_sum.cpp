#include<iostream>
using namespace std;

int main(){
    int a[100];
    cout<<"Enter n : ";
    int n;
    cin>>n;

    for(int i=0; i<n; i++)
        cin>>a[i];

    cout<<endl;
    int currSum = 0;
    int maxSum = 0;
    int left = -1;
    int right = -1;
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            currSum = 0;
            for(int k=i; k<=j; k++){
                cout<<a[k]<<" ";
                currSum += a[k];
            }
            cout<<endl<<"Sum : "<<currSum<<endl<<endl;
            if(currSum>maxSum){
                maxSum = currSum;
                left = i;
                right = j;
            }
        }

    }
    cout<<"Maximum Sum : "<<maxSum<<endl<<"Sub Array : ";
    for(int k=left; k<=right; k++)
        cout<<a[k]<<" ";

    return 0;
}
