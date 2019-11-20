#include<iostream>
#include<list>
#include<queue>
using namespace std;

class Graph{
    int V;
    list<int>*l;

public:
    Graph(int v){
        V = v;
        l = new list<int>[V];
    }

    void addEdge(int u, int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }

    bool is_bipartite(int src){
        queue<int> q;
        q.push(src);

        int*colors = new int[V];
        for(int i=0; i<V; i++)
            colors[i] = -1;

        colors[src] = 0;

        while(!q.empty()){
            int u = q.front();
            q.pop();

            for(auto v: l[u]){
                if(colors[v]==-1){
                    colors[v] = 1 - colors[u];
                    q.push(v);
                }
                else if(colors[v]==colors[u]){
                    return false;
                }
            }
        }
        return true;
    }
};

int main(){
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(3, 1);
    g.addEdge(3, 2);
    g.addEdge(0, 3);

    if(g.is_bipartite(0))
        cout<<"Yes it is Bipartite!"<<endl;
    else
        cout<<"No it is not Bipartite!"<<endl;

    return 0;
}
