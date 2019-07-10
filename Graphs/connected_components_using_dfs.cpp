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

        int component = 1;
        dfs_helper(src, visited);
        cout<<endl;

        for(auto i: adjList){
            T city = i.first;
            if(!visited[city]){
                dfs_helper(city, visited);
                cout<<endl;
                component++;
            }
        }

        cout<<endl;
        cout<<"Total connected components in current graph are: "<<component<<endl;
        return;
    }

};


int main(){
    Graph<string> g;

    g.addEdge("Amritsar", "Jaipur");
    g.addEdge("Amritsar", "Delhi");
    g.addEdge("Delhi", "Jaipur");
    g.addEdge("Mumbai", "Jaipur");
    g.addEdge("Mumbai", "Bhopal");
    g.addEdge("Delhi", "Bhopal");
    g.addEdge("Mumbai", "Bangalore");
    g.addEdge("Agra", "Delhi");
    g.addEdge("Andaman", "Nicobar");

    g.print();
    cout<<endl<<endl;

    g.dfs("Amritsar");
    cout<<endl;

    g.dfs("Andaman");
    cout<<endl;

    return 0;
}

