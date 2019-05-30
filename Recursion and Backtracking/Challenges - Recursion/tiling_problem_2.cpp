#include<iostream>
using namespace std;

int tiling_ways(int n, int m){
    if(n<m)
        return 1;

    if(n>=m)
        return tiling_ways(n-1, m) + tiling_ways(n-m, m);
}

int main(){
    int n, m;
    cin>>n>>m;

    cout<<tiling_ways(n, m);

    return 0;
}
