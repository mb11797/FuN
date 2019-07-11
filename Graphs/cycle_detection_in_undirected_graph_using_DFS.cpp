#include<iostream>
#include<map>
#include<list>
using namespace std;

template<typename T>
class Graph{
    int V;
    map<T, list<T>> adjList;
public:
    Graph(int v){
        V = v;
    }

    void addEdge(T u, T v, bool bidir=true){
        adjList[u].push_back(v);
        if(bidir){
            adjList[v].push_back(u);
        }
    }

    void print(){
        for(pair<T, list<T>> i: adjList){
            cout<<i.first<<"->";
            for(T entry: i.second){
                cout<<entry<<", ";
            }
            cout<<endl;
        }
    }

    bool is_cyclic_DFS_helper(T node, map<T, bool> &visited, T parent){
        visited[node] = true;

        for(auto neighbour: adjList[node]){
            if(!visited[neighbour]){
                bool cycle_detected = is_cyclic_DFS_helper(neighbour, visited, node);
                if(cycle_detected==true)
                    return true;
            }
            //if this neighbour is already visited
            else if(neighbour!=parent){
                return true;
            }
        }
        return false;
    }

    //check for undirected graph
    bool is_cyclic_DFS(T src){
        map<T, bool> visited;

        //check for finding cycle in every DFS tree
        for(auto i: adjList){
            T node = i.first;
            if(!visited[node]){
                bool ans = is_cyclic_DFS_helper(node, visited, node);
                if(ans==true)
                    return true;
            }
        }
        return false;
    }
};


int main(){
    Graph<int> g(6);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(0, 4);
    g.addEdge(2, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(3, 5);

    g.print();

    if(g.is_cyclic_DFS(0))
        cout<<"Cyclic Graph"<<endl;
    else
        cout<<"Not Cyclic"<<endl;

    return 0;
}
