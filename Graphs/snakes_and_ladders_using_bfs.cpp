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
            cout<<i.first<<"->";
            for(auto entry: i.second){
                cout<<entry<<", ";
            }
            cout<<endl;
        }
    }

    void bfs(T src){
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
            cout<<node<<" ";
            q.pop();

            for(T neighbour: adjList[node]){
                if(dist[neighbour]==INT_MAX){
                    q.push(neighbour);
                    dist[neighbour] = dist[node] + 1;
                    parent[neighbour] = node;
                }
            }
        }
        return;
    }

    int bfs_shortest_path(T src, T dest){
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
//            cout<<node<<" ";
            q.pop();

            for(T neighbour: adjList[node]){
                if(dist[neighbour]==INT_MAX){
                    q.push(neighbour);
                    dist[neighbour] = dist[node] + 1;
                    parent[neighbour] = node;
                }
            }
        }

        //Print the path
        //U can Start from the destination and go backwards
        //BACKPROPAGATION
        T temp = dest;
        while(temp!=src){
            cout<<temp<<"<--";
            temp = parent[temp];
        }
        cout<<src<<endl;


        return dist[dest];
    }


};

int main(){
    Graph<int> g;
    int board[50] = {0};

    board[2] = 13;
    board[5] = 2;
    board[9] = 18;
    board[18] = 11;
    board[17] = -13;
    board[20] = -14;
    board[24] = -8;
    board[25] = -10;
    board[32] = -2;
    board[34] = -22;

    //lets first construct the graph, add pairs of (u, v)
    for(int u=0; u<=36; u++){
        //at every node you can throw a dice
        for(int dice=1; dice<=6; dice++){
            int v = u + dice + board[u + dice];
            g.addEdge(u, v, false);
        }
    }


    g.print();
    cout<<endl;


    cout<<"BFS of respective graph: ";
    g.bfs(0);
    cout<<endl;

    cout<<"The shortest distance is "<<g.bfs_shortest_path(0, 35)<<endl;
    cout<<"The shortest distance is "<<g.bfs_shortest_path(0, 36)<<endl;
    cout<<"The shortest distance is "<<g.bfs_shortest_path(0, 15)<<endl;
    cout<<"The shortest distance is "<<g.bfs_shortest_path(0, 27)<<endl;


    return 0;
}
