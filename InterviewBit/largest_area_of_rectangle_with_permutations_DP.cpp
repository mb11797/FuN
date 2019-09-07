#include<iostream>
using namespace std;

int arr[100][100];

int largest_area(int sx, int sy, int ex, int ey){


}

int main(){

    int n, m;
    cin>>n>>m;

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin>>arr[i][j];

    cout<<largest_area(0, 0, n-1, m-1)<<endl;

    return 0;
}
