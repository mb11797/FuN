#include<iostream>
using namespace std;

#define inf INT_MAX

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
        for(int i=0; i<V; i++)
            dist[i] = inf;


        dist[src] = 0;

        for(int i=0; i<=V-1; i++){
            for(int j=0; j<E; j++){
                int src = edge[j].src;
                int dest = edge[i].dest;
                int wt = edge[i].weight;

                if(dist[src] != inf and (dist[src] + wt < dist[dest])){
                    dist[dest] = dist[src] + wt;

                }
            }
        }

            for(int j=0; j<E; j++){
                int src = edge[j].src;
                int dest = edge[j].dest;
                int wt = edge[j].weight;

                if(dist[src] != inf and (dist[src] + wt < dist[dest])){
                    cout<<"Negative Cycle Present"<<endl;
                    return;
                }
            }


    }

};

int main(){
    int V, E;
    cin>>V>>E;
    Graph g(V, E);

    for(int e=0; e<E; e++){
        int s, d, w;
        cin>>s>>d>>w;

        g.add_edge(s, d, w, e);

    }

    g.Bellman_Ford_SSSP(0);



    return 0;
}



