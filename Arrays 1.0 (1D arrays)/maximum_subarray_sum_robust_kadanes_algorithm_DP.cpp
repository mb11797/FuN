#include<iostream>
using namespace std;

int main(){
    int a[100];
    int n;
    cin>>n;

    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    int max_so_far = a[0];
    int max_ending_here = a[0];

    for(int i=1; i<n; i++){
        max_ending_here = max(max_ending_here+a[i], a[i]);
        max_so_far = max(max_so_far, max_ending_here);
    }

    cout<<max_so_far<<endl;

    return 0;
}
