#include<iostream>
#include<map>
#include<list>
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

    void dfs_helper(T node, map<T, bool> &visited, list<T> &ordering){
        visited[node] = true;

        //will call dfs on the unvisited neighbours of the current node
        for(T neighbour: adjList[node]){
            if(!visited[neighbour]){
                dfs_helper(neighbour, visited, ordering);
            }
        }

        //Add just 1 line for Topological sort
        //At this point all the children of current node have been visited
        //so we can add current node to the list
        ordering.push_front(node);
        return;
    }

    void dfs_topological_sort(){
        map<T, bool> visited;
        list<T> ordering;

        for(auto i: adjList){
            //i is pair - (node, list of nodes)
            T node = i.first;
            if(!visited[node]){
                dfs_helper(node, visited, ordering);
            }
        }

        //Print all the elements in ordering
        for(T element: ordering)
            cout<<element<<"--->";
        cout<<endl;
        return;
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
    cout<<"Topological Sorting using DFS: "<<endl;
    g.dfs_topological_sort();

    return 0;
}
