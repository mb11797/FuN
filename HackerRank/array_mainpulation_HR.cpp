#include<iostream>
using namespace std;

int array_manip(int n, int q[100][3]){
    int arr[n] = {0};
    for(int i=0; i<3; i++){
        int s = q[i][0]-1;
        int e = q[i][1]-1;
        int add = q[i][2];
        for(int j=s; j<=e; j++){
            arr[j] += add;
        }
    }



    int mx = -1;
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
        if(arr[i] > mx)
            mx = arr[i];
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

