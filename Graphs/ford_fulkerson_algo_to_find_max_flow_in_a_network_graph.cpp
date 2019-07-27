#include<iostream>
using namespace std;


int ford_fulkerson_max_flow(int graph[V][V], int src, int sink){
    int u, v;

    //creating a residual graph and filling it initially with capacities as given in the original graph
    int res_graph[V][V];
    for(int i=0; i<V; i++){
        for(int j=0; j<V; j++){
            res_graph[i][j] = graph[i][j];
        }
    }



}

int main(){

    int graph[V][V] = { {0, 16, 13, 0, 0, 0},
                        {0, 0, 10, 12, 0, 0},
                        {0, 4, 0, 0, 14, 0},
                        {0, 0, 9, 0, 0, 20},
                        {0, 0, 0, 7, 0, 4},
                        {0, 0, 0, 0, 0, 0}
                      };

    cout<<"The maximum possible flow is "<<for_fulkerson_max_flow(graph, 0, 5)<<endl;

    return 0;
}
