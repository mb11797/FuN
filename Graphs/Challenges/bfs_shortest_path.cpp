#include<iostream>
#include<map>
#include<list>
using namespace std;

class Graph{
public:
    int V;
    int E;
    map<int, list<pair<int, int>>> m;

    Graph(int n, int m){
        V = n;
        E = m;
    }


    void add_edge(int u, int v, int cost, bool bidir=true);

    void print_adjList();

};

void Graph :: add_edge(int u, int v, int cost=6, bool bidir){
    m[u].push_back(make_pair(v, cost));
    if(bidir){
        m[v].push_back(make_pair(u, cost));
    }
    return;
}

void Graph :: print_adjList(){
    for(int v=1; v<=V; v++){
        cout<<v<<"->";
        for(auto neighbour: m[v]){
            cout<<"("<<neighbour.first<<", "<<neighbour.second<<") ";
        }
        cout<<endl;
    }
    cout<<endl;
    return;
}


int main(){
    int q;
    cin>>q;

    while(q--){
        int n, m;
        cin>>n>>m;

        Graph g(n, m);
        for(int i=0; i<m; i++){
           int u, v;
            cin>>u>>v;
            g.add_edge(u, v);
        }
        int src;
        cin>>src;

        g.print_adjList();
    }


    return 0;
}
