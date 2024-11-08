#include<iostream>
#include<map>
#include<list>
#include<queue>
#include<vector>
#include<bits/stdc++.h>
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

    void bfs_shortest_path(T src, T dest){
    queue<T> q;
    map<T, int> dist;
    map<T, T> parent;

    for(auto i: adjList){
        dist[i.first] = INT_MAX;
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

    cout<<endl;
    for(auto i: adjList){
        T node = i.first;
        cout<<"Dist of "<<node<<" from "<<src<<" is "<<dist[node]<<endl;
    }

    ///Path print
    vector<T> path;
    T temp = dest;
    while(temp != src){
        path.push_back(temp);
        temp = parent[temp];
    }
    path.push_back(src);

    reverse(path.begin(), path.end());

    for(auto i: path){
        cout<<i<<"->";
    }
    cout<<endl;
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

    g.bfs_shortest_path(0, 5);

    return 0;
}
