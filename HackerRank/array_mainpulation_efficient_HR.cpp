#include<iostream>
using namespace std;

int array_manip(int n, int q[100][3]){
    int arr[n+2] = {0};
    for(int i=0; i<3; i++){
        int s = q[i][0];
        int e = q[i][1];
        int k = q[i][2];

        arr[s] += k;
        arr[e+1] -= k;

    }

    long mx = INT_MIN;
    long sum = 0;

    for(long i=0; i<n+2; i++){
        sum += arr[i];
        arr[i] = sum;
        mx = max(mx, sum);
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return mx;
}


int main(){
    int q[100][3] = {
                    {1, 2, 100},
                    {2, 5, 100},
                    {3, 4, 100}
    };

    int n=5;

    cout<<array_manip(n, q)<<endl;

    return 0;
}
