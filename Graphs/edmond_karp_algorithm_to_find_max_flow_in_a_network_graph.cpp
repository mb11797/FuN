#include<iostream>
#include<string.h>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

bool bfs(int **residual_capacity, int src, int sink, int V, int *parent){
    bool visited[V];
    memset(visited, 0, sizeof(visited));
    queue<int> que;
    visited[src] = true;
    que.push(src);

    bool found_augmented_path = false;

    while(not que.empty()){
        int u = que.front();
        que.pop();

        for(int v=0; v<V; v++){
            if(visited[v] == false and residual_capacity[u][v] > 0){
                parent[v] = u;
                visited[v] = true;
                que.push(v);

                if(v == sink){
                    found_augmented_path = true;
                    break;
                }
            }
        }
    }
    return found_augmented_path;
}

void print_augmented_path(vector<vector<int> > augmented_paths){
    for(int i=0; i<augmented_paths.size(); i++){
        for(int j=0; j<augmented_paths[i].size(); j++){
            cout<<augmented_paths[i][j]<<", ";
        }
        cout<<endl;
    }
    cout<<endl;
    return;
}


int max_flow(int**capacity, int src, int sink, int V){
    int **residual_capacity = new int*[V];
    for(int i=0; i<V; i++)
        residual_capacity[i] = new int[V];

    for(int i=0; i<V; i++)
        for(int j=0; j<V; j++)
            residual_capacity[i][j] = capacity[i][j];

    int *parent = new int[1000];

    vector<vector<int> > augmented_paths;
    int max_flow = 0;

    while(bfs(residual_capacity, src, sink, V, parent)){
        vector<int> current_augmented_path;
        int v = sink;
        int flow = INT_MAX;

        while(v != src){
            current_augmented_path.push_back(v);
            int u = parent[v];
            if(flow > residual_capacity[u][v])
                flow = residual_capacity[u][v];
            v = u;
        }

        current_augmented_path.push_back(src);
        std::reverse(current_augmented_path.begin(), current_augmented_path.end());
        augmented_paths.push_back(current_augmented_path);
        max_flow += flow;

        //updating the pipe capacities, i.e, edge weights of the current augmented path with the flow found to be minimum
        v = sink;
        while(v != src){
            int u = parent[v];

            residual_capacity[u][v] -= flow;
            residual_capacity[v][u] += flow;

            v = u;
        }
    }

    print_augmented_path(augmented_paths);
    return max_flow;
}

int main(){
    int V, E;
    cin>>V>>E;

    int **capacity = new int*[V];
    for(int v=0; v<V; v++)
        capacity[v] = new int[V];

//    V = 6;
//    int graph[V][V] = { {0, 16, 13, 0, 0, 0},
//                        {0, 0, 10, 12, 0, 0},
//                        {0, 4, 0, 0, 14, 0},
//                        {0, 0, 9, 0, 0, 20},
//                        {0, 0, 0, 7, 0, 4},
//                        {0, 0, 0, 0, 0, 0}
//                      };
//
//
//
//    for(int i=0; i<V; i++){
//        for(int j=0; j<V; j++){
//        capacity[i] = graph[i];
//    }

    for(int e=0; e<E; e++){
        int u, v, c;
        cin>>u>>v>>c;

        capacity[u][v] = c;
    }

    int src = 0;
    int sink = 5;

    cout<<max_flow(capacity, src, sink, V)<<endl;

    return 0;
}
