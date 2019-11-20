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

    void bfs_topological_sort(){
        queue<T> q;
        map<T, bool> visited;
        map<T, int> indegree;

        for(auto i: adjList){
            //i is a pair - (node, list)
            T node = i.first;
            visited[node] = false;
            indegree[node] = 0;
        }

        //Init the indegrees of all nodes
        for(auto i: adjList){
            T u = i.first;
            for(T v: adjList[u])
                indegree[v]++;
        }

        //Find out all the nodes with 0 indegree
        for(auto i: adjList){
            T node = i.first;
            if(indegree[node]==0)
                q.push(node);
        }

        //start with the algorithm
        while(!q.empty()){
            T node = q.front();
            cout<<node<<"--->";
            q.pop();

            for(T neighbour: adjList[node]){
                indegree[neighbour]--;

                if(indegree[neighbour]==0)
                    q.push(neighbour);

            }
        }
    }
};


int main(){
    Graph<string> g;

    g.addEdge("English", "Programming Logic", false);
    g.addEdge("Maths", "Programming Logic", false);
    g.addEdge("Programming Logic", "HTML", false);
    g.addEdge("Programming Logic", "Python", false);
    g.addEdge("Programming Logic", "Java", false);
    g.addEdge("Programming Logic", "JS", false);
    g.addEdge("English", "HTML", false);
    g.addEdge("HTML", "CSS", false);
    g.addEdge("CSS", "JS", false);
    g.addEdge("JS", "Web Dev", false);
    g.addEdge("Java", "Web Dev", false);
    g.addEdge("Python", "Web Dev", false);

    g.print();

    cout<<endl;
    cout<<"Topological Sorting using BFS: "<<endl;
    g.bfs_topological_sort();
    cout<<endl;

    return 0;
}

