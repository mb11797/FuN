#include<iostream>
using namespace std;

int no_of_ways_to_tile_the_wall(int n){
    if(n<4)
        return 1;
    return no_of_ways_to_tile_the_wall(n-1) + no_of_ways_to_tile_the_wall(n-4);
}

int main(){
    //4 x n wall
    int n;
    cin>>n;

    cout<<no_of_ways_to_tile_the_wall(n)<<endl;
    return 0;
}
