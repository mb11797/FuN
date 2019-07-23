#include<iostream>
using namespace std;

#define inf 1e9

/*
5 8
0 1 -1
0 2 4
1 2 3
3 2 5
4 3 -3
1 4 2
1 3 2
3 1 1
*/

class Edge{
public:
    int src;
    int dest;
    int weight;
};

class Graph{
    int V;
    int E;

    Edge*edge;
public:
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
        for(int i=0; i<V; i++){
            dist[i] = inf;
        }
        dist[src] = 0;

        //Relaxation code
        for(int i=1; i<=V-1; i++){
            for(int j=0; j<E; j++){
                int src = edge[j].src;
                int dest = edge[j].dest;
                int wt = edge[j].weight;

                //Relaxation check
                if(dist[src] != inf and (dist[src] + wt < dist[dest])){
                    dist[dest] = dist[src] + wt;
                }
            }
        }


        //checking for negative cycles
        for(int j=0; j<E; j++){
            int src = edge[j].src;
            int dest = edge[j].dest;
            int wt = edge[j].weight;

            //Relaxation check
            if(dist[src] != inf && (dist[src] + wt < dist[dest])){
                cout<<"Graph has negative weight cycle!"<<endl;
                return;
            }
        }

        //Printing the distances
        for(int i=0; i<V; i++){
            cout<<"Distance of "<<i<<" from "<<src<<" is "<<dist[i]<<endl;
        }
        return;
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
