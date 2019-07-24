#include<iostream>
using namespace std;

class Edge{
public:
    int src, dest, weight;
};

class Graph{
public:
    int V, E;

    Edge*edge;

    Graph(int V, int E){
        this->V = V;
        this->E = E;

        edge = new Edge[E];
    }

    void add_edge(int u, int v, int wt, int count){
        edge[count].src = u;
        edge[count].dest = v;
        edge[count].weight = wt;
        return;
    }

    void Bellman_Ford_SSSP(int src){
        int dist[V];
        for(int i=0;)



    }

};

int main(){




    return 0;
}



