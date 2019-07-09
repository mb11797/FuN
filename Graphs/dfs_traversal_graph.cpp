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

    void dfs_helper(T node, map<T, bool> &visited){
        visited[node] = true;
        cout<<node<<" ";

        for(auto neighbour: adjList[node]){
            if(!visited[neighbour]){
                dfs_helper(neighbour, visited);
            }
        }
        return;
    }


    void dfs(T src){
        map<T, bool> visited;
        dfs_helper(src, visited);
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

    g.dfs(0);
    cout<<endl;

    return 0;
}

