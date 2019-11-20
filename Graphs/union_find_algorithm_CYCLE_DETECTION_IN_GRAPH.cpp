#include<iostream>
#include<string.h>
using namespace std;

class Edge{
public:
    int src, dest;
};

class Graph{
public:
    int V, E;

    //Graph is represented as an array of edges
    Edge*edge;
};

//creates a graph with V vertices and E edges
Graph*create_graph(int V, int E){
    Graph*graph = new Graph();
    graph->V = V;
    graph->E = E;
    //Size of all edges in the graph => no_of_edges_in_the_graph * size_of_single_edge
    graph->edge = new Edge[graph->E * sizeof(Edge)];

    return graph;
}

//function to find the subset of an element i
int find(int parent[], int i){
    if(parent[i] == -1)
        return i;
    return find(parent, parent[i]);
}

void Union(int*parent, int x, int y){
    int xset = find(parent, x);
    int yset = find(parent, y);
    if(xset != yset)
        parent[xset] = yset;
    return;
}

bool is_cycle(Graph*graph){
    int*parent = new int[graph->V * sizeof(int)];
    memset(parent, -1, sizeof(int) * graph->V);

    for(int i=0; i < graph->E; i++){
        int x = find(parent, graph->edge[i].src);
        int y = find(parent, graph->edge[i].dest);

        if(x==y)
            return true;

        Union(parent, x, y);
    }
    return false;
}

int main(){
    int V=3, E = 3;
    Graph*graph = create_graph(V, E);

    //adding edge 0-1
    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;

    //edge 1-2
    graph->edge[1].src = 1;
    graph->edge[1].dest = 2;

    //edge 0-2
    graph->edge[2].src = 0;
    graph->edge[2].dest = 2;

    if(is_cycle(graph)){
        cout<<"Cycle exists!"<<endl;
    }
    else
        cout<<"No cycle present!"<<endl;

    return 0;
}
