#include<iostream>
using namespace std;

#define ld long double
#define N 50

//function to compute euclidian distance between two points
ld distance(pair<int, int> p1, pair<int, int> p2){
    int dx = p1.first - p2.first;
    int dy = p1.second - p2.second;
    return sqrt(dx*dx + dy*dy);
}

//make a distance array
ld dist[N][N] = {0};

//n is the no of shops except kitchen and k is the no of ingredients needed
int n, k;
vector<pair<int, int>> coordinates;
vector<int>ingredients;


int main(){
    int tc;
    cin>>tc;

    while(tc--){
        coordinates.clear();
        ingredients.clear();

        cin>>n>>k;




    }

    return 0;
}
