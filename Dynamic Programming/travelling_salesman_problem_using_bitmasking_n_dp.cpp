#include<iostream>
using namespace std;

//#define INT_MAX 999999

int n=4;
int dp[16][4];                  //no of possible states(due to mask)=2^n        positions can be equal to no of cities, i.e, no of bits
//Adjacency matrix which defines the graph
int dist[10][10] = {
                    {0, 20, 42, 25},
                    {20, 0, 30, 34},
                    {42, 30, 0, 10},
                    {25, 34, 10, 0}
};

//If all cities have been visited
int VISITED_ALL = (1<<n) - 1;


int tsp(int mask, int pos){
    if(mask == VISITED_ALL){
        return dist[pos][0];
    }

    //lookup
    if(dp[mask][pos] != -1)
        return dp[mask][pos];

    int ans = INT_MAX;
    //Try to go to an unvisited city
    for(int city=0; city<n; city++){
        //check to see if the city has already been visited or not
        if((mask&(1<<city)) == 0){
            int new_ans = dist[pos][city] + tsp(mask|(1<<city), city);
            ans = min(ans, new_ans);
        }
    }
    return dp[mask][pos] = ans;
}

int main(){
    for(int i=0; i<(1<<n); i++){
        for(int j=0; j<n; j++){
            dp[i][j]=-1;
        }
    }
    //starting from city 1, i.e. mask=1 initially
    cout<<"Min. weight Hamiltonian path costs "<<tsp(1, 0)<<endl;

    return 0;
}
