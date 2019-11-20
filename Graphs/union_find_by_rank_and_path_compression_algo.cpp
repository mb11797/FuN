#include<iostream>
using namespace std;

class Edge{
public:
    int src;
    int dest;
};

class Graph{
public:
    int V;
    int E;

    //Graph is represented as an array of edges
    Edge*edge;
};

Graph*create_graph(int V, int E){
    Graph*graph = new Graph();
    graph->V = V;
    graph->E = E;

    graph->edge = new Edge[sizeof(Edge) * graph->E];
    return graph;
}

class subset{
public:
    int parent;
    int rank;
};

int find(subset*subsets, int i){
    if(subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

void Union(subset*subsets, int x, int y){
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);


    //attach similar rank tree under root of high rank tree
    //(Union by rank)
    if(subsets[xroot].rank > subsets[yroot].rank){
        subsets[yroot].parent = xroot;
    }
    else if(subsets[yroot].rank > subsets[xroot].rank){
        subsets[xroot].parent = yroot;
    }
    //if ranks are same, then make one as root and increment its rank by one
    else{
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

bool is_cycle(Graph*graph){
    //allocating memory for creating v sets
    subset*subsets = new subset[sizeof(subset) * graph->V];

    for(int v=0; v < graph->V; v++){
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }


    //iterate through all edges of graph, find sets of both vertices of every edge,
    //if sets are same, then there is cycle in graph
    for(int e=0; e < graph->E; e++){
        int x = find(subsets, graph->edge[e].src);
        int y = find(subsets, graph->edge[e].dest);

        if(x == y)
            return true;

        Union(subsets, x, y);
    }
    return false;
}

int main(){
    int V, E;
    V = 3;
    E = 3;
    Graph*graph = create_graph(V, E);

    //Adding the edges

    //adding edge 0-1
    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;

    //adding edge 1-2
    graph->edge[1].src = 1;
    graph->edge[1].dest = 2;

    //adding edge 0-2
    graph->edge[2].src = 0;
    graph->edge[2].dest = 2;

    if(is_cycle(graph))
        cout<<"Cycle Present."<<endl;
    else
        cout<<"Cycle not Present."<<endl;

    return 0;
}
