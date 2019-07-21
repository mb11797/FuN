#include<iostream>
#include<list>
using namespace std;

#define inf 1e9

/*
7 8
0 3 4
0 1 6
1 2 5
3 2 7
3 4 2
4 5 4
5 6 1
4 6 3
*/

class Graph{
public:
    int V;
    list<pair<int, int>>*adj;

    Graph(int v){
        V = v;
        adj = new list<pair<int, int>>[V];
    }

    void addEdge(int u, int v, int w){
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back({u, w});
    }

    int find_min_vertex(bool*visited, int*weight, int V){
        int min_vertex = -1;
        for(int i=0; i<V; i++){
            if(!visited[i] and (min_vertex==-1 or weight[i]<weight[min_vertex])){
                min_vertex = i;
            }
        }

        return min_vertex;
    }

    void prims(){
        bool*visited = new bool[V];     //mapping for vertices that have been visited
        int*parent = new int[V];
        int*weight = new int[V];
        for(int i=0; i<V; i++){
            visited[i] = false;
            weight[i] = inf;
        }
        parent[0] = -1;
        weight[0] = 0;
        for(int i=0; i<V; i++){
            int min_vertex = find_min_vertex(visited, weight, V);
            visited[min_vertex] = true;

            for(auto neighbour: adj[min_vertex]){
                if(!visited[neighbour.first]){
                    if(weight[neighbour.first] > neighbour.second){     //to check if the weight for a vertex in our mapping is greater than the weight at a particular edge or not
                        weight[neighbour.first] = neighbour.second;
                        parent[neighbour.first] = min_vertex;
                    }
                }
            }
        }
        for(int i=1; i<V; i++)
            cout<<i<<"---"<<parent[i]<<" with weight "<<weight[i]<<endl;

        return;
    }
};

int main(){
    int n, e;
    cin>>n>>e;

    Graph g(n);

    for(int i=0; i<e; i++){
        int u, v, w;
        cin>>u>>v>>w;

        g.addEdge(u, v, w);
    }

    g.prims();

    return 0;
}
