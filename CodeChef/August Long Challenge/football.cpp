#include<iostream>
#include<climits>
using namespace std;

int max_pts(int*A, int*B, int n){
    int pts[n] = {0};
    int max_pts=INT_MIN;

    for(int i=0; i<n; i++){
        pts[i] = A[i]*20 - B[i]*10;
        if(pts[i]<0)
            pts[i]=0;
        if(pts[i]>max_pts)
            max_pts = pts[i];
    }
    return max_pts;
}

int main(){
    int tc;
    cin>>tc;

    while(tc--){
        int n;
        cin>>n;

        int A[n];
        int B[n];

        for(int i=0; i<n; i++){
            cin>>A[i];
        }

        for(int i=0; i<n; i++){
            cin>>B[i];
        }
        cout<<max_pts(A, B, n)<<endl;
    }

    return 0;
}



