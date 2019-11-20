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
        if(bidir)
            adjList[v].push_back(u);
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
};


int main(){
    Graph<string> g1;
    g1.addEdge("Putin", "Modi", false);
    g1.addEdge("Putin", "Trump", false);
    g1.addEdge("Putin", "Pope", false);
    g1.addEdge("Trump", "Modi", true);
    g1.addEdge("Modi", "Yogi", true);
    g1.addEdge("Yogi", "Prabhu", false);
    g1.addEdge("Prabhu", "Modi", false);

    g1.print();
    cout<<endl;

    Graph<int> g2;
    g2.addEdge(1,2);
    g2.addEdge(100, 2);
    g2.addEdge(100, 3);

    g2.print();

    return 0;
}
