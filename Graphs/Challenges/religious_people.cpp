#include<iostream>
#include<map>
#include<list>
using namespace std;

/*
SAMPLE INPUT:
2
3 3 2 1
1 2
3 1
2 3
6 6 2 5
1 3
3 4
2 4
1 2
2 3
5 6
*/


class Graph{
public:
    int V, E;
    map<int, list<pair<int, int>>> m;


    Graph(int A, int B){
        V = A;
        E = B;
    }

    void add_edge(int u, int v, int cost, bool bidir=true);

    void print_adjList();



};

void Graph :: add_edge(int u, int v, int cost, bool bidir){
    m[u].push_back(make_pair(v, cost));
    if(bidir){
        m[v].push_back({u, cost});
    }
    return;
}

void Graph :: print_adjList(){
    for(auto i: m){
        cout<<i.first<<"->";
        for(auto neighbour: i.second){
            cout<<"("<<neighbour.first<<", "<<neighbour.second<<") ";
        }
        cout<<endl;
    }
    return;
}


int main(){
    int tc;
    cin>>tc;

    while(tc--){
        int N, M, A, B;
        cin>>N>>M>>A>>B;

        Graph g(N, M);

        for(int i=0; i<M; i++){
            int u, v;
            cin>>u>>v;

            g.add_edge(u, v, B);
        }

        g.print_adjList();
    }

    return 0;
}



