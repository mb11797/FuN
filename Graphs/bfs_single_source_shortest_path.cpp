#include<iostream>
#include<map>
#include<list>
#include<queue>
using namespace std;


template<typename T>
class Graph{
    map<T, list<T>> adjList;
public:
    Graph(){

    }

    void addEdge(T u, T v, bool bidir=true){
        adjList[u].push_back(v);
        if(bidir){
            adjList[v].push_back(u);
        }
    }

    void print(){
        //iterate over the map
        for(auto i: adjList){
            cout<<i.first<<"->";

            //i.second is LL
            for(T entry: i.second){
                cout<<entry<<", ";
            }
            cout<<endl;
        }
    }

    void bfs(T src){
        queue<T> q;
        map<T, bool> visited;

        q.push(src);
        visited[src] = true;

        while(!q.empty()){
            T node = q.front();
            q.pop();
            cout<<node<<" ";

            //for the neighbours of the current node, find out the nodes which are not visited
            for(auto neighbour: adjList[node]){
                if(!visited[neighbour]){
                    q.push(neighbour);
                    visited[neighbour] = true;
                }
            }
        }
    }

    void bfs_shortest_path(T src){
    queue<T> q;
    map<T, int> dist;
    map<T, T> parent;

    for(auto i: adjList){
        dist[i] = INT_MAX;
    }

    q.push(src);
    dist[src] = 0;
    parent[src] = src;

    while(!q.empty()){
        T node = q.front();
        q.pop();
        cout<<node<<" ";

        for(auto neighbour: adjList[node]){
            if(dist[neighbour]==INT_MAX){
                q.push(neighbour);
                dist[neighbour] = dist[node] + 1;
                parent[neighbour] = node;
            }

        }
    }

    for(auto i: dist){
        cout<<"Dist of "<<i<<"from "<<src<<" is "<<dist[i]<<endl;
    }

}


};


int main(){
    Graph<int> g;

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(0, 4);
    g.addEdge(2, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(3, 5);

    g.print();
    cout<<endl<<endl;
    g.bfs(0);
    cout<<endl;



    return 0;
}
