#include<iostream>
using namespace std;

int main(){
    int n = 7;
//    int n = 8;
    int arr[7] = {6,2,5,4,5,2,6};
//    int arr[n] = {2,4,5,6,6,5,4,2};
    int m;
    int area = 0;
    for(int i=0; i<n; i++){
        m = arr[i];
        for(int j=i+1; j<n; j++){
            m = min(m, arr[j]);
            area = max(area, m*(j-i+1));
        }
    }

    cout<<area<<endl;

    return 0;
}
