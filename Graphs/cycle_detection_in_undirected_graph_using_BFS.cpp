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
        for(auto i: adjList){
            T node = i.first;
            cout<<node<<"->";
            for(T entry: i.second){
                cout<<entry<<", ";
            }
            cout<<endl;
        }
    }

    bool is_cyclic_BFS(T src){
        map<T, bool> visited;
        map<T, int> parent;
        queue<T> q;

        q.push(src);
        visited[src] = true;
        parent[src] = src;

        while(!q.empty()){
            T node = q.front();
            q.pop();

            for(auto neighbour: adjList[node]){
                if(visited[neighbour]==true and parent[node]!=neighbour){
                    return true;
                }
                else if(!visited[neighbour]){
                    q.push(neighbour);
                    visited[neighbour]=true;
                    parent[neighbour] = node;
                }
            }
        }
        return false;
    }
};


int main(){
    Graph<int> g;


    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(0, 4);
//    g.addEdge(2, 4);
    g.addEdge(2, 3);
//    g.addEdge(3, 4);
    g.addEdge(3, 5);

    g.print();
    cout<<endl;

    if(g.is_cyclic_BFS(0))
        cout<<"Cyclic Graph"<<endl;
    else
        cout<<"Not Cyclic"<<endl;

    return 0;
}
