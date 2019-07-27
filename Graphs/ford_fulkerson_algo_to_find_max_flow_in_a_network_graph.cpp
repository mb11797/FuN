#include<iostream>
#include<string.h>
#include<queue>
using namespace std;

/* Returns true if there is a path from src to sink  in
  residual graph. Also fills parent[] to store the path */
bool bfs(int res_graph[][10], int src, int sink, int V, int*parent){
    // Create a visited array and mark all vertices as not visited
    bool visited[V];
    memset(visited, 0, sizeof(visited));

    // Create a queue, enqueue source vertex and mark source vertex
    // as visited
    queue<int> q;
    visited[src] = true;
    q.push(src);
    parent[src] = -1;

    //Standard BFS loop
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v=0; v<V; v++){
            if(visited[v]==false && res_graph[u][v] > 0){
                visited[v] = true;
                parent[v] = u;
                q.push(v);
            }
        }
    }

    // If we reached sink in BFS starting from source, then return
    // true, else false
    return (visited[sink]==true);
}

// Returns the maximum flow from src to sink in the given graph
int ford_fulkerson_max_flow(int graph[][10], int src, int sink, int V){
    int u, v;


    // Create a residual graph and fill the residual graph with
    // given capacities in the original graph as residual capacities
    // in residual graph
    int res_graph[10][10];   // Residual graph where rGraph[i][j] indicates
                             // residual capacity of edge from i to j (if there
                             // is an edge. If rGraph[i][j] is 0, then there is not)

    for(int i=0; i<V; i++){
        for(int j=0; j<V; j++){
            res_graph[i][j] = graph[i][j];
        }
    }

    int parent[V];           // This array is filled by BFS and to store path

    int max_flow = 0;

    // Augment the flow while there is path from source to sink
    while(bfs(res_graph, src, sink, V, parent)){
        // Find minimum residual capacity of the edges along the
        // path filled by BFS. Or we can say find the maximum flow
        // through the path found.
        int path_flow = INT_MAX;

        for(v = sink; v != src; v = parent[v]){
            u = parent[v];
            path_flow = min(path_flow, res_graph[u][v]);
        }

        // update residual capacities of the edges and reverse edges
        // along the path
        for(v = sink; v != src; v = parent[v]){
            u = parent[v];
            res_graph[u][v] -= path_flow;
            res_graph[v][u] += path_flow;
        }
        // Add path flow to overall flow
        max_flow += path_flow;

    }
    return max_flow;
}

int main(){
    int V = 6;
    int graph[10][10] = { {0, 16, 13, 0, 0, 0},
                        {0, 0, 10, 12, 0, 0},
                        {0, 4, 0, 0, 14, 0},
                        {0, 0, 9, 0, 0, 20},
                        {0, 0, 0, 7, 0, 4},
                        {0, 0, 0, 0, 0, 0}
                      };

    cout<<"The maximum possible flow is "<<ford_fulkerson_max_flow(graph, 0, 5, V)<<endl;

    return 0;
}
